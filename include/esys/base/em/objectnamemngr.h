/*!
 * \file esys/base/em/objectnamemngr.h
 * \brief Header file for the embedded implementation of the ObjectNameMngr class
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
#include "esys/base/objectnamemngr_t.h"

namespace esys::base::em
{

class ESYSBASE_API ObjectName;

/*! \class ObjecttNameMngr esys/base/em/objectnamemngr.h "esys/base/em/objectnamemgr.h"
 *  \brief
 */
class ESYSBASE_API ObjectNameMngr : public ObjectNameMngr_t<ObjectName, ObjectNameMngr>
{
public:
    using BaseType = ObjectNameMngr_t<ObjectName, ObjectNameMngr>;

    //! Default Constructor
    ObjectNameMngr();

    //! Destructor
    ~ObjectNameMngr() override;

    void set_current(ObjectName *current) override;

    ObjectName *get_current() override;

protected:
    //!< \cond DOXY_IMPL
    static ObjectName *s_current;
    //!< \endcond
};

#ifdef ESYSBASE_EM
using namespace em;
#endif

} // namespace esys::base::em
