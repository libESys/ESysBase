
#pragma once

#include "esystest/esystest_defs.h"
#include "esystest/order_defs.h"
#include "esystest/types.h"

#include <boost/test/tree/decorator.hpp>

namespace esystest
{

namespace boost_impl
{

class /*ESYSTEST_API*/ order : public ::boost::unit_test::decorator::base
{
public:
    explicit order(int value) : m_value(value)
    {
    }

private:
    virtual void apply(::boost::unit_test::test_unit& tu)
    {
    }

    virtual ::boost::unit_test::decorator::base_ptr clone() const
    {
        return ::boost::unit_test::decorator::base_ptr(new order(m_value));
    }

    int m_value;
};

}

#ifdef ESYSTEST_USE_BOOST
using namespace boost_impl;
#endif

}
