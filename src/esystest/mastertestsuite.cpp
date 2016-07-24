/*!
 * \file esystest/mastertestsuite.cpp
 * \brief
 *
 * \cond
 *__legal_b__
 *
 * Copyright (c) 2016 Michel Gillet
 * Distributed under the wxWindows Library Licence, Version 3.1.
 * (See accompanying file LICENSE_3_1.txt or
 * copy at http://www.wxwidgets.org/about/licence)
 *
 *__legal_e__
 * \endcond
 *
 */

#include "esystest/esystest_prec.h"
#include "esystest/mastertestsuite.h"
#include "esystest/assert.h"

namespace esystest
{

MasterTestSuite *MasterTestSuite::s_master_test_suite = nullptr;

MasterTestSuite &MasterTestSuite::Get()
{
    assert(s_master_test_suite != nullptr);

    return *s_master_test_suite;
}

#ifdef ESYSTEST_USE_ESYS
MasterTestSuite::MasterTestSuite(const esys::ObjectName &name)
    : TestSuite(name.GetName()), esys::Module(name), m_mutex("TestMutex")
#else
MasterTestSuite::MasterTestSuite(const char *name) : TestSuite(name)
#endif
{
    assert(s_master_test_suite == nullptr);
    s_master_test_suite = this;
}

MasterTestSuite::~MasterTestSuite()
{
}

#ifdef ESYSTEST_USE_ESYS
const char *MasterTestSuite::GetName()
{
    return TestSuite::GetName();
}

esys::Mutex &MasterTestSuite::GetMutex()
{
    return m_mutex;
}

#endif

}




