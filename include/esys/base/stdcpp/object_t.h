/*!
 * \file esys/base/stdcpp/object_t.h
 * \brief Header file of the Object_t class
 *
 * \cond
 * __legal_b__
 *
 * Copyright (c) 2014-2022 Michel Gillet
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
#include "esys/base/stdcpp/objectname.h"
#include "esys/base/stdcpp/objectnamemngr.h"

#include <string>

namespace esys::base::stdcpp
{

/*! \class Object_t esys/base/stdcpp/object_t.h "esys/base/stdcpp/object_t.h"
 *  \brief A template class with common features of all Object class implementations
 */
template<typename OBJ, typename OBJNAME>
class Object_t : public ObjectBase_t<OBJ, OBJNAME>
{
public:
    Object_t(const ObjectName &name, OBJ *obj);
    ~Object_t() override;

    const char *get_name() const override;

    const std::string &get_name_str() const;

protected:
    static unsigned int s_count;
    std::string m_name;
};

template<typename OBJ, typename OBJNAME>
unsigned int Object_t<OBJ, OBJNAME>::s_count = 0;

template<typename OBJ, typename OBJNAME>
Object_t<OBJ, OBJNAME>::Object_t(const ObjectName &name, OBJ *obj)
    : ObjectBase_t<OBJ, OBJNAME>(obj)
    , m_name(name.get_name())
{
    ++s_count;
}

template<typename OBJ, typename OBJNAME>
Object_t<OBJ, OBJNAME>::~Object_t()
{
}

template<typename OBJ, typename OBJNAME>
const char *Object_t<OBJ, OBJNAME>::get_name() const
{
    return get_name_str().c_str();
}

template<typename OBJ, typename OBJNAME>
const std::string &Object_t<OBJ, OBJNAME>::get_name_str() const
{
    return m_name;
}

} // namespace esys::base::stdcpp
