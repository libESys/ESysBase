/*!
 * \file esys/base/objectnamebase.cpp
 * \brief Source file of the ObjectName class
 *
 * \cond
 * __legal_b__
 *
 *
 * __legal_e__
 * \endcond
 *
 */

#include "esys/base/esysbase_prec.h"
#include "esys/base/objectnamebase.h"

namespace esys
{

namespace base
{

ObjectNameBase::ObjectNameBase(const char *name)
    : m_name(name)
{
}

ObjectNameBase::~ObjectNameBase()
{
}

const char *ObjectNameBase::get_name() const
{
    return m_name;
}

ObjectNameBase::operator const char *() const
{
    return m_name;
}

} // namespace base

} // namespace esys
