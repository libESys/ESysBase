/*!
* \file esystest_t/test03.cpp
* \brief
*
* \cond
* __legal_b__
*
* Copyright (c) 2016 Michel Gillet
* Distributed under the wxWindows Library Licence, Version 3.1.
* (See accompanying file LICENSE_3_1.txt or
* copy at http://www.wxwidgets.org/about/licence)
*
* __legal_e__
* \endcond
*
*/

#include "esystest_t/esystest_t_prec.h"
#include <esys/inttypes.h>

ESYSTEST_AUTO_TEST_CASE(Test03)
{
    int32_t result;

    result = 0;
    ESYSTEST_REQUIRE_EQUAL(0, result);

    ESYSTEST_REQUIRE_NE(1, result);

    ESYSTEST_REQUIRE_EQUAL(1, result);

    ESYSTEST_REQUIRE_LT(-1, result);

}
