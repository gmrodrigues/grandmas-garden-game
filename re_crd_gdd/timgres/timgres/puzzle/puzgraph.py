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
from timgres.base.basecl import ResDataItemBase
from timgres.base.misc import (s_opt_zoom, s_opt_flip, s_opt_no_puzzle_backgr,
                               s_obj_pngshapedraw16, print_msg,
                               print_traceback)
from timgres.base.pngexp import png_sign
from timgres.base.vdobase import (nt_size, _num_list_to_str_nosp)
'''
This module contains the base classes for implementing puzzle viewing.
    PartGraphicsInfoBase for implementing parts, PuzzleGraphicsInfoBase for
    implementing viewing for one or more game versions as well as mixin
    classes for part types that behave similarly between versions.
'''

# nt_info_puzzle: Temporary  namedtuple for puzzle viewing
# (was: nt_sub_item_info_puzzle_temp) Temporary namedtuple obj for testing
nt_info_puzzle = namedtuple('nt_info_puzzle', ('item_text', 'info'))

# Layers for puzzle graphics. The purpose of this is to ensure z-order
#      and to allow some layers switched off.
# NOTE: could use enum, however enum is not available on Python 2.7

puzzle_layer_background = 0
puzzle_layer_scenery_background = 1
puzzle_layer_scenery = 2
puzzle_layer_fixed_parts = 3
puzzle_layer_moving_parts = 4
puzzle_layer_parts_bin_parts = 5
puzzle_layer_foreground = 6
puzzle_layer_foreground_parts_bin = 7

# nt_field_layer_number: Namedtuples returned by get_frame_images_info
#     in PartGraphicsInfoBase subclasses
nt_field_layer_number = 'layer_number'

# part_numbers_foreground: Contains the part numbers of foreground
#     parts. Note: part #76 is only valid in TIM 2
# Note: 8: belt, 10: rope, 76: steel cable
part_numbers_foreground = (8, 10, 76)


def layer_for_part(part_info):
    '''
    Returns the layer number a prt belongs to (One of puzzle_layer_*)
        constants (type: int).
    part_info: A part info object class (see d_puzzle,py)
    '''
    if part_info.part_num in part_numbers_foreground:
        return (puzzle_layer_foreground_parts_bin
                if part_info.in_partsbin else puzzle_layer_foreground)
    elif part_info.is_scenery:
        return puzzle_layer_scenery
    elif part_info.in_partsbin:
        return puzzle_layer_parts_bin_parts
    elif part_info.is_moving:
        return puzzle_layer_moving_parts
    else:
        return puzzle_layer_fixed_parts


def int_16_to_2_bytes(uint16):
    '''
    Private helper function, converts an int (uint16, int) in range
        -32768..32767 to two bytes. Returns a tuple of 2 ints.
    '''
    # Note: & 0xffff is required to force the result unsigned!
    return uint16 & 0xff, ((uint16 & 0xffff) >> 8)


str_not_impl_PartGraphicsInfoBase = 'Not implemented in PartGraphicsInfoBase'


class PartGraphicsInfoBase(object):
    '''
    PartGraphicsInfoBase is an abstract base class for implementing "part
        graphics info" subclasses. These classes provide methods that
        processes the raw data from puzzle decode from each part to
        namedtuples or lists that can be used directly by a
        level viewer class, a subclass of ViewerDataObj_MultiSubImage
        (and ....)
    Objects of PartGraphicsInfoBase subclasses are stored in an
        associated PuzzleGraphicsInfoBase "parent" object. The methods of
        this parent object are in turn called from the level viewer object.
    '''

    def __init__(self, part_num):
        '''
        The constructor of the class. Requires one argument. Note that
            constructors of sub-classes can have extra argument.
            part_num: int, the part number this class or object is associated
            with. None for "generic"/"fallback" objects.
        part_num (int or None): The part number associated iwth the class
            or None if this class processes multiple types of parts
        '''
        self.part_num = part_num
        # puzzle_graph_info: A PuzzleGraphicsInfoBase subclass
        #     associated with the game version
        self.puzzle_graph_info = None

    def set_puzzle_graph_info(self, new_obj):
        '''
        Sets the "parent object" (type: the associated PuzzleGraphicsInfoBase
            subclass).
        new_obj: The "parent object"
        '''
        self.puzzle_graph_info = new_obj

    def get_image_load_info(self, puzzle_part):
        '''
        Not implemented in PartGraphicsInfoBase. A re-implementation in a
            sub-class must return a list of game version specific namedtuples
             that provide information required for implementing
            set_sub_image_load_info in the level viewer class.
        puzzle_part: The "raw" information for the current part from the
            information returned by the level decoder. A namedtuple subclass,
            see d_puzzle.py
        '''
        raise NotImplementedError(str_not_impl_PartGraphicsInfoBase)

    def get_frame_images_info(self, puzzle_part):
        '''
        Not implemented in PartGraphicsInfoBase. A re-implementation in a
            sub-class must return a list of game version specific namedtuples
            that provide information required for implementing set_frame_data
            in the level viewer class. Such a namedtuple must always contain
            a layer_number field.
        puzzle_part: The "raw" information for the current part,
            see get_image_load_info
        '''
        raise NotImplementedError(str_not_impl_PartGraphicsInfoBase)

    def get_part_extra_info(self, puzzle_part, part_index):
        '''
        Default implementation for get_part_extra_info. Moved to the "parent"
            class due to the similarities of TIM / TIM 2 part info
            namedtuples. In addition, the sme type (nt_info_puzzle) is used
            as return value.
        puzzle_part: The "raw" information for the current part,
            see get_image_load_info (in current version nt_info_puzzle)
        part_index: The index odf the part in level file (int)
        '''
        # TODO, copied from PartGraphicsInfo_T1_Simple

        return (nt_info_puzzle(
            'Part %d, %s (%d)' %
            (part_index,
             self.puzzle_graph_info.puzzle_info_obj.get_part_name(
                 puzzle_part.part_num), puzzle_part.part_num),
            ('is_moving: %d in_partsbin: %d is_scenery: %d '
             'pos_x: %d pos_y: %d width: %d height: %d %s') %
            (puzzle_part.is_moving, puzzle_part.in_partsbin,
             puzzle_part.is_scenery, puzzle_part.pos_x, puzzle_part.pos_y,
             puzzle_part.width_1, puzzle_part.height_1,
             self.get_part_specific_info(puzzle_part))), )

        # TODO, width_2 and height_2?

    def get_part_specific_info(self, puzzle_part):
        '''
        Returns a formatted string, containing information of the
            current part that is only relevant for some types of parts.
        puzzle_part: The "raw" information for the current part,
            namedtuple subclass, see d_puzzle.py
        '''
        # By defailt, returns empty string
        return ''

    def new_puzzle_loaded(self):
        '''
        A "placeholder" method that can be used for some part type specific
            action that is executed when a new puzzle file is opened/viewed.
            One possible usage is for clearing fields in the class that
            store for the previously opened puzzle. It is called on a
            per-object (in the parent PuzzleGraphicsInfo class), not
            per-part basis. By default it does nothing.
        '''
        pass

    def new_puzzle_loaded_part_action(self, puzzle_part):
        '''
        A "placeholder" method that can be used for some part type specific
            action that is executed when a new puzzle file is opened. Unlike
            new_puzzle_loaded, but similarly to get_image_load_info/
            get_frame_images_info it has a puzzle_part argument and is called
            for each part in the puzzle. By default it does nothing.
        puzzle_part: The "raw" information for the current part,
            see get_image_load_info
        '''
        pass


# --- The PuzzleGraphicsInfoBase base class ---

str_not_impl_PuzzleGraphicsInfoBase = ('Not implemented in '
                                       'PuzzleGraphicsInfoBase')

# nt_part_counts: Namedtuple, returned by
#     PuzzleGraphicsInfoBase.part_counts_in_layers()
# All four members are ints and refer to fields in part info objects
#     (see d_puzzle.py)

nt_part_counts = namedtuple(
    'nt_part_counts',
    ('count_all', 'count_moving', 'count_in_partsbin', 'count_scenery'))

# Extension for "stored images", case sensitive on Unix-based systems.
stored_image_ext = '.png'


class PuzzleGraphicsInfoBase(ResDataItemBase):
    '''
    PuzzleGraphicsInfoBase serves as a base class for implementing "puzzle
        graphics info" classes for specific game versions. The purpose of
        such classes is to process  the raw data from puzzle decoding and to
        provide data for displaying parts in a puzzle/level file using a
        ViewerDataObj_MultiSubImage subclass(....)
        Subclasses store several
        objects (type is a PartGraphicsInfoBase) that deal with specific
        puzzle parts.
    '''
    # supported_verisons: The game versions supported, tuple must
    #      contain version constants defined in puzdata.py
    # Must be modified in sub-classes.
    supported_verisons = ()

    # part_object_types: Must be modified in sub-classes. List/tuple
    #     of tuples, first item of an inner tuple is the part number
    #     for a part requiring separate treatment, the second item
    #     is the type (PartGraphicsInfoBase), further items are passed to
    #     the constructor of sub_class.
    part_object_types = ()

    # part_object_default_type. Must be modified in sub-classes.
    #     Value must be a type, more precisely a PartGraphicsInfoBase
    #     subclass.
    part_object_default_type = None

    # puzzle_info_obj_name: Name of the associated puzzle info object
    #     (PuzzleInfoBase subclass), see puzdata.py.
    #     Must be modified in sub-class.
    puzzle_info_obj_name = ''

    # puzzle_screen_size: Size of puzzle screen, must be modified in
    #     sub-classes. Type: nt_size
    puzzle_screen_size = nt_size(-1, -1)

    def __init__(self):
        '''Constructor of the class. Requires no argument.'''
        ResDataItemBase.__init__(self)
        self.reset_puzzle_data()

        # part_objs: dictionary key: part number, value: a game version
        #     specific PartGraphicsInfoBase subclasses
        self.part_objs = {}

        for part_obj_info in self.part_object_types:
            part_num, part_obj_type = part_obj_info[:2]
            part_obj = part_obj_type(part_num, *part_obj_info[2:])
            part_obj.set_puzzle_graph_info(self)
            self.part_objs[part_num] = part_obj

        # part_obj_default: returned by get_part_obj_by_number if the part
        #     number is valid according to the data in self.puzzle_info_obj
        #     but not in self.part_objs
        self.part_obj_default = self.part_object_default_type(None)
        self.part_obj_default.set_puzzle_graph_info(self)

    def reset_puzzle_data(self):
        '''
        Resets all fields containing information about the loaded puzzle.
        '''
        # puzzle_info_obj: A PuzzleInfoT1/PuzzleInfoT2 object, retrieved
        #     from parent. Note that this cannot be done in constructor.
        self.puzzle_info_obj = None
        # puzzle_data: nt_puzzle_data returned by the puzzle decoder.
        self.puzzle_data = None
        # png_shape_draw: The PngShapeDraw_4BPP object from parent
        self.png_shape_draw = None

    def set_puzzle_data(self, new_puzzle_data):
        '''
        Must be called after decoding a puzzle file. Set puzzle data fields.
        new_puzzle_data: A PuzzleInfoT1/PuzzleInfoT2 object, retrieved
            from parent. Note that th
        '''
        # Note: this cannot be done from the constructor
        self.puzzle_info_obj = self.parent.get_object(
            self.puzzle_info_obj_name)

        self.puzzle_data = new_puzzle_data

        self.png_shape_draw = self.parent.get_object(s_obj_pngshapedraw16)

        if self.puzzle_data.game_ver not in self.supported_verisons:
            return  # FIXME

        self.puzzle_info_obj.set_game_version(self.puzzle_data.game_ver)

        # NOTE: the order in which new_puzzle_loaded is called for the
        #     part_objs objects is not "deterministic"
        for part_obj in self.part_objs.values():
            part_obj.new_puzzle_loaded()

        self.part_obj_default.new_puzzle_loaded()

        # After new_puzzle_loaded, call new_puzzle_loaded_part_action
        for part in self.puzzle_data.parts:
            self.get_part_obj_by_number(
                part.part_num).new_puzzle_loaded_part_action(part)

    def get_game_version(self):
        '''
        Must be called after set_puzzle_data. Returns game version (int,
            one of the game_ver_* constants (puzzle/puz_data.py)
        '''
        return self.puzzle_data.game_ver

    def is_puzzle_version_supported(self):
        '''
        Must be called after set_puzzle_data. Returns bool (True if puzzle
            file verion is supported)
        '''
        return self.puzzle_data.game_ver in self.supported_verisons

    def get_puzzle_info_obj(self):
        '''
        Returns the associated PuzzleInfo object (see puzdata.py) or
            None if not available (type: PuzzleInfoBase subclass)
        '''
        return self.puzzle_info_obj

    def get_puzzle_screen_size(self):
        '''
        Returns the puzzle screen size associated with the subclass.
        Return type: nt_size
        '''
        return self.puzzle_screen_size

    def get_part_obj_by_number(self, part_number):
        '''
        The default implementation returns an item from self.part_objs by
            number or self.part_obj_default if the number is valid according
            to the data in self.puzzle_info_obj, but not in self.part_objs.
            (TODO) May be re-implemented in subclasses to support
            PartGraphicsInfo objects handling multiple part types.
        '''
        part_graph_info_obj = self.part_objs.get(part_number)

        if part_graph_info_obj is not None:
            return part_graph_info_obj
        elif self.puzzle_info_obj.get_part_name(part_number) is not None:
            return self.part_obj_default
        else:
            raise RuntimeError('Invalid part number %d' % part_number)

    def get_part(self, index):
        '''
        Returns the "raw data" for part at "index" (type: int) from
            self.puzzle_data.
        Return type: A namedtuple subclass, see d_puzzle.py
        '''
        if index < 0:  # Do not accept negative indices
            raise ValueError('get_part: Invalid index')

        return self.puzzle_data.parts[index]

    def get_background_fill_image(self):
        '''
        Not implemented in PuzzleGraphicsInfoBase. When re-implemented in a
            sub-class, must return the namedtuple used by the
            get_image_load_info method of the associated PartGraphicsInfo
            objects.
        '''
        raise NotImplementedError(str_not_impl_PuzzleGraphicsInfoBase)

    def get_image_load_info(self):
        '''
        Retrieves the "image load information" for all parts in the opened
            puzzle using the PartGraphicsInfo objects. Calls the
            get_image_load_info in the object corresponding to each part,
            and concatenates the result into a list. Returns list of a game
            version specific namedtuple.
        '''

        return list(
            itertools.chain.from_iterable(
                self.get_part_obj_by_number(part.part_num).get_image_load_info(
                    part) for part in self.puzzle_data.parts))

    def get_frame_images_info(self):
        '''
        Retrieves the "image frame information" for all parts in the opened
            puzzle using the PartGraphicsInfo objects. Calls the
            get_frame_images_info in the object corresponding to each part,
            and concatenates the result into a list. Returns list of a game
            version specific namedtuple. Also adds an extra item for
            the puzzle_background if needed
        '''
        frame_imgs_iter_1 = itertools.chain.from_iterable(
            self.get_part_obj_by_number(part.part_num).get_frame_images_info(
                part) for part in self.puzzle_data.parts)

        if self.parent.get_option(s_opt_no_puzzle_backgr):
            return list(frame_imgs_iter_1)
        else:
            return list(
                itertools.chain((self.get_background_fill_image(), ),
                                frame_imgs_iter_1))

    def get_part_extra_info(self):
        '''
        Retrieves the "image load information" for all parts in the opened
            puzzle using the PartGraphicsInfo objects. Calls the
            get_part_extra_info in the object corresponding to each part,
            and concatenates the result into a list. Returns list of a game
            version specific namedtuple.
        '''
        return list(
            itertools.chain.from_iterable(
                self.get_part_obj_by_number(part.part_num).get_part_extra_info(
                    part, part_index)
                for part_index, part in enumerate(self.puzzle_data.parts)))

    def part_counts_in_layers(self, layers):
        '''
        Returns the part counts for layers specified as argument "layers".
        Result is nt_part_Counts namedtuple.
        layers: tuple or list of puzzle_layer_* constants
        '''
        # TODO, revise counts
        count_all = 0
        count_moving = 0
        count_in_partsbin = 0
        count_scenery = 0

        for puzzle_part in self.puzzle_data.parts:
            part_layer = layer_for_part(puzzle_part)

            if part_layer in layers:
                count_all += 1

                if puzzle_part.is_moving:
                    count_moving += 1

                if puzzle_part.in_partsbin:
                    count_in_partsbin += 1

                if puzzle_part.is_scenery:
                    count_scenery += 1

        return nt_part_counts(count_all, count_moving, count_in_partsbin,
                              count_scenery)


# --- "Mixin" classes for implementing specific parts in ---
# ---     both supported game versions ---

# Note on similarities in walls and belts between TIM 1 and TIM 2:
#     Similarly to ropes, these parts work largely the same way in
#     both versions. However, there are several subtle differences.
# It would be possible to find a largest** common denominator for these,
#     and write common classes/subroutines accordingly, but this would
#     only complicate things.
# For walls, there is a common helper function, wall_coords_check

# nt_part_index_data: For internal storage of part numbers & corresponding
#     data in PartGraphicsInfoRopeMixin.
# part_index: int, the index of part
# part_data: PartInfoT1, the namedtuple subclass  returned by
#     self.puzzle_graph_info.get_part
nt_part_index_data = namedtuple('nt_part_index_data',
                                ('part_index', 'part_data'))

# nt_rope_line_segment_data: A namedtuple containing the information returned
#     by function get_rope_segments_list in PartGraphicsInfoRopeMixin.
#     (the function returns a list of these namedtuples.)
# start_x, start_y: x and y coordinates of the start of the segment (int)
# end_x, end_y: x and y coordinates of the end of the segment (int)

nt_rope_line_segment_data = namedtuple(
    'nt_rope_line_segment_data', ('start_x', 'start_y', 'end_x', 'end_y'))

# Part numbwer for the pulley part, same in all supported versions.
part_number_pulley = 7

str_warn_rope_params = ('WARNING: Rope with invalid parameters found, '
                        'part will not be shown.')

str_warn_pulley_connect = ('WARNING: Inconsistent connection data '
                           'for pulley, corresponding rope will not be shown.')


class PartGraphicsInfoRopeMixin(object):
    '''
    A mixin for implementing PartGraphicsInfoBase subclasses for ropes
        in the two "major game versions" (TIM & TEMIM, TIM2 & TIM3).
        Ropes behave very similarly in the two game versions.
    '''

    def find_pulleys(self, first_part_index, one_conn_part_index):
        '''
        Method for internal use. Returns a list of nt_part_index_data.
            The last item corresponds to the part at the "other" end of the
            rope (always different from one_conn_part_index). This can be
            preceded by entries for the pulleys in-between (if there are any).
        first_part_index: The index of the first of the two parts connected
            by te current loop.
        one_conn_part_index: Index of one of the at most two parts
            part first_part_index is connected to.
        '''
        # NOTE: If one_conn_part_index corresponds to a part with two
        #     ropes connected, first_part_index can be a part with
        #     a different rope connected.
        out_data = []
        part_index = one_conn_part_index
        prev_index = first_part_index

        # TODO, in TIM 2, field (???) contains the index of the rope part,
        #     check should be added for this later (but not a high priority)

        while True:
            part_data = self.puzzle_graph_info.get_part(part_index)

            out_data.append(nt_part_index_data(part_index, part_data))

            if part_data.part_num != part_number_pulley:
                return out_data

            # If this was a pulley, continue with next part

            if ((prev_index != part_data.connected_1)
                    and (part_data.connected_1 >= 0)):
                prev_index = part_index
                part_index = part_data.connected_1
            else:
                prev_index = part_index
                part_index = part_data.extra_data_1.connect_pulley_2

            if part_index < 0:
                return None

    def get_connected_parts_list(self, puzzle_part):
        '''
        Method for implementing PartGraphicsInfoBase subclasses for ropes and
            related parts. Returns a list of nt_part_index_data. The first and
            the last items correspond to the two parts connected by the rope.
            The list may contain extra entries between the two,
            corresponding to pulleys.
        puzzle_part: PartInfoT1/PartInfoT2 for the rope.
        '''

        # TODO: The information in extra_data_1.temp_0 could be used for
        #     simplifying this function (?)

        index_part_1 = puzzle_part.rope_index_connected_1
        index_part_2 = puzzle_part.rope_index_connected_2

        if index_part_1 >= 0:

            if index_part_2 < 0:
                # Only one end of rope connected but not the other (?)
                print_msg(str_warn_rope_params)
                return []

            # NOTE: It is possible that an other rope is connected to the part
            #     with index index_part_1 (part at one end of current
            #     rope). Try the first connected part (to index_part_1)
            #     first, and check the last item in the list returned by
            #     find_pulleys. If the part index matches the index of the
            #     part at the other end of this rope, use that. If not, re-try
            #     with the second connected part (to index_part_1).

            part_data = self.puzzle_graph_info.get_part(index_part_1)

            if part_data.connected_1 >= 0:
                out_list_part_1 = self.find_pulleys(index_part_1,
                                                    part_data.connected_1)

                if out_list_part_1 is None:
                    print_msg(str_warn_t1_pulley_connect)
                    return []

                # Is this the part we need?
                if out_list_part_1[-1].part_index == index_part_2:
                    return ([nt_part_index_data(index_part_1, part_data)] +
                            out_list_part_1)

            if part_data.connected_2 >= 0:
                out_list_part_2 = self.find_pulleys(index_part_1,
                                                    part_data.connected_2)

                if out_list_part_2 is None:
                    print_msg(str_warn_t1_pulley_connect)
                    return []

                # Is this the part we need? (FIXME, duplication)
                if out_list_part_2[-1].part_index == index_part_2:
                    return ([nt_part_index_data(index_part_1, part_data)] +
                            out_list_part_2)

        elif index_part_2 >= 0:
            # Only one end of rope connected but not the other (?)
            print_msg(str_warn_rope_params)

        return []  # TODO

    def get_rope_segments_list(self, puzzle_part):
        '''
        Method for implementing PartGraphicsInfoBase subclasses for ropes and
            related parts. Returns a list of nt_rope_line_segment_data.
            The items of the list correspond to one rope segment to be drawn.
            start_* of the first item and end_* of the last item will
            be also used for the rope end (kont) graphics.
        Returns empty list on failure, otherwise, the output always contains
            at least one item.
        puzzle_part: PartInfoT1/PartInfoT2 for the rope.
        '''
        conn_list = self.get_connected_parts_list(puzzle_part)

        if len(conn_list) < 2:
            return []

        # NOTE: It is possible that two ropes are connected to one or both
        #     parts corresponding to the first and the last items in conn_list

        # NOTE: check for a value of -1 in connected_1/connected_2 is
        #     not needed (??)

        index_part_1 = puzzle_part.rope_index_connected_1
        index_part_2 = puzzle_part.rope_index_connected_2

        if conn_list[0].part_data.connected_1 == conn_list[1].part_index:
            part_1_conn_x, part_1_conn_y = int_16_to_2_bytes(
                conn_list[0].part_data.rope_info_1)
        elif conn_list[0].part_data.connected_2 == conn_list[1].part_index:
            part_1_conn_x, part_1_conn_y = int_16_to_2_bytes(
                conn_list[0].part_data.rope_info_2)
        else:
            print_msg(str_warn_t1_pulley_connect)  # TODO, message
            return []

        if conn_list[-1].part_data.connected_1 == conn_list[-2].part_index:
            part_2_conn_x, part_2_conn_y = int_16_to_2_bytes(
                conn_list[-1].part_data.rope_info_1)
        elif conn_list[-1].part_data.connected_2 == conn_list[-2].part_index:
            part_2_conn_x, part_2_conn_y = int_16_to_2_bytes(
                conn_list[-1].part_data.rope_info_2)
        else:
            print_msg(str_warn_t1_pulley_connect)  # TODO, message
            return []

        prev_index = index_part_1
        pos_start_x = conn_list[0].part_data.pos_x + part_1_conn_x
        pos_start_y = conn_list[0].part_data.pos_y + part_1_conn_y
        pos_last_x = conn_list[-1].part_data.pos_x + part_2_conn_x
        pos_last_y = conn_list[-1].part_data.pos_y + part_2_conn_y

        out_segments = []

        for pulley_index, pulley_data in conn_list[1:-1]:

            if ((prev_index != pulley_data.connected_1)
                    and (pulley_data.connected_1 >= 0)):
                pulley_conn_start_x, pulley_conn_start_y = int_16_to_2_bytes(
                    pulley_data.extra_data_1.rope_info_pulley_2)
                pulley_conn_end_x, pulley_conn_end_y = int_16_to_2_bytes(
                    pulley_data.rope_info_1)
            elif pulley_data.extra_data_1.connect_pulley_2 >= 0:
                pulley_conn_start_x, pulley_conn_start_y = int_16_to_2_bytes(
                    pulley_data.rope_info_1)
                pulley_conn_end_x, pulley_conn_end_y = int_16_to_2_bytes(
                    pulley_data.extra_data_1.rope_info_pulley_2)
            else:
                print_msg(str_warn_t1_pulley_connect)
                return []

            pos_end_x = pulley_data.pos_x + pulley_conn_start_x
            pos_end_y = pulley_data.pos_y + pulley_conn_start_y

            out_segments.append(
                nt_rope_line_segment_data(pos_start_x, pos_start_y, pos_end_x,
                                          pos_end_y))

            prev_index = pulley_index
            pos_start_x = pulley_data.pos_x + pulley_conn_end_x
            pos_start_y = pulley_data.pos_y + pulley_conn_end_y

        out_segments.append(
            nt_rope_line_segment_data(pos_start_x, pos_start_y, pos_last_x,
                                      pos_last_y))

        return out_segments

    def get_rope_layer(self, puzzle_part):
        '''
        Method for implementing PartGraphicsInfoBase subclasses for ropes and
            related parts. Returns the appropriate layer for the part
            (type: int)
        '''
        index_part_1 = puzzle_part.rope_index_connected_1
        index_part_2 = puzzle_part.rope_index_connected_2
        part_data_1 = self.puzzle_graph_info.get_part(index_part_1)
        part_data_2 = self.puzzle_graph_info.get_part(index_part_2)

        if part_data_1.in_partsbin or part_data_2.in_partsbin:
            return puzzle_layer_foreground_parts_bin
        else:
            return layer_for_part(puzzle_part)

    def get_rope_info_str(self, puzzle_part):
        '''
        Method for implementing PartGraphicsInfoBase subclasses for ropes and
            related parts. Intended to be used in method
            get_part_specific_info.
        puzzle_part: PartInfoT1/PartInfoT2 for the rope.
        '''
        conn_list = self.get_connected_parts_list(puzzle_part)

        if len(conn_list) < 2:
            return ''

        if len(conn_list) > 2:
            info_pulleys = ' pulleys: ' + _num_list_to_str_nosp(
                x.part_index for x in conn_list[1:-1])
        else:
            info_pulleys = ''

        return 'connected_part_1: %d connected_part_2: %d%s' % (
            puzzle_part.rope_index_connected_1,
            puzzle_part.rope_index_connected_2, info_pulleys)


class PartGraphicsInfElectricOutletMixin(object):
    '''
    A mixin for implementing PartGraphicsInfoBase subclasses for electric
        outletsin the "major game versions" (TIM & TEMIM, TIM2 & TIM3).
    '''

    def get_electric_outlet_appearance(self, puzzle_part, frame_number):
        '''
        Method for implementing PartGraphicsInfoBase subclasses for electric
            routlets and elated parts. Intended to be used in method
            get_part_specific_info.
        puzzle_part: PartInfoT1/PartInfoT2 for the rope.
        frame_number: The frame number found in the puzzle file, typically
            the "appearance" field.
        '''

        # Note: frame_info_index can also be interpreted as a flag parameter
        #     with three bit flags, bit 0 is 1 when a plug is shown in the
        #     upper position, bit 1 is 1 when a plug is shown in the other
        #     position, while bit 2 is only used for the outlet with
        #     switch and corresponds to the position of the switch. (TODO)

        # Check whether the connected parts are placed to the parts bin
        #     and clear the corresponding bits. Can also set the bits
        #     if frame_number is 0 but it should not

        frame_number_out = frame_number

        if not puzzle_part.in_partsbin:
            connected_1 = puzzle_part.connected_3
            connected_2 = puzzle_part.connected_4

            if connected_1 > 0:
                if (self.puzzle_graph_info.get_part(connected_1).in_partsbin):
                    frame_number_out &= ~1
                elif (frame_number & 1) == 0:
                    frame_number_out |= 1  # HACK

            if connected_2 > 0:
                if (self.puzzle_graph_info.get_part(connected_2).in_partsbin):
                    frame_number_out &= ~2
                elif (frame_number & 2) == 0:
                    frame_number_out |= 2  # HACK

        return frame_number_out


# Height for vertical, width for horizontal walls
wall_part_thickness = 16
# Minimum length (height or width) of horizontal/vertical wall
wall_part_min_length_horiz = 16
wall_part_min_length_vert = 32

str_warn_wall_params = ('WARNING: Wall with invalid parameters found, '
                        'part will not be shown.')


def wall_coords_check(puzzle_part, thickness):
    '''
    Performs some basic checks for the coordinates and width/height of
        a wall part. Returns true if the data is valid, otherwise
        prints a warning and returns False.
    Note that thickness is an argument, because it is also used for some
        "non-wall" parts (notably, "large pipe" in TIM 2)
    puzzle_part: PartInfoT1/PartInfoT2 for the wall.
    thickness: the smaller side for the wall part. (int)
    '''

    if ((puzzle_part.width_1 != puzzle_part.width_2)
            or (puzzle_part.height_1 != puzzle_part.height_2)
            or ((puzzle_part.pos_x & 0xf) != 0x8)
            or ((puzzle_part.pos_y & 0xf) != 0x8)):  # ???
        print_msg(str_warn_wall_params)
        return False

    if puzzle_part.height_1 == thickness:
        # Horizontal wall
        # TODO: In TIM 1, 16 pixel (one tile) wide seems to be possible for
        #     "brick" and "dirt" walls, but not for "wood" and "pipe" ?
        # Currently, if both sides are equal to thickness, the part
        #     is considered a "valid" horizontal wall
        # Note: puzzle_part.width_1 & 0xf -> not divisible by 16
        if ((puzzle_part.width_1 < wall_part_min_length_horiz)
                or (puzzle_part.width_1 & 0xf)):
            print_msg(str_warn_wall_params)
            return False
        else:
            return True
    elif puzzle_part.width_1 == thickness:
        # Vertical wall
        if ((puzzle_part.height_1 < wall_part_min_length_vert)
                or (puzzle_part.height_1 & 0xf)):
            print_msg(str_warn_wall_params)
            return False
        else:
            return True
    else:
        print_msg(str_warn_wall_params)
        return False


# --- "Helper" class for implementing TIM 2 "wall join" graphics ---

str_warn_wall_coords = (
    'WARNING: Invalid wall coordinates detected in PuzleWallsInfo. '
    'Puzzle seems to contain colliding walls (?).')


class PuzzleWallsInfo(object):
    '''
    A PuzleWallsInfo object stores information about wall parts in a TIM
        (specifically, TIM 2) puzzle. It provides methods for searching walls
        at specific positions to check whether "join" graphics should be shown
    '''
    wall_thickness = wall_part_thickness

    def __init__(self):
        '''
        The constructor of the class. Requires no arguments,
        '''
        self.reset_wall_data()

    def reset_wall_data(self):
        '''
        Resets all fields containing information about the walls in puzzle.
        '''
        # Lists containing PartInfoT2 objects for walls, depending on
        #     the orientation.
        self.horiz_walls = []
        self.vert_walls = []

    def add_wall_part(self, puzzle_part):
        '''
        Adds a wall puzzle part to the appropriate list (horiz_walls,
            vert_walls) depending on its orientation. Invalid "walls"
            are ignored (and a warning is printed in wall_coords_check)
        puzzle_part: PartInfoT1/PartInfoT2 for the wall.
        '''
        if not wall_coords_check(puzzle_part, self.wall_thickness):
            return

        if puzzle_part.height_1 == self.wall_thickness:
            self.horiz_walls.append(puzzle_part)
        elif puzzle_part.width_1 == self.wall_thickness:
            self.vert_walls.append(puzzle_part)

    def find_horiz_wall_by_top_side(self, wall_pos_top, pos_x):
        '''
        Finds a horizontal wall in the stored wall data that meets two
            criteria: 1. the y coordinate of the top edge of the wall is
            equal to wall_pos_top, 2. pos_x is greater than or equal to the
            x coordinate of the left edge, but less than the x coordinate of
            the right edge. Used in the "wall join graphics" code.
            More than one match is possible only if the data is invalid.
            In this case, a warning is printed using print_msg.
        Returns a stored part data namedtuple or None if there is no match.
        wall_pos_top: the y coordinate of the top edge of the wall part (int)
        pos_x: The x position used in the 2nd search condition (see above)
            (int)
        '''
        out_part = None

        for wall_part in self.horiz_walls:
            if ((wall_part.pos_y == wall_pos_top)
                    and (wall_part.pos_x <= pos_x)
                    and (pos_x < (wall_part.pos_x + wall_part.width_1))):
                if out_part is None:
                    out_part = wall_part
                    # Note: For optimization, the loop could be terminated
                    #     here. However, it is continued for data checking
                else:
                    print_msg(str_warn_wall_coords)

        return out_part

    def find_vert_wall_by_left_side(self, wall_pos_left, pos_y):
        '''
        Finds a vertical wall in the stored wall data that meets two
            criteria: 1. the x coordinate of the left edge of the wall is
            equal to wall_pos_left, 2. pos_y is greater than or equal to the
            y coordinate of the top edge, but less than the y coordinate of
            the bottom edge. Used in the "wall join graphics" code.
            More than one match is possible only if the data is invalid.
            In this case, a warning is printed using print_msg.
        Returns a stored part data namedtuple or None if there is no match.
        wall_pos_top: the x coordinate of the left edge of the wall part (int)
        pos_y: The y position used in the 2nd search condition (see above)
            (int)
        '''
        out_part = None

        for wall_part in self.vert_walls:
            if ((wall_part.pos_x == wall_pos_left)
                    and (wall_part.pos_y <= pos_y)
                    and (pos_y < (wall_part.pos_y + wall_part.height_1))):
                if out_part is None:
                    out_part = wall_part
                    # Note: For optimization, the loop could be terminated
                    #     here. However, it is continued for data checking
                else:
                    print_msg(str_warn_wall_coords)

        return out_part
