/*!
 * \file esystest/boost/test/unit_test.hpp
 * \brief Version info for esystest
 *
 * \cond
 *__legal_b__
 *
 *__legal_e__
 * \endcond
 *
 */

#ifndef __ESYSTEST_BOOST_TEST_UNIT_TEST_HPP__
#define __ESYSTEST_BOOST_TEST_UNIT_TEST_HPP__

#include "esystest/testcaseinfo.h"
#include "esystest/testcase.h"
#include "esystest/testsuite.h"

namespace esystest
{

enum ToolLevel 
{
	WARN, CHECK, REQUIRE, PASS
};

enum CheckType 
{
	CHECK_PRED,
	CHECK_MSG,
	CHECK_EQUAL,
	CHECK_NE,
	CHECK_LT,
	CHECK_LE,
	CHECK_GT,
	CHECK_GE,
	CHECK_CLOSE,
	CHECK_CLOSE_FRACTION,
	CHECK_SMALL,
	CHECK_BITWISE_EQUAL,
	CHECK_PRED_WITH_ARGS,
	CHECK_EQUAL_COLL,
	CHECK_BUILT_ASSERTION
};

}

#define BOOST_FIXTURE_TEST_CASE_WITH_DECOR( test_name, F, decorators )  \
class test_name ## Info : public esystest::TestCaseInfo					\
{																		\
public:																	\
	test_name ## Info()													\
		: esystest::TestCaseInfo(#test_name,__FILE__, __LINE__)			\
	{																	\
		esystest::TestSuite *test_suite;								\
		test_suite=esystest::TestSuite::GetCurrent();					\
		test_suite->AddTest(this);										\
	}																	\
	virtual ~ ## test_name ## Info() {}									\
	virtual void Invoke();												\
	static test_name ## Info g_test_case_info;							\
 };																		\
                                                                        \
test_name ## Info test_name ## Info::g_test_case_info;					\
																		\
class test_name : public F, public esystest::TestCase					\
{																		\
public:																	\
	test_name() : F(), esystest::TestCase() {}							\
	virtual ~test_name() {}												\
	virtual void TestMethod();											\
protected:																\
	static test_name##Info g_info;										\
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

template <typename L, typename R, typename P>
void boost_test_tool_impl(const L &left, const R &right, const P &p, const char *file, int line)
{
	bool result;

	result = p(left, right);
}

template<typename L, typename R>
void boost_require_equal(const L &left, const R &right, const char *file, int line)
{	
	boost_test_tool_impl(left, right, equal_impl_frwd(), file, line);
}

}

#define BOOST_TEST_TOOL_IMPL( frwd_type, P, assertion_descr, TL, CT, L, R )     \
	::esystest::boost_test_tool_impl(L, R, P ## (),__FILE__, __LINE__);
/**/

#define BOOST_WARN_EQUAL( L, R )            BOOST_TEST_TOOL_IMPL( 0, \
    ::esystest::equal_impl_frwd, "", WARN, CHECK_EQUAL, (L), (R) )
#define BOOST_CHECK_EQUAL( L, R )           BOOST_TEST_TOOL_IMPL( 0, \
    ::esystest::equal_impl_frwd, "", CHECK, CHECK_EQUAL, (L), (R) )
#define BOOST_REQUIRE_EQUAL( L, R )         BOOST_TEST_TOOL_IMPL( 0, \
    ::esystest::equal_impl_frwd, "", REQUIRE, CHECK_EQUAL, (L), (R) )

namespace esystest
{

struct nil_t {};



}

#ifdef BOOST_TEST_MAIN 
int main(int argc, char *argv[])
{
    return 0;
}
#endif

#endif
