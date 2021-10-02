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

include_directories(../../include)

set(LIBESYSTEST_CXX_SOURCES
    esystest_dll.cpp
    esystest_prec.cpp
    globalfixture.cpp
    logger.cpp
    mastertestsuite.cpp
    order.cpp
    report.cpp
    testcase.cpp
    testcasectrlbase.cpp
    testcaseinfo.cpp
    testsuite.cpp
    types.cpp)

if(ESYSTEST_BUILD_OS)
  set(LIBESYSTEST_CXX_SOURCES ${LIBESYSTEST_CXX_SOURCES} exception.cpp
                              stdlogger.cpp)
endif()

set(LIBESYSTEST_BOOST_CXX_SOURCES boost/testcasectrl_boost.cpp)

set(LIBESYSTEST_ESYSTEST_CXX_SOURCES esystest/testcasectrl_esystest.cpp)

set(LIBESYSTEST_MULTIOS_CXX_SOURCES multios/testcasectrlcore_multios.cpp)

if(NOT ESYSTEST_USE_ONLY_BOOST AND NOT ESYSTEST_USE_ONLY_ESYSTEST)
  set(ESYSTEST_USE_BOOST 1)
  set(ESYSTEST_USE_ESYSTEST 1)

  set(LIBESYSTEST_CXX_SOURCES
      ${LIBESYSTEST_CXX_SOURCES} ${LIBESYSTEST_ESYSTEST_CXX_SOURCES}
      ${LIBESYSTEST_BOOST_CXX_SOURCES})
elseif(ESYSTEST_USE_ONLY_BOOST)
  set(ESYSTEST_USE_BOOST 1)
  set(LIBESYSTEST_CXX_SOURCES ${LIBESYSTEST_CXX_SOURCES}
                              ${LIBESYSTEST_BOOST_CXX_SOURCES})
elseif(ESYSTEST_USE_ONLY_ESYSTEST)
  set(ESYSTEST_USE_ESYSTEST 1)
  set(LIBESYSTEST_CXX_SOURCES ${LIBESYSTEST_CXX_SOURCES}
                              ${LIBESYSTEST_ESYSTEST_CXX_SOURCES})
endif()

if(ESYSTEST_BUILD_OS)
  set(LIBESYSTEST_CXX_SOURCES ${LIBESYSTEST_CXX_SOURCES}
                              ${LIBESYSTEST_MULTIOS_CXX_SOURCES})

  add_library(esystest SHARED ${LIBESYSTEST_CXX_SOURCES})
  set_property(TARGET esystest PROPERTY VERSION ${ESYSTEST_VERSION})
  set_property(TARGET esystest PROPERTY SOVERSION ${ESYSTEST_VERSION_MAJOR})
  target_compile_definitions(esystest PUBLIC ESYSTEST_MULTIOS)
else()
  add_library(esystest STATIC ${LIBESYSTEST_CXX_SOURCES})
endif()

if(DEFINED ESYSTEST_USE_BOOST)

  find_package(Boost 1.66 REQUIRED QUIET COMPONENTS filesystem program_options
                                                    unit_test_framework)

  target_link_libraries(
    esystest
    PRIVATE Boost::filesystem Boost::program_options
    PUBLIC Boost::unit_test_framework)
endif()

if(NOT WIN32)

else()
  set(CMAKE_CXX_FLAGS
      "${CMAKE_CXX_FLAGS} -DWIN32 -D_DEBUG -D_WINDOWS -D_USRDLL -DPAL_EXPORTS")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHsc  /W3")
endif()

target_include_directories(
  esystest PUBLIC $<INSTALL_INTERFACE:include>
                  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../include>)

install(
  TARGETS esystest
  EXPORT esystest-export
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib)

install(
  EXPORT esystest-export
  FILE esystestTargets.cmake
  DESTINATION lib/cmake/esystest)

install(
  DIRECTORY include/esystest/
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/esystest
  FILES_MATCHING
  PATTERN "*.h*")

install(
  FILES ${CMAKE_CURRENT_SOURCE_DIR}/../../project/cmake/esystestConfig.cmake
  DESTINATION "lib/cmake/esystest")

set(CMAKE_EXPORT_PACKAGE_REGISTRY ON)
export(PACKAGE esystest)

# install(TARGETS esystest ARCHIVE DESTINATION lib LIBRARY DESTINATION lib )

# install(DIRECTORY include/ DESTINATION include)

if(DEFINED LOGS_OUTPUT_PATH)
  add_custom_command(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND
      ${CMAKE_OBJDUMP} -C -x -w $<TARGET_FILE:${PROJECT_NAME}>
      >${LOGS_OUTPUT_PATH}/$<TARGET_FILE_NAME:${PROJECT_NAME}>.objdump || true)
  add_custom_command(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND
      ${CMAKE_NM} --print-size --size-sort --reverse-sort --radix=d -C
      $<TARGET_FILE:${PROJECT_NAME}>
      >${LOGS_OUTPUT_PATH}/$<TARGET_FILE_NAME:${PROJECT_NAME}>.nm)
endif()

if(COMMAND add_clang_format_target)
  add_clang_format_target(esystest)
endif()

if(COMMAND add_clang_tidy_target)
  add_clang_tidy_target(esystest)
endif()
