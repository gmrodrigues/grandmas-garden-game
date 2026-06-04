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
from timgres.base.bmpdbase import (SubFileDecoder_MultiSubImg,
                                   RawBMData8BPPMixin)
from timgres.base.misc import (print_msg, print_traceback, s_obj_pngexp256,
                               s_obj_chunkuncompr, s_opt_zoom)

# --- BMP sub-file decoder, TIM 3 ---

'''
This module contains SubFileDecoder_Bmp_T3, a multi sub-image resource
    format common in TIM 3.
'''

# NOTE: This is a common image resource file format in TIM 3 Demo
#     and very likely also TIM 3.

nt_fields_bm_sub_img_info_t3 = ('f_name_part', 'part_id', 'start_pos',
                                'data_len', 'img_w', 'img_h',
                                'compr_algorithm', 'uncompr_size')

# nt_bm_info_t3: Namedtuple containing information extracted
#     from the header of the image file. (TODO: add field description)
# Will be stored as the bm_info member of nt_bm_data namedtuple

nt_bm_info_t3 = namedtuple('nt_bm_info_t12',
                           ('bmp_chunk_size', 'size_offs', 'size_pixdata'))

# nt_bm_sub_img_info_t3: Contains information for each sub-image
#     from the file. (TODO: add field description)
# Will be stored as the sub_img_info member of nt_bm_sub_img_data namedtuple

nt_bm_sub_img_info_t3 = namedtuple('nt_bm_sub_img_info_t3',
                                   nt_fields_bm_sub_img_info_t3)

pos_n_sub_imgs = 10
pos_offs = 12
skip_width_height = 4


class SubFileDecoder_Bmp_T3(SubFileDecoder_MultiSubImg, RawBMData8BPPMixin):
    '''
    This SubFileDecoder_MultiSubImg provides support for a common multi
        sub-image resource format in TIM 3. A significant difference from
        other image formats is that each sub-image has its own "compression
        header" (see base.dcunbase)
    '''

    # file_ext: the file extension, modified
    file_ext = 'BMP'
    # ID of png exporter object in parent, modified
    png_exporter_obj_id = s_obj_pngexp256

    def reset_decode_temp_data(self):
        '''
        Re-implementation of reset_decode_temp_data from
            SubFileDecoder_MultiSubImg (base,bmpdbase).
        '''
        # data_uncompr: stores the uncompressed data (see decode_sub_image)
        self.data_uncompr = None

    def is_file_type_supported(self, file_data_start):
        '''
        Re-implementation is_file_type_supported from ResDataBase_Decoder.
        See meaning of argument there (base.basecl)
        '''
        if not isinstance(file_data_start, bytes):
            raise TypeError('file_data_start: must be bytes')

        return (file_data_start[:4] == b'BMP:') and \
               (file_data_start[8:10] == b'\xe8\x03')

    def add_png_lines_flipped(self, flip):
        '''
        Re-implementation of add_png_lines_flipped from
            SubFileDecoder_MultiSubImg. (base.bmpdbase)
            See meaning of argument there.
        '''
        self.add_png_lines_flipped_8bpp(self.data_uncompr,
                                        self.sub_img_info.img_w,
                                        self.sub_img_info.img_h, flip)

    def decode_sub_image(self):
        '''
        Re-implementation of decode_sub_image from
            SubFileDecoder_MultiSubImg. (base.bmpdbase).
        '''
        ch_uncompr = self.parent.get_object(s_obj_chunkuncompr)
        zoom = self.parent.get_option(s_opt_zoom)

        ch_uncompr.process_data(self.data_sub_img)
        self.data_uncompr = ch_uncompr.get_data()
        self.img_width = self.sub_img_info.img_w * zoom
        self.img_height = self.sub_img_info.img_h * zoom
        size_calc = self.sub_img_info.img_w * self.sub_img_info.img_h

        if len(self.data_uncompr) != size_calc:
            raise RuntimeError(
                'Sub-image size mismatch, uncompressed '
                'size %d, expected %d' % (len(self.data_uncompr), size_calc))

    def decode_header_data(self, f_name_part, file_data):
        '''
        Re-implementation decode_header_data from SubFileDecoder_MultiSubImg
        See meaning of arguments there (base.bmpdbase)
        '''
        _err_decode = 'BMP decode (file "%s.BMP")' % f_name_part

        # todo, "superfluous", already checked in is_file_type_supported
        if not self.is_file_type_supported(file_data[:16]):
            raise RuntimeError(_err_decode + ': Unsupported BMP format')

        head_chunk_size = struct.unpack_from('<L', file_data, 4)[0]
        num_sub_imgs = struct.unpack_from('<H', file_data, pos_n_sub_imgs)[0]
        size_offs = num_sub_imgs * 4  # fixme

        # first should be zero
        part_offsets = struct.unpack_from('<%dL' % num_sub_imgs, file_data,
                                          pos_offs)

        if part_offsets[0] != (pos_offs + size_offs):
            raise RuntimeError(_err_decode + ': invalid first "offset"')

        part_off_mod = part_offsets + (len(file_data), )

        self.out_conv_bmp_info = nt_bm_info_t3(
            head_chunk_size, size_offs,
            len(file_data) - pos_offs - size_offs)

        for part_num in xrange(num_sub_imgs):
            pos_start_i = part_off_mod[part_num]
            pos_end_i = part_off_mod[part_num + 1]

            # TODO: compression algorithm and uncompr. size unpacked twice
            sub_img_data_part = struct.unpack_from('<HHBL', file_data,
                                                   pos_start_i)

            pos_start_data = pos_start_i + skip_width_height

            self.process_sub_image(
                file_data[pos_start_data:pos_end_i],
                nt_bm_sub_img_info_t3._make((f_name_part, part_num,
                                             pos_start_i, pos_end_i -
                                             pos_start_i) + sub_img_data_part))
