/*!
 * \file esys/base/objectbase.h
 * \brief Header file of the ObjectBase class
 *
 * \cond
 * __legal_b__
 *
 * Copyright (c) 2014-2023 Michel Gillet
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

/*! \class Object esys/base/objectbase.h "esys/base/objectbase.h"
 *  \brief The base class for all Object class implementation
 */
class ESYSBASE_API ObjectBase
{
public:
    explicit ObjectBase();
    virtual ~ObjectBase();

    virtual const char *get_name() const = 0;
    virtual unsigned int get_children_count() const = 0;

    virtual void set_parent(ObjectBase *parent);
    ObjectBase *get_parent() const;

private:
    //!< \cond DOXY_IMPL
    ObjectBase *m_parent = nullptr;
    //!< \endcond
};

} // namespace esys::base
