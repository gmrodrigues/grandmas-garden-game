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
from timgres.base.nibblarr import _single_char
from timgres.base.basecl import ResDataBase_Decoder
from timgres.base.bmpdbase import nt_pal_data

# --- PAL parser, TIM 3 ---

'''
This module contains the decoder class (SubFileDecoder_Pal_T3) of a 256-color
    palette file format found in version 3 of the game,
    based on the RIFF container format (?).
'''

# nt_pal_info_t3: The palette information for this format, will be stored
#     in the pal_info member of nt_pal_data.
# pal_data_size (int): The size of the "palette" part.
# data_short_1, data_short_2 (int): 16-bit integer values from header,
#     meaning unclear

nt_pal_info_t3 = namedtuple('nt_pal_info_t3',
                            ('pal_data_size', 'data_short_1', 'data_short_2'))

pal_start_sub_head = 16
pal_start_sub_head_2 = 20
pal_start_colors = 24

len_16col = 16 * 4

col_magenta = b'\xff\x00\xff\x00'


class SubFileDecoder_Pal_T3(ResDataBase_Decoder):
    '''
    Decoder class for a 256-color palette file format found in version 3 of
        the game, based on the RIFF format. The result is an nt_pal_data
        namedtuple (see get_data).
    '''

    def __init__(self):
        '''The constructor of the class. Requires no argument.'''
        ResDataBase_Decoder.__init__(self)
        self.reset_conv_data()

    def reset_conv_data(self):
        '''Resets the palette data stored in the class.'''
        self.pal_data = None

    def is_file_type_supported(self, file_data_start):
        '''
        Re-implementation is_file_type_supported from ResDataBase_Decoder.
        See meaning of argument there (base.basecl)
        '''

        if not isinstance(file_data_start, bytes):
            raise TypeError('file_data_start: must be bytes')

        return (file_data_start[:4] == b'RIFF') and \
               (file_data_start[8:16] == b'PAL data')

    def process_sub_file(self, f_name_part, file_data, process_options):
        '''
        Re-implements process_sub_file from ResDataBase_Decoder.
        See meaning of arguments there (base.basecl)
        '''

        self.reset_conv_data()  # FIXME dupl., p_t12pal

        _err_decode = 'PAL decode (file "%s.PAL")' % f_name_part

        if process_options is not None:
            raise ValueError(_err_decode +
                             ': process_options: invalid value, must be None')

        # fixme, double check (is_file_type_supported)
        if not self.is_file_type_supported(file_data[:16]):
            raise RuntimeError(_err_decode + ': invalid RIFF PAL header')

        pal_size_full = struct.unpack_from('<L', file_data, 4)[0]
        pal_info = nt_pal_info_t3._make(
            struct.unpack_from('<LHH', file_data, pal_start_sub_head))

        if pal_info.pal_data_size != pal_size_full - 12:
            raise RuntimeError(_err_decode + ': wrong RIFF palette size')

        if pal_info.pal_data_size + pal_start_sub_head_2 != len(file_data):
            raise RuntimeError(_err_decode + ': invalid color data size')

        # 16 color palette, likely NOT needed
        # ? min(len_16col + pal_start_colors, len(file_data))
        end_16 = pal_start_colors + len_16col
        pal_end = (len(file_data)
                   if file_data[end_16:].strip(b'\x00') else end_16)

        out_col = [
            bytearray(file_data[x:x + 3])
            for x in xrange(pal_start_colors, pal_end, 4)
        ]

        # check fourth bytes, must be 0
        if any(
                _single_char(x) != 0
                for x in file_data[pal_start_colors + 3:pal_end:4]):
            raise RuntimeError(
                _err_decode +
                ': unsupported format, 4th byte of color entry must be 0')

        # TODO: color #0 in some palettes (e.g. TITLE.PAL) is FF FF FF 00
        #   (white). It is unclear whether this means transparency or not

        # FIXME, transparent color, hardcoded
        transp_col = (0 if file_data[pal_start_colors:end_16] == col_magenta *
                      16 else None)

        self.pal_data = nt_pal_data(out_col, transp_col, pal_info)

    def get_data(self):
        '''
        Re-implements get_data from ResDataBase_Decoder.
        Returns the data as a nt_pal_data namedtuple.
        '''
        return self.pal_data
