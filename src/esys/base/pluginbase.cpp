/*!
 * \file esys/base/pluginbase.cpp
 * \brief
 *
 * \cond
 * __legal_b__
 *
 * Copyright (c) 2017-2020 Michel Gillet
 * Distributed under the wxWindows Library Licence, Version 3.1.
 * (See accompanying file LICENSE_3_1.txt or
 * copy at http://www.wxwidgets.org/about/licence)
 *
 * __legal_e__
 * \endcond
 *
 */

#include "esys/base/esysbase_prec.h"
#include "esys/base/pluginbase.h"

namespace esys::base
{

const std::string PluginBase::s_entry_fct_name = "get_base_plugin";

PluginBase::PluginBase() = default;

PluginBase::~PluginBase() = default;

std::string &PluginBase::get_name()
{
    return m_name;
}

std::string &PluginBase::get_short_name()
{
    return m_short_name;
}

std::string &PluginBase::get_version()
{
    return m_version;
}

bool PluginBase::is_debug() const
{
    return m_is_debug;
}

int PluginBase::init()
{
    return 0;
}

int PluginBase::release()
{
    return 0;
}

int PluginBase::run(const std::vector<std::string> &cmd_line, const po::variables_map &vm)
{
    return 0;
}

std::size_t PluginBase::get_options_desc_count()
{
    return m_options_desc.size();
}

po::options_description *PluginBase::get_options_desc(std::size_t idx)
{
    if (idx < m_options_desc.size()) return m_options_desc[idx];
    return nullptr;
}

void PluginBase::add_options_desc(po::options_description *options_desc)
{
    m_options_desc.push_back(options_desc);
}

void PluginBase::set_debug(bool debug)
{
    m_is_debug = debug;
}

void PluginBase::set_name(const std::string &name)
{
    m_name = name;
}

void PluginBase::set_short_name(const std::string &short_name)
{
    m_short_name = short_name;
}

void PluginBase::set_version(const std::string &version)
{
    m_version = version;
}

const ::boost::filesystem::path &PluginBase::get_path() const
{
    return m_path;
}

void PluginBase::set_path(const ::boost::filesystem::path &path)
{
    m_path = path;
}

std::string &PluginBase::get_filename()
{
    return m_filename;
}

void PluginBase::set_filename(const std::string &filename)
{
    m_filename = filename;
}

} // namespace esys::base
