/*!
 * \file esystest/esystest/unit_test.h
 * \brief Version info for esystest
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

#include "esystest/esystest_defs.h"
#include "esystest/testcaseinfo.h"
#include "esystest/testcase.h"
#include "esystest/mastertestsuite.h"
#include "esystest/globalfixture.h"
#include "esystest/report.h"
#include "esystest/types.h"
#include "esystest/order.h"
#include "esystest/assert.h"

#ifdef ESYSTEST_USE_ESYS
#include <esys/mutexlocker.h>
#endif

#define ESYSTEST_FIXTURE_TEST_CASE_WITH_DECOR( test_name, F, decorators )  \
class test_name ## Info : public esystest::TestCaseInfo                 \
{                                                                       \
public:                                                                 \
    test_name ## Info()                                                 \
        : esystest::TestCaseInfo(#test_name,__FILE__, __LINE__)         \
    {                                                                   \
        esystest::TestSuite *test_suite;                                \
        test_suite=esystest::TestSuite::GetCurrent();                   \
        SetSuite(test_suite);                                           \
        *this decorators;                                               \
    }                                                                   \
    virtual ~ test_name ## Info() {}                                    \
    virtual void Invoke();                                              \
 };                                                                     \
                                                                        \
test_name ## Info g_test_case_ ## test_name ## _info;                   \
                                                                        \
class test_name : public F, public esystest::TestCase                   \
{                                                                       \
public:                                                                 \
    test_name() : F(), esystest::TestCase() {}                          \
    virtual ~test_name() {}                                             \
    virtual void TestMethod();                                          \
protected:                                                              \
};                                                                      \
                                                                        \
void test_name##Info::Invoke()                                          \
{                                                                       \
    test_name test;                                                     \
    Start();                                                            \
    test.TestMethod();                                                  \
    End();                                                              \
}                                                                       \
                                                                        \
void test_name::TestMethod()                                            \
/**/

#define ESYSTEST_AUTO_TEST_CASE_WITH_DECOR( test_name, decorators )  \
ESYSTEST_FIXTURE_TEST_CASE_WITH_DECOR( test_name, ::esystest::nil_t, decorators) \
/**/

#define ESYSTEST_FIXTURE_TEST_CASE_NO_DECOR( test_name, F )                \
ESYSTEST_FIXTURE_TEST_CASE_WITH_DECOR( test_name, F,                       \
    * ::esystest::nil_t() )                                             \
/**/

#define ESYSTEST_AUTO_TEST_CASE_NO_DECOR( test_name )                      \
    ESYSTEST_FIXTURE_TEST_CASE_NO_DECOR( test_name,                        \
        ::esystest::nil_t )                                             \
/**/

#define ESYSTEST_AUTO_TEST_CASE( test_name )                               \
    ESYSTEST_AUTO_TEST_CASE_NO_DECOR( test_name )                          \
/**/

#define ESYSTEST_FIXTURE_TEST_CASE( test_name, F )                         \
     ESYSTEST_FIXTURE_TEST_CASE_NO_DECOR(test_name, F)                     \
/**/

namespace esystest
{

template <class Left, class Right>
inline bool equal_impl(Left const& left, Right const& right)
{
    return left == right;
}

struct equal_impl_frwd
{
    template <typename Left, typename Right>
    inline bool
    call_impl(Left const& left, Right const& right) const
    {
        return equal_impl(left, right);
    }

    template <typename Left, typename Right>
    inline bool
    operator()(Left const& left, Right const& right) const
    {
        return call_impl(left, right);
    }
};

struct ne_impl
{
    template <class Left, class Right>
    bool operator()(Left const& left, Right const& right) const
    {
        return !equal_impl_frwd()(left, right);
    }
};

struct lt_impl
{
    template <class Left, class Right>
    bool operator()(Left const& left, Right const& right) const
    {
        return left < right;
    }
};

struct le_impl
{
    template <class Left, class Right>
    bool operator()(Left const& left, Right const& right) const
    {
        return left <= right;
    }
};

struct gt_impl
{
    template <class Left, class Right>
    bool operator()(Left const& left, Right const& right) const
    {
        return left > right;
    }
};

struct ge_impl
{
    template <class Left, class Right>
    bool operator()(Left const& left, Right const& right) const
    {
        return left >= right;
    }
};

template <typename L, typename R, typename P>
bool boost_test_tool_impl(const L &left, const R &right, const P &p, const char *file, int line)
{
    bool result;

    result = p(left, right);
    return result;
}

template<typename L, typename R>
bool boost_require_equal(const L &left, const R &right, const char *file, int line)
{
    return boost_test_tool_impl(left, right, equal_impl_frwd(), file, line);
}
}

#define ESYSTEST_TEST_TOOL_IMPL( frwd_type, P, assertion_descr, TL, CT, L, R )     \
    { \
        bool esystest_result=::esystest::boost_test_tool_impl(L, R, P,__FILE__, __LINE__); \
        ::esystest::report_assertion(esystest_result, __FILE__, __LINE__, TL, CT, assertion_descr); \
    }
/**/

#define ESYSTEST_TEST_TOOL_IMPL_P( frwd_type, P, assertion_descr, TL, CT, L, R )     \
    { \
        ::esystest::report_assertion((P), __FILE__, __LINE__, TL, CT, assertion_descr); \
    }
/**/

#define ESYSTEST_WARN( P )                     ESYSTEST_TEST_TOOL_IMPL_P( 2, \
    (P), "", ::esystest::WARN, ::esystest::CHECK_PRED, _, _)
#define ESYSTEST_CHECK( P )                    ESYSTEST_TEST_TOOL_IMPL_P( 2, \
    (P), "", ::esystest::CHECK, ::esystest::CHECK_PRED, _, _ )
#define ESYSTEST_REQUIRE( P )                  ESYSTEST_TEST_TOOL_IMPL_P( 2, \
    (P), "", ::esystest::REQUIRE, ::esystest::CHECK_PRED, _, _ )

#define ESYSTEST_WARN_EQUAL( L, R )            ESYSTEST_TEST_TOOL_IMPL( 0, \
    ::esystest::equal_impl_frwd(), "", ::esystest::WARN, ::esystest::CHECK_EQUAL, (L), (R) )
#define ESYSTEST_CHECK_EQUAL( L, R )           ESYSTEST_TEST_TOOL_IMPL( 0, \
    ::esystest::equal_impl_frwd(), "", ::esystest::CHECK, ::esystest::CHECK_EQUAL, (L), (R) )
#define ESYSTEST_REQUIRE_EQUAL( L, R )         ESYSTEST_TEST_TOOL_IMPL( 0, \
    ::esystest::equal_impl_frwd(), #L " == " #R, ::esystest::REQUIRE, ::esystest::CHECK_EQUAL, (L), (R) )

#define ESYSTEST_WARN_NE( L, R )               ESYSTEST_TEST_TOOL_IMPL( 0, \
    ::esystest::ne_impl(), "", ::esystest::WARN, ::esystest::CHECK_NE, (L), (R) )
#define ESYSTEST_CHECK_NE( L, R )              ESYSTEST_TEST_TOOL_IMPL( 0, \
    ::esystest::ne_impl(), "", ::esystest::CHECK, ::esystest::CHECK_NE, (L), (R) )
#define ESYSTEST_REQUIRE_NE( L, R )            ESYSTEST_TEST_TOOL_IMPL( 0, \
    ::esystest::ne_impl(), "", ::esystest::REQUIRE, ::esystest::CHECK_NE, (L), (R) )

#define ESYSTEST_WARN_LT( L, R )               ESYSTEST_TEST_TOOL_IMPL( 0, \
    ::esystest::lt_impl(), "", ::esystest::WARN, ::esystest::CHECK_LT, (L), (R) )
#define ESYSTEST_CHECK_LT( L, R )              ESYSTEST_TEST_TOOL_IMPL( 0, \
    ::esystest::lt_impl(), "", ::esystest::CHECK, ::esystest::CHECK_LT, (L), (R) )
#define ESYSTEST_REQUIRE_LT( L, R )            ESYSTEST_TEST_TOOL_IMPL( 0, \
    ::esystest::lt_impl(), "", ::esystest::REQUIRE, ::esystest::CHECK_LT, (L), (R) )

#define ESYSTEST_WARN_LE( L, R )               ESYSTEST_TEST_TOOL_IMPL( 0, \
    ::esystest::le_impl(), "", ::esystest::WARN, ::esystest::CHECK_LE, (L), (R) )
#define ESYSTEST_CHECK_LE( L, R )              ESYSTEST_TEST_TOOL_IMPL( 0, \
    ::esystest::le_impl(), "", ::esystest::CHECK, ::esystest::CHECK_LE, (L), (R) )
#define ESYSTEST_REQUIRE_LE( L, R )            ESYSTEST_TEST_TOOL_IMPL( 0, \
    ::esystest::le_impl(), "", ::esystest::REQUIRE, ::esystest::CHECK_LE, (L), (R) )

#define ESYSTEST_WARN_GT( L, R )               ESYSTEST_TEST_TOOL_IMPL( 0, \
    ::esystest::gt_impl(), "", ::esystest::WARN, ::esystest::CHECK_GT, (L), (R) )
#define ESYSTEST_CHECK_GT( L, R )              ESYSTEST_TEST_TOOL_IMPL( 0, \
    ::esystest::gt_impl(), "", ::esystest::CHECK, ::esystest::CHECK_GT, (L), (R) )
#define ESYSTEST_REQUIRE_GT( L, R )            ESYSTEST_TEST_TOOL_IMPL( 0, \
    ::esystest::gt_impl(), "", ::esystest::REQUIRE, ::esystest::CHECK_GT, (L), (R) )

#define ESYSTEST_WARN_GE( L, R )               ESYSTEST_TEST_TOOL_IMPL( 0, \
    ::esystest::ge_impl(), "", ::esystest::WARN, ::esystest::CHECK_GE, (L), (R) )
#define ESYSTEST_CHECK_GE( L, R )              ESYSTEST_TEST_TOOL_IMPL( 0, \
    ::esystest::ge_impl(), "", ::esystest::CHECK, ::esystest::CHECK_GE, (L), (R) )
#define ESYSTEST_REQUIRE_GE( L, R )            ESYSTEST_TEST_TOOL_IMPL( 0, \
    ::esystest::ge_impl(), "", ::esystest::REQUIRE, ::esystest::CHECK_GE, (L), (R) )

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
::esystest::GlobalFixture_t<F> g_ ## gf ## F \
/**/

#ifdef ESYSTEST_USE_ESYS
#define ESYSTEST_TASK_BEGIN \
std::exception_ptr esystest_task_eptr; \
try \
{

#define ESYSTEST_TASK_END \
} \
catch (const Exception &e) \
{ \
    esystest_task_eptr=std::current_exception(); \
    \
}

#else
#endif

#include "esystest/esystest/boost.h"

#ifdef ESYSTEST_TEST_MAIN
int main(int argc, char *argv[])
{
    esystest::MasterTestSuite &master = esystest::MasterTestSuite::Get();

    esystest::TestCaseInfo::Populate();

    master.SetCommandLine(argc, argv);
    master.Sort();
    master.Run();

    return 0;
}
#endif




