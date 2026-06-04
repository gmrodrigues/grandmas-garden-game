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
from timgres.base.dcunbase import ComprChunkFormatBase, ChunkUncompressorBase

# NOTE, TODO: Add new compression formats here (such  as the unimplemented
#     LZHUF format [format 3]).

# # # try:
# # #     # TODO, not implemented
# # #     from timgres.extra.lzhuf import ComprChunkFormat_LZHUF, compr_f_lzhuf
# # # except ImportError:
# # #     ComprChunkFormat_LZHUF = None
# # #     compr_f_lzhuf = None

# --- "Extra" module, to support D./S. RLE & LZW compression (uncompress) ---

'''
This module contains the decompresor classes of two "chunk formats" in
    Dynamix/Sierra games: ComprChunkFormat_RLE (RLE format, 1) and
    ComprChunkFormat_LZW (LZW format 2). ChunkUncompressor is a subclass of
    ChunkUncompressorBase, adds support for these two algorithms.
'''

# Note: Compression format 3 (LZHUF?) is currently unimplemented!
# (?) The GPL-licensed Commander Keen Dreams source code seems to contain an
#     implementation: https://github.com/keendreams/keen/blob/master/lzhuf.c

# ... Dynamix/Sierra RLE uncompressor ...

# Information about the Dynamix RLE file format (format 1):
# https://moddingwiki.shikadi.net/wiki/RES_Format_(Stellar_7)#BMP:_Image
# https://moddingwiki.shikadi.net/wiki/RLE_Compression
# https://github.com/bluegr/scummvm-dgds/blob/master/scrimage.cpp


class ComprChunkFormat_RLE(ComprChunkFormatBase):
    '''ComprChunkFormatBase subclass, implements the RLE format (1)'''

    def reset_data_sub_class(self):
        '''
        Re-implementation of reset_data_sub_class from ComprChunkFormatBase
        '''
        # bytes_remaining: stores the remaining bytes between two calls
        #     of uncompress_data
        self.bytes_remaining = None

    def uncompress_data(self, data):
        '''
        Re-implementation of uncompress_data from ComprChunkFormatBase
        data (bytes): (part of) the data to decompress
        '''
        # Getting an item of a bytearray should return an int
        #   both in Python 2 and Python 3

        if self.bytes_remaining is None:
            data2 = bytearray(data)
        else:
            data2 = self.bytes_remaining + bytearray(data)
            self.bytes_remaining = None

        d2_len = len(data2)
        index = 0

        while index < d2_len:
            b_ctrl = data2[index]
            index += 1

            if b_ctrl & 0x80:
                if index < d2_len:
                    # IMPORTANT: this differs from the source given above
                    #     tested for RLE-encoded font files and seems to work
                    b_data = data2[index]
                    index += 1
                    self.out_data += bytearray((b_data, )) * (b_ctrl & 0x7f)
                else:
                    self.bytes_remaining = data2[-1:]

                # The code referred to above would correspond to this:
                ## b_len = data2[index] ; index += 1
                ## self.out_dataout += bytearray((b_ctrl & 0x7f,)) * b_len
            else:
                index_end = index + b_ctrl

                if index_end <= d2_len:
                    self.out_data += data2[index:index_end]
                else:
                    self.bytes_remaining = data2[index - 1:]

                index = index_end  # fixme, use break instead in "else:" block?

    def finish_processing(self):
        '''
        Re-implementation of finish_processing from ComprChunkFormatBase
        '''
        # does nothing, only checks bytes_remaining

        if self.bytes_remaining is not None:
            raise RuntimeError('ComprChunkFormat_RLE: format error')


# ... Dynamix/Sierra LZW uncompressor ...

# _bit_len: This is for backwards compatibility
# Documentation: https://docs.python.org/3.8/library/stdtypes.html

if hasattr(int, 'bit_length'):
    _bit_len = lambda x: x.bit_length()
else:
    # Py 2.7 backwards compatibility, slow!
    _bit_len = lambda x: len(bin(x).lstrip('-0b'))

# Information about the Dynamix LZW file format (format 2)
#    (and LZW in general):
# https://github.com/bluegr/scummvm-dgds/blob/master/scrimage.cpp
# https://en.wikipedia.org/wiki/Lempel%E2%80%93Ziv%E2%80%93Welch
# https://rosettacode.org/wiki/LZW_compression
# http://nyerguds.arsaneus-design.com/project_stuff/2018/EngieFileConverter/dev
#    (for implementing [simulating?] caching)


class ComprChunkFormat_LZW(ComprChunkFormatBase):
    '''ComprChunkFormatBase subclass, implements the LZW format (2)'''

    # max_dict_size: Max size of the dictionary (max. code width is 12 bytes)
    max_dict_size = 4096

    def reset_data_sub_class(self):
        '''
        Re-implementation of reset_data_sub_class from ComprChunkFormatBase
        '''
        # bytes_remaining: stores the remaining bytes between two calls
        #     of uncompress_data
        bytes_remaining = None

        # in_data: (part of) the data currently processed
        self.in_data = None
        # bit_len: length of input data, in bits
        self.bit_len = None
        # bit_index: position in input, in bits
        self.bit_index = 0
        # out_data: the decompressed data is "collected" in this array
        self.out_data = bytearray()
        # bits_read: the current code width, in bits.
        self.bits_read = None
        # bit_mask: set in set_bits_read, used for "extracting" the
        #     appropriate number of bits from input.
        self.bit_mask = None
        # dec_dict: the dictionary for decoding, see reset_decode_dict
        self.dec_dict = None
        # cached bits, see EngieFileConverter source (URL above)
        #     (TODO, additional testing needed)
        self.bits_cached = 0

        # store prev_entry between uncompress_data calls
        self.prev_entry = None
        # bytes_remaining: unlike ComprChunkFormat_RLE, always bytearray()
        self.bytes_remaining = bytearray()

        self.reset_decode_dict()

    def set_bits_read(self):
        '''Updates the code size/width in bits.'''
        self.bits_read = _bit_len(len(self.dec_dict))
        self.bit_mask = (1 << self.bits_read) - 1

    def reset_decode_dict(self):
        '''Resets the "dictionary" used for decoding.'''
        # self.dec_dict: actually, a list
        self.dec_dict = [bytes(bytearray((x, ))) for x in xrange(256)]
        self.dec_dict.append(None)  # fixme, special entry
        self.set_bits_read()

    def get_bits(self):
        '''
        Returns the appropriate numbar of bits from in_data.
            Advances the bit index. Returns an int, containing the bits read.
        '''
        # TODO: this code is probably inefficient if self.bits_read
        #    is too low (< 8), but this should never occur

        # This should work in Python 2 (at least if dict size remains below
        #     2 ** 16) and seems to be slightly faster than the alternative
        bi = self.bit_index

        if bi < (self.bit_len - 24):
            # at least 4 bytes available
            bits0 = struct.unpack_from('<L', self.in_data, bi >> 3)[0]
        else:
            bits0 = struct.unpack('<L',
                                  self.in_data[bi >> 3:].ljust(4, b'\x00'))[0]

        bits1 = (bits0 >> (bi & 7)) & self.bit_mask

        self.bit_index += self.bits_read

        return bits1

    def _get_bits_alternative(self):
        '''Alternative implementation of get_bits.'''
        # TODO, unused, requires Python 3.2 +
        # NOTE: this code is probably inefficient if elf.bits_read is too low
        # Slightly slower than the implementation in get_bits()
        #     on Python 3.8/Linux/x86-64 according to tests
        bi = self.bit_index

        out = (int.from_bytes(
            self.in_data[bi >> 3:(bi + self.bits_read + 7) >> 3], 'little') >>
               (bi & 7)) & self.bit_mask

        self.bit_index += self.bits_read

        return out

    def handle_special_entry(self, coded):
        '''
        "Helper" function of special entry:
        Returns False if the entry was actually NOT handled because
            there are not enough bytes in the buffer, otherwise True.
        coded (int): code of the "special entry"
        '''

        if coded == 256:
            # cached bits, see EngieFileConverter source (URL: above)
            #     (TODO: test this on more files)
            ignore_bits = self.bits_read * 8 - self.bits_cached
            index_new = self.bit_index + ignore_bits

            if index_new > (self.bit_len - self.bits_read):
                return False

            self.reset_decode_dict()
            self.bit_index = index_new
            return True
        else:
            raise RuntimeError('LZW: invalid "special" entry: %d ' % coded)

    def uncompress_data(self, data):
        '''
        Re-implementation of uncompress_data from ComprChunkFormatBase
        data (bytes): (part of) the data to decompress
        '''
        self.in_data = self.bytes_remaining + bytearray(data)
        # bit_index should be set previously to the correct value
        self.bit_len = len(self.in_data) << 3

        # preserve prev_entry between uncompress_data() calls
        prev_entry = self.prev_entry

        while self.bit_index <= (self.bit_len - self.bits_read):
            coded = self.get_bits()

            self.bits_cached += self.bits_read

            if self.bits_cached > (self.bits_read * 8):
                self.bits_cached -= self.bits_read * 8

            if coded < len(self.dec_dict):
                entry = self.dec_dict[coded]

                if entry is None:
                    if not self.handle_special_entry(coded):
                        self.bit_index -= self.bits_read
                        break

                    prev_entry = None
                    continue
            else:
                if (coded > len(self.dec_dict)) or (prev_entry is None):
                    raise RuntimeError('BUG: LZW decode, invalid coded data')

                # Note: indexing (not slicing) (prev_entry[...])
                #     returns int in Python 3
                entry = prev_entry + prev_entry[:1]

            self.out_data.extend(entry)

            if (len(self.dec_dict) < self.max_dict_size) \
                    and (prev_entry is not None):
                # entry[:1]: see comment above
                self.dec_dict.append(prev_entry + entry[:1])
                self.bits_cached = 0

                if len(self.dec_dict) < self.max_dict_size:
                    self.set_bits_read()

            prev_entry = entry

        self.prev_entry = prev_entry
        self.bytes_remaining = self.in_data[self.bit_index >> 3:]
        self.bit_index &= 7
        self.in_data = None  # fixme

    def finish_processing(self):
        '''
        Re-implementation of finish_processing from ComprChunkFormatBase.
        '''
        # TODO, check remaining bits (only padding 0 bits should remain)
        pass


# ... "Uncompressor" class supporting the additional formats ...

compr_f_rle = 1
compr_f_lzw = 2


class ChunkUncompressor(ChunkUncompressorBase):
    '''
    ChunkUncompressorBase subclass that adds support for the
        RLE and the LZW formats.
    '''

    def add_formats_subclass(self):
        '''
        Re-implementation of add_formats_subclass from ChunkUncompressorBase.
        '''
        # does not call parent method
        self.add_compr_format(compr_f_rle, ComprChunkFormat_RLE())
        self.add_compr_format(compr_f_lzw, ComprChunkFormat_LZW())

        # # if ComprChunkFormat_LZHUF is not None:
        # #     self.add_compr_format(compr_f_lzhuf, ComprChunkFormat_LZHUF())
