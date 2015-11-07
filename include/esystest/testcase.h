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

#ifndef __ESYSTEST_TESTCASE_H__
#define __ESYSTEST_TESTCASE_H__

#include "esystest/esystest_defs.h"

namespace esystest
{

class ESYSTEST_API TestCase
{
public:
	TestCase();
	virtual ~TestCase();
	
	virtual void TestMethod()=0;
protected:
};

}

#endif


