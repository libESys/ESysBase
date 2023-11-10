#
# cmake-format: off
# __legal_b__
#
# Copyright (c) 2021-2022 Michel Gillet
# Distributed under the MIT License.
# (See accompanying file LICENSE.txt or
# copy at https://opensource.org/licenses/MIT)
#
# __legal_e__
# cmake-format: on
#

cmake_minimum_required(VERSION 3.15)

project(esysbase_top CXX)

option(ESYSBASE_SHARED "Build shared library" On)
option(ESYSBASE_HW "Build for MCU" Off)
option(ESYSBASE_BUILD_UTS "Build Unit Tests" Off)

if(ESYSBASE_HW)
  set(ESYSBASE_SHARED Off)
endif()

get_filename_component(ESYSBASE_DIR "${CMAKE_CURRENT_LIST_DIR}" REALPATH)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(ESYSBASE_SHARED)
  set(ESYSBASE_LIB_TYPE "SHARED")
else()
  set(ESYSBASE_LIB_TYPE "STATIC")
endif()

if(ESYSBASE_HW)
  set(ESYSBASE_VHW Off)
  add_compile_definitions(ESYSBASE_HW=1)
else()
  set(ESYSBASE_VHW On)
  add_compile_definitions(ESYSBASE_VHW=1)
endif()

add_subdirectory(src)
