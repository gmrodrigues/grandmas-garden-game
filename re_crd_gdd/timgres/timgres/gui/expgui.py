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

import os, re
from collections import namedtuple
import tkinter as tki
from tkinter import ttk, messagebox as mb, filedialog as fd
from timgres.base.basecl import nt_export_name_wildcard
from timgres.base.misc import print_msg, print_traceback, s_vdata_bmpsubimg

# --- Export GUI module ---

'''
Module providing GUI-based classes and helper functions related to
    file/image export.
Includes RegExp/Wildcard dialog and Export menu generation.
'''

# ... Viewer object selection dialog...


class ViewerObjSelectDialog(object):
    '''
    Dialog for prompting the user to choose a "viewer object".
    To obtain the result, wait_get_result() must be called.
    '''

    def __init__(self, item_list, obj_id_selected=None):
        '''
        The constructor of the class. requires two arguments.
        item_list: list of nt_viewer_obj_info_ext nameduples as
            returned by ResDataManager.get_viewer_info_for_all_ext()
        obj_id_selected: the item that will be selected right after
            the dialog creation (value can be None)
        '''
        # dialog_result: stores the result - the ID of a viewer object.
        #    By default, None.
        self.dialog_result = None
        self.window = tki.Toplevel()

        # s_vdata_bmpsubimg is used as fallback if the second arg is None
        obj_id_sel_default = (obj_id_selected if obj_id_selected is not None
                              else s_vdata_bmpsubimg)

        self.var_viewer_obj_id = tki.StringVar()

        self.list_item_texts = []

        for list_item in item_list:
            item_text = '(%s) %s%s [%s]' % (list_item.file_ext,
                                            ('*' if list_item.is_default else
                                             ''), list_item.obj_descr,
                                            list_item.obj_id)

            self.list_item_texts.append(item_text)

            if list_item.obj_id == obj_id_sel_default:
                self.var_viewer_obj_id.set(item_text)

        self.create_widgets()

    def create_widgets(self):
        '''Creates the main frame and the widgets.'''
        self.frame = ttk.Frame(self.window)

        ttk.Label(
            self.frame,
            text='A viewer object must be selected for this type of export.'
        ).grid(column=0, row=0, columnspan=3, sticky='nsew', padx=3, pady=3)

        ttk.Label(self.frame, text='Object name').grid(column=0,
                                                       row=1,
                                                       sticky='nsew',
                                                       padx=3,
                                                       pady=3)

        ttk.Combobox(self.frame,
                     state='readonly',
                     width=50,
                     textvariable=self.var_viewer_obj_id,
                     values=self.list_item_texts).grid(column=1,
                                                       row=1,
                                                       columnspan=2,
                                                       sticky='nsew',
                                                       padx=3,
                                                       pady=3)

        ttk.Button(self.frame, text='Ok',
                   command=self.ok_pressed).grid(column=1,
                                                 row=2,
                                                 sticky='ew',
                                                 padx=3,
                                                 pady=3)

        ttk.Button(self.frame, text='Cancel',
                   command=self.window.destroy).grid(column=2,
                                                     row=2,
                                                     sticky='ew',
                                                     padx=3,
                                                     pady=3)

        self.frame.columnconfigure(1, weight=1)
        self.frame.columnconfigure(2, weight=1)
        self.frame.rowconfigure(0, weight=1)
        self.frame.rowconfigure(1, weight=1)
        self.frame.rowconfigure(2, weight=1)
        self.frame.grid(column=0, row=0, sticky='nsew')
        self.window.columnconfigure(0, weight=1)
        self.window.rowconfigure(0, weight=1)

        self.window.title('Export - Select Viewer object')

    def ok_pressed(self):
        '''
        Callback function, executed when the OK button was pressed.
        Validates the dialog data. The dialog is closed and self.dialog_result
            is set if the data is valid.
        '''
        # NOTE: wait_get_result will return None if the value of
        #     self.var_viewer_obj_id is invalid

        text_selection = self.var_viewer_obj_id.get()
        if '[' not in text_selection: return
        self.dialog_result = text_selection.rsplit('[', 1)[1].rstrip(']')
        self.window.destroy()

    def wait_get_result(self):
        '''
        Wait until the dialog is closed and return the data stored in
            self.dialog_result. The result will be None if the Cancel button
            was pressed. Returns a viewer object name (str) or None
        '''
        self.window.wait_window(self.window)
        return self.dialog_result


# ... Wildcard/RegExp dialog ...

# TODO, localizability
text_widldcard_regexp = ('Wildcard:', 'Regular expression:')


class WildcardRegexpDialog(object):
    '''
    Dialog used for prompting the user to enter a wildcard or a regular
        expression, required for some exporters.
    To obtain the result, wait_get_result() must be called.
    '''

    def __init__(self):
        '''The constructor of the class. requires no arguments.'''

        # dialog_result: The result is stored in this field after
        #     the OK button was pressed and the data validation succeeded.
        # Type: a nt_export_name_wildcard namedtuple (wildcard input),
        #     an object returned by re.compile (regexp input)
        #     or None (canceled)
        self.dialog_result = None
        self.window = tki.Toplevel()

        self.var_wildcard_regexp_input = tki.StringVar()
        self.var_wildcard_regexp_select = tki.IntVar()
        self.var_wildcard_regexp_select.set(0)
        self.var_wildcard_regexp_label = tki.StringVar()
        self.var_wildcard_regexp_label.set(text_widldcard_regexp[0])
        self.var_case_sensitive = tki.IntVar()
        self.var_case_sensitive.set(0)

        self.create_widgets()

    def create_widgets(self):
        '''Creates the main frame and the widgets.'''
        self.frame = ttk.Frame(self.window)

        ttk.Label(self.frame,
                  textvariable=self.var_wildcard_regexp_label).grid(
                      column=0, row=0, sticky='nsew', padx=3, pady=3)

        ttk.Entry(self.frame,
                  width=20,
                  textvariable=self.var_wildcard_regexp_input).grid(
                      column=1,
                      row=0,
                      columnspan=2,
                      sticky='nsew',
                      padx=3,
                      pady=3)

        ttk.Checkbutton(self.frame,
                        text='Case sensitive',
                        onvalue=1,
                        offvalue=0,
                        variable=self.var_case_sensitive).grid(column=0,
                                                               row=1,
                                                               sticky='nsew',
                                                               padx=3,
                                                               pady=3)

        ttk.Radiobutton(self.frame,
                        text='Wildcard',
                        value=0,
                        variable=self.var_wildcard_regexp_select,
                        command=self.radio_pressed).grid(column=1,
                                                         row=1,
                                                         sticky='nsew',
                                                         padx=3,
                                                         pady=3)

        ttk.Radiobutton(self.frame,
                        text='Regular expression',
                        value=1,
                        variable=self.var_wildcard_regexp_select,
                        command=self.radio_pressed).grid(column=2,
                                                         row=1,
                                                         sticky='nsew',
                                                         padx=3,
                                                         pady=3)

        ttk.Button(self.frame, text='Ok',
                   command=self.ok_pressed).grid(column=1,
                                                 row=2,
                                                 sticky='ew',
                                                 padx=3,
                                                 pady=3)

        ttk.Button(self.frame, text='Cancel',
                   command=self.window.destroy).grid(column=2,
                                                     row=2,
                                                     sticky='ew',
                                                     padx=3,
                                                     pady=3)

        self.frame.columnconfigure(1, weight=1)
        self.frame.columnconfigure(2, weight=1)
        self.frame.rowconfigure(0, weight=1)
        self.frame.rowconfigure(1, weight=1)
        self.frame.rowconfigure(2, weight=1)
        self.frame.grid(column=0, row=0, sticky='nsew')
        self.window.columnconfigure(0, weight=1)
        self.window.rowconfigure(0, weight=1)

        self.window.title('File name Wildcard/RegExp')

    def radio_pressed(self):
        '''
        Callback function called when the Wildcard or RegExp radio buttons
        were clicked. Updates the wildcard/regexp label text.
        '''
        self.var_wildcard_regexp_label.set(
            text_widldcard_regexp[self.var_wildcard_regexp_select.get()])

    def ok_pressed(self):
        '''
        Callback function, executed when the OK button was pressed.
        Validates the dialog data. The dialog is closed and self.dialog_result
            is set if the data is valid. If validation fails, the dialog
            remains visible and an appropriate error message is shown.
        '''
        try:
            wildcard_regexp_input = self.var_wildcard_regexp_input.get()
            case_sensitive = self.var_case_sensitive.get()

            if self.var_wildcard_regexp_select.get():
                # TODO, use the re.A flag?

                self.dialog_result = (re.compile(wildcard_regexp_input)
                                      if case_sensitive else re.compile(
                                          wildcard_regexp_input, re.I))
            else:
                # TODO, validate wildcards (?)
                self.dialog_result = nt_export_name_wildcard(
                    wildcard_regexp_input, case_sensitive)

            self.window.destroy()

        except Exception as ex:
            str_error = 'Invalid wildcard/regular expression - %s' % ex
            print_msg(str_error)
            print_traceback()
            mb.showerror('Export error', str_error)

    def wait_get_result(self):
        '''
        Wait until the dialog is closed and return the data stored in
            self.dialog_result. Returns a nt_export_name_wildcard namedtuple,
            a regexp object or None if Cancel was pressed.
        '''
        self.window.wait_window(self.window)
        return self.dialog_result


# ... GUI export function ...


def gui_export(exporter_obj, initial_dir):
    '''
    Exports data using the exporter exporter_obj. Prompts the user for the
    output file name. Shows message boxes if an error or a warning occurs.
    Data except wildcard/regexp must be already set in exporter_obj, the
        function currently does not provide any mechanism for setting them.
    Returns the name of saved file on success (or None on failure/cancel)
    exporter_obj (ResDataBase_Exporter subclass): The exporter object.
    initial_dir (str): Initial directory for the save dialog.
    '''
    str_error_part_file = ''

    try:
        if exporter_obj.requires_argument_name_wildcard():
            regexp_or_wildcard = WildcardRegexpDialog().wait_get_result()

            if regexp_or_wildcard is None: return  # Cancel

            exporter_obj.set_argument_name_wildcard(regexp_or_wildcard)

        dialog_title = ('Save file - %s' %
                        exporter_obj.get_exporter_description())
        file_type_all = ('All files', '*')
        file_type_exporter = exporter_obj.get_export_ext_data()

        file_types = ((file_type_exporter,
                       file_type_all) if file_type_exporter != ('', '') else
                      (file_type_all, ))

        file_name_def = (exporter_obj.get_argument_file() if
                         (exporter_obj.requires_argument_file() and
                          (not exporter_obj.requires_argument_viewer_obj_id()))
                         else '')

        # Hack, uses defaultextension arg on Windows only. Seems to have
        #     "side effects" on Linux (dialog cannot be closed with the OK
        #     button if the extension is "incorrect".)
        # TODO, not tested on MacOS
        if sys.platform == 'win32':
            default_ext = exporter_obj.get_export_default_ext() or ''
        else:
            default_ext = ''

        out_f_name = fd.asksaveasfilename(title=dialog_title,
                                          initialdir=initial_dir,
                                          filetypes=file_types,
                                          initialfile=file_name_def,
                                          defaultextension=default_ext)

        if not out_f_name: return

        str_error_part_file = ', file "%s"' % out_f_name
        exporter_obj.set_warning_msg(None)  # not required, but make sure
        exporter_obj.export_to_file(out_f_name)

        warning_msg = exporter_obj.get_warning_msg()

        if warning_msg is not None:
            mb.showwarning('Export warning', warning_msg)

    except Exception as ex:
        str_error = 'Export failed%s - %s' % (str_error_part_file, ex)
        print_msg(str_error)
        print_traceback()
        mb.showerror('Export error', str_error)
        ## return # returns None


# ... Export menu ...


def _export_add_single_menu_item(parent_menu, export_func, exporter_id_descr):
    '''
    Helper function for export_create_menu, adds a single menu item.
    parent_menu (tkinter Menu object): the item will be added to this menu.
    export_func (callable): A callback function, requires one argument,
        the ID of the exporter object (str).
    exporter_id_descr (str): Short description of the exporter.
    '''
    # NOTE: this must be in a separate function due to the usage of lambda
    parent_menu.add_command(
        label=exporter_id_descr.exporter_description,
        command=lambda: export_func(exporter_id_descr.exporter_identifier))


def export_create_menu(parent_menu, export_func, exporter_info):
    '''
    Function that creates the items of a menu for choosing
        an export format (actually, an exporter object)
    parent_menu (tkinter Menu object): the item will be added to this menu.
    export_func (callable): A callback function, requires one argument,
        the ID of the exporter object (str).
    exporter_info: list of nt_exporter_id_descr namedtuples. returned by
        e.g. <ExporterObjectManagerBase subclass>.get_exporter_object_info()
    '''
    prefix_id_prev = None

    for exporter_id_descr in exporter_info:
        prefix_id = exporter_id_descr.exporter_identifier.split('_', 1)[0]

        if (prefix_id_prev is not None) and (prefix_id != prefix_id_prev):
            parent_menu.add_separator()

        _export_add_single_menu_item(parent_menu, export_func,
                                     exporter_id_descr)

        prefix_id_prev = prefix_id
