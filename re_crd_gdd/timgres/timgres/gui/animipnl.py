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

# --- Animation & info panel ---

'''
This module contains the AnimAndInfoPanel class, corresponding to a "panel"
    in the main window. It is used for displaying the image/animation and for
    showing data in a "table" format.
'''

import tkinter as tki
from tkinter import ttk, messagebox as mb
from timgres.base.misc import (print_traceback, tag_sel, tag_dbl,
                               s_opt_anim_enabled, s_opt_backgr_color,
                               s_opt_backgr_color_special)
from timgres.gui.canvimgr import CanvasImageManager, canvas_size_invalid

s_text_tab_anim = 'Image/Animation'
s_text_tab_info = 'File info'
s_text_no_item_selected = '(No item selected)'
s_text_item_sel = '"%s", sub-item "%s"'

def_col_width_0 = 100  # fixme, hardcoded
def_min_width = 20  # fixme, hardcoded

fmt_tree_item = 'i%d'
fmt_col = 'c%d'


class AnimAndInfoPanel(object):
    '''
    This class creates a "panel" that will be shown in the main window.
    The panel consists of a Tab widget with two tabs: one for displaying
        the image or the animation on a canvas, and one showing the
        data in a table format.
    Contains the CanvasImageManager object that creates the images to be shown
        in the canvas. Also contains the callback functions required
        by the widgets.
    '''

    def __init__(self, parent):
        '''
        The constructor of the class. requires one argument.
        parent: The main window (TLevelImgViewerMainWindow)
        '''
        # parent: the main Application class. AnimAndInfoPanel uses the
        #    following methods: get_parent_widget(), get_res_data_manager()
        # TODO: no type check
        self.parent = parent
        self.viewer_data_obj = None
        self.num_into_items = 0
        self.var_sub_item_name = tki.StringVar()
        self.var_sub_item_name.set(s_text_no_item_selected)
        self.tab_widget = None
        self.canvas = None
        self.info_w = None
        self.prev_viewer_obj_id = None
        self.prev_sub_item_num = None
        self.canvas_img_mgr = CanvasImageManager()
        self.create_widgets()
        self.canvas_img_mgr.set_canvas(self.canvas, None)

    def create_widgets(self):
        '''Creates the main frame and the widgets.'''
        parent_widget = self.parent.get_parent_widget()
        # NOTE: tab widget must be created before the frames!
        self.tab_widget = ttk.Notebook(parent_widget)

        self.frame_anim = ttk.Frame(parent_widget)

        self.label_c = ttk.Label(self.frame_anim,
                                 textvariable=self.var_sub_item_name)

        self.label_c.grid(column=0,
                          row=0,
                          columnspan=2,
                          sticky='nsew',
                          padx=3,
                          pady=3)

        self.canvas = tki.Canvas(self.frame_anim,
                                 scrollregion=canvas_size_invalid)
        self.canvas.grid(column=0, row=1, sticky='nsew')

        self.scrollx_c = ttk.Scrollbar(self.frame_anim,
                                       orient=tki.HORIZONTAL,
                                       command=self.canvas.xview)
        self.canvas.configure(xscrollcommand=self.scrollx_c.set)
        self.scrollx_c.grid(column=0, row=2, sticky='ew')
        self.scrolly_c = ttk.Scrollbar(self.frame_anim,
                                       orient=tki.VERTICAL,
                                       command=self.canvas.yview)
        self.canvas.configure(yscrollcommand=self.scrolly_c.set)
        self.scrolly_c.grid(column=1, row=1, sticky='ns')

        self.frame_anim.columnconfigure(0, weight=1)
        self.frame_anim.rowconfigure(1, weight=1)

        self.frame_info = ttk.Frame(parent_widget)

        self.label_i = ttk.Label(self.frame_info,
                                 textvariable=self.var_sub_item_name)
        self.label_i.grid(column=0,
                          row=0,
                          columnspan=2,
                          sticky='nsew',
                          padx=3,
                          pady=3)

        # NO column info by default
        self.info_w = ttk.Treeview(self.frame_info, selectmode='browse')
        self.info_w.grid(column=0, row=1, sticky='nsew')

        self.scrollx_i = ttk.Scrollbar(self.frame_info,
                                       orient=tki.HORIZONTAL,
                                       command=self.info_w.xview)
        self.info_w.configure(xscrollcommand=self.scrollx_i.set)
        self.scrollx_i.grid(column=0, row=2, sticky='ew')

        self.scrolly_i = ttk.Scrollbar(self.frame_info,
                                       orient=tki.VERTICAL,
                                       command=self.info_w.yview)
        self.info_w.configure(yscrollcommand=self.scrolly_i.set)
        self.scrolly_i.grid(column=1, row=1, sticky='ns')
        # TODO: bindings

        self.frame_info.columnconfigure(0, weight=1)
        self.frame_info.rowconfigure(1, weight=1)

        self.tab_widget.add(self.frame_anim, text=s_text_tab_anim)
        self.tab_widget.add(self.frame_info, text=s_text_tab_info)

    def get_tab_widget(self):
        '''Returns the main, tab widget (type: ttk.Notebook).'''
        return self.tab_widget

    def get_canvas(self):
        '''
        Returns the canvas for displaying images and animations.
            (type: tki.Canvas)
        '''
        return self.canvas

    def get_info_widget(self):
        '''
        Returns the widget used for displaying information about a file in
            a table-like form (type: ttk.Treeview)
        '''
        return self.info_w

    def get_current_node_obj(self):
        '''
        Returns the currently selected viewer data object
            (type: ResDataBase_ViewerDataObj) or None if nothing is selected
        '''
        return self.viewer_data_obj

    def sub_item_selected(self, viewer_obj_id, sub_item_num):
        '''
        This function must be called when a viewer object and a sub-item.
        Updates all widgets that are managed by this class (canvas (in part),
            information "table")
        viewer_obj_id (str): the ID of the viewer data object to select
        sub_item_num (int): the number of sub-item in the viewer
            data object to select.
        '''
        try:
            res_data = self.parent.get_res_data_manager()

            if (viewer_obj_id is not None) and (sub_item_num is not None):
                self.viewer_data_obj = res_data.get_viewer_obj_for_selection(
                    viewer_obj_id)
                self.viewer_data_obj.select_sub_item(sub_item_num)

                b_color_special = res_data.get_option(
                    s_opt_backgr_color_special)

                if b_color_special is None:
                    b_color_0 = res_data.get_option(s_opt_backgr_color)
                    b_color = ('#' +
                               b_color_0 if b_color_0 is not None else None)
                else:
                    b_color = b_color_special

                self.canvas_img_mgr.set_background_color(b_color)
                self.canvas_img_mgr.set_animation_enabled(
                    res_data.get_option(s_opt_anim_enabled))
                self.canvas_img_mgr.set_viewer_data_obj(self.viewer_data_obj)

                self.prev_viewer_obj_id = viewer_obj_id
                self.prev_sub_item_num = sub_item_num

                node_descr = self.viewer_data_obj.get_obj_description()
                sub_item_text = self.viewer_data_obj.get_sub_item_texts(
                )[sub_item_num]
                self.var_sub_item_name.set(
                    s_text_item_sel % (node_descr, sub_item_text))
            else:
                self.viewer_data_obj = None
                self.prev_viewer_obj_id = None
                self.prev_sub_item_num = None

                self.canvas_img_mgr.set_background_color(None)
                self.canvas_img_mgr.set_animation_enabled(False)
                self.canvas_img_mgr.set_viewer_data_obj(None)
                self.var_sub_item_name.set(s_text_no_item_selected)

            self.create_info_items()
        except Exception as ex:
            self.viewer_data_obj = None
            self.prev_viewer_obj_id = None
            self.prev_sub_item_num = None
            print_traceback()

            self.canvas_img_mgr.set_background_color(None)
            self.canvas_img_mgr.set_animation_enabled(False)
            self.canvas_img_mgr.set_viewer_data_obj(None)
            self.var_sub_item_name.set(s_text_no_item_selected)
            self.create_info_items()

            mb.showerror('Error - Select sub-item',
                         'Failed to select sub-item - %s' % ex)

    def set_col_width(self, c_index, c_width):
        '''
        Internal use function, for supporting both fixed (c_width negative)
            and sizeable columns (c_width [int] positive) in info widget
            c_width: int, see above
            c_index: int or str, will be passed to Tcl/Tk as col. ID
        '''
        if c_width > 0:
            self.info_w.column(c_index, width=c_width, minwidth=def_min_width)
        else:
            self.info_w.column(c_index, width=-c_width, minwidth=-c_width)

    def update_col_headers(self):
        '''
        "Helper function", called by create_info_items for updating the
            column headers in the information widget (self.info_w).
        '''
        if self.viewer_data_obj is not None:
            col_info = self.viewer_data_obj.get_info_col_headers()
        else:
            col_info = ()

        # TODO, column names?
        # note: len(col_info) - 1 can be negative, but this should be OK
        self.info_w.configure(
            columns=[fmt_col % (x + 1) for x in xrange(len(col_info) - 1)])

        for c_index, (c_text, c_width) in enumerate(col_info[1:]):
            self.info_w.heading(c_index, text=c_text)

            # HACK, allow using negative widths for unstretchable columns
            self.set_col_width(c_index, c_width)

        # Note: nt_info_col_header' has: ('text', 'width')

        if col_info:  # at least 1 item
            c_text_0, c_width_0 = col_info[0]
        else:
            c_text_0 = ''
            c_width_0 = def_col_width_0

        self.info_w.heading('#0', text=c_text_0)
        self.set_col_width('#0', c_width_0)

    def delete_info_items(self):
        '''
        "Helper" function, called by create_info_items,
            clears the self.info_w widget.
        '''
        for cnt in xrange(self.num_into_items):
            self.info_w.delete(fmt_tree_item % cnt)

        self.num_into_items = 0

    def create_info_items(self):
        '''
        "Helper" function, called by sub_item_selected. Updates the
            information widget (self.info_w), both column headers and items
        '''
        self.delete_info_items()
        self.update_col_headers()  # works even if no viewer_data_obj selected

        if self.viewer_data_obj is None: return

        self.num_into_items = 0

        for cnt, info_i in enumerate(self.viewer_data_obj.get_info_entries()):
            self.info_w.insert('',
                               'end',
                               fmt_tree_item % cnt,
                               text=info_i[0],
                               values=info_i[1:],
                               tags=(tag_sel, tag_dbl))
            self.num_into_items += 1

    def update_anim_and_info(self):
        '''
        Forces an update by calling sub_item_selected() with the currently
            selected viewer object ID and selected item index.
        '''
        self.sub_item_selected(self.prev_viewer_obj_id, self.prev_sub_item_num)

    def get_selected_viewer_obj_and_item(self):
        '''
        Returns the selected viewer object ID (str) and the selected item
            index (int) as a tuple (or (None, None) if nothing is selected)
        '''
        return self.prev_viewer_obj_id, self.prev_sub_item_num
