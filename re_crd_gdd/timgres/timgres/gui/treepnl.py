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
from tkinter import ttk, messagebox as mb
from collections import namedtuple
from timgres.base.misc import (s_res_file_special, print_msg, print_traceback,
                               get_path_shortened, tag_sel, tag_dbl,
                               s_opt_backgr_color_special, s_obj_resreadmap,
                               s_obj_resreaddir)
from timgres.base.resfile import (res_file_id_dir_opened,
                                  res_file_id_dir_local_files)

# --- GUI "panels" (ttk.Frame) for the two "data trees" ---

'''
This module contains two classes, TreePanel_ResSubFiles and
    TreePanel_RSViewerSubItems as well as their common base class
    TreePanelBase. Both classes create a panel shown in the main window.
    The first displays the resource sub-files and the second the items
    handled by the selected. "viewer data object".
'''

# (1. the file types in the resource file and 2. the "sub-item" list)

# nt_tree_id_text: used for storing information about a tree item
#    in a TreePanelBase.
# item_id (str): the ID of the item in the tree viewer widget
# item_text (str): the text that will be shown in widget
nt_tree_id_text = namedtuple('nt_tree_id_text', ('item_id', 'item_text'))

# nt_res_sub_files_open_options: Namedtuple that must be used as the
#     extra_options for TreePanel_ResSubFiles.open_file_get_tree_data
# res_reader_obj: The name of the resource reader object in the
#     res_data_manager object (see also ResDataManager.open_res_file,
#     base/rdatangr.py) (type: str)
# close_others: A boolean value, see meaning at ResDataManager.open_res_file

nt_res_sub_files_open_options = namedtuple(
    'nt_res_sub_files_open_options', ('res_reader_obj_id', 'close_others'))

s_tree_sub_file_special = '(Special items)'

s_text_res_map = 'Resource file'
s_text_res_dir = 'Directory'

s_text_sub_file = 'Sub-file %s'
s_text_no_res_file = '(No resource file loaded)'
s_text_no_sub_file = '(No sub-file selected)'

err_msg_select_format = 'Item selection failed - %s'
err_msg_select_title = 'Error - Item selection'


def res_file_name_add_source_marker(sub_file_info):
    '''
    For internal use. Adds one asterisk at the beginning of the sub-file
        name if the file is from a local directory, or two if a
        "local" file is specified. Returns str.
    sub_file_info: nt_sub_file_info namedtuple (see base/resfile.py)
    '''
    if sub_file_info.res_file_id == res_file_id_dir_opened:
        return '*' + sub_file_info.sub_f_name
    elif sub_file_info.res_file_id == res_file_id_dir_local_files:
        return '**' + sub_file_info.sub_f_name
    else:
        return sub_file_info.sub_f_name


def res_sub_file_opened_panel_text(res_data_mgr):
    '''
    Function for internal use. Returns the text that should be displayed in
        the "panel" above the tree viewer in TreePanel_ResSubFiles.
        The result depend son whether a resource MAP file or a directory
        is opened (or both). Returns str,
    res_data_mgr: The ResDataManager object.
    '''

    f_name_res_read_map = res_data_mgr.get_object(
        s_obj_resreadmap).get_res_f_name()

    if f_name_res_read_map is not None:
        res_sub_file_text_1 = '%s: %s' % (
            s_text_res_map, get_path_shortened(f_name_res_read_map))
    else:
        res_sub_file_text_1 = ''

    f_name_res_read_dir = res_data_mgr.get_object(
        s_obj_resreaddir).get_res_f_name()

    if f_name_res_read_dir is not None:
        res_sub_file_text_2 = '%s%s*%s: %s' % (
            res_sub_file_text_1, '\n' if res_sub_file_text_1 else '',
            s_text_res_dir, get_path_shortened(f_name_res_read_dir))
    else:
        res_sub_file_text_2 = res_sub_file_text_1

    # Return s_text_no_res_file if neither s_obj_resreadmap nor
    #     s_obj_resreaddir has open file/directory
    return res_sub_file_text_2 or s_text_no_res_file


class TreePanelBase(object):
    '''
    "Abstract" base class for classes that create a specific type of panel
        shown in the main window. The main widget of this panel is a Tree
        viewer, suitable for showing items in groups. Contains the callback
        functions for item selection. open_file_get_tree_data (for
        setting the fields containing the tree items) and
        select_item (selection callback) must be re-implemented.
        open_file must be called to create the items for a specific file
            or sub-file.
    '''

    # def_text_name_label: Must be modified in sub-classes.
    #    The label text if no file/sub-file is loaded.
    def_text_name_label = ''
    # col_header_text: Text shown in column header.
    #     Must be modified in sub-classes.
    col_header_text = ''
    # err_open_title. Must be modified in sub-classes.
    #    The title of error message boxes.
    err_open_title = ''
    # err_open_msg_format: must contain two "%s" for formatting:
    #   1. file name, 2. exception text
    err_open_msg_format = ''

    def __init__(self, parent):
        '''
        The constructor of the class. requires one argument.
        parent: The main window (TLevelImgViewerMainWindow)
        '''
        #   TreePanelBase uses one method: get_parent_widget()
        # TODO: no type check
        # parent: the main window.
        self.parent = parent
        # frame (ttk.Frame): the main frame
        self.frame = None  # fixme
        self.reset_data()
        self.var_name = tki.StringVar()
        self.var_name.set(self.def_text_name_label)
        self.create_widgets()

    def reset_data(self):
        '''
        Resets the fields that contain the data showin in "tree" form
            such as the resource sub-files.
        '''
        # top_items: list of nt_tree_id_text namedtuples
        self.top_items = []
        # sub_items: list of lists, elements in inner lists are nt_tree_id_text
        self.sub_items = []

    def create_widgets(self):
        '''Creates the main frame and the widgets.'''
        self.frame = ttk.Frame(self.parent.get_parent_widget())

        self.label = ttk.Label(self.frame, textvariable=self.var_name)
        self.label.grid(column=0,
                        row=0,
                        columnspan=2,
                        sticky='nsew',
                        padx=3,
                        pady=3)

        # currently, has NO columns!
        self.tree = ttk.Treeview(self.frame, selectmode='browse')
        self.tree.heading('#0', text=self.col_header_text)
        # self.tree.heading(col_info, text=col_info_heading)
        self.tree.grid(column=0, row=1, sticky='nsew')

        self.scrollx = ttk.Scrollbar(self.frame,
                                     orient=tki.HORIZONTAL,
                                     command=self.tree.xview)
        self.tree.configure(xscrollcommand=self.scrollx.set)
        self.scrollx.grid(column=0, row=2, sticky='ew')

        self.scrolly = ttk.Scrollbar(self.frame,
                                     orient=tki.VERTICAL,
                                     command=self.tree.yview)
        self.tree.configure(yscrollcommand=self.scrolly.set)
        self.scrolly.grid(column=1, row=1, sticky='ns')

        self.tree.tag_bind(tag_dbl, '<Double-1>', self.ev_item_dbl_clicked)
        self.tree.tag_bind(tag_sel, '<<TreeviewSelect>>', self.ev_tree_select)

        self.frame.rowconfigure(1, weight=1)
        self.frame.columnconfigure(0, weight=1)

    def get_frame(self):
        '''Returns the mian frame (type: ttk.Frame)'''
        return self.frame

    def clear_tree_items(self):
        '''Clears the tree viewer object, deletes all items-'''

        # self.tree.delete() should delete children too
        for item_id, item_text in self.top_items:
            self.tree.delete(item_id)

        self.reset_data()

    def create_tree_items(self):
        '''
        Creates the tree items, using the self.top_items and
            self.sub_items fields.
        '''

        for (top_item_id,
             top_item_text), sub_items_i in izip(self.top_items,
                                                 self.sub_items):
            # NOTE: values= is NOT used!

            self.tree.insert('',
                             'end',
                             top_item_id,
                             text=top_item_text,
                             tags=(tag_sel, tag_dbl))

            for sub_item_id, sub_item_text in sub_items_i:
                self.tree.insert(top_item_id,
                                 'end',
                                 sub_item_id,
                                 text=sub_item_text,
                                 tags=(tag_sel, tag_dbl))

    def open_file(self, new_f_name, extra_options=None):
        '''
        "Main" function for opening a file/sub-file [*] and creating the
            tree items. Calls open_file_get_tree_data, which
            must be re-implemented.
        new_f_name (str): The name of the file. In sub-classes new_f_name can
            be a file or sub-file.
        extra_options: additional options, either None or a sub-class
            specific namedtuple
        '''
        try:
            self.clear_tree_items()

            self.open_file_get_tree_data(new_f_name, extra_options)
            self.create_tree_items()
        except Exception as ex:
            err_msg = self.err_open_msg_format % (new_f_name, ex)

            print_msg(err_msg)
            print_traceback()
            self.var_name.set(self.def_text_name_label)

            mb.showerror(self.err_open_title, err_msg)

    def ev_item_dbl_clicked(self, ev):
        '''
        Callback function, for double click in treeview.
        ev: tkinter event object.
        '''
        sel = self.tree.selection()

        if sel:  # sel[0], multi-selection is not allowed
            try:
                self.item_dbl_clicked(sel[0])
            except Exception as ex:
                err_msg = err_msg_select_format % ex
                print_msg(err_msg)
                print_traceback()
                mb.showerror(err_msg_select_title, err_msg)

    def ev_tree_select(self, ev):
        '''
        Callback function, for item selection in treeview.
        ev: tkinter event object.
        '''
        sel = self.tree.selection()

        if sel:  # sel[0], multi-selection is not allowed
            try:
                self.select_item(sel[0])
            except Exception as ex:
                err_msg = err_msg_select_format % ex
                print_msg(err_msg)
                print_traceback()
                mb.showerror(err_msg_select_title, err_msg)

    def open_file_get_tree_data(self, new_f_name, extra_options=None):
        '''
        Must be re-implemented in a sub-class, an implementation
            must set self.top_items and self.sub_items
        new_f_name (str): class specific, new_f_name can be file or sub-file
        extra_options: additional options, either None or a sub-class
            specific namedtuple
        '''
        pass

    def item_dbl_clicked(self, item_id):
        '''
        May be re-implemented in sub-class. An optional callback called
            when one item was double clicked.
        item_id (str): The item ID in the tree that was selected
        '''
        # (todo, no sub-class implements it)
        pass

    def select_item(self, item_id):
        '''
        Must be re-implemented in sub-class. An implementation must handle
            the item selection in a class specific way for tree item item_id
        item_id (str): The item ID in the tree that was selected
        '''
        pass


class TreePanel_ResSubFiles(TreePanelBase):
    '''
    TreePanelBase subclass, displays the sub-files from
        a resource file, grouped by file extension/file type.
    '''
    # requires 2 "additional" methods from self.parent:
    #   get_res_data_manager and sub_file_selected [callback]

    # NOTE ":" is used as a separator in ids of sub-file nodes
    #   it was chosen because this character is not allowed in DOS file names

    def_text_name_label = s_text_no_res_file
    col_header_text = 'Sub-file name'
    err_open_title = 'Error - Open resource file'
    err_open_msg_format = 'Failed to open resource file "%s": %s'

    def clear_tree_items(self):
        '''Re-implementation of clear_tree_items from parent class.'''
        # HACK, clear items in "sub-items" tree
        TreePanelBase.clear_tree_items(self)
        self.parent.sub_file_selected(None)

    def open_file_get_tree_data(self, new_f_name, extra_options=None):
        '''
        Re-implementation of open_file_get_tree_data from parent class.
        new_f_name (str): Path to the resource file to open.
        extra_options: a nt_res_sub_files_open_options namedtuple
            containing the required extra information
        '''
        if not isinstance(extra_options, nt_res_sub_files_open_options):
            raise TypeError(
                'TreePanel_ResSubFiles.open_file_get_tree_data: '
                'extra_options must be nt_res_sub_files_open_options')

        res_data_mgr = self.parent.get_res_data_manager()
        res_data_mgr.open_res_file(new_f_name, extra_options.res_reader_obj_id,
                                   extra_options.close_others)

        top_items, file_lists = res_data_mgr.get_file_list_by_ext()

        for (f_ext, f_ext_descr), f_data_l in izip(top_items, file_lists):
            ext_prefix = f_ext.lstrip('.')
            self.top_items.append(nt_tree_id_text(ext_prefix, f_ext_descr))

            self.sub_items.append([
                nt_tree_id_text('%s:%s' % (ext_prefix, x.sub_f_name),
                                res_file_name_add_source_marker(x))
                for x in f_data_l
            ])

        # special items
        self.top_items.append(
            nt_tree_id_text(s_res_file_special, s_tree_sub_file_special))
        self.sub_items.append([])

        self.var_name.set(res_sub_file_opened_panel_text(res_data_mgr))

    def select_item(self, item_id):
        '''
        Re-implementation of select_item form parent class,
            Calls the sub_file_selected callback function in parent.
        item_id (str): The Id of selected item.
        '''
        # no type check!
        if item_id == s_res_file_special:
            self.parent.sub_file_selected(s_res_file_special)
            return

        # Currently, does nothing if this is a root node (expect "Special")
        if ':' not in item_id: return

        file_ext_prefix, sub_file_name = item_id.split(':')
        # todo, file_ext_prefix unused
        self.parent.sub_file_selected(sub_file_name)


# RS: resource sub-file


class TreePanel_RSViewerSubItems(TreePanelBase):
    '''
    TreePanelBase subclass, displays the sub-items from
        ResDataBase_ViewerDataObj objects associated with a file type.
    '''
    # requires 2 "additional" methods from self.parent:
    #   get_res_data_manager and sub_item_selected [callback]

    def_text_name_label = s_text_no_sub_file
    col_header_text = 'Viewer sub-item'
    err_open_title = 'Error - Open sub-file'
    err_open_msg_format = 'Failed to open resource sub-file "%s": %s'

    def clear_tree_items(self):
        '''Re-implementation of clear_tree_items from parent class.'''
        TreePanelBase.clear_tree_items(self)
        self.parent.sub_item_selected(None, None)

    def open_file_get_tree_data(self, new_f_name, extra_options=None):
        '''
        Re-implementation of open_file_get_tree_data from parent class.
        new_f_name (str or None): Path to the resource sub-file to open.
        extra_options: additional options, not supported by this class,
            must be None
        '''
        if extra_options is not None:
            raise ValueError('TreePanel_ResSubFiles.open_file_get_tree_data: '
                             'extra_options must be None')

        res_data_mgr = self.parent.get_res_data_manager()

        # s_opt_backgr_color_special: May be modified by the
        #     ViewerDataObj. Set default value here
        res_data_mgr.set_option(s_opt_backgr_color_special, None)

        res_data_mgr.tree_select_sub_file(new_f_name)
        node_info = res_data_mgr.get_viewer_item_info_for_selection()

        for item_id, item_descr in node_info:
            view_obj = res_data_mgr.get_viewer_obj_for_selection(item_id)

            self.top_items.append(nt_tree_id_text(item_id, item_descr))

            self.sub_items.append([
                nt_tree_id_text('%s:%d' % (item_id, x), y)
                for x, y in enumerate(view_obj.get_sub_item_texts())
            ])

        self.var_name.set(s_text_sub_file % new_f_name)

    def select_item(self, item_id):
        '''
        Re-implementation of select_item form parent class,
            Calls the sub_item_selected callback function in parent.
        item_id (str): The Id of selected item.
        '''
        # Currently, does nothing if this is a root node
        if ':' not in item_id: return

        node_obj_id, sub_item_s = item_id.split(':')
        self.parent.sub_item_selected(node_obj_id, int(sub_item_s))
