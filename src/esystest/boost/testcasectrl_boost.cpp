/*!
 * \file esystest/boost/testcasectrl.cpp
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
#include "esystest/boost/boost/testcasectrl.h"
#include "esystest/testcaseinfo.h"
#include "esystest/mastertestsuite.h"
#include "esystest/exception.h"
#include "esystest/assert.h"

#include <string.h>
#include <iostream>

#include <boost/program_options/cmdline.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/test/unit_test.hpp>

namespace esystest
{

namespace boost_impl
{

TestCaseCtrl::TestCaseCtrl()
    : TestCaseCtrlCore()
{
    set_strict_parsing(false);
    set_use_esystest(false);
}

TestCaseCtrl::~TestCaseCtrl()
{
}

void TestCaseCtrl::AddDefaultOptions()
{
    // clang-format off
    m_desc.add_options()
        ("help-all", "produce help message")
        ("list", "list all unit tests")
#ifdef ESYS_USE_VLD
        ("vld-off", "turn off vld")
#endif
        ("log_trace", po::value<std::string>(&m_log_trace_path)->implicit_value(""), "log calling traces")
        ("verbose,v", po::value<int>()->default_value(0), "set verbosity level: 0 is off")
        ("test_file_path", po::value<std::string>(&m_test_file_path_s), "set the path for test files")
        ("temp_file_path", po::value<std::string>(&m_temp_file_path_s), "set the path for temp files");
    // clang-format on
}

int TestCaseCtrl::GetArgC()
{
    return boost::unit_test::framework::master_test_suite().argc;
}

char **TestCaseCtrl::GetArgV()
{
    return boost::unit_test::framework::master_test_suite().argv;
}

class __MyGlobalFixture
{
public:
    __MyGlobalFixture()
    {
    }

    void setup()
    {
        TestCaseCtrlBase *ctrl = TestCaseCtrlBase::Get();
        int result = 0;

        if (ctrl != nullptr)
        {
            result = ctrl->Init();
            if (result < 0)
            {
                BOOST_TEST_MESSAGE("TestCaseCtrl initialization failed!");
            }
        }
    }
};

BOOST_TEST_GLOBAL_FIXTURE(__MyGlobalFixture);

} // namespace boost_impl

} // namespace esystest
