#
# cmake-format: off
# __legal_b__
#
# Copyright (c) 2021-2023 Michel Gillet 
# Distributed under the MIT License. 
# (See accompanying file LICENSE.txt or 
# copy at https://opensource.org/licenses/MIT)
#
# __legal_e__
# cmake-format: on
#

project(esysbase_t CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(GNUInstallDirs)

# add_definitions(-DESYSTEST_USE_ESYSTEST)
add_definitions(-DESYSTEST_MULTIOS -DESYSTEST_USE_BOOST)
set(ESYSTEST_USE_BOOST 1)

include_directories(../../../../include)

set(ESYSBASE_T_CXX_SOURCES esysbase_t_prec.cpp getpluginrelpath01.cpp main.cpp
                           testcasectrl.cpp)

set(ESYSBASE_T_EM_CXX_SOURCES ../em/test/objectnamemngr01_em.cpp)

set(ESYSBASE_T_IMPL_BOOST_CXX_SOURCES ../impl_boost/test/getexepath01_boost.cpp)

set(ESYSBASE_T_STDCPP_CXX_SOURCES ../stdcpp/test/objectnamemngr01_stdcpp.cpp)

set(ESYSBASE_T_STDCPP_FIX_CXX_SOURCES ../stdcpp/test/fix/object_stdcpp_fix.cpp)

add_executable(
  esysbase_t
  ${ESYSBASE_T_EM_CXX_SOURCES} ${ESYSBASE_T_CXX_SOURCES}
  ${ESYSBASE_T_IMPL_BOOST_CXX_SOURCES} ${ESYSBASE_T_STDCPP_CXX_SOURCES}
  ${ESYSBASE_T_STDCPP_FIX_CXX_SOURCES})

find_package(Boost 1.66 REQUIRED QUIET
             COMPONENTS date_time filesystem iostreams program_options thread)

target_link_libraries(esysbase_t PUBLIC Boost::filesystem
                                        Boost::program_options esysbase)

target_link_libraries(esysbase_t PUBLIC esystest)

install(TARGETS esysbase_t RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

add_test(
  NAME esysbase_t
  WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
  COMMAND esysbase_t -l test_suite)

if(DEFINED ESYSTEST_USE_BOOST)
  add_definitions(-DBOOST_ALL_DYN_LINK)
  find_package(Boost 1.66 REQUIRED QUIET COMPONENTS unit_test_framework)
  target_link_libraries(esysbase_t PUBLIC Boost::unit_test_framework)
endif()
