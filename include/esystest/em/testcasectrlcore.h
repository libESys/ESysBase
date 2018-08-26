/*!
 * \file esystest/em/testcasectrlcore.h
 * \brief
 *
 * \cond
 *__legal_b__
 *
 * Copyright (c) 2015-2018 Michel Gillet
 * Distributed under the wxWindows Library Licence, Version 3.1.
 * (See accompanying file LICENSE_3_1.txt or
 * copy at http://www.wxwidgets.org/about/licence)
 *
 *__legal_e__
 * \endcond
 *
 */

#pragma once

#include "esystest/esystest_defs.h"
#include "esystest/testcasectrlbase.h"

namespace esystest
{

namespace em
{

class ESYSTEST_API TestCaseCtrlCore: public TestCaseCtrlBase
{
public:
    TestCaseCtrlCore();
    virtual ~TestCaseCtrlCore();

    virtual void Invoke(TestCaseInfo *cur_test) override;

protected:
    int m_verbose;
    bool m_log_trace;
};

}

#ifdef ESYSTEST_EM
using namespace em;
#endif

}






