/*!
 * \file esystest/order.h
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

#ifndef __ESYSTEST_ORDER_H__
#define __ESYSTEST_ORDER_H__

#include "esystest/esystest_defs.h"

namespace esystest
{

class ESYSTEST_API TestCaseInfo;

const unsigned int ORDER_NOT_SET = 0xFFFE;
const unsigned int ORDER_LAST = 0xFFFF;

class ESYSTEST_API Order
{
public:
    Order(int value);

    void set_value(int order);
    int value() const;

protected:
    int m_order;
};

ESYSTEST_API Order order(int value);

}

ESYSTEST_API esystest::TestCaseInfo &operator*(esystest::TestCaseInfo& info, const esystest::Order & order);

#endif
