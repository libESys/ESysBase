/*!
 * \file esystest/boost/unit_test.h
 * \brief ESysTest a wrapper of Boost
 *
 * \cond
 * __legal_b__
 *
 * Copyright (c) 2016-2018 Michel Gillet
 * Distributed under the wxWindows Library Licence, Version 3.1.
 * (See accompanying file LICENSE_3_1.txt or
 * copy at http://www.wxwidgets.org/about/licence)
 *
 * __legal_e__
 * \endcond
 *
 */

#pragma once

#ifdef ESYSTEST_TEST_MAIN
#ifndef BOOST_TEST_MAIN
#define BOOST_TEST_MAIN
#endif
#endif

#ifdef _MSC_VER
#pragma warning (disable : 4996)
#pragma warning (disable : 4985)
#endif

#include <boost/test/unit_test.hpp>

#ifdef _MSC_VER
#pragma warning (default : 4996)
#pragma warning (default : 4985)
#endif

#define ESYSTEST_FIXTURE_TEST_CASE( test_name, F )              \
     BOOST_FIXTURE_TEST_CASE( test_name, F )                \
/**/

#define ESYSTEST_AUTO_TEST_CASE( test_name ) \
    BOOST_AUTO_TEST_CASE( test_name) \
/**/

#define ESYSTEST_AUTO_TEST_CASE_WITH_DECOR( test_name, decorators) \
    BOOST_AUTO_TEST_CASE_WITH_DECOR( test_name, decorators) \
/**/

#define ESYSTEST_FIXTURE_TEST_CASE_WITH_DECOR( test_name, fixture, decorators) \
    BOOST_FIXTURE_TEST_CASE_WITH_DECOR( test_name, fixture, decorators) \
/**/

#define ESYSTEST_WARN_EQUAL( L, R ) BOOST_WARN_EQUAL( L, R )
#define ESYSTEST_CHECK_EQUAL( L, R ) BOOST_CHECK_EQUAL( L, R )
#define ESYSTEST_REQUIRE_EQUAL( L, R ) BOOST_REQUIRE_EQUAL( L, R )

#define ESYSTEST_WARN_NE( L, R ) BOOST_WARN_NE( L, R )
#define ESYSTEST_CHECK_NE( L, R ) BOOST_CHECK_NE( L, R )
#define ESYSTEST_REQUIRE_NE( L, R ) BOOST_REQUIRE_NE( L, R )

#define ESYSTEST_WARN_LT( L, R ) BOOST_WARN_LT( L, R )
#define ESYSTEST_CHECK_LT( L, R ) BOOST_CHECK_LT( L, R )
#define ESYSTEST_REQUIRE_LT( L, R ) BOOST_REQUIRE_LT( L, R )

#define ESYSTEST_WARN_LE( L, R ) BOOST_WARN_LE( L, R )
#define ESYSTEST_CHECK_LE( L, R ) BOOST_CHECK_LE( L, R )
#define ESYSTEST_REQUIRE_LE( L, R ) BOOST_REQUIRE_LE( L, R )

#define ESYSTEST_WARN_GT( L, R ) BOOST_WARN_GT( L, R )
#define ESYSTEST_CHECK_GT( L, R ) BOOST_CHECK_GT( L, R )
#define ESYSTEST_REQUIRE_GT( L, R ) BOOST_REQUIRE_GT( L, R )

#define ESYSTEST_WARN_GE( L, R ) BOOST_WARN_GE( L, R )
#define ESYSTEST_CHECK_GE( L, R ) BOOST_CHECK_GE( L, R )
#define ESYSTEST_REQUIRE_GE( L, R ) BOOST_REQUIRE_GE( L, R )

#define ESYSTEST_WARN( C ) BOOST_WARN( C )
#define ESYSTEST_CHECK( C ) BOOST_CHECK( C )
#define ESYSTEST_REQUIRE( C ) BOOST_REQUIRE( C )

// MT version
#ifdef ESYSTEST_USE_ESYS
#define ESYSTEST_LOCK ::esys::MutexLocker lock( esystest::MasterTestSuite::Get().GetMutex())
#else
#define ESYSTEST_LOCK
#endif

#define ESYSTEST_MT_WARN_EQUAL( L, R ) \
    { \
        ESYSTEST_LOCK; \
        ESYSTEST_WARN_EQUAL( L, R ); \
    }

#define ESYSTEST_MT_CHECK_EQUAL( L, R ) \
    { \
        ESYSTEST_LOCK; \
        ESYSTEST_CHECK_EQUAL( L, R ); \
    }

#define ESYSTEST_MT_REQUIRE_EQUAL( L, R ) \
    { \
        ESYSTEST_LOCK; \
        ESYSTEST_REQUIRE_EQUAL( L, R ); \
    }

#define ESYSTEST_MT_WARN_NE( L, R ) \
    { \
        ESYSTEST_LOCK; \
        ESYSTEST_WARN_NE(L, R); \
    }

#define ESYSTEST_MT_CHECK_NE( L, R ) \
    { \
        ESYSTEST_LOCK; \
        ESYSTEST_CHECK_NE(L, R); \
    }

#define ESYSTEST_MT_REQUIRE_NE( L, R ) \
    { \
        ESYSTEST_LOCK; \
        ESYSTEST_REQUIRE_NE(L, R); \
    }

#define ESYSTEST_MT_WARN_LT( L, R ) \
    { \
        ESYSTEST_LOCK; \
        ESYSTEST_WARN_LT(L, R); \
    }


#define ESYSTEST_MT_CHECK_LT( L, R ) \
    { \
        ESYSTEST_LOCK; \
        ESYSTEST_CHECK_LT(L, R); \
    }

#define ESYSTEST_MT_REQUIRE_LT( L, R ) \
    { \
        ESYSTEST_LOCK; \
        ESYSTEST_REQUIRE_LT(L, R); \
    }

#define ESYSTEST_MT_WARN_LE( L, R ) \
    { \
        ESYSTEST_LOCK; \
        ESYSTEST_WARN_LE(L, R); \
    }

#define ESYSTEST_MT_CHECK_LE( L, R ) \
    { \
        ESYSTEST_LOCK; \
        ESYSTEST_CHECK_LE(L, R); \
    }

#define ESYSTEST_MT_REQUIRE_LE( L, R ) \
    { \
        ESYSTEST_LOCK; \
        ESYSTEST_REQUIRE_LE(L, R); \
    }

#define ESYSTEST_MT_WARN_GT( L, R ) \
    { \
        ESYSTEST_LOCK; \
        ESYSTEST_WARN_GT(L, R); \
    }

#define ESYSTEST_MT_CHECK_GT( L, R ) \
    { \
        ESYSTEST_LOCK; \
        ESYSTEST_CHECK_GT(L, R); \
    }

#define ESYSTEST_MT_REQUIRE_GT( L, R ) \
    { \
        ESYSTEST_LOCK; \
        ESYSTEST_REQUIRE_GT(L, R); \
    }

#define ESYSTEST_MT_WARN_GE( L, R ) \
    { \
        ESYSTEST_LOCK; \
        ESYSTEST_WARN_GE(L, R); \
    }

#define ESYSTEST_MT_CHECK_GE( L, R ) \
    { \
        ESYSTEST_LOCK; \
        ESYSTEST_CHECK_GE(L, R); \
    }

#define ESYSTEST_MT_REQUIRE_GE( L, R ) \
    { \
        ESYSTEST_LOCK; \
        ESYSTEST_REQUIRE_GE(L, R); \
    }

#define ESYSTEST_MT_WARN( C ) \
        { \
                ESYSTEST_LOCK; \
                ESYSTEST_WARN(C); \
        }

#define ESYSTEST_MT_CHECK( C ) \
        { \
                ESYSTEST_LOCK; \
                ESYSTEST_REQUIRE(C); \
        }

#define ESYSTEST_MT_REQUIRE( C ) \
        { \
                ESYSTEST_LOCK; \
                ESYSTEST_REQUIRE(C); \
        }

#define ESYSTEST_GLOBAL_FIXTURE( F ) \
BOOST_GLOBAL_FIXTURE( F ) \
/**/

#include "esystest/boost/esystest.h"


