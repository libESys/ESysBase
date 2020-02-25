/*!
 * \file esystest/exception.cpp
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

#include "esystest/esystest_prec.h"
#include "esystest/exception.h"

namespace esystest
{

Exception::Exception(ID id)
    : m_id(id)
{
}

void Exception::SetId(ID id)
{
    m_id = id;
}

Exception::ID Exception::GetId() const
{
    return m_id;
}

} // namespace esystest
