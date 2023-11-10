/*!
 * \file esys/base/stdpp/objectname.h
 * \brief Header file for the embedded implementation of the ObjectName class
 *
 * \cond
 * __legal_b__
 *
 * Copyright (c) 2016-2020 Michel Gillet
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
#include "esys/base/objectname_t.h"
#include "esys/base/stdcpp/objectnamemngr.h"

namespace esys
{

namespace base
{

namespace stdcpp
{

class ESYSBASE_API Object;

/*! \class ObjecttName esys/base/stdcpp/objectname.h "esys/base/stdcpp/objectname.h"
 *  \brief
 */

class ESYSBASE_API ObjectName : public ObjectName_t<Object, ObjectNameMngr, ObjectName>
{
public:
    typedef ObjectName_t<Object, ObjectNameMngr, ObjectName> BaseType;

    //! Constructor
    /*!
     *  \param[in] name The name of the Object
     */
    ObjectName(const char *name);

    //! Constructor
    /*!
     *  \param[in] name The name of the Object
     */
    ObjectName(const ObjectName &name);

    //! Destructor
    virtual ~ObjectName();

protected:
    //!< \cond DOXY_IMPL

    //!< \endcond
};

} // namespace stdcpp

#ifndef ESYSBASE_EM
using namespace stdcpp;
#endif

} // namespace base

} // namespace esys
