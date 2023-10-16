/*!
 * \file esys/base/pluginmngrbase.cpp
 * \brief
 *
 * \cond
 * __legal_b__
 *
 * Copyright (c) 2017-2023 Michel Gillet
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

#include <esys/trace/call.h>
#include <esys/trace/macros.h>

#include <boost/filesystem.hpp>
#include <boost/locale.hpp>
#include <boost/algorithm/string.hpp>

#include <sstream>
#include <memory>

namespace esys::base
{

void PluginMngrBase::set_plugin_filename(PluginBase *plugin, const std::string &filename)
{
    plugin->set_filename(filename);
}

PluginMngrBase::PluginMngrBase(const std::string &name)
    : m_name(name)
{
}

PluginMngrBase::~PluginMngrBase() = default;

void PluginMngrBase::set_name(const std::string &name)
{
    m_name = name;
}

const std::string &PluginMngrBase::get_name() const
{
    return m_name;
}

void PluginMngrBase::set_version(const Version &version)
{
    m_version = version;
}

const Version &PluginMngrBase::get_version() const
{
    return m_version;
}

Version &PluginMngrBase::get_version()
{
    return m_version;
}

void PluginMngrBase::set_search_folder(const std::string &search_folder)
{
    m_search_folder = search_folder;
}

const std::string &PluginMngrBase::get_search_folder() const
{
    return m_search_folder;
}

void PluginMngrBase::add_env_var_search_folder(const std::string &env_var_search_folder)
{
    m_env_var_search_folders.push_back(env_var_search_folder);
}

std::vector<std::string> &PluginMngrBase::get_env_var_search_folders()
{
    return m_env_var_search_folders;
}

const std::vector<std::string> &PluginMngrBase::get_env_var_search_folders() const
{
    return m_env_var_search_folders;
}

void PluginMngrBase::set_is_loaded(bool is_loaded)
{
    m_is_loaded = is_loaded;
}

bool PluginMngrBase::get_is_loaded() const
{
    return m_is_loaded;
}

int PluginMngrBase::find_plugin_path_rel_exe(const std::string &plugin_name, std::string &plugin_path)
{
    std::string exe_path;
    boost::filesystem::path plugin_path_;

    plugin_path = "";

    int result = find_exe_path(exe_path);
    if (result < 0) return result;

    plugin_path_ = exe_path;
    plugin_path_ = plugin_path_.parent_path();
#ifndef WIN32
    plugin_path_ /= "..";
    plugin_path_ /= "lib";
    plugin_path_ /= "lib" + plugin_name + ".so";
#else
    plugin_path_ /= plugin_name + ".dll";
#endif
    plugin_path = plugin_path_.string();
    return 0;
}

int PluginMngrBase::get_rel_plugin_path(std::string &rel_plugin_path)
{
    boost::filesystem::path p;

#ifdef WIN32
    p = "plugins";
    p /= get_name();
    rel_plugin_path = p.make_preferred().string();
    return 0;
#else
    std::ostringstream oss;
    oss << get_version().get_major();

    p = get_name();
    p /= oss.str();
    p /= "plugins";
    rel_plugin_path = p.make_preferred().string();
    return 0;
#endif
}

void PluginMngrBase::set_verbose_level(uint32_t verbose_level)
{
    m_verbose_level = verbose_level;
}

uint32_t PluginMngrBase::get_verbose_level() const
{
    return m_verbose_level;
}

const std::string &PluginMngrBase::get_entry_fct_name() const
{
    return m_entry_fct_name;
}

PluginBase *PluginMngrBase::get_plugin_from_entry_fct(void *entry_fct)
{
    auto the_entry_fct = (PluginBaseEntryFunction)entry_fct;
    PluginBase *plugin;

    assert(entry_fct != nullptr);

    plugin = (*the_entry_fct)();

    return plugin;
}

void PluginMngrBase::set_log_if(std::shared_ptr<Log_if> log_if)
{
    m_log_if = log_if;
}

std::shared_ptr<Log_if> PluginMngrBase::get_log_if() const
{
    return m_log_if;
}

void PluginMngrBase::trace(const std::string &msg)
{
    ETRC_CALL(msg);

    if (m_log_if)
    {
        m_log_if->trace(msg);
        return;
    }
}

void PluginMngrBase::debug(int level, const std::string &msg)
{
    ETRC_CALL(level, msg);

    if (m_log_if)
    {
        m_log_if->debug(level, msg);
        return;
    }
}

void PluginMngrBase::debug_helper(int level, const std::string &msg, const std::vector<std::string> &strings)
{
    std::ostringstream oss;

    oss << msg << " (count = " << strings.size() << "):";

    for (auto idx = 0; idx < strings.size(); ++idx)
    {
        oss << std::endl << "[" << idx << "] " << strings[idx];
    }

    debug(level, oss.str());
}

void PluginMngrBase::info(const std::string &msg)
{
    ETRC_CALL(msg);

    if (m_log_if)
    {
        m_log_if->info(msg);
        return;
    }
}

void PluginMngrBase::warn(const std::string &msg)
{
    ETRC_CALL(msg);

    if (m_log_if)
    {
        m_log_if->warn(msg);
        return;
    }
}

void PluginMngrBase::error(const std::string &msg)
{
    ETRC_CALL(msg);

    if (m_log_if)
    {
        m_log_if->error(msg);
        return;
    }
}

void PluginMngrBase::critical(const std::string &msg)
{
    ETRC_CALL(msg);

    if (m_log_if)
    {
        m_log_if->critical(msg);
        return;
    }
}

void PluginMngrBase::set_entry_fct_name(const std::string &entry_fct_name)
{
    m_entry_fct_name = entry_fct_name;
}

PluginBase *PluginMngrBase::find_plugin_abs_path(const std::string &abs_path) const
{
    boost::filesystem::path path = boost::filesystem::absolute(abs_path);

    auto it = m_abs_path_plugin_map.find(path.string());

    if (it == m_abs_path_plugin_map.end()) return nullptr;
    return it->second;
}

void PluginMngrBase::add_plugin_abs_path(const std::string &abs_path, PluginBase *plugin)
{
    boost::filesystem::path path = boost::filesystem::absolute(abs_path);

    if (find_plugin_abs_path(path.string()) != nullptr) return;

    m_abs_path_plugin_map[path.string()] = plugin;
}

int PluginMngrBase::load_if_not_loaded()
{
    int result = 0;

    if (!get_is_loaded()) result = load();

    return result;
}

} // namespace esys::base
