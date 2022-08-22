/*!
 * \file esys/base/em/object.h
 * \brief Header file of the Object class
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

#pragma once

#include "esys/base/esysbase_defs.h"
#include "esys/base/em/objectname.h"
#include "esys/base/em/object_t.h"
#include "esys/base/em/objectinit_t.h"

namespace esys::base::em
{

/*! \class Object esys/base/em/object.h "esys/base/em/object.h"
 *  \brief Object class for embedded
 */
class ESYSBASE_API Object : public Object_t<Object>
{
public:
    using BaseType = Object_t<Object>;

    Object(const ObjectName &name);
    ~Object() override;
};

#ifdef ESYSBASE_EM
using namespace em;
#endif

} // namespace esys::base::em
