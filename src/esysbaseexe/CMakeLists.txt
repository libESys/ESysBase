#
# cmake-format: off
# __legal_b__
#
# Copyright (c) 2022 Michel Gillet
# Distributed under the MIT License.
# (See accompanying file LICENSE.txt or
# copy at https://opensource.org/licenses/MIT)
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
                      esysbase esyslog esystrace)

install(TARGETS esysbaseexe DESTINATION bin)
