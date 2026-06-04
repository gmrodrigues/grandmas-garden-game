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

# --- Decoder base class for image formats with multiple sub-images ---

'''
This module contains base classes for implementing decoders
    (ResDataBase_Decoder subclasses) for multi sub-image bitmap resources.
    SubFileDecoder_MultiSubImg: Base class for such decoders
    SubFileDecoder_Base_BMP_BIN_VGA: Decoder for images with a specific
        chunk format
    Mixins and functions implementing such decoder subclasses
'''

import struct
from collections import namedtuple

from timgres.base.basecl import ResDataBase_Decoder
from timgres.base.misc import (print_msg, print_traceback, s_opt_zoom,
                               s_obj_prefix_pngexp, s_obj_pngexp16,
                               s_obj_pngexp256, s_obj_chunkuncompr)
from timgres.base.nibblarr import _single_char, _b_array_shift_left_4

# Possible values for flip.
# Note: flip_vertical and flip_horizontal are also used as bit "flags"!

flip_none = 0
flip_vertical = 1
flip_horizontal = 2
flip_vertical_horizontal = 3

# nt_bm_data: The return type of bitmap parsers
# bm_info is currently subclass dependent
# sub_images: list of nt_bm_sub_image_data namedtuples, containing the data
#     for each sub-image

nt_bm_data = namedtuple('nt_bm_data', ('bm_info', 'sub_images'))

# nt_pal_data: return type of palette parsers
# pal_colors: A list containing one item for each color
#   Inner lists must have a length of 3 and must contain the R, G, B
#   values (0..255)
# transp_col: Either a transparent color code or None
# pal_info: A class-specific namedtuple or None

nt_pal_data = namedtuple('nt_pal_data',
                         ('pal_colors', 'transp_col', 'pal_info'))

# nt_bm_sub_img_data: Information for each sub image as returned by a
#     multi sub-image decoder. Stored in the sub_images list in the
#     nt_bm_data namedtuple.
# sub_img_info: a decoder class specific namedtuple
# out_w, out_h (int): the width and the height of the decoded image
# last 3 fields, including png_data are None when an error occurred
# NOTE:: png_data_flip: a tuple of 4 elements or a single "bytes" string
#   if the class does not support this

nt_bm_sub_img_data = namedtuple(
    'nt_bm_sub_image_data',
    ('sub_img_info', 'out_w', 'out_h', 'png_data_flip'))

# nt_process_options_bm: Options for decoding an image resource, see also
#     ResDataBase_Decoder.decode_sub_file. Currently, the program supports
#     limiting the conversions to: 1. only specific sub-images
#     (process_sub_imgs) and 2. only specific "flips" (allow_flips)
# Type of both fields: be either None or any type that supports the "in"
#     operator (set, tuple, list) (None means convert all.)
nt_process_options_bm = namedtuple('nt_process_options_bm',
                                   ('process_sub_imgs', 'allow_flips'))


class SubFileDecoder_MultiSubImg(ResDataBase_Decoder):
    '''
    Sub-file decoder base class (inherits ResDataBase_Decoder) for image
        formats that can have multiple sub-images. Has three abstract methods:
        add_png_lines_flipped (must support zooming & flipping),
        decode_sub_image (must decode one sub-image) and decode_header_data
        (must process the data from the chunks before the pixel data chunk
        and locate the sub-images in the appropriate chunk)
    '''
    # Note that the class does not re-implement is_file_type_supported
    #     this must be done in sub-classes

    # file_ext: the file extension, must be modified in sub-classes
    file_ext = ''
    # png_exporter_obj_id: ID of png exporter object in parent, must be
    #     modified in sub-classes
    png_exporter_obj_id = ''

    def __init__(self):
        '''The constructor of the class, requires no argument.'''
        ResDataBase_Decoder.__init__(self)
        self.reset_conv_data()

    def reset_conv_data(self):
        '''
        Resets default values of the fields cotaining the output data
            (see get_data). Has no args and no return value.
        '''
        # process_options: nt_process_options_bm, see vdobase
        self.process_options = None
        # out_conv_bmp_info: decoder-specific information namedtuple (or None)
        #     returned by get_data() (as a field of nt_bm_data)
        self.out_conv_bmp_info = None  # nt_bm_info_t12
        # out_conv_png_data: list of nt_png_out namedtuples
        #     returned by get_data() (as a field of nt_bm_data)
        self.out_conv_png_data = []

    def reset_sub_img_data(self):
        '''
        Resets the fields containing information about the currently processed
            sub-image to their default values.
        '''
        # data for sub-file, sub-image + information used in error messages
        # data_sub_img: bytes, the binary data for the current sub-image
        self.data_sub_img = None
        # sub_img_info: a class-specific namedtuple
        self.sub_img_info = None  # nt_bm_sub_img_info_t12
        # extra_info: may be used for class_specific purposes
        self.extra_info = None
        # png_export: the png exporter, set in process_sub_image
        self.png_export = None
        # img_width, img_height: decode_sub_image must set these fields
        self.img_width = None
        self.img_height = None

        self.reset_decode_temp_data()

    def reset_decode_temp_data(self):
        '''
        Does nothing in the SubFileDecoder_MultiSubImg base class
        In sub-classes it can be used for adding fields that are automatically
            cleared after decoding.
        '''
        pass

    def format_err_msg_file_info(self):
        '''Should be used only in sub-classes, for error messages'''
        return (
            'Sub-file "%s.%s", sub-image %d: ' %
            (self.sub_img_info[0], self.file_ext,
             (self.sub_img_info[1]) if self.sub_img_info is not None else ''))

    def add_png_lines_flipped(self, flip):
        '''
        Not implemented in SubFileDecoder_MultiSubImg.
        When re-implemented in a subclass:
            self.png_export.add_line must be called for each line
        flip (int, 0-3): see flip_* constants
        '''
        raise RuntimeError('add_png_lines_flipped: Not implemented '
                           ' in SubFileDecoder_MultiSubImg')

    def decode_sub_image(self):
        '''
        Not implemented in SubFileDecoder_MultiSubImg.
        When re-implemented in a subclass:
            1. The sub-image data must be decoded
            2. self.img_width, self.img_height must be set
        '''
        raise RuntimeError('decode_sub_image: Not implemented '
                           ' in SubFileDecoder_MultiSubImg')

    def process_sub_image(self,
                          new_data,
                          new_sub_img_info,
                          new_extra_info=None):
        '''
        For internal use. Must be called from the decode_header_data
            method of subclasses. Calls decode_sub_image and
            add_png_lines_flipped
        new_data (bytes): The data (not decoded) of the sub-image
        new_sub_img_info: A subclass-specific namedtuple, will be stored
            in the sub_img_info field of nt_bm_sub_img_data
        new_extra_info: Class specific data or None
        '''
        if not isinstance(new_data, (bytes, bytearray)):
            raise TypeError('new_data: must be bytearray or bytes')

        if not isinstance(new_sub_img_info, tuple):
            raise TypeError(
                'new_sub_img_info: must be class-specific namedtuple')

        self.data_sub_img = new_data
        self.sub_img_info = new_sub_img_info
        self.extra_info = new_extra_info

        try:
            self.png_export = self.parent.get_object(self.png_exporter_obj_id)

            if self.process_options.process_sub_imgs is not None:
                if (new_sub_img_info.part_id
                        not in self.process_options.process_sub_imgs):
                    # FIXME: "Indistinguishable" from error
                    self.out_conv_png_data.append(
                        nt_bm_sub_img_data(new_sub_img_info, None, None, None))

                    return

            self.decode_sub_image()

            out_flipped = []

            for flip in xrange(4):
                if self.process_options.allow_flips is not None:
                    if flip not in self.process_options.allow_flips:
                        out_flipped.append(None)
                        continue

                self.png_export.reset_image()
                self.png_export.set_width_height(self.img_width,
                                                 self.img_height)
                self.add_png_lines_flipped(flip)
                out_flipped.append(self.png_export.get_png_data())

            self.out_conv_png_data.append(
                nt_bm_sub_img_data(self.sub_img_info, self.img_width,
                                   self.img_height, tuple(out_flipped)))

            self.png_export.reset_image()

        except Exception as ex:
            # add a "placeholder" if an error occurred

            self.out_conv_png_data.append(
                nt_bm_sub_img_data(self.sub_img_info, None, None, None))

            print_msg('Error, %s sub-image conversion failed: %s' %
                      (self.format_err_msg_file_info(), ex))
            print_traceback()

    def decode_header_data(self, f_name_part, file_data):
        '''
        Not implemented in SubFileDecoder_MultiSubImg.
        When re-implemented in a subclass:
            1. self.out_conv_bmp_info must be set to a
                class-specific namedtuple
            2. self.process_sub_image must be called for each part
        '''
        raise RuntimeError('decode_header_data: Not implemented '
                           ' in SubFileDecoder_MultiSubImg')

    def process_sub_file(self, f_name_part, file_data, process_options):
        '''
        Re-implements process_sub_file from ResDataBase_Decoder.
        See meaning of arguments there (base.basecl)
        Provides basic type checking for file_data and process_options
        '''
        self.reset_conv_data()
        self.reset_sub_img_data()

        if self.parent is None:
            raise RuntimeError('BMP decode: parent not set')

        # For allowing setting png_exporter_obj_id only later, in
        #     in decode_header_data

        if self.png_exporter_obj_id:
            png_export = self.parent.get_object(self.png_exporter_obj_id)

            if not png_export.has_palette():
                raise RuntimeError(
                    '%s decode: No palette for %s-color converter' %
                    (self.file_ext,
                     self.png_exporter_obj_id[len(s_obj_prefix_pngexp):]))

        if not isinstance(file_data, bytes):
            raise TypeError(
                '%s decode: file_data: must be bytes' % self.file_ext)

        if process_options is not None:
            if not isinstance(file_data, bytes):
                raise TypeError(('%s decode: process_options: must be'
                                 'nt_process_options_bm') % self.file_ext)

            self.process_options = process_options
        else:
            self.process_options = nt_process_options_bm(None, None)

        self.decode_header_data(f_name_part, file_data)
        self.reset_sub_img_data()

    def get_data(self):
        '''
        Re-implements get_data from ResDataBase_Decoder.
        Returns the data as a nt_bm_data namedtuple.
        '''
        return nt_bm_data(self.out_conv_bmp_info, list(self.out_conv_png_data))


# ... 4BPP helper functions ...


def _dupl_nibble(nibble):
    '''
    "Private" function. Returns a byte (int) with two identical nibbles.
    nibble (int)
    '''
    return ((nibble << 4) & 0xf0) | (nibble & 0xf)


def _rep_nibbles_even_odd(byte, half_rep_cnt, rep_cnt_odd):
    '''
    "Private" function. Repeats both nibbles of a single byte
        (byte - int). rep_cnt_odd and half_rep_cnt (both ints) are the
        least significant bit and all other bits (shifted by 1) of the
        repeat count, respectively.
    Returns a list that will be used in zoom_line_4bpp
    '''
    return ([_dupl_nibble(byte >> 4)] * half_rep_cnt +
            ([byte] if rep_cnt_odd else []) +
            [_dupl_nibble(byte & 0xf)] * half_rep_cnt)


def _swap_nibbles(byte):
    '''"Private" function, swaps the two nibbles of a byte'''
    return ((byte & 0xf) << 4) | (byte >> 4)


def zoom_line_4bpp(line_nibbles, last_nibble_unused, zoom):
    '''
    Repeats all nibbles of a bytes or a bytearray (or any iterable that
        returns bytes). Used for zooming lines in 4BPP (16-color) bitmaps
    line_nibbles (iterable, bytes or bytearray): any iterable that
        contains the input nibbles

    last_nibble_unused: True if the number of nibbles is odd, thus
        the lower-order 4-bits of last byte are unused
    zoom: all nibbles will be repeated "zoom" times
    returns tuple: output byte array, last nibble unused (bool) in output
    '''

    # NOTE: No type check!
    half_zoom = zoom >> 1
    zoom_odd = zoom & 1

    if zoom == 1:
        b_arr_1 = bytearray(line_nibbles)
    else:
        b_arr_1 = bytearray(
            itertools.chain.from_iterable(
                _rep_nibbles_even_odd(_single_char(x), half_zoom, zoom_odd)
                for x in line_nibbles))

    if last_nibble_unused:
        # hack, remove repeated "superfluous" nibble
        b_arr_2 = b_arr_1[:-half_zoom] if half_zoom else b_arr_1
        if zoom_odd: b_arr_2[-1] &= 0xf0
    else:
        b_arr_2 = b_arr_1

    return b_arr_2, last_nibble_unused and zoom_odd


def horizontal_flip_lines_4bpp(in_lines, last_nibble_unused):
    '''
    Used for horizontal flipping of a list of rows from a 4BPP bitmap
    in_lines: iterable of input lines
    last_nibble_unused: see zoom_line_4bpp (one nibble unused at the end if
        the width is odd)
    returns a list of bytearrays, one bytearray for each row.
    '''
    # No type check

    if last_nibble_unused:
        return [
            bytearray(
                _swap_nibbles(_single_char(y))
                for y in _b_array_shift_left_4(x, True)[::-1])
            for x in in_lines
        ]
    else:
        return [
            bytearray(_swap_nibbles(_single_char(y)) for y in x[::-1])
            for x in in_lines
        ]


class RawBMData4BPPMixin(object):
    '''
    Can be used to implement the add_png_lines_flipped method in an
        SubFileDecoder_MultiSubImg subclass
    Input is raw 4 BPP image data that has already been uncompressed)
    Implemented as a "mixin" due to the dependency on "self", "self.parent"
    '''

    def add_png_lines_flipped_4bpp(self, raw_bm_data, width, height, flip):
        '''
        Method that can be used in an add_png_lines_flipped implementation
        raw_bm_data (bytes, bytearray): The raw bitmap data for the sub-image,
              already decoded or uncompressed
        width, height (int): the width and the height of the bitmap
        flip (int): see flip_* constants
        '''
        zoom = self.parent.get_option(s_opt_zoom)
        width_bytes = (width + 1) >> 1
        size_calc = width_bytes * height
        last_n_unused = width & 1
        last_n_unused_zoom = (width * zoom) & 1

        rng_line_start = (xrange(size_calc - width_bytes, -1, -width_bytes)
                          if flip & flip_vertical else xrange(
                              0, size_calc, width_bytes))

        lines_1 = [
            zoom_line_4bpp(raw_bm_data[x:x + width_bytes], last_n_unused,
                           zoom)[0] for x in rng_line_start
        ]

        lines_2 = (horizontal_flip_lines_4bpp(lines_1, last_n_unused_zoom) if
                   (flip & flip_horizontal) else lines_1)

        for line_2 in lines_2:
            for cnt in xrange(zoom):
                self.png_export.add_line(line_2)


class RawBMData8BPPMixin(object):
    '''
    Can be used to implement the add_png_lines_flipped method in an
        SubFileDecoder_MultiSubImg subclass
    Input is raw 8 BPP image data that has already been uncompressed)
    '''

    def add_png_lines_flipped_8bpp(self, raw_bm_data, width, height, flip):
        '''
        Method that can be used in an add_png_lines_flipped implementation
        See meaning of arguments in add_png_lines_flipped_4bpp
        '''
        zoom = self.parent.get_option(s_opt_zoom)
        size_calc = width * height

        rng_line_start = (xrange(size_calc - width, -1, -width) \
            if flip & flip_vertical else xrange(0, size_calc, width))

        for line_start in rng_line_start:
            # In Python3, x[i] (x->bytes) returns an int,
            #     not a single_char bytes obj!
            line_1 = b''.join(raw_bm_data[x:x + 1] * zoom
                              for x in xrange(line_start, line_start + width))

            line_2 = line_1[::-1] if flip & flip_horizontal else line_1

            for cnt in xrange(zoom):
                self.png_export.add_line(line_2)


chunk_index_size = 4
chunk_data_start = 8

format_compr_info = '<BL'


def _nibble_swap_2_bytes(byte_1, byte_2):
    ''' "Private" function.
    Returns two bytes, the less significant nibbles of the two output bytes
         are both taken from byte_1 and the more significant nibbles from
         byte_2. Follows a "more significant nibble first" convention
         for both input bytes. e.g. 0x12 0x34 -> 0x31 0x42
    '''
    # Note: Does not range check either of the bytes
    return (byte_1 >> 4) | (byte_2 & 0xf0), (byte_1 & 0xf) | (
        (byte_2 & 0xf) << 4)


def _nibble_swap_2_bytes_zoomed(byte_1, byte_2, zoom):
    ''' "Private" function.
    Similar to _nibble_swap_2_bytes, but retuns a "zoomed" bytearray.
    (all three args must be int.)
    '''
    swapped_1, swapped_2 = _nibble_swap_2_bytes(byte_1, byte_2)
    return bytearray((swapped_1, ) * zoom + (swapped_2, ) * zoom)


class SubFileDecoder_Base_BMP_BIN_VGA(SubFileDecoder_MultiSubImg,
                                      RawBMData4BPPMixin):
    '''
    Decoder base class for .BMP files that contain a "BIN:" and optionally
        a "VGA:" chunk (latter is present if the image has 256 colors.)
    Implements reset_sub_img_data, add_png_lines_flipped and
        decode_sub_image. Does not implement decode_header_data, but provides
        a "helper" function decode_bin_vga_chunks for such an implementation
    Requires an "img_w" and an "img_h" field in the self.sub_img_info n.tuple
    '''

    def reset_sub_img_data(self):
        '''Re-implements reset_sub_img_data from SubFileDecoder_MultiSubImg'''
        SubFileDecoder_MultiSubImg.reset_sub_img_data(self)
        # data_uncompr_bin: the uncompressed data from the "BIN:" chunk
        self.data_uncompr_bin = None
        # data_uncompr_vga: the uncompressed data from the "VGA:" chunk
        #     or None if there is no such chunk
        self.data_uncompr_vga = None
        # compr_algorithm_bin, compr_algorithm_vga: the "compression
        #     algorithm filed for the two chunks (the latter can be None)
        self.compr_algorithm_bin = None
        self.compr_algorithm_vga = None
        # data_size_bin_vga: the uncompressed size of the two chunks
        #     The two sizes must match if both chunks are present
        self.data_size_bin_vga = None

    def add_png_lines_flipped(self, flip):
        '''
        Re-implements add_png_lines_flipped from SubFileDecoder_MultiSubImg
        See description of arguments there
        '''
        width = self.sub_img_info.img_w
        height = self.sub_img_info.img_h

        if self.extra_info is None:
            self.add_png_lines_flipped_4bpp(self.data_sub_img, width, height,
                                            flip)
            return

        zoom = self.parent.get_option(s_opt_zoom)
        width_bytes = (width + 1) >> 1
        size_calc = width_bytes * height

        # From documentation found at ModdingWiki,
        #     http://www.shikadi.net/moddingwiki/RES_Format_(Stellar_7)
        #     the "VGA:" chunk (here self.extra_info) contains the more
        #     significant nibbles

        rng_line_start = xrange(size_calc - width_bytes, -1, -width_bytes) \
            if flip & flip_vertical else xrange(0, size_calc, width_bytes)

        for line_start in rng_line_start:

            line_1 = b''.join(
                _nibble_swap_2_bytes_zoomed(_single_char(self.data_sub_img[x]),
                                            _single_char(self.extra_info[x]),
                                            zoom)
                for x in xrange(line_start, line_start + width_bytes))

            # If the width of the image is odd, one pixel (* zoom) must be
            #      removed because 16 BPP images have an "extra" unused nibble
            #      at the end of each row

            line_2 = line_1[:-zoom] if width & 1 else line_1
            line_3 = line_2[::-1] if flip & flip_horizontal else line_2

            for cnt in xrange(zoom):
                self.png_export.add_line(line_3)

    def decode_sub_image(self):
        '''Re-implements decode_sub_image from SubFileDecoder_MultiSubImg'''
        zoom = self.parent.get_option(s_opt_zoom)
        self.img_width = self.sub_img_info.img_w * zoom
        self.img_height = self.sub_img_info.img_h * zoom

    def decode_bin_vga_chunks(self, f_name_part, data_bin_vga):
        '''
        A method that can be used in an implementation of decode_header_data
            in a subclass.
        f_name_part (str): The f_name_part argument passed to
            decode_header_data
        data_bin_vga (bytes): Part of the file data that begins at the
            "BIN:" chunk
        '''
        # Sets the fields defined in (re-implemented) reset_sub_img_data
        _err_decode = '%s decode (file "%s.%s")' % (self.file_ext, f_name_part,
                                                    self.file_ext)

        if data_bin_vga[:chunk_index_size] != b'BIN:':
            raise RuntimeError(_err_decode + 'Invalid chunk data.')

        bin_data_size = struct.unpack_from('<L', data_bin_vga,
                                           chunk_index_size)[0]

        # According to the documentation at ModdingWiki
        #     (http://www.shikadi.net/moddingwiki/RES_Format_(Stellar_7)),
        #     there exists a type of SCR files that contain an additional
        #     VGA chunk. Such a file would contain the lower-order nibbles
        #     of the 8-bit data in the "BIN:" and the higher-order 4 bits
        #     on the "VGA:" chunk.

        bin_data_end = chunk_data_start + bin_data_size
        has_vga_chunk = False

        if bin_data_end <= (len(data_bin_vga) - 4):
            if data_bin_vga[bin_data_end:bin_data_end + 4] == b'VGA:':
                has_vga_chunk = True

        # Otherwise, the file decoding ends at the end of "BIN:" chunk

        # FIXME, compression algorithm and uncompressed size unpacked twice
        #      (again in ch_uncompr)

        self.compr_algorithm_bin, uncompr_size = struct.unpack_from(
            format_compr_info, data_bin_vga, chunk_data_start)

        ch_uncompr = self.parent.get_object(s_obj_chunkuncompr)
        ch_uncompr.process_data(data_bin_vga[chunk_data_start:bin_data_end])
        self.data_uncompr_bin = ch_uncompr.get_data()

        if has_vga_chunk:

            vga_data_size = struct.unpack_from(
                '<L', data_bin_vga, bin_data_end + chunk_index_size)[0]

            vga_data_start = bin_data_end + chunk_data_start
            vga_data_end = vga_data_start + vga_data_size

            self.compr_algorithm_vga, uncompr_size_vga = struct.unpack_from(
                format_compr_info, data_bin_vga, vga_data_start)

            if uncompr_size_vga != uncompr_size:
                raise RuntimeError(
                    'Mismatch between the uncompressed sizes '
                    'of the "BIN:" and the "VGA:" chunk, %d vs. %d' %
                    (uncompr_size, uncompr_size_vga))

            vga_data_end = vga_data_start + bin_data_size
            # Any chunk after the end of "VGA:" is ignored
            ch_uncompr.process_data(data_bin_vga[vga_data_start:vga_data_end])
            self.data_uncompr_vga = ch_uncompr.get_data()

            self.png_exporter_obj_id = s_obj_pngexp256
            num_bits = 256
        else:
            # NOTE: png_exporter_obj_id is set here, not at class declaration
            self.data_uncompr_vga = None
            self.png_exporter_obj_id = s_obj_pngexp16
            num_bits = 16

        self.data_size_bin_vga = uncompr_size
        # FIXME "duplicates" check in SubFileDecoder_MultiSubImg
        png_export = self.parent.get_object(self.png_exporter_obj_id)

        if not png_export.has_palette():
            raise RuntimeError('%s: No palette for %d-bit PNG converter.' %
                               (_err_decode, num_bits))
