/*!
 * \file esystest/testcasectrlbase.cpp
 * \brief
 *
 * \cond
 * __legal_b__
 *
 * Copyright (c) 2015-2020 Michel Gillet
 * Distributed under the wxWindows Library Licence, Version 3.1.
 * (See accompanying file LICENSE_3_1.txt or
 * copy at http://www.wxwidgets.org/about/licence)
 *
 * __legal_e__
 * \endcond
 *
 */

#include "esystest/esystest_prec.h"
#include "esystest/testcasectrlbase.h"
#include "esystest/mastertestsuite.h"

#include <cstring>

namespace esystest
{

TestCaseCtrlBase *TestCaseCtrlBase::s_ctrl = nullptr;

TestCaseCtrlBase *TestCaseCtrlBase::Get()
{
    return s_ctrl;
}

void TestCaseCtrlBase::Set(TestCaseCtrlBase *ctrl)
{
    s_ctrl = ctrl;
}

TestCaseCtrlBase::TestCaseCtrlBase()
    : m_run_all(true)
{
    s_ctrl = this;
}

TestCaseCtrlBase::~TestCaseCtrlBase()
{
}

void TestCaseCtrlBase::RunOneTest(char *name)
{
    m_run_all = false;
    strncpy(m_test_case_name, name, NAME_SIZE);
    m_test_case_name[NAME_SIZE] = 0;
}

bool TestCaseCtrlBase::GetRunAll()
{
    return m_run_all;
}

char *TestCaseCtrlBase::GetTestToRun()
{
    return m_test_case_name;
}

void TestCaseCtrlBase::PrintList()
{
    MasterTestSuite::Get().ListTestCases();
}

} // namespace esystest
