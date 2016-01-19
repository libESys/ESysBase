/*!
 * \file esystest/version.h
 * \brief Version info for esystest_t
 *
 * \cond
 *__legal_b__
 * 
 * Copyright (c) 2015-2016 Michel Gillet
 * Distributed under the wxWindows Library Licence, Version 3.1.
 * (See accompanying file LICENSE_3_1.txt or
 * copy at http://www.wxwidgets.org/about/licence)
 *
 *__legal_e__
 * \endcond
 *
 */

#ifndef __ESYSTEST_T_VERSION_H__
#define __ESYSTEST_T_VERSION_H__

// Bump-up with each new version
#define ESYSTEST_T_MAJOR_VERSION    0
#define ESYSTEST_T_MINOR_VERSION    0
#define ESYSTEST_T_RELEASE_NUMBER   1
#define ESYSTEST_T_VERSION_STRING   _T("esystest_t 0.0.1")

// Must be updated manually as well each time the version above changes
#define ESYSTEST_T_VERSION_NUM_DOT_STRING   "0.0.1"
#define ESYSTEST_T_VERSION_NUM_STRING       "0001"

// nothing should be updated below this line when updating the version

#define ESYSTEST_T_VERSION_NUMBER (ESYSTEST_T_MAJOR_VERSION * 1000) + (ESYSTEST_T_MINOR_VERSION * 100) + ESYSTEST_T_RELEASE_NUMBER
#define ESYSTEST_T_BETA_NUMBER      1
#define ESYSTEST_T_VERSION_FLOAT ESYSTEST_T_MAJOR_VERSION + (ESYSTEST_T_MINOR_VERSION/10.0) + (ESYSTEST_T_RELEASE_NUMBER/100.0) + (ESYSTEST_T_BETA_NUMBER/10000.0)

// check if the current version is at least major.minor.release
#define ESYSTEST_T_CHECK_VERSION(major,minor,release) \
    (ESYSTEST_T_MAJOR_VERSION > (major) || \
    (ESYSTEST_T_MAJOR_VERSION == (major) && ESYSTEST_T_MINOR_VERSION > (minor)) || \
    (ESYSTEST_T_MAJOR_VERSION == (major) && ESYSTEST_T_MINOR_VERSION == (minor) && ESYSTEST_T_RELEASE_NUMBER >= (release)))

#endif

