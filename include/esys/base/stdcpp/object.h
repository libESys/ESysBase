/*!
 * \file esys/base/stdcpp/object.h
 * \brief Header file of the Object class
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

#pragma once

#include "esys/base/esysbase_defs.h"
#include "esys/base/stdcpp/objectname.h"
#include "esys/base/stdcpp/object_t.h"
#include "esys/base/stdcpp/objectinit_t.h"

namespace esys::base::stdcpp
{

/*! \class Object esys/base/stdcpp/object.h "esys/base/stdcpp/object.h"
 *  \brief Object class for embedded
 */
class ESYSBASE_API Object : public Object_t<Object>
{
public:
    using BaseType = Object_t<Object>;

    Object(const ObjectName &name);
    ~Object() override;
};

} // namespace esys::base::stdcpp

#ifndef ESYSBASE_EM
namespace esys::base
{
using namespace stdcpp;
}
#endif
