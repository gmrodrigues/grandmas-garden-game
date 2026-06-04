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

import os, re, stat, struct
from collections import namedtuple
from timgres.base.misc import (print_msg, rx_type, ext_file_map,
                               game_text_encoding, full_path_dir_files)

# --- Resource file reader (and related) classes ---

'''
Module containing classes for parsing resource files and reading
    sub-files from them. The base class is ResFileReader_Base. Currently
    implements the RESOURCE.MAP/RESOURCE.00? format, in class
    ResFileReader_Map_T. ResFileReader_Dir is a class that has the same API
    but reads files from a local directory instead.
'''

# nt_sub_file_info: stores the information required for reading a
#     sub-file from a game resource file.
# sub_f_name (str): The name of the sub-file
# res_file_id (int): A number associated with the resource file if
#     there are more than one such files. Zero otherwise. A negative number
#     if ....
# start_pos (int): The start position of a sub-file in the resource file,
#     in bytes.
# sub_f_size (int): Size of sub-file, in bytes.
# NOTE: "hash" information, etc., not stored

nt_sub_file_info = namedtuple(
    'nt_sub_file_info',
    ('sub_f_name', 'res_file_id', 'start_pos', 'sub_f_size'))


def _file_name_match_single(f_name, ext_or_regex):
    '''
    "Private" function, used for file name matching in ResFileReader_Base
    f_name (str): The file name to check
    ext_or_regex (str or an object returned by re.compile): The file
        extension or regular expression used in matching.
    Returns a bool value (True if f_name matches ext_or_regex)
    '''
    if isinstance(ext_or_regex, str):
        return f_name.endswith(ext_or_regex)
    else:
        return ext_or_regex.match(f_name) is not None


str_err_sub_f_not_found = 'Resource sub-file not found: %s'


class ResFileReader_Base(object):
    '''
    Base class for a reader for a specific resource file format.
    Has two abstract methods that must be re-implemented in subclasses:
        open_res_file_or_dir for opening the resource file (or, alternatively,
        a directory) and read_data_from_single_file - will read binary data
        from a sub-file when rw-implemented.
    Uses two inner dicts for the sub-files read, one containing all files and
        one filtered by extensions. Has methods for retrieving  data for bath.
    '''
    # file_ext_accepted: Accepted resource file extension or None
    #     if not relevant for the subclass.
    file_ext_accepted = None
    # res_file_id: Value for the res_file_id field in nt_sub_file_info
    #     namedtuples or None if the class has different mechanism for this
    res_file_id = None
    # keep_open: keep_open == True indicates that close_all_files should not
    #     be called for this object as part of some "automatic actions" in
    #     ResDataManager. (e.g. opening a directory but closing the currently
    #     opened resource file.)
    keep_open = False

    def __init__(self):
        '''The constructor of class. Requires no arguments.'''
        self.reset_file_exts()
        self.reset_res_data()

    def reset_file_exts(self):
        '''
        Resets the fields related to file extension/regexp based filtering.
        '''
        self.file_exts = []

    def reset_res_data_subclass(self):
        '''
        Does nothing, may be re-implemented in a sub-class.
        Provides a mechanism for adding fields that can be reset using
            self.reset_res_data()
        '''
        pass

    def close_all_files(self):
        '''
        When re-implemented in a subclass, should close all open files.
        The default implementation just calls reset_res_data()
        '''
        self.reset_res_data()

    def reset_res_data(self):
        '''
        Resets the fields that contain the data from the
            currently opened resource file.
        '''
        # res_f_name (str or None): the name of the file/directory opened
        self.res_f_name = None
        # sub_file_info, dict: key: file name, value: nt_sub_file_info
        self.sub_file_info = {}
        # sub_file_info_all: same format as sub_file_info, all files
        #     filters do not apply
        self.sub_file_info_all = {}

        self.reset_res_data_subclass()

    def get_file_ext_accepted(self):
        '''
        Returns the value of self.file_ext_accepted. This value can be used
            for choosing the appropriate resource reader based on extension.
            This value is associated with the sub-class.
        '''
        return self.file_ext_accepted

    def get_res_file_id(self):
        '''
        Returns the value of self.res_file_id. Value is an integer (typically
            negative) is this class uses a single value for res_file_id in
            nt_sub_file_info, None if some other mechanism is used.
        '''
        return self.res_file_id

    def get_keep_open(self):
        '''
        Returns the value of self.keep_open. keep_open is a boolean value
             associated with a subclass. A True value indicates that
             close_all_files() should not be called for this class as part
             of some actions in the ResDataManager.
        '''
        return self.res_file_id

    def add_file_ext(self, new_ext):
        '''
        Add a filter based on file extension or a regular expression.
        Files with names that match will be added to self.sub_file_info
        new_ext (str or ab object returned by re.compile): The file extension
            (starting with a dot) or the regexp.
        '''
        # TODO check, new_ext can also be a regular expression
        #   used for the full file name
        if not isinstance(new_ext, (str, rx_type)):
            raise RuntimeError('new_ext: must be a file extension (str) '
                               'or a compiled regex object')

        self.file_exts.append(new_ext)

    def _file_name_match(self, f_name):
        '''
        For internal use only. Used for matching based on extension or regexp.
        f_name (str): The file name to be checked
        '''
        return any(_file_name_match_single(f_name, x) for x in self.file_exts)

    def add_info_item(self, info_single):
        '''
        This method should be only called from a re-implemented
            open_res_file_or_dir method. Adds the data stored in info_single
            to self.sub_file_info_all and also to self._file_name_match if
            it matches the filters.
            info_single (nt_sub_file_info): The file information.
        '''
        sub_f_name_upper = info_single.sub_f_name.upper()

        # TODO: Currently, the matching is always case insensitive!
        # However, the original case is preserved in info_single.sub_f_name

        self.sub_file_info_all[sub_f_name_upper] = info_single

        if self._file_name_match(sub_f_name_upper):
            self.sub_file_info[sub_f_name_upper] = info_single

    def open_res_file_or_dir(self, res_f_name):
        '''
        Must be re-implemented in sub-classes
        Method for opening the resource file. An implementation must call
            add_info_item for each sub-file to store their start positions
            and sizes.
        res_f_name (str or None in some subclasses): The file or directory
            to open.
        '''
        raise NotImplementedError('open_res_file_or_dir - '
                                  'Not implemnted in ResFileReaderBase')

    def read_data_from_single_file(self, f_info):
        '''
        Must be re-implemented in subclasses
        An implementation must read the binary data from a sub-file
            and return it as a bytes object.
        f_info: a nt_sub_file_info namedtuple, from
            either self.sub_file_info or self.sub_file_info_all
        '''

        raise NotImplementedError('read_data_from_single_file - '
                                  'Not implemnted in ResFileReaderBase')

    def contains_file_nofilter(self, sub_f_name):
        '''
        Checks if file with name sub_f_name is present in the archive
            Accepts file names in self.sub_file_info_all. Returns bool.
        sub_f_name (str): The sub-file name.
        '''
        return sub_f_name in self.sub_file_info_all

    def get_single_file_data(self, sub_f_name):
        '''
        Calls read_data_from_single_file and returns the binary data
            from the sub-file (type: bytes). Accepts file names found
            in self.sub_file_info.
        sub_f_name (str): The sub-file name
        '''
        f_info = self.sub_file_info.get(sub_f_name.upper())

        if f_info is None:
            raise ValueError(str_err_sub_f_not_found % sub_f_name)

        return self.read_data_from_single_file(f_info)

    def get_single_file_data_nofilter(self, sub_f_name):
        '''
        Calls read_data_from_single_file and returns the binary data
            from the sub-file (type: bytes). Accepts file names found
            in self.sub_file_info_all.
        sub_f_name (str): The sub-file name
        '''
        f_info = self.sub_file_info_all.get(sub_f_name.upper())

        if f_info is None:
            raise ValueError(str_err_sub_f_not_found % sub_f_name)

        return self.read_data_from_single_file(f_info)

    def get_res_f_name(self):
        '''
        Returns the name of the currently opened tub-file (type: str)
            or None if nothing is opened
        '''
        return self.res_f_name

    def get_file_list_sorted(self):
        '''
        Returns a file list (type: list of strs) based on self.sub_file_info,
            in alphabetical order.
        '''
        return sorted(self.sub_file_info.keys())

    def get_file_list_nofilter_sorted(self):
        '''
        Returns a file list (type: list of strs) based on
            self.sub_file_info_all, in alphabetical order.
        '''
        return sorted(self.sub_file_info_all.keys())

    def get_file_data_nofilter(self):
        '''
        Returns a list of nt_sub_file_info namedtuples, from
            self.sub_file_info_all, not sorted.
        Order of files in the list is "undefined"/"arbitrary", only
            gor internal use.
        '''
        return list(self.sub_file_info_all.values())

    def get_file_data_sorted(self):
        '''
        Returns a list of nt_sub_file_info namedtuples, from
            self.sub_file_info, sorted by file name.
        '''
        return sorted(self.sub_file_info.values(), key=lambda x: x.sub_f_name)

    def get_file_data_nofilter_sorted(self):
        '''
        Returns a list of nt_sub_file_info namedtuples, from
            self.sub_file_info_all, sorted by file name.
        '''
        return sorted(self.sub_file_info_all.values(),
                      key=lambda x: x.sub_f_name)


# ... RESOURCE.MAP/RESOURCE.00? file format support ...

# def_open_func: default value for ResFileReader_Map_T. open_func
def_open_func = lambda x: open(x, 'rb')

# constants for (relative) positions, in bytes
map_head_bytes = 6
map_head_single_res_f_bytes = 15
map_head_single_size_f_name = 13
map_file_entry_bytes = 8
res_file_name_size_bytes = 17
res_file_size_f_name = 13

str_f_name_resource_map = 'RESOURCE.MAP'  # TODO, unused

str_err_res_map = 'RESOURCE.MAP file format error'
str_err_res = 'Resource file format error'

# see ResFileReader_T_v0a.open_res_map_file
# possible values for bytes 0-3 in RESOURCE.MAP header
head_bytes_allowed = ((0, 1), (1, 2, 3, 4), (3, 4, 5, 6), (6, 7))


class ResFileReader_Map_T(ResFileReader_Base):
    '''
    A ResFileReader_Base subclass that implements a reader for the
        RESOURCE.MAP/RESOURCE.00? resource format.
    '''

    # file_ext_accepted: See parent class, accepts extension ".MAP"
    file_ext_accepted = ext_file_map

    def __init__(self):
        '''Constructor of the class. Has no arguments.'''
        ResFileReader_Base.__init__(self)
        # res_files_open: Stores the open file/stream objects, for
        #     reading data from the resource files.
        self.res_files_open = []
        # open_func: A function that accepts a file name an returns
        #     a stream-like objects, The default function simply calls "open"
        self.open_func = def_open_func

        self.reset_file_exts()
        self.reset_res_data()

    def __del__(self):
        '''Call close_all_files automatically when the class is deleted.'''
        # TODO, should use context manager (?)
        self.close_all_files()

    def close_all_files(self):
        '''
        Closes all files, the associated file objects are stored in
            self.res_files_open. Then, calls reset.
        '''
        for f_obj in self.res_files_open:
            f_obj.close()

        self.res_files_open = []
        self.reset_res_data()  # becomes "invalid"

    def set_open_func(self, new_open_func=None):
        '''
        Provides a mechanism for using a replacement function for opening
            the input file instead of the default (def_open_func)
        new_open_func: A function that accepts a string as argument
            and returns a binary/bytes stream object. (or None)
        '''
        # TODO: currently unused

        if new_open_func is None:
            # None means restore default
            self.open_func = def_open_func
        elif callable(new_open_func):
            self.open_func = new_open_func
        else:
            raise TypeError('new_open_func: must be callable or None')

    def read_single_res_file(self, in_f_map):
        '''
        For internal use only. Called from open_res_file_or_dir
            for each RESOURCE.00? file in order to read the file names
            and other information.
        in_f_map: on opened file object
        '''
        head_data = in_f_map.read(map_head_single_res_f_bytes)
        pos_ch0 = head_data[:map_head_single_size_f_name].find(b'\x00')

        if pos_ch0 == -1:
            raise RuntimeError(str_err_res_map)

        f_name_res = head_data[:pos_ch0].decode(game_text_encoding)

        n_items = struct.unpack_from('<H', head_data,
                                     map_head_single_size_f_name)[0]

        f_name_single_res = os.path.join(os.path.dirname(self.res_f_name),
                                         f_name_res)
        res_file_id = len(self.res_files_open)

        with self.open_func(f_name_single_res) as in_f_res:
            for cnt in xrange(n_items):
                file_hash, file_offs = struct.unpack(
                    '<LL', in_f_map.read(map_file_entry_bytes))

                # TODO TODO: Add check for hash values
                in_f_res.seek(file_offs)
                file_data_res = in_f_res.read(res_file_name_size_bytes)

                pos_ch0_r = file_data_res[:res_file_size_f_name].find(b'\x00')

                if pos_ch0_r == -1:
                    raise RuntimeError(str_err_res_map)

                # fixme, should use cp437 ?
                sub_f_name = file_data_res[:pos_ch0_r].decode(
                    game_text_encoding)
                sub_f_size = struct.unpack_from('<L', file_data_res,
                                                res_file_size_f_name)[0]

                info_single = nt_sub_file_info(
                    sub_f_name, res_file_id,
                    file_offs + res_file_name_size_bytes, sub_f_size)

                self.add_info_item(info_single)

        # TODO: file is opened twice
        self.res_files_open.append(self.open_func(f_name_single_res))

    def open_res_file_or_dir(self, res_f_name):
        '''
        Re-implementation of the open_res_file_or_dir method.
        Opens the "RESOURCE.MAP" file, then the associated "RESOURCE.00?"
            files. Keeps file objects open and stores them in res_files_open.
            Calls read_single_res_file for each resource file, which in turn
            fills the dicts storing the sub-file data.
        res_f_name (str): path to "RESOURCE.MAP" file to open.
        '''
        # Calling this with res_f_name = None is equivalent to
        #     self.close_all_files()

        self.close_all_files()
        self.res_f_name = res_f_name

        if res_f_name is None: return

        # TODO: hash values are currently IGNORED!

        with self.open_func(res_f_name) as in_f_map:
            # res_map_head[:4]: "hash indices", res_map_head[4]: number of
            #   res files (?) Use namedtuple
            res_map_head = struct.unpack('<4BH', in_f_map.read(6))

            # res_map_head[2] can be 4, 5, or 6 (?) [1] can be 1 or 2?
            if any(x not in y
                   for x, y in izip(res_map_head[:4], head_bytes_allowed)):
                raise RuntimeError(str_err_res_map)

            for cnt in xrange(res_map_head[4]):
                self.read_single_res_file(in_f_map)

    def read_data_from_single_file(self, f_info):
        '''
        Re-implementation of the read_data_from_single_file method.
        Uses one of the open file objects stored in self.res_files_open
        f_info: a nt_sub_file_info namedtuple (see parent class)
        '''
        self.res_files_open[f_info.res_file_id].seek(f_info.start_pos)
        return self.res_files_open[f_info.res_file_id].read(f_info.sub_f_size)


# ... Support for reading files from a directory instead of a resource file ...

# "Special" values for res_file_id field in nt_sub_file_info, used by
#     "ResFileReader_DirBase subclasses

res_file_id_dir_opened = -1
res_file_id_dir_local_files = -2


class ResFileReader_DirBase(ResFileReader_Base):
    '''
    A ResFileReader_Base subclass that reads the files from a local
        directory instead of a game resource file. Serves as a base
        class for two subclasses.
    '''

    def open_res_file_or_dir(self, res_f_name):
        '''
        Re-implementation of open_res_file_or_dir. Uses _list_files
            for obtaining information about the files.
            See meaning of argument in parent class.
        '''
        # Calling this with res_f_name = None is equivalent to
        #     self.reset_res_data()

        self.reset_res_data()
        self.res_f_name = res_f_name

        if res_f_name is None: return

        for info_item in self.list_files_in_dir(res_f_name):
            self.add_info_item(info_item)

    def read_data_from_single_file(self, f_info):
        '''
        Re-implementation of read_data_from_single_file. Opens a single
            file in the directory scanned in open_res_file_or_dir and
            returns the binary data from it.
        f_info: a nt_sub_file_info namedtuple (see parent class)
        '''

        # NOTE: ResFileReader_Dir ignores res_file_id and start_pos in
        #     f_info (a nt_sub_file_info namedtuple)
        # self.res_f_name is the path to the directory!

        with open(os.path.join(self.res_f_name, f_info.sub_f_name),
                  'rb') as in_f:
            return in_f.read()

    def _list_files_scandir(self, dir_path):
        '''
        "Private" method. Lists files in a directory, as a list of
            nt_sub_file_info namedtuples. Requires Python 3.5+
        dir_path (str): the directory to scan
        '''
        # NOTE: ResFileReader_Dir ignores res_file_id and start_pos in
        #     nt_sub_file_info These fields will be set to zero.
        out = []
        scan_dir = os.scandir(dir_path)

        for entry in scan_dir:
            if entry.is_file():
                out.append(
                    nt_sub_file_info(entry.name, self.res_file_id, 0,
                                     entry.stat().st_size))

        # Python 3.5 compatibility hack
        if hasattr(scan_dir, 'close'): scan_dir.close()
        return out

    def _list_files_listdir(self, dir_path):
        '''
        "Private" method. For backwards compatibility, result should
            match _list_files_scandir. See meaning of argument there
        '''
        out = []

        for f_name in os.listdir(dir_path):
            f_stat = os.stat(os.path.join(dir_path, f_name))

            if stat.S_ISREG(f_stat.st_mode):
                out.append(
                    nt_sub_file_info(f_name, self.res_file_id, 0,
                                     f_stat.st_size))

        return out

    # list_files_in_dir: Select implementation based on Python version.

    list_files_in_dir = (_list_files_scandir
                         if hasattr(os, 'scandir') else list_files_listdir)


class ResFileReader_Dir(ResFileReader_DirBase):
    '''
    A ResFileReader_DirBase subclass, used for files that are located in a
        directory opened either from the GUI or CLI.
    '''
    res_file_id = res_file_id_dir_opened


class ResFileReader_LocalFilesDir(ResFileReader_DirBase):
    '''
    A ResFileReader_DirBase subclass, used for accessing files from the
        "files" subdirectory of the program (see misc.full_path_dir_files)
    '''
    res_file_id = res_file_id_dir_local_files
    keep_open = True

    def open_res_file_or_dir(self, res_f_name):
        '''
        Re-implementation of open_res_file_or_dir. Opens files from
            directory misc.full_path_dir_files
        res_f_name: Not used, must be None
        '''
        if res_f_name:
            raise ValueError(
                'ResFileReader_LocalFilesDir.open_res_file_or_dir: '
                'res_f_name argumant must be None or empty')

        ResFileReader_DirBase.open_res_file_or_dir(self, full_path_dir_files)


class ResFileReader_Combined(ResFileReader_Base):
    '''
    ResFileReader_Base subclass that allows accessing resource sub-files
        or local files from multiple ResFileReader objects.
    '''

    keep_open = True

    def __init__(self):
        '''The constructor of class. Requires no arguments.'''
        ResFileReader_Base.__init__(self)
        self.reset_res_reader_objects()

    def reset_res_reader_objects(self):
        '''
        Resets the internal data structures that store the
            associated resource reader objects
        '''
        self.res_reader_objs = {}
        self.res_reader_obj_default = None

    def close_all_files(self):
        '''
        Re-implementation of close_all_files from ResFileReader_Base.
            Temporary!
        '''
        print_msg('DEBUG: ResFileReader_Combined.close_all_files called')
        ResFileReader_Base.close_all_files(self)

    def add_res_reader_object(self, new_res_reader):
        '''
        Adds a new resource reader object used by this class.
        new_res_reader: object, type: ResFileReader_Base subclass
        '''
        if not isinstance(new_res_reader, ResFileReader_Base):
            raise TypeError(
                'new_res_reader: must be ResFileReader_Base subclass')

        res_file_id = new_res_reader.get_res_file_id()

        if res_file_id is not None:
            if res_file_id in self.res_reader_objs:
                raise RuntimeError(
                    'Duplicated res_file_id in ResFileReader_Combined')

            self.res_reader_objs[res_file_id] = new_res_reader
        elif self.res_reader_obj_default is None:
            self.res_reader_obj_default = new_res_reader
        else:
            raise RuntimeError(
                'ResFileReader_Combined supports only one ResFileReader '
                'object without a res_file_id.')

    def add_file_info_from_res_reader(self, res_reader_obj):
        '''
        Method for internal use. Adds the nt_sub_file_info objects
            from one of the associated resource reader objects
            to the internal data structures.
        '''
        for info_single in res_reader_obj.get_file_data_nofilter():
            # Note: A resource reader object has higher priority if this
            #     method was called earlier for that object.

            sub_f_name_upper = info_single.sub_f_name.upper()

            if info_single.sub_f_name not in self.sub_file_info_all:
                self.add_info_item(info_single)

    def open_res_file_or_dir(self, res_f_name):
        '''
        Re-implementation of open_res_file_or_dir. Does not open a
            resource file, but updates self.sub_file_info based on
            associated resource reader objects.
        res_f_name: Not used, must be None
        '''
        if res_f_name:
            raise ValueError('ResFileReader_Combined.open_res_file_or_dir: '
                             'res_f_name argumant must be None or empty')

        self.reset_res_data()
        self.res_f_name = None

        for res_file_id, res_reader_obj in sorted(self.res_reader_objs.items(),
                                                  key=lambda x: x[0]):
            self.add_file_info_from_res_reader(res_reader_obj)

        # Note: res_reader_obj_default has the "lowest priority"
        #     i.e. a file will not appear if found in an other object
        self.add_file_info_from_res_reader(self.res_reader_obj_default)

    def read_data_from_single_file(self, f_info):
        '''
        Re-implementation of read_data_from_single_file. Calls the
            method with the same name from one of the associated
            resource reader objects. Returns the binary data (bytes).
        f_info: a nt_sub_file_info namedtuple (see parent class)
        '''
        # Note: the resource reader object to be used is identified
        #     based on f_info.res_file_id

        res_reader_obj = self.res_reader_objs.get(f_info.res_file_id)

        if res_reader_obj is not None:
            return res_reader_obj.read_data_from_single_file(f_info)
        else:
            return self.res_reader_obj_default.read_data_from_single_file(
                f_info)
