/*!
 * \file esystest/boost/testcasectrl.h
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

#ifndef __ESYSTEST_BOOST_TESTCASECTRL_H__
#define __ESYSTEST_BOOST_TESTCASECTRL_H__

#include "esystest/esystest_defs.h"
#include "esystest/testcasectrlbase.h"

#include <string>

#include <boost/program_options/options_description.hpp>
#include <boost/program_options/variables_map.hpp>

namespace po = boost::program_options;

namespace esystest
{

namespace boost
{

class ESYSTEST_API TestCaseCtrl: public TestCaseCtrlBase
{
public:
    TestCaseCtrl();
    virtual ~TestCaseCtrl();

    virtual esys::int32_t Init() override;

    virtual void BeforeTest() override;
    virtual void AfterTest() override;
    virtual void Invoke(TestCaseInfo *cur_test) override;
    virtual void Assert() override;

    virtual void AddOptions(po::options_description &desc);
    virtual int32_t Parse();
    virtual int32_t HandleActions();
    virtual int32_t HandleSwitches();
    bool IsParsed();
protected:
    std::string m_run_test;
    po::variables_map m_vm;
    po::options_description m_desc;
    bool m_is_parsed;
    int m_verbose;
    bool m_log_trace;
};

}

#ifdef ESYSTEST_CMD_LINE
using namespace boost;
#endif

}

#endif




