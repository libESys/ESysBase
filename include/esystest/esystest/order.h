/*!
 * \file esystest/order.h
 * \brief
 *
 * \cond
 * __legal_b__
 *
 * Copyright (c) 2015-2020 Michel Gillet
 * Distributed under the wxWindows Library Licence, Version 3.1.
 * (See accompanying file LICENSE_3_1.txt or
 * copy at http://www.wxwidgets.org/about/licence)
 *
 * __legal_e__
 * \endcond
 *
 */

#pragma once

#include "esystest/esystest_defs.h"
#include "esystest/order_defs.h"

namespace esystest
{

class ESYSTEST_API TestCaseInfo;

namespace esystest_impl
{

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

} // namespace esystest_impl

#ifdef ESYSTEST_USE_ESYSTEST
using namespace esystest_impl;
#endif

} // namespace esystest

ESYSTEST_API esystest::TestCaseInfo &operator*(esystest::TestCaseInfo &info,
                                               const esystest::esystest_impl::Order &order);
