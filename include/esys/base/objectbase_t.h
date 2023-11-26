/*!
 * \file esys/base/objectbase_t.h
 * \brief Header file of the ObjectBase_t class
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
#include "esys/base/objectbase.h"
#include "esys/base/assert.h"

namespace esys::base
{

/*! \class ObjectBase_t esys/base/objectbase_t.h "esys/base/objectbase_t.h"
 *  \brief A template class with common features of all Object class implementations
 */
template<typename OBJ, typename OBJNAME, typename OBJ_BASE = ObjectBase>
class ObjectBase_t : public OBJ_BASE
{
public:
    explicit ObjectBase_t(OBJ *object);

    ~ObjectBase_t() override;

    //! Adds a child object
    /*!
     *  \param[in] child the child object
     */
    virtual void add_child(OBJ *child);

    virtual OBJ *get_child(unsigned int idx);

    unsigned int get_children_count() const;

    void set_next(OBJ *next)
    {
        m_next = next;
    }

    OBJ *get_next() const
    {
        return m_next;
    }

    void set_prev(OBJ *prev)
    {
        m_prev = prev;
    }

    OBJ *get_prev() const
    {
        return m_prev;
    }

    void set_first_child(OBJ *first_child)
    {
        m_first_child = first_child;
    }

    OBJ *get_first_child() const
    {
        return m_first_child;
    }

    void set_last_child(OBJ *last_child)
    {
        m_last_child = last_child;
    }

    OBJ *get_last_child() const
    {
        return m_last_child;
    }

    //! Set the parent of this item in the tree
    /*!
     *  \param[in] parent the parent item
     */
    void set_parent(OBJ *parent)
    {
        ObjectBase::set_parent(parent);

        m_parent = parent;
    }

    //! Return the parent of this item in the tree
    /*!
     *  \return the parent if any, nullptr otherwise
     */
    OBJ *get_parent() const
    {
        return m_parent;
    }

private:
    //!< \cond DOXY_IMPL
    OBJ *m_next = nullptr;        //!< The next object to be initialized
    OBJ *m_prev = nullptr;        //!< The previous object
    OBJ *m_first_child = nullptr; //!< The first child object
    OBJ *m_last_child = nullptr;  //!< The last child object
    OBJ *m_parent = nullptr;      //!< The parent of the object
    //!< \endcond
};

template<typename OBJ, typename OBJNAME, typename OBJ_BASE>
ObjectBase_t<OBJ, OBJNAME, OBJ_BASE>::ObjectBase_t(OBJ *object)
    : OBJ_BASE()
{
    auto &mngr = OBJNAME::ObjectMngrType::get();
    auto cur_name = mngr.get_current();
    cur_name->set_object(object);
}

template<typename OBJ, typename OBJNAME, typename OBJ_BASE>
ObjectBase_t<OBJ, OBJNAME, OBJ_BASE>::~ObjectBase_t()
{
}

template<typename OBJ, typename OBJNAME, typename OBJ_BASE>
void ObjectBase_t<OBJ, OBJNAME, OBJ_BASE>::add_child(OBJ *child)
{
    assert(child != nullptr);

    // child->set_in_hierarchy();

    // child->set_depth(get_depth() + 1);

    if (m_first_child == nullptr)
    {
        m_first_child = child;
        m_last_child = child;
        return;
    }

    // Add the child object to the end of the list
    child->set_prev(m_last_child);
    m_last_child->set_next(child);
    m_last_child = child;
}

template<typename OBJ, typename OBJNAME, typename OBJ_BASE>
OBJ *ObjectBase_t<OBJ, OBJNAME, OBJ_BASE>::get_child(unsigned int idx)
{
    OBJ *current = m_first_child;
    unsigned int count = 0;

    while (current != nullptr)
    {
        if (idx == count) return current;

        ++count;
        current = current->get_next();
    }

    return nullptr;
}

template<typename OBJ, typename OBJNAME, typename OBJ_BASE>
unsigned int ObjectBase_t<OBJ, OBJNAME, OBJ_BASE>::get_children_count() const
{
    const OBJ *current = m_first_child;
    unsigned int count = 0;

    while (current != nullptr)
    {
        ++count;
        current = current->get_next();
    }
    return count;
}

} // namespace esys::base
