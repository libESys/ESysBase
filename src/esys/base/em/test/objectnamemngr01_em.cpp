/*!
 * \file esys/base/em/test/objectnamemngr01_em.cpp
 * \brief
 *
 * \cond
 * __legal_b__
 *
 * Copyright (c) 2020-2023 Michel Gillet
 * Distributed under the MIT License.
 * (See accompanying file LICENSE.txt or
 * copy at https://opensource.org/licenses/MIT)
 *
 * __legal_e__
 * \endcond
 *
 */

#include "esys/base/test/esysbase_t_prec.h"

#include <esys/base/em/objectnamemngr.h>
#include <esys/base/em/object.h>

#include <iostream>

namespace esys::base::em::test::objectnamemngr01
{

class MyObjectBase : public Object
{
public:
    MyObjectBase(const ObjectName &name)
        : Object(name)
    {
    }

    ~MyObjectBase() override = default;

    int plat_init() override
    {
        return 0;
    }

    int plat_release() override
    {
        return 0;
    }
};

class MyObject : public MyObjectBase
{
public:
    MyObject(const ObjectName &name);

private:
    MyObjectBase m_obj_a{"obj_a"};
    MyObjectBase m_obj_b{"obj_b"};
};

MyObject::MyObject(const ObjectName &name)
    : MyObjectBase(name)
{
}

class ObjectA : public MyObjectBase
{
public:
    ObjectA(const ObjectName &name);

protected:
    MyObjectBase m_my_obj_a{"my_obj_a"};
    MyObjectBase m_my_obj_b{"my_obj_b"};
    MyObjectBase m_my_obj_c{"my_obj_c"};
};

ObjectA::ObjectA(const ObjectName &name)
    : MyObjectBase(name)
{
}

/*! \class ObjectNameMngr01 esys/base/em/test/objectnamemngr01.cpp "esys/base/em/test/objectnamemngr01.cpp"
 *
 *  \brief
 */
ESYSTEST_AUTO_TEST_CASE(ObjectNameMngr01EM)
{
    MyObject obj("master");

    ESYSTEST_REQUIRE_EQUAL(obj.get_children_count(), 2);

    auto child = obj.get_child(0);
    int str_cmp = strcmp(child->get_name(), "obj_a");
    ESYSTEST_REQUIRE_EQUAL(str_cmp, 0);

    child = obj.get_child(1);
    str_cmp = strcmp(child->get_name(), "obj_b");
    ESYSTEST_REQUIRE_EQUAL(str_cmp, 0);

    child = obj.get_child(2);
    ESYSTEST_REQUIRE_EQUAL(child, nullptr);

    ObjectA obj_a("master_a");

    ESYSTEST_REQUIRE_EQUAL(obj_a.get_children_count(), 3);

    child = obj_a.get_child(0);
    str_cmp = strcmp(child->get_name(), "my_obj_a");
    ESYSTEST_REQUIRE_EQUAL(str_cmp, 0);
    ESYSTEST_REQUIRE_EQUAL(obj_a.get_child(0)->get_children_count(), 2);

    child = obj_a.get_child(1);
    str_cmp = strcmp(child->get_name(), "my_obj_b");
    ESYSTEST_REQUIRE_EQUAL(str_cmp, 0);

    child = obj_a.get_child(2);
    str_cmp = strcmp(child->get_name(), "my_obj_c");
    ESYSTEST_REQUIRE_EQUAL(str_cmp, 0);

    child = obj.get_child(3);
    ESYSTEST_REQUIRE_EQUAL(child, nullptr);
}

} // namespace esys::base::em::test::objectnamemngr01
