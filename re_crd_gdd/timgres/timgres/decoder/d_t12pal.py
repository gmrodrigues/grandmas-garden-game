#!/usr/bin/python3

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

# --- PAL reader, TIM 1 & 2 ---

'''
This module contains the decoder of the VGA palette format, found in the
    versions of games before version 3.
'''

# nt_pal_info_t12: The palette information for this format, will be stored
#     in the pal_info member of nt_pal_data.
# pal_chunk_size (int): The size of the "PAL:" chunk
#     see comment at "head_chunk_size" in process_sub_file
# data_ega (str): Data from the "EGA:" chunk, found in some palettes.
nt_pal_info_t12 = namedtuple('nt_pal_info_t12', ('pal_chunk_size', 'data_ega'))

pal_start_pos_colors = 16
pal_rel_pos_ega_start = 8

col_black = bytearray((0, 0, 0))


def conv_col_63_255(x):
    '''
    Private function for 0..63 -> 0..255 conversion, the same as DosBox does.
    Returns int.
    x (int): The input channel value (0..63)
    '''
    return x << 2 | x >> 4


class SubFileDecoder_Pal_T12(ResDataBase_Decoder):
    '''
    Decoder class for a VGA palette file format found in the versions of
        the game before version 3. The result is an nt_pal_data namedtuple
        (see get_data).
    '''

    def __init__(self):
        '''The constructor of the class. Has no arguments.'''
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

        return ((file_data_start[:4] == b'PAL:')
                and (file_data_start[8:12] == b'VGA:'))

    def process_sub_file(self, f_name_part, file_data, process_options):
        '''
        Re-implements process_sub_file from ResDataBase_Decoder.
        See meaning of arguments there (base.basecl)
        '''
        self.reset_conv_data()

        _err_decode = 'PAL decoder (file "%s.PAL")' % f_name_part

        if process_options is not None:
            raise ValueError(_err_decode +
                             ': process_options: invalid value, must be None')

        if (file_data[:4] != b'PAL:') or (file_data[8:12] != b'VGA:'):
            raise RuntimeError(_err_decode + ': "PAL:" or "VGA:" not found')

        # "PAL:" is a "container" chunk, the most significant bit in its
        #     size DWORD is set. (TODO, size check is missing)
        head_chunk_size_file = struct.unpack_from('<L', file_data, 4)[0]
        head_chunk_size = head_chunk_size_file & 0x7fffffff
        pal_vga_len = struct.unpack_from('<L', file_data, 12)[0]

        out_col_0 = []
        pal_vga_end = pal_vga_len + pal_start_pos_colors
        file_data_len = len(file_data)

        if pal_vga_end > file_data_len:
            raise RuntimeError(_err_decode + ': invalid "VGA:" size')

        for col_i in xrange(pal_start_pos_colors, pal_vga_end, 3):
            out_col_0.append(
                bytearray(
                    conv_col_63_255(x) for x in file_data[col_i:col_i + 3]))

        if all(x == col_black for x in out_col_0[16:]):
            # all further colors black -> only 16 color
            out_col_1 = out_col_0[:16]
        else:
            out_col_1 = out_col_0

        data_ega = '(none)'

        if pal_vga_end < file_data_len:
            # fixme, ega data, not required, should not raise exception
            if file_data[pal_vga_end:pal_vga_end + 4] == b'EGA:':
                pal_ega_len = struct.unpack_from('<L', file_data,
                                                 pal_vga_end + 4)[0]

                pal_ega_data_start = pal_vga_end + pal_rel_pos_ega_start
                pal_ega_end = pal_ega_data_start + pal_ega_len

                ## print(pal_ega_end, file_data_len)

                if pal_ega_end == file_data_len:
                    pal_ega = file_data[pal_ega_data_start:pal_ega_end]

                    data_ega = '(size:%d) %s' % (len(pal_ega), ' '.join(
                        '%02d' % _single_char(x) for x in pal_ega))

        # FIXME, transparent color, hardcoded
        transp_col = (0 if (out_col_0[0] == col_black)
                      and any(x == col_black
                              for x in out_col_0[1:16]) else None)

        self.pal_data = nt_pal_data(out_col_1, transp_col,
                                    nt_pal_info_t12(head_chunk_size, data_ega))

    def get_data(self):
        '''
        Re-implements get_data from ResDataBase_Decoder.
        Returns the data as a nt_pal_data namedtuple.
        '''
        return self.pal_data
