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

# --- "nibble" array ---

'''
This module provides a simple "nibble array" class that supports concatenating
    lsits of nibbles
'''


def _single_char(x):
    '''
    For Python 2 backwards compatibility. In Python 2, b[i] returns a char
        instead of a byte (int) if the type of "b" in the example is "bytes".
        x (int/char): is an item from a bytes object (b[i]) Returns int.
    '''
    # in Python 2, b[i] returns char/bytes instead of int when
    #     b is a bytes (not bytearray) object
    return x if isinstance(x, int) else ord(x)


# fixme, this requires at least Python 3.2

# This approach is much faster than an alternative implementation using
#    a generator


def _b_array_shift_left_4_frombytes(data, remove_last_byte):
    '''
    Function that treats data as an array of "nibbles" and shifts it to
        the right with one position. Requires Python 3.2+
    data (bytes/bytearray): the bytes string to shift
    remove_last_byte (bool): True if "data" contains an odd number of
        "nibbles" i.e. low-order 4 bits of last byte are unused
    '''

    # returns bytes, not bytearray
    data = (int.from_bytes(data, 'big') << 4).to_bytes(len(data) + 1, 'big')

    return data[:-1] if remove_last_byte else data


def _b_array_shift_left_4_gen(seq, remove_last_byte):
    '''
    A generator that provides a (slower) alternative implementation
        for shifting a byte array as a list of nibbles,
    seq (bytes/bytearray): the input
    remove_last_byte (bool): see _b_array_shift_left_4_frombytes
    "Yields" ints (single bytes).
    '''
    low_4b = 0

    for item in seq:
        byte = _single_char(item)

        yield (low_4b << 4) | (byte >> 4)
        low_4b = byte & 0xf

    if not remove_last_byte: yield low_4b << 4


if hasattr(int, 'from_bytes'):
    _b_array_shift_left_4 = _b_array_shift_left_4_frombytes
else:
    # fixme, returns bytearray, not bytes
    _b_array_shift_left_4 = lambda data, remove: \
        bytearray(_b_array_shift_left_4_gen(data, remove))

str_err_check_failure = 'NibbleArrayMSF._check failure'


class NibbleArrayMSF(object):
    '''
    A small "nibble array" class that supports "extensions" at the
        end of the lists. See the append_* methods. The get_data method
        returns the stored data as "bytes".
    "MSF" stands for "more significant nibble first"
    '''

    # According to my tests, concatenating bytes to a bytearray using the
    #   += operator or .extend is at least as fast as using a BytesIO obj
    #   (this is, however, not the case with "bytes")

    def __init__(self):
        '''The constructor of class, has no argument.'''
        self.reset()

    def __len__(self):
        '''Returns the length of the nibble array (int).'''
        return self.len_nibbles

    def _check(self):
        '''Private function for simple "sanity checks"'''
        if ((self.len_nibbles + 1) >> 1) != len(self.data):
            raise RuntimeError(str_err_check_failure)

        if self.len_nibbles & 1:
            if (self.data[-1] & 0xf):
                raise RuntimeError(str_err_check_failure)

    def reset(self):
        '''Clears the stored nibble array.'''
        self.data = bytearray()
        # in "nibbles", not bytes
        self.len_nibbles = 0

    def append_nibble(self, nibble):
        '''
        Appends a single nibble to the end of the array.
        nibble (int, 0-15): the nibble to append
        '''
        if (nibble < 0) or (nibble > 15):
            raise ValueError('nibble: out of range')

        if self.len_nibbles & 1:  # only "high-order" nibble used in last byte
            self.data[-1] |= nibble
        else:
            self.data.append(nibble << 4)

        self.len_nibbles += 1
        self._check()

    def append_nibble_repeated(self, nibble, repeat):
        '''
        Appends the same nibble several times to the end of the array.
        nibble (int, 0-15): the nibble to append
        repeat (int): the repeat count
        '''
        if (nibble < 0) or (nibble > 15):
            raise ValueError('nibble: out of range')

        if repeat < 0:
            raise ValueError('repeat: invalid value')

        if repeat == 0:
            return  # fixme, "general" code should support this
        elif repeat == 1:
            self.append_nibble(nibble)
            return

        # this code works if repeat >= 2
        if self.len_nibbles & 1:  # only "high-order" nibble used in last byte
            self.data[-1] |= nibble
            remaining = repeat - 1
        else:
            remaining = repeat

        self.data.extend((nibble << 4 | nibble, ) * (remaining >> 1))

        if remaining & 1:
            self.data.append(nibble << 4)

        self.len_nibbles += repeat
        self._check()

    def append_byte(self, byte):
        '''
        Appends a single byte (two nibbles) to the end of the array.
        byte (int): the byte to append.
        '''
        if (byte < 0) or (byte > 255):
            raise ValueError('nibble: out of range')

        if self.len_nibbles & 1:  # only "high-order" nibble used in last byte
            self.data[-1] |= byte >> 4
            self.data.append((byte & 0xf) << 4)
        else:
            self.data.append(byte)

        self.len_nibbles += 2
        self._check()

    def append_bytes(self, data, last_nibble_unused):
        '''
        Appends a bytes or bytearray object, interpreted as a list of nibbles,
            to the end of the array.
        data (bytes, bytearray): the byte array to append.
        last_nibble_unused (bool): If a sequence of nibbles with an odd length
            is stored as a byte array, the last nibble of it will be unused.
            True if the input data should be treated this way.
        '''
        if not isinstance(data, (bytes, bytearray)):
            raise TypeError('data: must be bytearray or bytes')

        if last_nibble_unused and (_single_char(data[-1]) & 0xf):
            raise ValueError('Last "nibble" mist be zero when '
                             'last_nibble_unused is True')

        if not data: return  # empty, todo ....

        if self.len_nibbles & 1:  # only "high-order" nibble used in last byte
            data_sh = _b_array_shift_left_4(data, last_nibble_unused)
            # todo: check data_sh[0]
            self.data[-1] |= _single_char(data_sh[0])
            self.data.extend(data_sh[1:])
        else:
            self.data.extend(data)

        self.len_nibbles += len(data) * 2 - bool(last_nibble_unused)
        self._check()

    def get_bytes(self):
        '''
        Returns the data stored in the class (type: bytes)
        '''
        return bytes(self.data)
