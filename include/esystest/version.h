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

#include "esystest/esystest_defs.h"

// Don't bump-up manually, this is done automatically with the tool Commitizen
#define ESYSTEST_VERSION_NUM_DOT_STRING "0.0.1"
#define ESYSTEST_VERSION_STRING "ESysTest 0.0.1"

// check if the current version is at least major.minor.release
#define ESYSTEST_CHECK_VERSION(major, minor, release)                                                            \
    (ESYSTEST_MAJOR_VERSION > (major) || (ESYSTEST_MAJOR_VERSION == (major) && ESYSTEST_MINOR_VERSION > (minor)) \
     || (ESYSTEST_MAJOR_VERSION == (major) && ESYSTEST_MINOR_VERSION == (minor)                                  \
         && ESYSTEST_RELEASE_NUMBER >= (release)))

namespace esystest
{

ESYSTEST_API int get_major_version();
ESYSTEST_API int get_minor_version();
ESYSTEST_API int get_patch_version();

ESYSTEST_API bool check_version(int major, int minor, int patch = -1);
ESYSTEST_API bool check_version(const char *version, int major, int minor, int patch = -1);

ESYSTEST_API int get_int_till_dot(const char *str, int skip_dot = 0, bool till_end_str = false);
} // namespace esystest
