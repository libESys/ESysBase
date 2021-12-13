/*!
 * \file esystest/version.cpp
 * \brief Version info for esystest
 *
 * \cond
 * __legal_b__
 *
 * Copyright (c) 2021 Michel Gillet
 * Distributed under the wxWindows Library Licence, Version 3.1.
 * (See accompanying file LICENSE_3_1.txt or
 * copy at http://www.wxwidgets.org/about/licence)
 *
 * __legal_e__
 * \endcond
 *
 */

#include "esystest/esystest_prec.h"
#include "esystest/version.h"

#include <string.h>
#include <stdlib.h>

namespace esystest
{

ESYSTEST_API int get_major_version()
{
    return get_int_till_dot(ESYSTEST_VERSION_NUM_DOT_STRING);
}

ESYSTEST_API int get_minor_version()
{
    return get_int_till_dot(ESYSTEST_VERSION_NUM_DOT_STRING, 1);
}

ESYSTEST_API int get_patch_version()
{
    return get_int_till_dot(ESYSTEST_VERSION_NUM_DOT_STRING, 2, true);
}

ESYSTEST_API bool check_version(int major, int minor, int patch)
{
    return check_version(ESYSTEST_VERSION_NUM_DOT_STRING, major, minor, patch);
}

ESYSTEST_API bool check_version(const char *version, int major, int minor, int patch)
{
    int major_test = get_int_till_dot(version);
    int minor_test = get_int_till_dot(version, 1);
    int patch_test = get_int_till_dot(version, 2, true);

    if (major < 0) return false;
    if (major_test < major) return false;
    if (major_test > major) return true;

    if (minor < 0) return false;
    if (minor_test < minor) return false;
    if (minor_test > minor) return true;

    if ((patch < 0) && (patch_test < 0)) return true;
    if (patch_test >= patch) return true;

    return false;
}

ESYSTEST_API int get_int_till_dot(const char *str, int skip_dot, bool till_end_str)
{
    int idx = 0;
    int value = 0;

    while (skip_dot != 0)
    {
        while ((idx < strlen(str)) && (str[idx] != '.')) ++idx;
        if (str[idx] != '.') return -1;
        ++idx;
        --skip_dot;
    }

    while (idx < strlen(str))
    {
        if (idx > 0) value *= 10;

        if ((str[idx] < '0') || (str[idx] > '9')) return -1;
        value += str[idx] - '0';

        ++idx;

        if (str[idx] == '.')
        {
            return value;
        }
    }
    if (till_end_str) return value;
    return -1;
}

} // namespace esystest
