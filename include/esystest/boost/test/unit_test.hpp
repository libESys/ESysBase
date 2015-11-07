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

#define BOOST_FIXTURE_TEST_CASE_WITH_DECOR( test_name, F, decorators )  \
class test_name ## Info : public esystest::TestCaseInfo					\
{																		\
public:																	\
	test_name ## Info()													\
		: esystest::TestCaseInfo(#test_name,__FILE__, __LINE__)			\
	{}																	\
	virtual ~ ## test_name ## Info();									\					
	virtual void Invoke();												\
 };																		\
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
    boost::unit_test::decorator::collector::instance() )                \
/**/

#define BOOST_AUTO_TEST_CASE_NO_DECOR( test_name )                      \
    BOOST_FIXTURE_TEST_CASE_NO_DECOR( test_name,                        \
        nullptr /*BOOST_AUTO_TEST_CASE_FIXTURE*/ )                                  \
/**/

#define BOOST_AUTO_TEST_CASE( test_name )                               \
    BOOST_AUTO_TEST_CASE_NO_DECOR( test_name )                          \
/**/

namespace esystest
{
}

#ifdef BOOST_TEST_MAIN 
int main(int argc, char *argv[])
{
    return 0;
}
#endif

#endif
