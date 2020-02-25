/*!
 * \file esystest/boost/test/unit_test.hpp
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

#include "esystest/esystest_defs.h"
#include "esystest/unit_test.h"

/*#include "esystest/testcaseinfo.h"
#include "esystest/testcase.h"
#include "esystest/testsuite.h"
#include "esystest/globalfixture.h"
#include "esystest/report.h"
#include "esystest/types.h"
#include "esystest/order.h" */

#define BOOST_FIXTURE_TEST_CASE_WITH_DECOR(test_name, F, decorators) \
    ESYSTEST_FIXTURE_TEST_CASE_WITH_DECOR(test_name, F, decorators)

#define BOOST_FIXTURE_TEST_CASE_NO_DECOR(test_name, F) ESYSTEST_FIXTURE_TEST_CASE_NO_DECOR(test_name, F)

#define BOOST_AUTO_TEST_CASE_NO_DECOR(test_name) ESYSTEST_AUTO_TEST_CASE_NO_DECOR(test_name)

#define BOOST_AUTO_TEST_CASE(test_name) ESYSTEST_AUTO_TEST_CASE(test_name)

#define BOOST_FIXTURE_TEST_CASE(test_name, F) ESYSTEST_FIXTURE_TEST_CASE(test_name, F)

#define BOOST_WARN(P) ESYSTEST_WARN(P)
#define BOOST_CHECK(P) ESYSTEST_CHECK(P)
#define BOOST_REQUIRE(P) ESYSTEST_REQUIRE(P)

#define BOOST_WARN_EQUAL(L, R) ESYSTEST_WARN_EQUAL(L, R)
#define BOOST_CHECK_EQUAL(L, R) ESYSTEST_CHECK_EQUAL(L, R)
#define BOOST_REQUIRE_EQUAL(L, R) ESYSTEST_REQUIRE_EQUAL(L, R)

#define BOOST_WARN_NE(L, R) ESYSTEST_WARN_NE(L, R)
#define BOOST_CHECK_NE(L, R) ESYSTEST_CHECK_NE(L, R)
#define BOOST_REQUIRE_NE(L, R) ESYSTEST_REQUIRE_NE(L, R)

#define BOOST_WARN_LT(L, R) ESYSTEST_WARN_LT(L, R)
#define BOOST_CHECK_LT(L, R) ESYSTEST_CHECK_LT(L, R)
#define BOOST_REQUIRE_LT(L, R) ESYSTEST_REQUIRE_LT(L, R)

#define BOOST_WARN_LE(L, R) ESYSTEST_WARN_LE(L, R)
#define BOOST_CHECK_LE(L, R) ESYSTEST_CHECK_LE(L, R)
#define BOOST_REQUIRE_LE(L, R) ESYSTEST_REQUIRE_LE(L, R)

#define BOOST_WARN_GT(L, R) ESYSTEST_WARN_GT(L, R)
#define BOOST_CHECK_GT(L, R) ESYSTEST_CHECK_GT(L, R)
#define BOOST_REQUIRE_GT(L, R) ESYSTEST_REQUIRE_GT(L, R)

#define BOOST_WARN_GE(L, R) ESYSTEST_WARN_GE(L, R)
#define BOOST_CHECK_GE(L, R) ESYSTEST_CHECK_GE(L, R)
#define BOOST_REQUIRE_GE(L, R) ESYSTEST_REQUIRE_GE(L, R)

#define BOOST_GLOBAL_FIXTURE(F) ESYSTEST_GLOBAL_FIXTURE(F)

#ifdef BOOST_TEST_MAIN
#define ESYSTEST_TEST_MAIN
#endif

#include "esystest/unit_test.h"
