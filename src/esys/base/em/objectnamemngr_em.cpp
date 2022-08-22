/*!
 * \file esys/base/em/objectnamemngr_em.cpp
 * \brief Source file for the embedded implementation of the ObjectNameMngr class
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
#include "esys/base/em/objectnamemngr.h"

namespace esys::base::em
{

ObjectName *ObjectNameMngr::s_current = nullptr;

ObjectNameMngr::ObjectNameMngr()
    : BaseType()
{
}

ObjectNameMngr::~ObjectNameMngr() = default;

void ObjectNameMngr::set_current(ObjectName *current)
{
    s_current = current;
}

ObjectName *ObjectNameMngr::get_current()
{
    return s_current;
}

} // namespace esys::base::em
