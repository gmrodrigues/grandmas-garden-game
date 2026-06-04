#!/usr/bin/python3
# coding: utf8

# The Incredible Machine (TIM) level/image resource reader, version 0.2
# By knt47, licensed under the Creative Commons Zero license

from __future__ import division, print_function, unicode_literals

import itertools, sys

if sys.version_info[0] != 3:
    izip = itertools.izip
else:
    izip = zip
    xrange = range

import struct, zlib
from collections import namedtuple
from timgres.base.nibblarr import _single_char, _b_array_shift_left_4
from timgres.base.pngexp import (SimplePngExporter, png_sign, png_head_chunk,
                                 PNG_COL_TYPE_INDEXED, PNG_IHDR, PNG_PLTE,
                                 PNG_IDAT, PNG_IEND)
from timgres.base.misc import (print_msg, print_traceback, s_opt_transpcol16,
                               s_opt_transpcol256, s_obj_pngexp16,
                               s_obj_pngexp256, color_dist, color_white)
from timgres.base.basecl import ResDataItemBase
from timgres.base.bmpdbase import flip_vertical, flip_horizontal

# --- PNG image merger ---

'''
This module provides classes for creating a "merged" PNG image from
    multiple images. The base class is PngMergerBase, two sub-classes
    implement the 4BPP and 8BB output format (PngMerger_4BPP, PngMerger_8BPP).
The entire code is "pure Python", and used for saving PNG images (but
    not for displaying them in a Tcl/Tk canvas for performance reasons).
'''

# NOTE 1: This small image manipulation library is implemented in "pure
#     Python". Of course, this will affect its performance.
# NOTE 2: In current version, this module supports only 4BPP and 8BPP
#     indexed-color PNG images. The palette of all images must be identical!
#     (It additionally supports !BPP "input" images in 8BPP "output" if the
#     256-color palette contains matching colors.)
# NOTE 3: This module is only used for saving PNG files (i.e. export), not
#    for displaying them in the Tcl/Tk canvas. This framework unfortunately
#    does not support saving the canvas content as an image, only Postscript.
# NOTE 4: Allows the export of multi-part images from command line without
#    dependency on a GUI framework.

_BPP_4 = 4  # 4 bits per pixel, max. 16 colors
_BPP_8 = 8  # 8 bits per pixel, max. 256 colors

chars_a_z = set(itertools.chain(xrange(65, 91), xrange(97, 123)))

# See PNG specification: https://www.w3.org/TR/PNG

# nt_png_header: Contains PNG header information from the "IHDR" chunk
# width (int): the width of the image
# height (int): the height of the image
# bit_depth (int): bits per pixel (1, 4, 8, 16)
# color_type (int): see PNG_COL_TYPE_* in base.pngexp
# compression_method (int): 0 for zlib compression, see specification
# filter_method (int): see PNG specification
# interlace_method (int): see PNG specification

nt_png_header = namedtuple(
    'nt_png_header',
    ('width', 'height', 'bit_depth', 'color_type', 'compression_method',
     'filter_method', 'interlace_method'))


def detect_png_format_indexed(png_data):
    '''
    Returns _BPP_4 or _BPP_8 (int) if the png data contains a valid header
       for a 4 or 8 BPP indexed-color PNG image. Returns None if the format
       is not supported. Does not raise exceptions (unless the input is
       too short to contain even a header)
    '''

    if not png_data.startswith(png_sign): return  # returns None if invalid!

    header_start = len(png_sign)
    # TODO, check head chunk size at head_start

    if png_data[header_start + +4:header_start + 8] != PNG_IHDR: return

    png_header = nt_png_header._make(
        struct.unpack_from(png_head_chunk, png_data, header_start + 8))

    if ((png_header.color_type != PNG_COL_TYPE_INDEXED) or (png_header[-3:] !=
                                                            (0, 0, 0))):
        return

    return png_header.bit_depth if \
        png_header.bit_depth in (_BPP_4, _BPP_8) else None


class PngMergerBase(ResDataItemBase):
    '''
    Base class for creating "merged" PNG images. The output image size is set
        by set_canvas_size(). Then, the add_image() method must be called for
        adding the "input" images. The processing must be finalized using
        finish_processing(). get_png_data() retrieves the output PNG data.
    Inherits ResDataItemBase, so that the parent can be set
         using the set_parent method.
    Has two abstract methods, create_empty_canvas and copy_single_line.
    '''

    # png_exporter_obj_id: ID of png exporter object in parent,
    #     must be modified in sub-classes
    png_exporter_obj_id = ''
    # transp_col_opt_id: ID of "transparent color" option, must be
    #     modified in sub-classes
    transp_col_opt_id = ''

    # input_bit_depths_supported: In a subclass, must be changed to a
    #     tuple/list/set containing one or more of the possible return values
    #     of detect_png_format_indexed (currently _BPP_4 and _BPP_8)
    input_bit_depths_supported = ()

    def __init__(self):
        '''The constructor of the class. Has no arguments.'''
        ResDataItemBase.__init__(self)
        self.reset_data()

    def reset_sub_image_data(self):
        '''
        Resets the fields storing information about the PNG image
            currently being processed
        '''
        # image_data_uncompr: the uncompressed IDAT chunk of
        #     current PNG image
        self.image_data_uncompr = None
        # added_image_width, added_image_height: the sizes of current PNG
        self.added_image_width = None
        self.added_image_height = None
        # added_image_bit_depth: return value of detect_png_format_indexed()
        #     for the added image
        self.added_image_bit_depth = None
        # image_bytes_in_row: set by set_added_image_data() (in subclasses)
        #     depends on image_width and the bit depth of image
        self.added_image_bytes_in_row = None

        self.reset_sub_image_data_sublass()

    def reset_sub_image_data_sublass(self):
        '''
        May be re-implemented in a subclass. for adding additional fields.
            By default, does nothing.
        '''
        pass

    def reset_data(self):
        '''
        Resets the fields that store information about the output PNG image
        '''
        self.reset_sub_image_data()

        # The palette from the "PNG exporter" object
        self.pal_exporter = None

        # canvas_width, canvas_height: the canvas size
        self.canvas_width = None
        self.canvas_height = None

        # background_color: usually transparent, or the color closest to
        #    white as fallback. None if not set
        self.background_color = None
        # transparent_color: the transparent color or None
        self.transparent_color = None

        # out_image_lines: list of bytearray()s, contains the output data
        self.out_image_lines = None

    def reset_image(self):
        '''
        Resets the PNG exporter object in parent with ID png_exporter_obj_id
        '''
        self.parent.get_object(self.png_exporter_obj_id).reset_image()

    def reset_data_image(self):
        '''
        Calls both self.reset_data and self.reset_image
        '''
        self.reset_data()
        self.reset_image()

    def set_canvas_size(self, new_width, new_height):
        '''
        Sets the self.canvas_width and self.canvas_height fields.
        Resets image data (self.out_image_lines)!
        new_width (int): the image width
        new_height (int): the image height
        '''
        if not (isinstance(new_width, int) and isinstance(new_height, int)):
            raise TypeError('new_width, new_height: must be int')

        self.reset_data()
        self.canvas_width = new_width
        self.canvas_height = new_height

        self.reset_image()
        self.set_background_color()
        self.create_empty_canvas()

    def set_background_color(self):
        '''
        Sets self.background color that will be used in
            self.create_empty_canvas as the initial values of pixels.
            By default, "transparent". If no transparent color is available,
            finds thw color closest to white in the current palette.
        '''
        # If there is a transparent color, use it
        # TODO FIXME: The transparent color is currently NOT obtained
        #    from the PNG image, but from the transparent color option
        exporter_obj = self.parent.get_object(self.png_exporter_obj_id)
        self.pal_exporter = exporter_obj.get_palette_raw()
        self.transparent_color = self.parent.get_option(self.transp_col_opt_id)

        if self.transparent_color is not None:
            self.background_color = self.transparent_color
            return

        # As a fallback, use the color closest to white (todo, hardcoded)
        self.background_color = None

        diff_max = 195076  # 255 ** 2 * 3 + 1

        for color_id, arr_index in enumerate(
                xrange(0, len(self.pal_exporter), 3)):

            diff_white = color_dist(
                bytearray(self.pal_exporter[arr_index:arr_index + 3]),
                color_white)

            if diff_white < diff_max:
                self.background_color = color_id
                diff_max = diff_white

        if self.background_color is None:
            raise RuntimeError('set_background_color failure')

    def create_empty_canvas(self):
        '''
        Must be re-implemented in subclasses
        Must set out_image_rows to a list of bytearrays, size depends on
            the values of self.canvas_width and self.canvas_height
        '''

        raise NotImplementedError('create_empty_canvas - '
                                  'Not implemented in PngMergerBase')

    def add_image(self, img_disp_data):
        '''
        Method that processes a PNG image that should be drawn to the
            output PNG. Extracts the required information from the PNG
            chunks, then calls process_image_data.
        img_disp_data: nt_image_display_data (base.vdobase) namedtuple
            the PNG data is stored in the img_data field.
        '''
        # NOTE: detect_png_format_indexed detects the magic number +
        #    the FIRST chunk of the image!
        img_data = img_disp_data.img_data

        self.added_image_bit_depth = detect_png_format_indexed(img_data)

        if self.added_image_bit_depth not in self.input_bit_depths_supported:
            raise RuntimeError(('Merging this type of image is currently '
                                'not supported with a %d BPP PNG') %
                               self.png_format_supported)

        index = len(png_sign)
        len_data = len(img_data)

        while True:
            # Raise an exception if less than 8 bytes are remaining
            if (index + 8) > len_data:
                raise RuntimeError(
                    'Error, file data ends at unexpected postiton')

            chunk_name = img_data[index + 4:index + 8]

            if any(_single_char(x) not in chars_a_z for x in chunk_name):
                raise RuntimeError('Invalid chunk name')

            chunk_data_len = struct.unpack_from('>L', img_data, index)[0]
            # chunk_size includes chunk len and checksum (4 + 4 bytes)
            chunk_size = chunk_data_len + 8
            chunk_data = img_data[index + 8:index + chunk_size]

            if chunk_name == PNG_IHDR:
                # NOTE: currently reads only width and height, further checks
                #     are done in detect_png_format_indexed() !
                head_data = nt_png_header._make(
                    struct.unpack(png_head_chunk, chunk_data))

                if (self.added_image_width
                        is not None) or (self.added_image_height is not None):
                    raise RuntimeError('Duplicated "IHDR" chunk')

                self.added_image_width = head_data.width
                self.added_image_height = head_data.height
                self.set_added_image_data()

            elif chunk_name == PNG_PLTE:
                self.process_palette_data(chunk_data)

            elif chunk_name == PNG_IDAT:
                if self.image_data_uncompr is not None:
                    raise RuntimeError(
                        'Currently, images with more than one IDAT chunk '
                        'are not supported')

                self.image_data_uncompr = zlib.decompress(chunk_data)
                self.process_image_data(img_disp_data)

            elif chunk_name == PNG_IEND:
                if (index + chunk_size + 4) != len_data:
                    raise RuntimeError('"IEND" chunk at invalid position')

                if chunk_data_len != 0:
                    raise RuntimeError('"IEND" chunk must contain no data')

                break

            # TODO: All other chunks (including transp. color-tRNS) are ignored
            # TODO: Add check sum check for PNG chunks

            index += chunk_size + 4

        # fixme, these vars need to be cleared
        self.reset_sub_image_data()

    def set_added_image_data(self):
        '''
        Sets the self.image_bytes_in_row field based on image width
            and the bit dept of added PNG. Currently supports indexed-color
            4BPP and 8BPP image. May be re-implemented in subclasses.
        '''
        if self.added_image_bit_depth == _BPP_4:
            # + 1 -> due to the filter byte
            self.added_image_bytes_in_row = \
                ((self.added_image_width + 1) >> 1) + 1
        elif self.added_image_bit_depth == _BPP_8:
            # + 1 -> due to the filter byte
            self.added_image_bytes_in_row = self.added_image_width + 1
        else:
            raise RuntimeError('image_bytes_in_row - unsupported image format')

    def process_palette_data(self, pal_data):
        '''
        By default, this function compares if the palette of added image
            with self.pal_exporter. May be re-implemented in sub-classes
        pal_data (bytes): RGB values for each color
        '''
        if pal_data != self.pal_exporter:
            raise RuntimeError(
                'Image has a different palette than the exporter')

    def process_image_data(self, img_disp_data):
        '''
        Draws all lines from an "input" image (in img_disp_data) to
            self.out_image_lines. img_disp_data contains all required
            information (x, y position, flip)
        img_disp_data: nt_image_display_data (base.vdobase) namedtuple
        '''
        if (self.added_image_bytes_in_row is
                None) or (self.added_image_width is
                          None) or (self.added_image_height is None):
            raise RuntimeError('Error, PngMergerBase.process_image_data: '
                               'image_width/image_height/image_bytes_in_row')

        img_pos_x, img_pos_y, img_flip, _data_unused = img_disp_data

        pos_x = (img_pos_x - self.added_image_width if img_flip
                 & flip_horizontal else img_pos_x)
        pos_y = (img_pos_y - self.added_image_height if img_flip
                 & flip_vertical else img_pos_y)
        index = 0

        for line_num in xrange(pos_y, pos_y + self.added_image_height):
            if _single_char(self.image_data_uncompr[index]) != 0:
                raise RuntimeError('Error, this class supports only filter #0')

            if (line_num >= 0) and (line_num < self.canvas_height):
                # index + 1: ignore filter byte
                self.copy_single_line(
                    self.out_image_lines[line_num],
                    self.image_data_uncompr[index + 1:index +
                                            self.added_image_bytes_in_row],
                    pos_x)

            index += self.added_image_bytes_in_row

    def copy_single_line(self, line_b_arr, line_bytes, pos_x):
        '''
        Not implemented in PngMergerBase. An implementation must
            draw a single row from the input PNG file to the output data
        line_b_arr (bytearray): the bytearray that will be modified
            (in copy_single_line)
        line_bytes (bytes/bytearray): the bytes/nibbles from the input image
        pos_x (int): the X position in output image
        '''
        raise NotImplementedError('copy_single_line - '
                                  'Not implemented in PngMergerBase')

    def finish_processing(self):
        '''
        This method must be called after all images were drawn using
            add_image. After finishing the processing, the output PNG image
            can be obtained using get_png_data.
        '''
        exporter_obj = self.parent.get_object(self.png_exporter_obj_id)
        # does NOT call exporter_obj.reset_image() (nothing has changed since
        #     the set_canvas_size() call)
        exporter_obj.set_width_height(self.canvas_width, self.canvas_height)

        for img_line in self.out_image_lines:
            exporter_obj.add_line(img_line)
        # TODO, prevent "double call"

    def get_png_data(self):
        '''
        Returns the PNG data (bytes), after the processing has been finished.
        '''
        return self.parent.get_object(self.png_exporter_obj_id).get_png_data()


def _fill_b_arr_4bpp(back_color, arr_len):
    '''
    "Private" function. Creates a bytearray that will be used as a line
        in self.out_image_lines for 4BPP images.
    back_color (int, 0-15): the background color to use
    arr_len (int): the width, in pixels
    '''
    # TODO: no range check
    out_arr = bytearray(((back_color << 4) | back_color, )) * (arr_len >> 1)
    # NOTE: If the lower-order nibble is unused it will be always 0!
    if arr_len & 1: out_arr.append(back_color << 4)
    return out_arr


def _transparent_copy_4bpp(out_b_arr, in_b_arr, start_pos, transp_col):
    '''
    Copies a sequence of nibbles from in_b_arr to out_b_arr, with
        transparency taken into account.
    out_b_arr: the bytearray to modify
    in_b_arr: the input data, must by bytearray for Py 2 compatibility
    start_pos (int): the start position in bytes (not pixels)
    transp_col (int, 0-15): the code of transparent color in palette
    '''
    # NOTE: this function will use both the first and the last
    #     nibble from in_b_arr. See PngMerger_4BPP.copy_single_line
    #     for the cases where the first and/or the last nibbles are unused

    if transp_col is None:
        out_b_arr[start_pos:start_pos + len(in_b_arr)] = in_b_arr
        return

    # NOTE: Transparency is implemented in "pure Python" and can be SLOW
    # No range check for transp_col!
    transp_2px = (transp_col << 4) | transp_col

    for i_bytes_in, b_bytes_in in enumerate(in_b_arr, start_pos):
        if b_bytes_in == transp_2px:
            pass
        elif (b_bytes_in & 0xf) == transp_col:
            out_b_arr[i_bytes_in] = \
                (out_b_arr[i_bytes_in] & 0xf) | (b_bytes_in & 0xf0)
        elif (b_bytes_in >> 4) == transp_col:
            out_b_arr[i_bytes_in] = \
                (out_b_arr[i_bytes_in] & 0xf0) | (b_bytes_in & 0xf)
        else:
            out_b_arr[i_bytes_in] = b_bytes_in


class PngMerger_4BPP(PngMergerBase):
    '''
    PngMergerBase subclass that uses 4 BPP, indexed color PNG as output
        format. Accepts only 4BPP PNG images with a palette identical with
        output (output palette is from the s_obj_pngexp16 object in parent).
        Implements the two abstract methods of parent (create_empty_canvas,
        copy_single_line)
    '''

    # png_exporter_obj_id, transp_col_opt_id: modified from parent,
    #     the appropriate values for 4BPP output
    png_exporter_obj_id = s_obj_pngexp16
    transp_col_opt_id = s_opt_transpcol16
    # input_bit_depths_supported: Accepts only 4 BPP input
    input_bit_depths_supported = (_BPP_4, )

    def create_empty_canvas(self):
        '''
        Re-implements create_empty_canvas(). Sets self.out_image_lines to
            a list of bytearrays that is suitable for storing the 4BPP pixel
            data. with the given width and height
            (self.canvas_width, self.canvas_height)
        '''
        self.out_image_lines = [
            _fill_b_arr_4bpp(self.background_color, self.canvas_width)
            for x in xrange(self.canvas_height)
        ]

    def copy_single_line(self, line_b_arr, line_bytes, pos_x):
        '''
        Re-implements copy_single_line(), see the meaning of arguments
            in parent class.
        Supports clipping at the left and right edges of output image.
        '''

        # ... 1. Left clip of line_bytes ...
        last_n_unused = self.added_image_width & 1

        if pos_x < 0:
            if pos_x & 1:
                bytes_clip_left = _b_array_shift_left_4(
                    line_bytes, last_n_unused)[(-pos_x + 1) >> 1:]

                last_n_unused_clip_left = not last_n_unused
            else:
                bytes_clip_left = line_bytes[(-pos_x) >> 1:]
                last_n_unused_clip_left = bool(last_n_unused)

            pos_x_clip_left = 0
        else:
            bytes_clip_left = line_bytes
            last_n_unused_clip_left = bool(last_n_unused)
            pos_x_clip_left = pos_x

        len2_clip_left = len(bytes_clip_left) * 2 - last_n_unused_clip_left

        # ... 2. Right clip of line_bytes ...

        # Seems to give identical result with > and >=
        nibble_len_img = self.canvas_width

        if (pos_x_clip_left + len2_clip_left) > nibble_len_img:

            len2_clip_right = nibble_len_img - pos_x_clip_left

            if len2_clip_right <= 0:
                return  # HACK

            bytes_clip_right = bytes_clip_left[:(len2_clip_right + 1) >> 1]
            last_n_unused_clip_right = bool(len2_clip_right & 1)
        else:
            bytes_clip_right = bytes_clip_left
            last_n_unused_clip_right = last_n_unused_clip_left
            len2_clip_right = len2_clip_left

        if not bytes_clip_right:
            return  # HACK

        pos_arr = pos_x_clip_left >> 1

        # ... 3. Modify line_b_arr ...
        transp_col = self.transparent_color

        if pos_x_clip_left & 1:
            # NOTE: if clipping took place on the left side, pos_x_clip_left
            #     is set to 0. Therefore, _b_array_shift_left_4 is
            #     never called twice (NOTE: must by bytearray for Py 2 compat)
            bytes_clip_shift = bytearray(
                _b_array_shift_left_4(bytes_clip_right,
                                      last_n_unused_clip_right))

            pos_arr_end = pos_arr + len(bytes_clip_shift)

            # Higher-order nibble should be zero, so we can compare
            #     it directly with transp_col

            if bytes_clip_shift[0] != transp_col:
                line_b_arr[pos_arr] = \
                    (line_b_arr[pos_arr] & 0xf0) | bytes_clip_shift[0]

            if last_n_unused_clip_right:
                _transparent_copy_4bpp(line_b_arr, bytes_clip_shift[1:],
                                       pos_arr + 1, transp_col)
            else:
                _transparent_copy_4bpp(line_b_arr, bytes_clip_shift[1:-1],
                                       pos_arr + 1, transp_col)

                if (bytes_clip_shift[-1] >> 4) != transp_col:
                    line_b_arr[pos_arr_end - 1] = \
                        (line_b_arr[pos_arr_end - 1] & 0xf) | \
                        bytes_clip_shift[-1]
        elif last_n_unused_clip_right:
            # TODO, avoid duplication (?)
            pos_arr_end = pos_arr + len(bytes_clip_right)
            # bytearray for Py 2 compatibility!
            _transparent_copy_4bpp(line_b_arr,
                                   bytearray(bytes_clip_right[:-1]), pos_arr,
                                   transp_col)

            if (bytes_clip_right[-1] >> 4) != transp_col:
                line_b_arr[pos_arr_end - 1] = \
                    (line_b_arr[pos_arr_end - 1] & 0xf) | \
                    (bytes_clip_right[-1] & 0xf0)
        else:
            _transparent_copy_4bpp(line_b_arr, bytearray(bytes_clip_right),
                                   pos_arr, transp_col)


class PngMerger_8BPP(PngMergerBase):
    '''
    PngMergerBase subclass that produces 8 BPP, indexed color PNG as output.
        Accepts two input formats: 1. 8BPP  PNG image with an palette
        identical with output image. 2. a 4BPP image that has a "compatible"
        palette i.e. there is an equivalent for all non-transparent colors.
        Implements the two abstract methods of parent (create_empty_canvas,
        copy_single_line), modifies process_palette_data (for 4BPP->8BPP).
    '''

    # png_exporter_obj_id, transp_col_opt_id: modified from parent,
    #     the appropriate values for 8BPP output
    png_exporter_obj_id = s_obj_pngexp256
    transp_col_opt_id = s_opt_transpcol256
    # input_bit_depths_supported: Supports both 4BPP and 8BPP PNG files
    input_bit_depths_supported = (_BPP_4, _BPP_8)

    # find_nearest_color_max_diff: Maximum difference allowed in
    #     4BPP color matching
    find_nearest_color_max_diff = 3000

    def create_empty_canvas(self):
        '''
        Re-implements create_empty_canvas(). Sets self.out_image_lines to
            a list of bytearrays that is suitable for storing the 8BPP data.
        '''
        self.out_image_lines = [
            bytearray((self.background_color, )) * self.canvas_width
            for x in xrange(self.canvas_height)
        ]

    def reset_sub_image_data_sublass(self):
        '''Re-implements reset_sub_image_data_sublass.'''
        # pal_indices_4bpp: A byte array containing the indices in
        #     the 256-color palette that will be used for the 4BPP image
        #     None if the added image has a 256-color palette.
        self.pal_indices_4bpp = None

    def process_palette_data(self, pal_data):
        '''
        Re-implements process_palette_data to support both 4BPP and 8BPP
            input. For 4BPP input, calls find_nearest_colors_4bpp and
            sets pal_indices_4bpp.
        pal_data (bytes): See parent class.
        '''
        if self.added_image_bit_depth == _BPP_8:
            PngMergerBase.process_palette_data(self, pal_data)
        elif self.added_image_bit_depth == _BPP_4:
            self.pal_indices_4bpp = self.find_nearest_colors_4bpp(pal_data)

    def find_nearest_colors_4bpp(self, pal_data):
        '''
        Function for finding the matching colors in the 256 color output
            palette. Returns a bytearray containing the indices of the
            closest color in the 256 color palette for each entry in the
            16 color data.
        pal_data (bytes): RGB values for each color
        '''
        pal_indices = bytearray()

        # TODO FIXME: the transparent color is currently obtained
        #     from the s_opt_transpcol16 option, not the image
        transp16 = self.parent.get_option(s_opt_transpcol16)
        transp256 = self.parent.get_option(s_opt_transpcol256)

        for color_id_16, arr_index_16 in enumerate(xrange(0, len(pal_data),
                                                          3)):

            if (transp16 is not None) and (transp16 == color_id_16):
                if transp256 is None:
                    raise RuntimeError('Transparent color required for '
                                       '4BPP to 8BPP conversion')

                pal_indices.append(transp256)
                continue

            color_nearest = None
            color_diff_min = self.find_nearest_color_max_diff
            color_16 = bytearray(pal_data[arr_index_16:arr_index_16 + 3])

            for color_id_256, arr_index_256 in enumerate(
                    xrange(0, len(self.pal_exporter), 3)):

                color_256 = bytearray(
                    self.pal_exporter[arr_index_256:arr_index_256 + 3])
                diff = color_dist(color_16, color_256)

                if diff < color_diff_min:
                    color_nearest = color_id_256
                    color_diff_min = diff

            if color_nearest is None:
                raise RuntimeError(('No color close to #%d (%d, %d, %d) found '
                                    ' in the 256-color palette.') %
                                   ((color_id_16, ) + tuple(color_16)))

            pal_indices.append(color_nearest)

        # NOTE that output bytearray may contain less than 16 color IDs
        return pal_indices

    def _convert_4bpp_line_to_8bpp(self, data_4bpp):
        '''
        Converts 4BPP data to 8BPP using the color indices
            in self.pal_indices_4bpp. Returns the 8BPP data that can
            be used in copy_single_line. (type: bytearray)
        data_4bpp: The line from the 4BPP bitmap. Must be bytearray
            for Python 2 compatibility.
        '''
        #
        data_8bpp = bytearray().join(
            bytearray((self.pal_indices_4bpp[x >> 4],
                       self.pal_indices_4bpp[x & 0xf])) for x in data_4bpp)

        # One nibble at the end is unused in 4BPP images, remove the
        #     corresponding byte if needed
        return data_8bpp[:-1] if self.added_image_width & 1 else data_8bpp

    def copy_single_line(self, line_b_arr, line_bytes, pos_x):
        '''
        Re-implements copy_single_line(), see the meaning of arguments
            in parent class.
        Supports both 8BPP and 4BPP input data, the latter is converted to
            8BPP format using self._convert_4bpp_line_to_8bpp.
        Supports clipping at the left and right edges of output image.
        '''
        # NOTE that this function must support clipping!

        # ... 0. Convert 4 BPP line to 8 BPP if needed ...
        if self.pal_indices_4bpp is not None:
            # NOTE: bytearray for Python 2 compatibility
            line_bytes_conv = self._convert_4bpp_line_to_8bpp(
                bytearray(line_bytes))
        else:
            line_bytes_conv = line_bytes

        # ... 1. Left clip of line_bytes_conv ...
        if pos_x < 0:
            pos_x_clip = 0
            bytes_clip_left = line_bytes_conv[(-pos_x):]
        else:
            pos_x_clip = pos_x
            bytes_clip_left = line_bytes_conv

        len_bytes_clip_left = len(bytes_clip_left)

        # ... 2. Right clip of line_bytes_conv ...

        if pos_x_clip + len_bytes_clip_left > self.canvas_width:
            bytes_clip_right = bytes_clip_left[:self.canvas_width - pos_x_clip]
        else:
            bytes_clip_right = bytes_clip_left

        if not bytes_clip_right: return  # HACK

        # ... 3. Modify line_b_arr ...
        transp_col = self.transparent_color

        if transp_col is not None:
            # NOTE: bytearray() for Py 2 compatibility
            for i_bytes_cl, b_bytes_cl in enumerate(
                    bytearray(bytes_clip_right), pos_x_clip):
                # NOTE: Transparency is implemented in "pure Python"
                #    and can be SLOW
                if b_bytes_cl != transp_col:
                    line_b_arr[i_bytes_cl] = b_bytes_cl
        else:
            line_b_arr[pos_x_clip:pos_x_clip +
                       len(bytes_clip_right)] = bytes_clip_right
