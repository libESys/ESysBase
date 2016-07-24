/*!
 * \file esystest_t/unittest.cpp
 * \brief
 *
 * \cond
 * __legal_b__
 *
 * Copyright (c) 2015-2016 Michel Gillet
 * Distributed under the wxWindows Library Licence, Version 3.1.
 * (See accompanying file LICENSE_3_1.txt or
 * copy at http://www.wxwidgets.org/about/licence)
 *
 * __legal_e__
 * \endcond
 *
 */

#define BOOST_TEST_MAIN

#ifdef WIN32

#if ESYS_USE_VLD
#include <vld.h>
#endif

#endif

#ifdef _MSC_VER
#pragma warning (disable : 4996)
#pragma warning (disable : 4985)
#endif

#include <boost/test/unit_test.hpp>

#ifdef _MSC_VER
#pragma warning (default : 4996)
#pragma warning (default : 4985)
#endif

#include <esystest/testcasectrlexception.h>
#include <esystest/stdlogger.h>
#include <iostream>

class GlobalInit
{
public:
    GlobalInit();
    ~GlobalInit();
    int m_count;
protected:
    esystest::StdLogger m_logger;
    esystest::TestCaseCtrlException m_test_ctrl;
};

GlobalInit::GlobalInit() : m_count(0)
{
    m_count++;
    m_logger.Set(&std::cout);
    esystest::Logger::Set(&m_logger);
    esystest::TestCaseCtrl::Set(&m_test_ctrl);
}

GlobalInit::~GlobalInit()
{
}

BOOST_GLOBAL_FIXTURE(GlobalInit);
