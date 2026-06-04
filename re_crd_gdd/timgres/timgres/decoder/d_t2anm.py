#!/usr/bin/python3
# coding: utf8

# The Incredible Machine (TIM) level/image resource reader, version 0.2
# By knt47, licensed under the Creative Commons Zero license

from __future__ import division, print_function, unicode_literals

import itertools, sys

if sys.version_info[0] != 3:
    izip = itertools.izip
else:
    izip = zip
    xrange = range

import struct
from collections import namedtuple
from timgres.base.nibblarr import _single_char
from timgres.base.basecl import ResDataBase_Decoder
from timgres.base.misc import print_msg, print_traceback, game_text_encoding

# --- ANM sub-file decoder ---

'''
This module contains the main decoder class for the "TIM 2" (and later)
    animation files (.ANM), SubFileDecoder_Anm_T2. Several namedtuples
    are declared in this module, for storing data extracted from
    the animation file.
'''

# Documentation for this file format is available at:
# https://moddingwiki.shikadi.net/wiki/The_Incredible_Machine_2-3_ANM_File_Format
# Information about this file format can also be found in the fformat.txt
#     file in this package.

# TODO, support for some features of this file format found only in TIM 3
#     is incomplete.

# nt_anm_data: the return type of SubFileDecoder_Anm_T2.grt_data()
# anm_info: a nt_anm_info namedtuple, data from file header
# anm_data_*: Lists. See the corresponding fields in
#     SubFileDecoder_Anm_T2.reset_conv_data
# bmp_names: List of strs. File names from the "TAG:" chunk
nt_anm_data = namedtuple('nt_anm_data',
                         ('anm_info', 'anm_data_a', 'anm_data_b', 'anm_data_c',
                          'anm_data_d', 'bmp_names'))

nt_fields_anm_head = ('anm_magic', 'n_items_a', 'n_items_b', 'n_items_c',
                      'n_items_d', 'width', 'height')

nt_fields_anm_info = ('f_name_part',) + nt_fields_anm_head + \
                     ('size_anm', 'size_tag', 'start_pos_tag')

nt_fields_anm_sect_b_entry = ('pos_x', 'pos_y', 'width', 'height',
                              'offs_sect_d')

# nt_anm_head: Contains data from file header.
# anm_magic (int): a magic number (see magic_nums_anm_head)
# n_items_* (int): Size of each sub-section after the header.
#     the size of one "entry" for each is found in anm_record_len_parts
# width, height (int): A width and a height for the animation (?)
nt_anm_head = namedtuple('nt_anm_head', nt_fields_anm_head)

# nt_anm_info: Contains information about an .ANM file, stored in the
#    nt_anm_data namedtuple. INcludes all fields from nt_anm_head.
# f_name_part (str): Name part of resource sub-file name.
# anm_magic (int): See nt_anm_head
# n_items_* (int): See nt_anm_head
# width, height (int): See nt_anm_head
# size_anm (int): size of the "ANM:" chunk in bytes
# size_tag (int): size of the "TAG:" chunk in bytes
# start_pos_tag (int): start optition of the "TAG:" chunk, in bytes
nt_anm_info = namedtuple('nt_anm_info', nt_fields_anm_info)

# nt_anm_sect_b_entry: Namedtuple corresponding to a section B item.
# pos_x, pos_y (int): The relative position of the (entire) animation frame
#      compared to the first one. Typically zero or a negative value.
# width, height (int): Size of the sub-image, this may change during
#      animation.
# offs_sect_d (int): An offset at which the corresponding data starts in
#     section D. The unit is 16-bit words (2 bytes), not byte.
nt_anm_sect_b_entry = namedtuple('nt_anm_sect_b_entry',
                                 nt_fields_anm_sect_b_entry)

# nt_anm_sect_c_entry: Namedtuple corresponding to a section C item.
# first_frame_id (int) is the index of animation frame at which
#     the animation belonging to a given state of the object begins.
#     If the ANM file has an A section, this must be also taken into
#     account for frame numbers.
# part_state_id (int): Probably, it represents the "state" (such as
#     switched on or off) of a part.

nt_anm_sect_c_entry = namedtuple('nt_anm_sect_c_entry',
                                 ('first_frame_id', 'part_state_id'))

str_rec_type = 'entry_type'

# rec_type_0_1 : Very likely no record type #1 will occur
#     as it is a "terminator" handled in process_section_d

# ... Entry type information ...

# NOTE: all fields of the nt_sect_d_entry_type_* namedtuples are ints.

# Type 0: End of a "sub-section" in section D
#     (corresponding to one entry in sect."B")
#     Fields: 0: entry type (0)

# Type 1: End of entire "D" section
#     Fields: 0: entry type (1)

nt_sect_d_entry_type_0_1 = namedtuple('nt_sect_d_entry_type_0_1',
                                      (str_rec_type))

# Type 2: Draw a sub-image from an image resource
#     Fields: 0: entry type (2)
#     1: The ID of bitmap file in the "TAG:" chunk (numbering starts at 1)
#     2: The sub-image ID (numbering starts at 1!)
#     3: The X position (Position is also affected by the offset in sect. B)
#     4: The Y position (Affected by sect. B, like X)
#     5: Whether the image should be flipped/mirrored (0: no flip,
#         1: flip horizontally, 2: flip vertically, 3: both)

nt_sect_d_entry_type_2 = namedtuple(
    'nt_sect_d_entry_type_2', (str_rec_type, 'bmp_file_id', 'bmp_sub_img_id',
                               'pos_x', 'pos_y', 'img_flip'))

# Type 3: Draw a rectangle
#     Fields: 0: entry type (3)
#     1: X1 position (see comments on the position at entry type 2)
#     2: Y1 position
#     3: Width
#     4: Height
#     5: Border color (0x1-0xf)
#     6: Fill information. The rectangle is filled if the more significant
#         byte is >= 0x80. (Only the value 0x80 is found in files.) The
#         fill color is the less significant byte (0x1-0xf)

nt_sect_d_entry_type_3 = namedtuple('nt_sect_d_entry_type_3',
                                    (str_rec_type, 'pos_x', 'pos_y', 'width',
                                     'height', 'border_color', 'fill'))

# Type 4: Draw line
#     Fields: 0: entry type (4)
#     1: X1 position (see comments on the position at entry type 2)
#     2: Y1 position
#     3: X2 position
#     4: Y2 position
#     5: Line color

nt_sect_d_entry_type_4 = namedtuple(
    'nt_sect_d_entry_type_4',
    (str_rec_type, 'pos_x1', 'pos_y1', 'pos_x2', 'pos_y2', 'line_color'))

# Type 5: Play sound
#     Fields: 0: entry type (5) ; 1: sound information
#     Sound info: The 16-bit value can have two different (?) meanings
#     Values above 3000 correspond to a SX_????.RAW sound resource file
#     All other values are below 256 (?) and are identifiers for sound
#     effects in TIM2.SX file.

nt_sect_d_entry_type_5 = namedtuple('nt_sect_d_entry_type_5',
                                    (str_rec_type, 'sound_info'))

d_nt_sect_d_entry_types = {
    0: (1, nt_sect_d_entry_type_0_1),
    1: (1, nt_sect_d_entry_type_0_1),
    2: (6, nt_sect_d_entry_type_2),
    3: (7, nt_sect_d_entry_type_3),
    4: (6, nt_sect_d_entry_type_4),
    5: (2, nt_sect_d_entry_type_5),
}

# There is a new file format at least in T 3 Demo, with magic number 0x3ea4254
#    In this "new" format, the size of header (including the magic number) is
#    22, the size of a section B items is 12 and can contain an additional
#    "LAB:" (label) chunk

nt_fields_anm_head_ea = (nt_fields_anm_head +
                         ('unknown_16', 'unknown_18', 'unknown_20'))

# nt_anm_head: Contains data from file header.
# See the meaning of the first 7 arguments at nt_anm_sect_b_entry.
# The meaning of the remaining 3 members is not yet known
nt_anm_head_ea = namedtuple('nt_anm_head_ea', nt_fields_anm_head_ea)

# nt_anm_sect_b_entry_ea: Namedtuple corresponding to a section B item.
#      if files with magic number magic_num_anm_head_ea.
# See the meaning of the first five arguments at nt_anm_sect_b_entry.
# The meaning of unknown_10 is unknown.

nt_fields_anm_sect_b_entry_ea = (nt_fields_anm_sect_b_entry + ('unknown_10', ))

nt_anm_sect_b_entry_ea = namedtuple('nt_anm_sect_b_entry_ea',
                                    nt_fields_anm_sect_b_entry_ea)

magic_num_anm_head_ea = 0x3ea4254
magic_num_anm_head_e9 = 0x3e94254
magic_num_anm_head_e8 = 0x3e84254
magic_nums_anm_head = (magic_num_anm_head_ea, magic_num_anm_head_e9,
                       magic_num_anm_head_e8)

anm_record_len_parts = (2, 10, 4, 1)
anm_record_len_parts_ea = (2, 12, 4, 1)

anm_head_size = 16
anm_head_size_ea = 22

chunk_pref_size = 8

sect_b_rec_pos_offs = 8

# File name used for game version check: TIM 2 or TIM 3
t3_check_file_name = 'WTOOLBAR.ANM'


class SubFileDecoder_Anm_T2(ResDataBase_Decoder):
    '''
    Decoder class for the TIM 2 (or later) animation (.ANM) file format.
    '''

    def __init__(self):
        '''The constructor of the class. requires no arguments.'''
        ResDataBase_Decoder.__init__(self)

        self.reset_conv_data()

        self._process_sect_funcs = (self.process_section_a,
                                    self.process_section_b,
                                    self.process_section_c,
                                    self.process_section_d)

        # Separate section process function tuple for files with
        #     magic number magic_num_anm_head_ea

        self._process_sect_funcs_ea = (self.process_section_a,
                                       self.process_section_b_ea,
                                       self.process_section_c,
                                       self.process_section_d)

    def reset_conv_data(self):
        '''Resets the fields that store the data extracted from input.'''
        # out_conv_anm_info: a nt_anm_info namedtuple
        self.out_conv_anm_info = None

        # out_conv_anm_data_a: from sect. A, list of ints
        self.out_conv_anm_data_a = []
        # out_conv_anm_data_b: sect. B, list of nt_anm_sect_b_entry namedtuples
        self.out_conv_anm_data_b = []
        # out_conv_anm_data_c: sect. c, list of nt_anm_sect_._entry namedtuples
        self.out_conv_anm_data_c = []

        # out_conv_anm_data_d: list of lists, each "inner" list corresponds
        #     to one entry in out_conv_anm_data_d, items are one of
        #     namedtuplpes, all n.t. must have an entry_type field
        self.out_conv_anm_data_d = []
        # out_conv_bmp_names: from "TAG:" chunk, list of strings
        self.out_conv_bmp_names = []  # (not always uppercase!)

        # record_len_parts: for internal use, either anm_record_len_parts or
        #     anm_record_len_parts_ea (or None)
        self.record_len_parts = None

    def process_section_a(self, section_data):
        '''
        Processes section A. This section is an optional list of ints.
        section_data (bytes): The data to process.
        '''
        # Contains information about the animation frame IDs that must be
        #     shown for a longer duration (likely)
        self.out_conv_anm_data_a = list(
            struct.unpack('<%dH' % self.out_conv_anm_info.n_items_a,
                          section_data))

    def process_section_b(self, section_data):
        '''
        Processes section B. See the description of nt_anm_sect_b_entry.
        section_data (bytes): The data to process.
        '''
        rec_len = self.record_len_parts[1]

        for s_pos in xrange(0, len(section_data), rec_len):
            # first two fields seem to be signed
            self.out_conv_anm_data_b.append(
                nt_anm_sect_b_entry._make(
                    struct.unpack_from('<2h3H', section_data, s_pos)))

    def process_section_b_ea(self, section_data):
        '''
        Processes section Bin files with magic number magic_num_anm_head_ea.
            See the description of nt_anm_sect_b_entry_ea.
        section_data (bytes): The data to process.
        '''
        rec_len = self.record_len_parts[1]

        for s_pos in xrange(0, len(section_data), rec_len):
            # first two fields seem to be signed
            self.out_conv_anm_data_b.append(
                nt_anm_sect_b_entry_ea._make(
                    struct.unpack_from('<2h4H', section_data, s_pos)))

    def process_section_c(self, section_data):
        '''
        Processes section C. See the description of nt_anm_sect_c_entry.
        section_data (bytes): The data to process.
        '''
        rec_len = self.record_len_parts[2]

        for s_pos in xrange(0, len(section_data), rec_len):
            self.out_conv_anm_data_c.append(
                nt_anm_sect_c_entry._make(
                    struct.unpack_from('<HH', section_data, s_pos)))

    def process_section_d(self, section_data):
        '''
        Processes section D. This section has the same number of sub-sections
            as section B. Each sub-section contains instructions on
            how to draw the frame (image, rectangle, line, etc.)
        section_data (bytes): The data to process.
        '''
        # NOTE: uses data from in process_section_b

        _err_sect_d = ('ANM decode (file "%s.ANM"), section D: ' %
                       self.out_conv_anm_info.f_name_part)

        # (?) can be considered a single command with entry size 0 (->2)
        sect_d_byte_m1 = _single_char(section_data[-1])  # m1: -1
        sect_d_byte_m2 = _single_char(section_data[-2])

        if (sect_d_byte_m2, sect_d_byte_m1) != (1, 0):
            raise RuntimeError(_err_sect_d + 'last 2 bytes must be 0x01 0x00')

        start_pos_sub_sect = [
            db.offs_sect_d * 2 for db in self.out_conv_anm_data_b
        ]

        # MODIFIED: Files may contain overlapping( blocks (PROBABLY NOT)
        # In current implementation, the end position of all sub-sections
        #   is the size of part d - 2, and they will be read until a
        #   terminator is found

        # not multiplied by 2, but last 2 byte removed
        pos_end_sect = self.out_conv_anm_info.n_items_d - 2

        for sub_sect_num, pos_start_i in enumerate(start_pos_sub_sect):
            try:

                self.process_d_sub_section(
                    sub_sect_num, section_data[pos_start_i:pos_end_sect])

            except Exception as ex:
                # Append an empty list as a "placeholder
                self.out_conv_anm_data_d.append([])

                print_msg('Error, %s failed to convert sub_section %d' %
                          (_err_sect_d, sub_sect_num))
                print_traceback()

    def process_d_sub_section(self, sub_section_num, sub_section_data):
        '''
        "Helper" method called by process_section_d. Processes a part of
            a section that is associated with one section B entry.
        sub_section_num (int): The index of the sub-section (0-based index)
        sub_section_data (bytes): The data to process.
        '''
        _err_sub_sect_d = (
            'ANM decode (file "%s.ANM"), section D,'
            'part %d: ' %
            (self.out_conv_anm_info.f_name_part, sub_section_num))

        index = 0
        len_data = len(sub_section_data)
        out_sub_sect = []

        # MODIFIED: Files may contain overlapping(?) blocks
        #   see additional details in process_section_d

        while True:

            # index == (len_data - 1) is also an error, as it would indicate
            #   a start of a new block which consists of only 1 byte
            if index >= (len_data - 1):
                raise RuntimeError(_err_sub_sect_d + 'Index overflow')

            if _single_char(sub_section_data[index + 1]) != 0:
                raise RuntimeError(
                    (_err_sub_sect_d +
                     'Invalid entry type, more significant byte must be 0'))

            entry_type = _single_char(sub_section_data[index])

            if entry_type == 0:  # "terminator"
                self.out_conv_anm_data_d.append(out_sub_sect)
                return

            entry_type_data_0 = d_nt_sect_d_entry_types.get(entry_type)

            if entry_type_data_0 is None:
                raise RuntimeError(
                    '%s Invalid entry type %d' % (_err_sub_sect_d, entry_type))

            size_short, nt_type = entry_type_data_0

            if (index + size_short * 2) > len_data:
                raise RuntimeError(('%s Not enough remaining bytes for entry '
                                    'type %d') % (_err_sub_sect_d, entry_type))

            # All numbers are positive in all files tested,
            #     very likely unsigned.

            out_sub_sect.append(
                nt_type._make(
                    struct.unpack_from('<%dH' % size_short, sub_section_data,
                                       index)))

            index += size_short * 2

    def is_file_type_supported(self, file_data_start):
        '''
        Re-implementation is_file_type_supported from ResDataBase_Decoder.
        See meaning of argument there (base.basecl)
        Detects the presence of the ANM chunk and the magic number.
        '''

        if not isinstance(file_data_start, bytes):
            raise TypeError('file_data_start: must be bytes')

        if file_data_start[:4] != b'ANM:': return False

        head_magic = struct.unpack_from('<L', file_data_start,
                                        chunk_pref_size)[0]

        return head_magic in magic_nums_anm_head

    def process_sub_file(self, f_name_part, file_data, process_options):
        '''
        Re-implements process_sub_file from ResDataBase_Decoder.
        See meaning of arguments there (base.basecl)
        Decodes the "ANM:" header, the "TAG:" chunk, and calls the
            functions responsible for processing each "AMM:" sub-sections
        '''

        self.reset_conv_data()

        _err_decode = 'ANM decode (file "%s.ANM")' % f_name_part

        if process_options is not None:
            raise ValueError(_err_decode +
                             ': process_options: invalid value, must be None')

        if file_data[:4] != b'ANM:':
            raise RuntimeError(_err_decode +
                               ': File must start with "ANM:" chunk')

        size_anm = struct.unpack_from('<L', file_data, 4)[0]

        # FIXME, we need to unpack the magic number twice

        head_magic = struct.unpack_from('<L', file_data, chunk_pref_size)[0]

        if head_magic == magic_num_anm_head_ea:
            head_anm = nt_anm_head_ea._make(
                struct.unpack_from('<L9H', file_data, chunk_pref_size))
            self.record_len_parts = anm_record_len_parts_ea
            process_sect_funcs = self._process_sect_funcs_ea
            anm_chunk_head_size = anm_head_size_ea
            first_file_index = None
            # TODO TEMPORARY
            print_msg('!!! File "%s.ANM", 0x%08u format' %
                      (f_name_part, magic_num_anm_head_ea))
        else:
            head_anm = nt_anm_head._make(
                struct.unpack_from('<L6H', file_data, chunk_pref_size))
            self.record_len_parts = anm_record_len_parts
            process_sect_funcs = self._process_sect_funcs
            anm_chunk_head_size = anm_head_size
            first_file_index = 1

        if head_anm.anm_magic not in magic_nums_anm_head:
            raise RuntimeError('%s: Bad "magic" number in "ANM:" chunk: %08x' %
                               (_err_decode, head_anm.anm_magic))

        size_calc = (
            sum(x * y for x, y in izip(head_anm[1:5], self.record_len_parts)) +
            anm_chunk_head_size)

        if size_calc != size_anm:
            raise RuntimeError(
                '%s: "ANM:" size check failed: %d, expected %d' %
                (_err_decode, size_calc, size_anm))

        start_pos_tag = size_anm + chunk_pref_size

        if file_data[start_pos_tag:start_pos_tag + 4] != b'TAG:':
            raise RuntimeError(_err_decode + ': "TAG:" chunk not found')

        size_tag = struct.unpack_from('<L', file_data, start_pos_tag + 4)[0]

        # HACK, TIM 3 files can contain extra chunk (LAB:) after TAG:
        #     check if this is TIM 3 and if yes, skip check

        end_pos_tag_chunk = start_pos_tag + chunk_pref_size + size_tag

        res_read_obj = self.parent.get_res_read_obj()

        if not res_read_obj.contains_file_nofilter(t3_check_file_name):
            if end_pos_tag_chunk != len(file_data):
                raise RuntimeError(_err_decode + 'File does not end at "TAG:"')

        if (len(file_data) > (end_pos_tag_chunk + 4)):
            if file_data[end_pos_tag_chunk:end_pos_tag_chunk + 4] == b'LAB:':
                print_msg(('File "%s.ANM" contains a "LAB:" chunk, ignored by '
                           'the current decoder.') % f_name_part)
            else:
                raise RuntimeError(_err_decode +
                                   'Invalid data after "TAG:" chunk')

        # IMPORTANT: file names are processed before the sections of "ANM:"
        # TODO, read null-terminated string should be a separate function(?)

        n_bmp_files = struct.unpack_from('<H', file_data,
                                         start_pos_tag + chunk_pref_size)[0]

        pos = start_pos_tag + chunk_pref_size + 2

        for i_file in xrange(n_bmp_files):
            file_id = struct.unpack_from('<H', file_data, pos)[0]

            if first_file_index is not None:
                if (i_file + first_file_index) != file_id:
                    raise RuntimeError(
                        ('%s : Unsupported file numbering, '
                         'expected %d, found %d') %
                        (_err_decode, i_file + first_file_index, file_id))
            else:
                # Hack for files with magic number magic_num_anm_head_ea
                first_file_index = file_id

                if first_file_index > 1:
                    for cnt in xrange(first_file_index - 1):
                        self.out_conv_bmp_names.append('')  # FIXME

            end_pos = file_data.find(b'\x00', pos + 2)

            if end_pos == -1:
                raise RuntimeError(_err_decode +
                                   'End of data reached before \\0 terminator')

            bmp_name = file_data[pos + 2:end_pos].decode(game_text_encoding)
            self.out_conv_bmp_names.append(bmp_name)

            pos = end_pos + 1

        # TODO: Files with magic number magic_num_anm_head_ea can have an
        #     additional "LAB:" chunk. This is currently ignored.

        # Finally, decode sub-sections of "ANM:" chunk
        self.out_conv_anm_info = nt_anm_info._make((f_name_part, ) +
                                                   head_anm[:7] +
                                                   (size_anm, size_tag,
                                                    start_pos_tag))

        pos = anm_chunk_head_size + chunk_pref_size

        for i_part, (n_items_p, r_len, proc_sect_f) in enumerate(
                izip(head_anm[1:5], self.record_len_parts,
                     process_sect_funcs)):
            len_part = n_items_p * r_len
            proc_sect_f(file_data[pos:pos + len_part])
            pos += len_part

    def get_data(self):
        '''
        Re-implements get_data from ResDataBase_Decoder.
        Returns the data as a nt_anm_data namedtuple.
        '''
        # make copies of lists
        return nt_anm_data(self.out_conv_anm_info,
                           list(self.out_conv_anm_data_a),
                           list(self.out_conv_anm_data_b),
                           list(self.out_conv_anm_data_c),
                           list(self.out_conv_anm_data_d),
                           list(self.out_conv_bmp_names))
