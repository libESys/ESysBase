/*!
 * \file esys/base/stdcpp/nodemngr_stdcpp
 * \brief Header file of the NodeMngr class
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

#include "esys/base/esysbase_prec.h"
#include "esys/base/stdcpp/nodemngr.h"

#include <cassert>

namespace esys
{

namespace base
{

namespace stdcpp
{

std::unique_ptr<NodeMngr> NodeMngr::s_mngr;

NodeMngr &NodeMngr::get()
{
    if (s_mngr == nullptr) s_mngr = std::make_unique<NodeMngr>();

    return *s_mngr.get();
}

NodeMngr::NodeMngr()
{
}

NodeMngr::~NodeMngr()
{
}

void NodeMngr::add(std::shared_ptr<Node> node)
{
    auto it = m_map_name_node.find(node->get_name());
    assert(it == m_map_name_node.end());

    m_map_name_node[node->get_name()] = node;
    m_nodes.push_back(node);
}

std::shared_ptr<Node> NodeMngr::find(const std::string &name)
{
    auto it = m_map_name_node.find(name);

    if (it == m_map_name_node.end()) return nullptr;

    return it->second;
}

std::shared_ptr<Node> NodeMngr::find(std::thread::id thread_id)
{
    auto it = m_map_thread_id_node.find(thread_id);

    if (it == m_map_thread_id_node.end()) return nullptr;

    return it->second;
}

std::shared_ptr<Node> NodeMngr::find()
{
    return find(std::this_thread::get_id());
}

bool NodeMngr::has(const std::shared_ptr<Node> node)
{
    auto it = m_map_name_node.find(node->get_name());

    if (it == m_map_name_node.end()) return false;
    return true;
}

std::size_t NodeMngr::get_size()
{
    return m_nodes.size();
}

std::shared_ptr<Node> NodeMngr::get_node(std::size_t idx)
{
    if (idx >= m_nodes.size()) return nullptr;

    return m_nodes[idx];
}

void NodeMngr::set_thread_id(std::shared_ptr<Node> node, std::thread::id id)
{
    if (!has(node)) add(node);

    m_map_thread_id_node[id] = node;
}

void NodeMngr::init()
{
    set_main_thread_id(std::this_thread::get_id());
}

void NodeMngr::clear()
{
    m_nodes.clear();
    m_map_name_node.clear();
    m_map_thread_id_node.clear();
}

void NodeMngr::set_main_thread_id(std::thread::id main_thread_id)
{
    m_main_thread_id = main_thread_id;
    m_is_main_thread_id_set = true;
}

std::thread::id NodeMngr::get_main_thread_id() const
{
    return m_main_thread_id;
}

bool NodeMngr::is_main_thread_id_set()
{
    return m_is_main_thread_id_set;
}

} // namespace stdcpp

} // namespace base

} // namespace esys
