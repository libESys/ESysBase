/*!
 * \file esys/base/objectnamebase.h
 * \brief Header file of the ObjectNameBase class
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

namespace esys
{

namespace base
{

/*! \class ObjecttNameBase esys/base/objectnamebase.h "esys/base/objectnamebase.h"
 *  \brief Base class of all ObjectName used to name all Object
 */
class ESYSBASE_API ObjectNameBase
{
public:
    //! Constructor
    /*!
     *  \param[in] name The name of the Object
     */
    ObjectNameBase(const char *name);

    //! Destructor
    virtual ~ObjectNameBase();

    //! Return the actual name of the Object as a string
    /*!
     *  \return the actual name of the Object
     */
    const char *get_name() const;

    //! Conversion operator to return the actual name of the Object as a string
    /*!
     *  \return the actual name of the Object
     */
    operator const char *() const;

protected:
    //!< \cond DOXY_IMPL
    const char *m_name = nullptr; //!< The actual name of the Object
    //!< \endcond
};

} // namespace base

} // namespace esys
