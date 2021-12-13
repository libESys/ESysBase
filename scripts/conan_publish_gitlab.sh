#!/bin/bash

echo "${TXT_S}Publish Conan pkg to GitLab ...${TXT_CLEAR}"
echo "pwd = "`pwd`

export CONAN_USER_HOME="$PWD/_conan"
echo "CONAN_USER_HOME=$CONAN_USER_HOME"

source ./scripts/conan_pkg_version.env

cd build/conan

CONAN_LOGIN_USERNAME=ci_user CONAN_PASSWORD=${CI_JOB_TOKEN} conan upload ESysTest/${ESYSTEST_CONAN_PKG_VERSION}${1} --all --remote=conan_project
if [ ! $? -eq 0 ]; then
   echo "${TXT_E}Failed to publish conan pkg to GitLab.${TXT_CLEAR}"
   exit 1
fi

echo "pwd = "`pwd`
echo "${TXT_S}Publish Conan pkg to GitLab done.${TXT_CLEAR}"
