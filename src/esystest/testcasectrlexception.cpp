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
#include "esystest/mastertestsuite.h"
#include "esystest/exception.h"
#include "esystest/assert.h"

#include <string.h>
#include <iostream>

#include <boost/program_options/cmdline.hpp>
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/program_options/parsers.hpp>

namespace po = boost::program_options;

namespace esystest
{

TestCaseCtrlException::TestCaseCtrlException() : TestCaseCtrl()
{
}

TestCaseCtrlException::~TestCaseCtrlException()
{
}

esys::int32_t TestCaseCtrlException::Init()
{
    po::variables_map vm;
    po::options_description desc("Allowed options");

    desc.add_options()
        ("help", "produce help message")
        ("run_test", po::value<std::string>(&m_run_test), "give the name of the test to run");

    po::store(po::parse_command_line(MasterTestSuite::Get().GetArgC(), MasterTestSuite::Get().GetArgV(), desc), vm);
    po::notify(vm);

    if (vm.count("help"))
    {
        std::cout << desc << "\n";
        return -1;
    }
    else
    {
        if (vm.count("run_test"))
        {
            RunOneTest((char *)m_run_test.c_str());
        }
    }
    return 0;
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

void TestCaseCtrlException::Assert()
{
    throw Exception(Exception::TEST_FAILED);
}

}

