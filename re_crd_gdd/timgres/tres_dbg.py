#!/usr/bin/python3
# coding: utf8

# The Incredible Machine (TIM) level/image resource reader, version 0.2
# By knt47, licensed under the Creative Commons Zero license

from __future__ import division, print_function, unicode_literals
import timgres.base.misc as misc

# This must be done before importing anything else (with the exception of
#     a few Python standard library modules, of course)

misc.puzzle_view_debug = True

from timgres.base.misc import set_verbose_mode
from timgres.gui.guimain import gui_main

# Main script for GUI usage. Activates "verbose mode" by default.

if __name__ == '__main__':
    set_verbose_mode(True)
    gui_main()
