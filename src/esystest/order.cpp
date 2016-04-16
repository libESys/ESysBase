/*!
 * \file esystest/order.cpp
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
#include "esystest/order.h"
#include "esystest/testcaseinfo.h"

namespace esystest
{

Order::Order(int value): m_order(value)
{
}

void Order::set_value(int order)
{
    m_order = order;
}

int Order::value() const
{
    return m_order;
}

ESYSTEST_API Order order(int value)
{
    Order order_(value);
    return order_;
}

}

ESYSTEST_API esystest::TestCaseInfo &operator*(esystest::TestCaseInfo& info, const esystest::Order &order)
{
    info.SetOrder(order.value());
    return info;
}

