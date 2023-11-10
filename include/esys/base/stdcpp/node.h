/*!
 * \file esys/base/stdcpp/node.h
 * \brief Header file of the Node class
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
#include "esys/base/stdcpp/objectname.h"
#include "esys/base/stdcpp/object.h"
#include "esys/base/stdcpp/objectnamemngr.h"

#include <memory>
#include <string>

namespace esys::base::stdcpp
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
    ~Node() override;

    ObjectNameMngr &get_object_name_mngr();
    const ObjectNameMngr &get_object_name_mngr() const;

private:
    //!< \cond DOXY_IMPL
    ObjectNameMngr m_object_name_mngr;
    //!< \endcond
};

} // namespace esys::base::stdcpp
