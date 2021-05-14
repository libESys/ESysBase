#!/bin/bash

echo "Build ..."
echo "PATH = $PATH"

mkdir build
cd build
mkdir cmake
cd cmake
pwd
cmake ../..
make esysbase_t

echo "Build done."
