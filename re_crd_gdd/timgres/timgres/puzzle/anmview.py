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

import zlib
from collections import namedtuple
from timgres.base.misc import (print_msg, print_traceback, namedtuple_to_str,
                               s_vdata_special_storeddata,
                               s_vdata_special_storeddata_anim,
                               s_obj_pngshapedraw16, s_opt_flip, s_opt_zoom,
                               s_opt_anim_delay)
from timgres.base.vdobase import (ResDataBase_ViewerDataObj,
                                  ViewerDataObj_MultiSubImage,
                                  nt_info_col_header, nt_anim_info, nt_size,
                                  flip_none, flip_vertical, flip_horizontal,
                                  _num_list_to_str_nosp)

# --- Base classes for animation frame/animation viewer objects ---

'''
This module contains base classes and mixins for implementing viewer objects
     used for animations and animation frames for TIM parts. Additionally,
     these serve as base classes for implementing puzzle viewers. The
     information for animation frames is stored either in game resource
     files (TIM 2 -> AnmFramesViewerMixin) or in a special Python module
     (TIM, TEMIM -> StoredDataViewerMixin). The module also contains a
     ViewerDataObj_MultiSubImage subclass (ViewerDataObj_Animation) that
     can serve as a base class for viewer objects for animations.
'''

# nt_sub_item_info_animation: Namedtuple for sub-item information
#     (sub_item_info), used in class ViewerDataObj_Animation.
#     All members are strings.
# anim_text: Text displayed in the first column in the "Information" panel
#     (table), also used by get_sub_item_texts
# notes: Additional information.
nt_sub_item_info_animation = namedtuple('nt_sub_item_info_animation',
                                        ('anim_text', 'notes'))


class ViewerDataObj_Animation(ResDataBase_ViewerDataObj):
    '''
    A ResDataBase_ViewerDataObj sub-class uses the animation sub-frames
        from an ViewerDataObj_MultiSubImage object. Unlike the related class
        ViewerDataObj_MultiSubImage, the "actual" animation will be displayed
        in the GUI (export of animations has not been implemented yet).
    Contains two abstract methods: get_expected_frame_number and
        add_anim_info.
    '''

    # viewer_obj_id_frames: the ID of the "associated"
    #     ViewerDataObj_MultiSubImage object.
    viewer_obj_id_frames = ''

    # viewer_obj_file_ext: Required for obtaining the "associated" object.
    viewer_obj_file_ext = ''

    # NOTE that this class depends on a "special" behavior of ResDataManager:
    #     the open_sub_file() methods of ViewerDataObjects  for the same
    #     type of resource are called in alphabetical order.
    # Thus, this class will only work properly if
    #     viewer_obj_id_frames > obj_identifier is True

    # info_col_headers: corresponds to the items of nt_sub_item_info_animation
    info_col_headers = (
        nt_info_col_header('Sub-file', 180),
        nt_info_col_header('Notes', 720),
    )

    def reset_data(self):
        '''
        Re-implementation of reset_data from ResDataBase_ViewerDataObj.
            Initializes class-specific fields.
        '''
        # NOTE: re-implements reset_data, not reset_data_subclass.
        #     reset_data_subclass is left for specific viewer implementations,
        #     not used in "base" classes.
        ResDataBase_ViewerDataObj.reset_data(self)
        # obj_frame_data: The associated "viewer data object", the
        #     source of animation frame data.
        self.obj_frame_data = None
        # anim_delay: The anim_delay option from parent.
        self.anim_delay = None
        # add_anim_frame: A temporary list of nt_anim_info namedtuples,
        #     used by add_anim_frame and end_current_animation
        self.anim_sub_list = []

    def get_expected_frame_number(self):
        '''
        Must be re-implemented in a sub-class. Used for checking the number
            of animation sub-frames in the "associated"
            ViewerDataObj_MultiSubImage object. An implementation must return
            the expected number (int).
        '''
        raise NotImplementedError('get_expected_frame_number - '
                                  'Not implemented in ViewerDataObj_Animation')

    def add_anim_info(self):
        '''
        Must be re-implemented in a sub-class. An implementation of this
            method must call add_anim_frame for each animation frame and
            end_current_animation when all frames have been added.
        '''
        raise NotImplementedError(
            'add_anim_info - Not implemented in ViewerDataObj_Animation')

    def add_anim_frame(self, frame_id, duration_rel):
        '''
        This "protected" method must be called from an add_anim info
            implementation only. Adds animation information to the
            temporary list self.anim_sub_list.
        frame_id: Animation frame ID in self.obj_frame_data
        duration_rel: "relative" duration, will be multiplied by anim_delay
        '''
        self.anim_sub_list.append(
            nt_anim_info(frame_id, duration_rel * self.anim_delay))

    def get_animation_text(self, part_state_id, num_animations):
        '''
        This "protected" method must be called from an add_anim info
            implementation only (as it uses self.sub_item_info.).
        returns the string value that will be used to set the first item
            of nt_sub_item_info_animation namedtuple
        May be re-implemented in a sub-class if needed
        part_state_id: an identifier associated with the animation,
            probably corresponds to one "state" of a part.
            (see nt_anm_sect_c_entry.part_state_id) (not used in default
            implementation)
        num_animations: the number of animations
        '''
        return 'Animation (%d frame%s) [%d/%d]' % (len(
            self.anim_sub_list), ('s' if len(self.anim_sub_list) > 1 else
                                  ''), len(self.anim_info), num_animations)

    def end_current_animation(self, part_state_id, num_animations):
        '''
        This "protected" method must be called from an add_anim info
            implementation only (as it uses self.sub_item_info.).
        Must be called at the and of each animation (from add_anim_info)
        part_state_id: an identifier associated with the animation,
            probably corresponds to one "state" of a part.
            (see nt_anm_sect_c_entry.part_state_id)
        num_animations: the number of animations (unused!)
        '''
        self.sub_item_info.append(
            nt_sub_item_info_animation(
                self.get_animation_text(part_state_id, num_animations),
                'part_state_id: %d anm_frames: %s' % (part_state_id, ','.join(
                    '%d' % x if y == self.anim_delay else '%d(%dms)' % (x, y)
                    for x, y in self.anim_sub_list))))

        self.anim_info.append(self.anim_sub_list)
        self.anim_sub_list = []

    def open_sub_file(self, sub_f_name):
        '''
        Re-implementation of open_sub_file from ResDataBase_ViewerDataObj.
        See meaning of argument there. Obtains the animation frames from the
            associated viewer object (self.obj_frame_data) Fills all list
            members of the class, required in a ViewerDataObj.
        '''
        self.reset_data()

        # Get the "associated" ViewerDataObj_MultiSubImage object,
        #     containing the animation sub-frames
        # NOTE that self.parent.get_viewer_obj_for_selection() cannot be
        #     used here (self.selected_viewer_data_objs_ext not set)
        self.obj_frame_data = self.parent.get_viewer_obj_by_id(
            self.viewer_obj_file_ext, self.viewer_obj_id_frames)

        # NOTE: Uses methods from ViewerDataObj_MultiSubImage that are
        #     not available in its parent class
        # This could be also an str to None comparison
        if self.obj_frame_data.get_sub_file_name() != sub_f_name:
            raise RuntimeError(
                ('Loaded file name does not match between '
                 ' viewer objects" %d" and "%d"') %
                (self.obj_identifier, self.viewer_obj_id_frames))

        data_frames = self.obj_frame_data.get_img_data_frames()

        if len(data_frames) != self.get_expected_frame_number():
            raise RuntimeError(
                ('Number of anim. frames do not match between '
                 ' viewer objects" %d" and "%d"') %
                (self.obj_identifier, self.viewer_obj_id_frames))

        self.img_data_frames = data_frames
        self.anim_delay = self.parent.get_option(s_opt_anim_delay)
        self.add_anim_info()
        self.item_info_head = nt_sub_item_info_animation(
            'Info: ' + self.obj_description,
            'anm_file: %s anim_delay: %dms' % (sub_f_name, self.anim_delay))
        self.recomm_canvas_size = \
            self.obj_frame_data.get_recommended_canvas_size()


# ... ....

str_err_storeddata_none_arg = ('set_stored_data: '
                               'Accepts either 0 or 2 None arguments.')

str_warn_group_unavail = ('StoredDataViewerMixin: Warning: %s, '
                          'items in group %d will not be available')

# See documentation in reset_stored_data
## index_sub_imgs_in_data = 2
name_pattern_res_part = 'PART%d.BMP'

str_err_graphics_not_in_ver = ('Graphics requested that is not available '
                               'in the opened game version.')


class StoredDataViewerMixin(object):
    '''
    A mixin for implementing ViewerDataObj_MultiSubImage subclasses
        that support animation frames composed of multiple images, but no
        animation. This class does not read the animation frame information
        from a game resource file, but depends on a "data source" (see
        set_stored_data).
    This mixin adds extra methods ViewerDataObj_MultiSubImage thet facilitate
         implementation of  set_sub_image_load_info and set_frame_data.
    It can be used for implementing classes that either can show all of the
        data for the current game version or combine graphics for multiple
        items into a screen (level viewer).
    Uses the following fields  and methods from ViewerDataObj_MultiSubImage:
        parent, add_single_sub_image_load_info, add_new_img_curr_frame
    '''

    def reset_stored_data(self):
        '''
        Resets the "stored data", information about the animation frames.
        '''
        # NOT affected by reset_data. Format description copied from t1_p1info.

        # data_checksums: The check-sums used for identifying the game version
        # A tuple, one item for each group (depending on presence/absence in)
        #     versions
        # Format if "inner" tuples:
        #     0. group id (based on availability in demo/full game), int
        #     1. image resource name (str)
        #     2. the crc32 checksum (unsigned 32 bit int)
        self.data_checksums = None

        # data_sub_img_pos: The positions (x, y) & other important data
        #     for each animation frame
        # Format of inner tuples:
        #     0. Frame information tuple, see format below
        #     1... information for each sub-image that will be displayed
        #
        # Format of "inner-inner" tuple 0 (frame information)
        #     0. The group id (from info_checksums)
        #     1. animation information
        #     2. frame width
        #     3. frame height
        #     4. x offset (frame)
        #     5. y offset (frame)
        #
        # Format of "inner-inner" tuples 1... (info for each sub-image):
        #     0. Resource file I.D eg. 15 -> 'PART15.BMP'
        #     1. Resource sub-item ID
        #     2. x offset (sub-image)
        #     3. y offset (sub-image)
        #     4. reserved for flip, currently unused
        self.data_sub_img_pos = None

        # groups_present: Result of crc32 check (set) or None if no check has
        #      been performed. Contains Available Group IDs, when the
        #      check was successful.
        self.groups_present = None

    def set_stored_data(self, new_data_checksums, new_data_sub_img_pos):
        '''
        Sets the "stored data" for the class (sub-image and checksum
            information).
        new_data_checksums: List or tuple, see description in vd_sdata.py
        new_data_sub_img_pos: List or tuple, see description in vd_sdata.py
        '''
        if new_data_checksums is not None:
            if not isinstance(new_data_checksums, (tuple, list)):
                raise TypeError('new_data_checksums: must be list or tuple')

            if new_data_sub_img_pos is None:
                raise ValueError(str_err_storeddata_none_arg)

        if new_data_sub_img_pos is not None:
            if not isinstance(new_data_sub_img_pos, (tuple, list)):
                raise TypeError('new_data_sub_img_pos: must be list or tuple')

            if new_data_checksums is None:
                raise ValueError(str_err_storeddata_none_arg)

        self.data_checksums = new_data_checksums
        self.data_sub_img_pos = new_data_sub_img_pos
        # Reset groups_present
        self.groups_present = None

    def add_sub_image_load_info_s_data_single(self, sub_item_data, flip):
        '''
        For internal use, Must be called from  set_sub_image_load_info,
            calls add_single_sub_image_load_info for sub-images.
            add_sub_image_load_info_s_data_index should be used instead
            if possible.
        sub_item_data: One entry from data_sub_img_pos (tuple).
        flip: An optional flip that is distinct from both the flip specified
            in the data_sub_img_pos entry and the s_opt_flip option of parent.
            Set to flip_none if this feature is not required. (int)
        '''
        # Note: no check for groups_present

        for res_f_num, sub_img_id, offs_x, offs_y, data_flip in \
                sub_item_data[1:]:
            # Note_ offs_x, offs_y unused here
            self.add_single_sub_image_load_info(
                name_pattern_res_part % res_f_num, sub_img_id,
                data_flip ^ flip)

    def add_sub_image_load_info_s_data_index(self, sub_item_index, flip):
        '''
        In sub-classes, this method must be called from
            set_sub_image_load_info. Calls add_single_sub_image_load_info
            for all sub-images defined in a single data_sub_img_pos entry.
            Performs some additional checks compared to
            add_sub_image_load_info_s_data_single.
        sub_item_index: An index in data_sub_img_pos (int).
        flip: See add_sub_image_load_info_s_data_single
        '''

        sub_item_data = self.data_sub_img_pos[sub_item_index]

        # NOTE: Difference from add_sub_image_load_info_s_data_all:
        #     raises an exception if sub-item with the specified index
        #     is not available in the opened game version.
        if ((self.groups_present is None)
                or (sub_item_data[0][0] not in self.groups_present)):
            # TODO, more informative error message (but part number not
            #     available here...)
            raise RuntimeError(str_err_graphics_not_in_ver)

        self.add_sub_image_load_info_s_data_single(sub_item_data, flip)

    def add_new_img_curr_frame_s_data_single(self,
                                             sub_item_data,
                                             pos_rel_x,
                                             pos_rel_y,
                                             flip,
                                             flip_axis_x=None,
                                             flip_axis_y=None):
        '''
        For internal use. Must be called from set_frame_data,
            calls add_new_img_curr_frame for sub-images.
            add_new_img_curr_frame_s_data_index should be used instead
            if possible.
        sub_item_data: One entry from data_sub_img_pos (tuple).
        pos_rel_x, pos_rel_y: An optional offset  of x and y coordinates for
            the sub images defined in a single data_sub_img_pos entry. (int)
        flip: An optional flip, see add_sub_image_load_info_s_data_single.
        flip_axis_x, flip_axis_y: Axes used for flipping the animatin frame
            (int or None). If None, defaults to frame_w and frame_h,
            (from sub_item_data) respectively.
        '''

        group_num, anim_info, frame_w, frame_h, frame_offs_x, \
            frame_offs_y = sub_item_data[0]

        flip_x = flip_axis_x if flip_axis_x is not None else frame_w
        flip_y = flip_axis_y if flip_axis_y is not None else frame_h

        for res_f_num, sub_img_id, offs_x, offs_y, data_flip in \
                sub_item_data[1:]:

            # TODO (?) flip frame_offs_x (?)
            pos_x_flip = flip_x - offs_x if flip & flip_horizontal else offs_x
            pos_y_flip = flip_y - offs_y if flip & flip_vertical else offs_y

            self.add_new_img_curr_frame(name_pattern_res_part % res_f_num,
                                        sub_img_id, data_flip ^ flip,
                                        pos_x_flip + frame_offs_x + pos_rel_x,
                                        pos_y_flip + frame_offs_y + pos_rel_y,
                                        False)

    def add_new_img_curr_frame_s_data_index(self,
                                            sub_item_index,
                                            pos_rel_x,
                                            pos_rel_y,
                                            flip,
                                            flip_axis_x=None,
                                            flip_axis_y=None):
        '''
        In sub-classes, this method must be called from set_frame_data,
            Calls add_new_img_curr_frame for sub-sub-images defined in
            a single data_sub_img_pos entry. Performs some additional
            checks compared to add_new_img_curr_frame_s_data_single.
        sub_item_index: An index in data_sub_img_pos (int).
        pos_rel_x, pos_rel_y: An optional offset  of x and y coordinates,
            see add_new_img_curr_frame_s_data_single
        flip: An optional flip, see add_sub_image_load_info_s_data_single.
        flip_axis_x, flip_axis_y: Optional flip axes, see
            add_new_img_curr_frame_s_data_single
        '''
        sub_item_data = self.data_sub_img_pos[sub_item_index]

        self.add_new_img_curr_frame_s_data_single(sub_item_data, pos_rel_x,
                                                  pos_rel_y, flip, flip_axis_x,
                                                  flip_axis_y)

    def perform_crc32_checks(self):
        '''
        Performs crc32 checks, in order to decide which game version is in use
        '''
        res_read = self.parent.get_res_read_obj()
        self.groups_present = set()

        if self.data_checksums is None: return

        for group_id, sub_f_name, crc32_correct in self.data_checksums:
            if group_id < 0:
                continue

            try:
                file_data = res_read.get_single_file_data(sub_f_name)
            except ValueError as ex:
                # get_single_file_data raises ValueError if
                #     the sub-file does not exist
                print_traceback()
                warn_msg_part = 'Sub-file "%s" not found' % sub_f_name
                print_msg(str_warn_group_unavail % (warn_msg_part, group_id))
                # No print_traceback!
                continue

            # zlib.crc32() & 0xffffffff: Python 2 compat hack
            if (zlib.crc32(file_data) & 0xffffffff) == crc32_correct:
                self.groups_present.add(group_id)
            else:
                warn_msg_part = 'Wrong crc32 checksum, file "%s"' % sub_f_name
                print_msg(str_warn_group_unavail % (warn_msg_part, group_id))


# ... ....

# Int constants for .ANM section D commands
anm_d_entry_type_sub_img = 2
anm_d_entry_type_rectangle = 3
anm_d_entry_type_line = 4
anm_d_entry_type_sound = 5

# name_pattern_res_anm: ANM file name for specific part. Must be used
#     with "%" formatting. Note: not used directly in this module.

name_pattern_res_anm = 'PART%d.ANM'


class AnmFramesViewerMixin(object):
    '''
    A mixin for implementing ViewerDataObj_MultiSubImage subclasses
        that support viewing animation frames, for which the data stored in
        .ANM animation files.
    This mixin adds extra methods ViewerDataObj_MultiSubImage thet facilitate
         implementation of  set_sub_image_load_info and set_frame_data.
    It can be used for implementing classes that either can show the frames
        in a single animation file or combine graphics for multiple
        items into a screen (level viewer).
    Uses the following fields  and methods from ViewerDataObj_MultiSubImage:
        parent, add_single_sub_image_load_info, add_new_img_curr_frame
    '''

    def reset_anim_file_data(self):
        '''
        Resets the field storing information from the opened .ANM files.
        '''
        # anm_files_data: Dict containing the names of the .ANM files already
        #     opened, and the data retrieved from them. Serves as a "cache"
        #     for the files already decoded.
        #     Dict key: file name (str), values: nt_anm_data
        self.anm_files_data = {}

    def decode_anm_file(self, anm_file_name):
        '''
        For internal use. If the .ANM file anm_file_name is not present in
            dict anm_files_data, the file is decoded, the result is stored
            in the list, and returned by the function. Otherwise, retrieves
            the data stored in the dict for anm_file_name.
        anm_file_name: The .ANM file name (str)
        Returns nt_anm_data namedtuple.
        '''
        # First, check if the file has been already cached
        anm_data = self.anm_files_data.get(anm_file_name)

        if anm_data is None:
            # NOTE: at present, ANM decode only accepts None as process info**
            anm_data = self.parent.decode_sub_file(anm_file_name, None)
            self.anm_files_data[anm_file_name] = anm_data

        return anm_data

    def add_sub_image_load_info_anm_single(self, anm_data, sect_d_sub_list,
                                           flip):
        '''
        For internal use, Must be called from set_sub_image_load_info, calls
            add_single_sub_image_load_info for sub-images referenced in
            sect_d_sub_list. add_sub_image_load_info_anm_index should be used
            instead if possible. Can be used only when the .ANM has aleady
            been decoded.
        anm_data: The namedtuple from ANM decoding, nt_anm_data
        sect_d_sub_list: One sub list from nt_anm_data.n_items_d, must be
            from anm_data, however this is not "enforced".
        flip: An optional flip that is distinct from both the flip specified
            in the data_sub_img_pos entry and the s_opt_flip option of parent.
            Set to flip_none if this feature is not required. (int)
        '''

        for sect_d_item in sect_d_sub_list:
            if sect_d_item.entry_type == anm_d_entry_type_sub_img:
                # Note: one-based indices!
                # img_flip is XOR red with flip
                bmp_name = anm_data.bmp_names[sect_d_item.bmp_file_id - 1].\
                    upper()

                self.add_single_sub_image_load_info(
                    bmp_name, sect_d_item.bmp_sub_img_id,
                    sect_d_item.img_flip ^ flip)

    def add_sub_image_load_info_anm_index(self, anm_file_name,
                                          anim_frame_index, flip):
        '''
        In sub-classes, this method must be called from
            set_sub_image_load_info. Calls add_single_sub_image_load_info
            for all sub-images referenced in a Section D sub-list.
            Unlike add_sub_image_load_info_anm_single, the first argument
            is an animation  file name, which is decoded when the data is not
            yet present in anm_files_data.
        anm_file_name: The .ANM file name.
        anim_frame_index: If the ANM file has no A section, an index in
            Section B of the .ANM file. If there is an A section, this needs
            to be taken into account for determining the B & Đ section
            index (int)
        flip: See add_sub_image_load_info_anm_single.
        '''

        anm_data = self.decode_anm_file(anm_file_name)

        sect_b_d_index = (anm_data.anm_data_a[anim_frame_index]
                          if anm_data.anm_data_a else anim_frame_index)

        if sect_b_d_index >= len(anm_data.anm_data_b):
            print_msg(('Inconsistency found while loading animation frames '
                       'from file "%s"') % anm_file_name)
            return

        self.add_sub_image_load_info_anm_single(
            anm_data, anm_data.anm_data_d[sect_b_d_index], flip)

    def add_new_img_curr_frame_s_data_single(self,
                                             anm_data,
                                             sect_b_item,
                                             sect_d_sub_list,
                                             pos_rel_x,
                                             pos_rel_y,
                                             flip,
                                             flip_axis_x=None,
                                             flip_axis_y=None,
                                             alternative_flip=False):
        '''
        For internal use. Must be called from set_frame_data,
            calls add_new_img_curr_frame for sub-images.
            add_sub_image_load_info_anm_index should be used instead
            if possible.
        anm_data: The namedtuple from ANM decoding, nt_anm_data.
        sect_b_item: One item from nt_anm_data.n_items_b,
            must be from anm_data (nt_anm_sect_b_entry).
        sect_d_sub_list: One sub list from nt_anm_data.n_items_d, must be
            from anm_data, however this is not "enforced".
        pos_rel_x, pos_rel_y: An optional offset  of x and y coordinates for
            the sub images defined in a single section D sub-list. (int)
        flip: An optional flip, see add_sub_image_load_info_anm_single.
        flip_axis_x, flip_axis_y: Axes used for flipping the animatin frame
            (int or None). If None, defaults to width anf height,
            respectively. from sect_b_item
        alternative_flip: See flip_right_bottom in add_single_sub_img_data
            (ViewerDataObj_MultiSubImage, vdobase.py)
        '''

        # TODO, sect_b_item.width and .height correct here (?)
        flip_x = (flip_axis_x
                  if flip_axis_x is not None else sect_b_item.width)
        flip_y = (flip_axis_y
                  if flip_axis_y is not None else sect_b_item.height)

        png_shape_draw = self.parent.get_object(s_obj_pngshapedraw16)

        for sect_d_item in sect_d_sub_list:
            if sect_d_item.entry_type == anm_d_entry_type_sub_img:
                bmp_name = anm_data.bmp_names[sect_d_item.bmp_file_id - 1].\
                    upper()

                # TODO, currently only sect_d_item.pos_* is flipped
                pos_x_flip = (flip_x - sect_d_item.pos_x
                              if flip & flip_horizontal else sect_d_item.pos_x)
                pos_y_flip = (flip_y - sect_d_item.pos_y
                              if flip & flip_vertical else sect_d_item.pos_y)

                self.add_new_img_curr_frame(
                    bmp_name, sect_d_item.bmp_sub_img_id,
                    sect_d_item.img_flip ^ flip,
                    pos_x_flip + sect_b_item.pos_x + pos_rel_x,
                    pos_y_flip + sect_b_item.pos_y + pos_rel_y,
                    alternative_flip)

            elif sect_d_item.entry_type == anm_d_entry_type_rectangle:
                # Rectangle is filled when the most significant bit
                #     of fill is set!

                png_data_rect = png_shape_draw.draw_rectangle_with_border(
                    sect_d_item.width, sect_d_item.height,
                    sect_d_item.border_color,
                    (sect_d_item.fill & 0xff if sect_d_item.fill
                     & 0x8000 else None))

                pos_x_flip = (flip_x - sect_d_item.pos_x
                              if flip & flip_horizontal else sect_d_item.pos_x)
                pos_y_flip = (flip_y - sect_d_item.pos_y
                              if flip & flip_vertical else sect_d_item.pos_y)

                self.add_single_sub_img_data_special(png_data_rect,
                                                     pos_x_flip + pos_rel_x,
                                                     pos_y_flip + pos_rel_y)

            elif sect_d_item.entry_type == anm_d_entry_type_line:
                png_data_line = png_shape_draw.draw_line(
                    sect_d_item.pos_x2 - sect_d_item.pos_x1,
                    sect_d_item.pos_y2 - sect_d_item.pos_y1,
                    sect_d_item.line_color, flip)

                pos_x_temp = min(sect_d_item.pos_x1, sect_d_item.pos_x2)
                pos_y_temp = min(sect_d_item.pos_y1, sect_d_item.pos_y2)

                pos_x_flip = (flip_x - pos_x_temp
                              if flip & flip_horizontal else pos_x_temp)
                pos_y_flip = (flip_y - pos_y_temp
                              if flip & flip_vertical else pos_y_temp)

                self.add_single_sub_img_data_special(png_data_line,
                                                     pos_x_flip + pos_rel_x,
                                                     pos_y_flip + pos_rel_y)

            elif sect_d_item.entry_type == anm_d_entry_type_sound:
                print_msg(('The .ANM file contains an instruction to play '
                           'sound %d. Sound playback is not implemented.') %
                          sect_d_item.sound_info)
            else:
                raise RuntimeError('Invalid entry type in .ANM section D')

    def add_new_img_curr_frame_s_data_index(self,
                                            anm_file_name,
                                            anim_frame_index,
                                            pos_rel_x,
                                            pos_rel_y,
                                            flip,
                                            flip_axis_x=None,
                                            flip_axis_y=None,
                                            alternative_flip=False,
                                            lookup_in_text_c=True):
        '''
        In sub-classes, this method must be called from set_frame_data,
            Calls add_new_img_curr_frame for sub-sub-images defined in
            a frame from an animation file (anim_frame_index).
            A the file name must be provided as an argument.
        anm_file_name: Name of an .ANM file, alrwady decoded
            by add_sub_image_load_info_anm_index.
        anim_frame_index: If the ANM file has no A section, an index in
            Section B of the .ANM file. If there is an A section, this needs
            to be taken into account for determining the B & Đ section
            index (int)
        pos_rel_x, pos_rel_y: An optional offset  of x and y coordinates,
            see add_new_img_curr_frame_s_data_single
        flip: An optional flip, see add_new_img_curr_frame_s_data_single.
        flip_axis_x, flip_axis_y: Optional flip axes, see
            add_new_img_curr_frame_s_data_single
        alternative_flip: See flip_right_bottom in add_single_sub_img_data
            (ViewerDataObj_MultiSubImage, vdobase.py)
        '''

        anm_data = self.anm_files_data.get(anm_file_name)

        if anm_data is None:
            raise ValueError('Error, add_new_img_curr_frame_s_data_index '
                             ' accepts only previously decoded .ANM files.')

        sect_b_d_index = (anm_data.anm_data_a[anim_frame_index]
                          if anm_data.anm_data_a else anim_frame_index)

        if sect_b_d_index >= len(anm_data.anm_data_b):
            print('!', anm_file_name, sect_b_d_index)
            return  # TEMPORARY HACK!

        self.add_new_img_curr_frame_s_data_single(
            anm_data, anm_data.anm_data_b[sect_b_d_index],
            anm_data.anm_data_d[sect_b_d_index], pos_rel_x, pos_rel_y, flip,
            flip_axis_x, flip_axis_y, alternative_flip)
