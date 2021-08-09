/*!
 * \file esys/base/objectinitbase_t.h
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

namespace esys::base
{

/*! \class ObjectInitBase_t esys/base/objectinitbase_t.h "esys/base/objectinitbase_t.h"
 *  \brief Base claas of all implementation of the ObjectInit_t
 */
template<typename T>
class ObjectInitBase_t
{
public:
    //! Default constructor
    ObjectInitBase_t(T *object);

    //! Destructor
    ~ObjectInitBase_t();

    virtual int init() = 0;
    virtual int release() = 0;

    T *get_object();

private:
    T *m_object = nullptr;
};

template<typename T>
ObjectInitBase_t<T>::ObjectInitBase_t(T *object)
    : m_object(object)
{
}

template<typename T>
ObjectInitBase_t<T>::~ObjectInitBase_t() = default;

template<typename T>
T *ObjectInitBase_t<T>::get_object()
{
    return m_object;
}

} // namespace esys::base
