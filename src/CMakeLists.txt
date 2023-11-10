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

add_subdirectory(esys/base)
if(ESYSBASE_VHW)
  add_subdirectory(esysbaseexe)
endif()
