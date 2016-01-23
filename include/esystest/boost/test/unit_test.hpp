/*!
 * \file esystest/boost/test/unit_test.hpp
 * \brief Version info for esystest
 *
 * \cond
 *__legal_b__
 *
 * Copyright (c) 2015 Michel Gillet
 * Distributed under the wxWindows Library Licence, Version 3.1.
 * (See accompanying file LICENSE_3_1.txt or
 * copy at http://www.wxwidgets.org/about/licence)
 *
 *__legal_e__
 * \endcond
 *
 */

#ifndef __ESYSTEST_BOOST_TEST_UNIT_TEST_HPP__
#define __ESYSTEST_BOOST_TEST_UNIT_TEST_HPP__

#include "esystest/esystest_defs.h"
#include "esystest/testcaseinfo.h"
#include "esystest/testcase.h"
#include "esystest/testsuite.h"
#include "esystest/globalfixture.h"
#include "esystest/report.h"

#define BOOST_FIXTURE_TEST_CASE_WITH_DECOR( test_name, F, decorators )  \
class test_name ## Info : public esystest::TestCaseInfo					\
{																		\
public:																	\
	test_name ## Info()													\
		: esystest::TestCaseInfo(#test_name,__FILE__, __LINE__)			\
	{																	\
		esystest::TestSuite *test_suite;								\
		test_suite=esystest::TestSuite::GetCurrent();					\
        SetSuite(test_suite);                                           \
	}																	\
	virtual ~ test_name ## Info() {}									\
	virtual void Invoke();												\
 };																		\
                                                                        \
test_name ## Info g_test_case_ ## test_name ## _info;					\
																		\
class test_name : public F, public esystest::TestCase					\
{																		\
public:																	\
	test_name() : F(), esystest::TestCase() {}							\
	virtual ~test_name() {}												\
	virtual void TestMethod();											\
protected:																\
};																		\
																		\
void test_name##Info::Invoke()											\
{																		\
	test_name test;														\
	test.TestMethod();													\
}																		\
																		\
void test_name::TestMethod()											\
/**/

#define BOOST_FIXTURE_TEST_CASE_NO_DECOR( test_name, F )                \
BOOST_FIXTURE_TEST_CASE_WITH_DECOR( test_name, F,                       \
    ::esystest::nil_t )													\
/**/

#define BOOST_AUTO_TEST_CASE_NO_DECOR( test_name )                      \
    BOOST_FIXTURE_TEST_CASE_NO_DECOR( test_name,                        \
        ::esystest::nil_t )												\
/**/

#define BOOST_AUTO_TEST_CASE( test_name )                               \
    BOOST_AUTO_TEST_CASE_NO_DECOR( test_name )                          \
/**/

#define BOOST_FIXTURE_TEST_CASE( test_name, F )                         \
     BOOST_FIXTURE_TEST_CASE_NO_DECOR(test_name, F)                     \
/**/

namespace esystest
{

template <class Left, class Right>
inline bool equal_impl(Left const& left, Right const& right)
{
	return left == right;
}

struct equal_impl_frwd {
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

struct ne_impl {
	template <class Left, class Right>
	bool operator()(Left const& left, Right const& right) const
	{
		return !equal_impl_frwd()(left, right);
	}
};

struct lt_impl {
	template <class Left, class Right>
	bool operator()(Left const& left, Right const& right) const
	{
		return left < right;
	}
};

struct le_impl {
	template <class Left, class Right>
	bool operator()(Left const& left, Right const& right) const
	{
		return left <= right;
	}
};

struct gt_impl {
	template <class Left, class Right>
	bool operator()(Left const& left, Right const& right) const
	{
		return left > right;
	}
};

struct ge_impl {
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

#define BOOST_TEST_TOOL_IMPL( frwd_type, P, assertion_descr, TL, CT, L, R )     \
    { \
	bool esystest_result=::esystest::boost_test_tool_impl(L, R, P,__FILE__, __LINE__); \
    ::esystest::report_assertion(esystest_result, __FILE__, __LINE__, TL, CT); \
    }
/**/

#define BOOST_WARN_EQUAL( L, R )            BOOST_TEST_TOOL_IMPL( 0, \
    ::esystest::equal_impl_frwd(), "", ::esystest::WARN, ::esystest::CHECK_EQUAL, (L), (R) )
#define BOOST_CHECK_EQUAL( L, R )           BOOST_TEST_TOOL_IMPL( 0, \
    ::esystest::equal_impl_frwd(), "", ::esystest::CHECK, ::esystest::CHECK_EQUAL, (L), (R) )
#define BOOST_REQUIRE_EQUAL( L, R )         BOOST_TEST_TOOL_IMPL( 0, \
    ::esystest::equal_impl_frwd(), "", ::esystest::REQUIRE, ::esystest::CHECK_EQUAL, (L), (R) )

#define BOOST_WARN_NE( L, R )               BOOST_TEST_TOOL_IMPL( 0, \
    ::esystest::ne_impl(), "", ::esystest::WARN, ::esystest::CHECK_NE, (L), (R) )
#define BOOST_CHECK_NE( L, R )              BOOST_TEST_TOOL_IMPL( 0, \
    ::esystest::ne_impl(), "", ::esystest::CHECK, ::esystest::CHECK_NE, (L), (R) )
#define BOOST_REQUIRE_NE( L, R )            BOOST_TEST_TOOL_IMPL( 0, \
    ::esystest::ne_impl(), "", ::esystest::REQUIRE, ::esystest::CHECK_NE, (L), (R) )

#define BOOST_WARN_LT( L, R )               BOOST_TEST_TOOL_IMPL( 0, \
    ::esystest::lt_impl(), "", ::esystest::WARN, ::esystest::CHECK_LT, (L), (R) )
#define BOOST_CHECK_LT( L, R )              BOOST_TEST_TOOL_IMPL( 0, \
    ::esystest::lt_impl(), "", ::esystest::CHECK, ::esystest::CHECK_LT, (L), (R) )
#define BOOST_REQUIRE_LT( L, R )            BOOST_TEST_TOOL_IMPL( 0, \
    ::esystest::lt_impl(), "", ::esystest::REQUIRE, ::esystest::CHECK_LT, (L), (R) )

#define BOOST_WARN_LE( L, R )               BOOST_TEST_TOOL_IMPL( 0, \
    ::esystest::le_impl(), "", ::esystest::WARN, ::esystest::CHECK_LE, (L), (R) )
#define BOOST_CHECK_LE( L, R )              BOOST_TEST_TOOL_IMPL( 0, \
    ::esystest::le_impl(), "", ::esystest::CHECK, ::esystest::CHECK_LE, (L), (R) )
#define BOOST_REQUIRE_LE( L, R )            BOOST_TEST_TOOL_IMPL( 0, \
    ::esystest::le_impl(), "", ::esystest::REQUIRE, ::esystest::CHECK_LE, (L), (R) )

#define BOOST_WARN_GT( L, R )               BOOST_TEST_TOOL_IMPL( 0, \
    ::esystest::gt_impl(), "", ::esystest::WARN, ::esystest::CHECK_GT, (L), (R) )
#define BOOST_CHECK_GT( L, R )              BOOST_TEST_TOOL_IMPL( 0, \
    ::esystest::gt_impl(), "", ::esystest::CHECK, ::esystest::CHECK_GT, (L), (R) )
#define BOOST_REQUIRE_GT( L, R )            BOOST_TEST_TOOL_IMPL( 0, \
    ::esystest::gt_impl(), "", ::esystest::REQUIRE, ::esystest::CHECK_GT, (L), (R) )

#define BOOST_WARN_GE( L, R )               BOOST_TEST_TOOL_IMPL( 0, \
    ::esystest::ge_impl(), "", ::esystest::WARN, ::esystest::CHECK_GE, (L), (R) )
#define BOOST_CHECK_GE( L, R )              BOOST_TEST_TOOL_IMPL( 0, \
    ::esystest::ge_impl(), "", ::esystest::CHECK, ::esystest::CHECK_GE, (L), (R) )
#define BOOST_REQUIRE_GE( L, R )            BOOST_TEST_TOOL_IMPL( 0, \
    ::esystest::ge_impl(), "", ::esystest::REQUIRE, ::esystest::CHECK_GE, (L), (R) )

#define BOOST_GLOBAL_FIXTURE( F ) \
::esystest::GlobalFixture_t<F> g_ ## gf ## F \
/**/

namespace esystest
{

struct nil_t {};



}

#ifdef BOOST_TEST_MAIN 
int main(int argc, char *argv[])
{
	esystest::TestSuite *master;

    esystest::TestCaseInfo::Populate();

	master = esystest::TestSuite::GetMaster();
    master->SetCommandLine(argc, argv);
	master->RunTestCases();

	return 0;
}
#endif

#endif
