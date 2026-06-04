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

import argparse
import re
from timgres.base.misc import (set_verbose_mode, print_msg, print_traceback,
                               version_str, copyright_info, s_obj_resreadmap,
                               s_obj_resreaddir)
from timgres.base.basecl import nt_export_name_wildcard
from timgres.cli.cliconf import ResDataManager_CliConf

# --- Module containing the CLI main entry point ---

'''Module that contains the CLI main function, cli_main.'''


def print_options_info(res_data_mgr):
    '''
    Prints information about the options available in the ResDataManager
        to the standard output. Used for the --list-options argument.
    res_data_mgr: The resource data manager (type: ResDataManager_CliConf)
    '''
    for option in res_data_mgr.get_defualt_options():
        print('{0.name:<30}{0.parser:<20}{0.def_value}'.format(option))


def print_exporter_info(res_data_mgr):
    '''
    Prints information about the exporter objects available in the
        ResDataManager to the standard output. Used for the --list-exporters
        argument.
    res_data_mgr: The resource data manager (type: ResDataManager_CliConf)
    '''
    for exporter_id, exporter_descr in res_data_mgr.get_exporter_object_info(
            True):
        exporter_obj = res_data_mgr.get_exporter(exporter_id)
        args_required = []

        if exporter_obj.requires_argument_file():
            args_required.append('file')

        if exporter_obj.requires_argument_file_list():
            args_required.append('file-list')

        if exporter_obj.requires_argument_name_wildcard():
            args_required.append('wildcard')

        if exporter_obj.requires_argument_viewer_obj_id():
            args_required.append('viewer-obj')

        if exporter_obj.requires_argument_viewer_sub_item():
            args_required.append('item-id')

        print('{:<25}{} [{}]'.format(exporter_id, exporter_descr,
                                     ', '.join(args_required)))


def print_viewer_info(res_data_mgr):
    '''
    Prints information about the viewer objects available in the
        ResDataManager to the standard output. Used for the --list-viewers
        argument.
    res_data_mgr: The resource data manager (type: ResDataManager_CliConf)
    '''
    for viewer_info in res_data_mgr.get_viewer_info_for_all_ext():
        print('{0.file_ext:<10}{1}{0.obj_id:<22}{0.obj_descr}'.format(
            viewer_info, '*' if viewer_info.is_default else ' '))


def set_option_cmdline_arg(res_data_mgr, option_value):
    '''
    Set a single option based on a command line argument, used by the
        -s/--set-opt implementation.
    res_data_mgr: The resource data manager (type: ResDataManager_CliConf)
    option_value (str): From the command line option, format is 'option=value'
    '''
    # separator character is =
    if '=' in option_value:
        option, value = option_value.split('=', 1)
        # TODO: more readable message instead of KeyError?
        try:
            res_data_mgr.set_option(option, value)
        except KeyError:
            sys.exit('*Error*: Invalid option "%s"' % option)
        except Exception as ex:
            print(('*Error*: Failed to set option "%s" - %s' % (option, ex)),
                  file=sys.stderr)
            print_traceback()
            sys.exit(1)
    else:
        sys.exit('*Error*: Invalid --set-opt/-s parameter, '
                 'format must be option=value')


def cli_main():
    '''
    Main function for the CLI part of the program. The CLI allows exporting
        a single resource sub-file (or a sub-set of the available files)
        using the specified "exporter" and "viewer" objects.
    '''
    parser = argparse.ArgumentParser()

    # NOTE: required=True was removed for options -o, -r and -e
    #     Otherwise, --list-* options will not work

    parser.add_argument('-o',
                        '--out',
                        help='Output file, type depends on the exporter used')

    # Modification: -r/--res and -d/--dir are no longer mutually exclusive

    parser.add_argument('-r',
                        '--res',
                        help='Resource file name (RESOURCE.MAP from the game)')

    parser.add_argument('-d',
                        '--dir',
                        help='Directory that contains the resource files')

    parser.add_argument(
        '-f',
        '--file',
        action='append',
        nargs='*',
        help=(
            'One or more resource sub-files. Required by several exporters.'))
    # FIXME: -f: should be "One or more files or resource sub-files"

    parser.add_argument(
        '-e',
        '--exporter',
        help='The name of exporter object, see --list-exporters')

    parser.add_argument(
        '-v',
        '--viewer-obj',
        help=('The name of viewer object, '
              'required by some exporters, see --list-viewers'))

    parser.add_argument('-i',
                        '--item-id',
                        type=int,
                        help=('The sub-item ID for the viewer object, '
                              'required by some exporters'))

    group_wildcard = parser.add_mutually_exclusive_group()
    group_wildcard.add_argument(
        '-w',
        '--wildcard',
        help=('A wildcard for file names, required by some exporters.'))

    group_wildcard.add_argument(
        '--wildcard-case', help='Similar to --wildcard but case sensitive')

    group_wildcard.add_argument(
        '--regexp',
        help=('Similar to --wildcard but allows specifying '
              'a regular expression instead.'))

    group_wildcard.add_argument('--regexp-case',
                                help='Similar to --regexp but case sensitive')

    parser.add_argument('-s',
                        '--set-opt',
                        action='append',
                        nargs='*',
                        help='Set option. Format is "-s option=value".')

    parser.add_argument('-V',
                        '--verbose',
                        action='store_true',
                        help='Print debug information to stderr.')

    parser.add_argument('-g',
                        '--gui',
                        action='store_true',
                        help=('Show GUI. Not available if the program is '
                              'launched as "python tres_cli.py"'))

    # Note, --list-* are not defined as "mutually exclusive"
    parser.add_argument('--list-options',
                        action='store_true',
                        help='List supported options and exit.')

    parser.add_argument('--list-exporters',
                        action='store_true',
                        help='List available exporter objects and exit.')

    parser.add_argument('--list-viewers',
                        action='store_true',
                        help='List available viewer objects and exit.')

    parser.add_argument('--version',
                        action='store_true',
                        help='Print version string and exit.')

    args = parser.parse_args()

    if args.gui:
        sys.exit(('*Error*: --gui option is not available if the program is '
                  'launched as "python tres_cli.py"'))

    set_verbose_mode(args.verbose)

    try:
        res_data_mgr = ResDataManager_CliConf()

        if args.list_options:
            print_options_info(res_data_mgr)
            return

        if args.list_exporters:
            print_exporter_info(res_data_mgr)
            return

        if args.list_viewers:
            print_viewer_info(res_data_mgr)
            return

        if args.version:
            print(version_str)
            print(copyright_info)
            return

        res_and_dir_missing = (args.res is None) and (args.dir is None)

        if (res_and_dir_missing or (args.out is None)
                or (args.exporter is None)):
            # NOTE: we cannot rely on argparse for this (required=True)
            #     because --list-* would not work
            sys.exit('*Error*: The following arguments are required: '
                     '-o/--out, -e/--exporter\n      and the path to the '
                     'resources (-r/--res and/or -d/--dir)')

        exporter_obj = res_data_mgr.get_exporter(args.exporter)

        # NOTE: action='append' and nargs='*' is combined to allow both
        #     -f FILE.001 FILE.002 and -f FILE.001 -f FILE.002 syntax
        #     The result is list of lists

        if args.file is not None:
            args_file = list(itertools.chain.from_iterable(args.file))
        else:
            args_file = []

        if exporter_obj.requires_argument_file():
            if len(args_file) != 1:
                sys.exit(
                    '*Error*: Exporter requires exactly one file argument')

            exporter_obj.set_argument_file(args_file[0])
        elif exporter_obj.requires_argument_file_list():
            # Note: The two "requirements" are considered "mutually exclusive"
            # Note: Single-element file list is not an error
            if not args_file:
                sys.exit('*Error*: Exporter requires at least one file name')

            exporter_obj.set_argument_file_list(args.file)
        elif args_file:
            sys.exit('*Error*: Exporter object does not '
                     'require a sub-file or file list')
        regexp_wildcard = None

        # Defined as mutually exclusive, no "regexp_wildcard is None"
        #     checks are needed (TODO: do with type= in argparse?)

        if args.wildcard is not None:
            regexp_wildcard = nt_export_name_wildcard(args.wildcard, False)
        elif args.wildcard_case is not None:
            regexp_wildcard = nt_export_name_wildcard(args.wildcard_case, True)
        elif args.regexp is not None:
            regexp_wildcard = re.compile(args.regexp, re.I)
        elif args.regexp_case is not None:
            regexp_wildcard = re.compile(args.regexp_case)

        if exporter_obj.requires_argument_name_wildcard():
            if regexp_wildcard is None:
                sys.exit('*Error*: Exporter requires wildcard/regexp, '
                         'but none was provided')

            exporter_obj.set_argument_name_wildcard(regexp_wildcard)
        elif regexp_wildcard is not None:
            sys.exit('*Error*: Exporter does not accept wildcard/regexp')

        if exporter_obj.requires_argument_viewer_obj_id():
            if args.viewer_obj is not None:
                viewer_obj = args.viewer_obj
            elif len(args_file) == 1:
                # [?] elif args_file:
                viewer_obj = res_data_mgr.get_default_viewer_id_for_file(
                    args_file[0])
                # NOTE: only printed in "verbose" mode
                print_msg(
                    ('*Exporter note*: viewer_obj was not specified, '
                     'using default "%s" by file extension') % viewer_obj)
            else:
                sys.exit('*Error*: The exporter requires --viewer_obj and '
                         'no "default" object could be determined.')

            exporter_obj.set_argument_viewer_obj_id(viewer_obj)
        elif args.viewer_obj is not None:
            sys.exit('*Error*, Exporter requires --viewer-obj, '
                     'but none was provided')

        if exporter_obj.requires_argument_viewer_sub_item():
            # NOTE: type is set to int
            if args.item_id is None:
                sys.exit('*Error*: Exporter requires --item-id, '
                         'but none was provided')

            exporter_obj.set_argument_viewer_sub_item(args.item_id)
        elif args.item_id is not None:
            sys.exit('*Error*: Exporter does not accept item ID.')

        # ... export options ...

        # Note: Combines action='append' and nargs='*', see note at args.file

        if args.set_opt is not None:
            for option_value in itertools.chain.from_iterable(args.set_opt):
                set_option_cmdline_arg(res_data_mgr, option_value)

        # ... write the output file ...
        # Modification: -r/--res and -d/--dir are no longer mutually exclusive
        # Note: The following code assumes that nothing was opened in
        #     res_data_mgr. Otherwise, it will not work

        if args.res is not None:
            res_data_mgr.open_res_file(args.res, s_obj_resreadmap, False)

        if args.dir is not None:
            res_data_mgr.open_res_file(args.dir, s_obj_resreaddir, False)

        exporter_obj.set_warning_msg(None)  # not required, but make sure
        exporter_obj.export_to_file(args.out)

        warning_msg = exporter_obj.get_warning_msg()

        if warning_msg is not None:
            print('*Export warning*:', warning_msg, file=sys.stderr)

    except Exception as ex:
        # does not use misc.print_msg
        print('*Export failed*: %s' % ex, file=sys.stderr)
        print_traceback()
