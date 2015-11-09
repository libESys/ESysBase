/*!
* \file esystest/testsuite.cpp
* \brief
*
* \cond
*__legal_b__
*
*__legal_e__
* \endcond
*
*/


#include "esystest/esystest_prec.h"
#include "esystest/testsuite.h"
#include "esystest/testcaseinfo.h"

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

TestSuite::TestSuite(const char *name)
	: m_name(name), m_first(nullptr), m_last(nullptr), m_prev(nullptr), m_next(nullptr), m_first_child(nullptr)
	, m_first_case(nullptr), m_last_case(nullptr), m_test_case_count(0), m_child_suite_count(0)
{
	++TestSuite::g_count;
}

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

	cur = GetFirst();
	while (cur != nullptr)
	{
		cur->RunTestCases();
		cur = m_first->GetNext();
	}

	cur_test = GetFirstCase();
	while (cur_test != nullptr)
	{
		cur_test->Invoke();
		cur_test = cur_test->GetNext();
	}
}

unsigned int TestSuite::GetTestCaseCount()
{
	return m_test_case_count;
}

unsigned int TestSuite::GetChildSuiteCount()
{
	return m_child_suite_count;
}

}




