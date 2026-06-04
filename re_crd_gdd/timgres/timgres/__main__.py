#!/usr/bin/python3
# coding: utf8

# The Incredible Machine (TIM) level/image resource reader, version 0.2
# By knt47, licensed under the Creative Commons Zero license

# --- Main source file for "python -m" ---

import sys

# NOTE: For example, argparse support combining the arguments
#    '-V', '-g', and '-r file' as '-Vgr file'. This is not supported,
#    only the -Vg grouping is allowed
# NOTE that his module lacks __future__ imports

if any(x in sys.argv[1:] for x in ('-g', '--gui', '-Vg', '-gV')):
    from timgres.gui.guimain import gui_main

    gui_main()
else:
    from timgres.cli.climain import cli_main

    cli_main()
