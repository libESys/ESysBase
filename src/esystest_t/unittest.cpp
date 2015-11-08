/*!
 * \file esystest_t/unittest.cpp
 * \brief
 *
 * \cond
 * __legal_b__
 *
 * Copyright (c) 2015 Michel Gillet
 * Distributed under the wxWindows Library Licence, Version 3.1.
 * (See accompanying file LICENSE_3_1.txt or
 * copy at http://www.wxwidgets.org/about/licence)
 *
 * __legal_e__
 * \endcond
 *
 */

//#define BOOST_TEST_MAIN

#ifdef WIN32
#include <vld.h>
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

#include <esystest/testsuite.h>

int main(int argc, char *argv[])
{
	esystest::TestSuite *master;

	master = esystest::TestSuite::GetMaster();
	master->RunTestCases();

	return 0;
}
