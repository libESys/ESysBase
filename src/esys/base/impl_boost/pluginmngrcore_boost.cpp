/*!
 * \file esys/base/boost/pluginmngrcore_boost.cpp
 * \brief
 *
 * \cond
 * __legal_b__
 *
 * Copyright (c) 2017-2022 Michel Gillet
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
#include <boost/dll/runtime_symbol_info.hpp>

#include <iostream>

namespace esys::base::impl_boost
{

PluginMngrImplHelper::PluginMngrImplHelper() = default;

PluginMngrImplHelper::~PluginMngrImplHelper() = default;

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

PluginMngrCore::PluginMngrCore(const std::string &name)
    : PluginMngrBase(name)
{
}

PluginMngrCore::~PluginMngrCore() = default;

int PluginMngrCore::load(const std::string &dir, PluginBase **plugin_base)
{
    auto plugin_lib = std::make_shared<DynLibrary>();
    boost::filesystem::path dir_path = dir;
    dir_path = dir_path.parent_path();

    std::string the_path = dir;
    if (boost::filesystem::is_symlink(the_path))
    {
        int result = find_regular_file(dir, the_path);
        if (result < 0)
        {
            std::cout << "    symlink doesn't point to a regular file: " << dir << std::endl;
            return -1;
        }
        std::cout << "the_path" << the_path << std::endl;
    }

    if (!boost::filesystem::is_regular_file(the_path))
    {
        std::cout << "This is not a file = " << dir_path << std::endl;
        return -1;
    }

    if (!boost::filesystem::is_directory(dir_path))
    {
        std::cout << "This is not a directory = " << dir_path.string() << std::endl;
        return -1;
    }

    auto result = set_dll_directory(dir_path.string());
    if (result < 0)
    {
        std::cout << "Failed to set plugin folder = " << dir_path.string() << std::endl;
    }

    if (plugin_lib->load(the_path) != 0)
    {
        if (get_verbose_level() > 0)
        {
            std::cout << "    failed to load the plugin." << std::endl;
        }
        return -1;
    }
    if (plugin_lib->has_symbol(get_entry_fct_name()) == false)
    {
        if (get_verbose_level() > 0)
        {
            std::cout << "    doesn't have entry fct '" << get_entry_fct_name() << "'." << std::endl;
        }
        return -2;
    }

    void *plugin_entry_function = plugin_lib->get_symbol(get_entry_fct_name());
    if (plugin_entry_function == nullptr)
    {
        if (get_verbose_level() > 0)
        {
            std::cout << "    failed to get the entry fct '" << get_entry_fct_name() << "'." << std::endl;
        }
        return -3;
    }

    PluginBase *plugin;
    plugin = get_plugin_from_entry_fct(plugin_entry_function);

#ifdef _MSC_VER
#ifdef _DEBUG
    if (plugin->is_debug() == false)
    {
        if (get_verbose_level() > 0)
        {
            std::cout << "    plugin is a release build." << std::endl;
        }
        return -4;
    }
#elif NDEBUG
    if (plugin->is_debug() == true)
    {
        if (get_verbose_level() > 0)
        {
            std::cout << "    plugin is a debug build." << std::endl;
        }
        return -5;
    }
#else
#error _DEBUG or NDEBUG must be defined
#endif
#endif
    if (plugin_base != nullptr) *plugin_base = plugin;

    std::shared_ptr<PluginMngrImplHelper> helper;

    helper = std::make_shared<PluginMngrImplHelper>();

    helper->set_dyn_lib(plugin_lib);
    helper->set_entry_point(plugin_entry_function);
    helper->set_plugin(plugin);
    set_plugin_filename(plugin, the_path);

    m_plugins.push_back(helper);
    if (get_verbose_level() > 0)
    {
        std::cout << "    plugin loaded successfully." << std::endl;
    }
    return 0;
}

int PluginMngrCore::set_dll_directory(const std::string &dir, bool only_if_different)
{
    if (only_if_different && (dir == m_set_dll_directory)) return 0;

#ifdef WIN32
    bool result = SetDllDirectory(dir.c_str());
    if (!result) return -1;
#endif
    m_set_dll_directory = dir;
    return 0;
}

int PluginMngrCore::find_regular_file(const std::string &symlink, std::string &regular_file)
{
    boost::filesystem::path temp = symlink;
    int count = 10;
    regular_file = "";

    while (boost::filesystem::is_symlink(temp) && (count > 0))
    {
        temp = boost::filesystem::read_symlink(temp);
        --count;
    }

    if (boost::filesystem::is_regular_file(temp))
    {
        regular_file = boost::filesystem::absolute(temp).string();
        return 0;
    }
    return -1;
}

int PluginMngrCore::load()
{
    if (get_is_loaded()) return -1;

    int result = 0;
    std::string abs_plugin_dir;

    result = find_plugin_folder(abs_plugin_dir);
    if (result < 0)
    {
        if (get_verbose_level() > 0)
        {
            std::cout << "Couldn't deduce the plugin folder." << std::endl;
        }
        return result;
    }
    if (abs_plugin_dir.empty())
    {
        if (get_verbose_level() > 0)
        {
            std::cout << "Found plugin folder is empty." << std::endl;
        }
        return -2;
    }

#ifdef _MSC_VER
#ifdef _DEBUG

    if (get_verbose_level() > 0)
    {
        std::cout << "Build type    = debug" << std::endl;
    }

#elif NDEBUG
    if (get_verbose_level() > 0)
    {
        std::cout << "Build type    = release" << std::endl;
    }
#else
    if (get_verbose_level() > 0)
    {
        std::cout << "Build type    = ?" << std::endl;
    }
#endif
#endif

    if (get_verbose_level() > 0)
    {
        std::cout << "Plugin folder = " << abs_plugin_dir.c_str() << std::endl;
    }

    result = set_dll_directory(abs_plugin_dir);
    if (result < 0)
    {
        std::cout << "Failed to set plugin folder = " << abs_plugin_dir.c_str() << std::endl;
    }
#ifdef WIN32
    std::string ext = ".dll";
#else
    std::string ext = ".so";
#endif
    std::string mask = "*" + ext;
    boost::filesystem::path search_path = abs_plugin_dir;
    search_path /= mask;

    if (get_verbose_level() > 0)
    {
        std::cout << "Search path   = " << search_path.string() << std::endl << std::endl;
    }

    boost::filesystem::directory_iterator file_end_it;

    for (boost::filesystem::directory_iterator it(abs_plugin_dir); it != file_end_it; ++it)
    {
        if (get_verbose_level() > 0)
        {
            std::cout << "Test file = " << it->path().string() << std::endl;
        }
        // If it's not a directory, list it. If you want to list directories too, just remove this check.
        if (!boost::filesystem::is_regular_file(it->path()))
        {
            if (get_verbose_level() > 0)
            {
                std::cout << "    not a regular file." << std::endl;
            }
            continue;
        }
        std::string the_path = it->path().string();
        if (boost::filesystem::is_symlink(the_path))
        {
            int result = find_regular_file(it->path().string(), the_path);
            if (result < 0)
            {
                if (get_verbose_level() > 0)
                {
                    std::cout << "    this is not a regular file: " << it->path() << std::endl;
                }
                continue;
            }
            std::cout << "the_path" << the_path << std::endl;
        }
        if (find_plugin_abs_path(the_path) != nullptr)
        {
            if (get_verbose_level() > 0)
            {
                std::cout << "    this plugin was already loaded: " << the_path << "." << std::endl;
            }
            continue;
        }
        if (it->path().extension() != ext)
        {
            // Needed because .so file can have version like .so.0.1.0
            auto temp_str = it->path().filename().string();
            auto idx = temp_str.find(ext);
            if (idx == std::string::npos)
            {
                idx = temp_str.find(ext + ".");
                if (idx == std::string::npos)
                {
                    if (get_verbose_level() > 0)
                    {
                        std::cout << "    wrong extension : " << it->path() << std::endl;
                    }
                    continue;
                }
            }
        }

        // assign current file name to current_file and echo it out to the console.
        std::string current_file = the_path;
        PluginBase *plugin;
        result = load(current_file, &plugin);
        if (result == 0) add_plugin_abs_path(the_path, plugin);
    }
    set_is_loaded(true);

    if (get_verbose_level() > 0)
    {
        std::cout << std::endl;
    }

    if (!m_plugins.empty()) return 0;
    return -1;
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

void PluginMngrCore::set_plugin_path_without_prefix_valid(bool plugin_path_without_prefix_valid)
{
    m_plugin_path_without_prefix_valid = plugin_path_without_prefix_valid;
}

bool PluginMngrCore::get_plugin_path_without_prefix_valid() const
{
    return m_plugin_path_without_prefix_valid;
}

int PluginMngrCore::find_exe_path(std::string &exe_path)
{
    return s_find_exe_path(exe_path);
}

int PluginMngrCore::find_plugin_folder(std::string &plugin_folder)
{
    int result = 0;
    boost::filesystem::path exe_folder;

    std::vector<std::string> search_paths;

    if (get_search_folder().empty())
    {
        boost::filesystem::path search_path;
        std::string path;
        result = find_exe_path(path);
        if (result < 0) return -2;
        search_path = path;
        search_path = search_path.parent_path(); // Remove the executable name
        exe_folder = search_path;
#ifndef WIN32
        // To get to the parent of bin folder
        search_path = search_path.parent_path();
        auto search_path_str = search_path.string();
        search_path /= "lib";
        search_paths.push_back(search_path.string());
        search_path = search_path_str;
#endif
        search_paths.push_back(search_path.string());
    }
    else
        search_paths.push_back(get_search_folder());

    char const *value = nullptr;

    for (auto const &env_var_search_path : get_env_var_search_folders())
    {
        value = std::getenv(env_var_search_path.c_str());
        if (value == nullptr) continue;
        search_paths.push_back(value);
    }

    if (!get_base_folder().empty())
    {
        search_paths.push_back(get_base_folder());
    }

    boost::filesystem::path path_to_test;

    std::string rel_plugin_path;
    result = get_rel_plugin_path(rel_plugin_path);
    if (result < 0) return -3;

    result = search_existing_folder(search_paths, rel_plugin_path, plugin_folder);
    if (result == 0) return 0;

    if (!get_plugin_path_without_prefix_valid()) return -1;

    return search_existing_folder(search_paths, rel_plugin_path, plugin_folder, false);
}

int PluginMngrCore::search_existing_folder(const std::vector<std::string> &search_paths,
                                           const std::string &rel_plugin_path, std::string &plugin_folder,
                                           bool use_rel_plugin_path) const
{
    boost::filesystem::path path_to_test;

    for (auto const &search_path : search_paths)
    {
        path_to_test = search_path;
        if (use_rel_plugin_path) path_to_test /= rel_plugin_path;
        path_to_test = ::boost::filesystem::absolute(path_to_test).normalize().make_preferred();
        if (boost::filesystem::exists(path_to_test))
        {
            plugin_folder = path_to_test.string();
            return 0;
        }
    }
    plugin_folder = "";
    return -1;
}

int PluginMngrCore::s_find_exe_path(std::string &exe_path)
{
    boost::filesystem::path p;
    boost::system::error_code ec;

    p = boost::dll::program_location(ec);
    if (ec) return -1;

    exe_path = p.normalize().make_preferred().string();
    return 0;
}

} // namespace esys::base::impl_boost
