/*!
 * \file esys/base/stdcpp/node.h
 * \brief Header file of the Node class
 *
 * \cond
 * __legal_b__
 *
 * Copyright (c) 2016-2020 Michel Gillet
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
#include "esys/base/stdcpp/objectname.h"
#include "esys/base/stdcpp/object.h"
#include "esys/base/stdcpp/objectnamemngr.h"

#include <memory>
#include <string>

namespace esys
{

namespace base
{

namespace stdcpp
{

/*! \class Node esys/base/stdcpp/node.h "esys/base/stdcpp/node.h"
 *  \brief
 */
class ESYSBASE_API Node : public Object, public std::enable_shared_from_this<Node>
{
public:
    //! Constructor
    /*!
     * \param[in] name the name of the Node
     */
    Node(const ObjectName &name);

    //! Destructor
    virtual ~Node();

    ObjectNameMngr &get_object_name_mngr();
    const ObjectNameMngr &get_object_name_mngr() const;
    
protected:
    //!< \cond DOXY_IMPL
    ObjectNameMngr m_object_name_mngr;
    //!< \endcond
};

} // namespace stdcpp

} // namespace base

} // namespace esys
