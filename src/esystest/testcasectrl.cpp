/*!
 * \file esystest/testcasectrl.cpp
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

#include "esystest/esystest_prec.h"
#include "esystest/testcasectrl.h"

#include <string.h>

namespace esystest
{

TestCaseCtrl *TestCaseCtrl::s_ctrl = nullptr;

TestCaseCtrl *TestCaseCtrl::Get()
{
    return s_ctrl;
}

void TestCaseCtrl::Set(TestCaseCtrl *ctrl)
{
    s_ctrl = ctrl;
}


TestCaseCtrl::TestCaseCtrl(): m_run_all(true)
{
}

TestCaseCtrl::~TestCaseCtrl()
{
}

void TestCaseCtrl::RunOneTest(char *name)
{
    m_run_all = false;
    strcpy(m_test_case_name, name);
}

bool TestCaseCtrl::GetRunAll()
{
    return m_run_all;
}

char *TestCaseCtrl::GetTestToRun()
{
    return m_test_case_name;
}

}





