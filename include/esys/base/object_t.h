/*!
 * \file esys/base/object_t.h
 * \brief Header file of the Object_t class
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
#include "esys/base/objectbase_t.h"

#include <string>

namespace esys::base
{

/*! \class Object_t esys/base/object_t.h "esys/base/object_t.h"
 *  \brief A template class with common features of all Object class implementations
 */
template<typename OBJ, typename OBJNAME, typename IL = ObjectInit_t<OBJ>>
class Object_t : public ObjectBase_t<OBJ, IL>
{
public:
    Object_t(const OBJNAME &name, OBJ *obj);
    virtual ~Object_t();

    const char *get_name() override;
    unsigned int get_id() override;

    const std::string &get_name_str();

protected:
    static unsigned int s_count;
    std::string m_name;
    unsigned int m_id;
};

template<typename OBJ, typename OBJNAME, typename IL>
unsigned int Object_t<OBJ, OBJNAME, IL>::s_count = 0;

template<typename T, typename OBJNAME, typename IL>
Object_t<T, IL>::Object_t(const OBJNAME &name, T *obj)
    : ObjectBase_t<T, IL>()
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
const char *Object_t<T, IL>::get_name()
{
    return get_name_str().c_str();
}

template<typename T, typename IL>
unsigned int Object_t<T, IL>::get_id()
{
    return m_id;
}

template<typename T, typename IL>
const std::string &Object_t<T, IL>::get_name_str()
{
    return m_name;
}

} // namespace esys::base
