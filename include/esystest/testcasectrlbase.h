/*!
 * \file esystest/testcasectrlbase.h
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

#ifndef __ESYSTEST_TESTCASECTRLBASE_H__
#define __ESYSTEST_TESTCASECTRLBASE_H__

#include "esystest/esystest_defs.h"
#include <esys/inttypes.h>

namespace esystest
{

class ESYSTEST_API TestCaseInfo;

class ESYSTEST_API TestCaseCtrlBase
{
public:
    TestCaseCtrlBase();
    virtual ~TestCaseCtrlBase();

    virtual esys::int32_t Init() = 0;

    virtual void BeforeTest() = 0;
    virtual void AfterTest() = 0;
    virtual void Invoke(TestCaseInfo *cur_test) = 0;
    virtual void Assert() = 0;

    void RunOneTest(char *name);
    bool GetRunAll();
    char *GetTestToRun();

    void PrintList();

    static TestCaseCtrlBase *Get();
    static void Set(TestCaseCtrlBase *);

protected:
    static TestCaseCtrlBase *s_ctrl;

    bool m_run_all;
    char m_test_case_name[50];
};

}

#endif



