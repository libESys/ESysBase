/*!
 * \file esys/base/stdcpp/test/fix/object_stdcpp_fix.cpp
 * \brief
 *
 * \cond
 * __legal_b__
 *
 * Copyright (c) 2023 Michel Gillet
 * Distributed under the MIT License.
 * (See accompanying file LICENSE.txt or
 * copy at https://opensource.org/licenses/MIT)
 *
 * __legal_e__
 * \endcond
 *
 */

#include "esys/base/test/esysbase_t_prec.h"
#include "esys/base/stdcpp/test/fix/object.h"

namespace esys::base::stdcpp::fix
{

Object::Object(const ObjectName &name)
    : base::stdcpp::Object(name)
{
}

Object::~Object() = default;

} // namespace esys::base::stdcpp::fix
