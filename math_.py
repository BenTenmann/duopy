#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Jan 19 11:59:31 2021

@author: benjamintenmann
"""

def power(x, n):
    
    if n == 0:
        
        return 1
    
    else:
        
        return x * power(x, n-1)


def factorial(n):
    
    if n == 0:
        
        return 1
    
    else:
        
        return n * factorial(n-1)


def euler(x, n):
    
    if n == 0:
        
        return 1 / factorial(n)
    
    else:
        
        return ((x ** n) / factorial(n)) + euler(x, n-1)


def ln(x, k):
    
    if k == 1:
        
        return x - 1
    else:
        
        return ln(x, k-1) + (((-1) ** (k-1)) * (((x - 1) ** k) / k))


def tanh(x, n=20):
    
    t = (euler(2*x, n) - 1) / (euler(2*x, n) + 1)
    
    return t

