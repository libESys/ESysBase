/*!
 * \file esys/base/version.h
 * \brief Version info for esysbase
 *
 * \cond
 * __legal_b__
 *
 * __legal_e__
 * \endcond
 *
 */

#pragma once

// Bump-up with each new version
#define ESYSBASE_MAJOR_VERSION 0
#define ESYSBASE_MINOR_VERSION 1
#define ESYSBASE_RELEASE_NUMBER 0
#define ESYSBASE_VERSION_STRING "ESysBase 0.1.0"

// Must be updated manually as well each time the version above changes
#define ESYSBASE_VERSION_NUM_DOT_STRING "0.1.0"
#define ESYSBASE_VERSION_NUM_STRING "0100"

// nothing should be updated below this line when updating the version

#define ESYSBASE_VERSION_NUMBER \
    (ESYSBASE_MAJOR_VERSION * 1000) + (ESYSBASE_MINOR_VERSION * 100) + ESYSBASE_RELEASE_NUMBER
#define ESYSBASE_BETA_NUMBER 1
#define ESYSBASE_VERSION_FLOAT                                                                   \
    ESYSBASE_MAJOR_VERSION + (ESYSBASE_MINOR_VERSION / 10.0) + (ESYSBASE_RELEASE_NUMBER / 100.0) \
        + (ESYSBASE_BETA_NUMBER / 10000.0)

// check if the current version is at least major.minor.release
#define ESYSBASE_CHECK_VERSION(major, minor, release)                                                            \
    (ESYSBASE_MAJOR_VERSION > (major) || (ESYSBASE_MAJOR_VERSION == (major) && ESYSBASE_MINOR_VERSION > (minor)) \
     || (ESYSBASE_MAJOR_VERSION == (major) && ESYSBASE_MINOR_VERSION == (minor)                                  \
         && ESYSBASE_RELEASE_NUMBER >= (release)))
