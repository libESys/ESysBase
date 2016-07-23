/*!
 * \file esystest/testsuite.h
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

#ifndef __ESYSTEST_TESTSUITE_H__
#define __ESYSTEST_TESTSUITE_H__

#include "esystest/esystest_defs.h"

#ifdef ESYSTEST_USE_ESYS
#include <esys/mutex.h>
#include <esys/modulebase.h>
#endif
namespace esystest
{

class ESYSTEST_API TestCaseInfo;

class ESYSTEST_API TestSuite
#ifdef ESYSTEST_USE_ESYS
    : public esys::ModuleBase
#endif
{
public:
#ifdef ESYSTEST_USE_ESYS
    TestSuite(const esys::ObjectName &name = "");
#else
    TestSuite(const char *name = nullptr);
#endif
    virtual ~TestSuite();

    void SetFirst(TestSuite *first);
    TestSuite *GetFirst();

    void SetLast(TestSuite *first);
    TestSuite *GetLast();

    void SetPrev(TestSuite *prev);
    TestSuite *GetPrev();

    void SetNext(TestSuite *next);
    TestSuite *GetNext();

    void SetFirstChild(TestSuite *first_child);
    TestSuite *GetFirstChild();

    void AddSuite(TestSuite *test_suite);
    void AddTest(TestCaseInfo *test_case);

    void SetFirstCase(TestCaseInfo *first_case);
    TestCaseInfo *GetFirstCase();
    void SetLastCase(TestCaseInfo *last_case);
    TestCaseInfo *GetLastCase();

    void RunTestCases();
    void Sort();
    void SortTestCaseInfo();
    void Swap(TestCaseInfo *test1, TestCaseInfo *test2);
    unsigned int GetTestCaseCount();
    unsigned int GetChildSuiteCount();

    void SetCommandLine(int argc, char **argv);

    int GetArgC();
    char **GetArgV();

    void Start();
    void End();
#ifndef ESYSTEST_USE_ESYS
    const char *GetName();
#endif
    static void SetCurrent(TestSuite *current);
    static TestSuite *GetCurrent();
    static TestSuite *GetMaster();
    static unsigned int GetCount();
protected:
    static TestSuite *g_current;
    static TestSuite *g_master;
    static TestSuite g_dft;
    static unsigned int g_count;

    TestSuite *m_first;
    TestSuite *m_last;
    TestSuite *m_prev;
    TestSuite *m_next;
    TestSuite *m_first_child;
    TestCaseInfo *m_first_case;
    TestCaseInfo *m_last_case;
    unsigned int m_test_case_count;
    unsigned int m_child_suite_count;
    int m_argc;
    char **m_argv;
#ifndef ESYSTEST_USE_ESYS
    const char *m_name;
#endif

};

}

#endif


