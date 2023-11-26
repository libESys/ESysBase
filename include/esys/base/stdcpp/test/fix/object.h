/*!
 * \file esys/base/stdcpp/test/fix/object.h
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

#pragma once

#include <esys/base/stdcpp/object.h>

namespace esys::base::stdcpp::fix
{

class Object : public base::stdcpp::Object
{
public:
    Object(const ObjectName &name);

    ~Object() override;
};

} // namespace esys::base::stdcpp::fix
