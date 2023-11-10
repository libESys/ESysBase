/*!
 * \file esys/base/em/objectname_em.cpp
 * \brief Source file for the embedded implementation of the ObjectName class
 *
 * \cond
 * __legal_b__
 *
 * Copyright (c) 2016-2020 Michel Gillet
 * Distributed under the MIT License.
 * (See accompanying file LICENSE.txt or
 * copy at https://opensource.org/licenses/MIT)
 *
 * __legal_e__
 * \endcond
 *
 */

#include "esys/base/esysbase_prec.h"
#include "esys/base/em/objectname.h"
#include "esys/base/em/object.h"

namespace esys::base::em
{

ObjectName::ObjectName(const char *name)
    : BaseType(name, this)
{
}

ObjectName::ObjectName(const ObjectName &name)
    : BaseType(name)
{
}

ObjectName::~ObjectName() = default;

} // namespace esys::base::em
