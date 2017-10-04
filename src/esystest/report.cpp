/*!
 * \file esystest/report.h
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
#include "esystest/report.h"
#include "esystest/logger.h"
#include "esystest/testcasectrlbase.h"
#include "esystest/testsuite.h"
#include "esystest/assert.h"

namespace esystest
{

ESYSTEST_API bool report_assertion(bool result, const char *file_name, int line_num, ToolLevel tl, CheckType ct, const char *desc)
{
    //log_level    ll;
    char const*  prefix;
    char const*  suffix;
    Logger *logger=Logger::Get();
    TestSuite *cur_test_suite = TestSuite::GetCurrent();

    if (cur_test_suite != nullptr)
    {
        if (result == true)
        {
            cur_test_suite->IncSuccessCountArray(ct, tl);
            cur_test_suite->IncSuccessCount();
        }
        else
        {
            cur_test_suite->IncFailureCountArray(ct, tl);
            cur_test_suite->IncFailureCount();
        }
    }

    if (result == true)
        tl = PASS;

    switch (tl)
    {
        case PASS:
            //ll = log_successful_tests;
            prefix = "check ";
            suffix = "has passed";
            break;
        case WARN:
            //ll = log_warnings;
            prefix = "condition ";
            suffix = "is not satisfied";
            break;
        case CHECK:
            //ll = log_all_errors;
            prefix = "check ";
            suffix = "has failed";
            break;
        case REQUIRE:
            //ll = log_fatal_errors;
            prefix = "critical check ";
            suffix = "has failed";
            break;
        default:
            return true;
    }

    if (logger != nullptr)
    {
        if ((tl != PASS) || ((tl == PASS) && (logger->GetReportPass() == true)))
        {
            *logger << prefix << suffix << " : ";
            if (desc!=nullptr)
                *logger << desc << "\n";
            *logger << "File: " << file_name << " Line: " << (int32_t)line_num << "\n";
        }
    }

    switch (tl)
    {
        case PASS:
            //framework::assertion_result(AR_PASSED);
            return true;

        case WARN:
            //framework::assertion_result(AR_TRIGGERED);
            return false;

        case CHECK:
            //framework::assertion_result(AR_FAILED);
            return false;

        case REQUIRE:
            //framework::assertion_result(AR_FAILED);

            //framework::test_unit_aborted(framework::current_test_case());

            //BOOST_TEST_IMPL_THROW(execution_aborted());
            if (TestCaseCtrlBase::Get() != nullptr)
                TestCaseCtrlBase::Get()->Assert();
            else
                assert(false);
        default:
            assert(false);
    }

    return true;
}

Report *Report::s_report = nullptr;

void Report::Set(Report *report)
{
    s_report = report;
}

Report *Report::Get()
{
    return s_report;
}

Report::Report()
{
}

Report::~Report()
{
}

}

