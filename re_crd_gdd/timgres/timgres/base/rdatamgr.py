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

import os
from collections import namedtuple
from timgres.base.basecl import ExporterObjectManagerBase, ResDataBase_Decoder
from timgres.base.vdobase import ResDataBase_ViewerDataObj
# (???) , nt_obj_manager_option
from timgres.base.resfile import ResFileReader_Base
from timgres.base.misc import (s_res_file_special, s_obj_resreadcombined,
                               is_file_type_supported_n_bytes)

# --- Tree Data ---

'''
Module that contain the base "resource data manager" base class
    (ResDataManager) that performs multiple tasks related to resource files.
'''

str_err_file_ext = 'file_ext: must start with "."'
# NOTE: This class has two types of "special" objects, decoder, and
#   view_data_obj. See information in corresponding add_* functions

# nt_file_ext_descr: Used for retrieving the information stored about
#     a supported file extension.
# file_ext (str): the file extension (e.g '.BMP')
# file_ext_descr (str): A short description of the file type, set by
#     ResDataManager.add_file_ext_descr
nt_file_ext_descr = namedtuple('nt_file_ext_descr',
                               ('file_ext', 'file_ext_descr'))
# nt_tree_item_info: Used for returning data that will be displayed
#    in a "tree viewer" form. Currently used for the sub-items
#    of a "viewer data object"
# tree_item_id (str): todo, add documentation
# tree_item_descr (str): todo, add documentation

nt_tree_item_info = namedtuple('nt_tree_item_info',
                               ('tree_item_id', 'tree_item_descr'))

# nt_viewer_obj_info_ext: Used for retrieving data about the
#     "viewer data objects" associated with specific file extensions.
# file_ext (str): the file extension (e.g '.BMP')
# is_default (bool): True if this is the default "viewer data object" for
#     the extension
# obj_id (str): the "viewer data object" ID
# obj_descr (str): short description associated with the object

nt_viewer_obj_info_ext = namedtuple(
    'nt_viewer_obj_info_ext',
    ('file_ext', 'is_default', 'obj_id', 'obj_descr'))


class ResDataManager(ExporterObjectManagerBase):
    '''
    Base class that performs many tasks related to resources.
    It is an object manager subclass, therefore all subclasses will have
        "objects" and "options" (see definitions in base.basecl module.)
    "Inherits" the support for exporters from ExporterObjectManagerBase.
    Has two types of "special" objects, stored in separate dicts:
        Decoders that decode a sub-file with a specific format
            (see ResDataBase_Decoder in module base.basecl)
        "Viewer data objects" that store the data extracted from the resource
            sub-files in a way that is suitable for displaying the images
            contained in them, showing animations and presenting the data
            in a "table" format. (ResDataBase_ViewerDataObj in base.vdobase)
    '''

    # NOTE: all items moved to sub_class.
    # options_default = () # from ObjectManagerBase, NOT modified!

    def __init__(self):
        '''The constructor of the class. Requires no arguments.'''
        ExporterObjectManagerBase.__init__(self)
        self.reset_res_objects()
        self.create_default_objects_resdata()  # fixme

    def reset_res_objects(self):
        '''
        Resets the internal data structures that store the objects
            and other information.
        See also ObjectManagerBase.reset_objects()
        '''
        # self.decoders: key: file ext (str), value list (of objects)
        self.decoders = {}
        # self.viewer_data_objs: key: file ext (str),
        #   value dict, identifier: object
        self.viewer_data_objs = {}
        # self.file_ext_descr: key: file extension, value: description
        # TODO: currently stored in a completely separate dict
        self.file_ext_descr = {}
        # open_res_callback_funcs: key: function name (order is important!)
        #   value: callable, called with self as only arg
        self.open_res_callback_funcs = {}
        self.selected_viewer_data_objs_ext = None
        self.selected_sub_f_name = None

    def create_default_objects(self):
        '''Method for creating the default objects.'''
        # NOTE: All objects that are used in this source file should be created
        #    here Everything else should be moved to a subclass
        # NOTE: Currently, a "placeholder" is created here
        self.res_reader_obj = None

    def create_default_objects_resdata(self):
        '''
        May be re-implemented in sub-classes.
        Provides a mechanism for creating objects in sub-classes.
        '''
        pass  # may be re-implemented in a sub-class

    def get_res_read_obj(self):
        '''
        Returns the currently selected resource reader object.
        Type: ResFileReader_Base subclass
        '''
        # NOTE: Currently, res_reader_obj is always s_obj_resreadcombined
        #     In later versions, this might change
        return self.res_reader_obj

    def add_decoder(self, file_ext, decoder_obj):
        '''
        Adds a new decoder object for the specified file type.
        file_ext (str): a file extension, must start with '.'
            (s_res_file_special is also an accepted value.)
        decoder_obj (type: ResDataBase_Decoder subclass):
            The decoder object to add.
        '''
        # file_ext: a file extension, must start with '.'
        #   unlike viewer_data_obj, None is NOT a possible value

        # NOTE: Decoders have no "name/ID", unlike ViewerDataObjs and open
        #    callbacks. Instead, decoders have an "is_file_type_supported"
        #    method that can be used for the selection the appropriate decoder

        if not file_ext.startswith('.'):  # fixme, no type check
            raise ValueError(str_err_file_ext)

        if not isinstance(decoder_obj, ResDataBase_Decoder):
            raise TypeError(
                'decoder_obj must be a ResDataBase_Decoder subclass')

        # Case insensitive for file extension
        file_ext_upper = file_ext.upper()
        decoder_l_ext = self.decoders.get(file_ext_upper)

        if decoder_l_ext is not None:
            decoder_l_ext.append(decoder_obj)
        else:
            self.decoders[file_ext_upper] = [decoder_obj]

        decoder_obj.set_parent(self)

        # TODO, resource reader objects should be stored separated from
        #     all other objects

        for obj_name, obj in self.objects.items():
            if isinstance(obj, ResFileReader_Base):
                # _file_name_match should work for extensions
                if not obj._file_name_match(file_ext_upper):
                    obj.add_file_ext(file_ext_upper)

    def decode_sub_file(self, sub_f_name, process_options=None):
        '''
        Decodes a resource sub-file, using a decoder object stored in
            self.decoders. Calls the is_file_type_supported() method
            for all decoders associated with a file type, to determine
            which object can decode the file. If this fails, raises
            RuntimeError. Returns the decoded data (type: data type
            specific namedtuple).
        sub_f_name (str): The resource sub-file to decode.
        process_options (class-specific namedtuple or None): Optional
            "process options", passed to the decoder object.
        '''
        if not isinstance(sub_f_name, str):
            raise TypeError('sub_f_name: must be str')

        name_part, file_ext = os.path.splitext(sub_f_name)
        # Case insensitive for file extension
        file_ext_upper = file_ext.upper()
        decoder_l_ext = self.decoders.get(file_ext_upper)

        if decoder_l_ext is None:
            raise RuntimeError(
                'No decoder exists for extension "%s"' % file_ext)

        file_data = self.get_res_read_obj().get_single_file_data(sub_f_name)

        for decoder in decoder_l_ext:
            if decoder.is_file_type_supported(
                    file_data[:is_file_type_supported_n_bytes]):
                decoder.process_sub_file(name_part, file_data, process_options)
                return decoder.get_data()

        raise RuntimeError('Decode file "%s": File extension is "%s", but  '
                           'no decoder can handle it' % (sub_f_name, file_ext))

    def add_viewer_data_obj(self, file_ext, viewer_data_obj):
        '''
        Adds a new "viewer data object" for a supported file extension.
        file_ext (str): a file extension, must start with '.'
            (s_res_file_special is also an accepted value.)
        viewer_data_obj (type: ResDataBase_ViewerDataObj subclass):
            The viewer object to add.
        '''

        if not isinstance(file_ext, str):
            raise TypeError('file_ext: must be str')

        if not isinstance(viewer_data_obj, ResDataBase_ViewerDataObj):
            raise TypeError('viewer_data_obj must be a '
                            'ResDataBase_ViewerDataObj subclass')

        if (not file_ext.startswith('.')) and (file_ext != s_res_file_special):
            # fixme, no type check TODO: s_res_file_special is not mentioned
            raise ValueError(str_err_file_ext)

        # Case insensitive for file extension
        file_ext_upper = (file_ext.upper()
                          if file_ext != s_res_file_special else file_ext)

        t_viewer_d_obj_l_ext = self.viewer_data_objs.get(file_ext_upper)
        obj_id = viewer_data_obj.get_obj_identifier()

        if t_viewer_d_obj_l_ext is not None:
            t_viewer_d_obj_l_ext[obj_id] = viewer_data_obj
        else:
            self.viewer_data_objs[file_ext_upper] = {obj_id: viewer_data_obj}

        viewer_data_obj.set_parent(self)

    def tree_reset_viewer_objs(self, sub_dict=None):
        '''
        For internal use. Resets all viewer data objects associated
            with the currently selected file type. Or, alternatively,
            a sub-dictionary of self.viewer_data_objs can be provided as
            an argument.
        sub_dict: a self.viewer_data_objs sub-dict or None
        '''
        if sub_dict is not None:
            sub_dict_2 = sub_dict
        else:
            if self.selected_viewer_data_objs_ext is None: return

            sub_dict_2 = self.viewer_data_objs[ \
                self.selected_viewer_data_objs_ext]

        for sel_obj in sub_dict_2.values():
            sel_obj.reset_data()

    def tree_select_sub_file(self, sub_f_name):
        '''
        Method for selecting a resource sub-file. Sets
            self.selected_viewer_data_objs_ext and self.selected_sub_f_name
            and calls open_sub_file for each viewer data object associated
            with the extension.
        sub_f_name (str or None): a sub-file name, s_res_file_special or None
        '''
        # sub_f_name (str or None): a sub-file name, s_res_file_special or None
        if not (isinstance(sub_f_name, str) or (sub_f_name is None)):
            raise TypeError('file_ext: must be str or None')

        # clear selection
        if self.selected_viewer_data_objs_ext is not None:
            self.tree_reset_viewer_objs()

        if sub_f_name is None:
            self.selected_viewer_data_objs_ext = None
            self.selected_sub_f_name = None
            return

        if sub_f_name != s_res_file_special:
            name_part, file_ext = os.path.splitext(sub_f_name)
            # Case insensitive for file extension
            file_ext_upper = file_ext.upper()
        else:
            file_ext_upper = s_res_file_special

        sub_dict = self.viewer_data_objs.get(file_ext_upper)

        if sub_dict is None:
            self.tree_reset_viewer_objs()
            self.selected_viewer_data_objs_ext = None
            self.selected_sub_f_name = None
            raise RuntimeError(
                'Select sub-file "%s": extension not supported' %
                file_ext_upper)

        try:
            # in "deterministic" order !
            for d_key, sel_obj in sorted(sub_dict.items(), key=lambda x: x[0]):
                sel_obj.open_sub_file(sub_f_name)

            self.selected_viewer_data_objs_ext = file_ext_upper
        except Exception as ex:
            self.tree_reset_viewer_objs(sub_dict)
            self.selected_viewer_data_objs_ext = None
            self.selected_sub_f_name = None
            raise ex  # fixme

        self.selected_sub_f_name = sub_f_name

    def get_viewer_info_for_ext(self, file_ext):
        '''
        Returns a list of nt_tree_item_info, containing the ID and the
            description, for file extension file_ext.
        Return type: List of nt_tree_item_info. For internal use.
        file_ext (str): The file extension (or s_res_file_special)
        '''
        # NOTE: for "internal" use only does not uppercase the extension!
        # NOTE: may raise KeyError
        return sorted((nt_tree_item_info(k, v.get_obj_description())
                       for k, v in self.viewer_data_objs[file_ext].items()),
                      key=lambda x: x.tree_item_id)

    def get_viewer_item_info_for_selection(self):
        '''
        Returns a list of nt_tree_item_info, containing the ID and the
            description, for the currently selected extension.
            Returns an empty list if nothing is selected.
        Return type: List of nt_tree_item_info
        '''
        if self.selected_viewer_data_objs_ext is None:
            # unlike selected_viewer_data_objs_ext, does not raise exception
            return []

        return self.get_viewer_info_for_ext(self.selected_viewer_data_objs_ext)

    def get_viewer_obj_info_for_ext(self, file_ext):
        '''
        Returns a list of nt_viewer_obj_info_ext, containing information
            about the viewer object, for one file extension.
        Return type: List of nt_viewer_obj_info_ext
        file_ext (str): The file extension (or s_res_file_special)
        '''
        # NOTE: for "internal" use only does not uppercase the extension!
        # NOTE: get_default_viewer_id_for_file() is primarily for file names,
        #   not extensions, "hacked" to work
        def_viewer_id = self.get_default_viewer_id_for_file(
            '_' +
            file_ext if file_ext != s_res_file_special else s_res_file_special)

        return [
            nt_viewer_obj_info_ext(file_ext, x == def_viewer_id, x, y)
            for x, y in self.get_viewer_info_for_ext(file_ext)
        ]

    def get_viewer_info_for_all_ext(self):
        '''
        Returns a list of nt_viewer_obj_info_ext, containing information
            about the viewer objects, for all available file types.
        Return type: List of nt_viewer_obj_info_ext
        '''
        ext_list_sorted = sorted(self.viewer_data_objs.keys())
        return list(
            itertools.chain.from_iterable(
                self.get_viewer_obj_info_for_ext(x) for x in ext_list_sorted))

    def get_viewer_obj_for_selection(self, obj_id):
        '''
        Returns the viewer data object with ID obj_id, form the dictionary
            of the objects associated with the currently selected file
            extension. Return type: ResDataBase_ViewerDataObj subclass
        obj_id: The object ID for the viewer object to retrieve
        '''
        if self.selected_viewer_data_objs_ext is None:
            raise RuntimeError('Nothing is selected.')

        # TODO, may raise KeyError (if selected_viewer_data_objs_ext is invalid)
        sel_obj = self.viewer_data_objs[
            self.selected_viewer_data_objs_ext].get(obj_id)

        if sel_obj is None:
            raise RuntimeError('"%s": No such sub item' % obj_id)

        return sel_obj

    def get_viewer_obj_by_id(self, file_ext, obj_id):
        '''
        For internal use only. get_viewer_obj_for_selection() should be used
            in most cases. Returns a Viewer object by file extension
            (file_ext) and object ID (obj_id). Raises KeyError if one of
            the args is invalid. Return type: ResDataBase_ViewerDataObj subcl.
        file_ext (str): The file extension (or s_res_file_special)
        obj_id (str): The ID of the viewer data object.
        '''
        return self.viewer_data_objs[file_ext][obj_id]

    def add_file_ext_descr(self, file_ext, new_descr):
        '''
        Adds a short description for a supported file type (by file ext).
        file_ext (str): The file extension associated with the file type.
        new_descr (str): The description to add.
        '''
        if not (isinstance(file_ext, str) and isinstance(new_descr, str)):
            raise TypeError('file_ext, new_descr: must be str')

        # TODO: check if extension starts with a "."
        #   does not check if the extension is actually supported
        # Case insensitive for file ext
        self.file_ext_descr[file_ext.upper()] = new_descr

    def get_file_list_by_ext(self):
        '''
        Returns the files from the open resource file, grouped by extension.
            (Only file types where a viewer object is available are returned)
        Result is a tuple. First item is a list of nt_file_ext_descr
            namedtuples, one for each supported file type. Second item is
            a list of lists, with the same number of items as the first member
            of returned tuple. Modified: "Inner" lists contain
            nt_sub_file_info namedtuples sorted by name
        '''
        file_data = self.get_res_read_obj().get_file_data_sorted()

        # TODO, only returns file types with a description available
        #   in self.file_ext_descr

        out_f_ext_descr = []
        out_files = []

        for f_ext, f_ext_descr in sorted(self.file_ext_descr.items(),
                                         key=lambda x: x[1]):
            out_f_ext_descr.append(nt_file_ext_descr(f_ext, f_ext_descr))
            out_files.append(
                [x for x in file_data if x.sub_f_name.upper().endswith(f_ext)])

        return out_f_ext_descr, out_files

    def get_default_viewer_id_for_file(self, f_name):
        '''
        Returns the default viewer data object ID for a file name
            by file extension. Returns str (the object ID).
        f_name (str): A file name.
        '''
        # At present, "hardcoded" to the first object in "alphabetical order"
        #     (of the ID) NOTE: min() will raise ValueError for empty dict

        if f_name != s_res_file_special:
            file_ext_upper = os.path.splitext(f_name)[1].upper()
        else:
            file_ext_upper = s_res_file_special

        return min(self.viewer_data_objs[file_ext_upper].keys())

    def get_defualt_options(self):
        '''
        Returns the list of options supported by the ResDataManager object.
        Type: list of nt_obj_manager_option namedtuples
        '''
        return list(self.options_default)

    def get_selected_sub_f_name(self):
        '''
        Returns the name of the selected resource sub file if one is selected
            (type: str). Otherwise, returns None.
        '''
        return self.selected_sub_f_name

    def get_exporter_set_sub_f_name(self, exporter_name):
        '''
        Returns the exporter object associated with an ID. When available,
            sets its argument_file argument to the currently selected
            resource sub-file.
        exporter_name (str): The ID of the exporter object to use.
        '''
        # Will raise KeyError if the object does not exist
        # NOTE: ResDataManager does not store the selected viewer data object
        #      (only a dict of objects for the selected file extension)
        #      Therefore, only the selected sub-file can be set here
        if not isinstance(exporter_name, str):
            raise RuntimeError('exporter_name: must be str')

        exporter_obj = self.get_exporter(exporter_name)
        exporter_obj.reset_data()

        if exporter_obj.requires_argument_file():
            # HACK: returns None when no file is selected but the exporter
            #     requires one. This corresponds to a warning instead of an
            #     error message in the GUI.
            if self.selected_sub_f_name is None: return
            exporter_obj.set_argument_file(self.selected_sub_f_name)

        return exporter_obj

    def add_open_res_callback_func(self, new_func_name, new_func):
        '''
        Adds a new callback function to self.open_res_callback_funcs
            (or replaces one)
        new_func_name (str): The identifier of the function.
        new_func (callable): The function to add.
        '''
        # fixme, no check for new_object
        if not isinstance(new_func_name, str):
            raise TypeError('new_func_name: must be str')

        if not callable(new_func):
            raise TypeError('new_func: must be callable')

        self.open_res_callback_funcs[new_func_name] = new_func

    def call_res_callback_func(self, func_name):
        '''
        Calls one of the callback functions stored in
            self.open_res_callback_funcs by identifier.
        func_name (str): The Id of the function to call.
        '''
        cb_func = self.open_res_callback_funcs.get(func_name)

        if cb_func is None:
            raise ValueError('func_name: No such callback function.')

        cb_func(self)

    def close_res_file(self):
        '''
        Closes the currently opened resource file, by calling the
        close_all_files() method of the resource reader obj.
        Also resets the associated "viewer data object".
        '''
        # NOTE: currently unused
        self.tree_reset_viewer_objs()
        self.selected_viewer_data_objs_ext = None
        self.selected_sub_f_name = None

        for obj_name, obj in self.objects.items():
            if isinstance(obj, ResFileReader_Base):
                obj.close_all_files()

    def open_res_file(self, res_f_name, res_reader_obj_id, close_others=True):
        '''
        Opens a resource file (or directory), using the resource reader obj
            set by select_res_reader. when the loading the resources was
            successful, calls the callback functions in
            self.open_res_callback_funcs.
        res_f_name (str or None): The path to the resource file (or directory)
            If res_f_name == None and close_others == False, the resource file
            opened in object res_reader_obj_id will be closed.
        res_reader_obj_id (str): Identifier for the resource reader object.
        close_others (bool): When set to True, opening of e.g. a resource file
            will trigger a closure in other resource reader objects
            (e.g. directory). Resource reader objects with keep_open == True
            are unaffected.
        '''
        self.tree_reset_viewer_objs()
        self.selected_viewer_data_objs_ext = None
        self.selected_sub_f_name = None

        if res_f_name is None:
            # Modified: Accept None for res_f_name
            res_f_name_pathfix = None
            file_ext_upper = ''
        elif os.path.basename(res_f_name):
            res_f_name_pathfix = res_f_name
            file_ext_upper = os.path.splitext(res_f_name)[1].upper()
        else:
            # Remove ending separator '\\' or '/' from directory paths
            res_f_name_pathfix = os.path.dirname(res_f_name)
            file_ext_upper = ''

        res_read_obj = self.get_object(res_reader_obj_id)

        if not isinstance(res_read_obj, ResFileReader_Base):
            raise ValueError('Invalid res_reader_obj_id argument.')

        # Close other resource readers if close_others == True
        if close_others:
            # TODO, this is inefficient, iterates through all
            #     objects, not just resource readers.
            for obj_name, obj in self.objects.items():
                if (isinstance(obj, ResFileReader_Base)
                        and (obj is not res_read_obj)):
                    if not obj.get_keep_open():
                        obj.close_all_files()

        file_ext_accepted = res_read_obj.get_file_ext_accepted()

        # Accept any name if file_ext_accepted is empty.
        #     (hack for directory names that contain a ".")
        if ((res_f_name is None) or (not file_ext_accepted)
                or (file_ext_upper == file_ext_accepted)):
            # RESOURCE.MAP file
            res_read_obj.open_res_file_or_dir(res_f_name_pathfix)
        else:
            # TODO, add support for other cases (e.g. zip file)
            res_read_obj.close_all_files()
            raise ValueError(
                'Unsupported resource file: "%s"' % res_f_name_pathfix)

        # Update the "combined" resource reader object
        self.get_object(s_obj_resreadcombined).open_res_file_or_dir(None)

        # Call "callbacks" in a "deterministic" order (in alphabetic order
        #     of names). Not called if res_f_name == None
        if res_f_name is not None:
            for func_id, cb_func in sorted(
                    self.open_res_callback_funcs.items(), key=lambda x: x[0]):
                cb_func(self)
