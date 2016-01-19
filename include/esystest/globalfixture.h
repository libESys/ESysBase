/*!
 * \file esystest/globalfixture.h
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

#ifndef __ESYSTEST_GLOBALFIXTURE_H__
#define __ESYSTEST_GLOBALFIXTURE_H__

#include "esystest/esystest_defs.h"

namespace esystest
{

class ESYSTEST_API GlobalFixture
{
public:
	GlobalFixture();
	virtual ~GlobalFixture();

protected:
	static GlobalFixture *m_last;
	GlobalFixture *m_prev;
};

template<typename T>
class GlobalFixture_t : public GlobalFixture
{
public:
	GlobalFixture_t();
	virtual ~GlobalFixture_t();
protected:
	static GlobalFixture_t<T> g_gf;
	T m_fixture;
};

template<typename T>
GlobalFixture_t<T>::GlobalFixture_t(): GlobalFixture(), m_fixture()
{
}

template<typename T>
GlobalFixture_t<T>::~GlobalFixture_t()
{
}

template<typename T>
GlobalFixture_t<T> GlobalFixture_t<T>::g_gf;

}

#endif



