/*!
 * \file esystest/mastertestsuite.h
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

#ifndef __ESYSTEST_MASTERTESTSUITE_H__
#define __ESYSTEST_MASTERTESTSUITE_H__

#include "esystest/esystest_defs.h"
#include "esystest/setup.h"
#include "esystest/testsuite.h"

#ifdef ESYSTEST_USE_ESYS
#include <esys/mutex.h>
#include <esys/module.h>
#endif

namespace esystest
{

class ESYSTEST_API MasterTestSuite : public TestSuite
#ifdef ESYSTEST_USE_ESYS
    , public esys::Module
#endif
{
public:
#ifdef ESYSTEST_USE_ESYS
    MasterTestSuite(const esys::ObjectName &name = "");
#else
    MasterTestSuite(const char *name = nullptr);
#endif
    virtual ~MasterTestSuite();

#ifdef ESYSTEST_USE_ESYS
    const char *GetName();
    esys::Mutex &GetMutex();
#endif
    static MasterTestSuite &Get();
protected:
    static MasterTestSuite *s_master_test_suite;

#ifdef ESYSTEST_USE_ESYS
    esys::Mutex m_mutex;
#endif
};

}

#endif


