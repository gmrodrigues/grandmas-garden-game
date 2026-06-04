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
import tkinter as tki
from tkinter import ttk, messagebox as mb, filedialog as fd
from timgres.base.misc import (print_msg, print_traceback, s_opt_pal_file_def,
                               s_opt_pal_file_def_2, s_obj_resreadmap,
                               s_obj_resreaddir, s_open_res_cback_pal,
                               version_str, copyright_info, main_window_title)

from timgres.gui.guiconf import ResDataManager_GuiConf, OptionsDialog_GuiConf
from timgres.gui.treepnl import (TreePanel_ResSubFiles,
                                 TreePanel_RSViewerSubItems,
                                 nt_res_sub_files_open_options)
from timgres.gui.animipnl import AnimAndInfoPanel
from timgres.gui.expgui import (ViewerObjSelectDialog, gui_export,
                                export_create_menu)
from timgres.gui.allrfwnd import AllResourceSubFilesWindow

# --- Main window class ---

'''This module contains the main window class, TLevelImgViewerMainWindow'''

dlg_title_open_res = 'Open resource file'
dlg_title_open_dir = 'Open resources from directory'
dlg_title_about = 'About'

menu_label_file = 'File'
menu_label_export = 'Export'
menu_label_help = 'Help'
menu_item_open_res_map = 'Open resource MAP file...'
menu_item_open_res_dir = 'Load resources from directory...'
menu_item_close_res_map = 'Close opened resource MAP file'
menu_item_close_res_dir = 'Close opened resource directory'
menu_item_all_res_files = 'Show all resource sub-files...'
menu_item_options = 'Options...'
menu_item_quit = 'Quit'
menu_item_about = 'About...'

str_confirm_close_title = 'Confirm close'
str_confirm_close_format = ('A %s is also loaded. Keep it open?\n'
                            '(Yes - keep open, No - close)')
str_err_close_title = 'Error - Close resources'
str_error_close_res_format = 'Error, no %s is open.'

str_confirm_close_res_map = 'resource file'
str_confirm_close_res_dir = 'directory'

str_warn_export = 'Export warning'

str_warn_export_file = ('No sub-file is selected, but the selected '
                        'type of export requires one.')

str_warn_export_viewer = ('No sub-item is selected, but the selected '
                          'type of export requires one.')


class TLevelImgViewerMainWindow(object):

    def __init__(self, root):
        '''
        The constructor of the class. requires one argument.
        root: tke tkinter.Tk object, created in gui.guimain
        '''
        self.root = root
        self.res_data_mgr = ResDataManager_GuiConf()
        self.frame = None
        self.res_sub_files_panel = None
        self.rs_file_sub_items_panel = None
        self.anim_info_panel = None
        self.open_initial_dir = ''
        self.export_initial_dir = ''
        self.all_sub_files_window = None
        self.options_window = None

        self.create_widgets()

        self.sub_file_selected = self.rs_file_sub_items_panel.open_file
        self.sub_item_selected = self.anim_info_panel.sub_item_selected

    def create_widgets(self):
        '''Creates the main frame and the widgets.'''
        # Version 0.2: Now uses a Panedwindow widget
        self.paned_win = ttk.Panedwindow(self.root, orient='horizontal')

        self.create_menus()

        # NOTE: row 0 is reserved for toolbar!
        self.res_sub_files_panel = TreePanel_ResSubFiles(self)
        self.paned_win.insert('end', self.res_sub_files_panel.get_frame())

        self.rs_file_sub_items_panel = TreePanel_RSViewerSubItems(self)
        self.paned_win.insert('end', self.rs_file_sub_items_panel.get_frame())

        self.anim_info_panel = AnimAndInfoPanel(self)
        self.paned_win.insert('end', self.anim_info_panel.get_tab_widget())

        self.root.title(main_window_title)

    def create_menus(self):
        '''Creates the menu bar and all menu items.'''
        menu_bar = tki.Menu(self.root)

        # * File *
        menu_file = tki.Menu(menu_bar)
        menu_file.add_command(label=menu_item_open_res_map,
                              command=self.open_dialog_res_map)
        menu_file.add_command(label=menu_item_open_res_dir,
                              command=self.open_dialog_res_dir)

        menu_file.add_separator()

        menu_file.add_command(label=menu_item_close_res_map,
                              command=self.close_res_map)
        menu_file.add_command(label=menu_item_close_res_dir,
                              command=self.close_res_dir)

        menu_file.add_separator()
        menu_file.add_command(label=menu_item_all_res_files,
                              command=self.show_all_sub_files_window)
        menu_file.add_command(label=menu_item_options,
                              command=self.options_dialog)
        menu_file.add_separator()
        menu_file.add_command(label=menu_item_quit, command=self.root.quit)

        menu_bar.add_cascade(menu=menu_file, label=menu_label_file)

        menu_export = tki.Menu(menu_bar)
        export_create_menu(menu_export, self.export_selection,
                           self.res_data_mgr.get_exporter_object_info())

        menu_bar.add_cascade(menu=menu_export, label=menu_label_export)

        menu_help = tki.Menu(menu_bar)
        menu_help.add_command(label=menu_item_about,
                              command=self.show_about_dialog)

        menu_bar.add_cascade(menu=menu_help, label=menu_label_help)

        self.root.configure(menu=menu_bar)

    def get_parent_widget(self):
        '''
        Returns the top-level widget ofthe window (type: ttk.Panedwindow)
        '''
        return self.paned_win

    def get_res_data_manager(self):
        '''
        Returns the "resource data manger" object stored in the main window
            object (type: ResDataManager_GuiConf)
        '''
        return self.res_data_mgr

    def get_export_initial_dir(self):
        '''
        Returns the "initial directory" for export, typically the directory
            of the last exported file. Used for "save as" dialogs. (type: str)
        '''
        return self.export_initial_dir

    def open_resources(self,
                       new_f_name,
                       res_reader_obj_id,
                       warn_close_others=True):
        '''
        Opens a resource file (or directory) using a file name and a
            resource reader object ID. Used in_gui_main to open
            a file specified as a command line argument as well as the
            open_dialog_* methods.
        new_f_name (str or None): Path to the file (or directory) to open.
            A valoe fo None means that the file or directory opened in
            res_reader_obj_id must be closed.
        res_reader_obj_id (str): The ID of the resource reader object in
            self.res_data_mgr to use.
        warn_close_others (bool): warn_close_others == True means that a
            confirmation dialog box will be shown if a file/directory is
            opened in an other resource viewer
        '''
        # NOTE: no exception handler, all exceptions are handled
        #     in gui.treepnl
        # NOTE: if warn_close_others is False, close_others defaults to False
        #     i.e. do not close file/directory in other resource readers
        close_others = False

        if warn_close_others:
            if res_reader_obj_id == s_obj_resreadmap:
                if self.res_data_mgr.get_object(
                        s_obj_resreaddir).get_res_f_name() is not None:
                    close_others = not mb.askyesno(
                        str_confirm_close_title,
                        str_confirm_close_format % str_confirm_close_res_dir)
            elif res_reader_obj_id == s_obj_resreaddir:
                if self.res_data_mgr.get_object(
                        s_obj_resreadmap).get_res_f_name() is not None:
                    close_others = not mb.askyesno(
                        str_confirm_close_title,
                        str_confirm_close_format % str_confirm_close_res_map)

        self.res_sub_files_panel.open_file(
            new_f_name,
            nt_res_sub_files_open_options(res_reader_obj_id, close_others))

        if self.all_sub_files_window is not None:
            self.all_sub_files_window.create_file_list_items()

    def open_dialog_res_map(self):
        '''
        Shows an open dialog, prompting the user to choose a resource file
            name. Opens the file if the OK button was pressed.
        '''
        fn = fd.askopenfilename(title=dlg_title_open_res,
                                initialdir=self.open_initial_dir)

        if not fn: return  # None or ''

        self.open_initial_dir = os.path.dirname(fn)
        self.open_resources(fn, s_obj_resreadmap, True)

    def open_dialog_res_dir(self):
        '''
        Shows an open dialog, prompting the user to choose a resource
            directory name. Opens the file if the OK button was pressed.
        '''
        fn = fd.askdirectory(title=dlg_title_open_dir,
                             initialdir=self.open_initial_dir,
                             mustexist=True)

        if not fn: return  # None or ''

        self.open_initial_dir = os.path.dirname(fn)
        self.open_resources(fn, s_obj_resreaddir, True)

    def close_res_map(self):
        '''
        Closes the resource file opened in object s_obj_resreadmap
            if one is open. Otherwise, shows an error message.
        '''

        if self.res_data_mgr.get_object(
                s_obj_resreadmap).get_res_f_name() is None:
            mb.showerror(
                str_err_close_title,
                str_error_close_res_format % str_confirm_close_res_map)

            return

        self.open_resources(None, s_obj_resreadmap, False)

    def close_res_dir(self):
        '''
        Closes the directory opened in object s_obj_resreaddir
            if one is open. Otherwise, shows an error message.
        '''
        if self.res_data_mgr.get_object(
                s_obj_resreaddir).get_res_f_name() is None:
            mb.showerror(
                str_err_close_title,
                str_error_close_res_format % str_confirm_close_res_dir)

            return

        self.open_resources(None, s_obj_resreaddir, False)

    def show_all_sub_files_window(self):
        '''
        Shows the "all resource sub-files" window. Only allows one such
            window to be shown at the same time.
        '''
        if self.all_sub_files_window is not None: return

        self.all_sub_files_window = AllResourceSubFilesWindow(self)
        self.all_sub_files_window.wait_window()
        self.all_sub_files_window = None  # fixme

    def options_dialog(self):
        '''
        Show the options dialog. Updates the palette if the palette name
            was changed in dialog. Updates anim/info panel.
        '''
        try:
            # Palette reload if the palettes were changed in the Options
            #   dialog. Todo: need to fund a more "logical" place for this
            # Note: may compare strings with None, but this should be OK

            pal1_save = self.res_data_mgr.get_option(s_opt_pal_file_def)
            pal2_save = self.res_data_mgr.get_option(s_opt_pal_file_def_2)

            self.options_window = OptionsDialog_GuiConf(self)
            result = self.options_window.wait_get_result()
            self.options_window = None  # fixme

            if result:
                if ((self.res_data_mgr.get_option(s_opt_pal_file_def) !=
                     pal1_save)
                        or (self.res_data_mgr.get_option(s_opt_pal_file_def_2)
                            != pal2_save)):
                    self.res_data_mgr.call_res_callback_func(
                        s_open_res_cback_pal)

                # TODO: In current version, pressing OK causes the full reload
                #     of the resource sub-file (i.e. it will be decoded again
                #     and the ViewerDataObj sub-items are re-created.)
                #     This is also done in cases when it is not necessary
                sub_f_selected = self.res_data_mgr.get_selected_sub_f_name()

                if sub_f_selected is not None:
                    viewer_obj_id_sel, sub_item_num = self.anim_info_panel.\
                        get_selected_viewer_obj_and_item()

                    self.sub_file_selected(sub_f_selected)
                    # NOTE: self.anim_info_panel.update_anim_and_info()
                    #     does NOT work here
                    self.sub_item_selected(viewer_obj_id_sel, sub_item_num)

        except Exception as ex:
            # this should very rarely happen
            print_traceback()
            mb.showerror('Error - Options',
                         'Failed to create options dialog - %s' % ex)

    def get_def_viewer_id_for_sel(self):
        '''
        Helper function, called by export_selection.
        Returns the viewer object ID (str) associated with the selection in
            the anim_info_panel, the default viewer object ID for file type,
            or None if both attempt had failed for determining thw viewer ID
        '''
        # Returns a viewer object ID for export
        #     If one viewer is selected in anim_info_panel, will return it
        #     If none is selected, returns the default object by the
        #     extension of selected file.
        #     If no file is selected, returns None

        viewer_obj_id_sel, sub_item_num = \
            self.anim_info_panel.get_selected_viewer_obj_and_item()

        if viewer_obj_id_sel is not None:
            return viewer_obj_id_sel
        else:
            file_name_sel = self.res_data_mgr.get_selected_sub_f_name()

            if file_name_sel is not None:
                return self.res_data_mgr. \
                    get_default_viewer_id_for_file(file_name_sel)

        return None  # otherwise

    def export_selection(self, exporter_obj_id):
        '''
        Performs an export using object ID exporter_obj_id.
        Sets the arguments required by the exporter and then calls gui_export.
        Contains the exception handler for the "export" code.
        exporter_obj_id (str): The exporter object ID.
        '''

        try:
            # NOTE: self.res_data_mgr stores the selected sub-file name
            #     but not the viewer data obj or the selection in it.
            #     This data is obtained from self.anim_info_panel

            exporter_obj = self.res_data_mgr.get_exporter_set_sub_f_name(
                exporter_obj_id)

            if exporter_obj is None:
                # HACK, None is returned when no file is selected, but the
                #     requires one. A warning (not error) message will be shown
                mb.showwarning(str_warn_export, str_warn_export_file)

                return

            if exporter_obj.requires_argument_viewer_obj_id():
                # NOTE: the current strategy for determining the viewer
                #     object ID:
                # 1. The exporter requires a single file
                #     a) Use the selected viewer in TreePanel_RSViewerSubItems
                #     b) If none is selected, use the default viewer by
                #        file extension
                # 2. Exporter requires a wildcard instead of a single file
                #     (using the selected viewer in TreePanel_RSViewerSubItems
                #     panel would be confusing)
                #     a) Show a "choose viewer object" dialog

                def_viewer_id = self.get_def_viewer_id_for_sel()

                if ((def_viewer_id is not None)
                        and exporter_obj.requires_argument_file()):
                    viewer_obj_id = def_viewer_id
                else:
                    # Note that the constructor of ViewerObjSelectDialog
                    #     accepts both a default object and None as second arg
                    viewer_obj_id = ViewerObjSelectDialog(
                        self.res_data_mgr.get_viewer_info_for_all_ext(),
                        def_viewer_id).wait_get_result()
                    # Cancel pressed or closed - return
                    if viewer_obj_id is None: return

                exporter_obj.set_argument_viewer_obj_id(viewer_obj_id)

                # Assume that viewer_sub_item is used only by exporters that
                #     require a viewer_obj_id, too

                if exporter_obj.requires_argument_viewer_sub_item():
                    viewer_obj_id_sel, sub_item_num = \
                        self.anim_info_panel.get_selected_viewer_obj_and_item()

                    if ((sub_item_num is None)
                            or (viewer_obj_id_sel != viewer_obj_id)):
                        mb.showwarning(str_warn_export, str_warn_export_viewer)
                        return

                    exporter_obj.set_argument_viewer_sub_item(sub_item_num)

            save_sub_f_selected = self.res_data_mgr.get_selected_sub_f_name()

            exported_f_name = gui_export(exporter_obj, self.export_initial_dir)

            if exported_f_name is not None:
                self.export_initial_dir = os.path.dirname(exported_f_name)

            # FIXME, this may leave the ViewerDataObj in "inconsistent" state
            if save_sub_f_selected is not None:
                if (exporter_obj.requires_argument_viewer_obj_id()
                        and (exporter_obj.requires_argument_name_wildcard()
                             or exporter_obj.requires_argument_file_list())):
                    self.sub_file_selected(save_sub_f_selected)

        except Exception as ex:
            str_error = 'Export failed - %s' % ex
            print_msg(str_error)
            print_traceback()
            mb.showerror('Export error', str_error)

    def show_about_dialog(self):
        '''Shows the "about" window.'''
        # Currently, a simple messagebox
        mb.showinfo(dlg_title_about, version_str + '\n' + copyright_info)
