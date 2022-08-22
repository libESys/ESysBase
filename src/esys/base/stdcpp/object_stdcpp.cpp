/*!
 * \file esys/base/stdcpp/object_em.cpp
 * \brief Implementation file of the Object class
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
#include "esys/base/stdcpp/object.h"

namespace esys::base::stdcpp
{

Object::Object(const ObjectName &name)
    : BaseType(name, this)
{
}

Object::~Object() = default;

} // namespace esys::base::stdcpp
