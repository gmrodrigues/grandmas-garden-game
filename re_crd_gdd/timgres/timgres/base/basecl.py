#!/usr/bin/python3
# coding: utf8

# The Incredible Machine (TIM) level/image resource reader, version 0.2
# By knt47, licensed under the Creative Commons Zero license

from __future__ import division, print_function, unicode_literals

import itertools
import sys

if sys.version_info[0] != 3:
    izip = itertools.izip
else:
    izip = zip
    xrange = range

from collections import namedtuple
from timgres.base.misc import print_msg, rx_type

# --- base classes ---

'''
Module containing the base classes, including:
    ObjectManager_Options (options for object manager),
    ObjectManagerBase (object manager base class),
    ResDataItemBase (abstract base class, allows setting parent in an
        object handled by the object manager)
    ResDataBase_Decoder (abstract base class for "decoder" objects,
        see base.rdatamgr for more information)
    ResDataBase_Exporter (abstract base class for "exporter" objects,
        see also ExporterObjectManagerBase class and base.defexp)
    ExporterObjectManagerBase (ObjectManagerBase subclass with basic support
        for exportinh)
'''

# namedtuple & constants used by ObjectManager_Options

# nt_fields_option_info: A namedtuple used for storing the parser
#     and the default value for an option in an ObjectManager_Options object
# parser (str): ID for the type of the option, as well as the ID
#     of the associated parser function. (opt_type_*)
# def_value (type depends on parser): the default value
nt_fields_option_info = ('parser', 'def_value')
nt_option_info = namedtuple('nt_option_info', nt_fields_option_info)

s_opt_type_int = 'int'
s_opt_type_int_none = 'int_none'
s_opt_type_float = 'float'
s_opt_type_str = 'str'
s_opt_type_color_none = 'color_none'  # fixme


def _parse_option_int_none(value):
    '''
    "Private" function, parser for the "int_none" type
    value (int, str or None): Accepts an int, an str, string 'none', or None
    Returns an int or None
    '''
    if value is None:
        return  # None
    elif isinstance(value, int):
        return value
    elif isinstance(value, str):
        vs = value.strip()
        if (not vs) or (vs.lower() == 'none'):
            return  # None
        else:
            return int(vs)
    else:
        raise TypeError('_parse_option_int_none: unsupportd type')


_hex_chars = '0123456789abcdef'


def _parse_option_color_none(value):
    '''
    "Private" function, parser for the "int_none" type
    value (str, None): may be hex rgb string (length=6), empty str or None
        unlike _parse_option_int_none, does not accept 'none' str!
    returns a hex rrggbb string or None
    '''

    if value is None:
        return  # None
    elif isinstance(value, str):
        if not value:
            return  # empty str -> None

        value_lower = value.lower()

        if (len(value) != 6) or any(x not in _hex_chars for x in value_lower):
            raise ValueError('Invalid color value')

        return value_lower
    else:
        raise TypeError('_decode_option_color_none: unsupportd type')


str_err_name_type = 'name: must be str'
str_err_new_name_type = 'new_name: must be str'


class ObjectManager_Options(object):
    '''
    ObjectManager_Options: Stores the options for an object manager
        (ObjectManagerBase subclass).

    Options can be added using add_option and they are associated with
        a parser (str, int, float, etc) and a default value.
    Values can be retrieved and set using get_value and set_value, respectively

    '''
    # parsers dict: key: string, value: function, only used by
    #     set_value, not get_value!

    parsers = {
        s_opt_type_int: int,
        s_opt_type_int_none: _parse_option_int_none,
        s_opt_type_float: float,
        s_opt_type_str: lambda x: str(x).strip(),
        s_opt_type_color_none: _parse_option_color_none,
    }

    def __init__(self):
        '''
        The constructor of the class, requires no arguments.
        '''

        self.reset_options()

    def reset_options(self):
        '''
        Resets the dicts containing the information on the options
            (type, parser, etc.) ant their present value.
        '''

        # options: dict, key: option name, value: nt_option_info
        #    the nt_option_info namedtuple stores the type of an option
        #    (the same as the name of parser used) and the default value
        self.options = {}
        # values: dict, key: option name, value: the current value,
        #    depends on option type/parser (The two have the same meaning)
        self.values = {}

    def reset_defaults(self):
        '''
        Sets all options to their default values.
        '''
        for k in self.values.keys():
            self.values[k] = self.options[k].def_value

    def add_option(self, name, opt_type, def_value):
        '''
        Adds a new option.
        Name (str): The name of the new option
        opt_type (str): One of the option type constants (s_opt_type_*)
        def_value: The default value, accepted type depends on opt_type
        '''
        if not (isinstance(name, str) and isinstance(opt_type, str)):
            raise RuntimeError(str_err_name_type)

        # NOTE: no exception should be raised if there is already an option
        #     with "name". This should make it easier to  re-implement
        #     "options_default" or similar fields in sub-classes

        self.options[name] = nt_option_info(opt_type, def_value)
        self.set_value(name, def_value)

    def get_value(self, name):
        '''
        Returns the current value of an option.
        name (str): The name of the option
        Returns the value of option, type depends on the option type stored in
            self.options
        '''
        # Will raise KeyError if option does not exist!
        if not isinstance(name, str):
            raise RuntimeError(str_err_name_type)

        return self.values[name]

    def set_value(self, name, new_value):
        '''
        Returns the current value of an option.
        name (str): The name of the option
        '''

        if not isinstance(name, str):
            raise RuntimeError(str_err_name_type)

        # may raise exceptions (KeyError, ValueError, TypeError etc.)
        self.values[name] = self.parsers[self.options[name].parser](new_value)


# Namedtuple used in ObjectManagerBase to store the default
#     values for options (options_default)

nt_fields_obj_manager_options = ('name', ) + nt_fields_option_info

# nt_obj_manager_option: A namedtuple for storing the default values
#     for options in ObjectManagerBase
# name (str): the name for the option
# parser (str): see nt_fields_option_info
# def_value (type depends on parser): see nt_fields_option_info
nt_obj_manager_option = namedtuple('nt_obj_manager_options',
                                   nt_fields_obj_manager_options)


class ObjectManagerBase(object):
    '''
    Base class for object manager. The base class provides support for
        options (see ObjectManager_Options) and objects
        (add_object/get_object)
    Sub-classes may treat some types of options in special ways,
        see for example exporters in ExporterObjectManagerBase
    '''

    # options_default: Must be modified in sub-classes to
    #     store the names and default values for options
    options_default = ()

    def __init__(self):
        '''
        The constructor of the class. Initializes self.options
            using the information in options_default (s "static" var)
        '''
        self.options = ObjectManager_Options()

        for opt_name, opt_type, opt_def in self.options_default:
            self.options.add_option(opt_name, opt_type, opt_def)

        self.reset_objects()

        # "convenience" function for objects
        self.get_option = self.options.get_value
        self.set_option = self.options.set_value

    def reset_objects(self):
        '''
        Creates an empty self.objects dict anf calls create_default_objects
        '''
        # key: str, value: (ony object)
        self.objects = {}
        self.create_default_objects()

    def create_default_objects(self):
        '''
        May be re-implemented in a subclass. Can be used as a place for adding
            new objects (see add_object)
        '''
        pass  # may be re-implemented in a sub-class

    def add_object(self, new_name, new_obj):
        '''
        Adds a new object
        new_name (str): The name associated with the object
        new_obj (object): The object
        '''

        # fixme, no check for new_object
        if not isinstance(new_name, str):
            raise TypeError(str_err_new_name_type)

        self.objects[new_name] = new_obj

    def get_object(self, name):
        '''
        Returns the object associated with "name"
        name (str): The name of the object to retrieve
        '''

        # Will raise KeyError if the object does not exist
        if not isinstance(name, str):
            raise RuntimeError(str_err_name_type)

        return self.objects[name]

    def get_objects_prefix(self, prefix):
        '''
        Returns a list of objects with names sharing a common prefix
        prefix (str): The prefix the names should start with.
        '''

        if not isinstance(prefix, str):
            raise RuntimeError('prefix: must be str')

        # NOTE: order is "arbitrary!"
        return [y for x, y in self.objects.items() if x.startswith(prefix)]


class ResDataItemBase(object):
    '''
    Abstract base class for objects that will be stored in an object manger
        (an ObjectManagerBase subclass). These objects can use self.parent
        for calling methods in the object manager.
    '''

    # parent_class: For type checking (Can this object be added to
    #     an object manager of this type?)
    parent_class = ObjectManagerBase

    def __init__(self):
        '''
        The constructor of the class.
        '''
        self.parent = None

    def set_parent(self, new_parent):
        '''
        Method for setting the self.parent field
        new_parent (type: a subclass of self.parent_class): The parent object
        '''

        if not isinstance(new_parent, self.parent_class):
            raise TypeError('new_parent: must be %s' % self.parent_class)

        self.parent = new_parent


str_not_impl_ResDataBase_Decoder = 'Not implemented in ResDataBase_Decoder'

# NOTE: ResDataBase_Decoder: parent_class is NOT modified, ObjectManagerBase
#  provides everything that is needed by "decoder" classes
#  (get_option, get_object)


class ResDataBase_Decoder(ResDataItemBase):
    '''
    Abstract base classes for "decoder" objects. A decoder is associated with
        a file type supported by the program (is_file_type_supported - checks
        if the file type is supported). The process_sub_file method is called
        for decoding and the data is retrieved using get_data.
        See the base.rdatamgr module for more information.
    '''

    def is_file_type_supported(self, file_data_start):
        '''
        Not implemented in ResDataBase_Decoder
        An implementation in a sub-class must return a bool value
            (True if the class supports the data format)
        file_data_start (bytes): The beginning of the file data to be decoded
            (see base.misc.is_file_type_supported_n_bytes)
        '''
        # file_data_start: currently the first 32 bytes # must return bool
        raise NotImplementedError(str_not_impl_ResDataBase_Decoder)

    def process_sub_file(self, f_name_part, file_data, process_options):
        '''
        Not implemented in ResDataBase_Decoder
        An implementation in a sub-class must decode the data provided
            as file_data using the specified process options
        f_name_part (str): the file name, without the extension
        file_data (bytes): the contents of the sub-file
        process_options: a namedtuple (object type dependent, str
            in some cases) or None if the class does not require tihs
        '''

        raise NotImplementedError(str_not_impl_ResDataBase_Decoder)

    def get_data(self):
        '''
        Not implemented in ResDataBase_Decoder
        When re-implemented in a subclass, must return a namedtuple
            depending on object type (see base.bmpdbase for an example)
        '''
        #  (... for bitmap parsers!)

        raise NotImplementedError(str_not_impl_ResDataBase_Decoder)


# Namedtuple used by exporter obj

# nt_export_name_wildcard: Contains the data for wildcard matching,
#     see its usage in base.defexp
nt_export_name_wildcard = namedtuple('nt_export_name_wildcard',
                                     ('pattern', 'case_sensitive'))


class ResDataBase_Exporter(ResDataItemBase):
    '''
    Base class for exporter objects, inherits ResDataItemBase
    "Export" means writing the converted data to an output file
        with a specific format (see export_to_file method)
    Contains several fields storing the information required for an export
        as well as the methods getting/setting them
    Also supports an optional warning message
    '''

    # Similarly to  ResDataBase_ViewerDataObj (base.vdobase), identifier is
    #     stored in the class as a static variable

    # ... "Static" constants associated with the class not the obj.instance ...
    # exporter_identifier: used for identifying the object in parent
    exporter_identifier = ''
    # exporter_description: the text for menu item
    exporter_description = ''

    # NOTE: the base class does not check whether the required data was
    #     set before the call to export_to_file
    # arg_required_*: Is the particular type of information required
    #     by this class? See also the docstrings of requires_argument_*
    arg_required_file = False
    arg_required_file_list = False
    arg_required_name_wildcard = False
    arg_required_viewer_obj_id = False
    arg_required_viewer_sub_item = False

    # show_in_gui: Whether the item should appear in a menu (GUI)
    show_in_gui = True

    # export_ext_default: should be lowercase, e.g. '.png', '.zip'
    export_ext_default = ''
    # export_ext_default_descr: e.g 'PNG image', 'ZIP archive'
    export_ext_default_descr = ''

    def __init__(self):
        '''The constructor of the class.'''
        ResDataItemBase.__init__(self)
        self.reset_data()

    def reset_data(self):
        '''
        Resets the fields containing the information for export
        '''
        self.argument_file = None
        self.argument_file_list = None
        self.argument_name_wildcard = None
        self.argument_viewer_obj_id = None
        self.argument_viewer_sub_item = None
        # warning_msg: None or a "warning message" set by export_to_file
        self.warning_msg = None

    def get_exporter_identifier(self):
        '''
        Returns the identifier associated with the exporter (str).
        Note that this should be a static value, associated with the class.
        '''
        return self.exporter_identifier

    def get_exporter_description(self):
        '''
        Returns a short description string associated with the object. (str)
        Note that this should be a static value, associated with the class.
        '''
        return self.exporter_description

    def shown_in_gui(self):
        '''
        Returns GUI-related information (whether a menu item should be created)
        '''
        return self.show_in_gui

    def requires_argument_file(self):
        '''
        Returns True if a single resource sub-file name is required for this
            type of export, False otherwise (type: bool)
        Note that this should be a "static" value, associated with the class.
            (This also applies to all requires_argument_* functions)
        '''
        return self.arg_required_file

    def requires_argument_file_list(self):
        '''
        Returns True if the exporter class requires a list of resource
            sub-file names (type: bool)
        '''
        return self.arg_required_file_list

    def requires_argument_name_wildcard(self):
        '''
        Returns True if the exporter class requires a wildcard or a regexp
            to determine which files to export (type: bool)
        '''
        return self.arg_required_name_wildcard

    def requires_argument_viewer_obj_id(self):
        '''
        Returns True if the exporter class requires a viewer object
            (ResDataBase_ViewerDataObj subclass, stored in self.parent)
            (type: bool)
        '''
        return self.arg_required_viewer_obj_id

    def requires_argument_viewer_sub_item(self):
        '''
        Returns True if the exporter class requires a sub-item number for the
            viewer object (ResDataBase_ViewerDataObj subclass) (type: bool)
        '''
        return self.arg_required_viewer_sub_item

    def set_argument_file(self, new_value):
        '''
        Method for setting the "file" argument of export
        new_value (str): A name of the resource sub-file
            required by the exporter
        '''
        if not isinstance(new_value, str):
            raise TypeError('"file" argument must be str')

        self.argument_file = new_value

    def set_argument_file_list(self, new_value):
        '''
        Method for setting the "file_list" argument of export
        new_value (list or tuple): List of the required sub-file names
        '''
        if not isinstance(new_value, (list, tuple)):
            raise TypeError('"file_list" argument must be list or tuple')

        self.argument_file_list = new_value

    def set_argument_name_wildcard(self, new_value):
        '''
        Method for setting the "name_wildcard" (or regexp) argument of export
        new_value (nt_export_name_wildcard namedtuple or an object returned by
            re.compile): The required wildcard information or regexp
        '''
        if not isinstance(new_value, (nt_export_name_wildcard, rx_type)):
            raise TypeError(
                '"name_wildcard" argument must be either'
                ' a nt_export_name_wildcard namedtuple or a regex object')

        self.argument_name_wildcard = new_value

    def set_argument_viewer_obj_id(self, new_value):
        '''
        Method for setting the "viewer_obj_id" argument of export
        new_value (str): The ID of the viewer object
            (ResDataBase_ViewerDataObj, stored in parent)
        '''
        if not isinstance(new_value, str):
            raise TypeError('"viewer_obj_id" argument must be str')

        self.argument_viewer_obj_id = new_value

    def set_argument_viewer_sub_item(self, new_value):
        '''
        Method for setting the "viewer_sub_item" argument of export
        new_value (int): The sub-item ID for the viewer object
            (ResDataBase_ViewerDataObj, stored in parent)
        '''
        if not isinstance(new_value, int):
            raise TypeError('"viewer_obj_id" argument must be int')

        self.argument_viewer_sub_item = new_value

    def get_argument_file(self):
        '''
        For in-module usage only. Returns the value of File argument (str)
        '''
        return self.argument_file  # not used in sub-classes

    def get_export_ext_data(self):
        '''
        Returns the information stored in export_ext_default_descr and
            export_ext_default as a tuple.
        '''
        return self.export_ext_default_descr, self.export_ext_default

    def get_export_default_ext(self):
        '''
        Returns the default extension (str) associated with the class,
            in a from that can be used with a "Save as" dialog
        '''
        # will be passed to .asksaveasfilename
        return self.export_ext_default.rstrip('*')

    def get_warning_msg(self):
        '''
        Method for retrieving the warning message after export.
        Returns str (the message) or None (no warning)
        '''
        return self.warning_msg  # fixme

    def set_warning_msg(self, new_msg=None):
        '''
        Method for setting (or clearing) the warning message.
        Should be used in sub-classes only, in export_to_file
        new_msg: The warning message (str) or None (no warning)
        '''

        if new_msg is not None:
            if not isinstance(new_msg, str):
                raise TypeError('"new_msg" must be str or None')

        self.warning_msg = new_msg

    def export_to_file(self, f_name):
        '''
        Not implemented in ResDataBase_Exporter. When re-implemented in a
            sub-class, the implementation must save the converted data into
            file "f_name" and optionally set the warning message.
        Raising class-specific exceptions is also allowed
        '''
        raise NotImplementedError('Not implemented in ResDataBase_Exporter')


# nt_exporter_id_descr: used by ExporterObjectManagerBase to return basic
#     information about its exporter objects.
# exporter_identifier (str): see ResDataBase_Exporter.exporter_identifier
# exporter_description (str): see ResDataBase_Exporter.exporter_description

nt_exporter_id_descr = namedtuple(
    'nt_exporter_id_descr', ('exporter_identifier', 'exporter_description'))


class ExporterObjectManagerBase(ObjectManagerBase):
    '''
    ObjectManagerBase subclass that adds support for exporting.
    Exporters can be added add_exporter (should be called in a
        method called by __init__). Exporter associated with an ID can be
        retrieved using the get_exporter() method.
    '''

    # Note: no "create_default" method but create_default_objects can be used
    def __init__(self):
        '''
        The constructor for the class, requires no argumant.
        '''
        ObjectManagerBase.__init__(self)
        self.reset_exporter_objects()

    def reset_exporter_objects(self):
        # exporters: dict, key: str, value: (ony object)
        self.exporters = {}

    def add_exporter(self, new_exporter):
        '''
        Adds a new exporter object.
        new_exporter (type: ResDataBase_Exporter subclass):
            the object to be added
        Note that the ID associated with the object is retrieved from
            the object itself.
        '''

        if not isinstance(new_exporter, ResDataBase_Exporter):
            raise TypeError(
                'new_exporter must be a ResDataBase_Exporter subclass')

        new_exporter.set_parent(self)
        self.exporters[new_exporter.get_exporter_identifier()] = new_exporter

    def get_exporter(self, name):
        '''
        Returns the exporter object associated with the ID
            (type: ResDataBase_Exporter subclass).
        Will raise KeyError if an object with this ID does not exist
        name (str): The object ID.
        '''
        if not isinstance(name, str):
            raise RuntimeError(str_err_name_type)

        return self.exporters[name]

    def get_exporter_object_info(self, get_all=False):
        '''
        Returns basic information about the exporters stored in this class,
            as a list of nt_exporter_id_descr namedtuples.
        get_all (bool, default: False): False: returns objects that should
            appear in a menu (shown_in_gui() returns True). True: returns all
        '''
        return sorted((nt_exporter_id_descr(k, v.get_exporter_description())
                       for k, v in self.exporters.items()
                       if get_all or v.shown_in_gui()),
                      key=lambda x: x.exporter_identifier)

    def get_exporter_objects_prefix(self, prefix):
        '''
        Returns a list of nt_exporter_id_descr namedtuples, like
            get_exporter_object_info. Unlike the other method it requires
            a prefix as a filter for the objects to be returned. It also
            ignores shown_in_gui.
        prefix (str): Returns objects with IDs beginning with this prefix
        '''
        if not isinstance(prefix, str):
            raise RuntimeError('prefix: must be str')

        # NOTE: has fixed order, unlike .get_objects_prefix() !
        # NOTE: ignores shown_in_gui
        return sorted(
            (nt_exporter_id_descr(k, v.get_exporter_description())
             for k, v in self.exporters.items() if k.startswith(prefix)),
            key=lambda x: x.exporter_identifier)
