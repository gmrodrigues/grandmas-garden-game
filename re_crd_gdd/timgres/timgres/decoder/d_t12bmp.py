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

import struct
from collections import namedtuple

from timgres.base.nibblarr import NibbleArrayMSF, _single_char
from timgres.base.bmpdbase import (flip_horizontal, flip_vertical,
                                   SubFileDecoder_MultiSubImg,
                                   horizontal_flip_lines_4bpp)
from timgres.base.misc import (print_msg, print_traceback, s_obj_pngexp16,
                               s_opt_transpcol16, s_opt_zoom)

# --- BMP sub-file decoder, containing "SCN:" chunk, TIM and TIM 2 ---

'''
This module contains the image decoder class SubFileDecoder_Bmp_T12 for .BMP
    resources that consist of a BMP: header (8 bytes)
    followed by an "INF:" an "SCN:" and an "OFS:" chunk. Note that this
    decoder unlike other formats, does not depend on ChunkUncompressorBase
    (base.dcunbase) at all.
'''

# I would like to acknowledge Nyerguds, the developer of "Engie File Converter"
#     for conducting addditional reserch on the "SCN:"/"OFS" file format.
# The improved and expanded documentation for the format written by him
#     is available at ModdingWiki:
# https://moddingwiki.shikadi.net/wiki/The_Incredible_Machine_Image_Format

nt_fields_bm_info_t12 = ('f_name_part', 'bmp_chunk_size', 'size_inf',
                         'size_scn', 'size_off')

nt_fields_bm_sub_img_info_t12 = ('f_name_part', 'part_id', 'p_start_scn',
                                 'p_size_scn', 'inf_w', 'inf_h')

# nt_bm_info_t12: Namedtuple containing information extracted
#     from the header of the image file.
# Will be stored as the bm_info member of nt_bm_data namedtuple
# f_name_part (str): The input file name without extension
# bmp_chunk_size (int): The size of the "BMP:" chunk
#     see comment at "head_chunk_size" in decode_header_data
# size_inf, size_scn, size_off: Size, in bytes, of the "INF:", "SCN:"
#     and the "OFS:" chunks, respectively
nt_bm_info_t12 = namedtuple('nt_bm_info_t12', nt_fields_bm_info_t12)

# nt_fnt_symbol_info: Contains information for each sub-image
#     from the file. (TODO: add field description)
# Will be stored as the sub_img_info member of nt_bm_sub_img_data namedtuple
# f_name_part (str): The input file name without extension
# part_id (int): The index of the sub-image in the input (and output).
# p_start_scn (int): Start position of the sub-image data in input data,
#     relative to the start of the "SCN:" chunk
# p_size_scn (int): Size of the sub-image data in input data ("SCN:")
# inf_w, inf_h (int): The width and the height of the sub-image,
#     from the "INF:" chunk.
nt_bm_sub_img_info_t12 = namedtuple('nt_bm_sub_img_info_t12',
                                    nt_fields_bm_sub_img_info_t12)

str_err_sub_image_end = 'Sub-image ends at wrong position.'
str_err_no_transp_col = 'A transparent color must be set for this option.'

# ... Helper functions ...

# One interesting feature of the BMP/SCN/OFF (t12bmp) file format is
#     that the value of the first byte must be added to all pixel values.
#     (add_val in the functions)


def _t12bmp_color_2_nibbles(byte, add_val):
    '''
    Adds add_val (int) to both nibbles of a byte (int). Returns int.
    '''
    return (((byte & 0xf0) + (add_val << 4)) & 0xf0) | \
           (((byte & 0xf) + add_val) & 0xf)


def _t12bmp_dupl_nibble(nibble, add_val):
    '''
    Returns a byte (int) with two identical nibbles (nibble - int).
        Adds add_val (int) to both nibbles.
    '''
    return (((nibble + add_val) << 4) & 0xf0) | ((nibble + add_val) & 0xf)


def _t12bmp_rep_nibbles_even_odd(byte, add_val, half_rep_cnt, rep_cnt_odd):
    '''
    "Private" function. similar to _rep_nibbles_even_odd (base.bmpdbase).
    Repeats both nibbles of a single byte (byte - int). Adds add_val (int)
        to all "used" nibbles in the output.
    rep_cnt_odd and half_rep_cnt (both ints) are the
        least significant bit and all other bits (shifted by 1) of the
        repeat count, respectively.
    Returns a list that will be used in _t12bmp_zoom_line_4bpp
    '''
    return ([_t12bmp_dupl_nibble(byte >> 4, add_val)] * half_rep_cnt +
            ([_t12bmp_color_2_nibbles(byte, add_val)] if rep_cnt_odd else []) +
            [_t12bmp_dupl_nibble(byte & 0xf, add_val)] * half_rep_cnt)


# Note: this class does not use zoom_line_4bpp from bmpdbase


def _t12bmp_zoom_line_4bpp(line_nibbles, last_nibble_unused, add_val, zoom):
    '''
    "Private" function. similar to zoom_line_4bpp (base.bmpdbase).
    Repeats all nibbles of a bytes or a bytearray (or any iterable that
        returns bytes). Adds "add_val" to all "used" nibbles in the output.
    line_nibbles (iterable, bytes or bytearray): any iterable that
        contains the input nibbles
    last_nibble_unused (bool): True if the number of nibbles is odd, thus
        the lower-order 4-bits of last byte are unused
    add_val (int): This value will be added to all nibbles to the output.
    zoom (int): all nibbles will be repeated "zoom" times
    returns tuple: output byte array, last nibble unused (bool) in output
    '''
    half_zoom = zoom >> 1
    zoom_odd = zoom & 1

    if zoom == 1:
        b_arr_1 = bytearray(
            _t12bmp_color_2_nibbles(_single_char(x), add_val)
            for x in line_nibbles)
    else:
        b_arr_1 = bytearray(
            itertools.chain.from_iterable(
                _t12bmp_rep_nibbles_even_odd(_single_char(
                    x), add_val, half_zoom, zoom_odd) for x in line_nibbles))

    if last_nibble_unused:
        # hack, remove repeated "superfluous" nibble
        b_arr_2 = b_arr_1[:-half_zoom] if half_zoom else b_arr_1
        if zoom_odd: b_arr_2[-1] &= 0xf0
    else:
        b_arr_2 = b_arr_1

    return b_arr_2, last_nibble_unused and zoom_odd


pos_inf_bmp = 12
pos_after_inf_size = 16
chunk_prefix_size = 8
scn_data_head = 9

# In empty images, the first, "color" byte has this value
color_byte_empty = 0xff
str_err_decode_empty_image = 'Invalid RLE command in "empty" image'

# TODO: According to the findings by Nyerguds, the "BMP:"/"SCN:" file format
#     also has a 8 BPP version. This 8 BPP format is not supported yet.
#     However, no known version of The Incredible Machine uses this format, so
#     it is not a high priority for now.


class SubFileDecoder_Bmp_T12(SubFileDecoder_MultiSubImg):
    '''
    This class implements a decoder for a ".BMP" file format that contains
        the following chunks: "BMP:", "INF:", "SCN:" and "OFS:". Note
        that this  decoder unlike other formats, does not depend on
        ChunkUncompressorBase (base.dcunbase)
    '''

    # file_ext: the file extension, modified from parent
    file_ext = 'BMP'
    # ID of png exporter object in parent, modified from parent
    png_exporter_obj_id = 'pngexp16'

    def __init__(self):
        '''The constructor of the class, requires no arguments.'''
        SubFileDecoder_MultiSubImg.__init__(self)
        # n_arr: The "nibble array" object used for conversion.
        self.n_arr = NibbleArrayMSF()

    def reset_out_png_lines(self):
        '''Initializes the out_png_lines, storing temporary data.'''
        # lines_zoom (list of "bytes"): Stores temporary data for
        #    image flipping.
        self.out_png_lines = []
        # lines_flipped (list of "bytes" or None): The lines flipped
        #     horizontally (or None if not set/not required).
        self.lines_flipped = None

    def reset_decode_temp_data(self):
        '''
        Re-implementation of reset_decode_temp_data from
            SubFileDecoder_MultiSubImg (base,bmpdbase).
            Calls reset_out_png_lines.
        '''
        self.reset_out_png_lines()
        # color_transparent: The transparent color, obtained from self.parent
        self.color_transparent = None
        # # color_transparent: Zoom (int), obtained from self.parent
        self.zoom = None

    def add_png_line(self):
        '''
        For "internal" use. Adds a line to self.out_png_lines.
            Data for the new line is stored in self.n_arr. If the line
            is shorter than the image width, transparent pixels are appended
            to the end.
        '''
        width = self.img_width
        pos_x = len(self.n_arr)

        if pos_x > width:
            raise RuntimeError('BMP/SCN sub-image: Line too long: '
                               '%d px, expected %d px' % (pos_x, width))

        if pos_x < width:
            if self.color_transparent is None:
                raise RuntimeError(str_err_no_transp_col)

            # NOT multiplied by zoom!
            self.n_arr.append_nibble_repeated(self.color_transparent,
                                              width - pos_x)

        # modified, "vertical" zooming is done by "flip" code

        self.out_png_lines.append(self.n_arr.get_bytes())
        self.n_arr.reset()

    def decode_single_sub_image(self):
        '''
        For internal use. Most of the code for decoding of the "SCN:" chunk
            (or, more precisely, the part belonging to one sub-image)
            is found here. The data for current line is stored in
            self.n_arr. When a line is finished, calls add_png_line.
        '''
        _err_sub_i = (self.format_err_msg_file_info() +
                      'BMP/SCN sub-image decode: ')
        data_sub_img = self.data_sub_img
        b_first = _single_char(data_sub_img[0])

        # If the image is "empty" (i.e it contains only a few transparent
        #     pixels), the value of this byte is 0xff
        if (b_first > 15) and (b_first != color_byte_empty):
            raise RuntimeError(_err_sub_i + 'Invalid first byte')

        index = 1
        data_len = len(data_sub_img)
        width = self.img_width  # fixme
        self.n_arr.reset()

        # NOTE: consecutive_c00_hack removed, proper fix added based on
        #     new information added by User Nyerguds at ModdingWiki
        ## consecutive_c00_hack = width >= 64

        while True:
            # FIXME, HACK, in some rare cases only a single 0xc0 byte remain
            #   as the previous 0x00 byte has a different function
            if index >= data_len:
                raise RuntimeError(_err_sub_i + str_err_sub_image_end)

            b_ctrl = _single_char(data_sub_img[index])
            index += 1

            if index == data_len:
                if b_ctrl == 0x40:
                    print_msg('HACK, %s 0x40 byte found at "unsupported" ' \
                              'position' % self.format_err_msg_file_info())
                    self.add_png_line()
                    break  # the end of sub-image!
                else:
                    # fixme, "compatibility" with previous code
                    raise RuntimeError(_err_sub_i + str_err_sub_image_end)

            b_high_2b_shift = b_ctrl >> 6
            b_low_6b = b_ctrl & 0x3f

            if b_high_2b_shift == 0:  # most significant 2 bits: 00
                # 00......: start a new line of the file, and move the current
                #   "x" position to the left with b_ctrl & 0x3f bytes (stored
                #   in the least significant 6 bits). The file may contain 2
                #   consecutive bytes with zero high-order bits, corresponding
                #   to a single jump with a 12-bit size. This effectively
                #   limits the image width to 4095 pixels.

                b_next = _single_char(data_sub_img[index])

                if (b_ctrl, b_next) == (0, 0x40):
                    if index != (data_len - 1):
                        raise RuntimeError(
                            _err_sub_i +
                            'Terminator found before end of block.')

                    self.add_png_line()
                    break  # the end of sub-image!

                # more significant 2 bits of next byte also zero?
                # MODIFIED: If the second byte is zero, the sequence is always
                #     interpreted as two separate commands.
                if ((b_next >> 6) == 0) and (b_next != 0):
                    # & 0x3f not needed, the two high bytes are 0!
                    move_left = (b_next << 6) | b_low_6b
                    index += 1
                else:
                    # otherwise, b_next is not used
                    move_left = b_low_6b

                # no "width" overflow check
                # this must be done before add_png_line()!
                pos_new_x_zoom = len(self.n_arr) - move_left * self.zoom

                if pos_new_x_zoom < 0:
                    raise RuntimeError(_err_sub_i + '"x" position underflow')

                self.add_png_line()

                if pos_new_x_zoom != 0:
                    if self.color_transparent is None:
                        raise RuntimeError(_err_sub_i + str_err_no_transp_col)

                    self.n_arr.append_nibble_repeated(self.color_transparent,
                                                      pos_new_x_zoom)

            elif b_high_2b_shift == 1:  # most significant 2 bits: 01
                # 01......: add transparent pixels
                if self.color_transparent is None:
                    raise RuntimeError(_err_sub_i + str_err_no_transp_col)

                self.n_arr.append_nibble_repeated(self.color_transparent,
                                                  b_low_6b * self.zoom)

            elif b_high_2b_shift == 2:  # most significant 2 bits: 10
                # 10......: a sequence of same-colored pixels ("RLE-like")
                if b_first == color_byte_empty:
                    raise RuntimeError(_err_sub_i + str_err_decode_empty_image)

                b_color = _single_char(data_sub_img[index])

                if b_color > 15:
                    raise RuntimeError(_err_sub_i +
                                       'invalid RLE-encoded color')

                b_color_out = (b_color + b_first) & 0xf
                index += 1
                # b_color must be in range 0x0 - 0xf !
                self.n_arr.append_nibble_repeated(b_color_out,
                                                  b_low_6b * self.zoom)

            else:  # most significant 2 bits: 11
                # 11......: a sequence of pixels with a specified size
                if b_first == color_byte_empty:
                    raise RuntimeError(_err_sub_i + str_err_decode_empty_image)

                n_bytes = (b_low_6b + 1) >> 1

                # fixme, byte array 'hacked" in 2 steps, may be slow
                data_append, last_n_unused = _t12bmp_zoom_line_4bpp(
                    data_sub_img[index:index + n_bytes], b_low_6b & 1, b_first,
                    self.zoom)

                self.n_arr.append_bytes(data_append, last_n_unused)

                index += n_bytes

    def is_file_type_supported(self, file_data_start):
        '''
        Re-implementation is_file_type_supported from ResDataBase_Decoder.
        See meaning of argument there (base.basecl)
        As the chunk format of this partially overlaps with the
            "BMP:"/"INF:"/"BIN:" format (decoder.bmpbin), the "SCN:"
            chunk must be located.
        '''
        if not isinstance(file_data_start, bytes):
            raise TypeError('file_data_start: must be bytes')

        if ((file_data_start[:4] != b'BMP:')
                or (file_data_start[8:12] != b'INF:')):
            return False

        # FIXME, duplication, decode_header_data
        size_inf = struct.unpack_from('<L', file_data_start, pos_inf_bmp)[0]
        start_pos_bin = pos_after_inf_size + size_inf

        # NOTE: this decoder is used as a fallback if the "INF:"
        #     chunk is too long! FIXME, this may prevent the decoding
        #     of some BMP/INF/BIN files

        if start_pos_bin > (len(file_data_start) - 4):
            return True

        return file_data_start[start_pos_bin:start_pos_bin + 4] == b'SCN:'

    def add_png_lines_flipped(self, flip):
        '''
        Re-implementation of add_png_lines_flipped from
            SubFileDecoder_MultiSubImg. (base.bmpdbase).
            lines_flipped is used for strong the horizontally flipped lines.
        See meaning of argument in SubFileDecoder_MultiSubImg.
        '''

        if flip & flip_horizontal:
            if self.lines_flipped is None:
                self.lines_flipped = horizontal_flip_lines_4bpp(
                    self.out_png_lines, self.img_width & 1)

        lines_1 = (self.lines_flipped
                   if flip & flip_horizontal else self.out_png_lines)
        lines_2 = lines_1[::-1] if flip & flip_vertical else lines_1

        for line in lines_2:
            for cnt in xrange(self.zoom):
                self.png_export.add_line(line)

    def decode_sub_image(self):
        '''
        Re-implementation of decode_sub_image from SubFileDecoder_MultiSubImg.
            (base.bmpdbase). Calls decode_single_sub_image, responsible for
            much of the decoding.
        '''

        self.img_width = self.sub_img_info.inf_w * self.zoom
        self.reset_out_png_lines()
        self.decode_single_sub_image()
        self.img_height = len(self.out_png_lines) * self.zoom

        if len(self.out_png_lines) != self.sub_img_info.inf_h:
            print_msg('WARNING: %s Height does not match: %d, expected %d ' %
                      (self.format_err_msg_file_info(), len(
                          self.out_png_lines), self.sub_img_info.inf_h))

    def decode_header_data(self, f_name_part, file_data):
        '''
        Re-implementation decode_header_data from SubFileDecoder_MultiSubImg
        See meaning of arguments there (base.bmpdbase)
        '''
        _err_decode = 'BMP decode (file "%s.BMP")' % f_name_part

        # todo, "superfluous", already checked in is_file_type_supported
        if file_data[:4] != b'BMP:':  # fixme, hardcoded positins
            raise RuntimeError(_err_decode + ': "BMP:" missing')

        if file_data[8:12] != b'INF:':
            raise RuntimeError(_err_decode + ': "INF:" missing')

        # "BMP:" is a "container" chunk, the most significant bit in its
        #     size DWORD is set. (TODO, size check is missing)
        head_chunk_size_file = struct.unpack_from('<L', file_data, 4)[0]
        head_chunk_size = head_chunk_size_file & 0x7fffffff

        size_inf = struct.unpack_from('<L', file_data, pos_inf_bmp)[0]
        start_pos_scn = pos_after_inf_size + size_inf

        if file_data[start_pos_scn:start_pos_scn + 4] != b'SCN:':
            raise RuntimeError(_err_decode + ': "SCN:" not found')

        size_scn = struct.unpack_from('<L', file_data, start_pos_scn + 4)[0]
        start_pos_off = start_pos_scn + chunk_prefix_size + size_scn

        if file_data[start_pos_off:start_pos_off + 4] != b'OFF:':
            raise RuntimeError(_err_decode + ': "OFF:" not found')

        size_off = struct.unpack_from('<L', file_data, start_pos_off + 4)[0]

        if (start_pos_off + chunk_prefix_size + size_off) != len(file_data):
            raise RuntimeError(_err_decode + ': file does not end at "OFS:"')

        scn_byte_m1 = _single_char(file_data[start_pos_off - 1])  # m1: -1
        scn_byte_m2 = _single_char(file_data[start_pos_off - 2])

        # Actually, all sub-images end with these two bytes (we check the
        #     ending of the last one in this case). Despite this, the check
        #     is useful for detecting some .BMP (sub-)files with
        #     "non-standard" format

        num_sub_imgs = struct.unpack_from('<H', file_data,
                                          pos_after_inf_size)[0]

        if (size_inf, size_off) != (num_sub_imgs * 4 + 2, num_sub_imgs * 4):
            raise RuntimeError(_err_decode +
                               ': Invalid size of "INF:" or "OFS:" chunk')

        # first should be zero
        part_offsets = struct.unpack_from('<%dL' % num_sub_imgs, file_data,
                                          start_pos_off + 8)

        if part_offsets[0] != 0:
            raise RuntimeError(_err_decode + ': first "offset" must be 0')

        part_off_mod = part_offsets + (size_scn, )

        self.out_conv_bmp_info = nt_bm_info_t12(f_name_part, head_chunk_size,
                                                size_inf, size_scn, size_off)

        self.color_transparent = self.parent.get_option(s_opt_transpcol16)
        self.zoom = self.parent.get_option(s_opt_zoom)
        start_pos_widths = pos_after_inf_size + 2
        start_pos_heights = start_pos_widths + num_sub_imgs * 2

        for part_num in xrange(num_sub_imgs):
            width_i = struct.unpack_from('<H', file_data,
                                         start_pos_widths + part_num * 2)[0]

            height_i = struct.unpack_from('<H', file_data,
                                          start_pos_heights + part_num * 2)[0]

            pos_start_i = start_pos_scn + 8 + part_off_mod[part_num]
            pos_end_i = start_pos_scn + 8 + part_off_mod[part_num + 1]

            self.process_sub_image(
                file_data[pos_start_i:pos_end_i],
                nt_bm_sub_img_info_t12(f_name_part, part_num, pos_start_i,
                                       pos_end_i - pos_start_i, width_i,
                                       height_i))
