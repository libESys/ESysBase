#
# cmake-format: off
# __legal_b__
#
# Copyright (c) 2022 Michel Gillet
# Distributed under the wxWindows Library Licence, Version 3.1.
# (See accompanying file LICENSE_3_1.txt or
# copy at http://www.wxwidgets.org/about/licence)
#
# __legal_e__
# cmake-format: on
#

project(esysbaseexe CXX)

find_package(Boost 1.66 REQUIRED QUIET COMPONENTS system filesystem
                                                  program_options thread)

include_directories(../../include)

set(ESYSBASEEXE_CXX_SOURCES esysbaseexe_prec.cpp esysbaseexe.cpp main.cpp)

add_executable(esysbaseexe ${ESYSBASEEXE_CXX_SOURCES})

set_target_properties(esysbaseexe PROPERTIES PREFIX "")
set_target_properties(esysbaseexe PROPERTIES OUTPUT_NAME "esysbase")

target_link_libraries(
  esysbaseexe PRIVATE Boost::filesystem Boost::program_options Boost::system
                      esysbase)

install(TARGETS esysbaseexe DESTINATION bin)
