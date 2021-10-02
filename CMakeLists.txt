#
# cmake-format: off
# __legal_b__
#
# Copyright (c) 2015-2021 Michel Gillet
# Distributed under the wxWindows Library Licence, Version 3.1.
# (See accompanying file LICENSE_3_1.txt or
# copy at http://www.wxwidgets.org/about/licence)
#
# __legal_e__
# cmake-format: on
#

cmake_minimum_required(VERSION 3.13)
project(esystest CXX)

option(ESYSTEST_BUILD_OS "Build for when a OS is present" On)
option(ESYSTEST_USE_ONLY_BOOST "Use only the Boost backend" Off)
option(ESYSTEST_USE_ONLY_ESYSTEST "Use only the ESysTest backend" Off)
option(ESYSTEST_UNIT_TESTS "Build all unit tests using all backends" Off)
option(ESYSTEST_BOOST_UNIT_TESTS "Build unit tests using Boost backend" Off)
option(ESYSTEST_ESYSTEST_UNIT_TESTS "Build unit tests using ESysTest backend"
       Off)
option(ESYSTEST_USE_CONAN "Use conan package mamager" Off)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif(NOT CMAKE_CXX_STANDARD)

set(ESYSTEST_VERSION_MAJOR 0)
set(ESYSTEST_VERSION_MINOR 0)
set(ESYSTEST_VERSION_PATCH 1)
set(ESYSTEST_VERSION
    ${ESYSTEST_VERSION_MAJOR}.${ESYSTEST_VERSION_MINOR}.${ESYSTEST_VERSION_PATCH}
)

if(ESYSTEST_USE_CONAN)
  include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
  conan_basic_setup()
endif()

if(ESYSTEST_UNIT_TESTS)
  set(ESYSTEST_BOOST_UNIT_TESTS On)
  set(ESYSTEST_ESYSTEST_UNIT_TESTS On)
endif()

add_subdirectory(src)
