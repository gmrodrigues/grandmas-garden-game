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
from timgres.base.misc import (print_msg, print_traceback, namedtuple_to_str,
                               s_vdata_special_storeddata,
                               s_vdata_special_storeddata_anim, ext_subf_lev,
                               s_vdata_puzzle_t1, s_opt_flip,
                               s_res_file_special)
from timgres.base.vdobase import (ViewerDataObj_MultiSubImage,
                                  nt_info_col_header, nt_size, flip_none,
                                  _num_list_to_str_nosp)
from timgres.puzzle.anmview import (ViewerDataObj_Animation,
                                    StoredDataViewerMixin)

# --- Viewer objs for "stored data" (information not from game resources) ---

'''
This module contains two ViewerDataObj classes, ViewerDataObj_StoredData and
    ViewerDataObj_StoredDataAnim. These classes are used in the cases where
    the "sub-image" information cannot be read directly from the game
    resource files, but some other "source" is required.
'''

# nt_sub_item_info_storeddata: namedtuple for sub-item information
#     (sub_item_info), used in class ViewerDataObj_StoredData.
#     All members are strings.
# item_text: Text displayed in the first column in the "Information" panel
#     (table), also used by get_sub_item_texts
# width, height: Dimensions of the animation frame.
# notes: Additional information.
nt_sub_item_info_storeddata = namedtuple(
    'nt_sub_item_info_storeddata', ('item_text', 'width', 'height', 'notes'))


class ViewerDataObj_StoredData(ViewerDataObj_MultiSubImage,
                               StoredDataViewerMixin):
    '''
    A subclass of ViewerDataObj_StoredDataBase, that serves as a viewer for
        animation frames of item graphics in current game version. These
        frames are composed of multiple images, but no animation. Like the
        paretn class, itnot read the animation frame information form a game
        resource file, but depends on a "data source" (see set_stored_data).
    '''

    # Note: crc32 checks are performed in open_res_callback_t1_crc_check

    # obj_identifier, obj_description: The ID and the description of the
    #     object (defined in ResDataBase_ViewerDataObj)
    obj_identifier = s_vdata_special_storeddata
    obj_description = 'Animation frames (TIM/TEMIM), multi-part'

    # info_col_headers: corresponds to the items of nt_sub_item_info_storeddata
    info_col_headers = (
        nt_info_col_header('Sub-file', 160),
        nt_info_col_header('Width', 60),
        nt_info_col_header('Height', 60),
        nt_info_col_header('Notes', 620),
    )

    def __init__(self):
        '''Constructor of the class. Requires no argument.'''
        ViewerDataObj_MultiSubImage.__init__(self)
        self.reset_stored_data()

    def reset_data_subclass(self):
        '''
        Re-implementation of reset_data_subclass from
            ResDataBase_ViewerDataObj. Initializes class-specific fields.
        '''

        # sub_item_count: set in set_stored_data, required by set_frame_data
        #     before self.img_data_frames is "complete"
        self.sub_item_count = 0

    def get_data_sub_img_pos(self):
        '''
        For internal use only, returns a copy of self.data_sub_img_pos
            (list or tuple, format described in vd_sdata.py)
        '''
        return self.data_sub_img_pos

    def get_groups_present(self):
        '''
        For internal use only, returns a copy of self.groups_present,
            the available groups, based on checksum check (type:
            set or None if not available).
        '''
        return (set(self.groups_present)
                if self.groups_present is not None else None)

    def get_item_count_storeddata(self):
        '''
        For internal use only, returns a copy of self.sub_item_count
            (type: int)
        '''
        return self.sub_item_count

    def set_sub_image_load_info(self):
        '''
        Re-implementation of set_sub_image_load_info from
            ViewerDataObj_MultiSubImage. Performs two steps: 1.
            If this is the first call to the method after set_stored_data,
            performs the crc32 checks, using the data in self.data_checksums
            2. Calls add_single_sub_image_load_info for each required
            sub-images.
        '''

        # As set_sub_image_load_info is always called before set_frame_data,
        #     crc32 checks are done in this method

        #  do nothing if data_ fields are None
        if (self.data_checksums is None) or (self.data_sub_img_pos is None):
            return

        # Note: crc32 checks are performed in open_res_callback_t1_crc_check

        for sub_item_data in self.data_sub_img_pos:
            # sub_item_data[0] is not unpacked here, only one item needed
            if sub_item_data[0][0] not in self.groups_present:
                continue

            self.add_sub_image_load_info_s_data_single(sub_item_data,
                                                       flip_none)

            self.sub_item_count += 1

    def set_frame_data(self):
        '''
        Re-implementation of set_frame_data from ViewerDataObj_MultiSubImage.
        '''

        for sub_item_data in self.data_sub_img_pos:
            # sub_item_data[0][0] is the group ID

            group_num, anim_info, frame_w, frame_h, frame_offs_x, \
                frame_offs_y = sub_item_data[0]

            if group_num not in self.groups_present: continue

            self.add_new_frame(frame_w, frame_h)

            self.add_new_img_curr_frame_s_data_single(sub_item_data, 0, 0,
                                                      flip_none, None, None)

            # NOTE: Item numbering is somewhat different than in vd_bmp
            #     only the items "present" are numbered, not the full
            #      self.data_sub_img_pos
            self.end_frame_add_info(
                nt_sub_item_info_storeddata(
                    'Animation frame (TIM/TEMIM) [%d/%d]' %
                    (len(self.img_data_frames), self.sub_item_count),
                    str(frame_w), str(frame_h),
                    self.sub_img_usage_data_text()))

    def set_head_info(self):
        '''
        Re-implementation of set_head_info from ViewerDataObj_MultiSubImage.
        '''
        self.item_info_head = nt_sub_item_info_storeddata(
            'Info: ' + self.obj_description, '', '',
            ('groups: %s' % _num_list_to_str_nosp(self.groups_present)))


# TODO, copied from t1p1nfo (a module that intentionally does not
#     import it from some other source file)
anim_unused = 0
anim_first_frame = 1
anim_continue = 2
anim_first_flipped = 3


class ViewerDataObj_StoredDataAnim(ViewerDataObj_Animation):
    '''
    A ViewerDataObj_Animation subclass for viewing animations.
    The data required for the animation is stored in an 'associated"
        ViewerDataObj_StoredData.
    '''
    # obj_identifier, obj_description: the identifier and a short description
    #     of the viewer class (ResDataBase_ViewerDataObj)
    obj_identifier = s_vdata_special_storeddata_anim
    obj_description = 'Animation (TIM/TEMIM)'

    # viewer_obj_id_frames, viewer_obj_file_ext: Required for accessing
    #     the associated viewer object that contains the frame data.
    #     (ViewerDataObj_StoredData) (originally defined in the parent)
    viewer_obj_id_frames = s_vdata_special_storeddata
    viewer_obj_file_ext = s_res_file_special

    def get_expected_frame_number(self):
        '''
        Re-implementation of get_expected_frame_number,
            from ViewerDataObj_Animation.
        '''
        return self.obj_frame_data.get_item_count_storeddata()

    def add_anim_info(self):
        '''
        Re-implementation of add_anim_info, from ViewerDataObj_Animation.
        Uses the data from the associated viewer object
            (s_vdata_special_storeddata)
        '''
        data_sub_img_pos = self.obj_frame_data.get_data_sub_img_pos()
        if data_sub_img_pos is None: return
        groups_present = self.obj_frame_data.get_groups_present()
        item_count = self.obj_frame_data.get_item_count_storeddata()
        cnt_anim = -1

        for sub_item_id, sub_item_data in enumerate(data_sub_img_pos):
            group_num = sub_item_data[0][0]
            if group_num not in groups_present: continue

            anim_info = sub_item_data[0][1]
            if anim_info == anim_unused: continue

            # TODO: currently anim_first_frame and anim_first_flipped
            #     behave the same way

            if anim_info in (anim_first_frame, anim_first_flipped):
                if cnt_anim != -1:
                    self.end_current_animation(cnt_anim, item_count)

                cnt_anim += 1

            if cnt_anim == -1:
                raise RuntimeError('Invalid "stored" data, first item must '
                                   'use anim_first_frame, not anim_continue')

            # Duration other than 1 is currently not supported
            self.add_anim_frame(sub_item_id, 1)

        self.end_current_animation(cnt_anim, item_count)


def open_res_callback_t1_crc_check(res_data_mgr):
    '''
    A ResDataManager callback function that performs the required crc32
        checks for subclasses of StoredDataViewerMixin. There are two
        such classes, ViewerDataObj_StoredData and
        ViewerDataObj_Puzzle_T1 in viewdata/vd_puz.py
    '''
    res_data_mgr.get_viewer_obj_by_id(
        s_res_file_special, s_vdata_special_storeddata).perform_crc32_checks()
    res_data_mgr.get_viewer_obj_by_id(
        ext_subf_lev, s_vdata_puzzle_t1).perform_crc32_checks()
