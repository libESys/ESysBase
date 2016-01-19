/*!
 * \file esystest/globalfixture.cpp
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
#include "esystest/globalfixture.h"

namespace esystest
{

GlobalFixture *GlobalFixture::m_last = nullptr;

GlobalFixture::GlobalFixture()
{
	m_prev = GlobalFixture::m_last;
	GlobalFixture::m_last = this;
}

GlobalFixture::~GlobalFixture()
{
}


}





