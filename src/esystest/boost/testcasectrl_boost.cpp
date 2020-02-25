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

namespace esystest
{

namespace boost_impl
{

TestCaseCtrl::TestCaseCtrl()
    : TestCaseCtrlCore()
{
}

TestCaseCtrl::~TestCaseCtrl()
{
}

} // namespace boost_impl

} // namespace esystest
