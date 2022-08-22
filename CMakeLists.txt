#
# __legal_b__
#
# Copyright (c) 2021 Michel Gillet
# Distributed under the wxWindows Library Licence, Version 3.1.
# (See accompanying file LICENSE_3_1.txt or
# copy at http://www.wxwidgets.org/about/licence)
#
# __legal_e__
#

CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

get_filename_component(ESYSBASE_DIR "${CMAKE_CURRENT_LIST_DIR}" REALPATH)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)
