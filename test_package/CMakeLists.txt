cmake_minimum_required(VERSION 3.1)
project(PackageTest CXX)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

find_package(Boost 1.66 REQUIRED QUIET COMPONENTS unit_test_framework)
find_package(esystest)

add_definitions(-DESYSTEST_MULTIOS -DESYSTEST_USE_BOOST)
set(ESYSTEST_USE_BOOST 1)

add_executable(example main.cpp test01.cpp)
target_link_libraries(example ${CONAN_LIBS})

# CTest is a testing tool that can be used to test your project.
# enable_testing() add_test(NAME example WORKING_DIRECTORY
# ${CMAKE_BINARY_DIR}/bin COMMAND example)
