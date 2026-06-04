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

import os, re, stat, struct, traceback, zlib
from collections import namedtuple
from timgres.base.misc import (print_msg, print_traceback, game_text_encoding,
                               full_path_dir_files, s_obj_puzzleinfov1,
                               s_obj_puzzleinfov2, s_obj_resreadlocaldir,
                               s_obj_resreadcombined)
from timgres.base.basecl import ResDataItemBase
from timgres.base.bmpdbase import flip_none, nt_process_options_bm

# --- Classes storing/managing data for puzzle decoding/viewing ---

'''
This module contains PuzzleInfoBase and the two sub-classes for TIM/TEMIM
    (PuzzleInfoT1) and TIM2/3 (PuzzleInfoT2). Also contains a callback
    function for loading the required TIM2 resource files and other helper
    functions.
'''

# Constants for game versions

game_ver_unknown = -1
# TIM (not TEMIM) demo is now treated as a separate version. Needed because
#     part entries have a significantly different format than the format
#     used in TIM full game/TEMIM (incl. TEMIM demo).
game_ver_tim_demo = 0
game_ver_tim = 1
game_ver_temim = 2
# Used for TIM and TEMIM for some "special" files, e.g. GKC
game_ver_tim_special = 3
# game_ver_tim2 is also used for TIM 3
game_ver_tim2 = 4

# Note: using the same value for "special files" TIM and TEMIM can have some
#     side effects such as accepting edited or custom GKC files that would
#     cause a crash in (original) TIM. However I do not consider this a
#     high priority - the author.

# Strings for the game_ver_* values (except -1)
game_ver_strs = ('TIM demo', 'TIM', 'TEMIM', 'TIM/TEMIM (special)', 'TIM 2')

str_music_unknown = 'unknown'


def format_music_title(music_id, music_title):
    '''
    Small helper function used by get_music_title in PuzzleInfoT1 and
    PuzzleInfoT2. Returns a string representing music_id (int) and
    music_title (str) returns str.
    '''
    return '%s (%d)' % (music_title or str_music_unknown, music_id)


class PuzzleInfoBase(ResDataItemBase):
    '''
    Puzzle info abstract base class (TODO)
    Inherits ResDataItemBase, so that the parent can be set
         using the set_parent method.
    '''

    def __init__(self):
        '''
        The constructor of PuzzleInfoBase base class. Has no arguments
            (note: sub-class constructors have).

        '''
        self.version_num = game_ver_unknown
        self.reset()
        self.reset_data()

    def reset_data(self):
        '''
        Clears data stored in the object. In parent class, it does nothing.
        '''
        pass

    def set_game_version(self, version_num):
        '''
        If a PuzzleInfoBase subclass supports multiple versions, one version
        (version_number, int, one of GAME_VER_*) consts. Can be selected by
        calling this method. Raises RuntimeError if the version
        is not supported.
        '''
        raise NotImplementedError(
            'set_game_version - Not supported in PuzzleInfoBase')

    def get_part_name(self, part_num):
        '''
        When re-implemented, Gets the name of a part for a specific game
        version. If the part number is not valid for this game, returns None.
        part_num (int): The part number. Returns str or None.
        '''
        return None

    def get_part_info(self, part_num):
        '''
        If a PuzzleInfoBase sub-class supports this, will return a game
        version specific namedtuple for a part (part_num, int). Otherwise
        returns None.
        '''
        return None

    def is_scenery_part(self, part_num):
        '''
        If a TIM version supports scenery parts, the function checks if
        a part with a given number ( part_num, int) is a scenery part or
        not. Otherwise returns False.
        '''
        return False

    def get_part_appearance_texts(self, part_num):
        '''
        Returns a subclass-specific namedtuple that contains the strings
        displayed for a puzzle part (part_num, int) in the "file info" tab
        that describe its "appearance" (e.g. was it flipped or not, ...)
        Returns None if no such info is available for the specified part.
        '''
        return None

    def get_solution_part_state_text(self, part_num, part_state_id):
        '''
        Returns a string that describes the "state" of a part,
            used for puzzle solution information on the "file info" tab.
        Returns None if such string is not available for the part and/or
            state or if the game version does not support this.
        part_num (int): the identifier of the part
        part_state_id (int): a number representing the state of a part,
            corresponds to nt_anm_sect_c_entry.part_state_id
        '''
        return None

    def get_music_title(self, music_id):
        '''
        When-re-implemented in a sub-class, returns the title of a music
        track. If the number (music_id, int) is not valid, returns
        str_music_unknown formatted using the music number
        '''
        return format_music_title(music_id, None)


info_t1_supported_ver = (game_ver_tim_demo, game_ver_tim, game_ver_temim,
                         game_ver_tim_special)

# nt_part_info_t1: Contains information for each TIM/TEMIM part
#   stored in game_data_parts_ver dict in  PuzzleInfoT1
# Meaning of fields (copied from t1pinfo.py)
#     part_id, part_name: ID and name of part. (int, str)
#     game_ver: appears first in this version (see GAME_VER* consts)
#     x_shift, y_shift: Display the part at this position relative to the
#         x, y coordinates in puzzle file. (int)
#     flip_axis_x, flip_axis_y: Optional axes for flipping. ignored when
#         anim_frame_info contains no negative item (int)
#     anim_frame_info: Contains the relevant frames either from .BMP files or
#         from info_frame_sub_image_pos for displaying the part (only the
#         "stopped" state of puzzles is supported.) 0 or positive item: frame
#         number in BMP file, negative: an item in info_frame_sub_image_pos
#         (type: tuple of ints, see t1pinfo.py)

nt_part_info_t1 = namedtuple(
    'nt_part_info_t1',
    ('part_num', 'part_name', 'game_ver', 'shift_x', 'shift_y', 'flip_axis_x',
     'flip_axis_y', 'anim_frame_info'))

# nt_part_appearance_texts_t1: Contains text in tuples for one part type,
#     used in the "File info" tab to describe the "appearance" of the part.
# Meaning of fields:
#     part_num: Number of the part (int)
#     flip_texts: Tuple of 2 strings, the first is used for an "unflipped",
#         the second for a flipped part
#     appearance_texts: Tuple of strings describing the "appearance" of the
#         part, used by PartGraphicsInfo_T1_SubImageID. Must have the same
#         length as anim_frame_info for the same part.

nt_part_appearance_texts_t1 = namedtuple(
    'nt_part_appearance_texts_t1',
    ('part_num', 'flip_texts', 'appearance_texts'))


class PuzzleInfo_T1(PuzzleInfoBase):
    '''
    PuzzleInfoBase subclass that stores information for TIM/TEMIM.
    The source of the information is the extra.t1pinfo module.
    ....
    '''

    def __init__(self):
        '''
        Re-implementation of constructor from ResDataItemBase.
            Has no arguments.
        '''
        PuzzleInfoBase.__init__(self)
        # Sets initial values for "game data". Note that this cannot be done
        #  in reset() as reset should not affect this data.
        self.game_data_parts = None
        self.game_data_music = None
        self.game_data_sub_img = None
        self.game_data_part_appearance = None
        self.game_data_checksums_dict = None

    def set_game_data(self,
                      new_parts_data=None,
                      new_parts_music=None,
                      new_data_sub_img_pos=None,
                      new_data_checksums=None,
                      new_data_part_appearance=None):
        '''
        Stores data from extra.t1pinfo module if this module is present.
            new_parts_data: list of tuples, see extra.t1pinfo
        '''
        self.game_data_parts = new_parts_data
        self.game_data_music = new_parts_music
        self.game_data_sub_img = new_data_sub_img_pos
        self.game_data_part_appearance = new_data_part_appearance

        # game_data_checksums_dict: key: resource sub-file (str),
        #     value: checksum (int)
        self.game_data_checksums_dict = {}

        # Fill game_data_checksums_dict
        if new_data_checksums:
            for group_id, sub_f_name, file_crc32 in new_data_checksums:
                self.game_data_checksums_dict[sub_f_name] = file_crc32

    def reset(self):
        '''
        Re-implements set_game_version (PuzzleInfoBase). Clears game version
        specific data. Usually called when setting a new version.
        '''
        self.version_num = game_ver_unknown
        # game_data_parts_ver: key: part number, value:  nt_part_info_t1
        self.game_data_parts_ver = {}
        # game_data_music_ver: key music ID, value: music title
        self.game_data_music_ver = {}
        # self.game_data_part_appearance_ver key: part number, value:
        #     nt_part_appearance_texts_t1
        self.game_data_part_appearance_ver = {}

    def set_game_version(self, version_num):
        '''
        Re-implements set_game_version (PuzzleInfoBase). Supports "versions"
            game_ver_tim_demo, game_ver_tim, game_ver_temim and
            game_ver_tim_special.
        '''
        if version_num not in info_t1_supported_ver:
            raise ValueError('Unsupported game version %d' % version_num)

        # If the version number matches, no action needed
        if version_num == self.version_num:
            return

        self.reset()
        self.version_num = version_num

        if self.game_data_parts is None:
            return  # TODO, print warining message. TODO: music but no parts?

        # Fill game_data_parts_ver

        for part_num, part_name, game_ver,shift_x, shift_y, flip_axis_x, \
                flip_axis_y, anim_frame_info in self.game_data_parts:

            if game_ver <= version_num:
                self.game_data_parts_ver[part_num] = nt_part_info_t1(
                    part_num, part_name, game_ver, shift_x, shift_y,
                    flip_axis_x, flip_axis_y,
                    self.convert_anim_info_tuple(part_num, anim_frame_info))

        # Fill game_data_part_appearance_ver

        if self.game_data_part_appearance:
            for part_num, flip_texts, appearance_texts in \
                    self.game_data_part_appearance:

                if part_num in self.game_data_parts_ver:
                    self.game_data_part_appearance_ver[
                        part_num] = nt_part_appearance_texts_t1(
                            part_num, flip_texts, appearance_texts)

        if self.game_data_music is None:
            return  # TODO, print warning message

        for music_id, music_title, game_ver in self.game_data_music:
            if game_ver <= version_num:
                self.game_data_music_ver[music_id] = music_title

    def get_part_name(self, part_num):
        '''
        Re-implementation of get_part_name from PuzzleInfoBase.
        See meaning of arguments there.
        '''

        part_info = self.game_data_parts_ver.get(part_num)

        return part_info[1] if part_info is not None else None

    def get_part_info(self, part_num):
        '''
        Re-implementation of get_part_info from PuzzleInfoBase.
        See meaning of arguments there.
        '''

        return self.game_data_parts_ver.get(part_num)

    def get_part_appearance_texts(self, part_num):
        '''
        Re-implementation of get_part_appearance_texts from PuzzleInfoBase.
        See meaning of arguments there.
        '''
        return self.game_data_part_appearance_ver.get(part_num)

    def get_music_title(self, music_id):
        '''
        Re-implementation of get_music_title from PuzzleInfoBase.
        See meaning of arguments there.
        '''

        if self.game_data_music_ver is not None:
            music_title = self.game_data_music_ver.get(music_id)
        else:
            music_title = None

        return format_music_title(music_id, music_title)

    def convert_anim_info_tuple(self, part_num, in_anim_data):
        '''
        Heler method for internal use. Works on anim frame tuples in
        self.game_data_parts. Returns a modified tuple in which "relative"
        indices were converted to "absolute" ones in self.game_data_sub_img
        part_num (int): the part number
        in_anim_data: the input tuple, see format in vd_sdata.py
        '''
        if not in_anim_data:  # TODO, type check
            return (0, )

        # All items are BMP file indices, not anim. frame indices, do nothing
        #   (This is needed due to part number check)
        if all(x >= 0 for x in in_anim_data):
            return in_anim_data

        data_sub_img_index = None

        for data_index, data_item in enumerate(self.game_data_sub_img):
            if len(data_item) > 1:  # Skip potential "empty" items
                # Note item #0 is always an "information" tuple
                # Check part number of first entry
                if data_item[1][0] == part_num:
                    data_sub_img_index = data_index
                    break

        if data_sub_img_index is None:
            raise RuntimeError(('PuzzleInfoT1: Error, invalid data '
                                'for part %d') % part_num)

        return tuple((x - data_sub_img_index if x < 0 else x) \
                     for x in in_anim_data)

    def get_stored_checksum(self, res_sub_f_name):
        '''
        Returns the checksum  (int) stored for image resource file
        res_sub_f_name if present, None otherwsie.
        '''
        return self.game_data_checksums_dict.get(res_sub_f_name)


# TODO: should be moved to misc?
s_res_file_t2_info = 'INFO.RES'
s_res_file_t2_music = 'MUSIC.RES'
s_res_file_t2_solve = 'SOLVE.RES'
# Note: scenery_part_block_start is not the first scenery part, but
#   after this number, all parts are scenery
scenery_part_block_start = 149  # TODO
scenery_part_last = 280  # TODO
str_part_scenery = '(scenery)'

str_solve_part_line = '!Part'
str_err_solve_res_parse = 'Failed to parse file "%s"' % s_res_file_t2_solve

# nt_part_info_t2: Contains (very limited) information on a TIM 2 part.
#   part_id, part_name: ID and name of part.
#   is_scenery: True if part is scenery, with a number
#     below scenery_part_block_start

nt_part_info_t2 = namedtuple('nt_part_info_t2',
                             ('part_num', 'part_name', 'is_scenery'))

# nt_part_appearance_texts_t2: Contains text in tuples for one part type,
#     used in the "File info" tab to describe the "appearance" of the part.
# Meaning of fields:
#     part_num: Number of the part (int)
#     flip_texts: Tuple of 2 strings, the first is used for an "unflipped",
#         the second for a flipped part
#     appearance_text_dict: Dict, key is the part number, value is a string.
#         the description of the "appearance". May be None.
#     behavior_text_dict: Dict, key is the part number, value is a string.
#         the description of the "behavior". May be None.
#     extra_data: Part specific data, currently used only for the
#         programmable ball and the accelerator pipe. None if not present.

nt_part_appearance_texts_t2 = namedtuple(
    'nt_part_appearance_texts_t2',
    ('part_num', 'flip_texts', 'appearance_text_dict', 'behavior_text_dict',
     'extra_data'))


class PuzzleInfo_T2(PuzzleInfoBase):
    '''
    PuzzleInfoBase subclass that stores information for TIM 2 and TIM 3.
    The class parses three resource files that contains
    the names of the parts, texts for programmed puzzle solutions,
    as well as the titles of music tracks.
    ....
    '''

    res_file_name_info = s_res_file_t2_info
    res_file_name_music = s_res_file_t2_music
    res_file_name_solve = s_res_file_t2_solve

    def __init__(self):
        '''
        Re-implementation of constructor from ResDataItemBase.
            Has no arguments.
        '''
        PuzzleInfoBase.__init__(self)
        self.game_data_part_appearance_t2 = None

    def set_game_data(self, new_data_part_appearance=None):
        '''
        Stores data from extra.t1pinfo module if this module is present.
            new_data_part_appearance: list of tuples, see extra.t2pinfo
        '''
        self.game_data_part_appearance_t2 = new_data_part_appearance

    def reset(self):
        '''
        Re-implements set_game_version (PuzzleInfoBase). Clears game version
        specific data. Usually called when setting a new version.
        '''
        self.version_num = game_ver_unknown
        # data_parts_t2: key: part number, value:
        #     (part_name (str), is_scenery (bool)) tuple
        self.data_parts_t2 = {}
        # data_music_t2: key music ID, value: music title (str)
        self.data_music_t2 = {}
        # data_solve_t2: key: (part number, state id) tuple,
        #     value? part state (str)
        self.data_solve_t2 = {}
        # game_data_part_appearance_t2_dict key: part number, value:
        #     nt_part_appearance_texts_t2
        self.game_data_part_appearance_t2_dict = {}

    def set_game_version(self, version_num):
        '''
        Re-implements set_game_version (PuzzleInfoBase).
        Supports only game_ver_tim2.
        '''

        if version_num != game_ver_tim2:
            raise ValueError('Unsupported game version %d' % version_num)

        # If the version number matches, no action needed
        # Note: The version is always TIM 2 so this will called only once
        #   per game resource file open. However, open_res_callback_t2data
        #   always calls reset(), therefore resource files will be parsed
        #   again if a new resource file is opened.
        # TODO: duplicates PuzzleInfoT1

        if version_num == self.version_num:
            return

        self.reset()
        self.version_num = version_num

        # Note: no "decoder" object is used for these file types
        # TODO: uses the res_read_obj from self.parent directly
        #    and uses the "nofilter" functions

        try:
            obj_resread = self.parent.get_res_read_obj()

            self.process_res_file_info(
                obj_resread.get_single_file_data_nofilter(
                    self.res_file_name_info).decode(game_text_encoding))
            self.process_res_file_music(
                obj_resread.get_single_file_data_nofilter(
                    self.res_file_name_music).decode(game_text_encoding))
            self.process_res_file_solve(
                obj_resread.get_single_file_data_nofilter(
                    self.res_file_name_solve).decode(game_text_encoding))
        except Exception as ex:
            # TODO, reset data on error. Exception will be re-raised.
            self.reset()
            raise ex

        # Fill game_data_part_appearance_t2_dict

        if self.game_data_part_appearance_t2:
            # Note: length varies, we cannot use the "more elegant"
            #      solution here (i.e. for part_num, flip_texts, ... in ...)
            for part_a_item in self.game_data_part_appearance_t2:
                part_num, flip_texts = part_a_item[:2]

                if part_num in self.data_parts_t2:
                    # Make copy of dicts
                    appearance_d_copy = (dict(part_a_item[2].items())
                                         if part_a_item[2] else None)

                    if len(part_a_item) > 3:
                        behavior_d_copy = (dict(part_a_item[3].items())
                                           if part_a_item[3] else None)
                    else:
                        behavior_d_copy = None

                    # Note: extra_data not copied!
                    extra_data = (part_a_item[4]
                                  if len(part_a_item) == 5 else None)

                    self.game_data_part_appearance_t2_dict[
                        part_num] = nt_part_appearance_texts_t2(
                            part_num, flip_texts, appearance_d_copy,
                            behavior_d_copy, extra_data)

    def get_part_name(self, part_num):
        '''
        Re-implementes get_part_name rom PuzzleInfoBase ....
        '''
        if part_num < 0:
            return None  # TODO

        if part_num < scenery_part_block_start:
            part_info = self.data_parts_t2.get(part_num)
            # TODO: str_part_scenery for scenery parts?
            return part_info.part_name if part_info is not None else None
        elif part_num <= scenery_part_last:
            return str_part_scenery

        # otherwise, returns None

    def is_scenery_part(self, part_num):
        '''
        Re-implementes is_scenery_part from PuzzleInfoBase ....
        '''
        # FIXME, duplication, get_part_name
        if part_num < 0:
            return False  # TODO

        if part_num < scenery_part_block_start:
            part_info = self.data_parts_t2.get(part_num)
            return part_info.is_scenery if part_info is not None else False
        elif part_num <= scenery_part_last:
            return True

    def get_part_appearance_texts(self, part_num):
        '''
        Re-implementation of get_part_appearance_texts from PuzzleInfoBase.
        See meaning of arguments there.
        '''
        return self.game_data_part_appearance_t2_dict.get(part_num)

    def get_solution_part_state_text(self, part_num, part_state_id):
        '''
        Re-implementation of get_solution_part_state_text from PuzzleInfoBase.
        See meaning of arguments there.
        '''
        return self.data_solve_t2.get((part_num, part_state_id))

    def get_music_title(self, music_id):
        '''
        Re-implementes get_music_title from PuzzleInfoBase ....
        '''
        # FIXME, duplication...
        if self.data_music_t2 is not None:
            music_title = self.data_music_t2.get(music_id)
        else:
            music_title = None

        return format_music_title(music_id, music_title)

    def process_res_file_info(self, file_data):
        '''
        Parses the INFO.RES resource file in TIM 2/TIM 3
        file_data (str): file data converted to unicode string
        '''
        # Note: line separator is \r\n, splitlines() should handle this
        #     correctly on all platform (and ignores \r\n at the end of file)
        # Note: SOLVE.RES also contains part names. We use INFO.RES here
        #     because it contains reliable information for identifying
        #     scenery parts with numbers below 148.

        for line in file_data.splitlines():
            if not line: continue

            # One part in each line, 3 fields separated by tabs:
            #   1. part number (may start with spaces, ends with dot),
            #   2. name 3. description (contains "scenery" if this is a
            #      scenery part with a number < 148)
            # Note: may raise various exceptions on error
            l_split = line.split('\t')

            part_num = int(l_split[0].rstrip('.'))
            self.data_parts_t2[part_num] = nt_part_info_t2(
                part_num, l_split[1], 'scenery' in l_split[2])

    def process_res_file_music(self, file_data):
        '''
        Parses the MUSIC.RES resource file in TIM 2/TIM 3
        file_data (str): file data converted to unicode string
        '''
        for line in file_data.splitlines():
            if not line: continue

            music_id_s, music_title = line.split(' ', 1)
            self.data_music_t2[int(music_id_s)] = music_title

    def process_res_file_solve(self, file_data):
        '''
        Parses the SOLVE.RES resource file in TIM 2/TIM 3
        file_data (str): file data converted to unicode string
        '''
        # Note: This field also contains part names, however, we use
        #     INFO,RES instead of SOLVE.RES for that purpose. It is also
        #     missing the name for part 22.
        part_name_line = False
        part_num = None
        part_state_ids = []

        for line in file_data.splitlines():
            line_strip = line.rstrip()

            if not line_strip: continue

            if line.startswith(str_solve_part_line):
                # Note: For some parts, there is a space between
                #     '!Part' and the part number, for others, there
                #      is no space. int() accepts numbers preceded by
                #      a space.
                if part_state_ids:
                    raise RuntimeError(str_err_solve_res_parse)

                if line_strip != str_solve_part_line:
                    part_num = int(line[5:])
                else:
                    # HACK for missing part number
                    if part_num is None:
                        raise RuntimeError(str_err_solve_res_parse)

                    part_num += 1

                part_name_line = True
                continue

            # Line starting with @ refer to parts that cannot have
            #     "part states"

            if part_name_line or line.startswith('@'):
                part_name_line = False
                continue

            if part_num is None:
                raise RuntimeError(str_err_solve_res_parse)

            if part_state_ids:
                for state_id in part_state_ids:
                    self.data_solve_t2[(part_num, state_id)] = line_strip

                part_state_ids = []
            else:
                for line_item in line_strip.split():
                    if ',' not in line_item:
                        raise RuntimeError(str_err_solve_res_parse)

                    part_state_ids.append(int(line_item.split(',', 1)[0]))


def get_puzzle_info_obj_for_ver(res_data_mgr, version_num):
    '''
    Helper function for obtaining the appropriate puzzle info object for a
    puzzle version. Calls the set_game_version method of the object.
    res_data_mgr: The ResDataManager object.
    version_num (imt):
    Returns the object (PuzzleInfoBase sub-class) from res_data_mgr
    '''

    if version_num in info_t1_supported_ver:
        info_obj = res_data_mgr.get_object(s_obj_puzzleinfov1)
    elif version_num == game_ver_tim2:
        info_obj = res_data_mgr.get_object(s_obj_puzzleinfov2)
    else:
        raise ValueError('Unsupported game version: %d' % version_num)

    info_obj.set_game_version(version_num)
    return info_obj


def open_res_callback_t2_data(res_data_mgr):
    '''
    A ResDataManager callback function for reading TIM 2 / 3 string resource
        data. At present, loads part and music information.
    res_data_mgr: The ResDataManager object.
    '''
    # TODO, this callback is not absolutely necessary for the program to work
    obj_puzzle_info_t2 = res_data_mgr.get_object(s_obj_puzzleinfov2)
    obj_resread = res_data_mgr.get_res_read_obj()

    # Always calls reset see comment in PuzzleInfoT2
    obj_puzzle_info_t2.reset()

    # To make sure no data from a different version of the game was left
    #      in the fields of the object, do this for puzzle_info_t1, too
    res_data_mgr.get_object(s_obj_puzzleinfov1).reset()

    if obj_resread.contains_file_nofilter(s_res_file_t2_info):
        obj_puzzle_info_t2.set_game_version(game_ver_tim2)


# TODO, hardcoded crc32 checksum

s_res_file_bmp_file_rope = 'PART10.BMP'
stored_file_name_rope = '_ROPEEND.BMP'


def open_res_callback_temim_store_img(res_data_mgr):
    '''
    A ResDataManager callback function that reads the graphics from resource
        sub-file s_res_file_bmp_file_rope, and stores a local directory
        (name: stored_png_name_rope)
    res_data_mgr: The ResDataManager object.
    '''
    # NOTE: This is a temporary solution as TIM 1 does not have an image
    #    in the resource file for the "rope end" graphics it and it is
    #    currently not known how/where this version stores the bitmap.

    obj_resread = res_data_mgr.get_res_read_obj()

    if obj_resread.contains_file_nofilter(stored_file_name_rope):
        return

    rope_end_file_checksum = res_data_mgr.get_object(
        s_obj_puzzleinfov1).get_stored_checksum(s_res_file_bmp_file_rope)

    if rope_end_file_checksum is None:
        return

    # Do not attempt to decode resource sub-file s_res_file_bmp_file_rope
    #     if this is TIM 2

    if obj_resread.contains_file_nofilter(s_res_file_t2_info):
        return

    if not obj_resread.contains_file_nofilter(s_res_file_bmp_file_rope):
        # No warning, this is expected when the resource file from
        #     TIM 1 is opened
        return

    file_data = obj_resread.get_single_file_data_nofilter(
        s_res_file_bmp_file_rope)

    # & 0xffffffff: For Python 2 compatibility
    if (zlib.crc32(file_data) & 0xffffffff) != rope_end_file_checksum:
        # Note that this warning will not be shown if the resources from
        #     TIM 2 are opened
        print_msg(('Warning: Opened resource file contains a file %s, but '
                   'checksum does not match') % s_res_file_bmp_file_rope)
        return

    saved_file_path = os.path.join(full_path_dir_files, stored_file_name_rope)

    try:
        with open(saved_file_path, 'wb') as saved_png_f:
            saved_png_f.write(file_data)
    except (OSError, IOError) as ex:
        print_msg('Error: I/O error while saving file %s' % saved_file_path)
        print_traceback()

    # Trigger update in both s_obj_resreadlocaldir and s_obj_resreadcombined
    res_data_mgr.get_object(s_obj_resreadlocaldir).open_res_file_or_dir(None)
    res_data_mgr.get_object(s_obj_resreadcombined).open_res_file_or_dir(None)
