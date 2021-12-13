/*!
 * \file esystest_t/version01.cpp
 * \brief
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

#include "esystest_t/esystest_t_prec.h"
//#include <boost/test/unit_test.hpp>
#include <esystest/version.h>

#include <stdlib.h>

#include <iostream>

ESYSTEST_AUTO_TEST_CASE(Version01)
{
    int value = esystest::get_int_till_dot("1.0.0");
    ESYSTEST_REQUIRE_EQUAL(value, 1);

    value = esystest::get_int_till_dot("5.0.0");
    ESYSTEST_REQUIRE_EQUAL(value, 5);

    value = esystest::get_int_till_dot("10.0.0");
    ESYSTEST_REQUIRE_EQUAL(value, 10);

    value = esystest::get_int_till_dot("53.0.0");
    ESYSTEST_REQUIRE_EQUAL(value, 53);

    value = esystest::get_int_till_dot("53.15.0", 1);
    ESYSTEST_REQUIRE_EQUAL(value, 15);

    value = esystest::get_int_till_dot("53.15", 1);
    ESYSTEST_REQUIRE_EQUAL(value, -1);

    value = esystest::get_int_till_dot("53.15", 1, true);
    ESYSTEST_REQUIRE_EQUAL(value, 15);

    value = esystest::get_int_till_dot("53.15.9", 2);
    ESYSTEST_REQUIRE_EQUAL(value, -1);

    value = esystest::get_int_till_dot("53.15.9", 2, true);
    ESYSTEST_REQUIRE_EQUAL(value, 9);

    value = esystest::get_int_till_dot("53.15", 2);
    ESYSTEST_REQUIRE_EQUAL(value, -1);

    value = esystest::get_int_till_dot("53.15", 2, true);
    ESYSTEST_REQUIRE_EQUAL(value, -1);

    bool val_bool = esystest::check_version("1.0.0", 1, 0, 0);
    ESYSTEST_REQUIRE_EQUAL(val_bool, true);

    val_bool = esystest::check_version("1.0", 1, 0);
    ESYSTEST_REQUIRE_EQUAL(val_bool, true);

    val_bool = esystest::check_version("1.0", 2, 0);
    ESYSTEST_REQUIRE_EQUAL(val_bool, false);

    val_bool = esystest::check_version("1.0", 1, 1);
    ESYSTEST_REQUIRE_EQUAL(val_bool, false);

    val_bool = esystest::check_version("1.0", 1, 1);
    ESYSTEST_REQUIRE_EQUAL(val_bool, true);

    int major = esystest::get_major_version();
    int major_test = atoi(ESYSTEST_VERSION_NUM_DOT_STRING);

    ESYSTEST_REQUIRE_EQUAL(major, major_test);
}
