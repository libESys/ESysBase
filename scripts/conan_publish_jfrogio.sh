#!/bin/bash

echo "${TXT_S}Publish Conan pkg to LibESys JFrog.io ...${TXT_CLEAR}"
echo "pwd = "`pwd`

export CONAN_USER_HOME="$PWD/_conan"
echo "CONAN_USER_HOME=$CONAN_USER_HOME"

cd build/conan

echo "username $1"
conan user -p $2 -r libesys_jfrogio $1
if [ ! $? -eq 0 ]; then
   echo "${TXT_E}Failed to login to LibEsys JFrog.io conan registry.${TXT_CLEAR}"
   exit 1
fi

conan upload ESysTest/0.1.0@libesys/testing --all --remote=libesys_jfrogio
if [ ! $? -eq 0 ]; then
   echo "${TXT_E}Failed to publish conan pkg to LibEsys JFrog.io conan registry.${TXT_CLEAR}"
   exit 1
fi

echo "pwd = "`pwd`
echo "${TXT_S}Publish Conan pkg LibESys JFrog.io done.${TXT_CLEAR}"
