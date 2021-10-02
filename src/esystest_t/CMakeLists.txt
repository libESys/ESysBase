#
# cmake-format: off
# __legal_b__
#
# Copyright (c) 2021 Michel Gillet
# Distributed under the wxWindows Library Licence, Version 3.1.
# (See accompanying file LICENSE_3_1.txt or
# copy at http://www.wxwidgets.org/about/licence)
#
# __legal_e__
# cmake-format: on
#

project(esystest_t CXX)

include(GNUInstallDirs)

include_directories(../../include)

set(ESYSTEST_T_CXX_SOURCES esystest_t_prec.cpp test01.cpp test02.cpp test03.cpp
                           unittest.cpp)

find_package(Boost 1.66 REQUIRED QUIET
             COMPONENTS date_time filesystem iostreams program_options thread)

function(CreateUnitTestExe target_name)

  add_executable(${target_name} ${ESYSTEST_T_CXX_SOURCES})

  target_link_libraries(
    ${target_name} PUBLIC Boost::date_time Boost::filesystem Boost::iostreams
                          Boost::program_options Boost::thread)

  target_link_libraries(${target_name} PUBLIC esystest)

  install(TARGETS ${target_name} RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

  add_test(
    NAME ${target_name}
    WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
    COMMAND ${target_name} -l test_suite)

endfunction()

if(ESYSTEST_ESYSTEST_UNIT_TESTS)
  createunittestexe(esystest_t)
endif()

if(ESYSTEST_BOOST_UNIT_TESTS)
  find_package(Boost 1.66 REQUIRED QUIET COMPONENTS unit_test_framework)

  createunittestexe(esystestboost_t)

  target_compile_definitions(esystestboost_t PRIVATE BOOST_ALL_DYN_LINK
                                                     ESYSTEST_USE_BOOST)
  target_link_libraries(esystestboost_t PUBLIC Boost::unit_test_framework)
endif()
