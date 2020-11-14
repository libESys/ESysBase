/*!
 * \file esys/base/test/version.h
 * \brief Version info for esysbase_t
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
#define ESYSBASE_T_MAJOR_VERSION 0
#define ESYSBASE_T_MINOR_VERSION 0
#define ESYSBASE_T_RELEASE_NUMBER 1
#define ESYSBASE_T_VERSION_STRING "esysbase_t 0.0.1"

// Must be updated manually as well each time the version above changes
#define ESYSBASE_T_VERSION_NUM_DOT_STRING "0.0.1"
#define ESYSBASE_T_VERSION_NUM_STRING "0001"

// nothing should be updated below this line when updating the version

#define ESYSBASE_T_VERSION_NUMBER \
    (ESYSBASE_T_MAJOR_VERSION * 1000) + (ESYSBASE_T_MINOR_VERSION * 100) + ESYSBASE_T_RELEASE_NUMBER
#define ESYSBASE_T_BETA_NUMBER 1
#define ESYSBASE_T_VERSION_FLOAT                                                                       \
    ESYSBASE_T_MAJOR_VERSION + (ESYSBASE_T_MINOR_VERSION / 10.0) + (ESYSBASE_T_RELEASE_NUMBER / 100.0) \
        + (ESYSBASE_T_BETA_NUMBER / 10000.0)

// check if the current version is at least major.minor.release
#define ESYSBASE_T_CHECK_VERSION(major, minor, release)                                                                \
    (ESYSBASE_T_MAJOR_VERSION > (major) || (ESYSBASE_T_MAJOR_VERSION == (major) && ESYSBASE_T_MINOR_VERSION > (minor)) \
     || (ESYSBASE_T_MAJOR_VERSION == (major) && ESYSBASE_T_MINOR_VERSION == (minor)                                    \
         && ESYSBASE_T_RELEASE_NUMBER >= (release)))
