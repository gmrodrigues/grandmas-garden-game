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
from tkinter import ttk, messagebox as mb, colorchooser
from collections import namedtuple
from timgres.base.basecl import ObjectManager_Options
from timgres.base.misc import print_msg, print_traceback

# --- Options/settings dialog ---

'''
This module contains the class OptionsDialogBase, a base class for dialogs/
    toplevel windows that provide a GUI for editing options in
    ResDataManager subclass.
'''

extra_button_id_color = 'color'

title_options_dlg = 'Options'
title_options_error = 'Error - Options'
text_color_button = 'Choose'
dialog_entry_width = 40

# nt_options_dialog_field: OptionsDialogBase.options_dialog_fields
#     must contain one such namedtuple for each option that can be modified
#     using the dialog. Affects the widgets created for each option as well as
#       the method for getting the data.
# name and parser must match the class (tree manager)
#    that stores the options. possib_list, extra_button: None if unused!
# name (str): Must match the name of the option.
# parser (str): Must match the parser field of the corresponding
#    nt_fields_obj_manager_options item in the resource data manager object.
# label_text (str): The text of the label.
# comment (str or None): An optional comment for the field that will be shown
#    at the bottom part of the dialog (None means no such comment).
# possib_list (list, tuple or None): An optional list of items the user can
#    choose from. The strings in the list typically contain a (square)
#    "bracketed" part at the end, this part is passed to the parser function
#    for the option. Otherwise, the entire item text is used.
# extra_button (str or None): The optional ID of a callback function,
#     prompting the user for some type of input when a button is pressed.
nt_options_dialog_field = namedtuple(
    'nt_options_dialog_field',
    ('name', 'parser', 'label_text', 'comment', 'possib_list', 'extra_button'))

# nt_options_extra_button_info: for internal use, stored in
#     OptionsDialogBase.extra_button_info, contains the information for one
#     the of input.
# func_name (str): ID for the callback function.
# text (str): The caption of the button, shown in the dialog.
# click_func (callable): function that receives an initial value as argument
#     (usually str) and returns a new value for the option (str, None)
nt_options_extra_button_info = namedtuple(
    'nt_options_extra_button_info', ('func_name', 'button_text', 'click_func'))


def _click_func_color_dlg(value):
    '''
    Function used by the "extra buttons" feature for showing a color chooser
        dialog. Returns a color in "rrggbb' format or an empty strin
        (not None)
    value (str): The current value fo the field to edit.
    '''
    value_1 = '#' + value if value else ''

    col = colorchooser.askcolor(value_1)[1]

    if col is not None:
        return col.lstrip('#')
    else:
        return ''


def _combo_item_extract_value(value):
    '''
    "Private" function. Extracts the bracketed part from the chosen item (str)
        text or returns the input unchanged if there is None. Returns str.
    value (str): The input value.
    '''
    value_s = value.rstrip()
    return value_s.split('[', 1)[1].rstrip(']') if '[' in value_s else value_s


def _find_value_in_combo_items(item_list, value):
    '''
    "Private" function. Performs a simple search in a string list by
        matching "bracketed" part. Returns a string or None if not found.
    item_list (list or tuple): A string list, one of its items will be
        returned if a matching "bracketed" part was found.
    value (str): The value to search.
    '''

    for item in item_list:
        if _combo_item_extract_value(item) == value:
            return item


class OptionsDialogBase(object):
    '''
    A base dialog class, implemented as a "top-level window",
        for editing the value. Modifies the options in a "Resource Data
        Manager" when the OK button is clicked and the input is valid.
        Thr wait_get_result() method must be called to wait for the dialog.
    "Static" variable options_dialog_fields must be modified in sub-classes.
    '''

    # options_dialog_fields: must be modified in a sub-class!
    # IMPORTANT: The parser items of the namedtuples must match the
    #     corresponding option in the tree manager however this is not checked
    options_dialog_fields = ()

    # extra_button_info: List of nt_options_extra_button_info namedtuples
    #     (see documentation there)
    extra_button_info = (nt_options_extra_button_info(extra_button_id_color,
                                                      text_color_button,
                                                      _click_func_color_dlg), )

    # row_skip_top: Number of the rows to skip on the top of the dialog
    #     for a non-edit widget (e.g. a label)
    # TODO: actually row 0 is empty (but a label(?) may be added later)
    row_skip_top = 1
    # row_skip_above_buttons: Rows to skip below the "edit" widgets (but above
    #     the OK and Cancel buttons) for an "information" widget. shpuld NOT
    #     be set to 0 otherwise "weight" will be set incorrectly in
    #     columconfigure
    row_skip_above_buttons = 1

    def __init__(self, parent):
        '''
        The constructor of the class, requires one argument.
        parent: The main window (TLevelImgViewerMainWindow)
        '''
        # result: set to True if OK was clicked and validation succeeded
        self.result = False
        # uses get_tree_manager() from parent
        self.parent = parent
        self.widgets = []
        self.tkvars = []
        self.comments = []
        self.extra_buttons = {}

        for button_i in self.extra_button_info:
            self.extra_buttons[button_i.func_name] = button_i

        self.window = tki.Toplevel()  # self.parent.(?)
        self.frame = None  # fixme
        self.create_widgets()
        self.set_data_all_fields()

    def create_widgets(self):
        '''Creates the main frame and the widgets.'''
        self.frame = ttk.Frame(self.window)
        # TODO, add label widget at top

        for field_index, field_data in enumerate(self.options_dialog_fields):
            self.create_widgets_for_field(field_index, field_data)

        row_label_comment = len(self.widgets) + self.row_skip_top
        row_buttons = row_label_comment + self.row_skip_above_buttons
        text_comment = '\n'.join(self.comments)

        ttk.Label(self.frame, text=text_comment).grid(columnspan=3,
                                                      column=0,
                                                      row=row_label_comment,
                                                      sticky='nsew',
                                                      padx=3,
                                                      pady=3)

        ttk.Button(self.frame, text='OK',
                   command=self.ok_pressed).grid(column=1,
                                                 row=row_buttons,
                                                 sticky='ew',
                                                 padx=3,
                                                 pady=3)

        ttk.Button(self.frame, text='Cancel',
                   command=self.window.destroy).grid(column=2,
                                                     row=row_buttons,
                                                     sticky='ew',
                                                     padx=3,
                                                     pady=3)

        self.frame.columnconfigure(1, weight=1)
        self.frame.columnconfigure(2, weight=1)
        self.frame.rowconfigure(row_label_comment, weight=1)
        self.frame.grid(column=0, row=0, sticky='nsew')

        self.window.columnconfigure(0, weight=1)
        self.window.rowconfigure(0, weight=1)

        self.window.title('Options')

    def create_widgets_for_field(self, field_index, field_data):
        '''
        Creates the label, edit  and optionally the edit button widget for one
        field/option
        field_index (int): The index of the field (see options_dialog_field)
        field_data: A nt_options_dialog_field namedtuple
        '''
        # IMPORTANT: this must be a separate func, see below
        # field_data: nt_options_dialog_field, no type check
        row_field = field_index + self.row_skip_top

        var_field = tki.StringVar()  # TODO, uses StringVar for all fields!
        self.tkvars.append(var_field)

        if field_data.comment is not None:
            comment_num = len(self.comments) + 1
            self.comments.append('[%d] %s' % (comment_num, field_data.comment))
            label_text = '%s [%d]' % (field_data.label_text, comment_num)
        else:
            label_text = field_data.label_text

        ttk.Label(self.frame, text=label_text).grid(column=0,
                                                    row=row_field,
                                                    sticky='nsew',
                                                    padx=3,
                                                    pady=3)

        if field_data.possib_list is not None:
            # todo, no type check
            widget = ttk.Combobox(self.frame,
                                  state='readonly',
                                  width=dialog_entry_width,
                                  textvariable=var_field,
                                  values=tuple(field_data.possib_list))
        else:
            widget = ttk.Entry(self.frame,
                               width=dialog_entry_width,
                               textvariable=var_field)

        widget.grid(column=1,
                    row=row_field,
                    columnspan=2,
                    sticky='nsew',
                    padx=3,
                    pady=3)

        self.widgets.append(widget)

        if field_data.extra_button is not None:
            # NOTE: uses a lambda: with field_index, this is why
            #   create_widgets_for_field must be a separate method
            button_info = self.extra_buttons[field_data.extra_button]

            # TODO: button not stored in any list
            ttk.Button(
                self.frame,
                text=button_info.button_text,
                command=lambda: self.extra_button_clicked(field_index)).grid(
                    column=3, row=row_field, sticky='nsew', padx=3, pady=3)

    def get_data_field_index(self, field_index):
        '''
        Returns the form data for one field (type: str).
        field_index (int): The index of the field
        '''
        # No exception handler!
        field_data = self.options_dialog_fields[field_index]
        value = self.tkvars[field_index].get()

        if field_data.possib_list is not None:
            return _combo_item_extract_value(value)
        else:
            return value.rstrip()

    def set_data_field_index(self, field_index, new_value):
        '''
        Sets the value of a widget belonging to a single field.
        field_index (int): The index of the field
        new_value (str): The value to set.
        '''
        # No exception handler!
        field_data = self.options_dialog_fields[field_index]
        # fixme, uses '' for None (should be lowercase none?)
        # FIXME: missing support for float (e.g. 2 decimals?)
        value_str = str(new_value) if new_value is not None else ''

        if field_data.possib_list is not None:
            value_set = _find_value_in_combo_items(field_data.possib_list,
                                                   value_str)
        else:
            value_set = value_str.rstrip()

        self.tkvars[field_index].set(value_set)

    def set_data_all_fields(self):
        '''
        Retrieves the values of the editable options from the "Resource Data
            Manager", and uses this data to update all widgets.
        '''
        str_err_field = ''  # fixme

        try:
            res_data = self.parent.get_res_data_manager()

            for field_index, field_data in enumerate(
                    self.options_dialog_fields):
                str_err_field = ', field "%s"' % field_data.label_text
                f_value = res_data.get_option(field_data.name)
                self.set_data_field_index(field_index, f_value)

        except Exception as ex:
            str_err_msg = 'Failed to set data%s - %s' % (str_err_field, ex)
            print_msg('Options - %s' % str_err_msg)
            print_traceback()
            mb.showerror(title_options_error, str_err_msg)
            self.window.destroy()

    def extra_button_clicked(self, field_index):
        '''
        Function called when one of the "extra" buttons is pressed (see
            self.extra_buttons).
        field_index (int): The index of the field.
        '''
        try:
            field_data = self.options_dialog_fields[field_index]
            click_func = self.extra_buttons[field_data.extra_button].click_func
            new_value = click_func(self.get_data_field_index(field_index))
            if new_value is None: return
            self.set_data_field_index(field_index, new_value)

        except Exception as ex:
            str_err_msg = (
                'Failed to set data for field "%s" - %s' %
                (self.options_dialog_fields[field_index].label_text, ex))

            print_msg('Options - %s' % str_err_msg)
            print_traceback()
            mb.showerror(title_options_error, str_err_msg)

    def ok_pressed(self):
        '''
        Callback function, executed when the OK button was pressed.
        Validates the dialog data. If the data is valid, updates the editable
            options of the "Resource Data Manager", sets the dialog_result
            to True and closes the window. If validation fails, the dialog
            remains visible and an appropriate error message is shown.
        '''
        str_err_field = ''

        try:
            # Use a ObjectManager_Options object for strong the values
            #   temporarily. Used for type checking. Also prevents modifying
            #   anything in tree_mgr until the validation is complete.
            opt_temp = ObjectManager_Options()

            for field_index, field_data in enumerate(
                    self.options_dialog_fields):
                str_err_field = ', field "%s"' % field_data.label_text

                opt_temp.add_option(field_data.name, field_data.parser,
                                    self.get_data_field_index(field_index))

            str_err_field = ''  # fixme
            res_data = self.parent.get_res_data_manager()

            for field_data in self.options_dialog_fields:
                # No exception should be raised in this loop unless
                #   there is a mismatch in "parser"

                res_data.set_option(field_data.name,
                                    opt_temp.get_value(field_data.name))

            self.result = True
            self.window.destroy()

        except Exception as ex:
            str_err_msg = 'Failed to set options%s - %s' % (str_err_field, ex)
            print_msg('Options - %s' % str_err_msg)
            print_traceback()
            mb.showerror(title_options_error, str_err_msg)

    def wait_get_result(self):
        '''
         Wait until the dialog is closed and returns a boolean value based on
            the result, True if the OK button was pressed.
        '''
        self.window.wait_window(self.window)
        return self.result
