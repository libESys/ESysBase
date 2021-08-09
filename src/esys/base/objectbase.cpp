/*!
 * \file esys/base/objectbase.cpp
 * \brief Source file of the ObjectBase class
 *
 * \cond
 * __legal_b__
 *
 * Copyright (c) 2014-2020 Michel Gillet
 * Distributed under the wxWindows Library Licence, Version 3.1.
 * (See accompanying file LICENSE_3_1.txt or
 * copy at http://www.wxwidgets.org/about/licence)
 *
 * __legal_e__
 * \endcond
 *
 */

#include "esys/base/esysbase_prec.h"
#include "esys/base/objectbase.h"

namespace esys
{

namespace base
{

ObjectBase::ObjectBase(bool skip_init)
    : m_can_be_disabled(false)
    , m_enabled(true)
{
}

ObjectBase::~ObjectBase()
{
}

void ObjectBase::set_can_be_disabled(bool can_be_disabled)
{
    m_can_be_disabled = can_be_disabled;
}

bool ObjectBase::get_can_be_disabled()
{
    return m_can_be_disabled;
}

bool ObjectBase::is_enabled()
{
    return m_enabled;
}

int ObjectBase::object_enable()
{
    return -1;
}

int ObjectBase::object_disable()
{
    return -1;
}

void ObjectBase::set_parent(ObjectBase *parent)
{
    m_parent = parent;
}

ObjectBase *ObjectBase::get_parent() const
{
    return m_parent;
}

} // namespace base

} // namespace esys
