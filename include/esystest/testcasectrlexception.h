/*!
 * \file esystest/testcasectrlexception.h
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

#ifndef __ESYSTEST_TESTCASECTRLEXCEPTION_H__
#define __ESYSTEST_TESTCASECTRLEXCEPTION_H__

#include "esystest/esystest_defs.h"
#include "esystest/testcasectrl.h"

#include <string>

namespace esystest
{

class ESYSTEST_API TestCaseCtrlException: public TestCaseCtrl
{
public:
    TestCaseCtrlException();
    virtual ~TestCaseCtrlException();

    virtual esys::int32_t Init() override;

    virtual void BeforeTest();
    virtual void AfterTest();
    virtual void Invoke(TestCaseInfo *cur_test);
    virtual void Assert();
protected:
    std::string m_run_test;
};

}

#endif




