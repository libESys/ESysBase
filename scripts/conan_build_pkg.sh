#!/bin/bash

echo "${TXT_S}Build Conan pkg ...${TXT_CLEAR}"
echo "pwd = "`pwd`

export CONAN_USER_HOME="$PWD/_conan"
echo "CONAN_USER_HOME=$CONAN_USER_HOME"

cd build/conan
pwd

conan install ../..
if [ ! $? -eq 0 ]; then
   echo "${TXT_E}Couldn't install conan pacakged.${TXT_CLEAR}"
   exit 1
fi

conan create ../.. libesys/testing
if [ ! $? -eq 0 ]; then
   echo "${TXT_E}Failed to create the package.${TXT_CLEAR}"
   exit 1
fi

echo "pwd = "`pwd`
echo "${TXT_S}Build Conan pkg done.${TXT_CLEAR}"
