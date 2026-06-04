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

# --- Base classes for chunk uncompress in D. (S.) games ---

'''
This module contains the base class ChunkUncompressorBase, for the
    decompression of a very common chunk format in the D./S. games.
    These chunks can have multiple compression formats, the base class
    implements only the "uncompressed" format in ComprChunkFormatBase.
Additional formats can be added in other modules by subclassing
    ComprChunkFormatBase and ChunkUncompressorBase.
'''

# These classes are intended for decompression of chunks containing a
#   specific, small header (compression algorithm 1 byte, uncompr. size 4 byte)
#   (this can also be part/ending of a larger header)

# Note: Several types of "chunks" do not follow this format. Most importantly,
#    the decoder for the "SCN:" chunk containing bitmaps is found in
#    p_t12bmp.py (The p_t12bmp module does not use any class from this file)

import struct


class ComprChunkFormatBase(object):
    '''
    Base class for decompressor objects supporting a specific compression
        format used in the games. This base class is used for format 0
        (uncompressed data). uncompress_data, finish_processing and
        (optionally) reset_data_sub_class must be re-implemented in
        sub-classes to support compressed formats-
    '''

    def __init__(self):
        '''Constructor of the class. Has no arguments.'''
        self.reset()

    def __len__(self):
        '''Returns the length of uncompressed data (int).'''
        return len(self.out_data)

    def reset(self):
        '''Resets output data and calls reset_data_sub_class'''
        # out_data (bytes): The output data, already decompressed.
        self.out_data = bytearray()
        self.reset_data_sub_class()

    def reset_data_sub_class(self):
        '''
         May be re-implemented in sub-classes (to define additional fields)
        '''
        pass

    def uncompress_data(self, data):
        '''
        Must be re-implemented in sub-classes to support a
            compressed file format.
        data (bytes): (part of) the data to decompress
        '''
        self.out_data += data

    def finish_processing(self):
        '''
        When be-re-implemented in a sub-class, performs some task after the
        last part of data was processed. By default, does nothing.
        '''
        pass
        # calling this method twice should not be an error

    def get_data(self):
        '''Method for retrieving the uncompressed data (type: bytes)'''
        return bytes(self.out_data)


# ComprChunkFormatBase is used for the uncompressed format
ComprChunkFormat_Uncompressed = ComprChunkFormatBase

str_err_start_uncompr = 'Uncompress chunk: '
str_err_no_format = str_err_start_uncompr + 'Chunk data must be set first'

compr_f_uncompr = 0


class ChunkUncompressorBase(object):
    '''
    Base class for uncompressing "chunks" found in many resource files
        in D. games. Can support multiple compression algorithms, all
        having an integer number. Decoders are added using the
        add_compr_format function that must be called from
        add_formats_subclass. Base class only supports the "uncompressed"
        format. Data can be decompressed using the process_data method and
        the result can be obtained with get_data. Supports a mechanism for
        uncompressing in multiple parts.
    '''

    def __init__(self):
        '''The constructor of the class, has no arguments.'''
        # compr_formats: dict that stores one object per supported
        #    compressed format. key: identifier (int), value: the
        #    "uncompress" object (type: ComprChunkFormatBase subclass)
        self.compr_formats = {}
        # format_current (int or None): the format of the data currently
        #    decoded or None
        self.format_current = None
        # size_unpacked (int or None): the expected size, stored in
        #     chunk header.
        self.size_unpacked = None
        self.add_formats()

    def reset_format_obj(self):
        '''
        Resets the fields associated with the uncompressed data and
            "uncompress" class
        '''
        if self.format_current is not None:
            self.format_current.reset()
            self.format_current = None
            self.size_unpacked = None

    def add_compr_format(self, new_id, new_format_obj):
        '''
        Adds a "decompressor" object for a comression format.
        new_id (int): A number associated with the format (one byte)
        new_format_obj (ComprChunkFormatBase subclass): the object to add.
        '''
        if not isinstance(new_id, int):
            raise TypeError('new_id: must be int')

        if (new_id < 0) or (new_id > 255):  # one byte!
            raise ValueError(
                'new_id: out of range, must be 0 <= new_id <= 255')

        if not isinstance(new_format_obj, ComprChunkFormatBase):
            raise TypeError(
                'new_format_obj must be a ComprChunkFormatBase subclass')

        self.compr_formats[new_id] = new_format_obj

    def add_formats(self):
        '''
        Adds the object for the default formats (in current ver. only the
            "uncompressed format")
        Calls add_formats_subclass.
        '''
        self.add_compr_format(compr_f_uncompr, ComprChunkFormat_Uncompressed())
        self.add_formats_subclass()

    def add_formats_subclass(self):
        '''
        Must be re-implemented in a sub-class to add formats using
            add_compr_format.
        '''
        pass

    def uncompress_data(self, data):
        '''
        Calls the uncompress_data() method in the object associated with
            the compression format of the decoded data.
        data (bytes): The binary data to uncompress.
        '''
        if self.format_current is None:
            raise RuntimeError(str_err_no_format)

        self.format_current.uncompress_data(data)

    def finish_processing(self):
        '''
        Calls the finish_processing() method in the object associated with
            the compression format of the decoded data.
        '''
        if self.format_current is None:
            raise RuntimeError(str_err_no_format)

        self.format_current.finish_processing()

    def process_data(self, data, finish=True):
        '''
        Method that chooses the "decompressor" object based on the chunk
            header and uses it for processing the data.
            Has support for decoding data in multiple parts (finish=False)
        data (bytes): The binary data to uncompress.
        finish (bool): If true, calls finish_processing. Must be False if
            data is just the first part (further parts must be passed to
            uncompress_data() and finish_processing() must be called)
        '''
        # NOTE: It is possible to uncompress the data in more than one part.
        #    process_data must be called first with finish=False, followed by
        #    one or more uncompress_data calls, and finally finish_processing
        # NOTE: the 5-byte header must be in first part (process_data())
        self.reset_format_obj()

        num_algorithm, self.size_unpacked = struct.unpack_from('<BL', data)

        self.format_current = self.compr_formats.get(num_algorithm)

        if self.format_current is None:
            self.size_unpacked = None
            raise RuntimeError(str_err_start_uncompr +
                               'Unsupported compression format (%d)' %
                               num_algorithm)

        self.format_current.uncompress_data(data[5:])

        if finish:
            self.format_current.finish_processing()

    def get_data(self):
        '''Method for retrieving the uncompressed data (bytes).'''

        if self.format_current is None:
            raise RuntimeError(str_err_no_format)

        if len(self.format_current) != self.size_unpacked:
            raise RuntimeError(str_err_start_uncompr + (
                'Uncompressed size (%d) does not match header (%d)' %
                (len(self.format_current), self.size_unpacked)))

        return self.format_current.get_data()
