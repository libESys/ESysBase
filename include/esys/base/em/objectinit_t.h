/*!
 * \file esys/base/em/objectinit_t.h
 * \brief Header file of the Object_t class
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
#include "esys/base/objectinitbase_t.h"

namespace esys::base::em
{

/*! \class ObjectInit_t esys/base/em/object_t.h "esys/base/em/object_t.h"
 *  \brief
 */
template<typename T>
class ObjectInit_t : public base::ObjectInitBase_t<T>
{
public:
    typedef base::ObjectInitBase_t<T> BaseType;

    ObjectInit_t(T *object);
    virtual ~ObjectInit_t();

protected:
    //!< \cond DOXY_IMPL

    //!< \endcond
};

template<typename T>
ObjectInit_t<T>::ObjectInit_t(T *object)
    : BaseType(object)
{
}

template<typename T>
ObjectInit_t<T>::~ObjectInit_t() = default;

} // namespace esys::base::em
