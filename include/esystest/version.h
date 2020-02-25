/*!
 * \file esystest/version.h
 * \brief Version info for esystest
 *
 * \cond
 * __legal_b__
 *
 * Copyright (c) 2015-2020 Michel Gillet
 * Distributed under the wxWindows Library Licence, Version 3.1.
 * (See accompanying file LICENSE_3_1.txt or
 * copy at http://www.wxwidgets.org/about/licence)
 *
 * __legal_e__
 * \endcond
 *
 */

#pragma once

// Bump-up with each new version
#define ESYSTEST_MAJOR_VERSION 0
#define ESYSTEST_MINOR_VERSION 0
#define ESYSTEST_RELEASE_NUMBER 1
#define ESYSTEST_VERSION_STRING "esystest 0.0.1"

// Must be updated manually as well each time the version above changes
#define ESYSTEST_VERSION_NUM_DOT_STRING "0.0.1"
#define ESYSTEST_VERSION_NUM_STRING "0001"

// nothing should be updated below this line when updating the version

#define ESYSTEST_VERSION_NUMBER \
    (ESYSTEST_MAJOR_VERSION * 1000) + (ESYSTEST_MINOR_VERSION * 100) + ESYSTEST_RELEASE_NUMBER
#define ESYSTEST_BETA_NUMBER 1
#define ESYSTEST_VERSION_FLOAT                                                                   \
    ESYSTEST_MAJOR_VERSION + (ESYSTEST_MINOR_VERSION / 10.0) + (ESYSTEST_RELEASE_NUMBER / 100.0) \
        + (ESYSTEST_BETA_NUMBER / 10000.0)

// check if the current version is at least major.minor.release
#define ESYSTEST_CHECK_VERSION(major, minor, release)                                                            \
    (ESYSTEST_MAJOR_VERSION > (major) || (ESYSTEST_MAJOR_VERSION == (major) && ESYSTEST_MINOR_VERSION > (minor)) \
     || (ESYSTEST_MAJOR_VERSION == (major) && ESYSTEST_MINOR_VERSION == (minor)                                  \
         && ESYSTEST_RELEASE_NUMBER >= (release)))
