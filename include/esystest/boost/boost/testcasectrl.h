/*!
 * \file esystest/boost/testcasectrl.h
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

namespace boost_impl
{

class ESYSTEST_API TestCaseCtrl : public TestCaseCtrlCore
{
public:
    TestCaseCtrl();
    virtual ~TestCaseCtrl();

    virtual void AddDefaultOptions() override;
    virtual int GetArgC() override;
    virtual char **GetArgV() override;
};

} // namespace boost_impl

#if defined(ESYSTEST_USE_BOOST)
using namespace boost_impl;
#endif

} // namespace esystest
