/*!
 * \file esys/base/em/object_t.h
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
#include "esys/base/objectbase_t.h"
#include "esys/base/em/objectinit_t.h"
#include "esys/base/em/objectname.h"
#include "esys/base/em/objectnamemngr.h"

#include <cstdint>

namespace esys::base::em
{

/*! \class Object_t esys/base/em/object_t.h "esys/base/em/object_t.h"
 *  \brief A template class with common features of all Object class implementations
 */
template<typename T, typename IL = ObjectInit_t<T>>
class Object_t : public ObjectBase_t<T, IL>
{
public:
    Object_t(const ObjectName &name, T *obj);
    virtual ~Object_t();

    const char *get_name() const override;
    unsigned int get_id() const override;

protected:
    static uint16_t s_count;
    const char *m_name = nullptr;
    uint16_t m_id;
};

template<typename T, typename IL>
uint16_t Object_t<T, IL>::s_count = 0;

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
    return m_name;
}

template<typename T, typename IL>
unsigned int Object_t<T, IL>::get_id() const
{
    return m_id;
}

} // namespace esys::base::em
