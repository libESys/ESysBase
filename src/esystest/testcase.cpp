/*!
* \file esystest/testcase.h
* \brief
*
* \cond
*__legal_b__
*
*__legal_e__
* \endcond
*
*/

#include "esystest/esystest_prec.h"
#include "esystest/testcase.h"

namespace esystest
{

unsigned int TestCase::g_count = 0;

unsigned int TestCase::GetCount()
{
	return g_count;
}

TestCase::TestCase()
{
	++TestCase::g_count;
}

TestCase::~TestCase()
{
}

}




