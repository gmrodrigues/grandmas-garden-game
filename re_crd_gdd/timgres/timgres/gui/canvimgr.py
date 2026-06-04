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

import tkinter as tki
from timgres.base.vdobase import ResDataBase_ViewerDataObj
from timgres.base.misc import print_msg, print_traceback

# --- Canvas image manager, also responsible for "animation" ---

'''
Module that contains the "canvas image manager" class CanvasImageManager,
    responisble for creating Tk images (PhotoImage) create image items in
    tkinter canvas. Implemnts animation using after().
'''

coords_x_y_invalid = -999
canvas_size_invalid = (0, 0, 1, 1)  # actually, "scrollregion"

# NOTE: Determining the image width/height may be unreliable in some cases.
#     (However, such cases should be rare.) Therefore, the position top left
#     corner of the non-flipped images is considered the most "reliable".
#     The anchor parameter is set to the corner corresponding to the U.L.
#     in the original when the image was flipped,.

img_flip_anchor = ('nw', 'sw', 'ne', 'se')


class CanvasImageManager(object):
    '''
    Class that stores, creates and updates the canvas image/other items
        for displaying the images stored in the currently selected
        "viewer data object". Also contains the callback functions
        required for animation.
    '''

    def __init__(self):
        '''The constructor of the class. Has no arguments.'''
        self.reset()
        self.reset_images()

    def reset(self):
        '''Resets the class, sets fields to their default values.'''
        # canvas: The tkinter.canvas for displaying the images.
        self.canvas = None
        # background_item: A rectangle item for filling the background
        #     with the chosen color.
        self.background_item = None
        # viewer_data_obj: The currently selected "viewer data object"
        #     in the parent
        self.viewer_data_obj = None
        # id_tk_after: The timer ID returned by self.tk.after if
        #     an animation is shown, otherwise None
        self.id_tk_after = None
        # set_animation_enabled: set by self.set_animation_enabled,
        #      can be used for disabling the animation.
        self.animation_enabled = True
        # blank_photo_image: "Blank" PhotoImage for internal use
        self.blank_photo_image = tki.PhotoImage()

    def reset_images(self):
        '''
        Clears the list containig the pixmaps shown as wlee as the object IDs.
        '''
        self.img_obj_ids = []
        self.images_shown = []

    def set_canvas(self, new_canvas, new_background_item=None):
        '''
        Sets the canvas object. Creates the "background" rect item
            if needed.
        new_canvas: A tkinter.canvas object or None.
        new_background_item: If None, a new rect item is created as
            "background". Alternatively, an item ID for the already existing
            rect object.
        '''

        if self.img_obj_ids:
            raise RuntimeError(
                'Error, not supported when the canvas already has images.')

        if new_canvas is not None:
            if not isinstance(new_canvas, tki.Canvas):
                raise TypeError('new_canvas: must be tkinter.Canvas or None')

        if new_background_item is not None:
            # TODO, no type check for new_background_item
            self.background_item = new_background_item
        else:
            self.background_item = new_canvas.create_rectangle(
                *canvas_size_invalid, fill='', outline='')

        self.canvas = new_canvas

    def set_viewer_data_obj(self, new_viewer_obj):
        '''
        Method for updating the currently selected viewer data object.
        new_viewer_obj: The viewer object, currently selected in ResDataMgr,
            that will be used for showing the images/animation,
            (type: ResDataBase_ViewerDataObj subclass.)
        '''
        if new_viewer_obj is not None:
            if not isinstance(new_viewer_obj, ResDataBase_ViewerDataObj):
                raise TypeError('new_viewer_obj: must be '
                                'ResDataBase_ViewerDataObj or None')

        if self.canvas is None:
            raise RuntimeError('set_viewer_data_obj: canvas must be set')

        self.viewer_data_obj = new_viewer_obj
        self.restart_animation()

    def set_background_color(self, new_background_color):
        '''
        Sets the color of the "background" rect item.
        new_background_color (str): The color, in a format accepted by
            tkinter, typically "#rrggbb". None means no background.
        '''
        if self.background_item is None:
            raise RuntimeError('background_item not set')

        self.canvas.itemconfigure(
            self.background_item,
            fill=(new_background_color
                  if new_background_color is not None else ''))

    def set_animation_enabled(self, enable):
        '''
        Function for enabling/disabling the animation.
        enable (bool): True to enable the animation, False to disable it.
        '''
        self.animation_enabled = bool(enable)

    def restart_animation(self):
        '''
        Stops and re-starts the animation (or switches to a new one selected
            in the "viewer data object").
        '''
        self.cancel_tk_after()
        self.hide_all_images()

        if self.viewer_data_obj is not None:
            canvas_w, canvas_h = \
                self.viewer_data_obj.get_recommended_canvas_size()
            self.canvas.configure(scrollregion=(0, 0, canvas_w, canvas_h))
            self.canvas.coords(self.background_item, 0, 0, canvas_w, canvas_h)
            self.tk_after_func()  # just call the "callback" function directly
        else:
            self.canvas.configure(scrollregion=canvas_size_invalid)
            self.canvas.coords(self.background_item, *canvas_size_invalid)

    def cancel_tk_after(self):
        '''
        Calls after_cancel (tkinter) in an exception handler.
        Required for stopping the animation.
        '''
        if self.id_tk_after is not None:
            try:
                self.canvas.after_cancel(self.id_tk_after)
            except Exception as ex:
                print_msg('BUG: cancel_tk_after failure')
                print_traceback()

            self.id_tk_after = None

    def hide_all_images(self):
        '''Hides all image items of the canvas.'''
        if self.canvas is None:
            return  # HACK, no exception

        for img_id_i in self.img_obj_ids:
            # NOTE: image=None does not seem to work on all Tkinter version,
            #     so pass an empty PhotoImage object
            self.canvas.itemconfigure(img_id_i, image=self.blank_photo_image)
            self.canvas.coords(img_id_i, coords_x_y_invalid,
                               coords_x_y_invalid)

        self.images_shown = []

    def update_image_objs(self):
        '''
        Obtains the images that need to be displayed from the "viewer data
            object" for the current animation frame, and updates the canvas
            and its items accordingly.
        '''
        # NOTE: no "self.canvas is None", "self.viewer_data_obj is None" check
        #   this function should not be called directly

        new_images = []
        n_img_objs_start = len(self.img_obj_ids)

        for new_img_i, new_img_data in enumerate(
                self.viewer_data_obj.get_img_data_curr_frame()):

            new_img_obj = tki.PhotoImage(data=new_img_data.img_data)
            new_images.append(new_img_obj)

            # FIXME, HACK, due to possible extra empty pixels in bitmap (??)
            anchor_i = img_flip_anchor[new_img_data.flip_img]

            if new_img_i < n_img_objs_start:
                # re-use existing image object
                img_obj_id_i = self.img_obj_ids[new_img_i]
                self.canvas.coords(img_obj_id_i, new_img_data.pos_x,
                                   new_img_data.pos_y)
                self.canvas.itemconfigure(img_obj_id_i,
                                          image=new_img_obj,
                                          anchor=anchor_i)
            else:
                # create new object
                img_obj_id_i = self.canvas.create_image(new_img_data.pos_x,
                                                        new_img_data.pos_y,
                                                        image=new_img_obj,
                                                        anchor=anchor_i)

                self.img_obj_ids.append(img_obj_id_i)

        # Hide "extra" PhotoImages (but do not delete them)

        n_new_images = len(new_images)

        # n_img_objs_start is NOT used here !
        if n_new_images < len(self.img_obj_ids):
            for img_id_i in self.img_obj_ids[n_new_images:]:
                # NOTE: see comment in hide_all_images
                self.canvas.itemconfigure(
                    img_id_i, image=self.blank_photo_image)  # ,anchor='nw')
                self.canvas.coords(img_id_i, coords_x_y_invalid,
                                   coords_x_y_invalid)

        self.images_shown = new_images

    def tk_after_func(self):
        '''
        tkinter after() callback function, for showing the next frame of
            the animation.
        '''

        if self.viewer_data_obj is None: return  # important: no exception!

        # the following check is not "absolutely necessary" as neither of the
        #   two called self.viewer_data_obj methods will raise an exception
        #   if no sub-item is selected
        if self.viewer_data_obj.get_sub_item_selected() is None: return

        self.viewer_data_obj.anim_next_frame()
        self.update_image_objs()

        # get_time_delay_next_frame may return None (no animation/end of anim)
        delay_next_fr = self.viewer_data_obj.get_time_delay_next_frame()

        if (delay_next_fr is not None) and self.animation_enabled:
            self.id_tk_after = self.canvas.after(delay_next_fr,
                                                 self.tk_after_func)
