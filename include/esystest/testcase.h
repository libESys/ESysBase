/*!
 * \file esystest/testcase.h
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

namespace esystest
{

class ESYSTEST_API TestCase
{
public:
    TestCase();
    virtual ~TestCase();

    virtual void TestMethod() = 0;
    static unsigned int GetCount();

protected:
    static unsigned int g_count;
};

} // namespace esystest
