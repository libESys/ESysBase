#!/bin/bash

echo "${TXT_S}Publish Conan pkg to LibESys ...${TXT_CLEAR}"
echo "pwd = "`pwd`

export CONAN_USER_HOME="$PWD/_conan"
echo "CONAN_USER_HOME=$CONAN_USER_HOME"

cd build/conan

echo "username $1"
conan user -p $2 -r libesys_conan $1
if [ ! $? -eq 0 ]; then
   echo "${TXT_E}Failed to login to LibEsys conan registry.${TXT_CLEAR}"
   exit 1
fi

conan upload ESysTest/0.1.0@libesys/testing --all --remote=libesys_conan
if [ ! $? -eq 0 ]; then
   echo "${TXT_E}Failed to publish conan pkg to LibEsys conan registry.${TXT_CLEAR}"
   exit 1
fi

echo "pwd = "`pwd`
echo "${TXT_S}Publish Conan pkg LibESys done.${TXT_CLEAR}"
