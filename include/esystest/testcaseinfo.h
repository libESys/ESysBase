/*!
 * \file esystest/TestCaseInfo.h
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

#ifndef __ESYSTEST_TESTCASEINFO_H__
#define __ESYSTEST_TESTCASEINFO_H__

#include "esystest/esystest_defs.h"

namespace esystest
{

class ESYSTEST_API TestSuite;

class ESYSTEST_API TestCaseInfo
{
public:
	TestCaseInfo(const char *name=nullptr, const char *file=nullptr, int line=-1);
	virtual ~TestCaseInfo();

	const char *GetFile();
	int GetLine();
	virtual void SetSuite(TestSuite *test_suite);
	virtual TestSuite *GetSuite();
	virtual void SetPrev(TestCaseInfo *prev);
	virtual TestCaseInfo *GetPrev();
	virtual void SetNext(TestCaseInfo *next);
	virtual TestCaseInfo *GetNext();

	virtual void Invoke() = 0;

    static TestCaseInfo *GetFirst();
    static TestCaseInfo *GetLast();
    static int GetCount();
    static void Populate();

protected:
	const char *m_name;
	const char *m_file;
	int m_line;
	TestSuite *m_test_suite;
	TestCaseInfo *m_prev;
	TestCaseInfo *m_next;
    static TestCaseInfo *m_first;
    static TestCaseInfo *m_last;
    static int m_count;
};

}

#endif

