/*!
* \file esystest/testcase.h
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
#include "esystest/testcaseinfo.h"

namespace esystest
{

TestCaseInfo::TestCaseInfo(const char *name, const char *file, int line)
	: m_name(name), m_file(file), m_line(line), m_test_suite(nullptr), m_prev(nullptr), m_next(nullptr)
{
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

}



