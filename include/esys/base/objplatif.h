/*!
 * \file esys/base/objplatif.h
 * \brief
 *
 * \cond
 * __legal_b__
 *
 * Copyright (c) 2022 Michel Gillet
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
