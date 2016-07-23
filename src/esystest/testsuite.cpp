/*!
 * \file esystest/testsuite.cpp
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


#include "esystest/esystest_prec.h"
#include "esystest/testsuite.h"
#include "esystest/testcaseinfo.h"
#include "esystest/testcasectrl.h"
#include "esystest/logger.h"

namespace esystest
{

TestSuite TestSuite::g_dft("MasterSuite");
TestSuite *TestSuite::g_current = &g_dft;
TestSuite *TestSuite::g_master = &g_dft;
unsigned int TestSuite::g_count = 0;

void TestSuite::SetCurrent(TestSuite *current)
{
    g_current = current;
}

TestSuite *TestSuite::GetCurrent()
{
    if (g_current == nullptr)
        g_current = g_master;
    return g_current;
}

TestSuite *TestSuite::GetMaster()
{
    return g_master;
}


#ifdef ESYSTEST_USE_ESYS
TestSuite::TestSuite(const esys::ObjectName &name)
    : ModuleBase(name), m_first(nullptr), m_last(nullptr), m_prev(nullptr), m_next(nullptr), m_first_child(nullptr)
    , m_first_case(nullptr), m_last_case(nullptr), m_test_case_count(0), m_child_suite_count(0)
    , m_argc(0), m_argv(nullptr)
{
    ++TestSuite::g_count;
}
#else
TestSuite::TestSuite(const char *name)
    : m_first(nullptr), m_last(nullptr), m_prev(nullptr), m_next(nullptr), m_first_child(nullptr)
    , m_first_case(nullptr), m_last_case(nullptr), m_test_case_count(0), m_child_suite_count(0)
    , m_argc(0), m_argv(nullptr), m_name(name)
{
    ++TestSuite::g_count;
}
#endif
TestSuite::~TestSuite()
{
}

void TestSuite::SetFirst(TestSuite *first)
{
    m_first = first;
}

TestSuite *TestSuite::GetFirst()
{
    return m_first;
}

void TestSuite::SetLast(TestSuite *last)
{
    m_last = last;
}

TestSuite *TestSuite::GetLast()
{
    return m_last;
}

void TestSuite::SetPrev(TestSuite *prev)
{
    m_prev = prev;
}

TestSuite *TestSuite::GetPrev()
{
    return m_prev;
}

void TestSuite::SetNext(TestSuite *next)
{
    m_next = next;
}

TestSuite *TestSuite::GetNext()
{
    return m_next;
}


void TestSuite::SetFirstChild(TestSuite *first_child)
{
    m_first_child = first_child;
}

TestSuite *TestSuite::GetFirstChild()
{
    return m_first_child;
}

void TestSuite::AddSuite(TestSuite *test_suite)
{
    ++m_child_suite_count;

    if (GetFirst() == nullptr)
    {
        SetFirst(test_suite);
        SetLast(test_suite);
        return;
    }
    GetLast()->SetNext(test_suite);
    test_suite->SetPrev(GetLast());
    SetLast(test_suite);
}

void TestSuite::AddTest(TestCaseInfo *test_case)
{
    ++m_test_case_count;

    if (GetFirstCase() == nullptr)
    {
        SetFirstCase(test_case);
        SetLastCase(test_case);
        return;
    }
    GetLastCase()->SetNext(test_case);
    test_case->SetPrev(GetLastCase());
    test_case->SetSuite(this);
    SetLastCase(test_case);
}

void TestSuite::SetFirstCase(TestCaseInfo *first_case)
{
    m_first_case = first_case;
}

TestCaseInfo *TestSuite::GetFirstCase()
{
    return m_first_case;
}

void TestSuite::SetLastCase(TestCaseInfo *last_case)
{
    m_last_case = last_case;
}

TestCaseInfo *TestSuite::GetLastCase()
{
    return m_last_case;
}

void TestSuite::RunTestCases()
{
    TestSuite *cur;
    TestCaseInfo *cur_test;
    TestCaseCtrl *ctrl= TestCaseCtrl::Get();

    Start();

    cur = GetFirst();
    while (cur != nullptr)
    {
        cur->RunTestCases();
        cur = m_first->GetNext();
    }

    cur_test = GetFirstCase();
    while (cur_test != nullptr)
    {
        if (ctrl != nullptr)
        {
            ctrl->BeforeTest();
            ctrl->Invoke(cur_test);
        }
        else
            cur_test->Invoke();
        if (ctrl != nullptr)
            ctrl->AfterTest();
        if (cur_test->GetResult() < 0)
            cur_test->Failed();

        cur_test = cur_test->GetNext();
    }

    End();
}

void TestSuite::Sort()
{
    SortTestCaseInfo();
}

void TestSuite::SortTestCaseInfo()
{
    TestCaseInfo *test1;
    TestCaseInfo *test2;

    bool swapped = true;
    unsigned int idx;
    unsigned int count;

    if (m_test_case_count < 2)
        return;

    // Very simply bubble sort, mostly because there is no need for auxiliary memory
    count = m_test_case_count - 1;

    while (swapped == true)
    {
        swapped = false;
        test1 = GetFirstCase();
        test2 = test1->GetNext();

        for (idx = 0; idx < count; ++idx)
        {
            if (test1->GetOrder() > test2->GetOrder())
            {
                Swap(test1, test2);
                swapped = true;
                test2 = test1->GetNext();
            }
            else
            {
                test1 = test2;
                test2 = test1->GetNext();
            }
        }
        --count;
    }
}

void TestSuite::Swap(TestCaseInfo *test1, TestCaseInfo *test2)
{
    if (test1->GetPrev()!=nullptr)
        test1->GetPrev()->SetNext(test2);
    if (test2->GetNext() != nullptr)
        test2->GetNext()->SetPrev(test1);
    test2->SetPrev(test1->GetPrev());
    test1->SetNext(test2->GetNext());
    test2->SetNext(test1);
    test1->SetPrev(test2);

    if (m_first_case == test1)
        m_first_case = test2;
    if (m_last_case == test2)
        m_last_case = test1;
}

unsigned int TestSuite::GetTestCaseCount()
{
    return m_test_case_count;
}

unsigned int TestSuite::GetChildSuiteCount()
{
    return m_child_suite_count;
}

void TestSuite::SetCommandLine(int argc, char **argv)
{
    m_argc = argc;
    m_argv = argv;
}

int TestSuite::GetArgC()
{
    return m_argc;
}

char **TestSuite::GetArgV()
{
    return m_argv;
}

const char *TestSuite::GetName()
{
    return m_name;
}

void TestSuite::Start()
{
    Logger *log = Logger::Get();
    if (log == nullptr)
        return;
    *log << "[StartSuite: ";
    if (GetName() != nullptr)
        *log << GetName();
    *log << "]" << esystest::endl;
}

void TestSuite::End()
{
    Logger *log = Logger::Get();
    if (log == nullptr)
        return;
    *log << "[EndSuite: ";
    if (GetName() != nullptr)
        *log << GetName();
    *log << "]" << esystest::endl;
}

}




