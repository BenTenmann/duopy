cmake_minimum_required(VERSION 3.17)
project(duopy)

set(CMAKE_CXX_STANDARD 11)

find_package(Python3 3.7 COMPONENTS Interpreter Development)
if (Python3_FOUND)
    message("Python include directory: " ${Python3_INCLUDE_DIRS})
    message("Python version is: " ${Python3_VERSION})
    include_directories(${Python3_INCLUDE_DIRS})
endif (Python3_FOUND)

add_library(duopy depr/library.cpp depr/library.h depr/duals.cpp depr/duals.h depr/du_math.cpp depr/du_math.h depr/du_wrap.cpp depr/du_wrap.h duals.c duals.h dual_wrapper.c du_functions.c du_functions.h)