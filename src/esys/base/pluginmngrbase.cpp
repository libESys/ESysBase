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
#include <boost/algorithm/string.hpp>

#include <sstream>
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

PluginMngrBase::PluginMngrBase(const std::string &name) : m_name(name)
{
}

PluginMngrBase::~PluginMngrBase()
{
}

void PluginMngrBase::set_name(const std::string &name)
{
    m_name = name;
}

const std::string &PluginMngrBase::get_name() const
{
    return m_name;
}

void PluginMngrBase::set_version(const std::string &version)
{
    std::vector<std::string> versions;

    m_version = version;

    boost::split(versions,version,boost::is_any_of("."));

    if (versions.size() < 1) return;
    set_major_version(atoi(versions[0].c_str()));
}

void PluginMngrBase::set_version(int major, int minor, int patch)
{
    m_major_version = major;
    m_minor_version = minor;
    m_patch_version = patch;
}

const std::string &PluginMngrBase::get_version()
{
    if (m_version.empty())
    {
        std::ostringstream oss;

        oss << m_major_version;
        if (m_minor_version > 0)
        {
            oss << "." << m_minor_version;
            if (m_patch_version > 0) oss << "." << m_patch_version;
        }
        m_version = oss.str(); 
    }
    return m_version;
}

void PluginMngrBase::get_version(int &major, int &minor, int &patch)
{
    major = m_major_version;
    minor = m_minor_version;
    patch = m_patch_version;
}

void PluginMngrBase::set_major_version(int major_version)
{
    m_major_version = major_version;
    m_version.clear();

}

int PluginMngrBase::get_major_version() const
{
    return m_major_version;
}

void PluginMngrBase::set_minor_version(int minor_version)
{
    m_minor_version = minor_version;;
}

int PluginMngrBase::get_minor_version() const
{
    return m_minor_version;
}

void PluginMngrBase::set_patch_version(int patch_version)
{
    m_patch_version = patch_version;
}

int PluginMngrBase::get_patch_version() const
{
    return m_patch_version;
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
    oss << get_major_version();

    p = "lib";
    p /= get_name();
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

int PluginMngrBase::load_if_not_loaded()
{
    int result = 0;

    if (!get_is_loaded()) result = load();

    return result;
}

} // namespace base

} // namespace esys
