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
#include "esystest/testcaseinfo.h"
#include "esystest/testsuite.h"
#include "esystest/order.h"
#include "esystest/logger.h"
#include "esystest/report.h"
#include "esystest/assert.h"

namespace esystest
{

TestCaseInfo *TestCaseInfo::m_first = nullptr;
TestCaseInfo *TestCaseInfo::m_last = nullptr;
int TestCaseInfo::m_count = 0;

TestCaseInfo *TestCaseInfo::GetFirst()
{
    return m_first;
}

TestCaseInfo *TestCaseInfo::GetLast()
{
    return m_last;
}

int TestCaseInfo::GetCount()
{
    return m_count;
}

void TestCaseInfo::populate()
{
    TestCaseInfo *cur = GetFirst();
    TestSuite *test_suite;

    while (cur != nullptr)
    {
        test_suite = cur->GetSuite();

        assert(test_suite != nullptr);

        test_suite->AddTest(cur);

        cur = cur->GetNext();
    }
}

TestCaseInfo::TestCaseInfo(const char *name, const char *file, int line)
    : m_name(name)
    , m_file(file)
    , m_line(line)
    , m_test_suite(nullptr)
    , m_prev(nullptr)
    , m_next(nullptr)
    , m_order(ORDER_NOT_SET)
    , m_result(0)
{
#ifdef ESYSTEST_DBG
    m_id = m_count;
#endif
    ++m_count;

    if (m_first == nullptr)
    {
        m_first = this;
        m_last = this;
    }
    else
    {
        m_last->m_next = this;
        m_prev = m_last;
        m_last = this;
    }
}

TestCaseInfo::~TestCaseInfo()
{
}

const char *TestCaseInfo::GetFile()
{
    return m_file;
}

int TestCaseInfo::GetLine()
{
    return m_line;
}

const char *TestCaseInfo::GetName()
{
    return m_name;
}

void TestCaseInfo::SetResult(int result)
{
    m_result = result;
}

int TestCaseInfo::GetResult()
{
    return m_result;
}

void TestCaseInfo::SetSuite(TestSuite *test_suite)
{
    m_test_suite = test_suite;
}

TestSuite *TestCaseInfo::GetSuite()
{
    return m_test_suite;
}

void TestCaseInfo::SetPrev(TestCaseInfo *prev)
{
    m_prev = prev;
}

TestCaseInfo *TestCaseInfo::GetPrev()
{
    return m_prev;
}

void TestCaseInfo::SetNext(TestCaseInfo *next)
{
    m_next = next;
}

TestCaseInfo *TestCaseInfo::GetNext()
{
    return m_next;
}

void TestCaseInfo::SetOrder(unsigned int order)
{
    m_order = order;
}

unsigned int TestCaseInfo::GetOrder()
{
    return m_order;
}

void TestCaseInfo::Start()
{
    Report *report = Report::Get();
    Logger *log = Logger::Get();

    if (report != nullptr)
        report->Start(this);
    else if (log == nullptr)
        return;
    *log << "[Start: " << GetName() << "]" << esystest::endl;
}

void TestCaseInfo::End()
{
    Report *report = Report::Get();
    Logger *log = Logger::Get();

    if (report != nullptr)
        report->End(this);
    else if (log == nullptr)
        return;
    *log << "[End: " << GetName() << "]" << esystest::endl;
}

void TestCaseInfo::Failed()
{
    Report *report = Report::Get();
    Logger *log = Logger::Get();

    if (report != nullptr)
        report->Failed(this);
    else if (log == nullptr)
        return;
    *log << "[Failed: " << GetName() << "]" << esystest::endl;
}

#ifdef ESYSTEST_DBG
int TestCaseInfo::GetId()
{
    return m_id;
}
#endif

} // namespace esystest
