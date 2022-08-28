#!/bin/bash

echo "Build ..."
mkdir -p build_dev/build/cmake
cmake -S build_dev -B build_dev/build/cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DESYSBASE_BUILD_UTS=On

cd build_dev/build/cmake
make clean esysbaseexe esysbase_t

cd ../../..
mkdir -p build_dev/build/cmake_hw
cmake -S build_dev -B build_dev/build/cmake_hw -DESYSBASE_HW=On

cd build_dev/build/cmake_hw
make clean esysbase

echo "Build done."
