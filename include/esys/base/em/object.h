/*!
 * \file esys/base/em/object.h
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
#include "esys/base/em/objectname.h"
#include "esys/base/em/object_t.h"

namespace esys::base::em
{

/*! \class Object esys/base/em/object.h "esys/base/em/object.h"
 *  \brief Object class for embedded
 */
class ESYSBASE_API Object : public Object_t<Object, ObjectName>
{
public:
    using BaseType = Object_t<Object, ObjectName>;

    Object(const ObjectName &name);
    ~Object() override;
};

#ifdef ESYSBASE_EM
using namespace em;
#endif

} // namespace esys::base::em
