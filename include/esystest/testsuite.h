/*!
* \file esystest/testsuite.h
* \brief
*
* \cond
*__legal_b__
*
*__legal_e__
* \endcond
*
*/

#ifndef __ESYSTEST_TESTSUITE_H__
#define __ESYSTEST_TESTSUITE_H__

#include "esystest/esystest_defs.h"

namespace esystest
{

class ESYSTEST_API TestCaseInfo;

class ESYSTEST_API TestSuite
{
public:
	TestSuite(const char *name=nullptr);
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

	static void SetCurrent(TestSuite *current);
	static TestSuite *GetCurrent();
	static TestSuite *GetMaster();
protected:
	static TestSuite *g_current;
	static TestSuite *g_master;
	static TestSuite g_dft;
	const char *m_name;
	TestSuite *m_first;
	TestSuite *m_last;
	TestSuite *m_prev;
	TestSuite *m_next;	
	TestSuite *m_first_child;
	TestCaseInfo *m_first_case;
	TestCaseInfo *m_last_case;
};

}

#endif


