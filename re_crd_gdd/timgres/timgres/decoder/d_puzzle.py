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
from timgres.base.nibblarr import _single_char
from timgres.base.basecl import ResDataBase_Decoder
from timgres.base.misc import (print_msg, print_traceback, game_text_encoding,
                               ext_subf_gkc, ext_subf_lev, ext_subf_tim)
from timgres.puzzle.puzdata import (get_puzzle_info_obj_for_ver,
                                    game_ver_tim_demo, game_ver_tim,
                                    game_ver_temim, game_ver_tim_special,
                                    game_ver_tim2)

# --- Level/puzzle (sub-)file decoder ---

'''
    This class contains the decoder for various versions of TIM/TEMIM/TIM2
    puzzle/level file format. Variants of this format are also used for saved
    "freeform" machines, user-created TIM 2 puzzles as well as TIM/TEMIM .GKC
    intro screen files. The module also contains several namedtuples for
    storing data from puzzle files.
'''

# Documentation for this file format is available at:
# https://moddingwiki.shikadi.net/wiki/The_Incredible_Machine_Level_Format
# Information about this file format can also be found in the fformat.txt
#     file in this package.

# Supported file extensions
puzzle_file_ext_supported = (ext_subf_gkc, ext_subf_lev, ext_subf_tim)

puzzle_magic_num_t1_demo = 0x0100ACED
puzzle_magic_num_t1 = 0x0102ACED
puzzle_magic_num_temim = 0x0105ACEE
puzzle_magic_num_t2_1 = 0x0111ACEF
puzzle_magic_num_t2_2 = 0x0112ACEF
puzzle_magic_num_t2_3 = 0x0113ACEF
puzzle_magic_num_t3_1 = 0x0114ACEF

d_magic_num_game_ver = {
    puzzle_magic_num_t1_demo: game_ver_tim_demo,
    puzzle_magic_num_t1: game_ver_tim,
    puzzle_magic_num_temim: game_ver_temim,
    puzzle_magic_num_t2_1: game_ver_tim2,
    puzzle_magic_num_t2_2: game_ver_tim2,
    puzzle_magic_num_t2_3: game_ver_tim2,
    puzzle_magic_num_t3_1: game_ver_tim2
}

## magic_num_t1_temim = (puzzle_magic_num_t1, puzzle_magic_num_temim)
## magic_num_t2 = (
##     puzzle_magic_num_t2_1, puzzle_magic_num_t2_2, puzzle_magic_num_t2_3)

# nt_puzzle_data: The namedtuple containing the result of a puzzle
# game_ver: The game version the file is compatible with, determined
#     mainly from the magic number and file extension.
# magic_num: a 32-bit unsigned int in little endian format, the first four
#     bytes of the file. (TODO: redundancy)
# is_user_created: Bool, False for  "built-in" puzzles, True if this is a
#     free-form machine (TIM, TEMIM) or an user-created puzzle (TIM2).
#     Note: This means significant differences in file format in TIM and
#     TEMIM: in TIM both the puzzle title and the goal description are
#     missing, while, in TEMIM only the former one is not present.
#     The "header" is also different. In TIM 2, file format is identical
#     to built-in puzzles with magic number puzzle_magic_num_t2_3,
#     this field is set based on file extension (.TIM for user-created).
# backgr_color: Background color, only supported by TIM 2 puzzles
#     with magic number puzzle_magic_num_t2_3. None in all other cases,
#     defaults to color #3 in the 16-color palette.
# puzzle_title: Short title of the puzzle (str). Only TIM 2 (and 3) supports
#     this for user-made puzzles. None if unsupported.
# goal_descr: The goal of the puzzle (str). Not supported in TIM
#     (but not TEMIM) freefrom machines (-> None)
# hints: list of hints for supported format, that is, TIM 2 puzzles, None if
#     does not (May be empty list for TIM 2 puzzles)
# puzzle_info: Contains importan information about the puzzle (such as number
#       of parts, gravity, pressure, ) A namedtuple, depends on game ver
# parts: The parts in the puzzle, list of nt_part_info namedtuples
#     Note: puzzle file format groups moving/fixed parts and in case of
#     TIM/TEMIM parts in parts bin into sections. The parts list has no
#     sections, so that the parts can be accessed by number easier.
#     The "group" information is found in the nt_part_info namedtuple
#     for each part.
# solution: Solution information for TIM2 puzzles, list of
#     nt_t2_solution_info namedtuples.
#     Note: TIM stores solutions for puzzles in the exe file using
#     a yet unknown mechanism, perhaps puzzle specific procedures and not
#     data arrays. Solution fields are None for TIM and TEMIM.
# solution_delay: A feature of TIM 2 solution checking, the puzzle is solved
#    if all ...
#    Similarly to solution, None for TIM and TEMIM puzzles. 0 if no delay.
#    Unit is unknown, perhaps IRQ0 "ticks"?

nt_puzzle_data = namedtuple(
    'nt_puzzle_data', ('game_ver', 'magic_num', 'is_user_created',
                       'backgr_color', 'puzzle_title', 'goal_descr', 'hints',
                       'puzzle_info', 'parts', 'solution', 'solution_delay'))

# -------------

# Puzzle info namedtuple, created when decoding puzzle header
# NOTE: Additional information on the puzzle file format is provided
#     in the fformat.txt file.

nt_t1_puzzle_info = namedtuple(
    'nt_t1_puzzle_info',
    ('bonus_1', 'bonus_2', 'pressure', 'gravity', 'unknown_8', 'unkonwn_10',
     'music', 'num_parts_fixed', 'num_parts_moving', 'num_parts_partsbin'))

# nt_t2_puzzle_info: puzzle header for TIM 2 puzzles
# pressure, gravity, music: see nt_t1_puzzle_info
#
# unknown_*: probably unused, (nearly) always 0

nt_t2_puzzle_info = namedtuple(
    'nt_t2_puzzle_info',
    ('pressure', 'gravity', 'unknown_4', 'unknown_6', 'music',
     'num_parts_fixed', 'num_parts_moving', 'unknown_14'))

# nt_t1_puzzle_info_freeform: For TIM & TEMIM freeform machines,
#   see meaning of fields in nt_t1_puzzle_info
#   Note: num_parts_partsbin only used in TEMIM

nt_t1_puzzle_info_freeform = namedtuple(
    'nt_t1_puzzle_info_freeform',
    ('pressure', 'gravity', 'music', 'num_parts_fixed', 'num_parts_moving',
     'num_parts_partsbin'))

# Dict for obtaining puzzle info type for game version
#  Note that nt_t1_puzzle_info_freeform  and game_ver_tim_specialis not in
#     this dict, as they requires separate treatment

d_puzzle_info_type = {
    game_ver_tim_demo: nt_t1_puzzle_info,
    game_ver_tim: nt_t1_puzzle_info,
    game_ver_temim: nt_t1_puzzle_info,
    game_ver_tim2: nt_t2_puzzle_info
}

# todo, add constants for direction
# t2_hint_data: Namedtuple containing data from hints in TIM2 puzzles
#      pos_x, pos_y:
#      direction:
#      hint_text:
nt_t2_puzzle_hint = namedtuple('nt_t2_puzzle_hint',
                               ('pos_x', 'pos_y', 'direction', 'hint_text'))

# Note: pressure: 0 - 0x80 (includes 0x80 !), gravity: 0 - 0x200 (incl. 0x200)
#       Pressure: def value: 0x43, Gravity: def value:
#       0x10C (TIM) 0x110 (TIM2)

# --- Part namedtuples and subclasses ---

# NOTE: fields with names temp_* are subject to change
#     (* correponst to the position of the field in bytes)

# nt_part_info_t1_base: Namedtuple for each part in a TIM or TEMIM puzzle
# Note: is_moving in_partsbin, is_scenery and extra_fields are not part of
#     the "raw" data from the puzzle, all other fields are
# is_moving:
# in_partsbin:
# is_scenery: For compatibility with the namedtuple for TIM 2, always False
# extra_data_1, extra_data_2: extra fields for specific parts, either one
#     of the nt_part_extra_* namedtuples or None. extra_data_1 is located
#     before the connect_* fields, while extra_data_2 is found after all other
# part_num: The first field that comes directly from the decoded file
#     The type of the part (e.g. bowling ball, brick wall)
# TODO, add documentation for all other fields
# Raw data from the puzzle, all following fields are ints

# Note on flags: Flags are stored as signed ints like all other fields.
#     The & operator in python is implemented for negative numbers in a way...
nt_part_info_t1_base = namedtuple(
    'nt_part_info_t1_base',
    ('is_moving', 'in_partsbin', 'is_scenery', 'extra_data_1', 'extra_data_2',
     'part_num', 'flags_1', 'flags_2', 'flags_3', 'appearance', 'temp_10',
     'width_1', 'height_1', 'width_2', 'height_2', 'pos_x', 'pos_y', 'temp_24',
     'temp_26', 'belt_info_1', 'belt_info_2', 'temp_32', 'rope_info_1',
     'temp_36', 'rope_info_2', 'connected_1', 'connected_2', 'connected_3',
     'connected_4'))


class PartInfoT1(nt_part_info_t1_base):
    '''
    Namedtuple subclass for storing info for each part in TIM and TEMIM
    Has one extra method compared to namedtuples: get_raw_data
    '''

    def get_raw_data(self):
        '''
        Returns a tuple of ints corresponding to the "raw" data stored in this
        tuple subclass (length depends on part, see item_length_special_t1)
        '''
        return (self[5:-4] + (self.extra_data_1 or ()) + self[-4:] +
                (self.extra_data_2 or ()))

    # Field name synonyms for rope & belt part (TODO, temporary
    belt_index_connected_1 = nt_part_info_t1_base.temp_32
    belt_index_connected_2 = nt_part_info_t1_base.rope_info_1
    rope_index_connected_1 = nt_part_info_t1_base.temp_36
    rope_index_connected_2 = nt_part_info_t1_base.rope_info_2


# nt_part_info_t1_demo_base: Namedtuple for each part in a TIM 1 demo puzzle
#      See nt_part_info_t1_base for additional details
# is_moving, in_partsbin', is_scenery, extra_data: see above

# NOTE: the numbering of temp_* fields follow nt_part_info_t1_base, and do not
#     correspond to the byte position in the data structure. This makes
#     implementing level viewing significantly easier.

nt_part_info_t1_demo_base = namedtuple(
    'nt_part_info_t1_demo_base',
    ('is_moving', 'in_partsbin', 'is_scenery', 'extra_data_1', 'extra_data_2',
     'part_num', 'flags_1', 'flags_2', 'appearance', 'temp_10', 'width_1',
     'height_1', 'width_2', 'height_2', 'pos_x', 'pos_y', 'temp_24', 'temp_26',
     'belt_info_1', 'belt_info_2', 'temp_32', 'rope_info_1', 'temp_36',
     'rope_info_2', 'connected_1', 'connected_2', 'num_extra_fields_end'))


class PartInfoT1Demo(nt_part_info_t1_demo_base):
    '''
    Namedtuple subclass for storing info for each part in TIM1 demo
    Has one extra method compared to namedtuples: get_raw_data
    '''

    def get_raw_data(self):
        '''
        Returns a tuple of ints corresponding to the "raw" data stored in this
        tuple subclass (length depends on part, see item_length_special_t1)
        '''
        return (self[5:-3] + (self.extra_data_1 or ()) + self[-3:] +
                (self.extra_data_2 or ()))

    # Field name synonyms for rope & belt part (TODO, temporary
    belt_index_connected_1 = nt_part_info_t1_demo_base.temp_32
    belt_index_connected_2 = nt_part_info_t1_demo_base.rope_info_1
    rope_index_connected_1 = nt_part_info_t1_demo_base.temp_36
    rope_index_connected_2 = nt_part_info_t1_demo_base.rope_info_2


part_num_prog_ball = 87

# nt_part_info_t2_base: Namedtuple for each part in a TIM 2 puzzle
#      See nt_part_info_t1_base for additional details
# is_moving, in_partsbin', is_scenery, extra_data: see above
#      (but TIM 2 has scenery parts
# TODO, add documentation for all other fields
# TODO, temp_* fields are subject to change
# NOTE: Additional information on the puzzle file format is provided
#     in the fformat.txt file.

nt_part_info_t2_base = namedtuple(
    'nt_part_info_t2_base',
    ('is_moving', 'in_partsbin', 'is_scenery', 'extra_data_1', 'extra_data_2',
     'part_num', 'flags_1', 'flags_2', 'flags_3', 'appearance', 'temp_10',
     'width_1', 'height_1', 'width_2', 'height_2', 'pos_x', 'pos_y',
     'behavior', 'temp_26', 'belt_info_1', 'belt_info_2', 'temp_32',
     'rope_info_1', 'temp_36', 'rope_info_2', 'connected_1', 'connected_2',
     'connected_3', 'connected_4'))


class PartInfoT2(nt_part_info_t2_base):
    '''
    Namedtuple subclass for storing info for each part in TIM 2.
    Has one extra method compared to namedtupples: get_raw_data
    '''

    def get_raw_data(self):
        '''
        Returns a tuple of ints correponding to the "raw" data stored in this
        tuple subclass (length depends on part, see item_length_special_t2)
        '''
        # For parts expect part_num_prog_ball, the extra data is inserted
        #     at 4 positions before end.
        if self.part_num != part_num_prog_ball:
            return self[4:] + (self.extra_data or ())
        else:
            return self[4:-4] + (self.extra_data or ()) + self[-4:]

    # Field name synonyms for rope & belt part (TODO, temporary
    belt_index_connected_1 = nt_part_info_t2_base.temp_32
    belt_index_connected_2 = nt_part_info_t2_base.rope_info_1
    rope_index_connected_1 = nt_part_info_t2_base.temp_36
    rope_index_connected_2 = nt_part_info_t2_base.rope_info_2


# nt_solution_info_t2_base: contains solution information for TIM 2 puzzle
#    (for one part involved in solution).
# sol_type: One of the SOL_TYPE_T2_* constants, the only field
#     that does NOT come from the raw data
# part_index: Index of part in the corresponding section  of file
#     (not the type of part)
# part_state_1, part_state_2: Used for "state of part" solutions, e.g.
#     broken fish tank, popped balloon. Values seem to correspond to
#     resource file ....
# part_count: Number of identical parts involved in the solution.
#     The game has a separate entry field for this in "Sol. editor" window.
#     Note: seems to depend on the "appearance" of the part
# ...
# Note: "Off screen", "Off top", and "Off Bottom" goals are encoded as
#     special values of the last four fields
nt_solution_info_t2_base = namedtuple(
    'nt_solution_info_t2_base',
    ('sol_type', 'part_index', 'part_state_1', 'part_state_2', 'part_count',
     'position_x', 'position_y', 'position_width', 'position_height'))

# Note: class name uses different spelling due to PEP 8!


class SolutionInfoT2(nt_solution_info_t2_base):
    '''
    Namedtuple subclass for storing "solution" data from TIM 2 puzzles.
    Has one extra method compared to namedtuples: get_raw_data
    '''

    def get_raw_data(self):
        '''
        Returns a tuple of ints (length: 8), corresponding to the "raw" data
        stored in this tuple subclass
        '''
        return self[1:]


# ------------------

# ... Namedtuples and variables related to parts ...

# Extra data for specific parts
# See also item_length_special_t2 ; TODO, add description for fields

# nt_part_extra_pulley: Namedtuple for 8 bytes of extra
#    data for the "pulley" part

nt_part_extra_pulley = namedtuple(
    'nt_part_extra_pulley',
    ('extra_0', 'extra_2', 'rope_info_pulley_2', 'connect_pulley_2'))

# nt_part_extra_belt: Namedtuple for 4 bytes of extra
#    data for the "belt" part

nt_part_extra_belt = namedtuple('nt_part_extra_belt', ('extra_0', 'extra_2'))

# nt_part_extra_rope: Namedtuple for 6 bytes of extra
#    data for the "rope" and the "steel cable" (TIM 2+) part

nt_part_extra_rope = namedtuple('nt_part_extra_rope',
                                ('extra_0', 'extra_2', 'extra_4'))

# The dict for the "extra data 1" types for each part that requires it

d_item_extra_data_1_type_t2 = {
    7: nt_part_extra_pulley,
    8: nt_part_extra_belt,
    10: nt_part_extra_rope,
    76: nt_part_extra_rope,
    # NOTE: programmable ball now treated separately!
    # 87: nt_part_extra_prog_ball
}

max_part_num_temim = 65
d_item_extra_data_1_type_t1 = {
    x: y
    for x, y in d_item_extra_data_1_type_t2.items() if x <= max_part_num_temim
}

# nt_extra_data_2_tim_demo: TIM demo has a default part entry size of 44 bytes
#     (except for the rope/belt/pulley parts). However, this may be followed
#     by an "extra" structure with currently unknown meaning. Its size is
#     determined by the last short of the "main" entry. The maximum
#     possible size seems to be 12 shorts.

nt_extra_data_2_tim_demo_max_entries = 12

nt_extra_data_2_tim_demo = namedtuple(
    'nt_extra_data_2_tim_demo',
    ['extra_2_%d' % x for x in xrange(nt_extra_data_2_tim_demo_max_entries)])

# nt_part_extra_2_prog_ball: Namedtuple for 12 bytes of extra
#     data for the "programmable ball" (TIM 2+) part
# Unlike extra data for rope/belt/pulley parts, this seems to be located
#     after all other fields, thus stored as "extra_data_2".
# All fields are ints.
# density, elasticity, friction, mass: The four programmable parameters of
#     the ball, the possible values are found in the "extra" source file
#     t2pinfo.py
# gravity_buoyancy: value depends on the density of the ball and the
#     pressure set for the puzzle. If negative, the ball will rise, not fall.
# appearance_2: Contains the same value as appearance (in the "main"
#     namedtuple for the part).

nt_part_extra_2_prog_ball = namedtuple(
    'nt_part_extra_2_prog_ball', ('density', 'elasticity', 'friction',
                                  'gravity_buoyancy', 'mass', 'appearance_2'))

# --- Various constants for puzzle "header" decoding ---
music_n_range_min = 0x3E8
music_n_range_max = 0x3FF
skip_hints_magic_num_t2_1 = 42
# The maximum number of hints and the size of an "empty" hint in TIM 2
max_num_hints_t2 = 8
size_empty_hint_t2 = 7

# --- Constants for part information decoding ---
# t1_flags_1_nin_moving: This bit is set in the
#     more significant byte of flags 1 if the part is "fixed"
t1_flags_1_non_moving = 0x40
t2_flags_3_not_partsbin = 0xf0

# ... Constants related to solution data (TIM 2+ only) ...

# Max, 8 solutions per puzzle
solution_num_entries = 8

# The "solution type constants, see nt_solution_info_t2_base
#     Note: these consts are for internal use, and do not represent data
#     directly decoded from TIM 2 puzzle files.

SOL_TYPE_T2_NONE = 0
SOL_TYPE_T2_PART_STATE = 1
SOL_TYPE_T2_POSITION = 2
SOL_TYPE_T2_OFF_SCREEN = 3
SOL_TYPE_T2_OFF_TOP = 4
SOL_TYPE_T2_OFF_BOTTOM = 5

# Required for checking for unused entries in sol. block
sol_part_num_unused = -1

# The following tuples correspond to bytes 8 - 15 of a solution entry
#     (the "position" part of data) and have special meaning

sol_t2_pos_off_screen = (-1, -1, -1, -1)
sol_t2_pos_off_top = (-500, -2000, 1640, 2000)
sol_t2_pos_off_bottom = (-500, 400, 1640, 3000)
sol_t2_pos_none = (0, 0, 0, 0)  # Used for SOL_T2_PART_STATE

# Dict for setting sol_type field in nt_solution_info_t2_base
#     Note: SOL_TYPE_T2_POSITION must be used as "default" (.get())
#     Keys are tuples (see sol_t2_pos_*), values are int consts
#     (SOL_TYPE_T2_*) TODO, Py 3.8+ allows setting def. value for dicts

d_sol_t2_type_pos = {
    sol_t2_pos_none: SOL_TYPE_T2_PART_STATE,
    sol_t2_pos_off_screen: SOL_TYPE_T2_OFF_SCREEN,
    sol_t2_pos_off_top: SOL_TYPE_T2_OFF_TOP,
    sol_t2_pos_off_bottom: SOL_TYPE_T2_OFF_BOTTOM,
}

# --- Various struct format specifiers ---
format_freeform_info = '<6h'
format_single_short = '<h'
format_t2_hint_data = '<3h'
# Note: signed int for flags fields
format_part_1_data_common = '<h3H16h'
format_part_2_data_common = '<4h'
format_part_1_data_common_t1_demo = '<h3H15h'
# format_part_2_data_common_t1_demo: the last field, num_extra_fields_end
#     is treated as unsigned
format_part_2_data_common_t1_demo = '<2hH'
format_solution_entry_t2 = '<8h'

str_err_puzzle_head = 'Invalid head format.'
str_err_solution_t2 = 'Format error in TIM 2 puzzle solution block'


class SubFileDecoder_Puzzle(ResDataBase_Decoder):
    '''
    Decoder class for puzzle files in any version of the game until 3.
    Also supports "freeform" machines/user-made puzzles and the TIM/TEMIM
    Intro/Credits screen files (.GKC)
    '''

    def __init__(self):
        '''The constructor of the class. requires no arguments.'''
        ResDataBase_Decoder.__init__(self)

        self.reset_conv_data()

    def reset_conv_data(self):
        '''Resets the fields that store the data extracted from input.'''
        # file_data: The puzzle (sub-)file data to decode (bytes)
        self.file_data = None
        # The current index in the data (int)
        self.data_index = None
        # Message for exceptions, containing file name, see process_sub_file
        self.except_text = None
        # A puzzle data object, type is a PuzzleInfoBase (base.puzdata)
        #     subclass depending on game version
        self.puzzle_info_obj = None
        # Note: for exact meaning of following fields, see comment at
        #   nt_puzzle_data namedtuple. Only the data type is mentioned below.
        # game_ver: one of GAME_VER_* consts (int)
        self.game_ver = None
        # magic_num: one of puzzle_magic_num_* consts (int)
        self.magic_num = None
        # is_user_created: bool
        self.is_user_created = False
        # backgr_color: int (TIM2, magic num = puzzle_magic_num_t2_3) or None
        self.backgr_color = None
        # puzzle_title: str or None depending on format and version.
        self.puzzle_title = None
        # goal_descr: str or None
        self.goal_descr = None
        # hint: list of nt_t2_puzzle_hint (TIM 2) or None
        self.hints = None
        # puzzle_info: namedtuple depending on format (nt_t1_puzzle_info,
        #     nt_t2_puzzle_info, nt_t1_puzzle_info_freeform)
        self.puzzle_info = None
        # parts: list of nt_part_info
        self.parts = None
        # solution: list of nt_t2_solution_info (TIM 2) or None
        self.solution = None
        # solution_delay: int (TIM 2) or None
        self.solution_delay = None

    def is_file_type_supported(self, file_data_start):
        '''
        Re-implementation is_file_type_supported from ResDataBase_Decoder.
        See meaning of argument there (base.basecl)
        In current ver. it checks the first four bytes (magic number) only,
        '''

        if not isinstance(file_data_start, bytes):
            raise TypeError('file_data_start: must be bytes')

        if len(file_data_start) < 4: return False

        head_magic = struct.unpack_from('<L', file_data_start, 0)[0]

        return head_magic in d_magic_num_game_ver

    def read_z_ter_str(self):
        '''
        "Reads" a null_terminated_string from self.file_data starting at
        self.data_index. Finds the zero terminator and returns the
        string, decoded using game_text_encoding. Advances data_index
        to the position after the terminator. Returns str.
        '''
        start_pos = self.data_index
        end_pos = self.file_data.find(0, start_pos)

        if end_pos == -1:
            raise RuntimeError('End of data reached before \\0 terminator')

        self.data_index = end_pos + 1
        return self.file_data[start_pos:end_pos].decode(game_text_encoding)

    def read_bin_data(self, unpack_format):
        '''
        Reads a struct from self.file_data, the format must be specified
        using the syntax used by the struct module (unpack_format, str).
        Advances self.data_index. Returns a tuple.
        '''

        start_pos = self.data_index
        # fixme, no size check!
        self.data_index += struct.calcsize(unpack_format)
        return struct.unpack_from(unpack_format, self.file_data, start_pos)

    def read_16bit_ints_to_namedtuple(self, n_tuple_class):
        '''
        Reads the appropriate number of 16-bit signed integers from
        self.file_data and returns a new namedtuple object. n_tuple_class
        is the type of object that must be returned.
        '''
        start_pos = self.data_index
        # fixme, no size check!
        n_fields = len(n_tuple_class._fields)
        self.data_index += n_fields * 2
        return n_tuple_class._make(
            struct.unpack_from('<%dh' % n_fields, self.file_data, start_pos))

    def read_single_short(self):
        '''
        Reads a single 16-bit signed integer from self.file_data,
        Advances self.data_index. Returns int.
        '''
        return self.read_bin_data(format_single_short)[0]

    def read_str_or_freeform_head(self):
        '''
        Function for internal use only. Required for support of puzzle
        formats that lack a title, a goal string or both.
        Returns str or nt_t1_puzzle_info_freeform namedtuple.
        '''
        # For further information, see comment in process_puzzle_head

        save_index = self.data_index
        out_str_temp = self.read_z_ter_str()

        if len(out_str_temp) < 2:
            # Might be a puzzle header, see comment in process_puzzle_head
            out_head_temp = nt_t1_puzzle_info_freeform._make(
                struct.unpack_from(format_freeform_info, self.file_data,
                                   save_index))

            if music_n_range_min <= out_head_temp.music <= music_n_range_max:
                # Music number is also "correct" treat it as a header
                # TODO: an "or (out_head_temp.music == 0)" hack is needed to
                #     decode FF:LEV form TIM DEMO
                self.data_index = (save_index +
                                   struct.calcsize(format_freeform_info))
                return out_head_temp
            else:
                # otherwise, treat it as a string
                return out_str_temp
        else:
            # Definitely not a header
            return out_str_temp

    def process_puzzle_head(self, file_ext_upper):
        '''
        Method for internal use only. Processes the following parts of a
        puzzle file (if present): title, goal description, hints,
        information struct. Sets the following fields: puzzle_title,
        goal_descr, puzzle_info, hints, puzzle_info (not all present in all
        file formats). May modify game_ver.
        file_ext_upper (str): the file extension uppercased, e.g. '.LEV'
        '''
        # Try to decode puzzle title first

        # Note: there are file formats that lack both puzzle title and goal
        #     description: .GKC files and TIM (not TEMIM) freeform machines.
        #     On the other hand, TEMIM saved freeform machines have a goal
        #     description, but lack a title. The "puzzle info" format is
        #     also different, see nt_t1_puzzle_info_freeform

        # If the puzzle lacks both a title and a goal text, the "puzzle info"
        #     header starts directly after the magic num. The first word of
        #     this struct is the pressure, valid values are 0x0 - 0x80. Thus,
        #     in little endian format, the second byte is always zero, which
        #     can be exploited for detection of such a header: read_z_ter_str
        #     will return either 0 or 1. To confirm that this is a header and
        #     not just a very short string, the program additionally checks
        #     the music number, which must fall in range 0x3E8-0x3FF (
        #     although TIM and TEMIM have less music tracks than that.)

        title_or_freeform_head = self.read_str_or_freeform_head()

        if isinstance(title_or_freeform_head, str):
            # A string -> a puzzle title
            self.puzzle_title = title_or_freeform_head
        else:
            # No title or goal description, this is either 1. a .GKC file
            #     2. a saved freeform machine from TIM (not TEMIM)
            #     3. the file named "FF.LEV" in TIM demo
            # If this is a GKC file then set game_ver to game_ver_tim_special

            if file_ext_upper == ext_subf_gkc:
                if self.magic_num not in (puzzle_magic_num_t1,
                                          puzzle_magic_num_temim):
                    raise RuntimeError(self.except_text % str_err_puzzle_head)

                self.game_ver = game_ver_tim_special
            else:
                if self.magic_num not in (puzzle_magic_num_t1,
                                          puzzle_magic_num_t1_demo):
                    raise RuntimeError(self.except_text % str_err_puzzle_head)

                self.is_user_created = True

            self.puzzle_info = title_or_freeform_head
            # Header processed, we can return
            return

        goal_descr_or_freeform_head = self.read_str_or_freeform_head()

        if isinstance(goal_descr_or_freeform_head, str):
            # A string -> goal description
            self.goal_descr = goal_descr_or_freeform_head
        else:
            # Otherwise, this is a TEMIM freefrom machine
            #     Or, the TITLE.GKC file in TEMIM (!)
            if self.magic_num != puzzle_magic_num_temim:
                raise RuntimeError(self.except_text % str_err_puzzle_head)

            if file_ext_upper == ext_subf_gkc:
                self.game_ver = game_ver_tim_special
            else:
                self.is_user_created = True

            self.puzzle_info = goal_descr_or_freeform_head
            # puzzle_title is in fact the goal description!
            self.goal_descr = self.puzzle_title
            self.puzzle_title = None
            return

        # Process TIM 2 hints
        if self.magic_num == puzzle_magic_num_t2_1:
            # Note on TIM 2 puzzles using puzzle_magic_num_t2_1:
            #    The game contains 3 "built-in" puzzles with this magic num
            #    and none of them has hints. The number of bytes of this
            #    section is 42, making this format incompatible with the
            #    hint decoder code for other formats. This format _might_
            #    support hints (based on hint format in other files, a 16-bit
            #    hint count + 8 "empty" hints with a size of 4+1 bytes each
            #    [1->empty 0-ter string] seems logical) However, as user-made
            #    puzzles never use this format, there is no need to support
            #    hints for puzzle_magic_num_t2_1 files.
            # Just skip 42 bytes
            self.data_index += skip_hints_magic_num_t2_1
        elif self.magic_num in (puzzle_magic_num_t2_2, puzzle_magic_num_t2_3,
                                puzzle_magic_num_t3_1):
            num_hints = self.read_single_short()

            if (num_hints > max_num_hints_t2) or (num_hints < 0):
                raise RuntimeError(self.except_text %
                                   'Invalid number of hints in TIM 2 puzzle')

            self.hints = []

            for cnt_hint in xrange(num_hints):
                hint_data = self.read_bin_data(format_t2_hint_data)
                hint_text = self.read_z_ter_str()
                # TODO: use *hint_data instead ?
                self.hints.append(
                    nt_t2_puzzle_hint._make(hint_data + (hint_text, )))

            # Skip the appropriate number of bytes to info struct
            self.data_index += (max_num_hints_t2 -
                                num_hints) * size_empty_hint_t2

        # Finally process puzzle info header
        self.puzzle_info = self.read_16bit_ints_to_namedtuple(
            d_puzzle_info_type[self.game_ver])

    def read_puzzle_part(self, part_info_type, extra_data_1_type_dict,
                         is_moving, in_partsbin):
        '''
        part_info_type: Type of return value, PartInfoT1 or PartInfoT2
        extra_data_1_type_dict: Dict containing extra info namedtuple
            classes, d_item_extra_data_type_t2 or d_item_extra_data_1_type_t1
        is_moving, in_partsbin: Values for these two fields in the returned
            namedtuple, depends on both "sub-section" of file and game ver.
            (type: Any type that can be converted to bool.)
        Returns namedtuple subclass, type is part_info_type
        '''
        # Note: cannot use read_16bit_ints_to_namedtuple here

        # MODIFIED: "Extra" fields are now treated in the following way:
        #   data_common is split into two parts, and for parts other than the
        #   "programmable" ball, extra fields are between the two parts.

        data_common_1 = self.read_bin_data(
            format_part_1_data_common_t1_demo if self.game_ver ==
            game_ver_tim_demo else format_part_1_data_common)

        part_num = data_common_1[0]

        if self.puzzle_info_obj.get_part_name(part_num) is None:
            raise RuntimeError(
                self.except_text % ('Unsupported part %d' % part_num))

        extra_data_type = extra_data_1_type_dict.get(part_num)

        if (extra_data_type is not None) and (part_num != part_num_prog_ball):
            extra_data_1 = self.read_16bit_ints_to_namedtuple(extra_data_type)
        else:
            extra_data_1 = None

        data_common_2 = self.read_bin_data(
            format_part_2_data_common_t1_demo if self.game_ver ==
            game_ver_tim_demo else format_part_2_data_common)

        if self.game_ver == game_ver_tim_demo:
            size_t1_demo_extra_2 = data_common_2[2]  # shorts

            # Note: size_t1_demo_extra_2 is expected to be unsigned!
            if size_t1_demo_extra_2 > nt_extra_data_2_tim_demo_max_entries:
                raise RuntimeError(
                    self.except_text %
                    ('Invalid TIM demo part entry, part %d' % part_num))

            extra_data_2_raw = self.read_bin_data(
                '<%dh' % size_t1_demo_extra_2)
            extra_data_2 = nt_extra_data_2_tim_demo._make(
                extra_data_2_raw + (None, ) *
                (nt_extra_data_2_tim_demo_max_entries - size_t1_demo_extra_2))

        elif part_num == part_num_prog_ball:
            extra_data_2 = self.read_16bit_ints_to_namedtuple(
                nt_part_extra_2_prog_ball)
        else:
            extra_data_2 = None

        return part_info_type._make(
            (bool(is_moving), bool(in_partsbin),
             self.puzzle_info_obj.is_scenery_part(part_num), extra_data_1,
             extra_data_2) + data_common_1 + data_common_2)

    def process_parts_t1(self):
        '''
        Decodes all parts from a TIM or TEMIM puzzle, adds PartInfoT1
        (or PartInfoT1Demo) entries to self.parts. There are 3 "sections",
        "fixed", "moving", and parts initially in the parts bin.
        Sets field self.parts.
        '''
        self.parts = []
        part_info_type = (PartInfoT1Demo if self.game_ver == game_ver_tim_demo
                          else PartInfoT1)

        for cnt in xrange(self.puzzle_info.num_parts_fixed):
            self.parts.append(
                self.read_puzzle_part(part_info_type,
                                      d_item_extra_data_1_type_t1, False,
                                      False))

        for cnt in xrange(self.puzzle_info.num_parts_moving):
            self.parts.append(
                self.read_puzzle_part(part_info_type,
                                      d_item_extra_data_1_type_t1, True,
                                      False))

        # Note: In TEMIM. between "sections" #2 and #3 (moving, in parts bin)
        #     there is an extra 16 bit value. Apparently there are two
        #     possible values: 1 (user-made machine with parts in parts bin?)
        #     and 0 (all other cases). Not stored in the decoder output.
        # FIXME, we have to use the magic number here as the decoder uses
        #     game_ver_tim_special instead of game_ver_temim

        if self.magic_num == puzzle_magic_num_temim:
            if self.read_single_short() not in (0, 1):
                raise RuntimeError(
                    self.except_text % 'Format error in TEMIM puzzle')

        for cnt in xrange(self.puzzle_info.num_parts_partsbin):
            # For parts initially in parts bin, the more significant byte of
            #    bit 6 (0x40) is zero in the more significant byte of flags_1
            #    if the part can move
            flags_1_high = _single_char(self.file_data[self.data_index + 3])

            self.parts.append(
                self.read_puzzle_part(
                    part_info_type, d_item_extra_data_1_type_t1,
                    not (flags_1_high & t1_flags_1_non_moving), True))

    def process_parts_t2(self):
        '''
        Decodes all parts from a TIM 2 puzzle, adds PartInfoT2 entries
        to self.parts. There are 2 "sections", "fixed" and "moving".
        Sets field self.parts.
        '''
        self.parts = []

        # If the part is in the parts bin initially, the less upper nibble in
        #     the less significant byte of flags_3 is zero
        for cnt in xrange(self.puzzle_info.num_parts_fixed):
            flags_3_low = _single_char(self.file_data[self.data_index + 6])

            self.parts.append(
                self.read_puzzle_part(
                    PartInfoT2, d_item_extra_data_1_type_t2, False,
                    not (flags_3_low & t2_flags_3_not_partsbin)))

        for cnt in xrange(self.puzzle_info.num_parts_moving):
            flags_3_low = _single_char(self.file_data[self.data_index + 6])

            self.parts.append(
                self.read_puzzle_part(
                    PartInfoT2, d_item_extra_data_1_type_t2, True,
                    not (flags_3_low & t2_flags_3_not_partsbin)))

    def process_solution_t2(self):
        '''
        Decodes the solution data block in TIM 2 puzzles. Sets fields
        self.solution and self.solution_delay.
        '''
        # Note that such data block is not present in TIM and TEMIM puzzles.
        #     In these game versions, this information is probably stored in
        #     the EXE file, using some yet unknown mechanism.

        self.solution = []

        # The first 16-bit field is 1 if any solution is set, 0 if not (?)
        has_sol_short = self.read_single_short()

        for cnt_sol in xrange(solution_num_entries):
            sol_data_raw = self.read_bin_data(format_solution_entry_t2)

            sol_part_num = sol_data_raw[0]

            if sol_part_num == sol_part_num_unused:
                # "Unused" sol entry, end of block
                continue
            elif sol_part_num < sol_part_num_unused:
                # Any other negative num, raise an exception
                raise RuntimeError(self.except_text % str_err_solution_t2)

            sol_type = d_sol_t2_type_pos.get(sol_data_raw[4:],
                                             SOL_TYPE_T2_POSITION)

            # TODO, additional checks
            self.solution.append(
                SolutionInfoT2._make((sol_type, ) + sol_data_raw))

        # Check has_sol_short, see meaning above

        if has_sol_short != bool(self.solution):
            self.solution = None
            raise RuntimeError(self.except_text % str_err_solution_t2)

        # Last 2 bytes are a "delay" in the sol.checking mechanism of the game
        self.solution_delay = self.read_single_short()

    def process_sub_file(self, f_name_part, file_data, process_options):
        '''
        Re-implements process_sub_file from ResDataBase_Decoder.
        See meaning of arguments there (base.basecl)
        Decodes ....
        '''
        self.reset_conv_data()

        # FIXME: Decoders are file extension specific, and therefore
        #     process_sub_file method receives only the file name from the
        #     ResDataManager. However, for puzzles, the same object is used
        #     for 3 extensions. The file extension is important for decoding
        #     in many cases. Therefore, the file extension must be provided
        #     as process_options (str, perhaps a namedtuple later)

        file_ext_upper = process_options.upper()

        if file_ext_upper not in puzzle_file_ext_supported:
            # TODO, does not use self.except_text
            raise ValueError('Puzzle decoder: process_options: invalid '
                             ' value, must be file extension (str)')

        self.except_text = 'Puzzle decode (file "%s%s"): %%s' % (
            f_name_part, file_ext_upper)

        self.magic_num = struct.unpack_from('<L', file_data, 0)[0]

        self.game_ver = d_magic_num_game_ver.get(self.magic_num)

        # Note: this should not happen due to check in is_file_type_supported

        if self.game_ver is None:
            raise RuntimeError(self.except_text % 'Invalid magic number')

        # TIM 2 puzzles starting with puzzle_magic_num_t2_3 store the
        #     background color, preceded by an unused 0 byte directly
        #     after the magic number

        if self.magic_num in (puzzle_magic_num_t2_3, puzzle_magic_num_t3_1):
            self.backgr_color = _single_char(file_data[5])

            if (self.backgr_color > 15) or (_single_char(file_data[4]) != 0):
                raise RuntimeError(self.except_text %
                                   'Invalid background color in TIM 2 puzzle.')

            # todo, hardcoded numbers
            self.data_index = 6
        else:
            self.data_index = 4

        self.file_data = file_data
        self.process_puzzle_head(file_ext_upper)

        # Note: game_ver may be modified by process_puzzle_head

        self.puzzle_info_obj = get_puzzle_info_obj_for_ver(
            self.parent, self.game_ver)

        if self.game_ver == game_ver_tim2:
            self.process_parts_t2()
            self.process_solution_t2()
        else:
            self.process_parts_t1()

        # Check if decoder is at the end of file

        if self.data_index != len(self.file_data):
            raise RuntimeError(
                self.except_text % 'Invalid data at the end of file.')

    def get_data(self):
        '''
        Re-implements get_data from ResDataBase_Decoder.
        Returns the data as a nt_puzzle_data namedtuple.
        '''
        return nt_puzzle_data(self.game_ver, self.magic_num,
                              self.is_user_created, self.backgr_color,
                              self.puzzle_title, self.goal_descr, self.hints,
                              self.puzzle_info, self.parts, self.solution,
                              self.solution_delay)
