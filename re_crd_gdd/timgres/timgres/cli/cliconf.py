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

from timgres.base.misc import s_opt_transpcol16, s_opt_transpcol256, \
    s_opt_zoom, s_opt_flip, s_opt_pal_file_def, s_opt_pal_file_def_2, \
    s_opt_font_color, s_opt_csv_format, s_opt_preserve_pos_size_singleimg, \
    s_opt_no_puzzle_backgr, s_opt_export_hide_local, s_opt_show_solution, \
    s_opt_raw_part_info, \
\
    s_obj_resreadmap, s_obj_resreaddir, s_obj_resreadlocaldir, \
    s_obj_resreadcombined, s_obj_pngexp2, s_obj_pngexp16, s_obj_pngexp256, \
    s_obj_chunkuncompr, s_obj_pngmerge16, s_obj_pngmerge256, \
    s_obj_pngshapedraw16, s_obj_puzzleinfov1, s_obj_puzzleinfov2, \
    s_obj_graphinfov1, s_obj_graphinfov2, s_res_file_special, \
    s_open_res_cback_pal, s_open_res_cback_t1_crc_check, \
    s_open_res_cback_t2_data, s_open_res_cback_temim_store_img, \
 \
    ext_subf_anm, ext_subf_bmp, ext_subf_fnt, ext_subf_pal, \
    ext_subf_scr, ext_subf_gkc, ext_subf_lev, ext_subf_tim, \
    opt_pal_file_def, opt_pal_file_2_def, opt_font_color_def, \
    opt_csv_format_def


from timgres.base.basecl import nt_obj_manager_option, s_opt_type_int, \
    s_opt_type_float, s_opt_type_int_none, s_opt_type_str, \
    s_opt_type_color_none

from timgres.base.rdatamgr import ResDataManager

# * "other" object classes *

from timgres.base.resfile import ResFileReader_Map_T, ResFileReader_Dir, \
    ResFileReader_LocalFilesDir,  ResFileReader_Combined

from timgres.base.dcchunk import ChunkUncompressor

from timgres.base.pngexp import SimplePngExporter, PNG_COL_TYPE_INDEXED
from timgres.base.pngmerge import _BPP_4, _BPP_8, PngMerger_4BPP, PngMerger_8BPP
from timgres.base.pngdraw import PngShapeDraw_4BPP

from timgres.puzzle.puzdata import PuzzleInfo_T1, PuzzleInfo_T2, \
    open_res_callback_t2_data, open_res_callback_temim_store_img

from timgres.puzzle.t1pgraph import PuzzleGraphicsInfo_T1
from timgres.puzzle.t2pgraph import PuzzleGraphicsInfo_T2

# * decoder classes *
from timgres.decoder.d_bmpbin import SubFileDecoder_BmpBin
from timgres.decoder.d_fnt import SubFileDecoder_Fnt_1BPP
from timgres.decoder.d_scr import SubFileDecoder_Scr
from timgres.decoder.d_t12pal import SubFileDecoder_Pal_T12
from timgres.decoder.d_t3pal import SubFileDecoder_Pal_T3
from timgres.decoder.d_t12bmp import SubFileDecoder_Bmp_T12
from timgres.decoder.d_t3bmp import SubFileDecoder_Bmp_T3
from timgres.decoder.d_t2anm import SubFileDecoder_Anm_T2

from timgres.decoder.d_puzzle import SubFileDecoder_Puzzle

# * ViewerDataObj classes *
from timgres.viewdata.vd_bmp import ViewerDataObj_Bmp, \
    ViewerDataObj_Fnt, ViewerDataObj_Scr
from timgres.viewdata.vd_pal import ViewerDataObj_Pal, open_res_callback_pal
from timgres.viewdata.vd_anm import ViewerDataObj_AnmFrames
from timgres.viewdata.vd_sdata import ViewerDataObj_StoredData, \
    open_res_callback_t1_crc_check

# * Puzzle viewer classes *
from timgres.viewdata.vd_puz import ViewerDataObj_Puzzle_T1, \
    ViewerDataObj_Puzzle_T2

# * TIM/TEMIM/TIM 2 "part info" *
try:
    from timgres.extra.t1pinfo import tim_temim_info_checksums, \
        tim_temim_frame_sub_image_pos, tim_temim_part_info, \
        tim_temim_part_appearance_texts, tim_temim_music_info
except ImportError:
    tim_temim_info_checksums = None
    tim_temim_frame_sub_image_pos = None
    tim_temim_part_info = None
    tim_temim_part_appearance_texts = None
    tim_temim_music_info = None

try:
    from timgres.extra.t2pinfo import tim_2_part_appearance_texts
except ImportError:
    tim_2_part_appearance_texts = None

# * exporter classes *

# TODO TODO: add further
from timgres.base.defexp import SingleBinFileExporter, AllBinFilesExporter, \
    BinFileListExporter, BinFilePatternExporter, ImageSingleSubItemExporter, \
    ImageSubItemsExporter, ImageListSubItemsExporter, \
    ImageFilePatternSubItemsExporter, PlainNameListPatternExporter, \
    PlainSubItemNameListExporter, FileInfoCsvExporter, ItemInfoCsvExporter

# --- ResDataManager subclass, "configured" for CLI ---

'''
This module contains the ResDataManager_CliConf class, a sub-class of
    ResDataManager. This class is responsible for the creation of all
    objects, exporters and viewers required for both the CLI and the GUI.
'''

_BPP_1 = 1  # 1 bits per pixel, 2 colors

file_ext_descr_anm = 'Animation files (.ANM)'
file_ext_descr_bmp = 'Bitmap files (.BMP)'
file_ext_descr_fnt = 'Font files (.FNT)'
file_ext_descr_scr = 'Full-screen files (.SCR)'
file_ext_descr_pal = 'Palette files (.PAL)'

file_ext_descr_gkc = 'Title/Credits screen (.GKC)'
file_ext_descr_lev = 'Level (puzzle) files (.LEV)'
file_ext_descr_tim = 'Saved puzzle files (.TIM)'


class ResDataManager_CliConf(ResDataManager):
    '''
    A ResDataManager subclass, used by the CLI part of the program.
        Creates all Resource Manager objects that are used in the CLI
        part of the program, and much of the objects used in the GUI
        version.
    '''

    # NOTE: options_default is empty in parent !
    # options_default = TreeObjectsManager.options_default + \

    options_default = (
        nt_obj_manager_option(s_opt_transpcol16, s_opt_type_int_none, None),
        nt_obj_manager_option(s_opt_transpcol256, s_opt_type_int_none, None),
        nt_obj_manager_option(s_opt_zoom, s_opt_type_int, 1),
        nt_obj_manager_option(s_opt_flip, s_opt_type_int, 0),
        nt_obj_manager_option(s_opt_pal_file_def, s_opt_type_str,
                              opt_pal_file_def),
        nt_obj_manager_option(s_opt_pal_file_def_2, s_opt_type_str,
                              opt_pal_file_2_def),
        # FOXME, font color should not be None, default is black
        nt_obj_manager_option(s_opt_font_color, s_opt_type_color_none,
                              opt_font_color_def),
        nt_obj_manager_option(s_opt_csv_format, s_opt_type_str,
                              opt_csv_format_def),
        nt_obj_manager_option(s_opt_preserve_pos_size_singleimg,
                              s_opt_type_int, False),
        nt_obj_manager_option(s_opt_no_puzzle_backgr, s_opt_type_int, False),
        nt_obj_manager_option(s_opt_export_hide_local, s_opt_type_int, True),
        # NOTE: the following two options are True by default in CLI mode
        #     but False in GUI mode!
        nt_obj_manager_option(s_opt_show_solution, s_opt_type_int, True),
        nt_obj_manager_option(s_opt_raw_part_info, s_opt_type_int, True),
    )

    def create_default_objects_resdata(self):
        '''
        Calls the create_default_objects_resdata method of the parent class.
        Creates all objects that are both accessible in the CLI and the GUI version.
        '''

        # NOTE: create_default_objects_treedata does nothing in parent class
        ResDataManager.create_default_objects_resdata(self)

        # * "other" objects *
        obj_resreadmap = ResFileReader_Map_T()
        self.add_object(s_obj_resreadmap, obj_resreadmap)
        obj_resreaddir = ResFileReader_Dir()
        self.add_object(s_obj_resreaddir, obj_resreaddir)
        obj_resreadlocaldir = ResFileReader_LocalFilesDir()
        self.add_object(s_obj_resreadlocaldir, obj_resreadlocaldir)

        # Get files from local directory
        obj_resreadlocaldir.open_res_file_or_dir(None)

        obj_resreadcombined = ResFileReader_Combined()
        obj_resreadcombined.add_res_reader_object(obj_resreadmap)
        obj_resreadcombined.add_res_reader_object(obj_resreaddir)
        obj_resreadcombined.add_res_reader_object(obj_resreadlocaldir)
        self.add_object(s_obj_resreadcombined, obj_resreadcombined)

        # NOTE: modifies a field in the parent class. Currently, self.res_reader_obj
        #     self.res_reader_obj is always obj_resreadcombined
        self.res_reader_obj = obj_resreadcombined

        obj_pngexp2 = SimplePngExporter()
        obj_pngexp2.set_bit_depth_color_type(_BPP_1, PNG_COL_TYPE_INDEXED)
        self.add_object(s_obj_pngexp2, obj_pngexp2)

        obj_pngexp16 = SimplePngExporter()
        obj_pngexp16.set_bit_depth_color_type(_BPP_4, PNG_COL_TYPE_INDEXED)
        self.add_object(s_obj_pngexp16, obj_pngexp16)

        obj_pngexp256 = SimplePngExporter()
        obj_pngexp256.set_bit_depth_color_type(_BPP_8, PNG_COL_TYPE_INDEXED)
        self.add_object(s_obj_pngexp256, obj_pngexp256)

        self.add_object(s_obj_chunkuncompr, ChunkUncompressor())

        # Note: PNG merger objects are stored in the "object" dict, but
        #     require 'parent' like decoders and exporters.
        #     set_parent() must be called after object creation

        png_merger_4bpp = PngMerger_4BPP()
        png_merger_4bpp.set_parent(self)
        self.add_object(s_obj_pngmerge16, png_merger_4bpp)

        png_merger_8bpp = PngMerger_8BPP()
        png_merger_8bpp.set_parent(self)
        self.add_object(s_obj_pngmerge256, png_merger_8bpp)

        png_shape_draw_4bpp = PngShapeDraw_4BPP()
        png_shape_draw_4bpp.set_parent(self)
        self.add_object(s_obj_pngshapedraw16, png_shape_draw_4bpp)

        puzzle_info_t1 = PuzzleInfo_T1()
        puzzle_info_t1.set_parent(self)
        puzzle_info_t1.set_game_data(tim_temim_part_info, tim_temim_music_info,
                                     tim_temim_frame_sub_image_pos,
                                     tim_temim_info_checksums,
                                     tim_temim_part_appearance_texts)
        self.add_object(s_obj_puzzleinfov1, puzzle_info_t1)

        puzzle_info_t2 = PuzzleInfo_T2()
        puzzle_info_t2.set_parent(self)
        puzzle_info_t2.set_game_data(tim_2_part_appearance_texts)
        self.add_object(s_obj_puzzleinfov2, puzzle_info_t2)

        puzzle_graph_info_t1 = PuzzleGraphicsInfo_T1()
        puzzle_graph_info_t1.set_parent(self)
        self.add_object(s_obj_graphinfov1, puzzle_graph_info_t1)

        puzzle_graph_info_t2 = PuzzleGraphicsInfo_T2()
        puzzle_graph_info_t2.set_parent(self)
        self.add_object(s_obj_graphinfov2, puzzle_graph_info_t2)

        # * file type descriptions *

        self.add_file_ext_descr(ext_subf_anm, file_ext_descr_anm)
        self.add_file_ext_descr(ext_subf_bmp, file_ext_descr_bmp)
        self.add_file_ext_descr(ext_subf_fnt, file_ext_descr_fnt)
        self.add_file_ext_descr(ext_subf_pal, file_ext_descr_pal)
        self.add_file_ext_descr(ext_subf_scr, file_ext_descr_scr)

        self.add_file_ext_descr(ext_subf_gkc, file_ext_descr_gkc)
        self.add_file_ext_descr(ext_subf_lev, file_ext_descr_lev)
        self.add_file_ext_descr(ext_subf_tim, file_ext_descr_tim)

        # * decoder objects *

        # FIXME, has no "name", unlike ViewerDataObj
        #   (but the "name" is not an arg, stored in cl.)
        self.add_decoder(ext_subf_pal, SubFileDecoder_Pal_T12())
        self.add_decoder(ext_subf_pal, SubFileDecoder_Pal_T3())
        self.add_decoder(ext_subf_bmp, SubFileDecoder_Bmp_T12())
        self.add_decoder(ext_subf_bmp, SubFileDecoder_Bmp_T3())
        self.add_decoder(ext_subf_bmp, SubFileDecoder_BmpBin())
        self.add_decoder(ext_subf_anm, SubFileDecoder_Anm_T2())
        self.add_decoder(ext_subf_fnt, SubFileDecoder_Fnt_1BPP())
        self.add_decoder(ext_subf_scr, SubFileDecoder_Scr())

        decoder_puzzle = SubFileDecoder_Puzzle()
        self.add_decoder(ext_subf_gkc, decoder_puzzle)
        self.add_decoder(ext_subf_lev, decoder_puzzle)
        self.add_decoder(ext_subf_tim, decoder_puzzle)

        # TODO TODO: add more

        # * ViewerDataObj objects *

        self.add_viewer_data_obj(ext_subf_pal, ViewerDataObj_Pal())
        self.add_viewer_data_obj(ext_subf_bmp, ViewerDataObj_Bmp())
        self.add_viewer_data_obj(ext_subf_fnt, ViewerDataObj_Fnt())
        self.add_viewer_data_obj(ext_subf_anm, ViewerDataObj_AnmFrames())
        self.add_viewer_data_obj(ext_subf_scr, ViewerDataObj_Scr())

        viewer_stored_data = ViewerDataObj_StoredData()
        viewer_stored_data.set_stored_data(tim_temim_info_checksums,
                                           tim_temim_frame_sub_image_pos)
        self.add_viewer_data_obj(s_res_file_special, viewer_stored_data)

        viewer_puzzle_t1 = ViewerDataObj_Puzzle_T1()
        # Requires the same stored data as viewer_stored_data
        viewer_puzzle_t1.set_stored_data(tim_temim_info_checksums,
                                         tim_temim_frame_sub_image_pos)

        self.add_viewer_data_obj(ext_subf_gkc, viewer_puzzle_t1)
        self.add_viewer_data_obj(ext_subf_lev, viewer_puzzle_t1)
        self.add_viewer_data_obj(ext_subf_tim, viewer_puzzle_t1)

        viewer_puzzle_t2 = ViewerDataObj_Puzzle_T2()
        self.add_viewer_data_obj(ext_subf_lev, viewer_puzzle_t2)
        self.add_viewer_data_obj(ext_subf_tim, viewer_puzzle_t2)

        # TODO TODO: add more

        # * exporter objects *

        self.add_exporter(SingleBinFileExporter())
        self.add_exporter(AllBinFilesExporter())
        self.add_exporter(BinFileListExporter())
        self.add_exporter(BinFilePatternExporter())
        self.add_exporter(ImageSingleSubItemExporter())
        self.add_exporter(ImageSubItemsExporter())
        self.add_exporter(ImageListSubItemsExporter())
        self.add_exporter(ImageFilePatternSubItemsExporter())
        self.add_exporter(PlainNameListPatternExporter())
        self.add_exporter(PlainSubItemNameListExporter())
        self.add_exporter(FileInfoCsvExporter())
        self.add_exporter(ItemInfoCsvExporter())

        # * resource file open callbacks *
        self.add_open_res_callback_func(s_open_res_cback_pal,
                                        open_res_callback_pal)
        self.add_open_res_callback_func(s_open_res_cback_t1_crc_check,
                                        open_res_callback_t1_crc_check)
        self.add_open_res_callback_func(s_open_res_cback_t2_data,
                                        open_res_callback_t2_data)
        self.add_open_res_callback_func(s_open_res_cback_temim_store_img,
                                        open_res_callback_temim_store_img)
