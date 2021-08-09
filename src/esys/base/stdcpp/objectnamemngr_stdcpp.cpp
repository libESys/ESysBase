/*!
 * \file esys/base/stdcpp/objectnamemngr_em.cpp
 * \brief Source file for the embedded implementation of the ObjectNameMngr class
 *
 * \cond
 * __legal_b__
 *
 * Copyright (c) 2016-2020 Michel Gillet
 * Distributed under the wxWindows Library Licence, Version 3.1.
 * (See accompanying file LICENSE_3_1.txt or
 * copy at http://www.wxwidgets.org/about/licence)
 *
 * __legal_e__
 * \endcond
 *
 */

#include "esys/base/esysbase_prec.h"
#include "esys/base/stdcpp/objectnamemngr.h"
#include "esys/base/stdcpp/nodemngr.h"

namespace esys
{

namespace base
{

namespace stdcpp
{

ObjectNameMngr::ObjectNameMngr()
    : BaseType()
{
}

ObjectNameMngr::~ObjectNameMngr()
{
}

void ObjectNameMngr::set_current(ObjectName *current)
{
    auto node = NodeMngr::get().find();

    if (node == nullptr)
        m_current = current;
    else
        node->get_object_name_mngr().set_current(current);
}

ObjectName *ObjectNameMngr::get_current()
{
    auto node = NodeMngr::get().find();

    if (node == nullptr)
        return m_current;
    else
        return node->get_object_name_mngr().get_current();
}

} // namespace stdcpp

} // namespace base

} // namespace esys
