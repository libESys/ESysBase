/*!
 * \file esys/base/stdcpp/test/nodemngr01_stdcppcpp
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

#include <esys/base/stdcpp/nodemngr.h>
#include <esys/base/stdcpp/object.h>

#include <iostream>

namespace esys
{

namespace base
{

namespace stdcpp
{

namespace test
{

namespace nodemngr01
{

class MyObject : public Object
{
public:
    MyObject(const ObjectName &name);

protected:
    Object m_obj_a{"obj_a"};
    Object m_obj_b{"obj_b"};
};

MyObject::MyObject(const ObjectName &name)
    : Object(name)
{
}

class ObjectA : public Object
{
public:
    ObjectA(const ObjectName &name);

protected:
    MyObject m_my_obj_a{"my_obj_a"};
    MyObject m_my_obj_b{"my_obj_b"};
    MyObject m_my_obj_c{"my_obj_c"};
};

ObjectA::ObjectA(const ObjectName &name)
    : Object(name)
{
}

class NodeA : public Node
{
public:
    NodeA(const ObjectName &name);

protected:
    ObjectA m_obj_a{"obj_a"};
};

NodeA::NodeA(const ObjectName &name)
    : Node(name)
{
}

class NodeB : public Node
{
public:
    NodeB(const ObjectName &name);

protected:
    MyObject m_my_obj{"my_obj"};
    ObjectA m_obj_b{"obj_b"};
};

NodeB::NodeB(const ObjectName &name)
    : Node(name)
{
}

/*! \class ObjectNameMngr01 esys/base/em/test/objectnamemngr01.cpp "esys/base/em/test/objectnamemngr01.cpp"
 *
 *  \brief
 */
ESYSTEST_AUTO_TEST_CASE(NodeMngr01StdCpp)
{
    NodeMngr::get().clear();
    NodeMngr::get().init();

    std::shared_ptr<NodeA> node_a = std::make_shared<NodeA>("NodeA");
    NodeMngr::get().add(node_a);

    std::shared_ptr<NodeB> node_b = std::make_shared<NodeB>("NodeB");
    NodeMngr::get().add(node_b);

    ESYSTEST_REQUIRE_EQUAL(NodeMngr::get().get_size(), 2);

    auto node0 = NodeMngr::get().get_node(0);
    ESYSTEST_REQUIRE_EQUAL(node0->get_name_str(), "NodeA");
    ESYSTEST_REQUIRE_EQUAL(node0->get_children_count(), 1);

    auto node1 = NodeMngr::get().get_node(1);
    ESYSTEST_REQUIRE_EQUAL(node1->get_name_str(), "NodeB");
    ESYSTEST_REQUIRE_EQUAL(node1->get_children_count(), 2);

    auto obj = node1->get_child(0);
    ESYSTEST_REQUIRE_NE(obj, nullptr);
    ESYSTEST_REQUIRE_EQUAL(obj->get_name_str(), "my_obj");
    
    obj = node1->get_child(1);
    ESYSTEST_REQUIRE_NE(obj, nullptr);
    ESYSTEST_REQUIRE_EQUAL(obj->get_name_str(), "obj_b");

    ESYSTEST_REQUIRE_EQUAL(obj->get_children_count(), 3);
}

} // namespace nodemngr01

} // namespace test

} // namespace stdcpp

} // namespace base

} // namespace esys
