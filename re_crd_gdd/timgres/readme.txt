      TIM-TIM 3 level/image resource reader/converter, version 0.2
      ************************************************************

This Python package (named "timgres") is a converter and viewer tool that
supports opening level, image and animation resources found in the The 
Incredible Machine (TIM) game series (from The Incredible Machine to The 
Incredible Machine 3* - the DOS versions, plus the Windows version of TIM 3).
The program can show how the levels look like in the game before the machine
is started and the solution of the puzzles (but see comment on TIM 1 puzzles).
It can also draw PNG images from the levels or their solution. (The program
is not an engine re-creation (yet), the levels are not playable.) Additional
features are: conversion of bitmap files from these games to PNG format, and
viewing animations in a Graphical User Interface. File conversion is also
possible through a Command Line Interface.

It currently requires Python 3.6 or later to run, however, much of the code
is compatible with Python 3.4. Back porting the CLI/converter parts of the
code to Python 2.7 is in progress. The GUI is Tkinter-based and needs
Tcl/Tk 8.6 to run (earlier versions do not support the PNG file format).
It does not depend on any package from PyPI or any other source except
from Tkinter (and the Python standard library). Everything (even the creation
of PNG files) is implemented in "pure Python". The tool should theoretically
run on any platform where Python and Tkinter are available. (The program was
tested on Microsoft Windows 10 and Ubuntu Linux, but not on other
operating systems.)

The "official" Python installers for Windows (from python.org) contain
every dependency of the program. Linux users need to install the "python3-tk"
package using the package manager. (The name may vary between Linux
distributions.)

Two source files, containing important data related to the puzzles and puzzle
parts in the game are not part of the default distribution of this package.
Several features of the program depends on these files. You should read the
'Features that depend on "extra" modules or files extracted from shareware
versions' section before using this level viewer.

The code is licensed under the Creative Commons Zero license
(https://creativecommons.org/publicdomain/zero/1.0/). However there are
two "extra" modules that are not included in the "main" package for
copyright reasons.

(Note: This documentation is a work in progress, some features are 
currently undocumented.)

(* TIM 3: only the demo version was tested extensively.)

Features
========

 * The program can open the resource files of the TIM games 
   (RESOURCE.MAP, RESOURCE.00?, documented at
   http://www.shikadi.net/moddingwiki/TIM_Resource_Format), and read and
   extract files from it. RESOURCE.MAP is the file which needs to be opened.
   Additionally, the program can read files with a supported format from
   a local directory on the computer. At most one local directory and
   the resource files from one game version/installation can be opened at
   the same time. This is required for viewing user-made saved puzzle/machine
   files(File names should be upper case in Unix/Linux/Mac OS
   to avoid problems.)
   
 * Supports opening and viewing level files as well as drawing PNG images 
   from them, for the following versions of the game: TIM demo (DOS), TIM
   (DOS), TEMIM (The Even More Incredible Machine) (DOS), TIM 2 demo (DOS),
   TIM 2 (DOS), TIM 3 demo (Windows), TIM 3 (Windows, not tested extensively).
   The program can also load the user-created puzzles and saved "freeform"
   machines from the supported game versions. The level viewer can show both
   the unsolved puzzle and the solution stored in the same file. Note that
   this is not an engine re-implementation, the machines will not work.

 * Supports decoding bitmap resources (.BMP) that contain the coded pixel
   data in an "SCN:" chunk. The graphics for all puzzle parts in TIM, TEMIM
   and TIM 2 has this format (and also several other image files). This format
   was "reverse engineered" by the author of this program, with additional
   research on the format performed by Nyerguds who posted his results on
   ModdingWiki. The file format is also supported by his
   Engie File Converter software.

 * Supports the animation file format found in TIM 2 and (in at least the
   demo of) TIM 3. A description of this format is provided in the
   fformat.txt file. However, it should be noted that TIM and TEMIM does not
   contain such files. The method used for animations is described in the
   "Extra modules" section.
   
 * Supports ".BMP" and ".SCN" images that contain a "BIN:" and optionally a
   "VGA:" chunk. This format is documented at ModdingWiki
   (http://www.shikadi.net/moddingwiki/RES_Format_(Stellar_7)) and is
   supported by other converter tools. (But see comments in the "Features
   that depend on "extra" modules" section.)
   
 * Thanks to the documentation available at ModdingWiki
   (http://www.shikadi.net/moddingwiki/Dynamix_Font_Format_v4-v5), the
   program has limited support for the font files in the TIM games
   (displaying the graphics for individual characters and optionally saving
   them as PNG)
   
 * Can read palette files and draw images for palettes.
 
 * Has a command line interface for file conversion, documented in a
   separate section.
   
Features that depend on "extra" modules or 
==========================================
    files extracted from shareware versions
===========================================

Note: The extra modules and the extracted, locally stored files are not
present in the CC0 licensed Python package, but are distributed separately.
The extra files must be copied into the "timgres/extra" sub-directory.
The _ROPEEND.BMP

 * Unlike TIM 2/3, TIM and TEMIM do not contain "animation" resource files.
   The information required for animations and puzzle part sprites that
   consist of multiple image sub-items are likely stored in the executable
   file. (However, this has not been reverse engineered yet.) As an
   alternative solution, the required data (i.e. the relative position of
   the sub-images) is provided as an "extra" Python file, t1pinfo.py. 
   Without this file, it is not possible to view levels from TIM and
   The Even More Incredible Machine (TEMIM).
   
   Note: This data was NOT extracted from the game, but manually
   "reconstructed" using a large number of screenshots.
   Instructions for obtaining this files are provided in the "dirinfo.txt"
   file in the "extra" subdirectory.
   
 * There is another "extra" Python file, t2pinfo.py, which contains some
   information about several TIM 2 / 3 puzzle parts. TIM 2 / 3 level viewer
   does work if this file is not present, however, important information will
   be missing about several puzzle parts in the "File info" tab.

 * The original TIM does not have the graphics for "rope ends" ("knot" symbol)
   in any format supported by the game. This small image is probably located
   in the EXE file instead of the archive file. Fortunately, the demo version
   of The Even More Incredible Machine contains the same image in a supported
   format.
   
   See "dirinfo.txt" in the "files" subdirectory for the instructions on
   how to install this file.
   
Notes
=====

 * The solution for the puzzles are not shown by default. This must be
   enabled in the "Options" dialog ("Solution for puzzles"). To enable
   showing puzzle solutions permanently, open the timgres/base/misc.py
   file (of course path separators are "\" on Windows) in a text editor and 
   change the last (non-empty) line to: puzzle_view_debug = True
   Note that in CLI mode, exporting the solutions for puzzles as PNG image
   is enabled by default.
   
 * Often, the "solutions" shown for TIM/TEMIM puzzles are in fact not the 
   correct/perfect solutions. Parts may be in invalid positions, colliding
   with other parts and ropes and belts are very often missing. This is not
   a bug in the program, the level viewer just shows what it present in the
   puzzle file. However, in most cases, these "solutions" still contain 
   important clues on how to solve the puzzle. TIM 2/3 puzzles (nearly)
   always contain the correct solution.  
   
   
Limitations
===========

The current version of the program has the following limitations:

 * The levels are not playable. This is only a level viewer, not a full
   game engine re-implementation.

 * The program has no sound support. (TIM 2/3 animation files can contain
   instructions for playing sound effects.)
   
 * According to the reverse engineering work posted by Nyerguds on
   ModdingWiki, the "BMP:"/"SCN:" file format also has a 8 BPP version.
   This 8 BPP format is not supported yet. However, no known version of
   The Incredible Machine uses this format. (The sprite files in TIM 3,
   which are 8 BPP, use a simple, uncompressed format instead.)
   
 * The "BMP:"/"BIN:" file decoder does not support compression algorithm 3
   (LZHUF). The GNU GPL-licensed source code of Commander Keen Dreams seems
   to contain an implementation of the same algorithm (TODO, this should be
   checked) which could be added in a later version. None of the image files
   in TIM/TEMIM is known to use this algorithm.
   
 * PNG (with indexed colors) is the only supported output format for images.
   
 * Animations cannot be saved/exported, only the animation frames.
 
 * File name hash checking is not implemented in the RESOURCE.MAP reader,
   the program will accept files with invalid values without warning.
 
 * The decoding/conversion of some files may fail due to bugs or
   limitations of the code.
   
 * The implementation of part flipping in the puzzle viewer code contains
   a few kludges, especially for TIM 2 / 3. But at least, it provides
   pixel-accurate results for all puzzle parts I have tested.
   
 * To my knowledge, multiple versions of TIM have been released for old
   Macintosh machines. Such versions are not supported at all. This
   program supports only the DOS versions of the games, as well as TIM 3,
   which is a 32-bit Windows game.
 
Command line arguments
======================

The command line version of the program (can be run using
"python3 tres_cli.py ..." or "python -m timgres ...") supports the
following command line arguments:

-h, --help
    Show help message and exit 
-o, --out
    Output file, type depends on the exporter used**
-r, -–res
    Resource file name (RESOURCE.MAP from the game) 
-d, --dir 
    Directory that contains the resource files 
-f, --file 
    One or more resource sub-files. Required by several exporters. 
-e, --exporter 
    The name of exporter object, see --list-exporters 
-v, --viewer-obj 
    The name of viewer object, required by some exporters,
    see –list-viewers
-i, --item-id
    The sub-item ID for the viewer object, required by some exporters.
    (An integer number.)
-w, --wildcard
    A wildcard for file names, required by some exporters.
    (Or, alternatively, --wildcard-case, --regexp, --regexp-case. "case"
    means case sensitive.) 
-s, --set-opt
    Set option. Format is "-s option=value". 
-V, --verbose
    Print debug information to stderr. 
-g, --gui
    Show GUI***
--list-options
    List available exporter objects and exit. 
--list-exporters
    List available exporter objects and exit. 
--list-viewers
    List available viewer objects and exit. 
--version
    Print version string and exit.


In the GUI part of the program, the support for command line arguments is
much more limited. Only the -V (verbose mode/debug output), -r 
(open RESOURCE.MAP file) and -d (open files from a directory) parameters
are available.

( ** Output files (except .ZIP archives) can be written to the standard
output using "-o -". )

( *** Only relevant when the program is launched as "python -m timgres ...". )

Options, viewer objects and exporters
=====================================

(This is a Work In Progress. Detailed documentation for specific viewer
objects and exporters will be added later.)

The list of available options in the CLI (printed  when the --list-options
    argument is specified):
    
transpcol16                   int_none            None
transpcol256                  int_none            None
zoom                          int                 1
flip                          int                 0
pal_file_def                  str                 TIM.PAL
pal_file_def_2                str                 TIM2.PAL
font_color                    color_none          000000
csv_format                    str                 excel
preserve_pos_size_singleimg   int                 False
no_puzzle_backgr              int                 False
export_hide_local             int                 True
show_solution                 int                 True
raw_part_info                 int                 True


The first column is the name of the option, the second is the type and the
third is the default value. (Option types are defined in
timgres/base/basecl.py)

The "zoom" option can be used for scaling the image. The amount is always
a positive integer numbers, so scaling to e.g. 50% or 150% the original
size is not possible. Scaling is done by simply repeating the pixels, no
filter is applied.

The image can be flipped using the "flip" options. Flipping has relevance
in the game as many parts can be flipped, and typically only one "version"
is found as an image resource. The possible values are: 0=no flip,
1=vertical, 2=horiziontal, 3=verical&horizontal. (Note: TIM2 animation
files use the same numbers.)

The palette used for decoding the image can be set using "pal_file_def"
and "pal_file_def_2". The program can use a 16-color palette for 4BPP
images and a 256 color palette for 8BPP images simultaneously. Note:
if two 16-color palettes are specified, "pal_file_def_2" has "priority".

"font_color" is used in 1BPP fonts.

(Note: transpcol16 and transpcol256 are for internal usage only.)

The GUI part of the program has options not listed above, including
"enable/disable animation", "delay between animation frames" and "canvas
background color". The options can be modified using an Options dialog.

The list of available viewer objects in CLI mode (--list-viewers):

.ANM      *anmframes             ANM animation frames
.BMP      *bmpsubimg             BMP sub-images
.FNT      *fntsymbol             Symbols in FNT font
.GKC      *puzzle_t1             TIM/TEMIM Puzzle
.LEV      *puzzle_t1             TIM/TEMIM Puzzle
.LEV       puzzle_t2             TIM 2/3 Puzzle
.PAL      *palimg                Palette
.SCR      *scrimg                SCR image
.TIM      *puzzle_t1             TIM/TEMIM Puzzle
.TIM       puzzle_t2             TIM 2/3 Puzzle
>special< *_special_anim_frames  Animation frames (TIM/TEMIM), multi-part


The first column contains the file extension of a resource type. 

The name for the viewer object is found in the second column. The asterisk
is not part of the name. It indicates the default viewer for a file
extension. Note that the current version of the program has a limitation:
it cannot determine the default viewer object if a wildcard or a RegExp
is specified instead of a single file name.

">special<" viewers have no connection to a file type. Animations in games
that do not contain animation files (TIM, TEMIM) are implemented using
this "mechanism".

(Note: some viewer objects, especially the animation viewers, are only
available in the GUI part.)

The list of available exporters objects in CLI mode (--list-exporters):

bin_all_files            Export all files (raw) []
bin_file_list            Export selected files (raw) [file-list]
bin_file_pattern         Export files by wildcard/regex (raw) [wildcard]
bin_single_file          Export single file (raw) [file]
img_single_sub_item      Export selected sub-item as PNG [file, viewer-obj, item-id]
img_sub_items            Export all sub-items from selected file as ZIP [file, viewer-obj]
img_sub_items_list       Export sub-items as ZIP (list) [file-list, viewer-obj]
img_sub_items_pattern    Export sub-items of files by wildcard/regex as ZIP [wildcard, viewer-obj]
text_list_fileinfo       Export sub-file information as CSV []
text_list_plain_pattern  Export simple file list by wildcard/regex [wildcard]
text_sub_item_info       Export sub-item information as CSV [file, viewer-obj]
text_sub_item_names      Export sub-item names as text [file, viewer-obj]

The first column is the name/ID of the exporter object. The second column
contains a short description. The required arguments are listed in square
brackets.

 * file: A single resource sub-file must be specified using the -f option.
   The GUI uses the selected file from a list viewer widget.
   
 * file-list: One or more "-f resource_name" arguments are required.
 
 * wildcard: see the -w/--wildcard, --wildcard-case, --regexp,
   --regexp-case command-line argument. The GUI version has a
   "wildcard/RegExp" dialog.
   
 * viewer-obj: The viewer object name (see the -v option). The GUI version
   determines this based on the selection or prompts the user to choose
   one if this is not available (e.g. wildcard input).
 
 * item-id: The sub-item ID for the viewer object. In the GUI, this is
   determined based on the current selection.

(The timgres/base/defexp.py module contains the implementation of
exporter objects.)

Command line usage examples
===========================

python3 tres_cli.py -r /path/to/RESOURCE.MAP -o output_dir/all_files.zip
    -e bin_all_files

  Creates a ZIP archive that contains all sub-files from the RESOURCE.MAP
  file (the original files, no conversion takes place.)


python3 tres_cli.py -r /path/to/RESOURCE.MAP -o output_dir/part50.bmp
    -f PART50.BMP -e bin_single_file

  Extracts a single file (PART50.BMP) from the RESOURCE.MAP file. (No
  conversion takes place.)


python3 tres_cli.py -r /path/to/RESOURCE.MAP -o output_dir/conv_part15.zip
    -e img_sub_items -f PART15.BMP

  Converts all sub-images of PART15.BMP to PNG images, and writes all to a
  single ZIP archive.


python3 tres_cli.py -r /path/to/RESOURCE.MAP -o output_dir/part22_0.png
    -e img_single_sub_item -f PART22.BMP -i 0
    
  Converts sub-image #0 from PART22.BMP to PNG.


python3 tres_cli.py -r /path/to/RESOURCE.MAP -o output_dir/all_bmp.zip
    -e img_sub_items_pattern -v bmpsubimg -w "*.BMP" 

  Converts all sub-images from all BMP files to PNG images, and writes all
  to a single ZIP archive.
  
python3 tres_cli.py -r /path/to/RESOURCE.MAP -o output_dir/easy_levels.zip
    -e img_sub_items_pattern -v puzzle_t2 -w "ELEV*.LEV" -s show_solution=0
    
  Draws all "Easy" levels from TIM 2 or 3 into PNG files, but not their
  solutions. The images will be written to a ZIP file.

File format documentation
=========================

Documentation for three file formats, the TIM level file format, the TIM 2 / 3
ANM format, and the "BMP:"/"SCN:" image compression can be found in the
fformat.txt file in this package. These formats are also documented at
ModdingWiki, links are provided in the fformat.txt file.
    
Version history
===============

22 Jul 2022: Version 0.2. The program is now a level viewer for (the supported
     versions of) the TIM games. 
24 Jan 2021: Version 0.1, the initial release of the program

Acknowledgments
===============

Special thanks to Nyerguds, the author of "Engine File Converter" for
conducting additional research on the Dynamix "BMP:"/"SCN:" file format
and documenting it at ModdingWiki. Link: 

https://moddingwiki.shikadi.net/wiki/The_Incredible_Machine_Image_Format

License
=======

This file is part of TIM level/image resource reader, version 0.2.
Available under the Creative Commons Zero license.
