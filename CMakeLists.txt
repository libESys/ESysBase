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
    src/esystest/order.cpp
    src/esystest/report.cpp
    src/esystest/testcase.cpp
    src/esystest/testcasectrl.cpp
    src/esystest/testcaseinfo.cpp
    src/esystest/testsuite.cpp
    src/esystest/types.cpp
)

if (DEFINED ESYSTEST_BUILD_VHW)
    add_library (esystest SHARED ${LIBESYSTEST_CXX_SOURCES})
else ()
    add_library (esystest STATIC ${LIBESYSTEST_CXX_SOURCES})
endif ()

if (NOT WIN32)
	set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=gnu++11")
	target_include_directories ( esystest  PUBLIC
        ./include
    )

else ()
	set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DWIN32 -D_DEBUG -D_WINDOWS -D_USRDLL -DPAL_EXPORTS")
	set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHsc  /W3")
	target_include_directories ( esystest  PUBLIC
    ./include
    ${ESYS_BOOST}
    )

endif ()

#add_dependencies( cal
#    ral
#    pal)

if ( ${MOE_BOARD} STREQUAL "virtualhw" )
#    target_link_libraries( cal
#        ral
#        pal)
else ()
#    target_link_libraries( cal
#        ral
#        pal        
#        )
endif ()

ADD_CUSTOM_COMMAND(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_OBJDUMP} -C -x -w $<TARGET_FILE:${PROJECT_NAME}> >${LOGS_OUTPUT_PATH}/$<TARGET_FILE_NAME:${PROJECT_NAME}>.objdump)
ADD_CUSTOM_COMMAND(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_NM} --print-size --size-sort --reverse-sort --radix=d  -C $<TARGET_FILE:${PROJECT_NAME}> >${LOGS_OUTPUT_PATH}/$<TARGET_FILE_NAME:${PROJECT_NAME}>.nm)

