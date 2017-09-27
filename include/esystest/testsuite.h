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

extern "C"
{

typedef void (*before_main_type)(void);

ESYSTEST_API void esystest_set_before_main(before_main_type before_main);

}

#ifdef __cplusplus

namespace esystest
{

class ESYSTEST_API TestCaseInfo;

class ESYSTEST_API TestSuite
{
public:
    TestSuite(const char *name = nullptr);
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

    void Run();
    void RunTestCases();
    void ListTestCases();

    void Sort();
    void SortTestCaseInfo();
    void Swap(TestCaseInfo *test1, TestCaseInfo *test2);
    unsigned int GetTestCaseCount();
    unsigned int GetChildSuiteCount();

    int GetSuccessCount();
    int GetFailureCount();
    void IncSuccessCount();
    void IncFailureCount();

    int GetSuccessCountArray(CheckType check_type, ToolLevel tool_level);
    int GetFailureCountArray(CheckType check_type, ToolLevel tool_level);
    void IncSuccessCountArray(CheckType check_type, ToolLevel tool_level);
    void IncFailureCountArray(CheckType check_type, ToolLevel tool_level);

    void SetCommandLine(int argc, char **argv);

    int GetArgC();
    char **GetArgV();

    void Start();
    void End();
    const char *GetName();

    static void SetCurrent(TestSuite *current);
    static TestSuite *GetCurrent();
    static TestSuite *GetMaster();
    static unsigned int GetCount();

    static int GetTotalSuccessCount();
    static int GetTotalFailureCount();
    static void IncTotalSuccessCount();
    static void IncTotalFailureCount();

    static before_main_type GetBeforeMain();
protected:
    static TestSuite ESYSTEST_DATA_SECTION *g_current;
    static TestSuite ESYSTEST_DATA_SECTION *g_master;
    //static TestSuite g_dft;
    static unsigned int ESYSTEST_DATA_SECTION g_count;

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
    const char *m_name;
    int m_success_count;
    int m_failure_count;
    static int ESYSTEST_DATA_SECTION g_total_success_count;
    static int ESYSTEST_DATA_SECTION g_total_failure_count;
#ifdef ESYSTEST_META
    int m_success_count_array[CHECKTYPE_COUNT][TOOLLEVEL_COUNT];
    int m_failure_count_array[CHECKTYPE_COUNT][TOOLLEVEL_COUNT];
#endif
};

}
#endif


#endif


