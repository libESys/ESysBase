/*!
 * \file test01.cpp
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

#include <esystest/unit_test.h>

#include <iostream>

namespace test_package
{

namespace test_package
{

ESYSTEST_AUTO_TEST_CASE(Test01)
{
    bool test_bool = true;
    ESYSTEST_REQUIRE_EQUAL(test_bool, true);
}

} // namespace test_package

} // namespace test_package
