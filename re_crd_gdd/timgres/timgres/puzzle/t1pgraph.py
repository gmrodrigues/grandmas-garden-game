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
# --- ... ---

from collections import namedtuple
from timgres.base.misc import (print_msg, s_obj_graphinfov1,
                               s_obj_puzzleinfov1)
from timgres.base.vdobase import (nt_size, flip_none, flip_vertical,
                                  flip_horizontal, _num_list_to_str_nosp)
from timgres.puzzle.anmview import name_pattern_res_part
from timgres.puzzle.puzdata import (game_ver_tim_demo, game_ver_tim,
                                    game_ver_temim, game_ver_tim_special,
                                    stored_file_name_rope)
from timgres.puzzle.puzgraph import (
    nt_field_layer_number, layer_for_part, PartGraphicsInfoBase,
    PuzzleGraphicsInfoBase, PartGraphicsInfoRopeMixin,
    PartGraphicsInfElectricOutletMixin, wall_part_thickness, wall_coords_check,
    puzzle_layer_background, puzzle_layer_fixed_parts,
    puzzle_layer_moving_parts, puzzle_layer_parts_bin_parts,
    puzzle_layer_foreground, puzzle_layer_foreground_parts_bin, nt_info_puzzle,
    int_16_to_2_bytes)
'''
This module contains PartGraphicsInfoBase and PuzzleGraphicsInfoBase
    subclasses required for viewing puzlle files from TIM and TEMIM.
'''

# In TIM and TEMIM, background color is always color 3 (cyan/teal).
background_color_t1 = 3

# Note that get_image_load_info and get_frame_images_info uses the
#     same namedtuple in PartGraphicsInfoT1
# layer_number: The number of layer the part belongs to. One
#     of the puzzle_layer_* constants. See puzgraph.py. (type: int)
# file_name: The name of bitmap file to read the sub-image from. If None,
#     the data from data_sub_img_pos of the associated puzzle viewer
#     (which inherits StoredDataViewerMixin) will be used, that stores
#     information about part animation frames consisting of multiple
#     images. (type: str or None)
# sub_img_id: Either a sub image ID in file file_name or an item index
#     in data_sub_img_pos. (type: int or None)
# extra_img: An optional image and associated information, that is not
#     not read from an image resource file, but created internally
#     by this program (see for example pngdraw.py). The information
#     is stored in a nt_bm_sub_img_data namedtuple. If this member is
#     not None, then file_name and sub_img_id must be None.
#     (type: nt_bm_sub_img_data or None)
# pos_rel_x, pos_rel_y: Offset  of x and y coordinates for the sub-image
#     (or sub-images when file_name is None.) Ignored when the namedtuple
#     is returned by method get_image_load_info.
# flip: An optional flip that is distinct from both the flip specified
#     in the data_sub_img_pos entry and the s_opt_flip option of parent.
#     (Type: int) See anmview.py, StoredDataViewerMixin.
# flip_axis_x, flip_axis_y: Optional axes for flipping. Only used when
#     file name is None and no extra_img was provided.
#     (Type: int or None) See anmview.py, StoredDataViewerMixin.

nt_graphics_info_t1 = namedtuple(
    'nt_graphics_info_t1',
    (nt_field_layer_number, 'file_name', 'sub_img_id', 'extra_img',
     'pos_rel_x', 'pos_rel_y', 'flip', 'flip_axis_x', 'flip_axis_y'))

# IMPORATNT NOTE: The top left corner in the TIM1/TEMIM puzzle viewer
#   output corresponds to position (-8, -8) in the puzzle file.
#   Needed because some parts start at position -8
t1_shift_all_x = -8
t1_shift_all_y = -8


class PartGraphicsInfo_T1_Simple(PartGraphicsInfoBase):
    '''
    PartGraphicsInfoBase subclass for TIM / TEMIM parts.
    '''

    def get_graphics_info_default(self,
                                  puzzle_part,
                                  frame_info_index,
                                  flip,
                                  shift_x,
                                  shift_y,
                                  layer=None):
        '''
        "Private" helpaer function for implementing get_frame_images_info.
        puzzle_part: The "raw" information for the current part,
            namedtuple subclass, see d_puzzle.py
        frame_info_index: Index in anim_frame_info in the corresponding
            part info namedtuple (nt_part_info_t1) (type: int).
        flip: One of the flip_* constants (type: int).
        shift_x, shift_y: An optional shift along X and Y axes (type: int)
        layer: Specifying a puzzle_layer_* constant instead of None allows
            placing a part to a layer different from the default. (type: int)
        Returns nt_graphics_info_t1.
        '''
        part_info = self.puzzle_graph_info.puzzle_info_obj.get_part_info(
            puzzle_part.part_num)

        if part_info.anim_frame_info[frame_info_index] < 0:
            file_name = None
            # Note: Item is negative if the data from data_sub_img_pos of
            #     the associated puzzle viewer will be used (sprites
            #     consisting of multiple images)
            sub_img_id = -1 - part_info.anim_frame_info[frame_info_index]
            flip_axis_x = part_info.flip_axis_x
            flip_axis_y = part_info.flip_axis_y
        else:
            file_name = name_pattern_res_part % puzzle_part.part_num
            sub_img_id = part_info.anim_frame_info[frame_info_index]
            # Note: If the item is positive, flip does not affect
            #     the x, y coordinates.
            ## pos_x = puzzle_part.pos_x + part_info.shift_x + shift_x
            ## pos_y = puzzle_part.pos_y + part_info.shift_y + shift_y
            flip_axis_x = None
            flip_axis_y = None

        part_layer = layer_for_part(puzzle_part) if layer is None else layer

        return nt_graphics_info_t1(
            part_layer, file_name, sub_img_id, None,
            puzzle_part.pos_x + part_info.shift_x + shift_x - t1_shift_all_x,
            puzzle_part.pos_y + part_info.shift_y + shift_y - t1_shift_all_y,
            flip, flip_axis_x, flip_axis_y)

    def get_image_load_info(self, puzzle_part):
        '''
        Re-implementation of get_image_load_info from PartGraphicsInfoBase.
        Returns list/tuple of nt_graphics_info_t1 .
        '''
        # NOTE: By default, get_frame_images_info simply returns the same data
        #     as get_frame_images_info. However, if the part graphics contains
        #     "extra" (not from sprites) bitmaps, this function needs to
        #     be reimplemented
        return self.get_frame_images_info(puzzle_part)

    def get_frame_images_info(self, puzzle_part):
        '''
        Re-implementation of get_frame_images_info from PartGraphicsInfoBase.
        Returns tuple (1-membered) of nt_graphics_info_t1.
        '''
        # By default, one item, frame_info_index == 0 and flip == flip_none
        return (self.get_graphics_info_default(puzzle_part, 0, flip_none, 0,
                                               0), )


# IMPORTANT NOTE: Field names starting with "temp_" in namedtuples
#     from puzzle decoder may change in later versions of the program.

# t1_filp_horiz_bit, t1_filp_vert_bit: see PartGraphicsInfo_T1_Flip
t1_filp_horiz_bit = 0x10
t1_filp_vert_bit = 0x20


class PartGraphicsInfo_T1_Flip(PartGraphicsInfo_T1_Simple):
    '''
    PartGraphicsInfo_T1_Simple subclass that support horizontal or vertical
        flipping. The same images are used for both position, but they will
        by flipped along x/y axis in one of the two positions.
    The flip information is stored in flags_2, 0x10 means horizontal,
        0x20 means vertical flipping.
    '''

    # flip_bit: Which bit to check in flags_2 to see whether
    #     the part is flipped. Must be modified in sub_class.
    flip_bit = 0
    # flip_direction: One of flip_* constants, Must be modified in sub_class.
    flip_direction = 0
    # flip_texts_default: 2-element tuple containing the text displayed
    #     for the "original" and the "flipped" position.
    flip_texts_default = ('original', 'flipped')

    def get_frame_images_info(self, puzzle_part):
        '''
        Re-implementation of get_frame_images_info from
            PartGraphicsInfo_T1_Simple.
        Returns tuple (1-membered) of nt_graphics_info_t1.
        '''
        return (self.get_graphics_info_default(
            puzzle_part, 0, (self.flip_direction if puzzle_part.flags_2
                             & self.flip_bit else flip_none), 0, 0), )

    def get_part_specific_info(self, puzzle_part):
        '''
        Re-implementation of get_part_specific_info from
            PartGraphicsInfo_T1_Simple. See meaning of argument there.
        '''

        flip_texts = self.flip_texts_default

        puzzle_info_obj = self.puzzle_graph_info.puzzle_info_obj
        part_appearance_texts = puzzle_info_obj.get_part_appearance_texts(
            puzzle_part.part_num)

        if part_appearance_texts is not None:
            if part_appearance_texts.flip_texts is not None:
                flip_texts = part_appearance_texts.flip_texts

        flip_pos = bool(puzzle_part.flags_2 & self.flip_bit)
        return 'orientation: %s (%d)' % (flip_texts[flip_pos], flip_pos)


class PartGraphicsInfo_T1_FlipHoriz(PartGraphicsInfo_T1_Flip):
    '''
    PartGraphicsInfo_T1_Flip subclass, supporting horizontal flip
    '''
    # Fields modified from parent class
    flip_bit = t1_filp_horiz_bit
    flip_direction = flip_horizontal


class PartGraphicsInfo_T1_FlipVert(PartGraphicsInfo_T1_Flip):
    '''
    PartGraphicsInfo_T1_Flip subclass, supporting vertical flip
    '''
    # Note: only used for one part, the "eye hook"
    # Fields modified from parent class
    flip_bit = t1_filp_vert_bit
    flip_direction = flip_vertical


str_err_t1_sub_img_id = 'Part %d, field "appearance" has an invalid value %d'
t1_sub_image_text_default = 'sub-image'


class PartGraphicsInfo_T1_SubImageID(PartGraphicsInfo_T1_Simple):
    '''
    PartGraphicsInfo_T1_Simple subclass that support parts that use different
         graphics depending on the value of one field in puzzle data.
    appearance is the field used.
    '''

    def get_part_frame_id(self, puzzle_part):
        '''
        Internal function, returns an index in anim_frame_info tuple in the
            corresponding part_info namedtuple.
        puzzle_part: The "raw" information for the current part from the
            information returned by the level decoder. A namedtuple subclass,
            see d_puzzle.py
        '''
        # TODO, part info is retrieved twice
        part_info = self.puzzle_graph_info.puzzle_info_obj.get_part_info(
            puzzle_part.part_num)

        frame_number = puzzle_part.appearance

        if any(x < 0 for x in part_info.anim_frame_info):
            if ((frame_number < 0)
                    or (frame_number >= len(part_info.anim_frame_info))):
                raise RuntimeError(str_err_t1_sub_img_id %
                                   (puzzle_part.part_num, frame_number))

            return frame_number
        else:
            # Treat it as a sub-image index, but check first if it is present in
            #     the anim_frame_info tuple

            if frame_number not in part_info.anim_frame_info:
                raise RuntimeError(str_err_t1_sub_img_id %
                                   (puzzle_part.part_num, frame_number))

            return part_info.anim_frame_info.index(frame_number)

    def get_frame_images_info(self, puzzle_part):
        '''
        Re-implementation of get_frame_images_info from
            PartGraphicsInfo_T1_Simple.
        Returns tuple (1-membered) of nt_graphics_info_t1.
        '''
        return (self.get_graphics_info_default(
            puzzle_part, self.get_part_frame_id(puzzle_part), flip_none, 0,
            0), )

    def get_part_specific_info(self, puzzle_part):
        '''
        Re-implementation of get_part_specific_info from
            PartGraphicsInfo_T1_Simple. See meaning of argument there.
        '''
        # TODD, range check
        # NOTE: check in get_frame_images_info not done again
        frame_number = puzzle_part.appearance
        img_text = t1_sub_image_text_default

        puzzle_info_obj = self.puzzle_graph_info.puzzle_info_obj
        part_appearance_texts = puzzle_info_obj.get_part_appearance_texts(
            puzzle_part.part_num)

        if part_appearance_texts is not None:
            if part_appearance_texts.appearance_texts is not None:
                img_text = part_appearance_texts.appearance_texts[
                    self.get_part_frame_id(puzzle_part)]

        return 'appearance: %s (%d)' % (img_text, frame_number)


t1_slope_height = 32
t1_slope_direction = ('top-down', 'bottom-up')
str_warn_t1_slope_params = ('WARNING: Slope with invalid parameters found, '
                            'part will not be shown.')


class PartGraphicsInfo_T1_Slope(PartGraphicsInfo_T1_SubImageID):
    '''
    A subclass of PartGraphicsInfo_T1_SubImageID used for slopes that
        additionally supports horizontal flipping
    '''

    def __init__(self, part_num):
        '''
        The constructor of the class. Optional argument of parent class
            not valid in this subclass
        '''
        PartGraphicsInfo_T1_SubImageID.__init__(self, part_num)

    def get_frame_images_info(self, puzzle_part):
        '''
        Re-implementation of get_frame_images_info from
            PartGraphicsInfo_T1_SubImageID.
        '''
        frame_number = puzzle_part.appearance

        if ((puzzle_part.width_1 != puzzle_part.width_2)
                or (puzzle_part.height_1 != puzzle_part.height_2)
                or (puzzle_part.height_1 != t1_slope_height)
                or (puzzle_part.width_1 != ((frame_number + 1) << 4))):
            print_msg(str_warn_t1_slope_params)
            return ()

        return (self.get_graphics_info_default(
            puzzle_part, self.get_part_frame_id(puzzle_part),
            (flip_horizontal if puzzle_part.flags_2 & t1_filp_horiz_bit else
             flip_none), 0, 0), )

    def get_part_specific_info(self, puzzle_part):
        '''
        Re-implementation of get_part_specific_info from
            PartGraphicsInfo_T1_Simple. See meaning of argument there.
        '''
        flip_pos = bool(puzzle_part.flags_2 & t1_filp_horiz_bit)

        return (
            'direction_r_to_l: %s (%d) size: %d' %
            (t1_slope_direction[flip_pos], flip_pos, puzzle_part.appearance))


# Size of one tile (width for horizontal, height for vertical)
#     in a TIM/TEMIM wall
t1_wall_tile_size = 16
str_warn_t1_wall_params = ('WARNING: Wall with invalid parameters found, '
                           'part will not be shown.')


class PartGraphicsInfo_T1_Wall(PartGraphicsInfo_T1_Simple):
    '''
    PartGraphicsInfo_T1_Simple subclass for walls. Walls can be
        either horizontal or vertical depending on "width" and height
    There are 3 types of walls in TIM and 4 in TEMIM, which are treated
        in exactly the same way with the exception of the used sprites.
    '''

    # Note: All wall bitmap files in TIM/TEMIM have 8 sub images, in
    #     the following arrangement: 0: Horizontal, left end;
    #     1: H, center 1; 2: H, center 2; 3: H, right end
    #     4: Vertical, top; 5: V, center 1; 6: V, center 2;
    #     7: V, bottom

    # TODO: get_image_load_info could be re-implemented for optimization

    def get_frame_images_info(self, puzzle_part):
        '''
        Re-implementation of get_frame_images_info from
            PartGraphicsInfo_T1_Simple.
        '''
        if not wall_coords_check(puzzle_part, wall_part_thickness):
            return ()

        if puzzle_part.height_1 == wall_part_thickness:
            # Horizontal wall
            # Note: For horizontal walls, it depends on the absolute X
            #     position the wall whether "center element 1" or
            #     "center element 2" comes first
            item_center_add = ((puzzle_part.pos_x + 8) >> 4) + 1

            wall_length = puzzle_part.width_1 >> 4
            incr_x = t1_wall_tile_size
            incr_y = 0
            first_sub_img = 0
        elif puzzle_part.width_1 == wall_part_thickness:
            # Vertical wall
            # Note: For vertical walls, the absolute Y position on the screen
            #     determines whether  "center element 1" or "center element 2"
            #     must be drawn first
            item_center_add = ((puzzle_part.pos_y + 8) >> 4) + 1

            # HACK for vertical brick wall in TEMIM Title Screen
            if (self.puzzle_graph_info.get_game_version() ==
                    game_ver_tim_special):
                item_center_add -= 1

            wall_length = puzzle_part.height_1 >> 4
            incr_x = 0
            incr_y = t1_wall_tile_size
            first_sub_img = 4
        else:
            # This should never happen, wall_coords_check should have failed
            return ()

        # Note: For optimization, this method does not call
        #     get_graphics_info_default. This means that several fields in
        #     part info, including x/y offset, will be ignored even if not 0.

        part_info = self.puzzle_graph_info.puzzle_info_obj.get_part_info(
            puzzle_part.part_num)

        # Check whether part_info contains correct data for wall
        #     (TODO, not absolutely necessary
        if len(part_info.anim_frame_info) != 8:
            # TODO, better error
            raise RuntimeError('Bug: invalid data stored for wall')

        pos_x = puzzle_part.pos_x - t1_shift_all_x
        pos_y = puzzle_part.pos_y - t1_shift_all_y
        file_name = name_pattern_res_part % puzzle_part.part_num
        layer = layer_for_part(puzzle_part)

        wall_tiles = [
            nt_graphics_info_t1(layer, file_name, first_sub_img, None, pos_x,
                                pos_y, flip_none, 0, 0)
        ]

        for item_center in xrange(wall_length - 2):
            pos_x += incr_x
            pos_y += incr_y
            wall_tiles.append(
                nt_graphics_info_t1(
                    layer, file_name,
                    first_sub_img + 1 + ((item_center + item_center_add) & 1),
                    None, pos_x, pos_y, flip_none, 0, 0))

        if wall_length > 1:
            pos_x += incr_x
            pos_y += incr_y

            wall_tiles.append(
                nt_graphics_info_t1(layer, file_name, first_sub_img + 3, None,
                                    pos_x, pos_y, flip_none, 0, 0))

        return tuple(wall_tiles)

    # Note: currently get_part_specific_info is not re-implemented,
    #     only x, y, width, height will be shown


# For "electric outlet with switch
t1_num_frames_outlet_switch = 8
str_t1_outlet_switch = ('up', 'down')
t1_outlet_switch_bit = 0x4

str_warn_t1_outlet_frame = (
    'Warning: Unexpected "appearance" value %d found for "electric outlet" '
    'part type %d, using 0 instead.')


class PartGraphicsInfo_T1_ElectricOutlet(PartGraphicsInfo_T1_Simple,
                                         PartGraphicsInfElectricOutletMixin):
    '''
    PartGraphicsInfo_T1_Simple subclass for electric outlets. These parts can
        be treated similarly to PartGraphicsInfo_T1_SubImageID, because field
        appearance always contains valid information about the 'appearance"
        of the part. However, there is an important difference: If parts are
        connected to the outlet which are placed initially into the parts
        bin, the "plug" for these parts should not appear.
    '''

    def get_frame_images_info(self, puzzle_part):
        '''
        Re-implementation of get_frame_images_info from
            PartGraphicsInfo_T1_Simple.
        '''

        part_info = self.puzzle_graph_info.puzzle_info_obj.get_part_info(
            puzzle_part.part_num)

        # NOTE: This was copied from PartGraphicsInfo_T1_SubImageID

        frame_number = puzzle_part.appearance

        # FIXME, hack for the "generator" part in some puzzles
        if (frame_number == 4) and (len(part_info.anim_frame_info) == 4):
            print_msg(str_warn_t1_outlet_frame %
                      (frame_number, puzzle_part.part_num))
            frame_number = 0

        if ((frame_number < 0)
                or (frame_number >= len(part_info.anim_frame_info))):
            raise RuntimeError(
                str_err_t1_sub_img_id % (puzzle_part.part_num, frame_number))

        # NOTE: connected_3 and connected_4 is missing from PartInfoT1Demo
        #    however, it also does not support electric outlets so an
        #    exception in the following code is extremely unlikely, but
        #    make sure.
        if self.puzzle_graph_info.get_game_version() == game_ver_tim_demo:
            return ()

        # Note: frame_info_index can also be interpreted as a flag parameter
        #     with three bit flags, bit 0 is 1 when a plug is shown in the
        #     upper position, bit 1 is 1 when a plug is shown in the other
        #     position, while bit 2 is only used for the outlet with
        #     switch and corresponds to the position of the switch.

        # get_electric_outlet_appearance check whether the connected parts
        #     are placed to the parts bin and clears the corresponding bits
        # Can also set the bits if frame_number is 0 but it should not

        frame_info_index = self.get_electric_outlet_appearance(
            puzzle_part, frame_number)

        # When one or both parts are placed to the parts bin, actually
        #     two electric outlets will be shown in two different layers.
        # If puzzle_layer_parts_bin_parts is visible in the selected
        #     sub-item of the puzzle viewer, the outlet placed into
        #     the parts bin layer will cover the other outlet.

        if frame_info_index == frame_number:
            return (self.get_graphics_info_default(puzzle_part,
                                                   frame_info_index, flip_none,
                                                   0, 0), )
        else:
            return (self.get_graphics_info_default(puzzle_part,
                                                   frame_info_index, flip_none,
                                                   0, 0,
                                                   puzzle_layer_fixed_parts),
                    self.get_graphics_info_default(
                        puzzle_part, frame_number, flip_none, 0, 0,
                        puzzle_layer_parts_bin_parts))

    def get_part_specific_info(self, puzzle_part):
        '''
        Re-implementation of get_part_specific_info from
            PartGraphicsInfo_T1_Simple. See meaning of argument there.
        '''
        part_info = self.puzzle_graph_info.puzzle_info_obj.get_part_info(
            puzzle_part.part_num)
        frame_number = puzzle_part.appearance

        # Outlet with switch has t1_num_frames_outlet_switch anim. frames
        if len(part_info.anim_frame_info) == t1_num_frames_outlet_switch:
            out_info = [
                'switch: %s' %
                str_t1_outlet_switch[bool(frame_number & t1_outlet_switch_bit)]
            ]
        else:
            out_info = []

        # see comment in get_frame_images_info
        if self.puzzle_graph_info.get_game_version() == game_ver_tim_demo:
            return ''

        connected_1 = puzzle_part.connected_3
        connected_2 = puzzle_part.connected_4

        if connected_1 >= 0:
            out_info.append('connected_part_1: %d' % connected_1)

        if connected_2 >= 0:
            out_info.append('connected_part_2: %d' % connected_2)

        return ' '.join(out_info)


# Black color for belt
t1_color_belt = 5


class PartGraphicsInfo_T1_Belt(PartGraphicsInfo_T1_Simple):
    '''
    PartGraphicsInfo_T1_Simple subclass for belts. Belts connect two
        "rotating" parts. Belts in TIM/TEMIM are represented using two,
        1 pixel wide black lines.
    '''

    def get_image_load_info(self, puzzle_part):
        '''
        Re-implementation of get_image_load_info from PartGraphicsInfoBase.
        Returns list/tuple of nt_graphics_info_t1 .
        '''
        # Returns empty tuple as no image from game resource files is needed
        return ()

    def get_frame_images_info(self, puzzle_part):
        '''
        Re-implementation of get_frame_images_info from PartGraphicsInfoBase.
        Returns tuple of two nt_graphics_info_t1 entries coorresponding to two
            black lines or an empty tuple if the belt is not visible.
        '''
        # NOTE: Belts in TIM 1/TEMIM are represented by two black, usually not
        #     exactly parallel lines. These lines are drawn between the
        #     separate "belt binding" areas inside the two parts. This "area"
        #     is always  easily recognizable in the part graphics and has
        #     "circular" shape.
        #     The two "segments" of the belt start at either 0 deg and 180 deg
        #     (-> horizontal position) in a polar coordinate system centered
        #     at this "circular area" or at 90 deg and 270 deg
        #     (-> vertical position). The horizontal/vertical positioning
        #     depends on the slope of one of the two lines (see code below).
        # NOTE: belt_info_1 for a part is actually two 1-byte values, not
        #     a 16-bit int. It corresponds to the (x, y) coordinates of top
        #     left corner of the bounding rectangle around the aforementioned
        #     circular area. belt_info_2 is approximately the diameter of this
        #     circle (or alternatively, the sides of the bounding square.)

        index_part_1 = puzzle_part.belt_index_connected_1
        index_part_2 = puzzle_part.belt_index_connected_2

        # When at least one index is not valid (-1), return

        if (index_part_1 < 0) or (index_part_2 < 0):
            return ()

        part_connected_1 = self.puzzle_graph_info.get_part(index_part_1)
        part_connected_2 = self.puzzle_graph_info.get_part(index_part_2)
        part_1_conn_x, part_1_conn_y = int_16_to_2_bytes(
            part_connected_1.belt_info_1)
        # TODO, check for odd number
        part_1_belt_line_dist = part_connected_1.belt_info_2
        part_1_belt_line_halfd = part_1_belt_line_dist >> 1
        part_2_conn_x, part_2_conn_y = int_16_to_2_bytes(
            part_connected_2.belt_info_1)
        part_2_belt_line_dist = part_connected_2.belt_info_2
        part_2_belt_line_halfd = part_2_belt_line_dist >> 1

        part_1_conn_pos_x = part_1_conn_x + part_connected_1.pos_x
        part_1_conn_pos_y = part_1_conn_y + part_connected_1.pos_y
        part_2_conn_pos_x = part_2_conn_x + part_connected_2.pos_x
        part_2_conn_pos_y = part_2_conn_y + part_connected_2.pos_y

        # NOTE: According to my tests, the game seems to calculate
        #     the distance between part_1_conn_pos_x/y and
        #     part_2_conn_pos_x/y to determine if the position of the two
        #     lines should be "horizontal" or "vertical"
        # TODO, more precise tests needed to decide if
        #     < or <= should be used

        if (abs(part_2_conn_pos_x - part_1_conn_pos_x) <=
                abs(part_2_conn_pos_y - part_1_conn_pos_y)):
            line_1_pos_x = min(part_1_conn_pos_x, part_2_conn_pos_x)
            line_1_pos_y = (min(part_1_conn_pos_y, part_2_conn_pos_y) +
                            part_1_belt_line_halfd)
            line_2_pos_x = min(part_2_conn_pos_x + part_2_belt_line_dist,
                               part_1_conn_pos_x + part_1_belt_line_dist)
            line_2_pos_y = line_1_pos_y

            line_2_pos_dir_x = ((part_2_conn_pos_x + part_2_belt_line_dist) -
                                (part_1_conn_pos_x + part_1_belt_line_dist))
            line_2_pos_dir_y = part_2_conn_pos_y - part_1_conn_pos_y

        else:
            line_1_pos_x = (min(part_1_conn_pos_x, part_2_conn_pos_x) +
                            part_1_belt_line_halfd)
            line_1_pos_y = min(part_1_conn_pos_y, part_2_conn_pos_y)
            line_2_pos_x = line_1_pos_x
            line_2_pos_y = min(part_2_conn_pos_y + part_2_belt_line_dist,
                               part_1_conn_pos_y + part_1_belt_line_dist)

            line_2_pos_dir_x = part_2_conn_pos_x - part_1_conn_pos_x
            line_2_pos_dir_y = ((part_2_conn_pos_y + part_2_belt_line_dist) -
                                (part_1_conn_pos_y + part_1_belt_line_dist))

        line_1_pos_dir_x = part_2_conn_pos_x - part_1_conn_pos_x
        line_1_pos_dir_y = part_2_conn_pos_y - part_1_conn_pos_y

        line_obj_1 = self.puzzle_graph_info.png_shape_draw.draw_line(
            line_1_pos_dir_x, line_1_pos_dir_y, t1_color_belt, flip_none)
        line_obj_2 = self.puzzle_graph_info.png_shape_draw.draw_line(
            line_2_pos_dir_x, line_2_pos_dir_y, t1_color_belt, flip_none)

        if part_connected_1.in_partsbin or part_connected_2.in_partsbin:
            layer = puzzle_layer_foreground_parts_bin
        else:
            layer = layer_for_part(puzzle_part)

        return (
            nt_graphics_info_t1(layer, None, None, line_obj_1,
                                line_1_pos_x - t1_shift_all_x,
                                line_1_pos_y - t1_shift_all_y, flip_none, 0,
                                0),
            nt_graphics_info_t1(layer, None, None, line_obj_2,
                                line_2_pos_x - t1_shift_all_x,
                                line_2_pos_y - t1_shift_all_y, flip_none, 0,
                                0),
        )

    def get_part_specific_info(self, puzzle_part):
        '''
        Re-implementation of get_part_specific_info from
            PartGraphicsInfo_T1_Simple. See meaning of argument there.
        '''
        # TODO, more information
        index_part_1 = puzzle_part.belt_index_connected_1
        index_part_2 = puzzle_part.belt_index_connected_2

        out_info = []

        if index_part_1 >= 0:
            out_info.append('connected_part_1: %d' % index_part_1)

        if index_part_2 >= 0:
            out_info.append('connected_part_2: %d' % index_part_2)

        return ' '.join(out_info)


str_error_t1_rope_graphics = (
    'Unfortunately, the game version you opened '
    'does not\ncontain the graphics for "rope ends" in a supported file '
    'format.\nSee the dirinfo.txt file in timgres/files subdirectory for '
    'the\nsteps required before opeing level files in TIM versions before '
    'TEMIM.')

# Dark yellow color for rope
t1_color_rope = 6

# Needed for correct positioning of the "knot at rope end" graphics.
#   This information is not present in the puzzle file.
t1_knot_graph_pos_rel_x = -5
t1_knot_graph_pos_rel_y = -2

# Use image 0 for "knot at rope end" graphics
rope_knot_sub_img = 0


class PartGraphicsInfo_T1_Rope(PartGraphicsInfo_T1_Simple,
                               PartGraphicsInfoRopeMixin):
    '''
    PartGraphicsInfo_T1_Simple subclass for ropes. ...
    '''

    def get_rope_image_file_name(self):
        '''
        Function for internal use. Returns the full name to use for the "rope end"
            grpahics file, depending on whether this file was extracted to a
            local directory. Returns a resource file name (str).
        '''
        # NOTE: This is a temporary solution as TIM 1 does not have an image
        #    in the resource file for the "rope end" graphics it and it is
        #    currently not known how/where this version stores the bitmap.

        # TODO, uses "parent" field directly
        res_read_obj = self.puzzle_graph_info.parent.get_res_read_obj()

        if res_read_obj.contains_file_nofilter(stored_file_name_rope):
            # If _ROPEEND.BMP exists in the local storage directory
            #     return it
            return stored_file_name_rope
        else:
            # Although the program will show an error message when the rope
            #     end graphics file does not exist in the resource file of
            #     the game, an additional check is performed here so that
            #     a much more helpful message can be shown to the user.
            name_in_res_file = name_pattern_res_part % self.part_num

            if not res_read_obj.contains_file_nofilter(name_in_res_file):
                raise RuntimeError(str_error_t1_rope_graphics)

            return name_in_res_file

    def get_image_load_info(self, puzzle_part):
        '''
        Re-implementation of get_image_load_info from PartGraphicsInfoBase.
        Returns list/tuple of nt_graphics_info_t1.
        '''
        # Return the "knot at rope end" graphics but only if it is not
        #     stored in the "extra" subdirectory.
        index_part_1 = puzzle_part.rope_index_connected_1
        index_part_2 = puzzle_part.rope_index_connected_2

        if (index_part_1 >= 0) or (index_part_2 >= 0):
            # TODO, in some cases, the rope is not actually shown
            return (nt_graphics_info_t1(self.get_rope_layer(puzzle_part),
                                        self.get_rope_image_file_name(),
                                        rope_knot_sub_img, None, 0, 0,
                                        flip_none, 0, 0), )
        else:
            return ()

    def get_frame_images_info(self, puzzle_part):
        '''
        Re-implementation of get_frame_images_info from PartGraphicsInfoBase.
        TODO, add description
        Returns tuple (1-membered) of nt_graphics_info_t1.
        '''
        rope_segments = self.get_rope_segments_list(puzzle_part)

        if not rope_segments:
            return ()

        # "Knot at rope end" graphics, see comment at get_rope_image_file_name
        file_name = self.get_rope_image_file_name()
        layer = self.get_rope_layer(puzzle_part)

        pos_start_x = rope_segments[0].start_x
        pos_start_y = rope_segments[0].start_y
        pos_last_x = rope_segments[-1].end_x
        pos_last_y = rope_segments[-1].end_y

        frame_images = [
            nt_graphics_info_t1(
                layer, file_name, rope_knot_sub_img, None,
                pos_start_x + t1_knot_graph_pos_rel_x - t1_shift_all_x,
                pos_start_y + t1_knot_graph_pos_rel_y - t1_shift_all_y,
                flip_none, 0, 0),
            nt_graphics_info_t1(
                layer, file_name, rope_knot_sub_img, None,
                pos_last_x + t1_knot_graph_pos_rel_x - t1_shift_all_x,
                pos_last_y + t1_knot_graph_pos_rel_y - t1_shift_all_y,
                flip_none, 0, 0)
        ]

        for segment in rope_segments:
            line_pos_x = min(segment.start_x, segment.end_x)
            line_pos_y = min(segment.start_y, segment.end_y)

            line_obj = self.puzzle_graph_info.png_shape_draw.draw_line(
                segment.end_x - segment.start_x,
                segment.end_y - segment.start_y, t1_color_rope, flip_none)

            frame_images.append(
                nt_graphics_info_t1(layer, None, None, line_obj,
                                    line_pos_x - t1_shift_all_x,
                                    line_pos_y - t1_shift_all_y, flip_none, 0,
                                    0), )

        return tuple(frame_images)

    def get_part_specific_info(self, puzzle_part):
        '''
        Re-implementation of get_part_specific_info from
            PartGraphicsInfo_T1_Simple. See meaning of argument there.
        '''
        return self.get_rope_info_str(puzzle_part)


class PartGraphicsInfo_T1_Gear(PartGraphicsInfo_T1_Simple):
    '''
    PartGraphicsInfo_T1_SubImageID subclass for gears.
    '''

    def get_part_specific_info(self, puzzle_part):
        '''
        Re-implementation of get_part_specific_info from
            PartGraphicsInfo_T1_Simple. See meaning of argument there.
        '''
        # TODO, more reverse engineering work is needed. Gears seem to use
        #     connected_1 and connected_2 for part numbers of gears
        #     immediately on the left and the right side, respectively.
        #     Apparently, Horizontal "neighbors" (above/below) are never
        #     stored in this field. There seems to be no difference
        #     between TIM/TEMIM and TIM2/TIM3.

        out_info = []  # Fixme, duplication, from belt

        if puzzle_part.connected_1 >= 0:
            out_info.append('connected_part_1: %d' % puzzle_part.connected_1)

        if puzzle_part.connected_2 >= 0:
            out_info.append('connected_part_2: %d' % puzzle_part.connected_2)

        return ' '.join(out_info)


class PuzzleGraphicsInfo_T1(PuzzleGraphicsInfoBase):
    '''
    PuzzleGraphicsInfoBase subclass for TIM/TEMIM puzzles (including saved
          "freeform machines" and the GKC (intro/credits screen) files. ...
    '''
    # NOTE PuzzleGraphicsInfoT1 is used for both TIM 1 demo, TIM 1 and TEMIM

    # Supported game versions, modified from parent class
    supported_verisons = (game_ver_tim_demo, game_ver_tim, game_ver_temim,
                          game_ver_tim_special)

    # The identifier of associated PuzzleInfoT1 object
    puzzle_info_obj_name = s_obj_puzzleinfov1

    # puzzle_screen_size: Size of puzzle screen in the supported game versions
    puzzle_screen_size = nt_size(576, 368)

    # Different screen size must be used for game_ver_tim_special file
    puzzle_screen_size_special = nt_size(640, 400)

    # The default part type class is PartGraphicsInfo_T1_Simple
    part_object_default_type = PartGraphicsInfo_T1_Simple

    # Part types that require special treatment using
    #     PartGraphicsInfo_T1_Simple subclasses. Format: See puzgraph.py

    part_object_types = (
        (1, PartGraphicsInfo_T1_Wall),
        (2, PartGraphicsInfo_T1_Slope),
        (3, PartGraphicsInfo_T1_SubImageID),
        (5, PartGraphicsInfo_T1_SubImageID),
        (6, PartGraphicsInfo_T1_FlipHoriz),
        (7, PartGraphicsInfo_T1_SubImageID),
        (8, PartGraphicsInfo_T1_Belt),
        (10, PartGraphicsInfo_T1_Rope),
        (12, PartGraphicsInfo_T1_FlipHoriz),
        (13, PartGraphicsInfo_T1_FlipHoriz),
        (14, PartGraphicsInfo_T1_Gear),
        (16, PartGraphicsInfo_T1_FlipHoriz),
        (18, PartGraphicsInfo_T1_FlipHoriz),
        (19, PartGraphicsInfo_T1_FlipHoriz),
        (21, PartGraphicsInfo_T1_ElectricOutlet),
        (22, PartGraphicsInfo_T1_FlipHoriz),
        (23, PartGraphicsInfo_T1_FlipVert),
        (24, PartGraphicsInfo_T1_FlipHoriz),
        (25, PartGraphicsInfo_T1_FlipHoriz),
        (26, PartGraphicsInfo_T1_ElectricOutlet),
        (27, PartGraphicsInfo_T1_FlipHoriz),
        (29, PartGraphicsInfo_T1_SubImageID),
        (30, PartGraphicsInfo_T1_FlipHoriz),
        (31, PartGraphicsInfo_T1_FlipHoriz),
        (35, PartGraphicsInfo_T1_FlipHoriz),
        (36, PartGraphicsInfo_T1_FlipHoriz),
        (38, PartGraphicsInfo_T1_ElectricOutlet),
        (37, PartGraphicsInfo_T1_FlipHoriz),
        (40, PartGraphicsInfo_T1_FlipHoriz),
        (42, PartGraphicsInfo_T1_FlipHoriz),
        (46, PartGraphicsInfo_T1_Wall),
        (47, PartGraphicsInfo_T1_SubImageID),
        (48, PartGraphicsInfo_T1_Wall),
        (50, PartGraphicsInfo_T1_FlipHoriz),
        (51, PartGraphicsInfo_T1_FlipHoriz),
        (54, PartGraphicsInfo_T1_FlipHoriz),
        (55, PartGraphicsInfo_T1_SubImageID),
        (56, PartGraphicsInfo_T1_SubImageID),
        (57, PartGraphicsInfo_T1_SubImageID),
        (60, PartGraphicsInfo_T1_Wall),
        (61, PartGraphicsInfo_T1_FlipHoriz),
        (62, PartGraphicsInfo_T1_FlipHoriz),
    )

    def get_puzzle_screen_size(self):
        '''
        Re-implementation of get_puzzle_screen_size from
            PuzzleGraphicsInfoBase, takes into account the different screen
            size used by game_ver_tim_special puzzles
        Return type: nt_size
        '''
        return (self.puzzle_screen_size_special if self.puzzle_data.game_ver
                == game_ver_tim_special else self.puzzle_screen_size)

    def get_background_fill_image(self):
        '''
        Re-implementation of get_part_obj_by_number from
            PuzzleGraphicsInfoBase.
        '''
        rect_width, rect_height = self.get_puzzle_screen_size()

        return nt_graphics_info_t1(
            puzzle_layer_background, None, None,
            self.png_shape_draw.draw_rectangle_with_border(
                rect_width, rect_height, background_color_t1,
                background_color_t1), 0, 0, flip_none, None, None)
