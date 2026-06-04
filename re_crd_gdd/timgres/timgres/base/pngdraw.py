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

# --- Class for drawing simple shapes to 4BPP PNG images ---

from timgres.base.basecl import ResDataItemBase
from timgres.base.nibblarr import NibbleArrayMSF

from timgres.base.misc import (s_obj_pngexp16, s_opt_transpcol16, s_opt_zoom,
                               s_opt_flip)

from timgres.base.bmpdbase import (nt_bm_sub_img_data, flip_vertical,
                                   flip_horizontal)
'''
This module contains PngShapeDraw_4BPP, class for drawing simple shapes to
    4BPP PNG images.
'''


def _make_png_data_flip(png_data, flip):
    '''
    Used internally for setting the png_data_flip item of nt_bm_sub_img_data.
        Returns a list of 4 items (png_data (one item), None (other three)).
    png_data: bytes, a PNG image
    flip: int, 0-3 see flip_* constants (base.bmpdbase)
    '''
    return [png_data if x == flip else None for x in xrange(4)]


class PngShapeDraw_4BPP(ResDataItemBase):
    '''
    Draw simple shapes to 4BPP PNG images. Inherits support for
        self.set_parent fromResDataItemBase.
    '''

    # The methods in this class use self.parent.get_object() and .get_option()

    def __init__(self):
        ResDataItemBase.__init__(self)
        self.n_arr = NibbleArrayMSF()

    # The following functions return a nt_bm_sub_img_data namedtuple, with
    #     sub_img_info set to None

    def draw_line(self, pos_direction_x, pos_direction_y, color, extra_flip):
        '''
        Draw a line, corresponding to one of the diagonals of the
            image rectangle, using the Bresenham algorithm. Returns a
            nt_bm_sub_img_data namedtuple,
        pos_direction_x (int): The difference of the x coordinates for
            the two end points of the line. Can have both positive and
            negative values. If both directions are positive, the line is
            drawn from the top left to the bottom right corner.
        pos_direction_y (int): like pos_direction_x, y coordinate
        color (int): a color index in the 16-color palette.
        extra_flip (int): an additional flip, compared to the value of
            s_opt_flip. flip_none if not needed.
        '''
        transp_col = self.parent.get_option(s_opt_transpcol16)
        if transp_col is None:
            raise RuntimeError(
                'Transparent color is required for line drawing')

        zoom = self.parent.get_option(s_opt_zoom)
        # NOTE: the two "flips" can be "combined" using bitwise xor
        flip = self.parent.get_option(s_opt_flip)
        flip_combined = flip ^ extra_flip

        png_export = self.parent.get_object(s_obj_pngexp16)

        width_0 = abs(pos_direction_x)
        height_0 = abs(pos_direction_y)
        width_1 = width_0 + 1
        height_1 = height_0 + 1

        width_zoom = width_1 * zoom
        height_zoom = height_1 * zoom
        png_export.reset_image()
        png_export.set_width_height(width_zoom, height_zoom)

        # This function essentially draws one of the two diagonals in a
        #      rectangle. Therefore there are only two possible directions

        # Only horizontal flip is considered here (see comment below)
        direction = (bool(flip_combined & flip_horizontal) !=
                     (pos_direction_x < 0))

        # FIXME, this ensures that vertical flip always produces exact results
        out_png_lines = []

        if direction:
            pos_x = width_0
            step_x = -1
        else:
            pos_x = 0
            step_x = 1

        pos_x_prev = pos_x
        # TODO, the line is currently probably not pixel-exact compared to TIM2
        #     "hacking" the initial value of "err" could possibly be
        #     an easy way to archive this
        err = width_1 - height_1
        # FIXME, to prevent infinite loop when drawing horizontal lines
        end_horiz_line = False

        # Bresenham's line algorithm, see
        #     https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm

        while len(out_png_lines) < height_1:
            err_2 = 2 * err

            if err_2 >= -height_0:
                err -= height_0
                pos_x += step_x

                if height_0 == 0:
                    # FIXME, to prevent infinite loop when drawing horiz. lines
                    if (step_x == 1) and (pos_x == width_0):
                        end_horiz_line = True

                    if (step_x == -1) and (pos_x == 0):
                        end_horiz_line = True

            if (err_2 <= width_0) or end_horiz_line:
                if pos_x > pos_x_prev:
                    start_0 = pos_x_prev
                    end_0 = pos_x + 1
                else:
                    start_0 = pos_x
                    end_0 = pos_x_prev + 1

                pos_x_2 = max(start_0, 0) * zoom
                # pos_x_end: should be interpreted like an end of a slice,
                #     i.e. 5 --> x=4 is the last pixel drawn
                pos_x_end = min(end_0, width_1) * zoom
                self.n_arr.reset()
                self.n_arr.append_nibble_repeated(transp_col, pos_x_2)
                self.n_arr.append_nibble_repeated(color, pos_x_end - pos_x_2)
                self.n_arr.append_nibble_repeated(transp_col,
                                                  width_zoom - pos_x_end)
                out_png_lines.append(self.n_arr.get_bytes())
                err += width_0
                pos_x_prev = pos_x

        # TODO, is this behavior correct (pixel exact) for the
        #     pos_direction_y < 0 case?

        if bool(flip_combined & flip_vertical) != (pos_direction_y < 0):
            lines_flipped = out_png_lines[::-1]
        else:
            lines_flipped = out_png_lines

        for line in lines_flipped:
            for cnt in xrange(zoom):
                png_export.add_line(line)

        png_data = png_export.get_png_data()
        png_export.reset_image()
        self.n_arr.reset()

        return nt_bm_sub_img_data(None, width_zoom, height_zoom,
                                  _make_png_data_flip(png_data, flip))

    def draw_rectangle_with_border(self, width, height, border_color, fill):
        '''
        Draws a rectangle with a border. It can be both filled and non-filled,
            in the latter case, the interior will be transparent.
        width, height (int): the size of the rectangle
        border_color (int): the color ID of the border in the 16-color palette
        fill (int or None): A fill color or None. If None, the transparent
            will be used instead.
        '''
        #
        # fill: fill color number or None -> transparent!
        # NOTE: this function ignores flip because the shape drawn is symmetric

        if fill is None:
            fill_color = self.parent.get_option(s_opt_transpcol16)
            if fill_color is None:
                raise RuntimeError('Transparent color is required for '
                                   'drawing a non-filled rectangle')
        else:
            fill_color = fill

        png_export = self.parent.get_object(s_obj_pngexp16)
        zoom = self.parent.get_option(s_opt_zoom)
        width_zoom = width * zoom
        height_zoom = height * zoom
        png_export.reset_image()
        png_export.set_width_height(width_zoom, height_zoom)

        self.n_arr.reset()
        self.n_arr.append_nibble_repeated(border_color, width_zoom)
        line_top_bottom = self.n_arr.get_bytes()
        self.n_arr.reset()

        if width > 0:
            self.n_arr.append_nibble_repeated(border_color, zoom)

        if width > 1:
            self.n_arr.append_nibble_repeated(fill_color, (width - 2) * zoom)
            self.n_arr.append_nibble_repeated(border_color, zoom)

        line_middle = self.n_arr.get_bytes()
        self.n_arr.reset()

        if height > 0:
            for cnt in xrange(zoom):
                png_export.add_line(line_top_bottom)

        # range from 0 to a negative number: does nothing
        for lines in xrange(height - 2):
            for cnt in xrange(zoom):
                png_export.add_line(line_middle)

        if width > 1:
            for cnt in xrange(zoom):
                png_export.add_line(line_top_bottom)

        png_data = png_export.get_png_data()
        flip = self.parent.get_option(s_opt_flip)
        png_export.reset_image()

        return nt_bm_sub_img_data(None, width_zoom, height_zoom,
                                  _make_png_data_flip(png_data, flip))
