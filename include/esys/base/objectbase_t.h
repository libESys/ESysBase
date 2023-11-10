/*!
 * \file esys/base/objectbase_t.h
 * \brief Header file of the ObjectBase_t class
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
#include "esys/base/objectbase.h"
#include "esys/base/assert.h"

namespace esys::base
{

/*! \class ObjectBase_t esys/base/objectbase_t.h "esys/base/objectbase_t.h"
 *  \brief A template class with common features of all Object class implementations
 */
template<typename T, typename IL>
class ObjectBase_t : public ObjectBase, public IL
{
public:
    explicit ObjectBase_t(T *object);

    ~ObjectBase_t() override;

    //! Adds a child object
    /*!
     *  \param[in] child the child object
     */
    virtual void add_child(T *child);

    virtual T *get_child(unsigned int idx);

    unsigned int get_children_count() const override;

    void set_next(T *next)
    {
        m_next = next;
    }

    T *get_next() const
    {
        return m_next;
    }

    void set_prev(T *prev)
    {
        m_prev = prev;
    }

    T *get_prev() const
    {
        return m_prev;
    }

    void set_first_child(T *first_child)
    {
        m_first_child = first_child;
    }

    T *get_first_child() const
    {
        return m_first_child;
    }

    void set_last_child(T *last_child)
    {
        m_last_child = last_child;
    }

    T *get_last_child() const
    {
        return m_last_child;
    }

    //! Set the parent of this item in the tree
    /*!
     *  \param[in] parent the parent item
     */
    void set_parent(T *parent)
    {
        ObjectBase::set_parent(parent);

        m_parent = parent;
    }

    //! Return the parent of this item in the tree
    /*!
     *  \return the parent if any, nullptr otherwise
     */
    T *get_parent() const
    {
        return m_parent;
    }

private:
    //!< \cond DOXY_IMPL
    T *m_next = nullptr;        //!< The next object to be initialized
    T *m_prev = nullptr;        //!< The previous object
    T *m_first_child = nullptr; //!< The first child object
    T *m_last_child = nullptr;  //!< The last child object
    T *m_parent = nullptr;      //!< The parent of the object
    //!< \endcond
};

template<typename T, typename IL>
ObjectBase_t<T, IL>::ObjectBase_t(T *object)
    : ObjectBase()
    , IL(object)
{
}

template<typename T, typename IL>
ObjectBase_t<T, IL>::~ObjectBase_t()
{
}

template<typename T, typename IL>
void ObjectBase_t<T, IL>::add_child(T *child)
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

template<typename T, typename IL>
T *ObjectBase_t<T, IL>::get_child(unsigned int idx)
{
    T *current = m_first_child;
    unsigned int count = 0;

    while (current != nullptr)
    {
        if (idx == count) return current;

        ++count;
        current = current->get_next();
    }

    return nullptr;
}

template<typename T, typename IL>
unsigned int ObjectBase_t<T, IL>::get_children_count() const
{
    const T *current = m_first_child;
    unsigned int count = 0;

    while (current != nullptr)
    {
        ++count;
        current = current->get_next();
    }
    return count;
}

} // namespace esys::base
