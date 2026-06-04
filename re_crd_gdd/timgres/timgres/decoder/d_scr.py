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
from timgres.base.bmpdbase import SubFileDecoder_Base_BMP_BIN_VGA

# --- "SCR" (full-screen image) decoder ---

'''
This module contains the decoder class SubFileDecoder_Scr, which provides
    support for full-screen "SCR" images. Such a file contains
    the following chunks: "SCR:", "DIM:", "BIN:" and optionally "VGA:".
'''

scr_size_data_start = 16
scr_chunk_start = 20
scr_bin_data_start = 28

# nt_bm_info_scr: Namedtuple containing information extracted
#     from the header of the image file. (TODO: add field description)
# Will be stored as the bm_info member of nt_bm_data namedtuple

nt_bm_info_scr = namedtuple('nt_bm_info_scr',
                            ('f_name_part', 'scr_chunk_size', 'size_bin',
                             'compr_algorithm', 'uncompr_size'))

# nt_bm_sub_img_info_scr: Contains information for each sub-image
#     from the file. (TODO: add field description)
# Will be stored as the sub_img_info member of nt_bm_sub_img_data namedtuple

nt_bm_sub_img_info_scr = namedtuple(
    'nt_bm_sub_img_info_scr',
    ('f_name_part', 'part_id', 'data_size', 'img_w', 'img_h'))


class SubFileDecoder_Scr(SubFileDecoder_Base_BMP_BIN_VGA):
    '''
    This class implements a decoder for the "SCR" image format
        (typically, full-screen images)
    As this is one of the "BIN:"/"VGA:" image formats, it inherits
        SubFileDecoder_Base_BMP_BIN_VGA.
    '''

    # file_ext: the file extension, must be modified in sub-classes
    file_ext = 'SCR'

    def is_file_type_supported(self, file_data_start):
        '''
        Re-implementation is_file_type_supported from ResDataBase_Decoder.
        See meaning of argument there (base.basecl)
        Checks for the presence of the "SCR:", "DIM:" and "BIN:" chunks.
        '''

        if not isinstance(file_data_start, bytes):
            raise TypeError('file_data_start: must be bytes')

        return (file_data_start[:4] == b'SCR:') and \
               (file_data_start[8:12] == b'DIM:') and \
               (file_data_start[20:24] == b'BIN:')

    # def add_png_lines_flipped(self, flip): # Implemented in parent class
    # def decode_sub_image(self): # Implemented in parent class

    def decode_header_data(self, f_name_part, file_data):
        '''
        Re-implementation decode_header_data from SubFileDecoder_MultiSubImg
        See meaning of arguments there (base.bmpdbase)
        '''

        _err_decode = 'SCR decoder (file "%s.SCR")' % f_name_part

        if not self.is_file_type_supported(file_data[:32]):
            raise ValueError(_err_decode + ': Invalid file_data')

        # "SCR:" is a "container" chunk, the most significant bit in its
        #     size DWORD is set. (TODO, size check is missing)
        head_chunk_size_file = struct.unpack_from('<L', file_data, 4)[0]
        head_chunk_size = head_chunk_size_file & 0x7fffffff
        dim_chunk_len = struct.unpack_from('<L', file_data,
                                           scr_size_data_start - 4)[0]

        if dim_chunk_len != 4:
            raise RuntimeError(_err_decode +
                               ': Length DWORD of "DIM:" chunk is invalid')

        img_width, img_height = struct.unpack_from('<HH', file_data,
                                                   scr_size_data_start)

        bin_data_size = struct.unpack_from('<L', file_data,
                                           scr_bin_data_start - 4)[0]

        self.decode_bin_vga_chunks(f_name_part, file_data[scr_chunk_start:])

        # No loop, always contains a single image

        self.out_conv_bmp_info = nt_bm_info_scr(f_name_part, head_chunk_size,
                                                bin_data_size,
                                                self.compr_algorithm_bin,
                                                self.data_size_bin_vga)
        # self.data_uncompr_vga: may be None!

        self.process_sub_image(
            self.data_uncompr_bin,
            nt_bm_sub_img_info_scr(f_name_part, 0, self.data_size_bin_vga,
                                   img_width, img_height),
            self.data_uncompr_vga)
