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
from tkinter import ttk, messagebox as mb

from timgres.base.misc import (print_msg, print_traceback, tag_sel, tag_dbl,
                               s_export_text_list_fileinfo,
                               s_export_bin_single_file,
                               s_export_bin_all_files, s_export_bin_file_list,
                               s_export_bin_file_pattern)
from timgres.base.basecl import nt_exporter_id_descr
from timgres.gui.expgui import gui_export, export_create_menu
# FIXME? should be moved to misc?
from timgres.gui.treepnl import (s_text_no_res_file,
                                 res_sub_file_opened_panel_text)

#  --- "All resource sub-files" window ---

'''
This module contains the class AllResourceSubFilesWindow, which displays
    basic information about all sub-files of a resource file
    (not just the file types for which a decoder is present).
'''

exporter_obj_ids_all_res = (s_export_text_list_fileinfo,
                            s_export_bin_all_files, s_export_bin_file_pattern)

s_text_no_file_selected = 'No sub-file selected.'
s_text_1_file_selected = '1 sub-file selected.'
s_text_files_selected = '%d sub-files selected.'
s_text_button_export_single = 'Export sub-file'
s_text_button_export_multi = 'Export sub-files'
s_text_col_headers = ('Sub-file name', 'Resource file ID',
                      'Start position (bytes)', 'Size (bytes)')

def_col_width = 150  # fixme
s_column_ids = ('res_file', 'start_pos', 'file_size')

s_err_title_all_sub_files = 'Error - View all sub-files'


class AllResourceSubFilesWindow(object):
    '''
    Creates a top-level window that displays information about all sub-files
        present in a resource file, (not just the file types for which a
        decoder is present).
    '''

    def __init__(self, parent):
        '''
        The constructor of the class. requires one argument.
        parent: The main window (TLevelImgViewerMainWindow)
        '''
        # This class uses the get_res_data_manager(), get_export_initial_dir()
        #     and export_selection()
        self.parent = parent
        self.export_initial_dir = parent.get_export_initial_dir()
        self.reset_data()

        self.var_file_name = tki.StringVar()
        self.var_file_name.set(s_text_no_res_file)
        self.var_n_files_sel = tki.StringVar()
        self.var_n_files_sel.set(s_text_no_file_selected)
        self.var_exp_button_text = tki.StringVar()
        self.var_exp_button_text.set(s_text_button_export_single)

        self.window = tki.Toplevel()  # self.parent.(?)
        self.frame = None  # fixme
        self.create_widgets()
        self.create_file_list_items()

    def reset_data(self):
        '''Resets the data stored in the object.'''
        # sub_file_info: stores information about the sub-files that
        #    will be shown in the tree viewer (list of nt_sub_file_info
        #    namedtuples.)
        self.sub_file_info = []

    def create_widgets(self):
        '''Creates the main frame and the widgets.'''
        self.frame = ttk.Frame(self.window)

        self.label_f_name = ttk.Label(self.frame,
                                      textvariable=self.var_file_name).grid(
                                          column=0,
                                          row=0,
                                          columnspan=4,
                                          sticky='nsew',
                                          padx=3,
                                          pady=3)

        # NO column info by default
        self.files_w = ttk.Treeview(self.frame, columns=s_column_ids)
        self.files_w.grid(column=0, row=1, columnspan=3, sticky='nsew')

        self.scrollx_i = ttk.Scrollbar(self.frame,
                                       orient=tki.HORIZONTAL,
                                       command=self.files_w.xview)
        self.files_w.configure(xscrollcommand=self.scrollx_i.set)
        self.scrollx_i.grid(column=0, row=2, columnspan=3, sticky='ew')

        self.scrolly_i = ttk.Scrollbar(self.frame,
                                       orient=tki.VERTICAL,
                                       command=self.files_w.yview)
        self.files_w.configure(yscrollcommand=self.scrolly_i.set)
        self.scrolly_i.grid(column=3, row=1, sticky='ns')

        self.files_w.tag_bind(tag_dbl, '<Double-1>', self.ev_item_dbl_clicked)
        self.files_w.tag_bind(tag_sel, '<<TreeviewSelect>>',
                              self.ev_tree_select)

        for c_index, c_text in enumerate(s_text_col_headers[1:]):
            self.files_w.heading(c_index, text=c_text)
            self.files_w.column(c_index, width=def_col_width)

        self.files_w.heading('#0', text=s_text_col_headers[0])
        self.files_w.column('#0', width=def_col_width)

        self.n_files_sel = ttk.Label(self.frame,
                                     textvariable=self.var_n_files_sel).grid(
                                         column=0,
                                         row=3,
                                         sticky='nsew',
                                         padx=3,
                                         pady=3)

        ttk.Button(self.frame,
                   textvariable=self.var_exp_button_text,
                   command=self.export_files).grid(column=1,
                                                   row=3,
                                                   sticky='ew',
                                                   padx=3,
                                                   pady=3)

        self.exp_menu_button = ttk.Menubutton(self.frame, text='Export...')
        self.exp_menu_button.grid(column=2, row=3, sticky='ew', padx=3, pady=3)
        # According to the doc, the button must be parent of menu
        self.export_menu = tki.Menu(self.exp_menu_button)
        self.exp_menu_button.configure(menu=self.export_menu)

        # NOTE: exp_menu contains only item that do not depend on item
        #     selection. Therefore, self.parent.export_selection() can be used

        export_create_menu(
            self.export_menu, self.parent.export_selection,
            self._get_menu_item_tuples(exporter_obj_ids_all_res))

        self.window.bind(
            '<Escape>',
            lambda ev: self.files_w.selection_remove(self.files_w.selection()))
        # TODO, more convenient multi-select

        self.frame.columnconfigure(0, weight=1)
        self.frame.columnconfigure(1, weight=1)
        self.frame.columnconfigure(2, weight=1)
        self.frame.rowconfigure(1, weight=1)
        self.frame.grid(column=0, row=0, sticky='nsew')

        self.window.columnconfigure(0, weight=1)
        self.window.rowconfigure(0, weight=1)

        self.window.title('All resource sub-files')

    def _get_menu_item_tuples(self, obj_ids):
        '''
        "Private", "helper" function. Returns a list of nt_exporter_id_descr
            namedtuples for objects with IDs specified in obj_ids.
        obj_ids (list or tuple): List "or tuple) of exporter object IDs.
        '''
        res_data_mgr = self.parent.get_res_data_manager()

        return [
            nt_exporter_id_descr(
                x,
                res_data_mgr.get_exporter(x).get_exporter_description())
            for x in obj_ids
        ]

    def clear_widget_items(self):
        '''
        Deletes all items of the widget showing thr resource
            sub-file information.
        '''
        # self.tree.delete() should delete children too
        for file_info_item in self.sub_file_info:
            self.files_w.delete(file_info_item.sub_f_name)

        self.reset_data()

    def create_widget_items(self):
        '''
        Creates the items of the resource sub-files widget using the
            information stored in self.sub_file_info.
        '''
        for file_info_item in self.sub_file_info:
            # Hack, convert 0-based indices to 1-based
            file_info_item_mod = [str(x) for x in file_info_item[2:]]

            if file_info_item[1] == -1:
                file_info_item_mod.insert(0, 'Dir (0)')
            elif file_info_item[1] == -2:
                file_info_item_mod.insert(0, 'Local (-1)')
            else:
                file_info_item_mod.insert(0, str(file_info_item[1] + 1))

            self.files_w.insert('',
                                'end',
                                file_info_item.sub_f_name,
                                text=file_info_item.sub_f_name,
                                values=file_info_item_mod,
                                tags=(tag_sel, tag_dbl))

    def create_file_list_items(self):
        '''
        Obtains the information about the resource sub-files that will
            be displayed from self.parent. Updates self.sub_file_info.
            Updates the list widget of sub-files.
        '''
        try:
            self.clear_widget_items()
            res_data_mgr = self.parent.get_res_data_manager()
            res_read = res_data_mgr.get_res_read_obj()

            if res_read is None:
                self.var_file_name.set(s_text_no_res_file)
                return

            # TODO, filter out "local" files in "files" sub-directory (?)
            self.sub_file_info = res_read.get_file_data_nofilter_sorted()

            self.create_widget_items()

            self.var_file_name.set(
                res_sub_file_opened_panel_text(res_data_mgr))

        except Exception as ex:
            err_msg = 'Failed co create sub-file list items - %s' % ex

            print_msg(err_msg)
            print_traceback()
            self.var_file_name.set(s_text_no_res_file)

            mb.showerror(s_err_title_all_sub_files, err_msg)

    def items_selected(self, items):
        '''
        Updates labels, button texts, etc. based on the current selection.
        items (list or tuple): List of the selected item IDs.
        '''
        # items: list or tuple of file names
        len_items = len(items)

        if len_items == 0:
            self.var_n_files_sel.set(s_text_no_file_selected)
            # NOTE: var_exp_button_text is also set for "consistent result"
            self.var_exp_button_text.set(s_text_button_export_single)
            # TODO, disable the button
        elif len_items == 1:
            self.var_n_files_sel.set(s_text_1_file_selected)
            self.var_exp_button_text.set(s_text_button_export_single)
        else:
            self.var_n_files_sel.set(s_text_files_selected % len_items)
            self.var_exp_button_text.set(s_text_button_export_multi)

    def export_files(self):
        '''
        Callback function, executed when the "Export file(s)" button
            was pressed. Exports the currently selected resource sub-file(s)
            in "raw" (binary data, unchanged) format.
        '''
        try:
            items_sel = self.files_w.selection()
            len_items = len(items_sel)

            if len_items == 0:
                mb.showwarning(s_err_title_all_sub_files, 'No file selected.')
                return

            if len_items == 1:
                exporter_obj = self.parent.get_res_data_manager().get_exporter(
                    s_export_bin_single_file)
                # NOTE: this method does not use get_exporter_set_sub_f_name!
                exporter_obj.reset_data()
                exporter_obj.set_argument_file(items_sel[0])
            else:
                exporter_obj = self.parent.get_res_data_manager().get_exporter(
                    s_export_bin_file_list)
                exporter_obj.reset_data()
                exporter_obj.set_argument_file_list(items_sel)

            exported_f_name = gui_export(exporter_obj, self.export_initial_dir)

            if exported_f_name is not None:
                self.export_initial_dir = os.path.dirname(exported_f_name)

        except Exception as ex:
            str_error = 'Export failed - %s' % ex
            print_msg(str_error)
            print_traceback()
            mb.showerror(s_err_title_all_sub_files, str_error)

    def wait_window(self):
        '''
        Wait until the window is closed.
        '''
        self.window.wait_window()

    def ev_item_dbl_clicked(self, ev):
        '''
        Callback function for the "double click in list/tree viewer" event.
        ev: tkinter event object
        '''
        # todo, todo, does nothing on double click
        pass

    def ev_tree_select(self, ev):
        '''
        Callback function for the "item selected in list/tree viewer" event.
        ev: tkinter event object
        '''
        try:
            self.items_selected(self.files_w.selection())
        except Exception as ex:
            err_msg = 'Tree item selection failed - %s' % ex
            print_msg(err_msg)
            print_traceback()
            mb.showerror(s_err_title_all_sub_files, err_msg)
