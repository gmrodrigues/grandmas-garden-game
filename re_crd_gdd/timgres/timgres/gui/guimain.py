#!/usr/bin/python3
# coding: utf8

# The Incredible Machine (TIM) level/image resource reader, version 0.2
# By knt47, licensed under the Creative Commons Zero license

from __future__ import division, print_function
import os, sys

if sys.version_info[0] < 3:
    raise NotImplementedError('Only Python3 is supported!')
else:
    xrange = range
    izip = zip

import argparse
from base64 import b64decode
# import _config

import tkinter as tki
from tkinter import ttk, messagebox as mb

from timgres.gui.mainwnd import TLevelImgViewerMainWindow
from timgres.base.misc import (set_verbose_mode, print_msg, print_traceback,
                               s_obj_resreadmap, s_obj_resreaddir)

# --- main module for GUI app ---

'''Module that contains the GUI main function, gui_main.'''


def check_tk_png_support():
    '''
    Tests if tkinter.PhotoImage can accept indexed color PNG images.
    '''
    # A tiny, indexed-color PNG file, base64 encoded
    test_png_b64 = (
        'iVBORw0KGgoAAAANSUhEUgAAAAYAAAAEBAMAAABfKlNwAAAAElBMVEX/AAAA/'
        'wAAAP8A////AP///wAMmNgyAAAAE0lEQVR4nGMIFTRmAGElFwYQBgASIAH/Lj'
        '/W8QAAAABJRU5ErkJggg==')

    try:
        test_image = tki.PhotoImage(data=b64decode(test_png_b64))
    except Exception:  # todo, TclError?
        print_msg('*Error*, installed Tcl/Tk version has no PNG support')
        print_traceback()
        return False
    else:
        return True


def gui_main():
    '''
    Main function for the GUI part of the program. Initializes Tkinter.
    Performs argument parsing like climain.cli_main, but significantly
        fewer arguments are supported.
    '''
    parser = argparse.ArgumentParser()

    # FIXME, Partial code duplication from climain
    # Modification: -r/--res and -d/--dir are no longer mutually exclusive

    parser.add_argument(
        '-r',
        '--res',
        help='Optional. Resource file name (RESOURCE.MAP from the game)')

    parser.add_argument(
        '-d',
        '--dir',
        help='Optional. Directory that contains the resource files')

    parser.add_argument('-V',
                        '--verbose',
                        action='store_true',
                        help='Print debug information to stderr.')

    parser.add_argument(
        '-g',
        '--gui',
        action='store_true',
        help=('Show GUI. If the program is launched as "python tres_gui.py", '
              'the GUI will be shown regardless of this option.'))

    args = parser.parse_args()

    if args.verbose:
        set_verbose_mode(True)

    root = tki.Tk()
    # disable "tear off menus" feature
    root.option_add('*tearOff', 0)

    if not check_tk_png_support():
        mb.showerror(
            ('Unsupported Tcl/Tk version',
             'This program requires a Tcl/Tk version with PNG support (8.6).'
             '\nThe version currently installed: )%.1f ' % tki.TkVersion))

        return

    main_win = TLevelImgViewerMainWindow(root)
    main_win.get_parent_widget().grid(column=0, row=0, sticky='nsew')

    if args.res is not None:
        main_win.open_resources(args.res, s_obj_resreadmap, False)

    if args.dir is not None:
        main_win.open_resources(args.dir, s_obj_resreaddir, False)

    root.rowconfigure(0, weight=1)
    root.columnconfigure(0, weight=1)

    root.mainloop()
