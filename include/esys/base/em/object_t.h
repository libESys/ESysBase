/*!
 * \file esys/base/em/object_t.h
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
#include "esys/base/em/objectname.h"
#include "esys/base/em/objectnamemngr.h"

#include <cstdint>

namespace esys::base::em
{

/*! \class Object_t esys/base/em/object_t.h "esys/base/em/object_t.h"
 *  \brief A template class with common features of all Object class implementations
 */
template<typename OBJ, typename OBJNAME>
class Object_t : public ObjectBase_t<OBJ, OBJNAME>
{
public:
    using BaseType = ObjectBase_t<OBJ, OBJNAME>;

    Object_t(const ObjectName &name, OBJ *obj);
    ~Object_t() override;

    const char *get_name() const override;

protected:
    static uint16_t s_count;

private:
    const char *m_name = nullptr;
};

template<typename OBJ, typename OBJNAME>
uint16_t Object_t<OBJ, OBJNAME>::s_count = 0;

template<typename OBJ, typename OBJNAME>
Object_t<OBJ, OBJNAME>::Object_t(const ObjectName &name, OBJ *obj)
    : BaseType(obj)
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
    return m_name;
}

} // namespace esys::base::em
