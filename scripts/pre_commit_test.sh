#!/bin/bash

echo "${TXT_S}Pre-commit test ...${TXT_CLEAR}"

if [ ! -z ${CI_COMMIT_BRANCH+x} ];
then
    echo "Commit branch : ${CI_COMMIT_BRANCH}"
    TO_CHECKOUT=${CI_COMMIT_BRANCH}
elif [ ! -z ${CI_MERGE_REQUEST_REF_PATH+x} ];
then
    echo "Merge request : ${CI_MERGE_REQUEST_REF_PATH}"
    TO_CHECKOUT=${CI_COMMIT_SHA}
else
    echo "${TXT_W}Neither a branch commit nor a merge request?!${TXT_CLEAR}"
    env
fi

TO_CHECKOUT="HEAD"

if command -v pre-commit &> /dev/null; then
    pre-commit run --from-ref origin/master --to-ref ${TO_CHECKOUT}
    RESULT_PRE_COMMIT=$?
    if [ ! ${RESULT_PRE_COMMIT} -eq 0 ]; then
        echo "${TXT_E}Git checkout failed.${TXT_CLEAR}"
   exit ${RESULT_PRE_COMMIT}
    fi
else
    echo "${TXT_W}pre-commit not found: skip running it.${TXT_CLEAR}"
fi

echo "${TXT_S}Pre-commit test done.${TXT_CLEAR}"
