/*!
 * \file esys/base/stdpp/objectoperation_stdcpp.cpp
 * \brief Source file operation to perform on an Object
 *
 * \cond
 * __legal_b__
 *
 * Copyright (c) 2016-2022 Michel Gillet
 * Distributed under the wxWindows Library Licence, Version 3.1.
 * (See accompanying file LICENSE_3_1.txt or
 * copy at http://www.wxwidgets.org/about/licence)
 *
 * __legal_e__
 * \endcond
 *
 */

#include "esys/base/esysbase_prec.h"
#include "esys/base/stdcpp/objectoperation.h"

#include <iomanip>
#include <typeinfo>

namespace esys::base::stdcpp
{

ObjectOperation::ObjectOperation() = default;

ObjectOperation::ObjectOperation(const Object &object)
    : m_object(&object)
{
}

ObjectOperation::~ObjectOperation() = default;

void ObjectOperation::set_object(const Object &object)
{
    m_object = &object;
}

void ObjectOperation::set_object(const Object *object)
{
    m_object = object;
}

int ObjectOperation::print(std::ostream &os) const
{
    if (m_object == nullptr) return -1;

    return print(os, m_object, 0);
}

int ObjectOperation::print(std::ostream &os, const Object *object, int depth) const
{
    if (depth > 0)
    {
        os << std::setw(depth * 4) << " ";
    }
    os << typeid(*object).name() << " " << object->get_name() << std::endl;

    const Object *current = object->get_first_child();
    int result = 0;

    while (current != nullptr)
    {
        result = print(os, current, depth + 1);
        if (result < 0) return result;
        current = current->get_next();
    }

    return 0;
}

} // namespace esys::base::stdcpp
