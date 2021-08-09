#
# __legal_b__
#
# Copyright (c) 2021 Michel Gillet Distributed under the wxWindows Library
# Licence, Version 3.1. (See accompanying file LICENSE_3_1.txt or copy at
# http://www.wxwidgets.org/about/licence)
#
# __legal_e__
#

project(esysbase CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost 1.66 REQUIRED COMPONENTS filesystem system)

set(ESYSBASE_VERSION_MAJOR 0)
set(ESYSBASE_VERSION_MINOR 1)
set(ESYSBASE_VERSION_PATCH 0)
set(ESYSBASE_VERSION
    ${ESYSBASE_VERSION_MAJOR}.${ESYSBASE_VERSION_MINOR}.${ESYSBASE_VERSION_PATCH}
)

include_directories(../../../include)

set(ESYSBASE_CXX_SOURCES dynlibrarybase.cpp objectbase.cpp objectnamebase.cpp objplatif.cpp pluginbase.cpp pluginmngr.cpp
                         pluginmngrbase.cpp)

set(ESYSBASE_EM_CXX_SOURCES em/object_em.cpp em/objectname_em.cpp em/objectnamemngr_em.cpp
)

set(ESYSBASE_IMPL_BOOST_CXX_SOURCES
    impl_boost/dynlibrary_boost.cpp impl_boost/dynlibraryimpl_boost.cpp
    impl_boost/pluginmngrcore_boost.cpp)

set(ESYSBASE_STDCPP_CXX_SOURCES
  stdcpp/node_stdcpp.cpp
  stdcpp/nodemngr_stdcpp.cpp
  stdcpp/object_stdcpp.cpp
  stdcpp/objectname_stdcpp.cpp
  stdcpp/objectnamemngr_stdcpp.cpp
  stdcpp/objectoperation_stdcpp.cpp
)

add_library(esysbase SHARED ${ESYSBASE_CXX_SOURCES}
                            ${ESYSBASE_EM_CXX_SOURCES}
                            ${ESYSBASE_IMPL_BOOST_CXX_SOURCES}
                            ${ESYSBASE_STDCPP_CXX_SOURCES}
                            )

set_property(TARGET esysbase PROPERTY VERSION ${ESYSBASE_VERSION})
set_property(TARGET esysbase PROPERTY SOVERSION ${ESYSBASE_VERSION_MAJOR})

target_include_directories(esysbase PUBLIC ../.. ../../../include)

target_link_libraries(esysbase PRIVATE Boost::filesystem Boost::system dl)

install(TARGETS esysbase LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(
  DIRECTORY ../../../include/esys/base/
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/esys/base
  FILES_MATCHING
  PATTERN "*.h*")

if(COMMAND add_clang_format_target)
  add_clang_format_target(esysbase)
endif()

if(COMMAND add_clang_tidy_target)
  add_clang_tidy_target(esysbase)
endif()

add_subdirectory(test)
