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

#include "esystest/esystest_prec.h"
#include "esystest/testcase.h"

namespace esystest
{

unsigned int TestCase::g_count = 0;

unsigned int TestCase::GetCount()
{
    return g_count;
}

TestCase::TestCase()
{
    ++TestCase::g_count;
}

TestCase::~TestCase()
{
}

} // namespace esystest
