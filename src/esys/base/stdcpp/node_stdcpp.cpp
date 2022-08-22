/*!
 * \file esys/base/stdcpp/node_stdcpp.cpp
 * \brief Header file of the Node class
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
#include "esys/base/stdcpp/node.h"
#include "esys/base/stdcpp/nodemngr.h"

namespace esys::base::stdcpp
{

Node::Node(const ObjectName &name)
    : Object(name)
{
}

Node::~Node() = default;

ObjectNameMngr &Node::get_object_name_mngr()
{
    return m_object_name_mngr;
}

const ObjectNameMngr &Node::get_object_name_mngr() const
{
    return m_object_name_mngr;
}

} // namespace esys::base::stdcpp
