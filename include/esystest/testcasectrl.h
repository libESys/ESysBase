/*!
 * \file esystest/testcasectrl.h
 * \brief
 *
 * \cond
 *__legal_b__
 *
 * Copyright (c) 2015-2016 Michel Gillet
 * Distributed under the wxWindows Library Licence, Version 3.1.
 * (See accompanying file LICENSE_3_1.txt or
 * copy at http://www.wxwidgets.org/about/licence)
 *
 *__legal_e__
 * \endcond
 *
 */

#ifndef __ESYSTEST_TESTCASECTRL_H__
#define __ESYSTEST_TESTCASECTRL_H__

#include "esystest/esystest_defs.h"

namespace esystest
{

class ESYSTEST_API TestCaseInfo;

class ESYSTEST_API TestCaseCtrl
{
public:
	TestCaseCtrl();
	virtual ~TestCaseCtrl();

    virtual void BeforeTest() = 0;
    virtual void AfterTest() = 0;
    virtual void Invoke(TestCaseInfo *cur_test) = 0;
    virtual void Assert() = 0;

    static TestCaseCtrl *Get();
    static void Set(TestCaseCtrl *);
protected:
    static TestCaseCtrl *s_ctrl;
};

}

#endif



