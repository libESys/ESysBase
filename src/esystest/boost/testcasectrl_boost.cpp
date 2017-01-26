/*!
 * \file esystest/boost/testcasectrl.cpp
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
#include "esystest/boost/testcasectrl.h"
#include "esystest/testcaseinfo.h"
#include "esystest/mastertestsuite.h"
#include "esystest/exception.h"
#include "esystest/assert.h"

#include <string.h>
#include <iostream>

#include <boost/program_options/cmdline.hpp>
#include <boost/program_options/parsers.hpp>

namespace esystest
{

namespace boost
{

TestCaseCtrl::TestCaseCtrl()
    : TestCaseCtrlBase(), m_desc("ESysTest options"), m_is_parsed(false)
    , m_verbose(-1), m_log_trace(false)
{
}

TestCaseCtrl::~TestCaseCtrl()
{
}

int32_t TestCaseCtrl::Init()
{
    m_desc.add_options()
        ("help", "produce help message")
        ("run_test", po::value<std::string>(&m_run_test), "give the name of the test to run")
        ("list", "list all unit tests")
        ;

    AddOptions(m_desc);

    return Parse();
}

void TestCaseCtrl::BeforeTest()
{

}

void TestCaseCtrl::AfterTest()
{
}

void TestCaseCtrl::Invoke(TestCaseInfo *cur_test)
{
    bool succeeded = true;
    bool run_test = true;
    Exception::ID excep_id = Exception::UNKNOWN;

    assert(cur_test != nullptr);

    if (GetRunAll() == false)
    {
        if (strcmp(GetTestToRun(), cur_test->GetName()) != 0)
            run_test = false;
    }

    if (run_test == true)
    {
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
    else
        cur_test->SetResult(0);
}

void TestCaseCtrl::Assert()
{
    throw Exception(Exception::TEST_FAILED);
}

void TestCaseCtrl::AddOptions(po::options_description &desc)
{
}

int TestCaseCtrl::HandleActions()
{
    return 1;
}

int TestCaseCtrl::HandleSwitches()
{
    return 0;
}

int TestCaseCtrl::Parse()
{
    int result = 0;

    po::store(po::parse_command_line(MasterTestSuite::Get().GetArgC(), MasterTestSuite::Get().GetArgV(), m_desc), m_vm);
    po::notify(m_vm);

    m_is_parsed = true;

    result = HandleSwitches();
    if (result < 0)
        return -1;
    result = HandleActions();
    if (result <= 0)
        return result;

    if (m_vm.count("help"))
    {
        std::cout << m_desc << "\n";
        return -1;
    }
    else
    {
        if (m_vm.count("run_test"))
        {
            RunOneTest((char *)m_run_test.c_str());
        }
        else if (m_vm.count("list"))
        {
            PrintList();
            result = -1;
        }
    }
    return result;
}

bool TestCaseCtrl::IsParsed()
{
    return m_is_parsed;
}

}

}

