#!/bin/bash

echo "Boostrap ..."

git clone https://gitlab-ci-token:${CI_JOB_TOKEN}@gitlab.com/libesys/esysrepo/dev.git _ci_dev
_ci_dev/scripts/bootstrap.sh

echo "Boostrap done."
