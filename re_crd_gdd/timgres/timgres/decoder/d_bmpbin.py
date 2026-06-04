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
from timgres.base.bmpdbase import SubFileDecoder_Base_BMP_BIN_VGA
from timgres.base.misc import (print_msg, print_traceback, s_obj_pngexp16,
                               s_obj_chunkuncompr, s_opt_zoom)

# --- Decoder for the "BMP:"/"INF:"/"BIN:" image format ---

'''
This module contains the decoder class SubFileDecoder_BmpBin, which provides
    support for one specific "BMP" resource format. Such a file contains
    the following chunks: "BMP:", "INF:", "BIN:" and optionally "VGA:".
'''

chunk_head_skip = 8
pos_inf_bmp = 12
pos_after_inf_size = 16

nt_fields_bm_info_bmpbin = ('f_name_part', 'bmp_chunk_size', 'size_inf',
                            'size_bin', 'compr_algorithm', 'uncompr_size')

nt_fields_bm_sub_img_info_bmpbin = ('f_name_part', 'part_id', 'start_imgdata',
                                    'size_imgdata', 'img_w', 'img_h')

# nt_bm_info_bmpbin: Namedtuple containing information extracted
#     from the header of the image file. (TODO: add field description)
# Will be stored as the bm_info member of nt_bm_data namedtuple

nt_bm_info_bmpbin = namedtuple('nt_bm_info_bmpbin', nt_fields_bm_info_bmpbin)

# nt_bm_sub_img_info_bmpbin: Contains information for each sub-image
#     from the file. (TODO: add field description)
# Will be stored as the sub_img_info member of nt_bm_sub_img_data namedtuple

nt_bm_sub_img_info_bmpbin = namedtuple('nt_bm_sub_img_info_bmpbin',
                                       nt_fields_bm_sub_img_info_bmpbin)


class SubFileDecoder_BmpBin(SubFileDecoder_Base_BMP_BIN_VGA):
    '''
    This class implements a decoder for a ".BMP" file format that contains
        the following chunks: "BMP:", "INF:", "BIN:" and optionally "VGA:".
    As this is one of the "BIN:"/"VGA:" image formats, it inherits
        SubFileDecoder_Base_BMP_BIN_VGA.
    '''

    # file_ext: the file extension, modified
    file_ext = 'BMP'

    def is_file_type_supported(self, file_data_start):
        '''
        Re-implementation is_file_type_supported from ResDataBase_Decoder.
        See meaning of argument there (base.basecl)
        As the chunk format of this partially overlaps with the "BMP:"/
            "INF:"/"SCN:"/"OFS:" format (decoder.d_t12bmp), the "BIN:"
            chunk must be located.
        '''

        if not isinstance(file_data_start, bytes):
            raise TypeError('file_data_start: must be bytes')

        if ((file_data_start[:4] != b'BMP:')
                or (file_data_start[8:12] != b'INF:')):
            return False

        size_inf = struct.unpack_from('<L', file_data_start, pos_inf_bmp)[0]
        start_pos_bin = pos_after_inf_size + size_inf

        # NOTE: this decoder CANNOT be used if the INF: chunk is too long!

        if start_pos_bin > (len(file_data_start) - 4):
            return

        return file_data_start[start_pos_bin:start_pos_bin + 4] == b'BIN:'

    # def add_png_lines_flipped(self, flip): # Implemented in parent class
    # def decode_sub_image(self): # Implemented in parent class

    def decode_header_data(self, f_name_part, file_data):
        '''
        Re-implementation decode_header_data from SubFileDecoder_MultiSubImg
        See meaning of arguments there (base.bmpdbase)
        '''

        _err_decode = 'BMP decode (file "%s.BMP")' % f_name_part

        # todo, "superfluous", already checked in is_file_type_supported
        if file_data[:4] != b'BMP:':  # fixme, hardcoded positions
            raise RuntimeError(_err_decode + ': "BMP:" missing')

        if file_data[8:12] != b'INF:':
            raise RuntimeError(_err_decode + ': "INF:" missing')

        # "BMP:" is a "container" chunk, the most significant bit in its
        #     size DWORD is set. (TODO, size check is missing)
        head_chunk_size_file = struct.unpack_from('<L', file_data, 4)[0]
        head_chunk_size = head_chunk_size_file & 0x7fffffff
        size_inf = struct.unpack_from('<L', file_data, pos_inf_bmp)[0]
        start_pos_bin = pos_after_inf_size + size_inf

        if file_data[start_pos_bin:start_pos_bin + 4] != b'BIN:':
            raise RuntimeError(_err_decode + ': "BIN:" not found')

        # NOTE: any data after the "BIN:" chunk is ignored!

        bin_data_size = struct.unpack_from('<L', file_data,
                                           start_pos_bin + 4)[0]

        num_sub_imgs = struct.unpack_from('<H', file_data,
                                          pos_after_inf_size)[0]

        if size_inf != num_sub_imgs * 4 + 2:
            raise RuntimeError(_err_decode + ': bad "INF:" chunk size')

        self.decode_bin_vga_chunks(f_name_part, file_data[start_pos_bin:])

        data_uncompr_pos = 0
        len_data = self.data_size_bin_vga

        self.out_conv_bmp_info = nt_bm_info_bmpbin(f_name_part,
                                                   head_chunk_size, size_inf,
                                                   bin_data_size,
                                                   self.compr_algorithm_bin,
                                                   self.data_size_bin_vga)

        for part_num in xrange(num_sub_imgs):
            width_i = struct.unpack_from(
                '<H', file_data, pos_after_inf_size + 2 + part_num * 2)[0]

            height_i = struct.unpack_from(
                '<H', file_data,
                pos_after_inf_size + 2 + (part_num + num_sub_imgs) * 2)[0]

            width_bytes = (width_i + 1) >> 1
            size_bytes = width_bytes * height_i

            if (data_uncompr_pos + size_bytes) > self.data_size_bin_vga:
                raise RuntimeError(_err_decode +
                                   ': "BIN:" chunk ends too early')

            data_uncompr_pos_end = data_uncompr_pos + size_bytes
            data_bin = self.data_uncompr_bin[
                data_uncompr_pos:data_uncompr_pos_end]
            data_vga = (
                self.data_uncompr_vga[data_uncompr_pos:data_uncompr_pos_end]
                if self.data_uncompr_vga is not None else None)

            self.process_sub_image(
                data_bin,
                nt_bm_sub_img_info_bmpbin(f_name_part, part_num,
                                          data_uncompr_pos, size_bytes,
                                          width_i, height_i), data_vga)

            data_uncompr_pos += size_bytes

        if data_uncompr_pos < self.data_size_bin_vga:
            print_msg(_err_decode +
                      ': WARNING: Unprocessed data in "BIN:" chunk')
