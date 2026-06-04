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

import os
from collections import namedtuple
from timgres.base.misc import (print_msg, namedtuple_to_str,
                               s_opt_raw_part_info, s_opt_no_puzzle_backgr,
                               s_opt_show_solution, s_vdata_puzzle_t1,
                               s_vdata_puzzle_t2, s_obj_graphinfov1,
                               s_obj_graphinfov2)

from timgres.base.vdobase import (ViewerDataObj_MultiSubImage,
                                  nt_info_col_header, _num_list_to_str_nosp)
from timgres.puzzle.anmview import (StoredDataViewerMixin,
                                    AnmFramesViewerMixin, name_pattern_res_anm)
from timgres.puzzle.puzdata import (get_puzzle_info_obj_for_ver, game_ver_strs,
                                    game_ver_tim_demo)
from timgres.puzzle.puzgraph import (
    puzzle_layer_background, puzzle_layer_scenery_background,
    puzzle_layer_scenery, puzzle_layer_fixed_parts, puzzle_layer_moving_parts,
    puzzle_layer_parts_bin_parts, puzzle_layer_foreground,
    puzzle_layer_foreground_parts_bin, nt_info_puzzle)
'''
This module contains the viewer classes for TIM - TIM 3 puzzles. The common
    parent class for such objects is ViewerDataObj_PuzzleBase. It has two
    subclasses, one for TIM / TEMIM (ViewerDataObj_Puzzle_T1) and one for
    TIM 2 / 3 (ViewerDataObj_Puzzle_T2). The two inherit different mixin
    classes form puzzle.anmview in addition to the common parent.
'''


def namedtuple_to_str_part(nt, start=0, end=None):
    '''
    Function for internal use. Similar to namedtuple_to_str, with
        additional slicing.
    '''
    if end is not None:
        return ' '.join('%s: %d' % xy
                        for xy in izip(nt._fields[start:end], nt[start:end]))
    else:
        return ' '.join('%s: %d' % xy
                        for xy in izip(nt._fields[start:], nt[start:]))


# nt_sub_item_layers: namedtuple containing information about
#     which layers are visible in a puzzle viewer sub-item
# sub_item_text: Text of sub-item displayed (str)
# layers_shown: tuple of layer numbers, see puzzle_layer_* constants
#     (puzgraph.py)

nt_sub_item_layers = namedtuple('nt_sub_item_layers',
                                ('sub_item_text', 'layers_shown'))

str_not_impl_ViewerDataObj_PuzzleBase = ('Not implemented in '
                                         'ViewerDataObj_PuzzleBase')

part_num_prog_ball = 87


def part_namedtuple_to_str(part_data, game_ver):
    '''
    Function for internal use. Converts a part info namedtuple sub
    part_data: Part specific namedtuple subclass, see d_puzzle.py
    game_ver: The game version, see constants in puzdata.py (int)
    '''
    # NOTE: extra_data is now inserted before the last 4 fields
    #   of the namedtuple

    pos_after_extra_1 = -3 if game_ver == game_ver_tim_demo else -4

    if part_data.extra_data_1 is not None:
        str_extra_1 = ' ' + namedtuple_to_str(part_data.extra_data_1)
    else:
        str_extra_1 = ''

    if part_data.extra_data_2 is not None:
        if game_ver == game_ver_tim_demo:
            str_extra_2 = ' ' + namedtuple_to_str_part(
                part_data.extra_data_2, 0, part_data.num_extra_fields_end)
        else:
            str_extra_2 = ' ' + namedtuple_to_str(part_data.extra_data_2)
    else:
        str_extra_2 = ''

    return '%s%s %s%s' % (
        namedtuple_to_str_part(part_data, 5, pos_after_extra_1), str_extra_1,
        namedtuple_to_str_part(part_data, pos_after_extra_1), str_extra_2)


class ViewerDataObj_PuzzleBase(ViewerDataObj_MultiSubImage):
    '''
    Base ViewerDataObj_MultiSubImage class for viewing puzzles
    Has two abstract methods: add_sub_image_load_info_subclass and
        add_new_img_curr_frame_subclass
    Temporary viewer class for testing puzzle decoding. ****
    No images are displayed, info text only.
    '''

    # Fields modified from parent class

    # info_col_headers: corresponds to the items of nt_sub_item_info_bmp
    # TODO, Temporary !!!
    info_col_headers = (
        nt_info_col_header('Info', -250),
        nt_info_col_header('Data', -4000),
    )

    # sub_item_layers: tuple of nt_sub_item_layers namedtuples, must be
    #      modified in sub_classes
    sub_item_layers = ()

    # puzzle_graph_info_obj_name: Name of the associated puzzle graphics info
    #     object (PuzzleGraphicsInfoBase subclass), see puzgraph.py.
    #     Must be modified in sub-class.
    puzzle_graph_info_obj_name = ''

    def reset_data_subclass(self):
        '''
        Re-implementation of reset_data_subclass from
            ResDataBase_ViewerDataObj. Resets fields that are used for
            storing data related to the selected file/sub-item.***
        '''
        # NOTE: this cannot be done in constructor
        # puzzle_graph_info
        self.puzzle_data = None
        self.puzzle_graph_info = None
        self.puzzle_info_obj = None

    def add_sub_image_load_info_subclass(self, load_info):
        '''
        Not implemented in ViewerDataObj_PuzzleBase. Called from
            set_sub_image_load_info, receives single subclass-specific
            namedtuples as argument from
            puzzle_graph_info.get_frame_images_info.
        load_info: A subclass (and version) specific namedtuple
        '''
        raise NotImplementedError(str_not_impl_ViewerDataObj_PuzzleBase)

    def add_new_img_curr_frame_subclass(self, img_info):
        '''
        Not implemented in ViewerDataObj_PuzzleBase. Called from
            set_frame_data, receives single subclass-specific
            namedtuples as argument from
            puzzle_graph_info.get_frame_images_info.
        img_info: A subclass (and version) specific namedtuple
        '''
        raise NotImplementedError(str_not_impl_ViewerDataObj_PuzzleBase)

    def set_sub_image_load_info(self):
        '''
        Re-implementation of set_sub_image_load_info from
            ViewerDataObj_MultiSubImage. ....
        '''
        self.puzzle_data = self.parent.decode_sub_file(
            self.sub_file_name,
            os.path.splitext(self.sub_file_name)[1])

        self.puzzle_graph_info = self.parent.get_object(
            self.puzzle_graph_info_obj_name)
        self.puzzle_graph_info.set_puzzle_data(self.puzzle_data)

        if not self.puzzle_graph_info.is_puzzle_version_supported():
            return

        self.puzzle_info_obj = self.puzzle_graph_info.get_puzzle_info_obj()

        for load_info_item in self.puzzle_graph_info.get_image_load_info():
            self.add_sub_image_load_info_subclass(load_info_item)

    def set_frame_data(self):
        '''
        Re-implementation of set_frame_data from ViewerDataObj_MultiSubImage.
        '''
        # Note: This method expects that self.puzzle_graph_info and
        #     self.puzzle_data was already set in set_sub_image_load_info

        if not self.puzzle_graph_info.is_puzzle_version_supported():
            return

        frame_images_info = self.puzzle_graph_info.get_frame_images_info()
        frame_width, frame_height = \
            self.puzzle_graph_info.get_puzzle_screen_size()
        no_background = self.parent.get_option(s_opt_no_puzzle_backgr)
        show_solution = self.parent.get_option(s_opt_show_solution)

        for sub_item_cnt, (sub_item_text,
                           layers_shown) in enumerate(self.sub_item_layers):
            # TODO TODO: If show_solution is False, the graphics for the parts
            #     only present in the "solution" is still loaded
            if ((not show_solution)
                    and (puzzle_layer_parts_bin_parts in layers_shown)):
                continue

            layers = (layers_shown if no_background else
                      (puzzle_layer_background, ) + layers_shown)

            self.add_new_frame(frame_width, frame_height)

            for num_layer in layers:
                # Note: num_layer is a namedtuple that must always have
                #     a field named layer_number

                # HACK for TIM 2 puzzle scenery Z-order

                for images_info_item in frame_images_info[::-1]:
                    if num_layer == images_info_item.layer_number:
                        self.add_new_img_curr_frame_subclass(images_info_item)

            self.end_frame_add_info(
                nt_info_puzzle(
                    '%s [%d/%d]' %
                    (sub_item_text, sub_item_cnt, len(self.sub_item_layers)),
                    'Layers: %s %s' %
                    (_num_list_to_str_nosp(layers),
                     namedtuple_to_str(
                         self.puzzle_graph_info.part_counts_in_layers(layers)))
                ))

    def set_head_info(self):
        '''
        Re-implementation of set_head_info from ViewerDataObj_MultiSubImage.
        '''
        if not self.puzzle_graph_info.is_puzzle_version_supported():
            return

        puzzle_data = self.puzzle_data

        str_data_top = ('magic_num: 0x%08x user_created: %d music: %s %s%s' %
                        (puzzle_data.magic_num, puzzle_data.is_user_created,
                         self.puzzle_info_obj.get_music_title(
                             puzzle_data.puzzle_info.music),
                         ('' if puzzle_data.backgr_color is None else
                          ' backr_color: 0x%02x' % puzzle_data.backgr_color),
                         ('' if puzzle_data.solution_delay is None else
                          ' solution_delay: %d' % puzzle_data.solution_delay)))

        self.item_info_head = nt_info_puzzle('Puzzle file info', str_data_top)

        self.item_info_extra.append(
            nt_info_puzzle('Puzzle info',
                           namedtuple_to_str(puzzle_data.puzzle_info)))

        if puzzle_data.puzzle_title is not None:
            self.item_info_extra.append(
                nt_info_puzzle('Title', puzzle_data.puzzle_title))

        if puzzle_data.goal_descr is not None:
            self.item_info_extra.append(
                nt_info_puzzle('Goal', puzzle_data.goal_descr))

        if puzzle_data.hints is not None:
            for puzzle_hint in puzzle_data.hints:
                # ?? namedtuple_to_str
                self.item_info_extra.append(
                    nt_info_puzzle('Hint', namedtuple_to_str(puzzle_hint)))

        for part_info_item in self.puzzle_graph_info.get_part_extra_info():
            self.item_info_extra.append(part_info_item)

        if self.parent.get_option(s_opt_raw_part_info):
            self.puzzle_part_raw_info()

        ## self.puzzle_part_info_subclass()

        self.puzzle_solution_info()

    def puzzle_part_raw_info(self):
        '''
        Method for internal use, responsible for the "raw puzzle part data"
            on the "File info" tab if enabled.
        '''
        puzzle_data = self.puzzle_data

        for p_index, puzzle_part in enumerate(puzzle_data.parts):
            self.item_info_extra.append(
                nt_info_puzzle(
                    'Part Info %d, %s (%d)' %
                    (p_index,
                     self.puzzle_info_obj.get_part_name(
                         puzzle_part.part_num), puzzle_part.part_num),
                    'is_moving: %d in_partsbin: %d is_scenery: %d %s' %
                    (puzzle_part.is_moving, puzzle_part.in_partsbin,
                     puzzle_part.is_scenery,
                     part_namedtuple_to_str(puzzle_part,
                                            puzzle_data.game_ver))))

    def puzzle_solution_info(self):
        '''
        Mrthod for generating the solution information that will be displayed
            on the "File info" tab of the GUI. As only TIM 2 + supports this,
            the method in the parent class does nothing.
        '''
        # (TODO, hints are also TIM 2 +)
        pass


class ViewerDataObj_Puzzle_T1(ViewerDataObj_PuzzleBase, StoredDataViewerMixin):
    '''
    ViewerDataObj_PuzzleBase subclass for TIM/TEMIM built-in levels and
        user-made "freeform machines. Also supports displaying .GKC
        intro/credits screen without animation.
    Also inherits StoredDataViewerMixin, which adds methods required for
        displaying graphics for TIM/TEMIM parts that consist of multiple
        sub-images.
    '''

    # Fields modified from parent class
    obj_identifier = s_vdata_puzzle_t1
    obj_description = 'TIM/TEMIM Puzzle'

    sub_item_layers = (
        nt_sub_item_layers(
            'Puzzle', (puzzle_layer_fixed_parts, puzzle_layer_moving_parts,
                       puzzle_layer_foreground)),
        nt_sub_item_layers(
            '"Solution"',
            (puzzle_layer_fixed_parts, puzzle_layer_moving_parts,
             puzzle_layer_parts_bin_parts, puzzle_layer_foreground,
             puzzle_layer_foreground_parts_bin)),
    )

    puzzle_graph_info_obj_name = s_obj_graphinfov1

    # Note: crc32 checks, required by StoredDataViewerMixin are performed in
    #     open_res_callback_t1_crc_check (viewdata/vd_sdata.py)

    def add_sub_image_load_info_subclass(self, load_info):
        '''
        Re-implementation of add_sub_image_load_info_subclass from
            ViewerDataObj_PuzzleBase
        load_info: One data namedtuple from
            self.puzzle_graph_info.get_image_load_info,
            (type: nt_graphics_info_t1)
        '''

        if load_info.extra_img is not None: return

        if load_info.file_name is None:
            self.add_sub_image_load_info_s_data_index(load_info.sub_img_id,
                                                      load_info.flip)
        else:
            self.add_single_sub_image_load_info(load_info.file_name,
                                                load_info.sub_img_id,
                                                load_info.flip)

    def add_new_img_curr_frame_subclass(self, img_info):
        '''
        Re-implementation of add_new_img_curr_frame_subclass from
            ViewerDataObj_PuzzleBase
        img_info: One data namedtuple from
            self.puzzle_graph_info.get_frame_images_info,
            (type: nt_graphics_info_t1)
        '''
        if img_info.extra_img is not None:
            self.add_single_sub_img_data_special(img_info.extra_img,
                                                 img_info.pos_rel_x,
                                                 img_info.pos_rel_y)
        elif img_info.file_name is None:
            self.add_new_img_curr_frame_s_data_index(
                img_info.sub_img_id, img_info.pos_rel_x, img_info.pos_rel_y,
                img_info.flip, img_info.flip_axis_x, img_info.flip_axis_y)
        else:
            # Note: flip_right_bottom must be True in order to "simulate"
            #     the way the game engine flips the part graphics
            self.add_new_img_curr_frame(img_info.file_name,
                                        img_info.sub_img_id, img_info.flip,
                                        img_info.pos_rel_x, img_info.pos_rel_y,
                                        True)


# Strings for solution types. TODO, this should be moved to a
#     more logical place/module (?) See also decoder.d_puzzle for more details

sol_type_strs = ('None', 'Part State', 'Position', 'Off Screen', 'Off Top',
                 'Off Bottom')

# Constants for solution types, TODO, should be moved (?)

t2_sol_type_part_state = 1
t2_sol_type_position = 2


class ViewerDataObj_Puzzle_T2(ViewerDataObj_PuzzleBase, AnmFramesViewerMixin):
    '''
    ViewerDataObj_PuzzleBase subclass for TIM 2 (and TIM 3) built-in levels
        and user-made puzzles.
    Also inherits AnmFramesViewerMixin, which adds methods required for
        displaying
        the corresponding frames in the animation (.ANM) files.
    '''
    # Fields modified from parent class
    obj_identifier = s_vdata_puzzle_t2
    obj_description = 'TIM 2/3 Puzzle'

    sub_item_layers = (
        nt_sub_item_layers(
            'Puzzle (no scenery)',
            (puzzle_layer_fixed_parts, puzzle_layer_moving_parts,
             puzzle_layer_foreground)),
        nt_sub_item_layers(
            'Puzzle', (puzzle_layer_scenery_background, puzzle_layer_scenery,
                       puzzle_layer_fixed_parts, puzzle_layer_moving_parts,
                       puzzle_layer_foreground)),
        nt_sub_item_layers(
            'Solution (no scenery)',
            (puzzle_layer_fixed_parts, puzzle_layer_moving_parts,
             puzzle_layer_parts_bin_parts, puzzle_layer_foreground,
             puzzle_layer_foreground_parts_bin)),
        nt_sub_item_layers(
            'Solution', (puzzle_layer_scenery_background, puzzle_layer_scenery,
                         puzzle_layer_fixed_parts, puzzle_layer_moving_parts,
                         puzzle_layer_parts_bin_parts, puzzle_layer_foreground,
                         puzzle_layer_foreground_parts_bin)),
    )

    puzzle_graph_info_obj_name = s_obj_graphinfov2

    def reset_data_subclass(self):
        '''
        Re-implementation of reset_data_subclass from ViewerDataObj_PuzzleBase
        '''
        ViewerDataObj_PuzzleBase.reset_data_subclass(self)
        # Do not keep ANM file data stored for previously loaded puzzles
        self.reset_anim_file_data()

    def add_sub_image_load_info_subclass(self, load_info):
        '''
        Re-implementation of add_sub_image_load_info_subclass from
            ViewerDataObj_PuzzleBase
        load_info: One data namedtuple from
            self.puzzle_graph_info.get_image_load_info,
            (type: nt_graphics_info_t2)
        '''

        # Note: None is not a valid value for load_info.file_name in
        #     ViewerDataObj_Puzzle_T2

        if load_info.extra_img is None:
            self.add_sub_image_load_info_anm_index(load_info.file_name,
                                                   load_info.anm_frame_id,
                                                   load_info.flip)

    def add_new_img_curr_frame_subclass(self, img_info):
        '''
        Re-implementation of add_new_img_curr_frame_subclass from
            ViewerDataObj_PuzzleBase
        img_info: One data namedtuple from
            self.puzzle_graph_info.get_frame_images_info,
            (type: nt_graphics_info_t2)
        '''
        if img_info.extra_img is None:
            self.add_new_img_curr_frame_s_data_index(
                img_info.file_name, img_info.anm_frame_id, img_info.pos_rel_x,
                img_info.pos_rel_y, img_info.flip, img_info.flip_axis_x,
                img_info.flip_axis_y, img_info.alternative_flip)
        else:
            self.add_single_sub_img_data_special(img_info.extra_img,
                                                 img_info.pos_rel_x,
                                                 img_info.pos_rel_y)

    def puzzle_solution_info(self):
        '''
        Re-implementation of puzzle_solution_info from
            ViewerDataObj_PuzzleBase.
        '''

        puzzle_data = self.puzzle_data

        if puzzle_data.solution is not None:
            for puzzle_sol in puzzle_data.solution:
                puzzle_part = puzzle_data.parts[puzzle_sol.part_index]
                part_num = puzzle_part.part_num

                solution_info = [
                    'part: (%d) %s' %
                    (puzzle_sol.part_index,
                     self.puzzle_info_obj.get_part_name(part_num))
                ]

                if puzzle_sol.part_count:
                    solution_info.append(
                        'part_count: %d' % puzzle_sol.part_count)

                if puzzle_sol.sol_type == t2_sol_type_part_state:
                    # Note: The .ANM file should have been already decoded at
                    #     this point, so ANM data "cached" by
                    #     AnmFramesViewerMixin will be returned
                    anm_data = self.decode_anm_file(
                        name_pattern_res_anm % part_num)

                    part_state_id = None
                    state_str = None

                    # Look up part_state_1 in the C section of .ANM data

                    for sect_c_item in anm_data.anm_data_c:
                        if ((sect_c_item.first_frame_id ==
                             puzzle_sol.part_state_1)):
                            part_state_id = sect_c_item.part_state_id
                            break

                    if part_state_id is not None:
                        state_str = self.puzzle_info_obj.\
                            get_solution_part_state_text(
                                part_num, part_state_id)

                    solution_info.append(
                        'state: %s (%d %d)' %
                        (state_str or '(unknown)', puzzle_sol.part_state_1,
                         puzzle_sol.part_state_2))

                elif puzzle_sol.sol_type == t2_sol_type_position:
                    # TEMPORARY, makes assumption on iotem numbering in
                    #     the namedtuple
                    solution_info.append(
                        ('target_x: %d target_y: %d target_width: %d '
                         'target_height: %d') % puzzle_sol[-4:])

                self.item_info_extra.append(
                    nt_info_puzzle(
                        'Solution,  %s' % sol_type_strs[puzzle_sol.sol_type],
                        ' '.join(solution_info)))

        if self.parent.get_option(s_opt_raw_part_info):
            self.puzzle_solution_info_raw()

    def puzzle_solution_info_raw(self):
        '''
        Method for internal use, adds the puzzle solution information in a
            "raw" format (direct conversion of the namedtuples form the
            decoder). Shown only when "raw part info" is enabled.
        '''
        if self.puzzle_data.solution is not None:
            for puzzle_sol in self.puzzle_data.solution:
                self.item_info_extra.append(
                    nt_info_puzzle(
                        'Solution Info, %s' %
                        sol_type_strs[puzzle_sol.sol_type],
                        namedtuple_to_str_part(puzzle_sol, 1)))
