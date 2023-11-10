/*!
 * \file esys/base/stdcpp/objectnamemngr.h
 * \brief Header file for the embedded implementation of the ObjectNameMngr class
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
#include "esys/base/objectnamemngr_t.h"

#include <thread>

namespace esys
{

namespace base
{

namespace stdcpp
{

class ESYSBASE_API ObjectName;

/*! \class ObjecttNameMngr esys/base/stdcpp/objectnamemngr.h "esys/base/stdcpp/objectnamemgr.h"
 *  \brief
 */
class ESYSBASE_API ObjectNameMngr : public ObjectNameMngr_t<ObjectName, ObjectNameMngr>
{
public:
    typedef ObjectNameMngr_t<ObjectName, ObjectNameMngr> BaseType;

    //! Default Constructor
    ObjectNameMngr();

    //! Destructor
    virtual ~ObjectNameMngr();

    void set_current(ObjectName *current) override;
    virtual ObjectName *get_current() override;

protected:
    //!< \cond DOXY_IMPL
    ObjectName *m_current = nullptr;
    //!< \endcond
};

} // namespace stdcpp

#ifndef ESYSBASE_EM
using namespace stdcpp;
#endif

} // namespace base

} // namespace esys
