/*!
 * \file esys/base/stdpp/objectoperation.h
 * \brief Header file operation to perform on an Object
 *
 * \cond
 * __legal_b__
 *
 * Copyright (c) 2016-2022 Michel Gillet
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
#include "esys/base/object.h"

namespace esys::base::stdcpp
{

/*! \class ObjectOperation esys/base/stdcpp/objectoperation.h "esys/base/stdcpp/objectoperation.h"
 *  \brief
 */

class ESYSBASE_API ObjectOperation
{
public:
    //! Default constructor
    ObjectOperation();

    //! Constructor
    /*!
     *  \param[in] object The Object to work on
     */
    ObjectOperation(const Object &object);

    //! Destructor
    ~ObjectOperation();

    void set_object(const Object &object);
    void set_object(const Object *object);

    int print(std::ostream &os) const;
    int print(std::ostream &os, const Object *object, int depth = 0) const;

protected:
    //!< \cond DOXY_IMPL
    const Object *m_object = nullptr;
    //!< \endcond
};

} // namespace esys::base::stdcpp
