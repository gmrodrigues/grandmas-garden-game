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
import zlib

# --- PNG exporter ---

'''
This module provides the SimplePngExporter class, a small PNG exporter
    implementation that supports only the most basic chunk types and no
    "filtering".
'''

# NOTE: There exists a Python module named pypng
#   This library is NOT used here!

png_sign = b'\x89PNG\r\n\x1a\n'
# byte order is big-endian!
png_head_chunk = '>2L5B'


def make_png_chunk(ch_type, ch_data):
    '''
    Function for creating a simple PNG chunk, consisting of: chunk type,
        size, chunk_data, checksum. See PNG specification for more details.
    Returns the PNG chunk as a bytes string.
    ch_type (bytes): the chunk type, see PNG_* constants
    ch_data (bytes or bytearray): The data the chunk will contain.
    '''
    if (not isinstance(ch_type, bytes)) or (len(ch_type) != 4):
        raise ValueError('ch_type: must be bytes with a length of 4')

    if not isinstance(ch_data, (bytes, bytearray)):
        raise TypeError('ch_data: must be bytes or bytearray')

    # byte order is big-endian!
    type_data = ch_type + ch_data

    return bytearray(
        struct.pack('>L', len(ch_data)) + type_data +
        struct.pack('>L',
                    zlib.crc32(type_data) & 0xffffffff))


# PNG chunks
PNG_IHDR = b'IHDR'
PNG_PLTE = b'PLTE'
PNG_tRNS = b'tRNS'
PNG_IDAT = b'IDAT'
PNG_IEND = b'IEND'


# should use namedtuple ?
def make_png_hdr(width, height, bit_depth, color_type):
    '''
    Function for creating the header chunk. Returns the chunk data
        (type: bytes).
    width (int): the width of the image
    height (int): the height of the image
    bit_depth (int): bits per pixel (1, 4, 8, 16)
    color_type (int): see PNG_COL_TYPE_* constants below
    '''
    # compression method, filter method, and interlace method hardcoded to 0 !
    # (for the first two, this is only defined value in the standard)

    return make_png_chunk(
        PNG_IHDR,
        struct.pack(png_head_chunk, width, height, bit_depth, color_type, 0, 0,
                    0))


# PNG specification: https://www.w3.org/TR/PNG

# Color type constants

PNG_COL_TYPE_GRAYSCALE = 0
PNG_COL_TYPE_TRUECOLOR = 2
PNG_COL_TYPE_INDEXED = 3
PNG_COL_TYPE_GRAYSCALE_ALPHA = 4
PNG_COL_TYPE_TRUECOLOR_ALPHA = 6

t_color_types = (PNG_COL_TYPE_GRAYSCALE, PNG_COL_TYPE_TRUECOLOR,
                 PNG_COL_TYPE_INDEXED, PNG_COL_TYPE_GRAYSCALE_ALPHA,
                 PNG_COL_TYPE_TRUECOLOR_ALPHA)

str_err_img_data_present = 'Not possible if image data is already present.'
str_err_info_not_set = 'Image width/height and bit_depth/color_type must be set'

bit_size_shift = {1: 3, 2: 2, 4: 1}
pixel_sizes_truecolor = {
    PNG_COL_TYPE_TRUECOLOR: 3,
    PNG_COL_TYPE_GRAYSCALE_ALPHA: 2,
    PNG_COL_TYPE_TRUECOLOR_ALPHA: 4
}


class SimplePngExporter(object):
    '''
    A basic PNG exporter class that supports only the most important chunks
        in a PNG image. "Header" data must be set using self.set_width_height
        and self.set_bit_depth_color_type. A palette and a transparent color
        can also be set. Lines of the PNG image must be added using
        self.add_line. self.get_png_data generates the PNG output.
    '''

    def __init__(self):
        '''The constructor of the class- Requires no arguments.'''
        self.reset_image()
        self.reset_settings()

    def reset_image(self):
        '''
        Resets the fields containing the output image data.
        '''
        self.img_data = bytearray()
        self.lines = 0

    def reset_settings(self):
        '''
        Resets the fields containing information on the output image
            (width, height, color depth, palette, etc.)
        '''
        # width, height (int): the dimensions of the image.
        self.width = None
        self.height = None
        # bit_depth, color_type (int): Value will be used in PNG header chunk
        #    as "Bit depth" and "Color type" respectively.
        self.bit_depth = None
        self.color_type = None
        # palette (bytes or None): The palette, containing the RGB values or
        #     None if the image format does not require one
        self.palette = None
        # transp_col_bytes (int, tuple of 3 bytes, None): Information about
        #     the transparent color. Type depends on color_type
        #     see also self.set_transp_color
        self.transp_col_bytes = None
        self.line_size = None

    def _update_line_size(self):
        '''
        For internal use. sets self.line size based on bit depth
            and color type.
        '''
        if (self.width is None) or (self.color_type is None):
            self.line_size = None
            return

        # this class was "designed" for indexed-color images!
        if self.color_type in (PNG_COL_TYPE_INDEXED, PNG_COL_TYPE_GRAYSCALE):
            if self.bit_depth in (8, 16):
                # fixme, 16 is not valid for "INDEXED"
                self.line_size = self.width * (self.bit_depth >> 3)
            else:
                # 4-bit: (width + 1) >> 1 ; 2-bit: (width + 3) >> 2
                # 1-bit: (width + 7) >> 3
                self.line_size = ((self.width + 8 // self.bit_depth - 1) >>
                                  (bit_size_shift[self.bit_depth]))

        else:
            # TRUECOLOR, GRAYSCALE_ALPHA, TRUECOLOR_ALPHA
            self.line_size = (self.width * (self.bit_depth >> 3) *
                              pixel_sizes_truecolor[self.color_type])

    def set_width_height(self, new_width, new_height):
        '''
        Sets the width and height for a new image. If the object contains
            data for a "previous" output image in self.img_data, will
            raise RuntimeError.
        new_width (int): the new width
        new_height (int): the new height
        '''
        if (new_width <= 0) or (new_height <= 0):
            raise ValueError('PNG export: width and height must be positive')

        if self.img_data:
            raise RuntimeError(str_err_img_data_present)

        self.width = new_width
        self.height = new_height
        self._update_line_size()

    def set_bit_depth_color_type(self, new_bit_depth, new_color_type):
        '''
        Sets the "bit depth" nad the "color type" information for the image,
            this data will be stored in the PNG header (IHDR) chunk,
        new_bit_depth (int): The bit depth, bits per pixel (1, 4, 8, 16)
        color_type (int): see PNG_COL_TYPE_* constants
        '''
        if new_color_type not in t_color_types:
            raise ValueError('PNG export: Invalid color type.')

        if new_color_type == PNG_COL_TYPE_INDEXED:
            if new_bit_depth not in (1, 2, 4, 8):
                raise ValueError(
                    'color_type 3: allowed bit depths: 1, 2, 4, 8')
        elif new_color_type == PNG_COL_TYPE_GRAYSCALE:
            if new_bit_depth not in (1, 2, 4, 8, 16):
                raise ValueError(
                    'color_type 0: allowed bit depths: 1, 2, 4, 8, 16')
        else:
            if new_bit_depth not in (8, 16):
                raise ValueError('color_type %d: allowed bit depths: 8, 16' %
                                 new_color_type)

        if self.img_data:
            raise RuntimeError(str_err_img_data_present)

        self.bit_depth = new_bit_depth
        self.color_type = new_color_type
        self._update_line_size()

    def set_palette(self, new_pal=None):
        '''
        Sets the palette for the PNG imagw.
        palette: must be a list of (red, green, blue) tuples or
            None (no palette).
        '''
        if new_pal is None:
            self.palette = None
            return

        if self.color_type != PNG_COL_TYPE_INDEXED:
            # actually, the specification allows a PLTE chunk for color types
            # 2 and 6, but recommends an sPLT chunk instead
            # (the palette will contain "suggested" colors)
            raise RuntimeError('PNG export: palette not supported '
                               'for this color type')

        if self.img_data: raise RuntimeError(str_err_img_data_present)

        # TODO TODO: check lengths of RGB tuples
        pal_ba = bytearray(itertools.chain.from_iterable(new_pal))

        if ((len(pal_ba) > ((1 << self.bit_depth) * 3))
                or ((len(pal_ba) % 3) != 0)):
            raise ValueError('PNG export: Invalid palette length')

        self.palette = pal_ba

    def has_palette(self):
        '''
        Returns True if the image has a palette. (type: bool)
        '''
        return self.palette is not None

    def get_palette_raw(self):
        '''
        Intended for "internal" use only. Returns self.palette
            (type: bytes or None).
        '''
        return self.palette  # used by png merge

    def set_transp_color(self, transp_col_info=None):
        '''
        Sets the transparent color information for the image.
        transp_col_info: must be an int or a tuple of 3 ints depending on
            the color type. None means no transparent color
        '''
        if transp_col_info is None:
            self.transp_col_bytes = None
            return

        if self.img_data:
            raise RuntimeError(str_err_img_data_present)

        if self.color_type == PNG_COL_TYPE_INDEXED:
            # PNG_COL_TYPE_INDEXED: transp_col_info must be an int!

            # NOTE: supports only one transparent color !
            # TODO FIXME: range check (number of colors in palette)

            # All but one colors will have an alpha of 255 (not transparent)
            self.transp_col_bytes = b'\xff' * transp_col_info + b'\x00'
        elif self.color_type == PNG_COL_TYPE_TRUECOLOR:
            # transp_col_info: a tuple of 3 ints (R, G, B) (see spec)
            self.transp_col_bytes = struct.pack('>3H', *transp_col_info)
        elif self.color_type == PNG_COL_TYPE_GRAYSCALE:
            # transp_col_info: int (see spec)
            self.transp_col_bytes = struct.pack('>H', transp_col_info)
        else:
            raise RuntimeError('PNG export: transparent color '
                               'cannot be set for this color type')

    def has_transp_color(self):
        '''
        Returns True if the image has a transparent color (type: bool)
        '''
        return self.transp_col_bytes is not None

    def add_line(self, new_line):
        '''
        Adds a new line to the PNG output.
        new_line (bytes or bytearray): The pixel data in the line to add.
            Length is compared with self.line_size and ValueError will be
            raised if the two de not match
        '''
        # IMPORTANT: this class does not support filtering
        #     "filtering" byte will be 0 in all lines !
        if self.line_size is None:
            raise RuntimeError(str_err_info_not_set)

        if len(new_line) != self.line_size:
            raise ValueError('PNG export: Invalid data size')

        self.img_data.append(0)  # filter, hardcoded to 0 (see above)
        self.img_data.extend(new_line)
        self.lines += 1

    def get_png_data(self):
        '''
        Generates the output PNG image data from the image data stored in
            self.img_data as well as the information stored in other fields,
        Returns bytes.
        '''
        if self.line_size is None:
            raise RuntimeError(str_err_info_not_set)

        if self.lines != self.height:
            raise RuntimeError('PNG export: Number of lines does not match '
                               'the specified image height')

        out = bytearray(png_sign)
        out.extend(
            make_png_hdr(self.width, self.height, self.bit_depth,
                         self.color_type))

        if self.palette is not None:
            out.extend(make_png_chunk(PNG_PLTE, self.palette))

        if self.transp_col_bytes is not None:
            out.extend(make_png_chunk(PNG_tRNS, self.transp_col_bytes))

        # the default format (!) for zlib.compress is required
        #   (bytes() required for Python 2.7)   NOTE: zlib.compress()
        #   with the default settings produces exactly the required format!
        out.extend(
            make_png_chunk(PNG_IDAT, zlib.compress(bytes(self.img_data))))

        out.extend(make_png_chunk(PNG_IEND, b''))
        return bytes(out)  # bytes() required for Python 2.7
