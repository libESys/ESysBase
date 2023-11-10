/*!
 * \file esys/base/stdcpp/object_em.cpp
 * \brief Implementation file of the Object class
 *
 * \cond
 * __legal_b__
 *
 * Copyright (c) 2014-2020 Michel Gillet
 * Distributed under the MIT License.
 * (See accompanying file LICENSE.txt or
 * copy at https://opensource.org/licenses/MIT)
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
