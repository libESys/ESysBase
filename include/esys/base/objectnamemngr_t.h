/*!
 * \file esys/base/objectnamemngr_t.h
 * \brief Header file of the ObjectName class
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
#include "esys/base/objectname_t.h"

namespace esys::base
{

/*! \class ObjecttNameMngr_t esys/base/objectnamemngr_t.h "esys/base/objectnamemgr_t.h"
 *  \brief
 */
template<typename OBJ, typename MNGR>
class ObjectNameMngr_t
{
public:
    //! Default Constructor
    ObjectNameMngr_t();

    //! Destructor
    virtual ~ObjectNameMngr_t();

    static MNGR &get();

    //! Set the current ObjectName
    /*!
     *  \param[in] current the current ObjectName
     */
    virtual void set_current(OBJ *current) = 0;

    //! Get the current ObjectName
    /*!
     *  \return the current ObjectName
     */
    virtual OBJ *get_current() = 0;
};

template<typename OBJ, typename MNGR>
ObjectNameMngr_t<OBJ, MNGR>::ObjectNameMngr_t()
{
}

template<typename OBJ, typename MNGR>
ObjectNameMngr_t<OBJ, MNGR>::~ObjectNameMngr_t()
{
}

template<typename OBJ, typename MNGR>
MNGR &ObjectNameMngr_t<OBJ, MNGR>::get()
{
    static MNGR s_mngr;

    return s_mngr;
}

} // namespace esys::base
