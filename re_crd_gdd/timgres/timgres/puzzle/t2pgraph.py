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
from timgres.base.misc import (
    print_msg,
    game_text_encoding,
    s_obj_puzzleinfov2,
    s_obj_pngexp16,
    s_obj_pngexp256,
    s_obj_pngmerge16,
    s_obj_pngmerge256,
    s_opt_zoom,
    s_opt_flip,
)
from timgres.base.vdobase import (nt_size, flip_none, flip_vertical,
                                  flip_horizontal, nt_image_display_data)
from timgres.base.bmpdbase import (_rep_nibbles_even_odd, nt_bm_sub_img_data,
                                   nt_process_options_bm)
from timgres.base.pngdraw import _make_png_data_flip
from timgres.puzzle.anmview import name_pattern_res_part, name_pattern_res_anm
from timgres.puzzle.puzdata import game_ver_tim2
from timgres.puzzle.puzgraph import (
    nt_field_layer_number, layer_for_part, PartGraphicsInfoBase,
    PuzzleGraphicsInfoBase, PartGraphicsInfoRopeMixin,
    PartGraphicsInfElectricOutletMixin, wall_part_thickness, wall_coords_check,
    PuzzleWallsInfo, puzzle_layer_background, puzzle_layer_scenery_background,
    puzzle_layer_scenery, puzzle_layer_fixed_parts, puzzle_layer_moving_parts,
    puzzle_layer_parts_bin_parts, puzzle_layer_foreground,
    puzzle_layer_foreground_parts_bin, nt_info_puzzle, int_16_to_2_bytes)
'''
This module contains PartGraphicsInfoBase and PuzzleGraphicsInfoBase
    subclasses required for viewing puzlle files from TIM 2 (and 3)
'''

# A few puzzles in TIM 2 (those with a "magic number" other than
#     puzzle_magic_num_t2_3, see decoder/d_puzuzle.py) contain no
#     background color information. In such cases, the background color is
#     color 3 (sky blue).
background_color_t2_default = 3

# Note: nt_graphics_info_t2 is currently almost identical to
#     nt_graphics_info_t1, the differences are:
# anm_frame_id field instead of sub_img_id; file_name is the name
#     of an .ANM file and None is never allowed
#     alternative_flip added

# Note that get_image_load_info and get_frame_images_info uses the
#     same namedtuple in PartGraphicsInfoT2

# layer_number: The number of layer the part belongs to. One
#     of the puzzle_layer_* constants. See puzgraph.py. (type: int)
# file_name: The name of animation file that contains the information about
#     the bitmap files and their sub-images required to show the sprite for
#     the part.  (type: str)
# anm_frame_id: An index of an "animation frame" in the animation file
#     corresponds to an index in the B section of the file. (type: int)
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

nt_graphics_info_t2 = namedtuple(
    'nt_graphics_info_t2', (nt_field_layer_number, 'file_name', 'anm_frame_id',
                            'extra_img', 'pos_rel_x', 'pos_rel_y', 'flip',
                            'flip_axis_x', 'flip_axis_y', 'alternative_flip'))

# nt_anim_frame_info_t2: contains the text that should be shown
#     on the "Information" panel for a part depending on its
#     "appearance": the text to be shown (str)
# anm_frame_num: the frame number associated with the "appearance" (int)
# appearance_text
nt_anim_frame_info_t2 = namedtuple('nt_anim_frame_info_t2',
                                   ('anm_frame_num', 'appearance_text'))

# Corresponds to t1_shift_all_* in t1pgraph.py, zero in case of TIM 2

t2_shift_all_x = 0
t2_shift_all_y = 0

# t1_filp_horiz_bit, t1_filp_vert_bit: bits in flags_2 to indicate flip
t2_filp_horiz_bit = 0x10
t2_filp_vert_bit = 0x20


def convert_part_flip_flags(part_flags_2):
    return (
        (flip_horizontal if part_flags_2 & t2_filp_horiz_bit else flip_none) |
        (flip_vertical if part_flags_2 & t2_filp_vert_bit else flip_none))


t2_flip_scenery_strs = ('none (0)', 'vertical (1)', 'horizontal (2)',
                        'vertical&horizontal (3)')


class PartGraphicsInfo_T2_Simple(PartGraphicsInfoBase):
    '''
    PartGraphicsInfoBase subclass for TIM 2 parts.
    '''
    # show_flip_info: If show_flip_info == True, "flip" information will
    #     be dusplayed on the "File info" for the part.
    show_flip_info = False
    # alternative_flip: Flip correction for some parts (bool)
    alternative_flip = False
    # flip_axis_x: Flip correction for parts for which alternative_flip
    #     does not work correctly. TODO, this might be a bug in the filpping
    #     code of the program or alternatively (more probably?), a genuine
    #     difference in how the game handles these parts (type: int or None)
    flip_axis_x = None
    # flip_axis_y: Similar to flip_axis_x, currently no part uses it
    flip_axis_y = None
    # flip_bit: t2_filp_horiz_bit or t2_filp_vert_bit, horizontal is the
    #     default because it is much more common (type: int)
    flip_bit = t2_filp_horiz_bit
    # flip_texts_default: 2-element tuple containing the text displayed
    #     for the "original" and the "flipped" position.
    flip_texts_default = ('original', 'flipped')

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
        frame_info_index: Either an animation frame index in the ANM file
            or an index in self.appearance_dict (type: int).
        flip: One of the flip_* constants (type: int).
        shift_x, shift_y: An optional shift along X and Y axes (type: int)
        layer: Specifying a puzzle_layer_* constant instead of None allows
            placing a part to a layer different from the default. (type: int)
        Returns nt_graphics_info_t2.
        '''

        part_layer = layer_for_part(puzzle_part) if layer is None else layer
        file_name = name_pattern_res_anm % puzzle_part.part_num

        return nt_graphics_info_t2(
            part_layer, file_name, frame_info_index, None,
            puzzle_part.pos_x + shift_x - t2_shift_all_x,
            puzzle_part.pos_y + shift_y - t2_shift_all_y, flip,
            self.flip_axis_x, self.flip_axis_y, self.alternative_flip)

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

        # TEMPORARY !
        if puzzle_part.part_num in (8, 10): return ()

        return (self.get_graphics_info_default(
            puzzle_part, puzzle_part.appearance,
            convert_part_flip_flags(puzzle_part.flags_2), 0, 0), )

    def get_part_specific_info(self, puzzle_part):
        '''
        Re-implementation of get_part_specific_info from
            PartGraphicsInfo_T1_Simple. See meaning of argument there.
        '''

        part_specific_texts = []

        if puzzle_part.is_scenery:
            part_specific_texts.append(
                'scenery_flip: %s' %
                (t2_flip_scenery_strs[convert_part_flip_flags(
                    puzzle_part.flags_2)]))

        puzzle_info_obj = self.puzzle_graph_info.puzzle_info_obj
        part_appearance_texts = puzzle_info_obj.get_part_appearance_texts(
            puzzle_part.part_num)

        if part_appearance_texts is None:
            return ' '.join(part_specific_texts)

        if part_appearance_texts.flip_texts is not None:
            flip_pos = bool(puzzle_part.flags_2 & self.flip_bit)

            part_specific_texts.append(
                'orientation: %s (%d)' %
                (part_appearance_texts.flip_texts[flip_pos], flip_pos))

        if part_appearance_texts.appearance_text_dict is not None:
            appearance_text = part_appearance_texts.appearance_text_dict.get(
                puzzle_part.appearance, '')

            part_specific_texts.append(
                'appearance: %s (%d)' %
                (appearance_text, puzzle_part.appearance))

        if part_appearance_texts.behavior_text_dict is not None:
            behavior_text = part_appearance_texts.behavior_text_dict.get(
                puzzle_part.behavior, '')

            part_specific_texts.append(
                'behavior: %s (%d)' % (behavior_text, puzzle_part.behavior))

        return ' '.join(part_specific_texts)

    def create_thick_line_items(self, pos_x, pos_y, pos_dir_x, pos_dir_y,
                                colors, layer):
        '''
        Function for internal use. Returns a tuple of 3 nt_graphics_info_t2
            items containing line graphics.
        pos_x, pos_y: x and y coordinates of the top left corner of the
            correponding rectoangle (int)
        pos_dir_x, pos_dir_y: see draw_line (base/pngdraw.py) (int)
        colors: tuple of 3 colors (ints)
        layer: One of puzzle_layer_* constants (int)
        '''

        if len(colors) != 3:
            raise ValueError(
                'create_thick_line_items: colors: must contain 3 ints')

        shape_draw = self.puzzle_graph_info.png_shape_draw

        if abs(pos_dir_x) < abs(pos_dir_y):
            return tuple(
                nt_graphics_info_t2(
                    layer, None, None,
                    shape_draw.draw_line(pos_dir_x, pos_dir_y, color,
                                         flip_none), pos_x + shift_x -
                    t2_shift_all_x, pos_y -
                    t2_shift_all_y, flip_none, 0, 0, False)
                for shift_x, color in enumerate(colors, -1))
        else:
            return tuple(
                nt_graphics_info_t2(
                    layer, None, None,
                    shape_draw.draw_line(pos_dir_x, pos_dir_y, color,
                                         flip_none), pos_x -
                    t2_shift_all_x, pos_y + shift_y -
                    t2_shift_all_y, flip_none, 0, 0, False)
                for shift_y, color in enumerate(colors, -1))


class PartGraphicsInfo_T2_VerticalFlip(PartGraphicsInfo_T2_Simple):
    '''
    PartGraphicsInfo_T2_Simple subclass for vertically flippable parts.
    '''
    flip_bit = t2_filp_vert_bit


# Note on "hack fixes" PartGraphicsInfo_T2_AlternativeFlip and
#     PartGraphicsInfo_T2_FlipAxisXCorrect: Several parts require correction
#     for horizontal flipping in TIM 2. Currently, two different approaches
#     are used. For some parts, one "hack" works and the other does not and
#     vice versa. Currently, I have no idea whether this is due to a bug
#     in the flipping code of the puzzle viewer or this corresponds to a real
#     difference in the treatment of some parts by the game. In general,
#     "AlternativeFlip" parts typically use the "appearance" field and thus
#     the flipping depends on the corresponding item in the .ANM file,
#     while "FlipAxisXCorrect" parts use t2_filp_horiz_bit in flags_2.

# Note that this is not a problem for TIM/TEMIM as in this case we have to use
#     a large number of manually determined parameters for sprites consisting
#     of multiple images. The correct axes for horizontal flipping is part of
#     this data set (stored in extra/t2pgraph.py)


class PartGraphicsInfo_T2_AlternativeFlip(PartGraphicsInfo_T2_Simple):
    '''
    PartGraphicsInfo_T2_Simple subclass, used for parts that require
        alternative_flip.
    '''
    # alternative_flip: See explanation in PartGraphicsInfo_T2_Simple
    alternative_flip = True


class PartGraphicsInfo_T2_FlipAxisXCorrect(PartGraphicsInfo_T2_Simple):
    '''
    PartGraphicsInfo_T2_Simple subclass, used for parts that require
        a "corrected" flip axis (flip_axis_x).
    '''

    def get_frame_images_info(self, puzzle_part):
        '''
        Re-implementation of puzzle_part from PartGraphicsInfo_T2_Simple.
        See meaning of argument threTODO
        '''
        # Note: get_image_load_info calls get_frame_images_info,
        #     so this is the func that needs to be re-implemented

        self.flip_axis_x = puzzle_part.width_2

        return PartGraphicsInfo_T2_Simple.get_frame_images_info(
            self, puzzle_part)


t2_slope_height = 32
t2_slope_direction = ('top-down', 'bottom-up')
str_warn_t2_slope_params = ('WARNING: Slope with invalid parameters found, '
                            'part will not be shown.')


class PartGraphicsInfo_T2_Slope(PartGraphicsInfo_T2_Simple):
    '''
    A subclass of PartGraphicsInfo_T2_Simple used for slopes. (TODO)
    '''

    # NOTE: PartGraphicsInfo_T2_Simple actually produces correct results
    #     for slopes with valid parameters, this class is only for performing
    #     extra checks and for the "file info" text

    def get_frame_images_info(self, puzzle_part):
        '''
        Re-implementation of get_frame_images_info from
            PartGraphicsInfo_T1_SubImageID.
        '''
        frame_number = puzzle_part.appearance

        if ((puzzle_part.width_1 != puzzle_part.width_2)
                or (puzzle_part.height_1 != puzzle_part.height_2)
                or (puzzle_part.height_1 != t2_slope_height)
                or (puzzle_part.width_1 != ((frame_number + 1) << 4))):
            print_msg(str_warn_t2_slope_params)
            return ()

        return PartGraphicsInfo_T2_Simple.get_frame_images_info(
            self, puzzle_part)

    def get_part_specific_info(self, puzzle_part):
        '''
        Re-implementation of get_part_specific_info from
            PartGraphicsInfo_T2_Simple. See meaning of argument there.
        '''
        # TODO, copied form puzzle.t1pgraph
        flip_pos = bool(puzzle_part.flags_2 & t2_filp_horiz_bit)

        return (
            'direction_r_to_l: %s (%d) size: %d' %
            (t2_slope_direction[flip_pos], flip_pos, puzzle_part.appearance))


# For "electric outlet with switch
t2_outlet_switch_bit = 0x4


class PartGraphicsInfo_T2_ElectricOutlet(PartGraphicsInfo_T2_Simple,
                                         PartGraphicsInfElectricOutletMixin):
    '''
    PartGraphicsInfo_T2_Simple subclass for electric outlets. These parts can
        be treated similarly to PartGraphicsInfo_T1_SubImageID, because field
        appearance always contains valid information about the 'appearance"
        of the part. However, there is an important difference: If parts are
        connected to the outlet which are placed initially into the parts
        bin, the "plug" for these parts should not appear. (TODO TODO)
    '''

    def get_electric_outlet_appearance_t2(self, puzzle_part):
        '''
        Function for internal use. In the parent class, calls
            get_electric_outlet_appearance with  puzzle_part.appearance
            as the second argument. May be re-implemented in subclasses.
            Returns int, like get_electric_outlet_appearance.
        puzzle_part: the namedtuple argument of get_frame_images_info
        '''
        return self.get_electric_outlet_appearance(puzzle_part,
                                                   puzzle_part.appearance)

    def get_appearance_text_dict_index(self, puzzle_part):
        '''
        Function for internal use. Returns the dictionary key to be used
            for appearance_text_dict fro puzzle-info_obj. This function
            should be called only when this dict is available. Returns int.
        puzzle_part: the namedtuple argument of get_frame_images_info
        '''
        # Not counting the PartGraphicsInfo_T2_LaserOutlet subclass, this is
        #     only relevant for part 21 (switchable outlet)
        return puzzle_part.appearance & t2_outlet_switch_bit

    def get_frame_images_info(self, puzzle_part):
        '''
        Re-implementation of get_frame_images_info from
            PartGraphicsInfo_T1_Simple.
        '''
        # TODO, duplicates PartGraphicsInfo_T1_ElectricOutlet to some extent
        frame_number = puzzle_part.appearance

        # Check whether the connected parts are placed to the parts bin
        #     and clear the corresponding bits. Can also set the bits
        #     if frame_number is 0 but it should not

        frame_info_index = self.get_electric_outlet_appearance_t2(puzzle_part)

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
        # Difference from PartGraphicsInfo_T1_ElectricOutlet: uses t2pinfo.py
        #     for switch state strings for the "switchable" outlet, not
        #     hardcoded strings

        puzzle_info_obj = self.puzzle_graph_info.puzzle_info_obj
        part_appearance_texts = puzzle_info_obj.get_part_appearance_texts(
            puzzle_part.part_num)

        out_info = []

        if part_appearance_texts is not None:
            if part_appearance_texts.appearance_text_dict is not None:
                switch_str = part_appearance_texts.appearance_text_dict.get(
                    self.get_appearance_text_dict_index(puzzle_part))

                if switch_str:
                    out_info = [
                        'appearance: %s (%d)' %
                        (switch_str, puzzle_part.appearance)
                    ]

        connected_1 = puzzle_part.connected_3
        connected_2 = puzzle_part.connected_4

        if connected_1 >= 0:
            out_info.append('connected_part_1: %d' % connected_1)

        if connected_2 >= 0:
            out_info.append('connected_part_2: %d' % connected_2)

        return ' '.join(out_info)


t2_laser_outlet_num_colors = 7


class PartGraphicsInfo_T2_LaserOutlet(PartGraphicsInfo_T2_ElectricOutlet):
    '''
    PartGraphicsInfo_T2_Simple subclass for laser-activates electric outlets.
        Re-implements get_electric_outlet_appearance_t2 and
        get_appearance_text_dict_index from the parent class to adapt to
        the numbering of .ANM frames for this part.
    '''

    def get_electric_outlet_appearance_t2(self, puzzle_part):
        '''
        Re-implementation of get_electric_outlet_appearance_t2 from
            PartGraphicsInfo_T2_ElectricOutlet.
        '''
        outlet_pluugs_temp, color = divmod(puzzle_part.appearance,
                                           t2_laser_outlet_num_colors)
        outlet_plugs = self.get_electric_outlet_appearance(
            puzzle_part, outlet_pluugs_temp)
        return outlet_plugs * t2_laser_outlet_num_colors + color

    def get_appearance_text_dict_index(self, puzzle_part):
        '''
        Re-implementation of get_appearance_text_dict_index from
            PartGraphicsInfo_T2_ElectricOutlet.
        '''
        return puzzle_part.appearance % t2_laser_outlet_num_colors


# Size of one tile (width for horizontal, height for vertical
#     in a TIM 3 wall
t2_wall_tile_size = 16

# nt_t2_wall_tile_info: Contains information on the number for
# wall tiles in a TIM 2 wall part. All members are ints.
# num_tiles_horizontal: number of tiles for horizontal wall
# num_tiles_vertical: number of tiles for vertical wall
# sect_b_items_tiles_join: Section B item namedtuples for  sprites used at
#     points where two walls are connected (see get_wall_join_graphics)

nt_t2_wall_tile_info = namedtuple(
    'nt_t2_wall_tile_info',
    ('num_tiles_horizontal', 'num_tiles_vertical', 'sect_b_items_tiles_join'))

str_err_wall_anm = 'Invalid value in wall animation file'


class PartGraphicsInfo_T2_WallPipe(PartGraphicsInfo_T2_Simple):
    '''
    PartGraphicsInfo_T2_Simple subclass for walls and similarly behaving
        parts. Walls can be either horizontal or vertical depending on "width" and height.
    Sub-classes are also used for the "large pipe" and the "pool table wall"
        parts.
    '''

    # wall_thickness: The height of the wall if horizontal, the
    #     width if vertical.
    wall_thickness = wall_part_thickness
    # flip_bit: in flags_2, used for pool table wall. 0 means
    #     that walls do not use this by default. (Result of bitwise AND
    #     will be always 0)
    flip_bit_wall = 0

    # Note: All wall bitmap files in TIM/TEMIM have 8 sub images, in
    #     the following arrangement: 0: Horizontal, left end;
    #     1: H, center 1; 2: H, center 2; 3: H, right end
    #     4: Vertical, top; 5: V, center 1; 6: V, center 2;
    #     7: V, bottom (TODO TODO)

    def __init__(self, part_num):
        '''
        The constructor of the class, has no arguments other than part_num
            (type: int, see PartGraphicsInfo_T2_Simple)
        '''
        PartGraphicsInfo_T2_Simple.__init__(self, part_num)
        self.wall_anm_data = None

    def get_wall_info(self, puzzle_part):
        '''
        Helper function for internal use. Returns a nt_t2_wall_tile_info
            containing information from the ANM file for the wall
        puzzle_part: the namedtuple argument of get_frame_images_info
        '''
        # TODO, this should be cached to avoid decoding the ANM file again
        #     and again

        if self.wall_anm_data is None:
            res_data_obj = self.puzzle_graph_info.parent
            self.wall_anm_data = res_data_obj.decode_sub_file(
                name_pattern_res_anm % puzzle_part.part_num, None)

        if len(self.wall_anm_data.anm_data_c[0]) != 2:
            raise RuntimeError(str_err_wall_anm)

        anm_data_c_1 = self.wall_anm_data.anm_data_c[-2].first_frame_id
        anm_data_c_2 = self.wall_anm_data.anm_data_c[-1].first_frame_id

        return nt_t2_wall_tile_info(
            anm_data_c_1, anm_data_c_2 - anm_data_c_1,
            self.wall_anm_data.anm_data_b[anm_data_c_2:])

    def get_wall_join_graphics(self, puzzle_part):
        '''
        May be re-implemented in a sub-class forr additional, sub-class
            specific graphics for get_frame_images_info.
            By default, returns an empty list
        puzzle_part: the namedtuple argument of get_frame_images_info
        '''
        return []

    # TODO: get_image_load_info could be re-implemented for optimization

    def get_frame_images_info(self, puzzle_part):
        '''
        Re-implementation of get_frame_images_info from
            PartGraphicsInfo_T2_Simple.
        '''
        # TODO FIXME: "Wall join" graphics is NOT YET supported!

        # NOTE: This function duplicates some code from
        #     PartGraphicsInfo_T1_Wall.However, there are several differences,
        #     so writing a common subroutine would unnecessarily
        #     over-complicate the implementation.

        if not wall_coords_check(puzzle_part, self.wall_thickness):
            return ()

        wall_info = self.get_wall_info(puzzle_part)

        if puzzle_part.height_1 == self.wall_thickness:
            # Horizontal wall
            # In TIM 1, the order (1-2-1-2... or 2-1-2-1...) of "center" tiles
            #     depends on the absolute position on the screen. This is no
            #     longer the case in TIM 2, so there is no "item_center_add"
            #     in TIM 2 wall code

            wall_length = puzzle_part.width_1 >> 4
            incr_x = t2_wall_tile_size
            incr_y = 0
            first_sub_img = 0
            num_sub_imgs = wall_info.num_tiles_horizontal
            wall_flip = (flip_vertical if puzzle_part.flags_2
                         & self.flip_bit_wall else flip_none)
        elif puzzle_part.width_1 == self.wall_thickness:
            # Vertical wall
            # Note: item_center_add is NOT needed for TIM 2 walls (see above)

            wall_length = puzzle_part.height_1 >> 4
            incr_x = 0
            incr_y = t2_wall_tile_size
            first_sub_img = wall_info.num_tiles_horizontal
            num_sub_imgs = wall_info.num_tiles_vertical
            wall_flip = (flip_horizontal if puzzle_part.flags_2
                         & self.flip_bit_wall else flip_none)
        else:
            # This should never happen, wall_coords_check should have failed
            return ()

        # Note: For optimization, this method does not call
        #     get_graphics_info_default. This means that several fields in
        #     part info, including x/y offset, will be ignored even if not 0.

        part_info = self.puzzle_graph_info.puzzle_info_obj.get_part_info(
            puzzle_part.part_num)

        pos_x = puzzle_part.pos_x - t2_shift_all_x
        pos_y = puzzle_part.pos_y - t2_shift_all_y
        file_name = name_pattern_res_anm % puzzle_part.part_num
        layer = layer_for_part(puzzle_part)

        # NOTE: alternative_flip set for pool wall !
        wall_tiles = [
            nt_graphics_info_t2(layer, file_name, first_sub_img, None, pos_x,
                                pos_y, wall_flip, 0, 0, True)
        ]

        for item_center in xrange(wall_length - 2):
            pos_x += incr_x
            pos_y += incr_y
            wall_tiles.append(
                nt_graphics_info_t2(
                    layer, file_name,
                    first_sub_img + 1 + (item_center % (num_sub_imgs - 2)),
                    None, pos_x, pos_y, wall_flip, 0, 0, True))

        if wall_length > 1:
            pos_x += incr_x
            pos_y += incr_y

            wall_tiles.append(
                nt_graphics_info_t2(layer, file_name,
                                    first_sub_img + num_sub_imgs - 1, None,
                                    pos_x, pos_y, wall_flip, 0, 0, True))

        wall_tiles.extend(self.get_wall_join_graphics(puzzle_part))
        return tuple(wall_tiles)

    def new_puzzle_loaded(self):
        '''
        Re-implementation of new_puzzle_loaded from PartGraphicsInfoBase.
            Clears self.wall_anm_data
        '''
        self.wall_anm_data = None


# Tuples containing relative ANM frame indices for "wall join" graphics.
#     An index of 0 corresponds to the first ANM frame for this type of
#     sub-image and not ANM frame #0. The three elements of the tuple
#     are three different orientations (left/top, middle, right/bottom)

t2_wall_join_rel_indices_horiz_left = (0, 2, 4)
t2_wall_join_rel_indices_horiz_right = (1, 3, 5)
t2_wall_join_rel_indices_vert_top = (6, 7, 8)
t2_wall_join_rel_indices_vert_bottom = (9, 10, 11)
t2_wall_join_num_frames = 12

str_warn_t2_wall_join = ('Warning, "wall join" graphics cannot be displayed '
                         'due to unsupported ANM file for part')


class PartGraphicsInfo_T2_Wall(PartGraphicsInfo_T2_WallPipe):
    '''
    PartGraphicsInfo_T2_WallPipe subclass for the "typical" wall parts.
        The main additional feature compared to PartGraphicsInfo_T2_WallPipe
        is "wall join graphics". This feature is not present in TIM/TEMIM
    '''

    def get_wall_join_graphics_info_item(self, puzzle_part, wall_other,
                                         graph_index, pos_x, pos_y):
        '''
        For internal use, helper function for get_wall_join_graphics.
        Returns a nt_graphics_info_t2 namedtuple or None on error.
        puzzle_part: see PartGraphicsInfo_T2_WallPipe.get_frame_images_info
        wall_other: PartInfoT2 returned by the search function
            in PuzzleWallsInfo
        graph_index: int, see t2_wall_join_rel_indices_*
        pos_x, pos_y: position for drawing the join graphics, not including
            the relative position from the ANM section B item
        '''
        layer = (puzzle_layer_foreground_parts_bin if puzzle_part.in_partsbin
                 or wall_other.in_partsbin else puzzle_layer_foreground)

        file_name = name_pattern_res_anm % puzzle_part.part_num
        wall_info = self.get_wall_info(puzzle_part)

        if len(wall_info.sect_b_items_tiles_join) != t2_wall_join_num_frames:
            print_msg(str_warn_t2_wall_join)
            return

        # TODO, wall_info.sect_b_items_tiles_join not used for anything
        #     other than a size check

        return nt_graphics_info_t2(
            layer, file_name, (graph_index + wall_info.num_tiles_horizontal +
                               wall_info.num_tiles_vertical), None, pos_x,
            pos_y, flip_none, None, None, False)

    def get_wall_join_graphics_horiz(self, puzzle_part, find_pos_left,
                                     anm_frame_rel_indices):
        '''
        For internal use, helper function for get_wall_join_graphics.
        Returns a nt_graphics_info_t2 namedtuple or None if no
            such graphics needs to be shown.
        puzzle_part: see PartGraphicsInfo_T2_WallPipe.get_frame_images_info
        find_pos_left: wall_pos_left argument for find_vert_wall_by_left_side
        anm_frame_rel_indices: One of t2_wall_join_rel_indices_* tuples
        '''
        walls_info_obj = self.puzzle_graph_info.walls_info
        wall_other = walls_info_obj.find_vert_wall_by_left_side(
            find_pos_left, puzzle_part.pos_y)

        if wall_other is None:
            return

        if puzzle_part.pos_y == wall_other.pos_y:
            graph_index = anm_frame_rel_indices[0]
        elif (puzzle_part.pos_y == wall_other.pos_y + wall_other.height_1 -
              self.wall_thickness):
            graph_index = anm_frame_rel_indices[2]
        else:
            graph_index = anm_frame_rel_indices[1]

        return self.get_wall_join_graphics_info_item(puzzle_part, wall_other,
                                                     graph_index,
                                                     find_pos_left,
                                                     puzzle_part.pos_y)

    def get_wall_join_graphics_vert(self, puzzle_part, find_pos_top,
                                    anm_frame_rel_indices):
        '''
        For internal use, helper function for get_wall_join_graphics.
        Returns a nt_graphics_info_t2 namedtuple or None if no
            such graphics needs to be shown.
        See meaning of arguments at get_wall_join_graphics_horiz
        find_pos_top: wall_pos_left argument for find_horiz_wall_by_top_side
        '''
        walls_info_obj = self.puzzle_graph_info.walls_info
        wall_other = walls_info_obj.find_horiz_wall_by_top_side(
            find_pos_top, puzzle_part.pos_x)

        if wall_other is None:
            return

        if puzzle_part.pos_x == wall_other.pos_x:
            graph_index = anm_frame_rel_indices[0]
        elif (puzzle_part.pos_x == wall_other.pos_x + wall_other.width_1 -
              self.wall_thickness):
            graph_index = anm_frame_rel_indices[2]
        else:
            graph_index = anm_frame_rel_indices[1]

        return self.get_wall_join_graphics_info_item(puzzle_part, wall_other,
                                                     graph_index,
                                                     puzzle_part.pos_x,
                                                     find_pos_top)

    def get_wall_join_graphics(self, puzzle_part):
        '''
        Re-implementation of get_wall_join_graphics from
            PartGraphicsInfo_T2_WallPipe
        '''
        # TODO: puzzle_part.behavior (temp_24) seems to contain relevant
        #     information in some, but not all cases. However, apparently
        #     this is not necessary for correct rendering

        part_name = self.puzzle_graph_info.puzzle_info_obj.get_part_name(
            puzzle_part.part_num)

        if puzzle_part.height_1 == self.wall_thickness:
            # Horizontal wall
            graph_1 = self.get_wall_join_graphics_horiz(
                puzzle_part, puzzle_part.pos_x - self.wall_thickness,
                t2_wall_join_rel_indices_horiz_left)

            graph_2 = self.get_wall_join_graphics_horiz(
                puzzle_part, puzzle_part.pos_x + puzzle_part.width_1,
                t2_wall_join_rel_indices_horiz_right)

        elif puzzle_part.width_1 == self.wall_thickness:
            # Vertical wall
            graph_1 = self.get_wall_join_graphics_vert(
                puzzle_part, puzzle_part.pos_y - self.wall_thickness,
                t2_wall_join_rel_indices_vert_top)

            graph_2 = self.get_wall_join_graphics_vert(
                puzzle_part, puzzle_part.pos_y + puzzle_part.height_1,
                t2_wall_join_rel_indices_vert_bottom)

        return [gritem for gritem in (graph_1, graph_2) if gritem is not None]

    def new_puzzle_loaded_part_action(self, puzzle_part):
        '''
        Re-implementation of new_puzzle_loaded_part_action from
            PartGraphicsInfoBase. TODO !
        See meaning of argument there.
        '''
        self.puzzle_graph_info.walls_info.add_wall_part(puzzle_part)


t2_large_pipe_thickness = 38


class PartGraphicsInfo_T2_LargePipe(PartGraphicsInfo_T2_WallPipe):
    '''
    PartGraphicsInfo_T2_WallPipe subclass for the "large pipe" part. Large
        pipes can be either horizontal or vertical. They always have two
        "end" sprites and a repeated "middle" sprite, therefore it can be
        handled by largely the same code used for walls.
    '''
    wall_thickness = t2_large_pipe_thickness

    def get_wall_info(self, puzzle_part):
        '''
        Re-implementation of get_wall_info from PartGraphicsInfo_T2_Wall.
        Returns nt_t2_wall_tile_info.
        '''
        # HACK fix, the approach used in PartGraphicsInfo_T2_Wall does not
        #     work here
        return nt_t2_wall_tile_info(3, 3, [])


t2_pool_wall_thickness = 32


class PartGraphicsInfo_T2_PoolTableWall(PartGraphicsInfo_T2_WallPipe):
    '''
    PartGraphicsInfo_T2_WallPipe subclass for the "pool table wall" part.
        This is a special type of wall that additionally can be flipped.
    '''
    wall_thickness = t2_pool_wall_thickness
    flip_bit_wall = t2_filp_vert_bit
    flip_bit = t2_filp_vert_bit

    # TODO: Pool table wall can also have a type of "wall join" graphics.
    #     The animation file contains one frame for it, and it must
    #     be flipped to the appropriate orientation. The code for "normal"
    #     walls cannot be used here and this feature is not implemented yet.
    #     This is not found in any of the puzzle files in the game due to the
    #     usage of pool holes.


t2_color_black = 5
t2_color_transparent = 0

str_warn_t2_color_block_params = (
    'WARNING: "Color block" scenery with '
    'invalid parameters found, part will not be shown.')


class PartGraphicsInfo_T2_ColorBlock(PartGraphicsInfo_T2_Simple):
    '''
    PartGraphicsInfo_T2_Simple subclass for a special type of scenery
        that shows either a solid filled  rectangle or a "dithered" pattern
        of two colors in the background.
    '''

    # Note: "Color block" is the "official" name of the scenery, the name
    #     is from the INFO.RES file of the game.

    def get_color_block_colors(self, puzzle_part):
        '''
        Function for internal use. Returns a tuple of 2 colors (ints)
            for this color blocks
        '''
        if puzzle_part.behavior < 0x10:
            return (puzzle_part.behavior, puzzle_part.behavior)
        else:
            return (puzzle_part.behavior >> 4, puzzle_part.behavior & 0xf)

    def get_image_load_info(self, puzzle_part):
        '''
        Re-implementation of get_image_load_info from PartGraphicsInfoBase.
        Returns list/tuple of nt_graphics_info_t2.
        '''
        # Returns empty tuple as no image from game resource files is needed
        return ()

    def get_frame_images_info(self, puzzle_part):
        '''
        Re-implementation of get_frame_images_info from
            PartGraphicsInfo_T2_Simple. ....
        '''

        if ((puzzle_part.width_1 == 0) or (puzzle_part.height_1 == 0)):
            print_msg(str_warn_t2_color_block_params)
            return ()

        color_1, color_2_temp = self.get_color_block_colors(puzzle_part)

        # HACK for black color (0 is used for transparency in the viewer)
        color_2 = (t2_color_black
                   if color_2_temp == t2_color_transparent else color_2_temp)

        if ((puzzle_part.width_1 & 0xf) or (puzzle_part.height_1 & 0xf)
                or (puzzle_part.width_1 != puzzle_part.width_2)
                or (puzzle_part.height_1 != puzzle_part.height_2)):
            print_msg(str_warn_t2_color_block_params)
            return ()

        if (puzzle_part.pos_x & 0x7) or (puzzle_part.pos_y & 0x7):
            print_msg(str_warn_t2_color_block_params)
            return ()

        res_data_obj = self.puzzle_graph_info.parent
        png_export = res_data_obj.get_object(s_obj_pngexp16)
        zoom = res_data_obj.get_option(s_opt_zoom)
        flip = res_data_obj.get_option(s_opt_flip)
        width_zoom = puzzle_part.width_1 * zoom
        height_zoom = puzzle_part.height_1 * zoom
        half_zoom = zoom >> 1
        zoom_odd = zoom & 1
        png_export.reset_image()
        png_export.set_width_height(width_zoom, height_zoom)

        if zoom > 1:
            row_0 = (bytearray(
                _rep_nibbles_even_odd(
                    (color_1 << 4) | color_2, half_zoom, zoom_odd)) *
                     (puzzle_part.width_1 >> 1))
            row_1 = (bytearray(
                _rep_nibbles_even_odd(
                    (color_2 << 4) | color_1, half_zoom, zoom_odd)) *
                     (puzzle_part.width_1 >> 1))
        else:
            row_0 = (bytearray(
                ((color_1 << 4) | color_2, )) * (puzzle_part.width_1 >> 1))
            row_1 = (bytearray(
                ((color_2 << 4) | color_1, )) * (puzzle_part.width_1 >> 1))

        # Is the number of flips odd or even?
        if flip in (flip_vertical, flip_horizontal):
            row_out_0 = bytes(row_1)
            row_out_1 = bytes(row_0)
        else:
            row_out_0 = bytes(row_0)
            row_out_1 = bytes(row_1)

        for lines in xrange(puzzle_part.height_1 >> 1):
            for cnt in xrange(zoom):
                png_export.add_line(row_out_0)

            for cnt in xrange(zoom):
                png_export.add_line(row_out_1)

        png_data = png_export.get_png_data()
        png_export.reset_image()

        gr_obj = nt_bm_sub_img_data(None, width_zoom, height_zoom,
                                    _make_png_data_flip(png_data, flip))

        # "Color block" and wallpaper" are in puzzle_layer_scenery_background

        return (nt_graphics_info_t2(puzzle_layer_scenery_background, None,
                                    None, gr_obj,
                                    puzzle_part.pos_x - t2_shift_all_x,
                                    puzzle_part.pos_y - t2_shift_all_y,
                                    flip_none, 0, 0, False), )

    def get_part_specific_info(self, puzzle_part):
        '''
        Re-implementation of get_part_specific_info from
            PartGraphicsInfo_T2_ColorBlock.
        '''
        return ('color_1: %d color_2: %d' %
                self.get_color_block_colors(puzzle_part))


str_warn_t2_wallpaper_params = (
    'WARNING: "Wallpaper" scenery with '
    'invalid parameters found, part will not be shown.')


class PartGraphicsInfo_T2_Wallpaper(PartGraphicsInfo_T2_Simple):
    '''
    PartGraphicsInfo_T2_Simple subclass for a special type of scenery
        that tiles an area of the puzzle background with a repeating,
        rectangular pattern. This class uses the "PNG merger" object
        for its implementation of clipping to a rectangular area.
    '''

    # Note: Rendering of "wallpaper" scenery parts depend on the absolute
    #     x and y position on the screen. Wallpapers are rendered as if the
    #     rendering started at (0, 0), (i.e., if (0, 0) is part of the area,
    #     then the top left corner of one tile will be there). Tiles that are
    #     partially out of the rectangle (***) but cropped to the "visible"
    #     rectangle.

    # This implementation uses PngMerge which implements such cropping.

    def __init__(self, part_num):
        '''
        The constructor of the class, has no arguments other than part_num
            (type: int, see PartGraphicsInfo_T2_Simple)
        '''
        PartGraphicsInfo_T2_Simple.__init__(self, part_num)
        self.bm_data = None

    def get_image_load_info(self, puzzle_part):
        '''
        Re-implementation of get_image_load_info from PartGraphicsInfoBase.
        Returns list/tuple of nt_graphics_info_t2.
        '''
        # Returns empty tuple as image from game resource files are
        #     treated separately
        return ()

    def get_frame_images_info(self, puzzle_part):
        '''
        Re-implementation of get_frame_images_info from
            PartGraphicsInfo_T2_Simple. ....
        '''
        if ((puzzle_part.width_1 == 0) or (puzzle_part.height_1 == 0)):
            print_msg(str_warn_t2_wallpaper_params)
            return ()

        if ((puzzle_part.width_1 & 0x7) or (puzzle_part.height_1 & 0x7)
                or (puzzle_part.width_1 != puzzle_part.width_2)
                or (puzzle_part.height_1 != puzzle_part.height_2)):
            print_msg(str_warn_t2_wallpaper_params)
            return ()

        if (puzzle_part.pos_x & 0x7) or (puzzle_part.pos_y & 0x7):
            print_msg(str_warn_t2_wallpaper_params)
            return ()

        res_data_obj = self.puzzle_graph_info.parent
        zoom = res_data_obj.get_option(s_opt_zoom)
        flip = res_data_obj.get_option(s_opt_flip)

        if self.bm_data is None:
            self.bm_data = res_data_obj.decode_sub_file(
                name_pattern_res_part % puzzle_part.part_num,
                nt_process_options_bm(None, (flip, )))

        img_data = self.bm_data.sub_images[0]

        if res_data_obj.get_object(s_obj_pngexp256).has_palette():
            obj_merge = res_data_obj.get_object(s_obj_pngmerge256)
        else:
            obj_merge = res_data_obj.get_object(s_obj_pngmerge16)

        # NOTE: this should work with the implementation of % for
        #     negative numbers in Python
        # Note: img_data.out_w and img_data.out_h are "zoomed"!
        pos_x_zoom = puzzle_part.pos_x * zoom
        pos_y_zoom = puzzle_part.pos_y * zoom

        start_pos_x = (pos_x_zoom - pos_x_zoom % img_data.out_w)
        start_pos_y = (pos_y_zoom - pos_y_zoom % img_data.out_h)

        x_right_zoom = (puzzle_part.pos_x + puzzle_part.width_1) * zoom
        y_bottom_zoom = (puzzle_part.pos_y + puzzle_part.height_1) * zoom

        end_x_mod = x_right_zoom % img_data.out_w
        end_y_mod = y_bottom_zoom % img_data.out_h

        end_pos_x = (x_right_zoom + img_data.out_w -
                     end_x_mod if end_x_mod else x_right_zoom)
        end_pos_y = (y_bottom_zoom + img_data.out_h -
                     end_y_mod if end_y_mod else y_bottom_zoom)

        width_zoom = puzzle_part.width_1 * zoom
        height_zoom = puzzle_part.height_1 * zoom

        obj_merge.set_canvas_size(width_zoom, height_zoom)

        for pos_y_temp in xrange(start_pos_y, end_pos_y, img_data.out_h):
            pos_y = (height_zoom - img_data.out_h - (pos_y_temp - pos_y_zoom)
                     if flip & flip_vertical else pos_y_temp - pos_y_zoom)

            for pos_x_temp in xrange(start_pos_x, end_pos_x, img_data.out_w):
                pos_x = (width_zoom - img_data.out_w -
                         (pos_x_temp - pos_x_zoom) if flip & flip_horizontal
                         else pos_x_temp - pos_x_zoom)

                obj_merge.add_image(
                    nt_image_display_data(pos_x, pos_y, flip,
                                          img_data.png_data_flip[flip]))

        obj_merge.finish_processing()
        out_data = obj_merge.get_png_data()
        obj_merge.reset_data_image()

        gr_obj = nt_bm_sub_img_data(None, width_zoom, height_zoom,
                                    _make_png_data_flip(out_data, flip))

        # "Color block" and wallpaper" are in puzzle_layer_scenery_background

        return (nt_graphics_info_t2(puzzle_layer_scenery_background, None,
                                    None, gr_obj,
                                    puzzle_part.pos_x - t2_shift_all_x,
                                    puzzle_part.pos_y - t2_shift_all_y,
                                    flip_none, 0, 0, False), )

    def new_puzzle_loaded(self):
        '''
        Re-implementation of new_puzzle_loaded from PartGraphicsInfoBase.
            Clears self.bm_data
        '''
        self.bm_data = None


# Tuple of 3 items, color for belt (light gray, dark gray, black)
t2_colors_thick_line_belt = (7, 8, 5)

t1_color_belt = 5


class PartGraphicsInfo_T2_Belt(PartGraphicsInfo_T2_Simple):
    '''
    PartGraphicsInfo_T1_Simple subclass for belts. Belts connect two
        "rotating" parts. In TIM 2/3, belts are represented by two
        "thick lines" (both consisting of 3 lines each),
        see create_thick_line_items.
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
        Returns tuple of two nt_graphics_info_t1 entries corresponding to two
            black lines or an empty tuple if the belt is not visible.
        '''

        # NOTE: This function duplicates some code from
        #     PartGraphicsInfo_T1_Belt. For example, the same fields of the
        #     part namedtuples contain the required information. However,
        #     there are several differences, so writing a common subroutine
        #     would unnecessarily over-complicate the implementation.
        # Like in TIM/TEMIM, the belts connect approximately circle-shaped
        #     areas inside the parts. See puzzle/t1pgraph.py for more
        #     information. The "horizontal" vs. "vertical" positioning of the
        #     two belt segments also apply here. The most important
        #     differences are (in short):
        # 1. belt_info_1 contains approximately the position of the center
        #     of the circular area instead of the top left corner of bounding
        #     rectangle
        # 2. belt_info_2 is (approximately) the radius of this circle
        #     (- 1 pixel), not its diameter.

        index_part_1 = puzzle_part.belt_index_connected_1
        index_part_2 = puzzle_part.belt_index_connected_2

        # When at least one index is not valid (-1), return

        if (index_part_1 < 0) or (index_part_2 < 0):
            return ()

        part_connected_1 = self.puzzle_graph_info.get_part(index_part_1)
        part_connected_2 = self.puzzle_graph_info.get_part(index_part_2)
        # TODO, check for odd number
        part_1_conn_x, part_1_conn_y = int_16_to_2_bytes(
            part_connected_1.belt_info_1)

        # According to my tests, 1 needs to be added to part_1_belt_line_dist
        #     and part_2_belt_line_dist for drawing the belt "correctly"
        part_1_belt_line_dist = part_connected_1.belt_info_2 + 1
        part_2_conn_x, part_2_conn_y = int_16_to_2_bytes(
            part_connected_2.belt_info_1)
        part_2_belt_line_dist = part_connected_2.belt_info_2 + 1

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
            ## line_1_pos_x = min(part_1_conn_pos_x, part_2_conn_pos_x)
            ## line_1_pos_y = (min(part_1_conn_pos_y, part_2_conn_pos_y) -
            ##                 part_1_belt_line_dist)

            line_1_pos_x = min(part_2_conn_pos_x - part_2_belt_line_dist,
                               part_1_conn_pos_x - part_1_belt_line_dist)
            line_1_pos_y = min(part_1_conn_pos_y, part_2_conn_pos_y)
            line_2_pos_x = min(part_2_conn_pos_x + part_2_belt_line_dist,
                               part_1_conn_pos_x + part_1_belt_line_dist)
            line_2_pos_y = line_1_pos_y

            line_1_pos_dir_x = ((part_2_conn_pos_x - part_2_belt_line_dist) -
                                (part_1_conn_pos_x - part_1_belt_line_dist))
            line_1_pos_dir_y = part_2_conn_pos_y - part_1_conn_pos_y
            line_2_pos_dir_x = ((part_2_conn_pos_x + part_2_belt_line_dist) -
                                (part_1_conn_pos_x + part_1_belt_line_dist))
            line_2_pos_dir_y = part_2_conn_pos_y - part_1_conn_pos_y

        else:
            ## line_1_pos_x = (min(part_1_conn_pos_x, part_2_conn_pos_x) -
            ##                 part_1_belt_line_dist)
            ## line_1_pos_y = min(part_1_conn_pos_y, part_2_conn_pos_y)
            line_1_pos_x = min(part_1_conn_pos_x, part_2_conn_pos_x)
            line_1_pos_y = min(part_2_conn_pos_y - part_2_belt_line_dist,
                               part_1_conn_pos_y - part_1_belt_line_dist)

            line_2_pos_x = line_1_pos_x
            line_2_pos_y = min(part_2_conn_pos_y + part_2_belt_line_dist,
                               part_1_conn_pos_y + part_1_belt_line_dist)

            line_1_pos_dir_x = part_2_conn_pos_x - part_1_conn_pos_x
            line_1_pos_dir_y = ((part_2_conn_pos_y - part_2_belt_line_dist) -
                                (part_1_conn_pos_y - part_1_belt_line_dist))
            line_2_pos_dir_x = part_2_conn_pos_x - part_1_conn_pos_x
            line_2_pos_dir_y = ((part_2_conn_pos_y + part_2_belt_line_dist) -
                                (part_1_conn_pos_y + part_1_belt_line_dist))

        if part_connected_1.in_partsbin or part_connected_2.in_partsbin:
            layer = puzzle_layer_foreground_parts_bin
        else:
            layer = layer_for_part(puzzle_part)

        return (self.create_thick_line_items(
            line_1_pos_x, line_1_pos_y, line_1_pos_dir_x, line_1_pos_dir_y,
            t2_colors_thick_line_belt, layer) + self.create_thick_line_items(
                line_2_pos_x, line_2_pos_y, line_2_pos_dir_x, line_2_pos_dir_y,
                t2_colors_thick_line_belt, layer))

    def get_part_specific_info(self, puzzle_part):
        '''
        Re-implementation of get_part_specific_info from
            PartGraphicsInfo_T1_Simple. See meaning of argument there.
        '''
        index_part_1 = puzzle_part.belt_index_connected_1
        index_part_2 = puzzle_part.belt_index_connected_2

        out_info = []

        if index_part_1 >= 0:
            out_info.append('connected_part_1: %d' % index_part_1)

        if index_part_2 >= 0:
            out_info.append('connected_part_2: %d' % index_part_2)

        return ' '.join(out_info)


rope_knot_anm_frame = 0

# Tuple of 3 items, color for rope (orange, yellow, brown)
t2_colors_thick_line_rope = (6, 14, 13)

# Tuple of 3 items, color for steel cable (dark gray, light gray, black)
t2_colors_thick_line_steel_cable = (8, 7, 5)

# Needed for correct positioning of the "knot at rope end" graphics.
#     This information is not present in the puzzle or the ANM file.
#     Obtained by analyzing screenshots.
# Note: The behavior is similar in TIM, but with different constants.
#     This is however not implemented in the main class due to implementation
#     differences.
t2_knot_graph_pos_rel_x = -8
t2_knot_graph_pos_rel_y = -7


class PartGraphicsInfo_T2_Rope(PartGraphicsInfo_T2_Simple,
                               PartGraphicsInfoRopeMixin):
    '''
    PartGraphicsInfo_T2_Simple subclass for ropes. ...
    '''

    thick_line_colors = t2_colors_thick_line_rope

    def get_image_load_info(self, puzzle_part):
        '''
        Re-implementation of get_image_load_info from PartGraphicsInfoBase.
        Returns list/tuple of nt_graphics_info_t1.
        '''
        # Return the "knot at rope end" graphics but only if it is not
        #     stored in the "extra" subdirectory.
        index_part_1 = puzzle_part.temp_36
        index_part_2 = puzzle_part.rope_info_2  # FIXME

        if (index_part_1 >= 0) or (index_part_2 >= 0):
            # TODO, in some cases, the rope is not actually shown
            file_name = name_pattern_res_anm % puzzle_part.part_num

            return (nt_graphics_info_t2(self.get_rope_layer(puzzle_part),
                                        file_name, rope_knot_anm_frame, None,
                                        0, 0, flip_none, None, None, False), )
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

        file_name = name_pattern_res_anm % puzzle_part.part_num
        layer = self.get_rope_layer(puzzle_part)

        pos_start_x = rope_segments[0].start_x
        pos_start_y = rope_segments[0].start_y
        pos_last_x = rope_segments[-1].end_x
        pos_last_y = rope_segments[-1].end_y

        frame_images = [
            nt_graphics_info_t2(
                layer, file_name, rope_knot_anm_frame, None,
                pos_start_x + t2_knot_graph_pos_rel_x - t2_shift_all_x,
                pos_start_y + t2_knot_graph_pos_rel_y - t2_shift_all_y,
                flip_none, None, None, False),
            nt_graphics_info_t2(
                layer, file_name, rope_knot_anm_frame, None,
                pos_last_x + t2_knot_graph_pos_rel_x - t2_shift_all_x,
                pos_last_y + t2_knot_graph_pos_rel_y - t2_shift_all_y,
                flip_none, None, None, False)
        ]

        for segment in rope_segments:
            line_pos_x = min(segment.start_x, segment.end_x)
            line_pos_y = min(segment.start_y, segment.end_y)

            frame_images.extend(
                self.create_thick_line_items(line_pos_x, line_pos_y,
                                             segment.end_x - segment.start_x,
                                             segment.end_y - segment.start_y,
                                             self.thick_line_colors, layer))

        return tuple(frame_images)

    def get_part_specific_info(self, puzzle_part):
        '''
        Re-implementation of get_part_specific_info from
            PartGraphicsInfo_T1_Simple. See meaning of argument there.
        '''
        return self.get_rope_info_str(puzzle_part)


class PartGraphicsInfo_T2_SteelCable(PartGraphicsInfo_T2_Rope):
    '''
    PartGraphicsInfo_T2_Rope subclass for steel cable, behaving similar to
    rope, with two differences: 1. different color and kont graphics,
        2. can be cut only one of the two "scissors" parts.

    '''
    thick_line_colors = t2_colors_thick_line_steel_cable


class PartGraphicsInfo_T2_PhazerGun(PartGraphicsInfo_T2_FlipAxisXCorrect):
    '''
    PartGraphicsInfo_T2_Simple subclass for the "phazer gun" part.
        This part shoots energy pulses when its trigger is pulled
        through a rope.
    '''

    def get_part_specific_info(self, puzzle_part):
        '''
        Re-implementation of get_part_specific_info from
            PartGraphicsInfo_T1_Simple. See meaning of argument there.
        '''
        info_parent = PartGraphicsInfo_T2_Simple.get_part_specific_info(
            self, puzzle_part)

        return '%s number_shots: %d' % (info_parent, puzzle_part.behavior)


class PartGraphicsInfo_T2_MessageComputer(PartGraphicsInfo_T2_Simple):
    '''
    PartGraphicsInfo_T2_Simple subclass for the "message computer" part.
        This part looks like a PC and shows a single character when an object
        is dropped on its keyboard.
    '''

    def get_part_specific_info(self, puzzle_part):
        '''
        Re-implementation of get_part_specific_info from
            PartGraphicsInfo_T1_Simple. See meaning of argument there.
        '''
        # Note: The characters a message computer can show are essentially
        #     a sub_set of the CP437 code page
        # Check for invalid values

        char_code = puzzle_part.behavior

        if (char_code >= 0x20) and (char_code <= 0xff):
            return "character_shown: '%s' (%d)" % (bytearray(
                (char_code, )).decode(game_text_encoding), char_code)
        else:
            return ''


class PartGraphicsInfo_T2_AcceleratorPipe(PartGraphicsInfo_T2_Simple):
    '''
    PartGraphicsInfo_T2_Simple subclass for the "accelerator pipe" part.
        This part can be used for accelerating parts moving in pipes.
    '''

    def get_part_specific_info(self, puzzle_part):
        '''
        Re-implementation of get_part_specific_info from
            PartGraphicsInfo_T1_Simple. See meaning of argument there.
        '''
        # This part needs specific treatment for "part info" as it uses
        #      combination of flip flags (both horizontal and vertical) and
        #      .ANM frame indices ("appearance")

        puzzle_info_obj = self.puzzle_graph_info.puzzle_info_obj
        part_appearance_texts = puzzle_info_obj.get_part_appearance_texts(
            puzzle_part.part_num)

        # This should not occur
        if ((part_appearance_texts is None)
                or (part_appearance_texts.extra_data is None)):
            return ''

        flip_flags = puzzle_part.flags_2 & (t2_filp_horiz_bit
                                            | t2_filp_vert_bit)

        direction_text = part_appearance_texts.extra_data.get(
            (flip_flags, puzzle_part.appearance), '')

        return 'direction: %s (%d %d)' % (direction_text, flip_flags,
                                          puzzle_part.appearance)


t2_prog_part_params = ('mass', 'elasticity', 'density', 'friction')


class PartGraphicsInfo_T2_ProgrammableBall(PartGraphicsInfo_T2_Simple):
    '''
    PartGraphicsInfo_T2_Simple subclass for the "programmable ball" part.
        This part has 7 different appearances and its mass, elasticity,
        density and friction can be programmed.
    '''

    def get_part_specific_info(self, puzzle_part):
        '''
        Re-implementation of get_part_specific_info from
            PartGraphicsInfo_T1_Simple. See meaning of argument there.
        '''
        # Note: part_appearance_texts.extra_data for this part contains
        #     four dicts, one for each programmable parameter:  mass,
        #     elasticity, density and friction (in this order)
        puzzle_info_obj = self.puzzle_graph_info.puzzle_info_obj
        part_appearance_texts = puzzle_info_obj.get_part_appearance_texts(
            puzzle_part.part_num)

        # This should not occur (fixme, duplication)
        if ((part_appearance_texts is None)
                or (part_appearance_texts.extra_data is None)
                or (part_appearance_texts.appearance_text_dict is None)):
            return ''

        part_data = puzzle_part.extra_data_2
        data_tuple = (part_data.mass, part_data.elasticity, part_data.density,
                      part_data.friction)

        part_info = [
            '%s: %s (%d)' %
            (param_text, param_dict.get(param_value, ''), param_value)
            for param_text, param_dict, param_value in izip(
                t2_prog_part_params, part_appearance_texts.extra_data,
                data_tuple)
        ]

        # Note: appearance_2 not shown as it always contains the same value
        #     as appearance.
        part_info.append('gravity_buoyancy: (%d)' % part_data.gravity_buoyancy)
        part_info.append('appearance: %s (%d)' %
                         (part_appearance_texts.appearance_text_dict.get(
                             puzzle_part.appearance), puzzle_part.appearance))

        return ' '.join(part_info)


class PartGraphicsInfo_T2_Gear(PartGraphicsInfo_T2_Simple):
    '''
    PartGraphicsInfo_T2_SubImageID subclass for gears.
    '''

    def get_part_specific_info(self, puzzle_part):
        '''
        Re-implementation of get_part_specific_info from
            PartGraphicsInfo_T1_Simple. See meaning of argument there.
        '''
        # TODO, more reverse engineering work is needed. See comments in
        #     puzzle/t1pinfo.py. There seems to be no difference
        #     between TIM/TEMIM and TIM2/TIM3.

        out_info = []  # Fixme, duplication, from belt

        if puzzle_part.connected_1 >= 0:
            out_info.append('connected_part_1: %d' % puzzle_part.connected_1)

        if puzzle_part.connected_2 >= 0:
            out_info.append('connected_part_2: %d' % puzzle_part.connected_2)

        return ' '.join(out_info)


class PartGraphicsInfo_T2_RemoteControl(PartGraphicsInfo_T2_Simple):
    '''
    PartGraphicsInfo_T2_Simple subclass for the "remote control" of
        remote bomb part. The two "halves" of such a bomb is stored
        as two puzzle parts in the level file in TIM 2/3.
    '''

    def get_part_specific_info(self, puzzle_part):
        '''
        Re-implementation of get_part_specific_info from
            PartGraphicsInfo_T1_Simple. See meaning of argument there.
        '''
        # This part uses connected_1 for the rope connected to the explosives.
        # connected_2 is the bomb and not another rope.
        out_info = []  # Fixme, duplication, from belt

        if puzzle_part.connected_1 >= 0:
            out_info.append('connected_rope: %d' % puzzle_part.connected_1)

        if puzzle_part.connected_2 >= 0:
            out_info.append('bomb_part: %d' % puzzle_part.connected_2)

        return ' '.join(out_info)


class PartGraphicsInfo_T2_RemoteBomb(PartGraphicsInfo_T2_Simple):
    '''
    PartGraphicsInfo_T2_Simple subclass for the "bomb" in
        remote bomb puzzlr part.
    '''

    def get_part_specific_info(self, puzzle_part):
        '''
        Re-implementation of get_part_specific_info from
            PartGraphicsInfo_T1_Simple. See meaning of argument there.
        '''
        # connected_2 is the remote control
        if puzzle_part.connected_2 >= 0:
            return 'remote_c_part: %d' % puzzle_part.connected_2
        else:
            return ''


class PuzzleGraphicsInfo_T2(PuzzleGraphicsInfoBase):
    '''
    PuzzleGraphicsInfoBase subclass for TIM/TEMIM puzzles (including saved
          "freeform machines" and the GKC (intro/credits screen) files. ...
    '''
    # NOTE PuzzleGraphicsInfoT2 is used for TIM 2 and TIM 3 (the latter has
    #     the same puzzles)

    # Supported game versions, modified from parent class
    supported_verisons = (game_ver_tim2, )

    # The identifier of associated PuzzleInfoT1 object
    puzzle_info_obj_name = s_obj_puzzleinfov2

    # puzzle_screen_size: Size of puzzle screen in the supported game versions
    puzzle_screen_size = nt_size(560, 377)

    # The default part type class is PartGraphicsInfo_T2_Simple
    part_object_default_type = PartGraphicsInfo_T2_Simple

    # Part types that require special treatment using
    #     PartGraphicsInfo_T1_Simple subclasses. Format: See puzgraph.py

    part_object_types = (
        (1, PartGraphicsInfo_T2_Wall),
        (8, PartGraphicsInfo_T2_Belt),
        (10, PartGraphicsInfo_T2_Rope),
        (18, PartGraphicsInfo_T2_AlternativeFlip),
        (21, PartGraphicsInfo_T2_ElectricOutlet),
        (26, PartGraphicsInfo_T2_ElectricOutlet),
        (36, PartGraphicsInfo_T2_AlternativeFlip),
        (38, PartGraphicsInfo_T2_ElectricOutlet),
        (46, PartGraphicsInfo_T2_Wall),
        (48, PartGraphicsInfo_T2_Wall),
        (56, PartGraphicsInfo_T2_Wall),
        (60, PartGraphicsInfo_T2_Wall),
        (70, PartGraphicsInfo_T2_AlternativeFlip),
        (76, PartGraphicsInfo_T2_SteelCable),
        (82, PartGraphicsInfo_T2_Wall),
        (83, PartGraphicsInfo_T2_Wall),
        (84, PartGraphicsInfo_T2_Wall),
        (85, PartGraphicsInfo_T2_Wall),
        (91, PartGraphicsInfo_T2_AlternativeFlip),
        (92, PartGraphicsInfo_T2_AlternativeFlip),
        (93, PartGraphicsInfo_T2_AlternativeFlip),
        (94, PartGraphicsInfo_T2_AlternativeFlip),
        (95, PartGraphicsInfo_T2_AlternativeFlip),
        (96, PartGraphicsInfo_T2_LaserOutlet),
        (97, PartGraphicsInfo_T2_LargePipe),
        (117, PartGraphicsInfo_T2_AlternativeFlip),
        (118, PartGraphicsInfo_T2_PoolTableWall),
        (120, PartGraphicsInfo_T2_ElectricOutlet),
        (121, PartGraphicsInfo_T2_Wallpaper),
        (122, PartGraphicsInfo_T2_Wallpaper),
        (123, PartGraphicsInfo_T2_Wallpaper),
        (124, PartGraphicsInfo_T2_Wallpaper),
        (125, PartGraphicsInfo_T2_Wall),
        (127, PartGraphicsInfo_T2_ColorBlock),
        (203, PartGraphicsInfo_T2_Wallpaper),
        (205, PartGraphicsInfo_T2_Wallpaper),
        (271, PartGraphicsInfo_T2_Wallpaper),
        (280, PartGraphicsInfo_T2_Wallpaper),
        (16, PartGraphicsInfo_T2_FlipAxisXCorrect),
        (24, PartGraphicsInfo_T2_FlipAxisXCorrect),
        (40, PartGraphicsInfo_T2_FlipAxisXCorrect),
        (54, PartGraphicsInfo_T2_FlipAxisXCorrect),
        (109, PartGraphicsInfo_T2_FlipAxisXCorrect),
        (27, PartGraphicsInfo_T2_PhazerGun),
        (12, PartGraphicsInfo_T2_FlipAxisXCorrect),
        (42, PartGraphicsInfo_T2_FlipAxisXCorrect),
        (61, PartGraphicsInfo_T2_FlipAxisXCorrect),
        (25, PartGraphicsInfo_T2_FlipAxisXCorrect),
        (116, PartGraphicsInfo_T2_FlipAxisXCorrect),
        (81, PartGraphicsInfo_T2_FlipAxisXCorrect),
        (31, PartGraphicsInfo_T2_FlipAxisXCorrect),
        (35, PartGraphicsInfo_T2_FlipAxisXCorrect),
        (37, PartGraphicsInfo_T2_FlipAxisXCorrect),
        (77, PartGraphicsInfo_T2_FlipAxisXCorrect),
        (73, PartGraphicsInfo_T2_FlipAxisXCorrect),
        (50, PartGraphicsInfo_T2_FlipAxisXCorrect),
        (51, PartGraphicsInfo_T2_FlipAxisXCorrect),
        (62, PartGraphicsInfo_T2_FlipAxisXCorrect),
        (30, PartGraphicsInfo_T2_FlipAxisXCorrect),
        (45, PartGraphicsInfo_T2_FlipAxisXCorrect),
        (89, PartGraphicsInfo_T2_FlipAxisXCorrect),
        (6, PartGraphicsInfo_T2_FlipAxisXCorrect),
        (19, PartGraphicsInfo_T2_FlipAxisXCorrect),
        (75, PartGraphicsInfo_T2_FlipAxisXCorrect),
        (137, PartGraphicsInfo_T2_FlipAxisXCorrect),
        (33, PartGraphicsInfo_T2_FlipAxisXCorrect),
        (2, PartGraphicsInfo_T2_Slope),
        (99, PartGraphicsInfo_T2_Slope),
        (100, PartGraphicsInfo_T2_Slope),
        (101, PartGraphicsInfo_T2_Slope),
        (102, PartGraphicsInfo_T2_Slope),
        (126, PartGraphicsInfo_T2_Slope),
        (90, PartGraphicsInfo_T2_VerticalFlip),
        (23, PartGraphicsInfo_T2_VerticalFlip),
        (87, PartGraphicsInfo_T2_ProgrammableBall),
        (88, PartGraphicsInfo_T2_AcceleratorPipe),
        (136, PartGraphicsInfo_T2_MessageComputer),
        (14, PartGraphicsInfo_T2_Gear),
        (86, PartGraphicsInfo_T2_Gear),
        (22, PartGraphicsInfo_T2_RemoteControl),
        (55, PartGraphicsInfo_T2_RemoteBomb),
    )

    def __init__(self):
        '''Constructor of the class. Requires no argument.'''
        PuzzleGraphicsInfoBase.__init__(self)
        self.walls_info = PuzzleWallsInfo()

    def set_puzzle_data(self, new_puzzle_data):
        '''
        Re-implementation of set_puzzle_data from PuzzleGraphicsInfoBase.
        Additionally, resets the walls_info object.
        See meaning of argument there.
        '''
        self.walls_info.reset_wall_data()
        PuzzleGraphicsInfoBase.set_puzzle_data(self, new_puzzle_data)

    def get_background_fill_image(self):
        '''
        Re-implementation of get_part_obj_by_number from
            PuzzleGraphicsInfoBase.
        '''
        rect_width, rect_height = self.get_puzzle_screen_size()

        # If the background_color field is 0, black background is shown, which
        #     seems to correspond to color 0, not color 5 in the palette
        #     However, no such puzzle is found in the game
        # What is more interesting, if the background_color field is >= 0x10,
        #     the game will show a dithered pattern! (similar to the
        #     "color block" scenery.) However, again, no such puzzle is found
        #     in the game and the only way to create such a puzzle is editing
        #     the file by a hex editor.
        # This latter case is currently NOT supported
        background_color = (background_color_t2_default
                            if self.puzzle_data.backgr_color is None else
                            self.puzzle_data.backgr_color)

        return nt_graphics_info_t2(
            puzzle_layer_background, None, None,
            self.png_shape_draw.draw_rectangle_with_border(
                rect_width, rect_height, background_color, background_color),
            0, 0, flip_none, None, None, False)
