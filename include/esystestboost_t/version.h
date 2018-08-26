/*!
 * \file esystestboost_t/version.h
 * \brief Version info for esystestboost_t
 *
 * \cond
 *__legal_b__
 *
 * Copyright (c) 2015-2018 Michel Gillet
 * Distributed under the wxWindows Library Licence, Version 3.1.
 * (See accompanying file LICENSE_3_1.txt or
 * copy at http://www.wxwidgets.org/about/licence)
 *
 *__legal_e__
 * \endcond
 *
 */

#pragma once

// Bump-up with each new version
#define ESYSTESTBOOST_T_MAJOR_VERSION    0
#define ESYSTESTBOOST_T_MINOR_VERSION    0
#define ESYSTESTBOOST_T_RELEASE_NUMBER   1
#define ESYSTESTBOOST_T_VERSION_STRING   _T("ESysTestBoost_t 0.0.1")

// Must be updated manually as well each time the version above changes
#define ESYSTESTBOOST_T_VERSION_NUM_DOT_STRING   "0.0.1"
#define ESYSTESTBOOST_T_VERSION_NUM_STRING       "0001"

// nothing should be updated below this line when updating the version

#define ESYSTESTBOOST_T_VERSION_NUMBER (ESYSTESTBOOST_T_MAJOR_VERSION * 1000) + (ESYSTESTBOOST_T_MINOR_VERSION * 100) + ESYSTESTBOOST_T_RELEASE_NUMBER
#define ESYSTESTBOOST_T_BETA_NUMBER      1
#define ESYSTESTBOOST_T_VERSION_FLOAT ESYSTESTBOOST_T_MAJOR_VERSION + (ESYSTESTBOOST_T_MINOR_VERSION/10.0) + (ESYSTESTBOOST_T_RELEASE_NUMBER/100.0) + (ESYSTESTBOOST_T_BETA_NUMBER/10000.0)

// check if the current version is at least major.minor.release
#define ESYSTESTBOOST_T_CHECK_VERSION(major,minor,release) \
    (ESYSTESTBOOST_T_MAJOR_VERSION > (major) || \
    (ESYSTESTBOOST_T_MAJOR_VERSION == (major) && ESYSTESTBOOST_T_MINOR_VERSION > (minor)) || \
    (ESYSTESTBOOST_T_MAJOR_VERSION == (major) && ESYSTESTBOOST_T_MINOR_VERSION == (minor) && ESYSTESTBOOST_T_RELEASE_NUMBER >= (release)))



