#!/usr/bin/python3
# coding: utf8

# The Incredible Machine (TIM) level/image resource reader, version 0.2
# By knt47, licensed under the Creative Commons Zero license

from __future__ import division, print_function, unicode_literals

import itertools, sys

if sys.version_info[0] != 3:
    raise NotImplementedError('Only Python 3 is supported.')
else:
    izip = zip
    xrange = range

from collections import namedtuple
from timgres.base.misc import (print_msg, namedtuple_to_str, s_vdata_bmpsubimg,
                               s_vdata_fntsymbol, s_vdata_scrimg, s_opt_flip)
from timgres.base.bmpdbase import nt_bm_data, nt_process_options_bm, flip_none
from timgres.base.vdobase import (ResDataBase_ViewerDataObj, nt_anim_info,
                                  nt_image_display_data, nt_info_col_header,
                                  nt_size)

# --- ResDataBase_ViewerDataObj subclass for sub-images, no animation ---

'''
This module contains ViewerDataObj_SingleImgFile and its sub-classes for
    three formats: ViewerDataObj_Bmp, ViewerDataObj_Fnt and
    ViewerDataObj_Scr. These viewer objects support multiple sub-images
    but no animation.
'''

# nt_sub_item_info_bmp: namedtuple for sub-item information
#     (sub_item_info), used in class ViewerDataObj_SingleImgFile.
#     All members are strings.
# item_text: Text displayed in the first column in the "Information" panel
#     (table), also used by get_sub_item_texts
# conv_w, conv_h: Width and height of the converted image.
# notes: Additional information.

nt_sub_item_info_bmp = namedtuple('nt_sub_item_info_bmp',
                                  ('item_text', 'conv_w', 'conv_h', 'notes'))


class ViewerDataObj_SingleImgFile(ResDataBase_ViewerDataObj):
    '''
    ResDataBase_ViewerDataObj subclass, used for displaying (and exporting)
        multiple types of multi sub-image files (and symbols from fonts.)
        Does not support animation.
    '''

    # obj_identifier, obj_description: must be modified in sub-classes

    # sub_item_text: must be modified in sub-classes, used by
    #     get_sub_item_text()
    sub_item_text = ''
    # file_ext: stores the file extension, used in error messages
    viewer_obj_file_ext = ''

    # info_col_headers: corresponds to the items of nt_sub_item_info_bmp
    info_col_headers = (
        nt_info_col_header('Sub-file', 180),
        nt_info_col_header('Width (conv.)', 80),
        nt_info_col_header('Height (conv.)', 80),
        nt_info_col_header('Notes', 520),
    )

    def reset_data_subclass(self):
        '''
        Re-implementation of reset_data_subclass from
            ResDataBase_ViewerDataObj. Resets fields that are used for
            storing data related to the selected file/sub-item.
        '''
        # bmp_info, conv_png_data: from the nt_bm_data namedtuple
        #     returned by image parsing.
        self.bmp_info = None
        self.conv_png_data = None

    def get_sub_item_text(self, index, num_sub_imgs, sub_img_info):
        '''
        For "internal" use only. Returns the text for one sub-item (type: str)
        May be re-implemented in subclasses.
        index (int): The index of the sub-item.
        num_sub_imgs (int): The total number of sub-items.
        sub_img_info: The sub_img_info member from the nt_bm_sub_img_data
            associated with the item. (type: decoder specific namedtuple.)
        Default implementation does not use sub_img_info
        '''
        return '%s [%d/%d]' % (self.sub_item_text, index, num_sub_imgs)

    def open_sub_file(self, sub_f_name):
        '''
        Re-implementation of open_sub_file from ResDataBase_ViewerDataObj.
        See meaning of argument there. Calls the decode_sub_file method
            of parent for the specified image. Fills all list members of
            the class, required in a ViewerDataObj.
        '''

        self.reset_data()

        # Currently, the process options are: all sub images, "current" flip

        curr_flip = self.parent.get_option(s_opt_flip)
        bm_data = self.parent.decode_sub_file(
            sub_f_name, nt_process_options_bm(None, (curr_flip, )))

        if not isinstance(bm_data, nt_bm_data):
            raise RuntimeError(
                'parent.decode_sub_file() returned invalid data type for %s' %
                self.viewer_obj_file_ext)

        # TODO: stored, but not necessary?
        self.bmp_info, self.conv_png_data = bm_data
        num_sub_imgs = len(self.conv_png_data)

        for index, sub_img_data in enumerate(self.conv_png_data):
            # FIXME, type check, nt_bm_sub_img_data
            # NOTE: no "placeholder" is added for "non-existent" items
            if sub_img_data.png_data_flip is None: continue

            self.sub_item_info.append(
                nt_sub_item_info_bmp(
                    self.get_sub_item_text(index, num_sub_imgs,
                                           sub_img_data.sub_img_info),
                    str(sub_img_data.out_w), str(sub_img_data.out_h),
                    namedtuple_to_str(sub_img_data.sub_img_info)))

            # actually, no animation
            # NOTE: index is NOT correct here! If the item was skipped
            #    (see "continue" above), it should not be counted here

            self.anim_info.append(
                [nt_anim_info(len(self.img_data_frames), None)])

            # NOTE:, all images will be shown in a hardcoded (0, 0) position
            #   flip_img is always flip_none, regardless of flip
            #   (used in "composite" frames only, see ...)
            self.img_data_frames.append([
                nt_image_display_data(0, 0, flip_none,
                                      sub_img_data.png_data_flip[curr_flip])
            ])

        self.item_info_head = nt_sub_item_info_bmp(
            'Info: %s' % self.viewer_obj_file_ext, '', '',
            namedtuple_to_str(self.bmp_info))

        # item_info_extra left empty!

        # IMPORTANT: )Py 2.7 compatibility): The default= arg of max()
        #     requires at least Python 3.4
        # Already multiplied by zoom in the decoder.
        self.recomm_canvas_size = nt_size(
            max((x.out_w for x in self.conv_png_data if x.out_w is not None),
                default=1),
            max((x.out_h for x in self.conv_png_data if x.out_h is not None),
                default=1))


class ViewerDataObj_Bmp(ViewerDataObj_SingleImgFile):
    '''
    ViewerDataObj_SingleImgFile subclass for .BMP images with
        multiple sub-items.
    '''
    # obj_identifier: ID of the viewer class, modified
    obj_identifier = s_vdata_bmpsubimg
    # obj_description: A short description associated with the viewer class,
    #     modified
    obj_description = 'BMP sub-images'
    # sub_item_text: used in get_sub_item_text, modified
    sub_item_text = 'BMP sub-image'
    # viewer_obj_file_ext: File extension, modified
    viewer_obj_file_ext = '.BMP'


class ViewerDataObj_Fnt(ViewerDataObj_SingleImgFile):
    '''
    ViewerDataObj_SingleImgFile subclass for symbols in an .FNT font.
    '''
    # obj_identifier: ID of the viewer class, modified
    obj_identifier = s_vdata_fntsymbol
    # obj_description: A short description associated with the viewer class,
    #     modified
    obj_description = 'Symbols in FNT font'
    viewer_obj_file_ext = '.FNT'

    def get_sub_item_text(self, index, num_sub_imgs, sub_img_info):
        '''
        Re-implementation of get_sub_item_text from ViewerDataObj_SingleImgFile
        '''
        # Does not use self.sub_item_text
        return 'Character 0x%02x [%d/%d]' % (sub_img_info.char_code, index,
                                             num_sub_imgs)


class ViewerDataObj_Scr(ViewerDataObj_SingleImgFile):
    '''
    ViewerDataObj_SingleImgFile subclass for .SCR full-screen
        image files.
    '''
    # obj_identifier: ID of the viewer class, modified
    obj_identifier = s_vdata_scrimg
    # obj_description: A short description associated with the viewer class,
    #     modified
    obj_description = 'SCR image'
    # sub_item_text: used in get_sub_item_text, modified
    sub_item_text = 'SCR image'
    # viewer_obj_file_ext: File extension, modified
    viewer_obj_file_ext = '.SCR'
