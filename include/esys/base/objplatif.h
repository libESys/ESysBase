/*!
 * \file esys/base/objplatif.h
 * \brief
 *
 * \cond
 * __legal_b__
 *
 * Copyright (c) 2022 Michel Gillet
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

namespace esys::base
{

/*! \class ObjPlatIf esys/base/objplatif.h "esys/base/objplatif.h"
 *  \brief Interface to initiliaze object platform
 */
class ESYSBASE_API ObjPlatIf
{
public:
    //! Default constructor
    ObjPlatIf();

    //! Destructor
    virtual ~ObjPlatIf();

    //! Initialize an object of the platform
    /*!
     *  \return 0 if success, otherwise < 0
     */
    virtual int plat_init() = 0;

    //! Relase an object of the platform
    /*!
     *  \return 0 if success, otherwise < 0
     */
    virtual int plat_release() = 0;
};

} // namespace esys::base
