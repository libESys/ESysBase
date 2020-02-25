/*!
 * \file esystest/esystest/testcasectrl.h
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

#pragma once

#include "esystest/esystest_defs.h"
#include "esystest/testcasectrlcore.h"

namespace esystest
{

namespace esystest
{

class ESYSTEST_API TestCaseCtrl : public TestCaseCtrlCore
{
public:
    TestCaseCtrl();
    virtual ~TestCaseCtrl();

    static TestCaseCtrl &Get();

protected:
    static TestCaseCtrl *g_test_case;
};

} // namespace esystest

#ifdef ESYSTEST_USE_ESYSTEST
using namespace esystest;
#endif

} // namespace esystest
