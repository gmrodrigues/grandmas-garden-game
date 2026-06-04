# TIM-TIM 3 level/image resource reader/converter ("timgres")

This Python package (named "timgres") is a converter and viewer tool that supports opening level, image and animation resources found in the "The Incredible Machine" (TIM) game series (from The Incredible Machine to The  Incredible Machine 2 (DOS versions only) plus the Windows version of TIM 3). The program can show how the levels look like in the game before the machines started and the solution of the puzzles (but see comment on TIM 1 puzzles in the [readme.txt](/knt47/timgres/src/branch/main/readme.txt) file). It can also draw PNG images from the levels or their solution. (The program is not an engine re-creation (yet), the levels are not playable.) Additional features are: conversion of bitmap files from these games to PNG format, and viewing animations in a Graphical User Interface. File conversion is also possible through a Command Line Interface.

It currently requires Python 3.6 or later to run, however, much of the code is compatible with Python 3.4. Back porting the CLI/converter parts of the code to Python 2.7 is in progress. The GUI is Tkinter-based and needs Tcl/Tk 8.6 to run (earlier versions do not support the PNG file format). It does not depend on any package from PyPI or any other source except from Tkinter (and the Python standard library). Everything (even the creation of PNG files) is implemented in "pure Python". The tool should theoretically run on any platform where Python and Tkinter are available. (The program was tested on Microsoft Windows 10 and Ubuntu Linux, but not on other operating systems.)

The "official" Python installers for Windows (from python.org) contain every dependency of the program. Linux users need to install the "python3-tk" package using the package manager. (The name may vary between Linux distributions.)

Note: Two source files, containing important data related to the puzzles and puzzle parts in the game are not part of the default distribution of this package. Several features of the program depends on these files. See the Installation section of this document for more information.

Note: more detailed documentation is provided for the program in the [readme.txt](/knt47/timgres/src/branch/main/readme.txt) file.

# Installation

Assuming that a supported version of Python is already installed, the first step is simply to extract the ZIP file containing the 0.2C release of the program.

However, there are three files that are missing from this package, and not distributed as part of it due to copyright reasons.

* The **t1pinfo.py** and the **t2pinfo.py** files are made available on the retro video games and computer hardware forum VOGONS under a "fair use" license: [Link](https://www.vogons.org/viewtopic.php?p=1089156#p1089156). The two .py files must be extracted into the timgres/extra subdirectory. These files contain data required for correct drawing of puzzle part sprites in TIM and The Even More Incredible Machine (TEMIM) and information about puzzle parts in TIM 2. See the [readme.txt](/knt47/timgres/src/branch/main/readme.txt) file for more information. (Note: the data contained in these is not from disassembly or decompilation of any game versions, but from careful analysis of many screenshots and resource files (level, image, etc.) from the game. )

* The **_ROPEEND.BMP** file is required for drawing the "knot" graphics at the end of ropes for the "original" TIM. TEMIM and later versions contain this sprite in the same format as the graphics for other parts. However it is not currently known where the original TIM stores this. _ROPEEND_BMP is essentially the same graphics extracted from TEMIM. Please follow the installation instructions in the [timgres/files/dirinfo.txt](/knt47/timgres/src/branch/main/timgres/files/dirinfo.txt) file.
   
The 0.2 release is also available at the [VOGONS forum](https://www.vogons.org/viewtopic.php?p=1089143#p1089143) The VOGONS version is identical to the 0.2C release hare, the only difference is that the README.md file is missing and it does not inclode a full copy of the CC0 license.

# License

The code is licensed under the Creative Commons Zero license (https://creativecommons.org/publicdomain/zero/1.0/). However there are two "extra" modules that are not included in the "main" package. (see above)

Neither screenshots from proprietary video games, nor screenshots from this program showing graphics from these games are provided here. Such screenshots have been posted on the [VOGONS forum](https://www.vogons.org/viewtopic.php?p=1089143#p1089143) where the upload of such images is permitted under a "fair use" license.


Important note: During the development of this program, no version of the game was disassembled or decompiled. All information used for developing this program is from one of the following sources:

* Analysis of resource files extracted from the games using a hex editor or self-written Python scripts.
* Study of self-made level files saved from the built-in level editor.
* Study of a large number of screenshots from the games and comparing them with exported images from timgres for testing.
* Documentations for file formats posted on the Internet.
* Search for strings in the executable file of the program (not used in the final version).
