/*!
 * \file esys/base/objectbase.h
 * \brief Header file of the ObjectBase class
 *
 * \cond
 * __legal_b__
 *
 * Copyright (c) 2014-2020 Michel Gillet
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
#include "esys/base/objplatif.h"

namespace esys::base
{

/*! \class Object esys/base/objectbase.h "esys/base/objectbase.h"
 *  \brief The base class for all Object class implementation
 */
class ESYSBASE_API ObjectBase : public virtual ObjPlatIf
{
public:
    explicit ObjectBase(bool skip_init = false);
    ~ObjectBase() override;

    void set_can_be_disabled(bool can_be_disabled = true);
    bool get_can_be_disabled() const;
    bool is_enabled() const;
    virtual int object_enable();
    virtual int object_disable();

    virtual const char *get_name() const = 0;
    virtual unsigned int get_id() const = 0;
    virtual unsigned int get_children_count() const = 0;

    virtual void set_parent(ObjectBase *parent);
    ObjectBase *get_parent() const;

private:
    //!< \cond DOXY_IMPL
    ObjectBase *m_parent = nullptr;
    bool m_can_be_disabled : 1;
    bool m_enabled : 1;
    //!< \endcond
};

} // namespace esys::base
