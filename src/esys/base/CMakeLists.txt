#
# cmake-format: off
# __legal_b__
#
# Copyright (c) 2021-2022 Michel Gillet
# Distributed under the wxWindows Library Licence, Version 3.1.
# (See accompanying file LICENSE_3_1.txt or
# copy at http://www.wxwidgets.org/about/licence)
#
# __legal_e__
# cmake-format: on
#

project(esysbase CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(ESYSBASE_VHW)
  find_package(Boost 1.66 REQUIRED COMPONENTS filesystem system)
endif()

set(ESYSBASE_VERSION_MAJOR 0)
set(ESYSBASE_VERSION_MINOR 1)
set(ESYSBASE_VERSION_PATCH 0)
set(ESYSBASE_VERSION
    ${ESYSBASE_VERSION_MAJOR}.${ESYSBASE_VERSION_MINOR}.${ESYSBASE_VERSION_PATCH}
)

include_directories(../../../include)

set(ESYSBASE_CXX_SOURCES objectbase.cpp objectnamebase.cpp objplatif.cpp)

if(ESYSBASE_VHW)
  set(ESYSBASE_CXX_SOURCES
      ${ESYSBASE_CXX_SOURCES} dynlibrarybase.cpp pluginbase.cpp pluginmngr.cpp
      pluginmngrbase.cpp version.cpp)
endif()

set(ESYSBASE_EM_CXX_SOURCES em/log_if_em.cpp em/object_em.cpp
                            em/objectname_em.cpp em/objectnamemngr_em.cpp)

set(ESYSBASE_IMPL_BOOST_CXX_SOURCES
    impl_boost/dynlibrary_boost.cpp impl_boost/dynlibraryimpl_boost.cpp
    impl_boost/pluginmngrcore_boost.cpp)

set(ESYSBASE_STDCPP_CXX_SOURCES
    stdcpp/log_if_stdcpp.cpp
    stdcpp/logger_stdcpp.cpp
    stdcpp/node_stdcpp.cpp
    stdcpp/nodemngr_stdcpp.cpp
    stdcpp/object_stdcpp.cpp
    stdcpp/objectname_stdcpp.cpp
    stdcpp/objectnamemngr_stdcpp.cpp
    stdcpp/objectoperation_stdcpp.cpp)

set(ESYSBASE_CXX_SOURCES ${ESYSBASE_CXX_SOURCES} ${ESYSBASE_EM_CXX_SOURCES})

if(ESYSBASE_VHW)
  set(ESYSBASE_CXX_SOURCES
      ${ESYSBASE_CXX_SOURCES} ${ESYSBASE_IMPL_BOOST_CXX_SOURCES}
      ${ESYSBASE_STDCPP_CXX_SOURCES})
endif()

add_library(esysbase ${ESYSBASE_LIB_TYPE} ${ESYSBASE_CXX_SOURCES})

if(ESYSBASE_SHARED)
  # find_package(dl)
  set_property(TARGET esysbase PROPERTY VERSION ${ESYSBASE_VERSION})
  set_property(TARGET esysbase PROPERTY SOVERSION ${ESYSBASE_VERSION_MAJOR})
endif()

target_include_directories(esysbase PUBLIC ../.. ../../../include)

if(ESYSBASE_SHARED)
  target_link_libraries(esysbase PRIVATE Boost::filesystem Boost::system
                                         ${CMAKE_DL_LIBS})
endif()

if(ESYSBASE_VHW)
  target_link_libraries(esysbase PRIVATE esystrace)
endif()

install(TARGETS esysbase LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(
  DIRECTORY ../../../include/esys/base/
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/esys/base
  FILES_MATCHING
  PATTERN "*.h*")

if(ESYSBASE_VHW)
  if(COMMAND add_clang_format_target)
    add_clang_format_target(esysbase)
  endif()

  if(COMMAND add_clang_tidy_target)
    add_clang_tidy_target(esysbase)
  endif()
endif()

if(ESYSBASE_VHW AND ESYSBASE_BUILD_UTS)
  add_subdirectory(test)
endif()
