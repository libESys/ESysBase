project (esystest CXX)
message(STATUS "ESysTest CMakeLists.txt")
# Helper function for adding source files from HW build files

include_directories(
    ./include
)

SET( LIBESYSTEST_CXX_SOURCES
    src/esystest/esystest_dll.cpp
    src/esystest/esystest_prec.cpp
    src/esystest/globalfixture.cpp
    src/esystest/logger.cpp
    src/esystest/mastertestsuite.cpp
    src/esystest/order.cpp
    src/esystest/report.cpp
    src/esystest/testcase.cpp
    src/esystest/testcasectrlbase.cpp
    src/esystest/testcaseinfo.cpp
    src/esystest/testsuite.cpp
    src/esystest/types.cpp
)

if (DEFINED ESYSTEST_BUILD_VHW)
SET( LIBESYSTEST_CXX_SOURCES
    ${LIBESYSTEST_CXX_SOURCES}
    src/esystest/exception.cpp
    src/esystest/stdlogger.cpp
)
endif()

SET( LIBESYSTEST_BOOST_CXX_SOURCES
    src/esystest/boost/testcasectrl_boost.cpp
)

SET( LIBESYSTEST_ESYSTEST_CXX_SOURCES
    src/esystest/esystest/testcasectrl_esystest.cpp
)

SET( LIBESYSTEST_MULTIOS_CXX_SOURCES
    src/esystest/multios/testcasectrlcore_multios.cpp
)

if (NOT DEFINED ESYSTEST_USE_BOOST OR DEFINED ESYSTEST_USE_ESYSTEST)
set(LIBESYSTEST_CXX_SOURCES
        ${LIBESYSTEST_CXX_SOURCES}
        ${LIBESYSTEST_ESYSTEST_CXX_SOURCES}
    )
elseif(DEFINED ESYSTEST_USE_BOOST)
set(LIBESYSTEST_CXX_SOURCES
        ${LIBESYSTEST_CXX_SOURCES}
        ${LIBESYSTEST_BOOST_CXX_SOURCES}
    )
endif()

if (DEFINED ESYSTEST_BUILD_VHW)
    set(LIBESYSTEST_CXX_SOURCES
        ${LIBESYSTEST_CXX_SOURCES}
        ${LIBESYSTEST_MULTIOS_CXX_SOURCES}
    )

    add_library (esystest SHARED ${LIBESYSTEST_CXX_SOURCES})
else ()
    add_library (esystest STATIC ${LIBESYSTEST_CXX_SOURCES})
endif ()

if (NOT WIN32)
	set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=gnu++11")
	target_include_directories ( esystest  PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/include/esystest/boost
    )

else ()
	set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DWIN32 -D_DEBUG -D_WINDOWS -D_USRDLL -DPAL_EXPORTS")
	set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHsc  /W3")
	target_include_directories ( esystest  PUBLIC
    ./include
    ${ESYS_BOOST}
    )

endif ()


if (DEFINED ESYSTEST_BUILD_VHW)
    #add_dependencies( esystest
    #    esys
    #)
else ()

endif ()

ADD_CUSTOM_COMMAND(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_OBJDUMP} -C -x -w $<TARGET_FILE:${PROJECT_NAME}> >${LOGS_OUTPUT_PATH}/$<TARGET_FILE_NAME:${PROJECT_NAME}>.objdump || true)
ADD_CUSTOM_COMMAND(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_NM} --print-size --size-sort --reverse-sort --radix=d  -C $<TARGET_FILE:${PROJECT_NAME}> >${LOGS_OUTPUT_PATH}/$<TARGET_FILE_NAME:${PROJECT_NAME}>.nm)

