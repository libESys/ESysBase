/*!
 * \file esys/base/stdcpp/nodemngr.h
 * \brief Header file of the Node class
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
#include "esys/base/stdcpp/node.h"

#include <string>
#include <map>
#include <vector>
#include <memory>
#include <thread>

namespace esys
{

namespace base
{

namespace stdcpp
{

/*! \class NodeMngr esys/base/stdcpp/nodemngr.h "esys/base/stdcpp/nodemngr.h"
 *  \brief
 */
class ESYSBASE_API NodeMngr
{
public:
    //! Default Constructor
    NodeMngr();

    //! Destructor
    virtual ~NodeMngr();

    void add(std::shared_ptr<Node> node);
    void set_thread_id(std::shared_ptr<Node> node, std::thread::id id);
    void init();
    void clear();

    void set_main_thread_id(std::thread::id main_thread_id);
    std::thread::id get_main_thread_id() const;
    bool is_main_thread_id_set() const;

    std::shared_ptr<Node> find(const std::string &name);
    std::shared_ptr<Node> find(std::thread::id thread_id);
    std::shared_ptr<Node> find();

    std::size_t get_size();
    std::shared_ptr<Node> get_node(std::size_t idx);

    bool has(const std::shared_ptr<Node> node);

    static NodeMngr &get();

protected:
    //!< \cond DOXY_IMPL
    static std::unique_ptr<NodeMngr> s_mngr;

    std::thread::id m_main_thread_id;
    bool m_is_main_thread_id_set = false;
    std::vector<std::shared_ptr<Node>> m_nodes;
    std::map<std::string, std::shared_ptr<Node>> m_map_name_node;
    std::map<std::thread::id, std::shared_ptr<Node>> m_map_thread_id_node;
    //!< \endcond
};

} // namespace stdcpp

} // namespace base

} // namespace esys
