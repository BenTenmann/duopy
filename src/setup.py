from distutils.core import setup, Extension

extension_mod = Extension("duopy", ["dual_wrapper.c", "duals.c", "du_functions.c"])

setup(name="duopy", ext_modules=[extension_mod])