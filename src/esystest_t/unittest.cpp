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

#define ESYSTEST_TEST_MAIN

#include <esystest/unit_test.h>
#include <esystest/testcasectrl.h>
#include <esystest/stdlogger.h>

#include <esystest/vld.h>

#include <iostream>

class GlobalInit
{
public:
    GlobalInit();
    ~GlobalInit();
    int m_count;
protected:
    esystest::StdLogger m_logger;
    esystest::TestCaseCtrl m_test_ctrl;
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

ESYSTEST_GLOBAL_FIXTURE(GlobalInit);
