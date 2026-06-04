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

from collections import namedtuple
from timgres.base.basecl import ResDataItemBase
from timgres.base.misc import print_msg, s_opt_flip, s_opt_zoom
from timgres.base.bmpdbase import (flip_none, flip_vertical, flip_horizontal,
                                   flip_vertical_horizontal,
                                   nt_process_options_bm, nt_bm_sub_img_data)

# --- ViewerDataObj base class ---

'''
This module contains the base class ResDataBase_ViewerDataObj. ViewerDataObj
    subclasses store the information from an image (with multiple sub images)
    or animation resource suitable for viewing in a GUI or exporting.
    Another abstract base class (ViewerDataObj_MultiSubImage, a subcass of
    ResDataBase_ViewerDataObj) provides support for animation frames.
'''

# nt_size: Used for canvas size. width, height: int
nt_size = namedtuple('nt_size', ('width', 'height'))

# nt_info_col_header: Column information for a table widget that will be used
#     for displaying the item data stored in the ViewerDataObj.
# text (str): The caption of the column.
# width (int): The column width.
# (NOTE: additional fields might bee added later)
nt_info_col_header = namedtuple('nt_info_col_header', ('text', 'width'))

# nt_anim_info: Namedtuple for internal use.
# frame_id (int): the index of animation frame in
#     ResDataBase_ViewerDataObj.img_data_frames
# delay (int): The delay, in milliseconds until the next frame
nt_anim_info = namedtuple('nt_anim_info', ('frame_id', 'delay'))

# nt_image_display_data: Contains the data for a PNG image, as well as
#      the information required for displaying it in a canvas.
# pos_x, pos_y (int): The position of the top lefr corner if the image
#     is not flipped. See canvimgr for all other cases ("anchor")
# flip_img (int): One of the flip_* constants, see above.
# img_data (bytes): The PNG data.
nt_image_display_data = namedtuple('nt_image_display_data',
                                   ('pos_x', 'pos_y', 'flip_img', 'img_data'))


class ResDataBase_ViewerDataObj(ResDataItemBase):
    '''
    This is the abstract base class for "viewer data objects", a special
        type of object used by a ResDataManager. A "viewer data object"
        has multiple functions, the most important is to store image data
        in a form suitable for viewing and exporting. Additionally, it
        stores data about resources that can be viewed as a table form
        (or exported). It it also required for animations.
    Has one abstract method: open_sub_file
    '''

    # obj_identifier: used for identifying the object in parent
    obj_identifier = ''
    # obj_description: a short description that wil appear in GUI
    obj_description = ''
    # info_col_headers: list/tuple of nt_info_col_header nameduples
    info_col_headers = ()  # should be modified in sub-classes!

    def __init__(self):
        '''The constructor of the class. Requires no arguments.'''
        ResDataItemBase.__init__(self)
        self.reset_data()

    def reset_data(self):
        '''
        Resets the values of all fields that store the data associated with
            the ViewerDataObj.
        '''

        # item_info_head: If set (not None), a class-specific namedtuple
        #     (same type as sub_item_info), that will be displayed as
        #     the first item in item info widget
        self.item_info_head = None

        # sub_item_info: list of class specific namedtuples
        #   NOTE: tuple item [0] of namedtuples in self.sub_item_info
        #   "special", used by get_sub_item_texts
        self.sub_item_info = []

        # item_info_extra: like sub_item_info, but not related to sub-items
        self.item_info_extra = []

        #  anim_info: list of lists! (nt_anim_info)
        #    length must be equal to len(self.sub_item_info)
        self.anim_info = []

        # img_data_frames: list of lists of nt_image_display_data
        #   NOTE that "image data frame" is not the same as sub-item!
        self.img_data_frames = []

        # sub_item_id: index in sub_item_info and anim_info
        self.sub_item_id = None

        # anim_frame: index in self.anim_info[self.sub_item_id]
        #   None before the first frame is shown
        self.anim_frame = None

        # image_info_frame_id: None or index in self.img_data_frames
        self.image_info_frame_id = None

        # recomm_canvas_size: Recommended canvas size, used by
        #   CanvasImageManager_TAnm, 1 pixel only by default (canvas unused)
        self.recomm_canvas_size = nt_size(1, 1)
        # Additional fields should be added in sub-classes
        self.reset_data_subclass()

    def reset_data_subclass(self):
        '''
        Provides a mechanism for defining new fields in sub-classes,
            affected by reset_data(). By default, does nothing.
        '''
        pass

    def open_sub_file(self, sub_f_name):
        '''
        Must be re-implemented in a sub class. An implementation must call
            self.parent.decode_sub_file for all files that are required for
            viewing an image/other resource. Must set self.sub_item_info,
            self.anim_info, self.img_data_frames and (optionally)
            self.item_info_extra and self.recomm_canvas_size.
        sub_f_name (str): The name of the resource sub-file to view
        '''
        raise NotImplementedError('open_sub_file: not implemented in '
                                  'in ResDataBase_ViewerDataObj')

    def select_sub_item(self, new_sub_item):
        '''
        Sets the selected sub-item of the object. Modifies self.sub_item_id.
        new_sub_item (int): Index of the item to select
        '''
        self.anim_frame = None
        self.image_info_frame_id = None

        if new_sub_item is not None:
            if not isinstance(new_sub_item, int):
                self.sub_item_id = None
                raise TypeError('new_sub_item: must be int')

            if (new_sub_item < 0) or (new_sub_item >= len(self.sub_item_info)):
                self.sub_item_id = None
                raise ValueError('Invalid sub-item index')

        self.sub_item_id = new_sub_item

    def get_img_data_curr_frame(self):
        '''
        Returns a list of nt_image_display_data namedtuples, containing
            the image data for the current animation frame.
        Returns an empty list if nothing is selected.
        '''
        return (list(self.img_data_frames[self.image_info_frame_id])
                if self.image_info_frame_id is not None else [])

    def get_time_delay_next_frame(self):
        '''
        Returns the delay between the currently visible frame and the next one
        Returns an integer number (milliseconds) or None (no anim.)
        '''
        if (self.anim_frame is not None) and (self.sub_item_id is not None):
            return self.anim_info[self.sub_item_id][self.anim_frame].delay

        # otherwise, returns None

    def get_obj_identifier(self):
        '''Returns the ID of the class (self.obj_identifier). (type: str)'''
        return self.obj_identifier

    def get_obj_description(self):
        '''
        Returns the short description associated with of the class
        (self.obj_description). (type: str)
        '''
        return self.obj_description

    def get_info_col_headers(self):
        '''
        Returns the column header information associated with the class.
        Return type: tuple of nt_info_col_header namedtuples
        '''
        return tuple(self.info_col_headers)  # make immutable!

    def get_sub_item_selected(self):
        '''Returns the selected sub-item ID (int) or None'''
        return self.sub_item_id

    def get_recommended_canvas_size(self):
        '''Returns the recommended canvas size (type: nt_size).'''
        return self.recomm_canvas_size

    def get_info_entries(self):
        '''
        Returns the information associated with the sub-items, ass well as
            the header and "extra" info, that can be displayed in a "table"
            form. Returns a list of class_specific namedtuples.
        '''
        list_head = ((self.item_info_head, )
                     if self.item_info_head is not None else ())

        return list(
            itertools.chain(list_head, self.sub_item_info,
                            self.item_info_extra))

    def get_sub_item_count(self):
        '''Returns the number of sub-items (int).'''
        return len(self.sub_item_info)

    def get_sub_item_texts(self):
        '''
        Returns the description associated with each sub-item.
        Uses tuple item [0] of namedtuples in self.sub_item_info.
        '''
        return [x[0] for x in self.sub_item_info]

    def anim_next_frame(self):
        '''
        Advances to the next animation frame, by setting
            self.image_info_frame_id
        '''
        if (not self.anim_info) or (self.sub_item_id is None): return

        anim_info_curr = self.anim_info[self.sub_item_id]

        if not anim_info_curr: return

        if self.anim_frame is not None:
            if self.get_time_delay_next_frame() is None:
                print_msg(
                    'WARNING, anim_next_frame called after end of animation')
                return

            self.anim_frame = (self.anim_frame + 1) % len(anim_info_curr)
        else:
            # NOTE: this function will be executed once if there is no anim
            #   (anim_info_curr has one item with delay = 0)
            self.anim_frame = 0

        self.image_info_frame_id = anim_info_curr[self.anim_frame].frame_id

    def get_single_img_frame(self, single_sub_item):
        '''
        This method is used by image exporters only. Does not change the
        This method is used by image exporters only. Does not change the
            following fields: self.anim_frame, self.sub_item_id,
            self.image_info_frame_id. This function does NOT support anim.
        Returns a copy of the corresponding img_data_frames sub-list
            or None if this sub-item has animation.
        single_sub_item (int): An index in self.img_data_frames
        '''
        anim_info_curr = self.anim_info[single_sub_item]

        if len(anim_info_curr) != 1:
            return  # Has animation (>1) or empty (0). returns None!

        if anim_info_curr[0].delay is not None:
            return  # returns None!

        img_frame_id = anim_info_curr[0].frame_id
        return list(self.img_data_frames[img_frame_id])


str_err_type_sub_f_name = 'sub_f_name: must be str'


def _check_sub_img_id(sub_img_id):
    '''
    "Private". Performs range check for sub_img_id (int, >= 0).
    Raises ValueError if invalid.
    '''
    # TODO, add extra type check (?)
    if sub_img_id < 0:
        raise ValueError('sub_img_id must be positive')


def _check_flip(flip):
    '''
    "Private". Performs range check for flip (int, 0-3).
    Raises ValueError if invalid.
    '''
    # TODO, add extra type check (?)
    if (flip < flip_none) or (flip > flip_vertical_horizontal):
        raise ValueError('flip: must be in range 0..3')


def _num_list_to_str_nosp(num_list):
    '''
    "Private" function. converts a list/any sequenne type of ints to a string
    with separator char=','. Output will contain no spaces.
    num_list: sequence of ints
    '''
    return ','.join('%d' % x for x in sorted(num_list))


class ViewerDataObj_MultiSubImage(ResDataBase_ViewerDataObj):
    '''
    A ResDataBase_ViewerDataObj sub-class that serves as an "abstract base
        class" for implementing "more complex" viewers, supporting more than
        one image in sub-items. Used for "animation frame" classes.
    Has two abstract methods: set_sub_image_load_info and set_frame_data.
    '''

    def reset_data(self):
        '''
        Re-implementation of reset_data from ResDataBase_ViewerDataObj.
            Initializes class-specific fields.
        '''
        # NOTE: re-implements reset_data, not reset_data_subclass.
        #     reset_data_subclass is left for specific viewer implementations,
        #     not used in "base" classes.

        ResDataBase_ViewerDataObj.reset_data(self)

        # sub_image_load_info: dict, key: sub-file name, value:
        #     a nt_process_options_bm namedtuple of two sets, one for
        #     the sub-items and one for the flips
        self.sub_image_load_info = {}

        # loaded_sub_img_data: dict, key: sub-file name, value: sub_images
        #     from the nt_bm_data namedtuple returned by the decoder
        self.loaded_sub_img_data = {}

        # curr_flip: stores flip, updated each time open_sub_file is called
        self.curr_flip = None
        # curr_zoom: the current zoom see curr_flip
        self.curr_zoom = None

        # sub_file_name: stores sub-file name during processing
        #     sub-image info (open_sub_file), None by default
        self.sub_file_name = None

        # img_data_curr_frame: None after a reset, a list of
        #     nt_image_display_data items if a new frame is being processed
        self.img_data_curr_frame = None

        # sub_img_usage_data: None (default) or a dict containing sub-image
        #     usage data (key: sub-file name, value: sub-image numbers (set))
        self.sub_img_usage_data = None

        # sub_img_data_special: Contains nt_bm_sub_img_data items that
        #     are not stored in loaded_sub_img_data, but were added using
        #     add_single_sub_img_data_special
        self.sub_img_data_special = []

        # curr_frame_width, curr_frame_height: a "pre-defined" width and
        #     height, set in add_new_frame
        self.curr_frame_width = None
        self.curr_frame_height = None

        # temp_canvas_width, temp_canvas_height: will be stored in
        #     self.recomm_canvas_size, Default is (1, 1), like in parent
        self.temp_canvas_width = 1
        self.temp_canvas_height = 1

    def get_sub_file_name(self):
        '''For internal use, returns self.sub_file_name (str)'''
        return self.sub_file_name

    def get_img_data_frames(self):
        '''
        For internal use, returns (a copy of) self.img_data_frames. Type:
            see ResDataBase_ViewerDataObj (base.vdobase)
        '''
        # Note: "inner" lists ar NOT copied
        return list(self.img_data_frames)

    def set_sub_image_load_info(self):
        '''
        Must be re-implemented in subclasses.
        A re-implementation must call add_single_sub_image_load_info.
            for each image sub-item.
        '''
        raise NotImplementedError(
            'set_sub_image_load_info - '
            'Not implemented in ViewerDataObj_MultiSubImage')

    def add_single_sub_image_load_info(self, sub_f_name, sub_img_id, flip):
        '''
        This "protected" method should be called only from the
            set_sub_image_load_info method implementation in a sub-class.
        sub_f_name (str): The image resource sub-file name.
        sub_img_id (int): The sub-image ID in the decoded sub-file.
        flip (int): One of the flip_* constants, associated with
            the sub image to be added, not the output.
        '''

        if not isinstance(sub_f_name, str):
            raise TypeError(str_err_type_sub_f_name)

        _check_sub_img_id(sub_img_id)
        _check_flip(flip)

        # "flip relative to current", can be determined using bitwise xor
        flip_rel_curr = flip ^ self.curr_flip

        data_sub_f = self.sub_image_load_info.get(sub_f_name)

        if data_sub_f is not None:
            data_sub_imgs, data_flips = data_sub_f
            data_sub_imgs.add(sub_img_id)
            data_flips.add(flip_rel_curr)
        else:
            self.sub_image_load_info[sub_f_name] = nt_process_options_bm(
                {sub_img_id}, {flip_rel_curr})

    def set_frame_data(self):
        '''
        Must be re-implemented in subclasses.
        A re-implementation must call add_new_frame for each frame
            and then add_new_img_curr_frame and end_frame_add_info
            for each image sub-item
        '''
        raise NotImplementedError(
            'set_frame_data - '
            'Not implemented in ViewerDataObj_MultiSubImage')

    def add_new_frame(self, new_frame_width, new_frame_height):
        '''
        This "protected" method should be called only from the
            set_frame_data method implementation in a sub-class.
        Must be called before starting adding images to a new animation frame.
        Resets the "temporary" variables for the currently modified frame.
        new_frame_width, new_frame_height (int): The width and the height
            of the new frame.
        '''
        # TODO, type check (?)
        if (new_frame_width < 0) or (new_frame_height < 0):
            raise RuntimeError('add_new_frame: new_frame_width and '
                               'new_frame_height must be non-negative')

        # TODO, sub_item info should be set here? FIXME: too "trivial"

        if self.img_data_curr_frame is not None:
            raise RuntimeError('add_new_frame was called before '
                               'last frame was finished')

        frame_width_zoom = new_frame_width * self.curr_zoom
        frame_height_zoom = new_frame_height * self.curr_zoom

        if frame_width_zoom > self.temp_canvas_width:
            self.temp_canvas_width = frame_width_zoom

        if frame_height_zoom > self.temp_canvas_height:
            self.temp_canvas_height = frame_height_zoom

        self.curr_frame_width = frame_width_zoom
        self.curr_frame_height = frame_height_zoom

        self.img_data_curr_frame = []
        self.sub_img_usage_data = {}

    def add_single_sub_img_data(self, sub_img_data, flip, pos_rel_x, pos_rel_y,
                                flip_right_bottom):
        '''
        "Private" method, called by add_new_img_curr_frame and
            add_single_sub_img_data_special. Add a new sub-image to the
            frame being processed (self.img_data_curr_frame).
        sub_img_data: nt_bm_sub_img_data, containing the image data
        flip (int): One of the flip_* constants, associated with
            the sub image to be added, not the output.
        pos_rel_x, pos_rel_y (int): Relative position, zoom (and flip)
            not yet taken into account.
        flip_right_bottom (bool): When set to True, uses "alternative" axes
            to flip the image horizontally and/or vertically (at the
            right and bottom of image, respectively)
        '''
        # NOTE: For internal use only, no argument checking

        pos_rel_x_zoom = pos_rel_x * self.curr_zoom
        pos_rel_y_zoom = pos_rel_y * self.curr_zoom

        if flip_right_bottom:
            pos_rel_x_temp = (pos_rel_x_zoom + sub_img_data.out_w if flip
                              & flip_horizontal else pos_rel_x_zoom)
            pos_rel_y_temp = (pos_rel_y_zoom + sub_img_data.out_h if flip
                              & flip_vertical else pos_rel_y_zoom)
        else:
            pos_rel_x_temp = pos_rel_x_zoom
            pos_rel_y_temp = pos_rel_y_zoom

        pos_x = (self.curr_frame_width - pos_rel_x_temp if self.curr_flip
                 & flip_horizontal else pos_rel_x_temp)
        pos_y = (self.curr_frame_height - pos_rel_y_temp if self.curr_flip
                 & flip_vertical else pos_rel_y_temp)

        flip_rel_curr = flip ^ self.curr_flip

        self.img_data_curr_frame.append(
            nt_image_display_data(pos_x, pos_y, flip_rel_curr,
                                  sub_img_data.png_data_flip[flip_rel_curr]))

    def add_new_img_curr_frame(self, sub_f_name, sub_img_id, flip, pos_rel_x,
                               pos_rel_y, flip_right_bottom):
        '''
        This "protected" method should be called only from the
            set_frame_data method implementation in a sub-class.
        Adds a sub-image to the current animation frame that has already been
            decoded and is stored in self.loaded_sub_img_data.
        sub_f_name (str): The image resource sub-file name.
        sub_img_id (int): The sub-image ID in the decoded sub-file.
        flip (int): One of the flip_* constants, associated with
            the sub image to be added, not the output.
        pos_rel_x, pos_rel_y (int): Relative position, zoom (and flip)
            not yet taken into account.
        flip_right_bottom (bool): When set to True, uses "alternative" axes
            to flip the image horizontally and/or vertically.
        '''

        # TODO, check pos_rel_x, pos_rel_y
        if not isinstance(sub_f_name, str):
            raise TypeError(str_err_type_sub_f_name)

        _check_sub_img_id(sub_img_id)
        _check_flip(flip)

        # "flip relative to current", can be determined using bitwise xor
        sub_img_data = self.loaded_sub_img_data[sub_f_name][sub_img_id]

        if not isinstance(sub_img_data.png_data_flip, tuple):
            raise RuntimeError(
                'File "%s" - decoder does not support flipping' % sub_f_name)

        sub_img_usage_item = self.sub_img_usage_data.get(sub_f_name)

        if sub_img_usage_item is not None:
            sub_img_usage_item.add(sub_img_id)
        else:
            self.sub_img_usage_data[sub_f_name] = {sub_img_id}

        self.add_single_sub_img_data(sub_img_data, flip, pos_rel_x, pos_rel_y,
                                     flip_right_bottom)

    def add_single_sub_img_data_special(self, sub_img_data, pos_rel_x,
                                        pos_rel_y):
        '''
        This "protected" method should be called only from the
            set_frame_data method implementation in a sub-class.
        Adds a nt_bm_sub_img_data item that is not stored in
            self.loaded_sub_img_data. Flip assumed to be flip_none (!)
        sub_img_data: nt_bm_sub_img_data, containing the image data
        pos_rel_x, pos_rel_y (int): Relative position, zoom (and flip)
            not yet taken into account.
        '''
        self.sub_img_data_special.append(sub_img_data)
        self.add_single_sub_img_data(sub_img_data, flip_none, pos_rel_x,
                                     pos_rel_y, False)

    def end_frame_add_info(self, sub_item_info):
        '''
        This "protected" method should be called only from the
            set_frame_data method implementation in a sub-class, after
            the last image of an animation frame has been added.
        sub_item_info: A subclass-specific namedtuple, will be added to
            self.sub_item_info
        '''
        if not isinstance(sub_item_info, tuple):
            raise TypeError('sub_item_info: must be namedtuple or tuple')

        self.sub_item_info.append(sub_item_info)

        # actually, no animation
        self.anim_info.append([nt_anim_info(len(self.img_data_frames), None)])
        self.img_data_frames.append(self.img_data_curr_frame)

        self.curr_frame_width = None
        self.curr_frame_height = None
        self.img_data_curr_frame = None
        self.sub_img_usage_data = None

    def sub_img_usage_data_text(self):
        '''
        This "protected" function should be called only from the
            set_frame_data method implementation in a sub-class.
        returns a str, example: "sub-imgs: FILE1.BMP/0,2 FILE2.BMP/5"
        '''
        if self.sub_img_usage_data is None:
            raise RuntimeError('sub_img_usage_data_text: available only '
                               'during sub-image processing')

        return 'sub-imgs: %s' % ' '.join(
            '%s/%s' % (k, _num_list_to_str_nosp(v))
            for k, v in sorted(self.sub_img_usage_data.items(),
                               key=lambda x: x[0]))

    def set_head_info(self):
        '''
        By default, does nothing (but does not raise an exception).
        An implementation in a sub-class must set self.item_info_head and
            (optionally) self.item_info_extra
        '''
        pass

    def open_sub_file(self, sub_f_name):
        '''
        Re-implementation of open_sub_file from ResDataBase_ViewerDataObj.
        See meaning of argument there.
        First, obtains the required image resource items by calling
            set_sub_image_load_info, which will store the data in temporary
            fields (if re-implemented).
        Second, obtains the corresponding PNG data using
            self.parent.decode_sub_file
        And finally, calls set_frame_data, which should fill all required list
            members inherited from the parent class.
        '''
        self.reset_data()
        self.curr_flip = self.parent.get_option(s_opt_flip)  # fixme
        self.curr_zoom = self.parent.get_option(s_opt_zoom)  # fixme
        self.sub_file_name = sub_f_name
        self.set_sub_image_load_info()

        # Not in "deterministic" order!
        for sub_f_name_img, sub_f_proc_data in \
                self.sub_image_load_info.items():
            bm_data = self.parent.decode_sub_file(sub_f_name_img,
                                                  sub_f_proc_data)

            # bm_info is ignored!
            self.loaded_sub_img_data[sub_f_name_img] = bm_data.sub_images

        self.set_frame_data()
        self.set_head_info()
        self.recomm_canvas_size = nt_size(self.temp_canvas_width,
                                          self.temp_canvas_height)
