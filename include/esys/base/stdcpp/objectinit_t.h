/*!
 * \file esys/base/stdcpp/objectinit_t.h
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

namespace esys::base::stdcpp
{

/*! \class ObjectInit_t esys/base/stdcpp/object_t.h "esys/base/stdcpp/object_t.h"
 *  \brief
 */
template<typename T>
class ObjectInit_t : public base::ObjectInitBase_t<T>
{
public:
    typedef base::ObjectInitBase_t<T> BaseType;

    ObjectInit_t(T *object);
    virtual ~ObjectInit_t();

    int init() override;
    int release() override;

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

template<typename T>
int ObjectInit_t<T>::init()
{
    auto obj = this->get_object();
    assert(obj != nullptr);

    if (obj == nullptr) return -1;
    int result = obj->plat_init();
    if (result < 0) return result;

    T *current = obj->get_first_child();
    while (current != nullptr)
    {
        result = current->plat_init();
        if (result < 0) return result;
        current = current->get_next();
    }

    return 0;
}

template<typename T>
int ObjectInit_t<T>::release()
{
    auto obj = this->get_object();
    assert(obj != nullptr);

    if (obj == nullptr) return -1;
    int result = 0;

    T *current = obj->get_first_child();
    while (current != nullptr)
    {
        result = current->plat_release();
        if (result < 0) return result;
        current = current->get_next();
    }

    result = obj->plat_release();
    if (result < 0) return result;

    return 0;
}

} // namespace esys::base::stdcpp
