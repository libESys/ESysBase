/*!
 * \file esys/base/stdcpp/object_t.h
 * \brief Header file of the Object_t class
 *
 * \cond
 * __legal_b__
 *
 * Copyright (c) 2014-2022 Michel Gillet
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
#include "esys/base/objectbase_t.h"
#include "esys/base/stdcpp/objectinit_t.h"
#include "esys/base/stdcpp/objectname.h"
#include "esys/base/stdcpp/objectnamemngr.h"

#include <string>

namespace esys::base::stdcpp
{

/*! \class Object_t esys/base/stdcpp/object_t.h "esys/base/stdcpp/object_t.h"
 *  \brief A template class with common features of all Object class implementations
 */
template<typename T, typename IL = ObjectInit_t<T>>
class Object_t : public ObjectBase_t<T, IL>
{
public:
    Object_t(const ObjectName &name, T *obj);
    ~Object_t() override;

    const char *get_name() const override;
    unsigned int get_id() const override;

    const std::string &get_name_str() const;

protected:
    static unsigned int s_count;
    std::string m_name;
    unsigned int m_id;
};

template<typename T, typename IL>
unsigned int Object_t<T, IL>::s_count = 0;

template<typename T, typename IL>
Object_t<T, IL>::Object_t(const ObjectName &name, T *obj)
    : ObjectBase_t<T, IL>(obj)
    , m_name(name.get_name())
{
    m_id = s_count;
    ++s_count;

    auto cur_name = ObjectNameMngr::get().get_current();
    cur_name->set_object(obj);
}

template<typename T, typename IL>
Object_t<T, IL>::~Object_t()
{
}

template<typename T, typename IL>
const char *Object_t<T, IL>::get_name() const
{
    return get_name_str().c_str();
}

template<typename T, typename IL>
unsigned int Object_t<T, IL>::get_id() const
{
    return m_id;
}

template<typename T, typename IL>
const std::string &Object_t<T, IL>::get_name_str() const
{
    return m_name;
}

} // namespace esys::base::stdcpp
