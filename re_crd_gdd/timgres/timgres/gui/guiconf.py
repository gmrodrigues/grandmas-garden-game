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

import tkinter as tki

from timgres.base.misc import (
    s_opt_zoom, s_opt_flip, s_opt_pal_file_def, s_opt_pal_file_def_2,
    s_opt_backgr_color, s_opt_backgr_color_special, s_opt_anim_enabled,
    s_opt_anim_delay, s_opt_font_color, ext_subf_anm, s_res_file_special,
    opt_backgr_color_def, s_opt_export_hide_local, s_opt_show_solution,
    s_opt_raw_part_info, puzzle_view_debug)
from timgres.base.basecl import (nt_obj_manager_option, s_opt_type_int,
                                 s_opt_type_float, s_opt_type_int_none,
                                 s_opt_type_str, s_opt_type_color_none)
from timgres.cli.cliconf import ResDataManager_CliConf
from timgres.gui.optdlg import (OptionsDialogBase, nt_options_dialog_field,
                                extra_button_id_color)

# * ViewerDataObj classes *
from timgres.viewdata.vd_anm import ViewerDataObj_AnmViewer
from timgres.viewdata.vd_sdata import ViewerDataObj_StoredDataAnim

# --- ResDataManager and OptionsDialog subclasses, "configured" for GUI ---

'''
This module contains the ResDataManager_GuiConf class, a sub-class of
    ResDataManager_Cli. This class is responsible for the creation of all
    objects, that are available only in the GUI part of the program, not in
    the CLI. OptionsDialog_GuiConf is a subclass of OptionsDialog_GuiConf,
    contains the information about the options that can be modified using
    the dialog.
'''


class ResDataManager_GuiConf(ResDataManager_CliConf):
    '''
    A ResDataManager subclass, used by the GUI part of the program.
        Supports all options and objects created in ResDataManager_CliConf,
        as well as additional ones.
    '''

    # options_default: Modifies the list of options from the parent class
    options_default = ResDataManager_CliConf.options_default + (
        nt_obj_manager_option(s_opt_backgr_color, s_opt_type_color_none,
                              opt_backgr_color_def),
        nt_obj_manager_option(s_opt_backgr_color_special,
                              s_opt_type_color_none, None),
        nt_obj_manager_option(s_opt_anim_enabled, s_opt_type_int, True),
        nt_obj_manager_option(s_opt_anim_delay, s_opt_type_int, 50),
        # NOTE: the following two options are True by default in CLI mode
        #     but depends on puzzle_view_debug (base.misc) in the GUI viewer
        nt_obj_manager_option(s_opt_show_solution, s_opt_type_int,
                              puzzle_view_debug),
        nt_obj_manager_option(s_opt_raw_part_info, s_opt_type_int,
                              puzzle_view_debug),
    )

    def create_default_objects_resdata(self):
        '''
        Calls the create_default_objects_resdata method of the parent class,
            and creates further default objects available only from the GUI.
        '''
        ResDataManager_CliConf.create_default_objects_resdata(self)

        # * ViewerDataObj objects *
        # NOTE that animation viewers are currently only accessible
        #     from the GUI
        self.add_viewer_data_obj(ext_subf_anm, ViewerDataObj_AnmViewer())

        self.add_viewer_data_obj(s_res_file_special,
                                 ViewerDataObj_StoredDataAnim())


l_possib_zoom = '1 2 3 4 5 6 8 10 12 16'.split()
l_possib_flip = ('No flip [0]', 'Vertical [1]', 'Horizontal [2]',
                 'Vertical & Horizontal [3]')
l_possib_enabled = ('Disabled [0]', 'Enabled [1]')
l_possib_show = ('Hide [0]', 'Show [1]')

label_anim_enabled = 'Animation enabled:'
label_anim_delay = 'Delay between anim. frames (ms):'
label_zoom = 'Zoom:'
label_flip = 'Flip:'
label_backgr_color = 'Background color:'
label_font_color = 'Font color:'
label_s_opt_pal_file_def = 'Palette resource name:'
label_s_opt_pal_file_def_2 = 'Palette resource name #2:'
label_s_opt_export_hide_local = 'Hide "local" files during export'
label_s_opt_show_solution = 'Solution for puzzles'
label_s_opt_raw_part_info = '"Raw" info for puzzle parts'
comment_flip = 'Not supported for all item types'
comment_backgr_color = 'Color format: rrggbb (hexadecimal) or empty'
comment_font_color = 'Format same as above, used for 1BPP fonts'
comment_s_opt_pal_file_def = 'Name of a sub-file in the resource file'


class OptionsDialog_GuiConf(OptionsDialogBase):
    '''
    OptionsDialogBase subclass. Modifies options_dialog_fields
        to contain information about the options that can be modified
    '''

    # options_dialog_fields : empty in parent!
    # NOTE that not all options are editable (non-editable opts
    #     are NOT listed here)

    options_dialog_fields = (
        nt_options_dialog_field(s_opt_anim_enabled, s_opt_type_int,
                                label_anim_enabled, None, l_possib_enabled,
                                None),
        nt_options_dialog_field(s_opt_anim_delay, s_opt_type_int,
                                label_anim_delay, None, None, None),
        nt_options_dialog_field(s_opt_zoom, s_opt_type_int, label_zoom, None,
                                l_possib_zoom, None),
        nt_options_dialog_field(s_opt_flip, s_opt_type_int, label_flip,
                                comment_flip, l_possib_flip, None),
        nt_options_dialog_field(s_opt_backgr_color, s_opt_type_color_none,
                                label_backgr_color, comment_backgr_color, None,
                                extra_button_id_color),
        nt_options_dialog_field(s_opt_font_color, s_opt_type_color_none,
                                label_font_color, comment_font_color, None,
                                extra_button_id_color),
        nt_options_dialog_field(s_opt_pal_file_def, s_opt_type_str,
                                label_s_opt_pal_file_def,
                                comment_s_opt_pal_file_def, None, None),
        nt_options_dialog_field(s_opt_pal_file_def_2, s_opt_type_str,
                                label_s_opt_pal_file_def_2, None, None, None),
        nt_options_dialog_field(s_opt_export_hide_local, s_opt_type_int,
                                label_s_opt_export_hide_local, None,
                                l_possib_enabled, None),
        nt_options_dialog_field(s_opt_show_solution, s_opt_type_int,
                                label_s_opt_show_solution, None, l_possib_show,
                                None),
        nt_options_dialog_field(s_opt_raw_part_info, s_opt_type_int,
                                label_s_opt_raw_part_info, None, l_possib_show,
                                None),
    )
