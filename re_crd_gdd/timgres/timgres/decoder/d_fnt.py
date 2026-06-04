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

# --- Font decoder for the TIM games ---

'''
This module contains the decoder for the 1BPP font format
    (SubFileDecoder_Fnt_1BPP) used in the TIM games, which inherits an
    abstract base class SubFileDecoder_Fnt_Base that could facilitate
    the implementation of related formats in the future.
    This file format has already been documented by user Nyerguds
    as "Dynamix font format v4" at ModdingWiki
'''

# The documentation is available at ModdingWiki:
#      http://www.shikadi.net/moddingwiki/Dynamix_Font_Format_v4-v5

import struct
from collections import namedtuple

from timgres.base.bmpdbase import (flip_horizontal, flip_vertical,
                                   SubFileDecoder_MultiSubImg,
                                   horizontal_flip_lines_4bpp)
from timgres.base.misc import (print_msg, print_traceback, s_obj_pngexp2,
                               s_obj_chunkuncompr, s_opt_zoom,
                               s_opt_font_color, color_black)
from timgres.base.nibblarr import _single_char

# nt_head_t12_fnt: Namedtuple containing information extracted from the
#     header of the font file. See ModdingWiki (link above)
#     for the meaning of (most) fields.
# Will be stored as the bm_info member of nt_bm_data namedtuple
# All fields are ints. (TODO: add field description)
nt_head_t12_fnt = namedtuple(
    'nthead_t12_fnt',
    ('format_byte', 'font_width', 'font_height', 'base_line', 'first_symbol',
     'n_symbols', 'symbol_data_size', 'compr_algorithm', 'uncompr_size'))

# nt_fnt_symbol_info: Contains information for each character
#     from the font. (TODO: add field description)
# Will be stored as the sub_img_info member of nt_bm_sub_img_data namedtuple
nt_fnt_symbol_info = namedtuple('nt_fnt_symbol_info',
                                ('f_name_part', 'part_id', 'start_pos',
                                 'size_data', 'char_code', 'symbol_width'))

fnt_chunk_size_pos = 4
fnt_head_pos = 8
fnt_uncompr_data_pos = 16
fnt_head_format = '<6BHBL'


class SubFileDecoder_Fnt_Base(SubFileDecoder_MultiSubImg):
    '''
    Common base class for font formats containing a "FNT:" chunk. Does not
        re-implement reset_decode_temp_data, add_png_lines_flipped and
        decode_sub_image (from SubFileDecoder_MultiSubImg). This must be done
        in sub-classes.
    '''

    # file_ext: the file extension, must be modified in sub-classes
    file_ext = 'FNT'
    # ID of png exporter object in parent, must be modified in sub-classes
    # png_exporter_obj_id # must be modified in sub-classes

    # file_format_byte: See documentation, 0xff for 1BPP (v4) and
    #     0xfd for 8BPP fonts (v5)
    file_format_byte = None

    #

    def is_file_type_supported(self, file_data_start):
        '''
        Re-implementation is_file_type_supported from ResDataBase_Decoder.
        See meaning of argument there (base.basecl)
        '''

        if not isinstance(file_data_start, bytes):
            raise TypeError('file_data_start: must be bytes')

        return ((file_data_start[:fnt_chunk_size_pos] == b'FNT:')
                and (_single_char(file_data_start[fnt_head_pos])
                     == self.file_format_byte))

    def decode_header_data(self, f_name_part, file_data):
        '''
        Re-implementation decode_header_data from SubFileDecoder_MultiSubImg
        See meaning of arguments there (base.bmpdbase)
        '''
        _err_decode = 'FNT decode (file "%s.FNT")' % f_name_part

        # Note: data after the "FNT:" chink is ignored!
        if not self.is_file_type_supported(file_data):
            raise RuntimeError(_err_decode + ': Unsupported FNT format')

        fnt_chunk_size = struct.unpack_from('<L', file_data,
                                            fnt_chunk_size_pos)[0]

        if fnt_chunk_size < struct.calcsize(fnt_head_format):
            raise RuntimeError(_err_decode + ': Invalid "FNT:" chunk size')

        # Note: Compression algorithm and uncompressed size unpacked twice
        #     (again in dcunbase.py)
        fnt_head = nt_head_t12_fnt._make(
            struct.unpack_from(fnt_head_format, file_data, fnt_head_pos))

        ch_uncompr = self.parent.get_object(s_obj_chunkuncompr)
        ch_uncompr.process_data(
            file_data[fnt_uncompr_data_pos:fnt_head_pos + fnt_chunk_size])

        data_uncompr = ch_uncompr.get_data()
        num_symbols = fnt_head.n_symbols

        symbol_offsets = struct.unpack_from('<%dH' % num_symbols, data_uncompr,
                                            0)
        char_data_start_pos = num_symbols * 3
        symbol_widths = bytearray(
            data_uncompr[num_symbols * 2:char_data_start_pos])

        symbol_offs_mod = symbol_offsets + (len(data_uncompr), )
        self.out_conv_bmp_info = fnt_head

        for part_num in xrange(num_symbols):
            pos_start_i = symbol_offs_mod[part_num] + char_data_start_pos
            pos_end_i = symbol_offs_mod[part_num + 1] + char_data_start_pos

            self.process_sub_image(
                data_uncompr[pos_start_i:pos_end_i],
                nt_fnt_symbol_info._make(
                    (f_name_part, part_num, pos_start_i,
                     pos_end_i - pos_start_i, part_num + fnt_head.first_symbol,
                     symbol_widths[part_num])))


def _color_rrggbb_to_bytearray(color_str):
    '''
    "Private" function. Converts a color in hexadecimal 'rrggbb' format
        to a bytearray. Returns a bytearray.
    color_str (str): The color in the format described above.
    '''

    if color_str is not None:
        return bytearray(
            int(color_str[x:x + 2], base=16)
            for x in xrange(0, len(color_str), 2))
    else:
        return color_black  # defauéts to black


def _repeat_bytes_bytearray(byte_arr, rep_count):
    '''
    "Private" function, repeats each byte in a bytearray. Returns bytearray.
    byte_arr (bytearray): The input bytearray.
    rep_count (int): The repeat count.
    '''
    # TODO: TEMPORARY CODE, until a "proper" bit array class is added
    #    (note: currently used with bytearrays containing only b'0's and b'1's)
    return bytearray().join(byte_arr[x:x + 1] * rep_count \
                            for x in xrange(len(byte_arr)))


def _bit_str_to_bytearray(bits):
    '''
    "Private" function. Accepts bytearrays consisting of b'0' and b'1'.
    Returns the result of 'back conversion" (type: bytearray).
    bits (bytearray): The input data.
    '''
    # TODO: TEMPORARY CODE, until a "proper" bit array class is added
    # bit_str: should accept bytes and bytearray consisting of b'0' and b'1'
    # Does not check if the langth is divisible by 8
    bits_ljust = bits.ljust((len(bits) + 7) & (~7), b'0')

    return bytearray(
        int(bits_ljust[x:x + 8], base=2)
        for x in xrange(0, len(bits_ljust), 8))


class SubFileDecoder_Fnt_1BPP(SubFileDecoder_Fnt_Base):
    '''
    SubFileDecoder_Fnt_Base sub-class implementing the "v4" format mentioned
        above. Re-implements all abstract methods from the parent.
    '''
    file_format_byte = 0xff

    def reset_lines_zoom(self):
        '''Initializes the lines_zoom field, containing temporary data.'''
        # lines_zoom (list of bytearrays): Stores temporary data for image
        #     generation.
        self.lines_zoom = []

    def reset_decode_temp_data(self):
        '''
        Re-implementation of reset_decode_temp_data from
            SubFileDecoder_MultiSubImg (base.bmpdbase).
            Calls reset_lines_zoom.
        '''
        self.reset_lines_zoom()

    def add_png_lines_flipped(self, flip):
        '''
        Re-implementation of add_png_lines_flipped from
            SubFileDecoder_MultiSubImg. (base.bmpdbase)
            See meaning of argument there.
        '''
        # TODO: TEMPORARY CODE, until a "proper" bit array type is added.
        zoom = self.parent.get_option(s_opt_zoom)

        if flip & flip_horizontal:
            lines_1 = [_bit_str_to_bytearray(x[::-1]) for x in self.lines_zoom]
        else:
            lines_1 = [_bit_str_to_bytearray(x) for x in self.lines_zoom]

        lines_2 = lines_1[::-1] if flip & flip_vertical else lines_1

        for line in lines_2:
            for cnt in xrange(zoom):
                self.png_export.add_line(line)

    def decode_sub_image(self):
        '''
        Re-implementation of decode_sub_image from
            SubFileDecoder_MultiSubImg. (base.bmpdbase).
        Decodes one character from the font and stores the data in
            self.lines_zoom.
        '''
        zoom = self.parent.get_option(s_opt_zoom)
        self.img_width = self.sub_img_info.symbol_width * zoom
        self.img_height = self.out_conv_bmp_info.font_height * zoom

        width_bytes = (self.sub_img_info.symbol_width + 7) >> 3
        size_calc = width_bytes * self.out_conv_bmp_info.font_height

        if len(self.data_sub_img) != size_calc:
            raise RuntimeError(
                'Sub-image size mismatch, size %d, expected %d' %
                (len(self.data_sub_img), size_calc))

        self.reset_lines_zoom()
        # TODO, find a more "logical" location for this
        png_export = self.parent.get_object(s_obj_pngexp2)
        png_export.set_palette((color_black,
                                _color_rrggbb_to_bytearray(
                                    self.parent.get_option(s_opt_font_color))))

        png_export.set_transp_color(0)

        for line_start in xrange(0, len(self.data_sub_img), width_bytes):
            input_bits = self.data_sub_img[line_start:line_start + width_bytes]

            self.lines_zoom.append(bytearray().join(
                _repeat_bytes_bytearray(bytearray(format(x, '08b'), 'latin1'),
                                        zoom)
                for x in input_bits)[:self.img_width])

    def decode_header_data(self, f_name_part, file_data):
        '''
        Re-implements decode_header_data from SubFileDecoder_Fnt_Base.
        See meaning of arguments in SubFileDecoder_MultiSubImg (base.bmpdbase)
        '''
        # This is a fix for the "png_exporter_obj palette problem."
        #     (Unlike most image decoders, the palette of the PNG exporter
        #     is set in this class.)
        self.png_exporter_obj_id = s_obj_pngexp2

        SubFileDecoder_Fnt_Base.decode_header_data(self, f_name_part,
                                                   file_data)
