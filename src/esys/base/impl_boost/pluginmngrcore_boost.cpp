/*!
 * \file esys/base/boost/pluginmngrcore_boost.cpp
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
#include "esys/base/impl_boost/pluginmngrcore.h"

#include <boost/filesystem.hpp>

#include <iostream>

namespace esys
{

namespace base
{

namespace impl_boost
{

PluginMngrImplHelper::PluginMngrImplHelper()
{
}

PluginMngrImplHelper::~PluginMngrImplHelper()
{
}

void PluginMngrImplHelper::set_dyn_lib(std::shared_ptr<DynLibrary> &dyn_lib)
{
    m_dyn_lib = dyn_lib;
}

DynLibrary *PluginMngrImplHelper::get_dyn_lib()
{
    return m_dyn_lib.get();
}

void PluginMngrImplHelper::set_entry_point(void *entry)
{
    m_entry_fct = entry;
}

void *PluginMngrImplHelper::get_entry_point()
{
    return m_entry_fct;
}

void PluginMngrImplHelper::set_plugin(PluginBase *plugin)
{
    m_plugin = plugin;
}

PluginBase *PluginMngrImplHelper::get_plugin()
{
    return m_plugin;
}

PluginMngrCore::PluginMngrCore()
    : PluginMngrBase()
{
}

PluginMngrCore::~PluginMngrCore()
{
}

int PluginMngrCore::load(const std::string &dir)
{
    std::shared_ptr<PluginMngrImplHelper> helper;
    PluginBase *plugin;
    std::shared_ptr<DynLibrary> plugin_lib = std::make_shared<DynLibrary>();

    if (plugin_lib->load(dir) != 0) return -1;
    if (plugin_lib->has_symbol(get_entry_fct_name()) == false) return -2;

    void *plugin_entry_function = plugin_lib->get_symbol(get_entry_fct_name());
    if (plugin_entry_function == nullptr) return -3;

    plugin = get_plugin_from_entry_fct(plugin_entry_function);

#ifdef _MSC_VER
#ifdef _DEBUG
    if (plugin->is_debug() == false) return -4;
#elif NDEBUG
    if (plugin->is_debug() == true) return -5;
#else
#error _DEBUG or NDEBUG must be defined
#endif
#endif
    helper = std::make_shared<PluginMngrImplHelper>();

    helper->set_dyn_lib(plugin_lib);
    helper->set_entry_point(plugin_entry_function);
    helper->set_plugin(plugin);
    set_plugin_filename(plugin, dir);

    m_plugins.push_back(helper);
    return 0;
}

int PluginMngrCore::load()
{
    if (get_is_loaded()) return -1;

    int result = 0;
    boost::filesystem::path abs_plugin_dir;
    boost::filesystem::path plugin_dir;
    boost::filesystem::path filename;
    boost::filesystem::directory_iterator file_end_it;
    DynLibrary *plugin_lib = nullptr;

    if (!get_base_folder().empty())
    {
        filename = get_base_folder();
        filename /= get_search_folder();
    }
    else
        filename = get_search_folder();
    filename = ::boost::filesystem::absolute(filename);

    abs_plugin_dir = filename;

    if (get_verbose_level() > 0)
    {
        std::cout << "Plugin folder = " << abs_plugin_dir.c_str() << std::endl;
    }
#ifdef WIN32
    SetDllDirectory(abs_plugin_dir.string().c_str());
#endif

#ifdef WIN32
    std::string mask = "*.dll";
#else
    std::string mask = "*.so";
#endif
    boost::filesystem::path search_path = abs_plugin_dir / mask;

    for (::boost::filesystem::directory_iterator it(abs_plugin_dir); it != file_end_it; ++it)
    {
        // If it's not a directory, list it. If you want to list directories too, just remove this check.
        if (!::boost::filesystem::is_regular_file(it->path())) continue;

        // assign current file name to current_file and echo it out to the console.
        std::string current_file = it->path().string();
        result = load(current_file);
    }
    set_is_loaded(true);

    return result;
}

int PluginMngrCore::release()
{
    uint16_t idx;

    for (idx = 0; idx < m_plugins.size(); ++idx)
    {
        assert(m_plugins[idx]->get_plugin() != nullptr);

        m_plugins[idx]->get_plugin()->release();
        m_plugins[idx].reset();
    }
    m_plugins.clear();
    set_is_loaded(false);

    return 0;
}

std::size_t PluginMngrCore::get_size()
{
    return m_plugins.size();
}

PluginBase *PluginMngrCore::get_base(std::size_t index)
{
    if (index >= m_plugins.size()) return nullptr;
    return m_plugins[index]->get_plugin();
}

} // namespace impl_boost

} // namespace base

} // namespace esys
