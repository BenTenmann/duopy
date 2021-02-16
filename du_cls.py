#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Feb 15 23:20:08 2021

@author: benjamintenmann
"""


import duopy as du

class dual():
    
    def __init__(self, real, dual):
        self.r = real
        self.d = dual
    def __repr__(self):
        if self.d < 0:
            return f'{self.r}{self.d}e'
        else:
            return f'{self.r}+{self.d}e'
    def __add__(self, other):
        try:
            if type(other) == dual:
                return dual(*du.addD(self.r, self.d,
                               other.r, other.d))
            else:
                return dual(*du.addV(self.r, self.d, 
                               other))
        except ValueError as e:
            return e
    def __radd__(self, other):
        return self.__add__(other)
    def __sub__(self, other):
        try:
            if type(other) == dual:
                return dual(*du.subD(self.r, self.d,
                               other.r, other.d))
            else:
                return dual(*du.subV(self.r, self.d, 
                               other))
        except ValueError as e:
            return e
    def __rsub__(self, other):
        try:
            return dual(*du.isubV(other, self.r, self.d))
        except ValueError as e:
            return e
    def __mul__(self, other):
        try:
            if type(other) == dual:
                return dual(*du.mulD(self.r, self.d,
                               other.r, other.d))
            else:
                return dual(*du.mulV(self.r, self.d, 
                               other))
        except ValueError as e:
            return e
    def __rmul__(self, other):
        return self.__mul__(other)
    def __truediv__(self, other):
        try:
            if type(other) == dual:
                return dual(*du.divD(self.r, self.d,
                               other.r, other.d))
            else:
                return dual(*du.divV(self.r, self.d,
                               other))
        except ValueError as e:
            return e
    def __rtruediv__(self, other):
        try:
            return dual(*du.idivV(other, self.r, self.d))
        except ValueError as e:
            return e
    def __pow__(self, other):
        try:
            return dual(*du.pow(self.r, self.d,
                          other))
        except ValueError as e:
            return e