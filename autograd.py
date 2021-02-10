#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Jan 18 11:22:08 2021

@author: benjamintenmann
"""

from math_ import power


class dual():
    
    def __init__(self, real, dual):
        """
        Dual number operations

        Parameters
        ----------
        real : int, float
            The real component of the dual.
        dual : int, float
            The dual component of the dual.

        """
        
        self.real = real
        self.dual = dual
        
    def __add__(self, other):
        
        if type(self) == type(other):
            
            return dual(self.real + other.real, self.dual + other.dual)
        
        else:
            
            return dual(self.real + other, self.dual)
        
    def __radd__(self, other):
        
        if type(self) == type(other):
            
            return dual(self.real + other.real, self.dual + other.dual)
        
        else:
            
            return dual(self.real + other, self.dual)
        
    def __sub__(self, other):
        
        if type(self) == type(other):
            
            return dual(self.real - other.real, self.dual - other.dual)
        
        else:
            
            return dual(self.real - other, self.dual)
        
    def __rsub__(self, other):
        
        if type(self) == type(other):
            
            return dual(other.real - self.real, other.dual - self.dual)
        
        else:
            
            return dual(other - self.real, -self.dual)
        
    def __mul__(self, other):
        
        if type(other) == type(self):
            
            return dual(self.real * other.real,
                    self.real * other.dual + self.dual * other.real)
        else:
            
            return dual(self.real * other, self.dual * other)
        
    def __rmul__(self, other):
        
        if type(other) == type(self):
            
            return dual(self.real * other.real,
                    self.real * other.dual + self.dual * other.real)
        else:
            
            return dual(self.real * other, self.dual * other)
    
    def __truediv__(self, other):
        
        if type(other) == type(self):
            
            return dual(self.real / other.real, 
                        (self.dual / other.real) - (self.real * other.dual / other.real**2))
        else:
            
            return dual(self.real / other, self.dual / other)
        
    def __rtruediv__(self, other):
        
        if type(other) == type(self):
            
            return dual(other.real / self.real, 
                        (other.dual / self.real) - (other.real * self.dual / self.real**2))
        else:
            
            return dual(other / self.real, -(other * self.dual / self.real**2))
        
    def __pow__(self, other):
        
        return power(self, other)
            
    def __repr__(self):
        
        if self.dual >= 0:
            
            return f'{self.real}+{self.dual}e'
        
        else:
            
            return f'{self.real}{self.dual}e'
    
    def __neg__(self):
        
        return dual(-1 * self.real, -1 * self.dual)
    
    