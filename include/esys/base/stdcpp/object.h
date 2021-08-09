/*!
 * \file esys/base/stdcpp/object.h
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
#include "esys/base/stdcpp/objectname.h"
#include "esys/base/stdcpp/object_t.h"
#include "esys/base/stdcpp/objectinit_t.h"

namespace esys::base
{

namespace stdcpp
{

/*! \class Object esys/base/stdcpp/object.h "esys/base/stdcpp/object.h"
 *  \brief Object class for embedded
 */
class ESYSBASE_API Object : public Object_t<Object>
{
public:
    typedef Object_t<Object> BaseType;

    Object(const ObjectName &name);
    virtual ~Object();
};

} // namespace stdcpp

#ifndef ESYSBASE_EM
using namespace stdcpp;
#endif

} // namespace esys::base
