#!/usr/bin/python3
# coding: utf8

# The Incredible Machine (TIM) level/image resource reader, version 0.2
# By knt47, licensed under the Creative Commons Zero license

from __future__ import division, print_function, unicode_literals

import itertools, sys

if sys.version_info[0] != 3:
    izip = itertools.izip
    # an open function accepting an encoding is required
    from io import open as _open_with_encoding

    # https://docs.python.org/2.7/library/csv.html
    #    " If csvfile is a file object, it must be opened with the
    #    ‘b’ flag on platforms where that makes a difference "
    _csv_open_mode = 'wb'
    _open_csv_w = lambda x: open(x, _csv_open_mode)
    _encode_str_list_csv = lambda x: [y.encode('utf8') for y in x]
else:
    izip = zip
    xrange = range

    _open_with_encoding = open

    # https://docs.python.org/3.8/library/csv.html
    # "If csvfile is a file object, it should be opened with newline='' "
    _csv_open_mode = 'w'
    _open_csv_w = lambda x: open(
        x, _csv_open_mode, encoding='utf8', newline='')
    # does nothing
    _encode_str_list_csv = lambda x: x

import csv, fnmatch, os, zipfile

from timgres.base.basecl import ResDataBase_Exporter, nt_export_name_wildcard

from timgres.base.misc import (
    print_msg, print_traceback, file_name_stdout, s_obj_pngexp256,
    s_obj_pngmerge16, s_obj_pngmerge256, s_opt_csv_format,
    s_opt_preserve_pos_size_singleimg, s_opt_export_hide_local,
    s_export_bin_single_file, s_export_bin_all_files, s_export_bin_file_list,
    s_export_bin_file_pattern, s_export_img_single_sub_item,
    s_export_img_sub_items, s_export_img_sub_items_list,
    s_export_img_sub_items_pattern, s_export_text_plainlist_pattern,
    s_export_text_sub_item_names, s_export_text_list_fileinfo,
    s_export_text_sub_item_info, s_res_file_special)

from timgres.base.pngmerge import _BPP_4, _BPP_8, detect_png_format_indexed

from timgres.base.resfile import res_file_id_dir_local_files

# --- "Default" exporters, i.e. subclasses of ResDataBase_Exporter ---

'''
This module contains numerous ResDataBase_Exporter subclasses, allowing
    export in multiple formats: "Unchanged" binary file, PNG image,
    text, CSV, ZIP file containing input from multiple files.
'''

ext_default_png = '*.png'
ext_default_descr_png = 'PNG images'
ext_default_zip = '*.zip'
ext_default_descr_zip = 'ZIP archives'
ext_default_txt = '*.txt'
ext_default_descr_txt = 'Text files'
ext_default_csv = '*.csv'
ext_default_descr_csv = 'CSV files'

str_err_no_res_read_obj = 'no "res_read" object in parent'


def _open_bin_file_or_stdout(f_name):
    '''
    Helper function, either opens a file for writing in a binary mode
        or creates a new file object for stdout, using the same mode.
    Returns a file object.
    f_name (str): The file to open (file_name_stdout, by def. '-') for stdout
    '''
    if f_name == file_name_stdout:
        return os.fdopen(os.dup(sys.stdout.fileno()), 'wb')
    else:
        return open(f_name, 'wb')


def _open_text_file_or_stdout(f_name):
    '''
    Helper function, either opens a file for writing using UTF-8 encoding
        or creates a new file object for stdout, using the default coding.
    Returns a file object.
    f_name (str): The file to open (file_name_stdout, by def. '-') for stdout
    '''
    if f_name == file_name_stdout:
        return os.fdopen(os.dup(sys.stdout.fileno()), 'w')
    else:
        return _open_with_encoding(f_name)


def _open_csv_file_or_stdout(f_name):
    '''
    Helper function, either opens a file in am ode suitable for writing CSV
        files (Format depends on Python version, see comments in defexp,py)
        or creates a new file object for stdout.
    Returns a file object.
    f_name (str): The file to open (file_name_stdout, by def. '-') for stdout
    '''
    if f_name == file_name_stdout:
        return os.fdopen(os.dup(sys.stdout.fileno()), _csv_open_mode)
    else:
        return _open_csv_w(f_name)


def _export_wildcard_match(f_name, wildcard_or_regex):
    '''
    Helper function, for wildcard or RegExp-based matching of file names.
    Returns True if the file name matches the wildcard/RegExp (type: bool)
    f_name (str): Te file name to match
    wildcard_or_regex: The wildcard (type: nt_export_name_wildcard, also
        contains case senistivity information) or RegExp (type: object
        returned by re.compile) to use.
    '''
    if isinstance(wildcard_or_regex, nt_export_name_wildcard):
        if wildcard_or_regex.case_sensitive:
            return fnmatch.fnmatchcase(f_name, wildcard_or_regex.pattern)
        else:
            return fnmatch.fnmatch(f_name, wildcard_or_regex.pattern)
    else:
        return wildcard_or_regex.match(f_name) is not None


class FileListExporterBase(ResDataBase_Exporter):
    '''
    An abstract base class for exporters that allows converting multiple
        resource sub-files, specified by the export arguments. The output
        is saved as a ZIP archive.For conversion, calls the get_export_data
        method (abstract in the parent class). The conversion may yield either
        a single output file or multiple outputs associated with the sub file
        (for example, multiple sub-images from an image file.)
    '''
    export_ext_default = ext_default_zip
    export_ext_default_descr = ext_default_descr_zip

    # self.out_zip_member_ext: extension for files written to the output
    #     zip file. None means keep original extension
    out_zip_member_ext = None

    def reset_data(self):
        '''Re-implementation of reset_data from ResDataBase_Exporter.'''
        ResDataBase_Exporter.reset_data(self)
        # warning_list: List of export warnings.
        self.warning_list = []

    def get_export_data(self, single_f_name):
        '''
        Must be re-implemented in a sub-class.
        In subclasses, the method must return either bytes/bytearray
            (no sub-items) or a list/tuple of bytes objects (this resource
            type has multiple sub-items that need to be saved separately)
            for the file. Must return None on error.
        single_f_name (str): The resource sub-file name.
        '''
        raise NotImplementedError(
            'get_export_data: not implemented in FileListExporterBase')

    def get_file_name_list_sorted(self):
        '''
        Method for internal use. Returns a sorted list of all file names
            obtained from the resource reader object. Filters out "local"
            files depending on the value of s_opt_export_hide_local.
            Returns list of strs.
        '''
        res_read = self.parent.get_res_read_obj()

        if self.parent.get_option(s_opt_export_hide_local):
            return [
                x.sub_f_name for x in res_read.get_file_data_nofilter_sorted()
                if x.res_file_id != res_file_id_dir_local_files
            ]
        else:
            return res_read.get_file_list_nofilter_sorted()

    def get_file_list(self):
        '''
        Returns the list of sub-file names that will be exported, depends on the
            arguments of exporter. (type: list of strs)
        '''
        if self.requires_argument_name_wildcard():
            # TODO, uses the "nofilter" variant, should be limited to the
            #    filtered list in some subclasses

            if self.argument_name_wildcard is None:
                raise RuntimeError('Error, no wildcard/regex was provided.')

            return [
                x for x in self.get_file_name_list_sorted()
                if _export_wildcard_match(x, self.argument_name_wildcard)
            ]
        elif self.requires_argument_file_list():
            if self.argument_file_list is None:
                raise RuntimeError('file list export: no list was provided')

            # assume that the class uses a list (self.argument_file_list)
            # NOTE:, does not check if the file exists
            return self.argument_file_list  # (??) make a copy?

        elif self.requires_argument_file():
            if self.argument_file is None:
                raise RuntimeError('file list export: no file was provided')

            return [self.argument_file]
        else:
            # get full file list, NOTE: always uses the "nofilter" method!
            return self.get_file_name_list_sorted()

    def export_to_file(self, f_name):
        '''
        Re-implementation of export_to_file from ResDataBase_Exporter,
            see the meaning of argument there.
        The output format is a zip file. Uses get_file_list() to obtain
            the file list. The output data is obtained for all files
            using get_export_data.
        '''

        if f_name == file_name_stdout:
            raise RuntimeError('Writing ZIP archives to stdout has not been '
                               'implemented yet.')

        file_list = self.get_file_list()

        if not file_list:
            self.set_warning_msg('Warning, no file selected for export.')
            return

        with zipfile.ZipFile(f_name, 'w',
                             compression=zipfile.ZIP_DEFLATED) as zip_f:
            for sub_f_name in file_list:
                export_data = self.get_export_data(sub_f_name)

                if export_data is None:
                    self.warning_list.append(
                        'File "%s": File skipped due to error' % sub_f_name)

                    print_msg('Zip export: file skipped due to error: %s' %
                              sub_f_name)
                    continue

                # replace s_res_file_special with the "more informative"
                #     ViewerDataObj ID

                if sub_f_name != s_res_file_special:
                    sub_f_name_part, sub_f_ext = os.path.splitext(sub_f_name)
                else:
                    # FIXME, handle the "self.argument_viewer_obj_id is None"
                    #     case, probably not required
                    sub_f_name_part = \
                        self.argument_viewer_obj_id or '_special_'
                    sub_f_ext = ''

                sub_f_ext_out = (self.out_zip_member_ext
                                 if self.out_zip_member_ext is not None else
                                 sub_f_ext)

                if isinstance(export_data, (bytes, bytearray)):
                    zip_f.writestr(sub_f_name_part + sub_f_ext_out,
                                   bytes(export_data))
                else:
                    for item_id, item_data in enumerate(export_data):
                        if item_data is None:
                            self.warning_list.append(
                                ('File "%s", Sub-item %d: Skipped due to '
                                 'error. Export of animations is currently '
                                 'not supported.') % (sub_f_name, item_id))
                            continue

                        zip_f.writestr(
                            '%s-%s/%s-%d%s' %
                            (sub_f_name_part, sub_f_ext.lstrip('.'),
                             sub_f_name_part, item_id, sub_f_ext_out),
                            bytes(item_data))

        if self.warning_list:
            self.set_warning_msg(
                '%d warnings during export:\n%s' %
                (len(self.warning_list), '\n'.join(self.warning_list)))


# ... "Bin": export a(n usually binary) file unchanged, "raw" ...


class BinFileListExporterBase(FileListExporterBase):
    '''
    Base class for exporter sub-classes that can be used for exporting
        resource sub-files unchanged, as a zip archive.
    Re-implements get_export_data
    '''

    def get_export_data(self, single_f_name):
        '''
        Re-implementation of get_export_data from FileListExporterBase.
        See the meaning of the argument there.
        '''
        try:
            res_read = self.parent.get_res_read_obj()
            # always uses get_single_file_data_nofilter not get_single_file_data
            return res_read.get_single_file_data_nofilter(single_f_name)

        except Exception as ex:
            print_msg('Failed to get sub-file "%s" for "raw" zip export: %s' %
                      (single_f_name, ex))
            print_traceback()


class SingleBinFileExporter(ResDataBase_Exporter):
    '''
    A ResDataBase_Exporter subclass that saves a single resource sub-file in
        an unchanged, binary format.
    '''
    # NOTE: SingleBinFileExporter inherits directly from ResDataBase_Exporter,

    exporter_identifier = s_export_bin_single_file
    exporter_description = 'Export single file (raw)'
    arg_required_file = True

    # export_ext_default, export_ext_default_descr NOT used!

    def export_to_file(self, f_name):
        '''
        Re-implementation of export_to_file from ResDataBase_Exporter,
            see the meaning of argument there.
        '''
        if self.argument_file is None:
            raise RuntimeError(
                'SingleBinFileExporter: argument_file must be set')

        # No exception handling
        res_read = self.parent.get_res_read_obj()

        if res_read is None:
            raise RuntimeError(str_err_no_res_read_obj)

        with _open_bin_file_or_stdout(f_name) as out_f:
            # uses get_single_file_data_nofilter, not get_single_file_data
            #    to support any file (command line export)
            out_f.write(
                res_read.get_single_file_data_nofilter(self.argument_file))


class AllBinFilesExporter(BinFileListExporterBase):
    '''
    AllBinFilesExporter: writes all resource files form the resource file
        into a zip archive (unchanged without conversion.)
    '''

    exporter_identifier = s_export_bin_all_files
    exporter_description = 'Export all files (raw)'


class BinFileListExporter(BinFileListExporterBase):
    '''
    BinFileListExporter: Performs "raw" export, accepts a file list as
    argument. Used by the "all resource sub-files" window
        when multiple items are selected. Can be used from command line too.
    '''

    exporter_identifier = s_export_bin_file_list
    exporter_description = 'Export selected files (raw)'
    arg_required_file_list = True
    show_in_gui = False


class BinFilePatternExporter(BinFileListExporterBase):
    '''
    BinFilePatternExporter: export a sub-set of resource sub-files
        by regex/wildcard ("raw" format)
    '''

    exporter_identifier = s_export_bin_file_pattern
    exporter_description = 'Export files by wildcard/regex (raw)'
    arg_required_name_wildcard = True


# ... Image exporters ...


class ExportSingleImageMixin(object):
    '''
    This "mixin" contains a single method, get_export_data_single_image.
        This method requires a viewer object and a sub-item ID, and returns
        the output PNG data (either a single, unchanged image)
    The same code is re-used both in ImageSingleSubItemExporter (writes a
        single image)   and ImageListSubItemsExporterBase (write multiple
        files into a ZIP archive). As it relies heavily on self and
        self.parent, implementing this as a mixin seems to be the more
        "elegant" simulation.
    '''

    def get_export_data_single_image(self, view_data_obj, sub_item_id):
        '''
        Method that can be used for image sub-item exporters. Requires a
            "viewer data object" ID and a sub-item number. Merges all
            sub-images to a single PNG if required. Returns the PNG
            file data to export (type: bytes)
        view_data_obj: The viewer data object" ID
        sub_item_id: The sub-item number.
        '''
        # self.parent.tree_select_sub_file() must be called before this!
        # self.argument_viewer_obj_id is NOT checked here!

        img_list_frame = view_data_obj.get_single_img_frame(sub_item_id)

        if not img_list_frame: return  # returns None!

        preserve_pos_size = self.parent.get_option(
            s_opt_preserve_pos_size_singleimg)

        if (len(img_list_frame) == 1) and (not preserve_pos_size):
            # Contains only one image. unless preserve_pos_size is set,

            # This is an optimization, because PNG merging will be skipped and
            #     the original image data will be returned. Both the position
            #     in img_list_frame[0] and the canvas size in view_data_obj
            #     will be ignored.
            return img_list_frame[0].img_data

        # NOTE: Currently can merge: a) 4 BPP and 8 BPP PNG images
        #     with an identical palette b) 4 BPP and 8 BPP images "mixed"
        #     if the 4 BPP images have a "compatible" palette i.e.
        #     there is a close equivalent for all non-transparent colors

        # At present we choose the merger based on the presence of a
        #     256 color palette (of course this is not the case
        #     when the merging step is skipped, see above)

        if self.parent.get_object(s_obj_pngexp256).has_palette():
            obj_merge = self.parent.get_object(s_obj_pngmerge256)
        else:
            obj_merge = self.parent.get_object(s_obj_pngmerge16)

        c_width, c_height = view_data_obj.get_recommended_canvas_size()
        obj_merge.set_canvas_size(c_width, c_height)

        for sub_img in img_list_frame:
            # TODO, add exception handler per item (?)
            obj_merge.add_image(sub_img)

        obj_merge.finish_processing()  # TODO, TEMPORARY
        out_data = obj_merge.get_png_data()
        obj_merge.reset_data_image()  # TODO

        return out_data


class ImageListSubItemsExporterBase(FileListExporterBase,
                                    ExportSingleImageMixin):
    '''
    The sub-classes of this class are used for exporting image items from
        viewer data objects, as a zip archive. Re-implements get_export_data.
    '''

    arg_required_viewer_obj_id = True
    out_zip_member_ext = ext_default_png.lstrip('*')

    def get_export_data(self, single_f_name):
        '''
        Re-implementation of get_export_data from FileListExporterBase.
        See the meaning of the argument there.
        '''
        if self.argument_viewer_obj_id is None:
            raise RuntimeError('Image export: viewer object ID not specified')

        try:
            self.parent.tree_select_sub_file(single_f_name)

            # TODO, parent.get_viewer_obj_for_selection called too many times
            view_data_obj = self.parent.get_viewer_obj_for_selection(
                self.argument_viewer_obj_id)

            # TODO (??) : Add "inner" exception handler ?
            return [
                self.get_export_data_single_image(view_data_obj, x)
                for x in xrange(view_data_obj.get_sub_item_count())
            ]

        except Exception as ex:
            print_msg('Failed to get export sub-items of image "%s": %s' %
                      (single_f_name, ex))
            print_traceback()
            ## return # returns None


class ImageSingleSubItemExporter(ResDataBase_Exporter, ExportSingleImageMixin):
    '''
    Exporter class for a single sub item in an "viewer data object".
    Requires a file, a viewer data object ID and a sub-item number.
    '''

    export_ext_default = ext_default_png
    export_ext_default_descr = ext_default_descr_png
    exporter_identifier = s_export_img_single_sub_item

    exporter_description = 'Export selected sub-item as PNG'
    arg_required_file = True
    arg_required_viewer_obj_id = True
    arg_required_viewer_sub_item = True

    def export_to_file(self, f_name):
        '''
        Re-implementation of export_to_file from ResDataBase_Exporter,
            see the meaning of argument there.
        '''
        if ((self.argument_file is None)
                or (self.argument_viewer_obj_id is None)
                or (self.argument_viewer_sub_item is None)):
            raise RuntimeError('arguments "file", "viewer_obj_id" and '
                               ' "viewer_sub_item" must be specified')

        # No exception handler !
        self.parent.tree_select_sub_file(self.argument_file)
        view_data_obj = self.parent.get_viewer_obj_for_selection(
            self.argument_viewer_obj_id)
        img_bytes = self.get_export_data_single_image(
            view_data_obj, self.argument_viewer_sub_item)

        # Probably the most common cause of "img_bytes is None" is that
        #     viewer_data.obj.get_single_img_frame fails and returns None
        #     (typically, when it is part of an animation). So this is a
        #     warning until export of animation will be supported (not error!)

        if img_bytes is None:
            self.set_warning_msg(
                ('File "%s", viewer "%s", sub-item "%d" '
                 'cannot be exported. Export of animations is not supported') %
                (self.argument_file, self.argument_viewer_obj_id,
                 self.argument_viewer_sub_item))
            return

        with _open_bin_file_or_stdout(f_name) as out_f:
            # uses get_single_file_data_nofilter, not get_single_file_data
            #    to support any file (command line export)
            out_f.write(img_bytes)


class ImageSubItemsExporter(ImageListSubItemsExporterBase):
    '''
    This class exports all sub-items from a single "viewer data object".
    NOTE: This class inherits FileListExporterBase even if it accepts
        a single file, not a list or a wildcard. The reason for this is
        that an image file may have multiple sub-images that will be
        exported into a zip file.
    '''

    exporter_identifier = s_export_img_sub_items
    exporter_description = 'Export all sub-items fom selected file as ZIP'

    arg_required_file = True
    # arg_required_viewer_obj_id = True # set by parent!


class ImageListSubItemsExporter(ImageListSubItemsExporterBase):
    '''
    This exporter requires a file list and the ID of a "viewer data object"
        Exports all sub-items belonging to all files, into a ZIP file.
    As the GUI does not support such "multi-select"
        this only works from command line
    '''

    exporter_identifier = s_export_img_sub_items_list
    exporter_description = 'Export sub-items as ZIP (list)'
    arg_required_file_list = True
    # arg_required_viewer_obj_id = True # set by parent!
    show_in_gui = False


class ImageFilePatternSubItemsExporter(ImageListSubItemsExporterBase):
    '''
    ImageFilePatternSubItemsExporter: Export all sub-items from an image
        viewer object, repeated for all files specified using
        a wildcard or regexp
    '''

    exporter_identifier = s_export_img_sub_items_pattern
    exporter_description = 'Export sub-items of files by wildcard/regex as ZIP'
    arg_required_name_wildcard = True


# ... "Text" / CSV exporters ...


class PlainNameListPatternExporter(ResDataBase_Exporter):
    '''
    This exporter will not be available from the GUI, designed
        for command-line use. Writes a list of resource sub-file names
        to the output that match a wildcard/regexp.
    '''

    export_ext_default = ext_default_txt
    export_ext_default_descr = ext_default_descr_txt
    exporter_identifier = s_export_text_plainlist_pattern
    exporter_description = 'Export simple file list by wildcard/regex'
    arg_required_name_wildcard = True
    show_in_gui = False

    def export_to_file(self, f_name):
        '''
        Re-implementation of export_to_file from ResDataBase_Exporter,
            see the meaning of argument there.
        '''
        if self.argument_name_wildcard is None:
            raise RuntimeError('PlainNameListPatternExporter: '
                               'arg_required_name_wildcard must be set')

        # No exception handling
        res_read = self.parent.get_res_read_obj()
        wildcard_regexp = self.argument_name_wildcard

        if res_read is None:
            raise RuntimeError(str_err_no_res_read_obj)

        # NOTE: currently uses platform-specific newlines!
        with _open_text_file_or_stdout(f_name) as out_f:
            # uses get_single_file_data_nofilter, not get_single_file_data
            out_f.write('\n'.join(
                x for x in self.get_file_name_list_sorted()
                if _export_wildcard_match(x, wildcard_regexp)))
            # add newline at end
            out_f.write('\n')


class PlainSubItemNameListExporter(ResDataBase_Exporter):
    '''
    This exporter will not be available from the GUI, designed
        for command-line use. Writes the "sub-item texts" of the
        selected viewer to output file/standard output.
    '''

    export_ext_default = ext_default_txt
    export_ext_default_descr = ext_default_descr_txt
    exporter_identifier = s_export_text_sub_item_names
    exporter_description = 'Export sub-item names as text'
    arg_required_file = True
    arg_required_viewer_obj_id = True
    show_in_gui = False

    def export_to_file(self, f_name):
        '''
        Re-implementation of export_to_file from ResDataBase_Exporter,
            see the meaning of argument there.
        '''
        if (self.argument_file is None) or (self.argument_viewer_obj_id is
                                            None):
            # fixme, dupl, FileInfoCsvExporter
            raise RuntimeError('arguments "file" and "viewer_obj_id" '
                               'must be specified')

        self.parent.tree_select_sub_file(self.argument_file)
        view_data_obj = self.parent.get_viewer_obj_for_selection(
            self.argument_viewer_obj_id)

        # platform-specific newlines, like PlainNameListPatternExporter
        with _open_text_file_or_stdout(f_name) as out_f:
            out_f.write('\n'.join(view_data_obj.get_sub_item_texts()))
            # add newline at end
            out_f.write('\n')


class FileInfoCsvExporter(ResDataBase_Exporter):
    '''
    This class exports the basic information about all resource sub-files
        (name, which resource file, size, position) as CSV.
    Writes information about all available sub-files, does not "filter"
        by wildcard/RegExp
    '''
    export_ext_default = ext_default_csv
    export_ext_default_descr = ext_default_descr_csv
    exporter_identifier = s_export_text_list_fileinfo
    exporter_description = 'Export sub-file information as CSV'

    # NOTE: show_in_gui is False because it will not be available in the main
    #      Export menu, but can be accessed from the "all sub-files" window
    show_in_gui = False

    # NOTE: The header row may start with either '!' or '"!' depending on
    #     quoting. If the file is read as plain text, both should be checked

    header_text = [
        '!Sub-file name', 'Resource file ID', 'Start position', 'Size'
    ]

    def export_to_file(self, f_name):
        '''
        Re-implementation of export_to_file from ResDataBase_Exporter,
            see the meaning of argument there.
        '''
        # No exception handling
        res_read = self.parent.get_res_read_obj()

        if res_read is None:
            raise RuntimeError(str_err_no_res_read_obj)

        csv_dialect = self.parent.get_option(s_opt_csv_format)

        with _open_csv_file_or_stdout(f_name) as out_f:
            csv_writer = csv.writer(out_f, dialect=csv_dialect)
            csv_writer.writerow(_encode_str_list_csv(self.header_text))

            # The namedtuple is simply converted to a list. Will contain both
            #      strings and integer numbers

            # TODO: "local" files are not filtered out. However, this is not
            #     absolutely necessary here as such files can be identified
            #     using the 'Resource file ID' column.

            for info_single in res_read.get_file_data_nofilter_sorted():
                csv_writer.writerow(_encode_str_list_csv(info_single))


class ItemInfoCsvExporter(ResDataBase_Exporter):
    '''
    This class writes the sub-item information stored by a ViewerDataObj
        for a specific resource sub-file in CSV format.
    Limitation: currently the data for a single sub-file can be saved
        (no file list/wildcard)
    '''

    export_ext_default = ext_default_csv
    export_ext_default_descr = ext_default_descr_csv
    exporter_identifier = s_export_text_sub_item_info
    # NOTE: this may be confused with "sub-file" info which is
    #     totally different
    exporter_description = 'Export sub-item information as CSV'
    arg_required_file = True
    arg_required_viewer_obj_id = True

    def export_to_file(self, f_name):
        '''
        Re-implementation of export_to_file from ResDataBase_Exporter,
            see the meaning of argument there.
        '''
        if (self.argument_file is None) or (self.argument_viewer_obj_id is
                                            None):
            raise RuntimeError('arguments "file" and "viewer_obj_id" '
                               'must be specified')

        self.parent.tree_select_sub_file(self.argument_file)
        view_data_obj = self.parent.get_viewer_obj_for_selection(
            self.argument_viewer_obj_id)

        csv_dialect = self.parent.get_option(s_opt_csv_format)

        with _open_csv_file_or_stdout(f_name) as out_f:
            csv_writer = csv.writer(out_f, dialect=csv_dialect)

            # Prepend a '!' before the first element
            head_text = [x.text for x in view_data_obj.get_info_col_headers()]

            if head_text:
                head_text[0] = '!' + head_text[0]

            csv_writer.writerow(_encode_str_list_csv(head_text))

            for item_entry in view_data_obj.get_info_entries():
                csv_writer.writerow(_encode_str_list_csv(item_entry))
