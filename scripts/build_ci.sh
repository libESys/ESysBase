#!/bin/bash

echo "Build ..."
mkdir -p build_dev/build/cmake
cmake -S build_dev -B build_dev/build/cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
# cmake --build build_dev/build/cmake --clean-first --target esysbaseexe esysbase_t
cd build_dev/build/cmake
make clean esysbaseexe esysbase_t

echo "Build done."
