/*!
* \file esystest/globalfixture.cpp
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





