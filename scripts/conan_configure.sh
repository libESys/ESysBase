#!/bin/bash

echo "${TXT_S}Configure Conan ...${TXT_CLEAR}"
echo "pwd = "`pwd`

export CONAN_USER_HOME="$PWD/_conan"
echo "CONAN_USER_HOME=$CONAN_USER_HOME"

mkdir -p build/conan
cd build/conan

conan --version
if [ ! $? -eq 0 ]; then
   echo "${TXT_E}Couldn't get conan vesion.${TXT_CLEAR}"
   exit 1
fi

conan profile new default --detect
if [ ! $? -eq 0 ]; then
   echo "${TXT_E}Couldn't detect conan profile.${TXT_CLEAR}"
   exit 1
fi

conan profile update settings.compiler.libcxx=libstdc++11 default
if [ ! $? -eq 0 ]; then
   echo "${TXT_E}Couldn't set compilet to use c++11 ABI.${TXT_CLEAR}"
   exit 1
fi

conan remote add gitlab https://gitlab.com/api/v4/packages/conan
if [ ! $? -eq 0 ]; then
   echo "${TXT_E}Couldn't add GitLab conan remote.${TXT_CLEAR}"
   exit 1
fi

conan remote add conan_project ${CI_API_V4_URL}/projects/$CI_PROJECT_ID/packages/conan
if [ ! $? -eq 0 ]; then
   echo "${TXT_E}Couldn't add GitLab conan remote.${TXT_CLEAR}"
   exit 1
fi

conan remote add libesys_conan https://artifactory.libesys.org/artifactory/api/conan/libesys
if [ ! $? -eq 0 ]; then
   echo "${TXT_E}Couldn't add LibEsys conan remote.${TXT_CLEAR}"
   exit 1
fi

echo "pwd = "`pwd`
echo "${TXT_S}configure Conan done.${TXT_CLEAR}"
