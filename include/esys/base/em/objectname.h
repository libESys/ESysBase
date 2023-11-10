/*!
 * \file esys/base/em/objectname.h
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
#include "esys/base/em/objectnamemngr.h"

namespace esys::base::em
{

class ESYSBASE_API Object;

/*! \class ObjecttName esys/base/em/objectname.h "esys/base/em/objectname.h"
 *  \brief
 */

class ESYSBASE_API ObjectName : public ObjectName_t<Object, ObjectNameMngr, ObjectName>
{
public:
    using BaseType = ObjectName_t<Object, ObjectNameMngr, ObjectName>;

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
    ~ObjectName() override;
};

#ifdef ESYSBASE_EM
using namespace em;
#endif

} // namespace esys::base::em
