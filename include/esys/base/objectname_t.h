/*!
 * \file esys/base/objectname_t.h
 * \brief Header file of the ObjectName class
 *
 * \cond
 * __legal_b__
 *
 * Copyright (c) 2016-2020 Michel Gillet
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
#include "esys/base/objectnamebase.h"

#include <cassert>

namespace esys::base
{

/*! \class ObjecttName_t esys/base/objectname_t.h "esys/base/objectname_t.h"
 *  \brief
 */
template<typename OBJ, typename MNGR, typename OBJNAME>
class ObjectName_t : public ObjectNameBase
{
public:
    //! Constructor
    /*!
     *  \param[in] name The name of the Object
     */
    ObjectName_t(const char *name, OBJNAME *obj_name);

    //! Constructor
    /*!
     *  \param[in] name The name of the Object
     */
    ObjectName_t(const OBJNAME &name);

    //! Destructor
    ~ObjectName_t() override;

    //! Set the ObjectName preceeding this instance
    /*!
     *  \param[in] prev the previous ObjectName
     */
    void set_prev(OBJNAME *prev);

    //! Get the ObjectName preceeding this instance
    /*!
     *  \return the previous ObjectName
     */
    OBJNAME *get_prev() const;

    //! Set the next ObjectName following this instance
    /*!
     *  \param[in] next the ObjectName to be set after the current one
     */
    void set_next(OBJNAME *next);

    //! Get the ObjectName after this instance
    /*!
     *  \return the item following this instance
     */
    OBJNAME *get_next() const;

    //! Set the Object related to this ObjectName
    /*!
     *  \param[in] object the Object related to this ObjectName
     */
    void set_object(OBJ *object);

    //! Get the Object related to this ObjectName
    /*!
     *  \return the Object related to this ObjectName
     */
    OBJ *get_object();

    //! Set the current ObjectName
    /*!
     *  \param[in] current the current ObjectName
     */
    static void set_current(OBJNAME *current);

    //! Get the current ObjectName
    /*!
     *  \return the current ObjectName
     */
    static OBJNAME *get_current();

private:
    //!< \cond DOXY_IMPL
    OBJNAME *m_prev = nullptr; //!< The previous ObjectName
    OBJNAME *m_next = nullptr; //!< The next ObjectName
    OBJ *m_object = nullptr;
    //!< \endcond
};

template<typename OBJ, typename MNGR, typename OBJNAME>
ObjectName_t<OBJ, MNGR, OBJNAME>::ObjectName_t(const char *name, OBJNAME *obj_name)
    : ObjectNameBase(name)
{
    if (get_current() == nullptr)
    {
        set_current(obj_name);
    }
    else
    {
        set_prev(get_current());
        get_current()->set_next(obj_name);
        set_current(obj_name);
    }
}

template<typename OBJ, typename MNGR, typename OBJNAME>
ObjectName_t<OBJ, MNGR, OBJNAME>::ObjectName_t(const OBJNAME &name)
    : ObjectNameBase(name.get_name())
{
}

template<typename OBJ, typename MNGR, typename OBJNAME>
ObjectName_t<OBJ, MNGR, OBJNAME>::~ObjectName_t()
{
    OBJNAME *cur_name;
    OBJNAME *prev_name;
    OBJ *cur_obj;
    OBJ *prev_obj;

    cur_name = get_current();
    if (cur_name != nullptr)
    {
        prev_name = cur_name->get_prev();
        if (prev_name != nullptr)
        {
            cur_obj = cur_name->get_object();
            assert(cur_obj != nullptr);

            prev_obj = prev_name->get_object();
            assert(prev_obj != nullptr);

            prev_obj->add_child(cur_obj);
            cur_obj->set_parent(prev_obj);
            prev_name->set_next(nullptr);
        }
        set_current(prev_name);
    }
}

template<typename OBJ, typename MNGR, typename OBJNAME>
void ObjectName_t<OBJ, MNGR, OBJNAME>::set_prev(OBJNAME *prev)
{
    m_prev = prev;
}

template<typename OBJ, typename MNGR, typename OBJNAME>
OBJNAME *ObjectName_t<OBJ, MNGR, OBJNAME>::get_prev() const
{
    return m_prev;
}

template<typename OBJ, typename MNGR, typename OBJNAME>
void ObjectName_t<OBJ, MNGR, OBJNAME>::set_next(OBJNAME *next)
{
    m_next = next;
}

template<typename OBJ, typename MNGR, typename OBJNAME>
OBJNAME *ObjectName_t<OBJ, MNGR, OBJNAME>::get_next() const
{
    return m_next;
}

template<typename OBJ, typename MNGR, typename OBJNAME>
void ObjectName_t<OBJ, MNGR, OBJNAME>::set_object(OBJ *object)
{
    m_object = object;
}

template<typename OBJ, typename MNGR, typename OBJNAME>
OBJ *ObjectName_t<OBJ, MNGR, OBJNAME>::get_object()
{
    return m_object;
}

template<typename OBJ, typename MNGR, typename OBJNAME>
void ObjectName_t<OBJ, MNGR, OBJNAME>::set_current(OBJNAME *current)
{
    MNGR::get().set_current(current);
}

template<typename OBJ, typename MNGR, typename OBJNAME>
OBJNAME *ObjectName_t<OBJ, MNGR, OBJNAME>::get_current()
{
    return MNGR::get().get_current();
}

} // namespace esys::base
