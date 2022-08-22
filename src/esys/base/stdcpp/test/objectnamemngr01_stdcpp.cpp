/*!
 * \file esys/base/stdcpp/test/objectnamemngr01_stdcpp.cpp
 * \brief
 *
 * \cond
 * __legal_b__
 *
 * __legal_e__
 * \endcond
 *
 */

#include "esys/base/test/esysbase_t_prec.h"

#include <esys/base/stdcpp/objectnamemngr.h>
#include <esys/base/stdcpp/object.h>
#include <esys/base/stdcpp/nodemngr.h>

#include <iostream>

namespace esys
{

namespace base
{

namespace stdcpp
{

namespace test
{

namespace objectnamemngr01
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

protected:
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
    MyObject m_my_obj_a{"my_obj_a"};
    MyObject m_my_obj_b{"my_obj_b"};
    MyObject m_my_obj_c{"my_obj_c"};
};

ObjectA::ObjectA(const ObjectName &name)
    : MyObjectBase(name)
{
}

/*! \class ObjectNameMngr01 esys/base/em/test/objectnamemngr01.cpp "esys/base/em/test/objectnamemngr01.cpp"
 *
 *  \brief
 */
ESYSTEST_AUTO_TEST_CASE(ObjectNameMngr01StdCpp)
{
    NodeMngr::get().clear();
    NodeMngr::get().init();

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

} // namespace objectnamemngr01

} // namespace test

} // namespace stdcpp

} // namespace base

} // namespace esys
