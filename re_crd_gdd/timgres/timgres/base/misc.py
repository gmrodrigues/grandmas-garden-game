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

import os, re, traceback
'''
Module conatining small helper functions and constants
    used in many parts of the package.
'''

# --- version string ---

version_str = 'TIM-TIM3 level/image resource reader/converter, version 0.2'
copyright_info = 'By knt47, licensed under the Creative Commons Zero license'
main_window_title = 'TIM-TIM3 Level/Image Viewer'

# --- print warning messages & other small helper funcs ---

# The exact name of this type may vary between Python versions (?)
rx_type = type(re.compile(''))

_print_msg_func = None


def set_verbose_mode(verbose=True):
    '''
    Activates the "verbose mode". In this mode, debug meassages
        ant Python exception tracebacks will be printed to stderr.
    verbose (bool): Activate (True) or deactivate (False) the mode
    '''

    # NOTE: uses global variable!
    global _print_msg_func

    if verbose:
        _print_msg_func = sys.stderr.write
    else:
        _print_msg_func = None


def print_msg(msg):
    '''
    Prints msg (type: str) to stderr in verbose mode. Otherwise, does nothing.
    '''
    if _print_msg_func is not None:
        _print_msg_func(msg + '\n')


def print_traceback():
    '''
    Prints an exception traceboack to stderr, but only in verbose mode.
    '''
    print_msg(traceback.format_exc())


def namedtuple_to_str(nt):
    '''
    Converts namedtuple nt to a string for printing/dispalying in GUI.
    nt: a namedtuple object
    '''
    return ' '.join('%s: %s' % xy for xy in izip(nt._fields, nt))


def get_path_shortened(path):
    '''
    "Shortens" a long path name, by splitting it at the separator characters
        and substituting its "middle part" with '...'. Only the first two and
        the last two "elements" are kept.
    name_part (str): the path
    '''
    if os.sep != '/':
        path1 = path.replace(os.sep, '/')
    else:
        path1 = path

    path_dirs = path1.split('/')

    if len(path_dirs) > 4:
        return '/'.join(path_dirs[:2] + ['...'] + path_dirs[-2:])
    else:
        return path1


# "-" means export to stdout (in command line mode only!)
file_name_stdout = '-'

# Constants and functions for RGB color values

color_black = bytearray((0, 0, 0))
color_white = bytearray((255, 255, 255))


def color_dist(col1, col2):
    '''
    Returns the  difference of two RGB color values (return type: int).
    col1, col2: sequence of ints (this includes bytearray!)
    '''
    # col1, col2: bytearray
    return sum((y - x)**2 for x, y in izip(col1, col2))


# is_file_type_supported_n_bytes is used by ResDataManager class,
#     It passes the first n bytes from a resource sub-file to the
#     is_file_type_supported() method of decoder objects.

is_file_type_supported_n_bytes = 512

# Text codec that will be used for game data files

game_text_encoding = 'cp437'

# Full path to directory that stores "local files" that can be opened
#     using a class in resfile.py module

sub_dir_files = 'files'

full_path_dir_files = os.path.join(
    os.path.dirname(os.path.dirname(sys.modules[__name__].__file__)),
    sub_dir_files)

# --- option, object names for ResDataManager ---

# Names for ResDataManager options

s_opt_transpcol16 = 'transpcol16'
s_opt_transpcol256 = 'transpcol256'
s_opt_zoom = 'zoom'
s_opt_flip = 'flip'
s_opt_pal_file_def = 'pal_file_def'
s_opt_pal_file_def_2 = 'pal_file_def_2'
s_opt_anim_enabled = 'anim_enabled'
s_opt_anim_delay = 'anim_delay'
s_opt_backgr_color = 'backgr_color'
# s_opt_backgr_color_special: can be used to override background color
s_opt_backgr_color_special = 'backgr_color_special'
# s_opt_color_font: used by the 1BPP font decoder
s_opt_font_color = 'font_color'
# s_opt_csv_format: one of the "dialects" supported by the csv module
s_opt_csv_format = 'csv_format'
s_opt_preserve_pos_size_singleimg = 'preserve_pos_size_singleimg'
s_opt_no_puzzle_backgr = 'no_puzzle_backgr'
s_opt_export_hide_local = 'export_hide_local'
s_opt_show_solution = 'show_solution'
s_opt_raw_part_info = 'raw_part_info'

s_obj_prefix_pngexp = 'pngexp'

# Names for objects in a ResDataManager that will be stored in the "other
#     objects" dictionary of the class.

# resreadmap: for .MAP resource files
s_obj_resreadmap = 'resreadmap'
# resreaddir: for reading files from a directory
s_obj_resreaddir = 'resreaddir'
# resreadlocaldir: for reading files in directory full_path_dir_files
s_obj_resreadlocaldir = 'resreadlocaldir'
# resreadcombined: For accessing files from multiple "resource readers"
s_obj_resreadcombined = 'resreadcombined'

s_obj_pngexp2 = 'pngexp2'
s_obj_pngexp16 = 'pngexp16'
s_obj_pngexp256 = 'pngexp256'
s_obj_pngmerge16 = 'pngmerge16'
s_obj_pngmerge256 = 'pngmerge256'
s_obj_pngshapedraw16 = 'pngshapedraw16'
s_obj_chunkuncompr = 'chunkuncompr'
## s_obj_pngexp_pal = 'pngexp_pal' # not in tree_mgr
s_obj_puzzleinfov1 = 'puzzleinfov1'
s_obj_puzzleinfov2 = 'puzzleinfov2'
s_obj_graphinfov1 = 'graphinfov1'
s_obj_graphinfov2 = 'graphinfov2'

# A special file name that can be used wtih a ResDataManager.
#     Allows adding viewer objects that are not associated with a single
#     resource sub-file.
# chosen because > and < are not supported in DOS file names
s_res_file_special = '>special<'

# IDs for "Viewer Data Objects". Note that the ID is stored in a "static"/
#     class variable in the corresponding class.
s_vdata_bmpsubimg = 'bmpsubimg'
s_vdata_fntsymbol = 'fntsymbol'
s_vdata_palimg = 'palimg'
# Note: the alphabetical order of animation frame and anim viewer object
#     names is important
s_vdata_anmframes = 'anmframes'
s_vdata_anmviewer = 'anmviewer'
s_vdata_scrimg = 'scrimg'
s_vdata_special_storeddata = '_special_anim_frames'
s_vdata_special_storeddata_anim = '_special_anim_viewer'

s_vdata_puzzle_t1 = 'puzzle_t1'
s_vdata_puzzle_t2 = 'puzzle_t2'

# IDs for exporter objects. Stored in the classes, in a similar manner
#     to "viewer data"  objects.
# NOTE: exporter object IDs should start with one of the prefixes
# currently: 'bin_' (resource sub-file unchanged), 'img_', 'text_'
s_export_bin_single_file = 'bin_single_file'
s_export_bin_all_files = 'bin_all_files'
s_export_bin_file_list = 'bin_file_list'
s_export_bin_file_pattern = 'bin_file_pattern'
s_export_img_single_sub_item = 'img_single_sub_item'
s_export_img_sub_items = 'img_sub_items'
s_export_img_sub_items_list = 'img_sub_items_list'
s_export_img_sub_items_pattern = 'img_sub_items_pattern'
s_export_text_plainlist_pattern = 'text_list_plain_pattern'
s_export_text_sub_item_names = 'text_sub_item_names'
s_export_text_list_fileinfo = 'text_list_fileinfo'
s_export_text_sub_item_info = 'text_sub_item_info'

# Names for callback functions (in ResDataManager)
# NOTE: The "callbacks" are executed in alphabetical (ASCII/unicode) order.
#     A '!' (ASCII 0x21) is added before the name of the 'pal' callback to
#     make sure it is called first.
s_open_res_cback_pal = '!pal'
s_open_res_cback_t1_crc_check = 't1_crc_check'
s_open_res_cback_t2_data = 't2_data'
s_open_res_cback_temim_store_img = 'temim_store_img'

# Resource file extensions
ext_file_map = '.MAP'

# Resource sub-file extensions
ext_subf_anm = '.ANM'
ext_subf_bmp = '.BMP'
ext_subf_fnt = '.FNT'
ext_subf_pal = '.PAL'
ext_subf_scr = '.SCR'
# (Sub-)file, extensions, puzzle/level
ext_subf_gkc = '.GKC'
ext_subf_lev = '.LEV'
ext_subf_tim = '.TIM'

# tag values, used in TreeView objects
tag_sel = 'sel'  # select
tag_dbl = 'dbl'  # double click

# Default values for sub-file name and other fields
opt_pal_file_def = 'TIM.PAL'
opt_pal_file_2_def = 'TIM2.PAL'
opt_backgr_color_def = '1e90ff'
opt_font_color_def = '000000'
opt_csv_format_def = 'excel'
# ( Note: background color - Empty string means no color )

# Debugging option for the puzzle viewer GUI. If puzzle_view_debug = True,
#    the raw information for puzzle part will appear automatically on the
#    "File info" tab and the solution will also be shown by default.

puzzle_view_debug = False
