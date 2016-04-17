/*!
 * \file esystest/testcasectrlexception.cpp
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
#include "esystest/testcasectrlexception.h"
#include "esystest/testcaseinfo.h"
#include "esystest/assert.h"
#include "esystest/exception.h"

namespace esystest
{

TestCaseCtrlException::TestCaseCtrlException() : TestCaseCtrl()
{
}

TestCaseCtrlException::~TestCaseCtrlException()
{
}

void TestCaseCtrlException::BeforeTest()
{

}

void TestCaseCtrlException::AfterTest()
{
}

void TestCaseCtrlException::Invoke(TestCaseInfo *cur_test)
{
    bool succeeded = true;
    Exception::ID excep_id = Exception::UNKNOWN;

    assert(cur_test != nullptr);

    try
    {
        cur_test->Invoke();
    }

    catch (const Exception &e)
    {
        succeeded = false;
        excep_id = e.GetId();
    }
    if (succeeded == false)
        cur_test->SetResult(-excep_id);
    else
        cur_test->SetResult(0);

}

void TestCaseCtrlException::Assert()
{
    throw Exception(Exception::TEST_FAILED);
}

}

