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

import zlib
from collections import namedtuple
from timgres.base.misc import (print_msg, print_traceback, namedtuple_to_str,
                               s_vdata_anmframes, s_vdata_anmviewer,
                               s_opt_flip, s_res_file_special, ext_subf_anm)
from timgres.base.vdobase import (ViewerDataObj_MultiSubImage,
                                  nt_info_col_header, nt_size, flip_none,
                                  _num_list_to_str_nosp)
from timgres.puzzle.anmview import (
    ViewerDataObj_Animation, AnmFramesViewerMixin, anm_d_entry_type_sub_img,
    anm_d_entry_type_rectangle, anm_d_entry_type_line, anm_d_entry_type_sound)

# --- ResDataBase_ViewerDataObj subclass for .ANM files  ---

'''
This module contains two viewer classes for animations stored in .ANM files:
    ViewerDataObj_AnmFrames: for viewing the animation frames without
    animation and ViewerDataObj_AnmViewer for animation.
'''

# nt_sub_item_info_anmdata: namedtuple for sub-item information (sub_item_info)
#     used in class ViewerDataObj_AnmFrames. All members are strings.
# item_text: Text displayed in the first column in the "Information" panel
#     (table), also used by get_sub_item_texts
# color_num_or_info: Text of the first column in the "information table".
# r, g, b: Information for each color of the palette
# notes: Additional information.

nt_sub_item_info_anmdata = namedtuple(
    'nt_sub_item_info_anmdata',
    ('item_text', 'x_pos', 'y_pos', 'width', 'height', 'notes'))


def _sect_d_type_2_item_info_to_str(nt_info):
    '''Helper function, for conversion of nt_info (type:
        nt_sect_d_entry_type_2) to a string that will be displayed
        in the "Notes" column. (returns str)'''
    return 'bmp_file_id: %d bmp_sub_img_id: %d img_flip: %d' % (
        nt_info.bmp_file_id, nt_info.bmp_sub_img_id, nt_info.img_flip)


class ViewerDataObj_AnmFrames(ViewerDataObj_MultiSubImage,
                              AnmFramesViewerMixin):
    '''
    ViewerDataObj_MultiSubImage subclass, for viewing animation frames,
        that uses the data stored in .ANM animation files.
    '''

    # obj_identifier, obj_description: The ID and the description of the
    #     object (defined in ResDataBase_ViewerDataObj)
    obj_identifier = s_vdata_anmframes
    obj_description = 'ANM animation frames'

    # info_col_headers: corresponds to the items of nt_sub_item_info_anmdata
    info_col_headers = (
        nt_info_col_header('Sub-file', 140),
        nt_info_col_header('X pos.', 50),
        nt_info_col_header('Y pos.', 50),
        nt_info_col_header('Width*', 50),
        nt_info_col_header('Height*', 50),
        nt_info_col_header('Notes', 560),
    )

    def __init__(self):
        '''Constructor of the class. Requires no argument.'''
        ViewerDataObj_MultiSubImage.__init__(self)
        self.reset_anim_file_data()

    def reset_data_subclass(self):
        '''
        Re-implementation of reset_data_subclass from
            ResDataBase_ViewerDataObj.
        '''
        # NOTE: Currently the "caching" of .ANM file data is "disabled", only
        #     the data from the currently opened file is stored in
        #     self.anm_files_data
        self.reset_anim_file_data()

    def get_anm_data(self):
        '''
        Returns the result of the ANM decoder, stored in the object
            (type: nt_anm_data or None on error)
        '''
        return self.anm_files_data.get(self.sub_file_name)

    def set_sub_image_load_info(self):
        '''
        Re-implementation of set_sub_image_load_info from
            ViewerDataObj_MultiSubImage.
        '''
        # set_sub_image_load_info is always called before set_frame_data, so
        #     the ANM file is decoded here

        anm_data = self.decode_anm_file(self.sub_file_name)

        # only section D (anm_data_d) and bmp_names is used here
        for sect_d_sub_list in anm_data.anm_data_d:

            self.add_sub_image_load_info_anm_single(anm_data, sect_d_sub_list,
                                                    flip_none)

    def set_frame_data(self):
        '''
        Re-implementation of set_frame_data from ViewerDataObj_MultiSubImage.
        Note that several animations contain instructions for drawing a
            rectangle or a line. These are drawn to PNG images, using
            the PngShapeDraw_4BPP object in parent.
        '''
        # NOTE: this class ignores information in sections A and C!

        anm_data = self.anm_files_data.get(self.sub_file_name)

        if anm_data is None:
            raise RuntimeError(
                'BUG, anm_data not loaded for file "%s"' % self.sub_file_name)

        if len(anm_data.anm_data_b) != len(anm_data.anm_data_d):
            raise RuntimeError('Incompatible B and D sections '
                               'detected in anm_data')

        if not anm_data.anm_data_b: return

        pos_x_min = min(x.pos_x for x in anm_data.anm_data_b)
        pos_y_min = min(x.pos_y for x in anm_data.anm_data_b)
        # HACK, width is (maybe) not "enough" for some anim. frames
        width_max_temp = (max(x.width
                              for x in anm_data.anm_data_b) - pos_x_min)
        # HACK, height is not "enough" for some anim. frames
        height_max_temp = (max(x.height
                               for x in anm_data.anm_data_b) - pos_y_min)
        # New width HACK
        width_max = max(width_max_temp, anm_data.anm_info.width)
        height_max = max(height_max_temp, anm_data.anm_info.height)

        for sect_b_item, sect_d_sub_list in izip(anm_data.anm_data_b,
                                                 anm_data.anm_data_d):

            cnt_rects = 0
            cnt_lines = 0
            list_sounds = []

            # self.add_new_frame(sect_b_item.width - pos_x_min,
            #                    sect_b_item.height - pos_y_min)

            # self.add_new_frame(sect_b_item.width, sect_b_item.height)
            # HACK for correct positioning when the image is flipped
            self.add_new_frame(width_max, height_max)

            self.add_new_img_curr_frame_s_data_single(anm_data, sect_b_item,
                                                      sect_d_sub_list,
                                                      -pos_x_min, -pos_y_min,
                                                      flip_none, None, None,
                                                      True)

            # Note: We need a separate loop for counting rectangles, lines
            #     and sound

            for sect_d_item in sect_d_sub_list:
                if sect_d_item.entry_type == anm_d_entry_type_rectangle:
                    cnt_rects += 1
                elif sect_d_item.entry_type == anm_d_entry_type_line:
                    cnt_lines += 1
                elif sect_d_item.entry_type == anm_d_entry_type_sound:
                    list_sounds.append(sect_d_item.sound_info)

            # NOTE: Item numbering is somewhat different than in vd_bmp
            #     only the items "present" are numbered, not all [???]

            list_notes = [self.sub_img_usage_data_text()]

            if cnt_rects:
                list_notes.append('rectangles:')
                list_notes.append(str(cnt_rects))

            if cnt_lines:
                list_notes.append('lines:')
                list_notes.append(str(cnt_lines))

            if list_sounds:
                list_notes.append('sound:')
                list_notes.append(_num_list_to_str_nosp(list_sounds))

            self.end_frame_add_info(
                nt_sub_item_info_anmdata(
                    'Animation frame [%d/%d]' %
                    (len(self.img_data_frames), len(anm_data.anm_data_b)),
                    str(sect_b_item.pos_x), str(sect_b_item.pos_y),
                    str(sect_b_item.width), str(sect_b_item.height),
                    ' '.join(list_notes)))

    def set_head_info(self):
        '''
        Re-implementation of set_head_info from ViewerDataObj_MultiSubImage.
        '''
        anm_data = self.anm_files_data.get(self.sub_file_name)

        self.item_info_head = nt_sub_item_info_anmdata(
            'Info: ' + self.obj_description, '', '', '', '',
            namedtuple_to_str(anm_data.anm_info))

        # TODO, add section A info

        for index_b, sect_b_item in enumerate(anm_data.anm_data_b):
            # Format with magic number 0x3ea4254

            if len(sect_b_item) > 5:
                item_notes = 'pos_sect_d: %d unknown_10: %d' % (
                    sect_b_item.offs_sect_d, sect_b_item.unknown_10)
            else:
                item_notes = 'pos_sect_d: %d' % sect_b_item.offs_sect_d

            self.item_info_extra.append(
                nt_sub_item_info_anmdata('B: Anim. frame %d' % index_b,
                                         str(sect_b_item.pos_x),
                                         str(sect_b_item.pos_y),
                                         str(sect_b_item.width),
                                         str(sect_b_item.height), item_notes))

        # Todo, add short description on sect. C (instead of Item)

        for index_c, sect_c_item in enumerate(anm_data.anm_data_c):
            self.item_info_extra.append(
                nt_sub_item_info_anmdata('C: Item %d' % index_c, '', '', '',
                                         '', namedtuple_to_str(sect_c_item)))

        for index_d, sect_d_sub_list in enumerate(anm_data.anm_data_d):
            for index_d_sub, sect_d_item in enumerate(sect_d_sub_list):

                if sect_d_item.entry_type == anm_d_entry_type_sub_img:
                    # fixme, pos_x and pos_y shown twice
                    self.item_info_extra.append(
                        nt_sub_item_info_anmdata(
                            'D: Sub-image %d, %d' % (index_d, index_d_sub),
                            str(sect_b_item.pos_x), str(sect_b_item.pos_y), '',
                            '', _sect_d_type_2_item_info_to_str(sect_d_item)))

                elif sect_d_item.entry_type == anm_d_entry_type_rectangle:
                    self.item_info_extra.append(
                        nt_sub_item_info_anmdata(
                            'D: Rectangle %d, %d' % (index_d, index_d_sub),
                            str(sect_d_item.pos_x), str(sect_d_item.pos_y),
                            str(sect_d_item.width), str(sect_d_item.height),
                            'border: %02x fill: %04x' %
                            (sect_d_item.border_color, sect_d_item.fill)))

                elif sect_d_item.entry_type == anm_d_entry_type_line:
                    self.item_info_extra.append(
                        nt_sub_item_info_anmdata(
                            'D: Line (*: x2, y2) %d, %d' %
                            (index_d, index_d_sub), str(sect_d_item.pos_x1),
                            str(sect_d_item.pos_y1), str(sect_d_item.pos_x2),
                            str(sect_d_item.pos_y2),
                            'color: %02x' % (sect_d_item.line_color, )))

                elif sect_d_item.entry_type == anm_d_entry_type_sound:
                    self.item_info_extra.append(
                        nt_sub_item_info_anmdata(
                            'D: Sound %d, %d' % (index_d, index_d_sub), '', '',
                            '', '', 'sound: %d' % sect_d_item.sound_info))


str_msg_frame_numbering = ('ViewerDataObj_AnmViewer - '
                           'Inconsistency in animation frame numbering')


class ViewerDataObj_AnmViewer(ViewerDataObj_Animation):
    '''
    ViewerDataObj_Animation subclass, for viewing animations contained in
        an ANM file. The animation frame information is stored in an
        associated ViewerDataObj_AnmFrames object.
    '''
    # obj_identifier, obj_description: The ID and the description of the
    #     object (defined in ResDataBase_ViewerDataObj)
    obj_identifier = s_vdata_anmviewer
    obj_description = 'ANM animations'

    # viewer_obj_id_frames, viewer_obj_file_ext: Required for accessing
    #     the associated viewer object that contains the frame data.
    #     (ViewerDataObj_StoredData) (originally defined in the parent)
    viewer_obj_id_frames = s_vdata_anmframes
    viewer_obj_file_ext = ext_subf_anm

    def get_expected_frame_number(self):
        '''
        Re-implementation of get_expected_frame_number,
            from ViewerDataObj_Animation
        '''
        anm_data = self.obj_frame_data.get_anm_data()
        if anm_data is None: return 0

        return len(anm_data.anm_data_d)

    def add_anim_info(self):
        '''
        Re-implementation of add_anim_info, from ViewerDataObj_Animation
        '''
        anm_data = self.obj_frame_data.get_anm_data()

        if anm_data is None: return

        index_sect_c_next = 0
        len_sect_c = len(anm_data.anm_data_c)

        if len_sect_c == 0: return

        # NOTE that a dict comprehension cannot be used here
        #     as we need the first rather than the last item for each
        if anm_data.anm_data_a:
            data_a_dict = {}
            for cnt_frame_a, frame_num_a in enumerate(anm_data.anm_data_a):
                if frame_num_a not in data_a_dict:
                    data_a_dict[frame_num_a] = cnt_frame_a
        else:
            data_a_dict = None

        for cnt_frame in xrange(len(anm_data.anm_data_d)):
            cnt_frame_anm = (data_a_dict[cnt_frame]
                             if data_a_dict is not None else cnt_frame)

            if index_sect_c_next < len_sect_c:
                first_frame_sect_c_next = anm_data.anm_data_c[
                    index_sect_c_next].first_frame_id

                if first_frame_sect_c_next == cnt_frame_anm:
                    if index_sect_c_next != 0:
                        self.end_current_animation(
                            anm_data.anm_data_c[index_sect_c_next -
                                                1].part_state_id, len_sect_c)

                    index_sect_c_next += 1

                if first_frame_sect_c_next < cnt_frame_anm:
                    if first_frame_sect_c_next == (cnt_frame_anm - 1):
                        # HACK fix for some .ANM files, NOTE: ignores sect. A
                        self.add_anim_frame(cnt_frame - 1, 1)
                        continue

                    print_msg(str_msg_frame_numbering)
                    return

            # NOTE on section A: This section is either empty or an array of 16-bit
            #     integer numbers, in ascending order from 0 to the number to the
            #     number of B section items. The only exception from the rule is
            #     that some numbers are repeated (e.g. 0 1 1 1 2...), indicating
            #     which frames should be displayed longer

            # NOTE: cnt_frame, not cnt_frame_anm
            self.add_anim_frame(cnt_frame,
                                (anm_data.anm_data_a.count(cnt_frame)
                                 if anm_data.anm_data_a else 1))

        if index_sect_c_next != len_sect_c:
            # TODO, raises may occur in some "valid" AMN files
            #     So d not raise an exception
            print_msg(str_msg_frame_numbering)

        self.end_current_animation(
            anm_data.anm_data_c[index_sect_c_next - 1].part_state_id,
            len_sect_c)
