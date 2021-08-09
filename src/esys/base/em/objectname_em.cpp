/*!
 * \file esys/base/em/objectname_em.cpp
 * \brief Source file for the embedded implementation of the ObjectName class
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
#include "esys/base/em/objectname.h"
#include "esys/base/em/object.h"

namespace esys
{

namespace base
{

namespace em
{

ObjectName::ObjectName(const char *name)
    : BaseType(name, this)
{
}

ObjectName::ObjectName(const ObjectName &name)
    : BaseType(name)
{
}

ObjectName::~ObjectName()
{
}

} // namespace em

} // namespace base

} // namespace esys
