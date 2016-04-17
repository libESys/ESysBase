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

#ifndef __ESYSTEST_REPORT_H__
#define __ESYSTEST_REPORT_H__

#include "esystest/esystest_defs.h"

namespace esystest
{

ESYSTEST_API bool report_assertion(bool result, const char *file_name, int line_num
    , ToolLevel tl, CheckType ct, const char *desc="");

class ESYSTEST_API TestCaseInfo;

class ESYSTEST_API Report
{
public:
    Report();
    virtual ~Report();

    virtual void Start(TestCaseInfo *test_case_info) = 0;
    virtual void End(TestCaseInfo *test_case_info) = 0;
    virtual void Failed(TestCaseInfo *test_case_info) = 0;

    static void Set(Report *report);
    static Report *Get();
protected:
    static Report *s_report;
};

}

#endif
