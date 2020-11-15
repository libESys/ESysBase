/*!
 * \file esys/base/pluginmngrbase.cpp
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
#include "esys/base/pluginmngrbase.h"
#include "esys/base/pluginbase.h"

#include <boost/filesystem.hpp>
#include <boost/locale.hpp>

#include <memory>

namespace esys
{

namespace base
{

std::string PluginMngrBase::m_base_folder;
std::string PluginMngrBase::m_app_exe;

void PluginMngrBase::set_base_folder(const std::string &base_folder)
{
    m_base_folder = base_folder;
}

const std::string &PluginMngrBase::get_base_folder()
{
    return m_base_folder;
}

void PluginMngrBase::set_app_exe(const std::string &app_exe)
{
    m_app_exe = app_exe;

    boost::filesystem::path exe_path = app_exe;
    exe_path.remove_filename();
    if (!exe_path.is_absolute()) exe_path = boost::filesystem::absolute(exe_path);
    exe_path.normalize();
    set_base_folder(exe_path.generic_string());
}

const std::string &PluginMngrBase::get_app_exe()
{
    return m_app_exe;
}

void PluginMngrBase::set_plugin_filename(PluginBase *plugin, const std::string &filename)
{
    plugin->set_filename(filename);
}

PluginMngrBase::PluginMngrBase()
{
}

PluginMngrBase::~PluginMngrBase()
{
}

void PluginMngrBase::set_search_folder(const std::string &search_folder)
{
    m_search_folder = search_folder;
}

const std::string &PluginMngrBase::get_search_folder() const
{
    return m_search_folder;
}

void PluginMngrBase::set_is_loaded(bool is_loaded)
{
    m_is_loaded = is_loaded;
}

bool PluginMngrBase::get_is_loaded() const
{
    return m_is_loaded;
}

void PluginMngrBase::set_verbose_level(uint32_t verbose_level)
{
    m_verbose_level = verbose_level;
}

uint32_t PluginMngrBase::get_verbose_level()
{
    return m_verbose_level;
}

const std::string &PluginMngrBase::get_entry_fct_name() const
{
    return m_entry_fct_name;
}

void PluginMngrBase::set_entry_fct_name(const std::string &entry_fct_name)
{
    m_entry_fct_name = entry_fct_name;
}

} // namespace base

} // namespace esys
