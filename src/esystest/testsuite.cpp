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

TestSuite *TestSuite::g_current = nullptr;
TestSuite TestSuite::g_dft("MasterSuite");
TestSuite *TestSuite::g_p_dft = &g_dft;

void TestSuite::SetCurrent(TestSuite *current)
{
	g_current = current;
}

TestSuite *TestSuite::GetCurrent()
{
	return g_current;
}

TestSuite::TestSuite(const char *name)
	: m_name(name), m_first(nullptr), m_last(nullptr), m_prev(nullptr), m_next(nullptr), m_first_child(nullptr)
	, m_first_case(nullptr), m_last_case(nullptr)
{
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


}




