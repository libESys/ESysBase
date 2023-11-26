/*!
 * \file esys/base/objectbase.cpp
 * \brief Source file of the ObjectBase class
 *
 * \cond
 * __legal_b__
 *
 * Copyright (c) 2014-2023 Michel Gillet
 * Distributed under the MIT License.
 * (See accompanying file LICENSE.txt or
 * copy at https://opensource.org/licenses/MIT)
 *
 * __legal_e__
 * \endcond
 *
 */

#include "esys/base/esysbase_prec.h"
#include "esys/base/objectbase.h"

namespace esys::base
{

ObjectBase::ObjectBase() = default;

ObjectBase::~ObjectBase() = default;

void ObjectBase::set_parent(ObjectBase *parent)
{
    m_parent = parent;
}

ObjectBase *ObjectBase::get_parent() const
{
    return m_parent;
}

} // namespace esys::base
