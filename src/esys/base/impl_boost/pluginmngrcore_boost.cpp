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
#include <sstream>

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
    dir_path = boost::filesystem::absolute(dir_path).normalize().make_preferred();
    std::string the_path = dir_path.string();

    dir_path = dir_path.parent_path();

    debug(0, "load file: " + the_path);

    if (boost::filesystem::is_symlink(the_path))
    {
        int result = find_regular_file(dir, the_path);
        if (result < 0)
        {
            std::ostringstream oss;

            oss << "symlink doesn't point to a regular file: " << dir;
            error_or_debug(oss.str());
            return -1;
        }

        std::ostringstream oss;

        oss << "the_path " << the_path;
        debug(0, oss.str());
    }

    if (!boost::filesystem::is_regular_file(the_path))
    {
        std::ostringstream oss;

        oss << "This is not a file = " << the_path;
        error_or_debug(oss.str());
        return -1;
    }

    if (!boost::filesystem::is_directory(dir_path))
    {
        std::ostringstream oss;

        oss << "This is not a directory = " << dir_path.string();
        error_or_debug(oss.str());
        return -1;
    }

    auto result = set_dll_directory(dir_path.string());
    if (result < 0)
    {
        std::ostringstream oss;

        oss << "Failed to set plugin folder = " << dir_path.string();
        error(oss.str());
    }

    if (plugin_lib->load(the_path) != 0)
    {
        std::ostringstream oss;

        oss << "Failed to load the plugin.";
        error_or_debug(oss.str());

        return -1;
    }
    if (plugin_lib->has_symbol(get_entry_fct_name()) == false)
    {
        std::ostringstream oss;

        oss << "doesn't have entry fct '" << get_entry_fct_name() << "'.";
        error_or_debug(oss.str());

        return -2;
    }

    void *plugin_entry_function = plugin_lib->get_symbol(get_entry_fct_name());
    if (plugin_entry_function == nullptr)
    {
        std::ostringstream oss;
        oss << "failed to get the entry fct '" << get_entry_fct_name() << "'.";
        error_or_debug(oss.str());
        return -3;
    }

    PluginBase *plugin;
    plugin = get_plugin_from_entry_fct(plugin_entry_function);

#ifdef _MSC_VER
#ifdef _DEBUG
    if (plugin->is_debug() == false)
    {
        std::ostringstream oss;

        oss << "plugin is a release build.";
        error_or_debug(oss.str());
        return -4;
    }
#elif NDEBUG
    if (plugin->is_debug() == true)
    {
        std::ostringstream oss;

        oss << "plugin is a debug build.";
        error_or_debug(oss.str());
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

    debug(0, "plugin loaded successfully.");

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

    set_load_auto_detect(true);

    int result = 0;
    std::string abs_plugin_dir;

    result = find_plugin_folder(abs_plugin_dir);
    if (result < 0)
    {
        debug(0, "Couldn't deduce the plugin folder.");
        set_load_auto_detect(false);
        return result;
    }

    debug(0, "The plugin folder = " + abs_plugin_dir);
    if (abs_plugin_dir.empty())
    {
        debug(0, "Found plugin folder is empty.");
        set_load_auto_detect(false);
        return -2;
    }

#ifdef _MSC_VER
#ifdef _DEBUG
    debug(0, "Build type    = debug");
#elif NDEBUG
    debug(0, "Build type    = release");
#else
    debug(0, "Build type    = ?");
#endif
#endif
    debug(0, "Plugin folder = " + abs_plugin_dir);

    result = set_dll_directory(abs_plugin_dir);
    if (result < 0)
    {
        debug(0, "Failed to set plugin folder = " + abs_plugin_dir);
    }
#ifdef WIN32
    std::string ext = ".dll";
#elif __APPLE__
    std::string ext = ".dylib";
#else
    std::string ext = ".so";
#endif
    std::string mask = "*" + ext;
    boost::filesystem::path search_path = abs_plugin_dir;
    search_path /= mask;

    debug(0, "Search path   = " + search_path.string());

    boost::filesystem::directory_iterator file_end_it;

    for (boost::filesystem::directory_iterator it(abs_plugin_dir); it != file_end_it; ++it)
    {
        debug(0, "Test file = " + it->path().string());

        std::string the_path = it->path().string();
        if (boost::filesystem::is_symlink(the_path))
        {
            int result = find_regular_file(it->path().string(), the_path);
            if (result < 0)
            {
                debug(0, "this is not a regular file =  " + it->path().string());
                continue;
            }
            debug(0, "the_path = " + the_path);
        }
        if (find_plugin_abs_path(the_path) != nullptr)
        {
            if (get_verbose_level() > 0)
            {
                debug(0, "this plugin was already loaded = " + the_path);
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
                    debug(0, "wrong extension = " + it->path().string());
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

    /*if (get_verbose_level() > 0)
    {
        std::cout << std::endl;
    }*/

    set_load_auto_detect(false);
    if (!m_plugins.empty())
    {
        debug(0, "Load successfull.");
        return 0;
    }
    debug(0, "Load failed.");
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

    auto result = s_find_exe_path(exe_path);

    debug(0, "[PluginMngrCore::find_exe_path] " + exe_path);

    return result;
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

void PluginMngrCore::error_or_debug(const std::string &msg)
{
    if (get_load_auto_detect())
        debug(0, msg);
    else
        error(msg);
}

void PluginMngrCore::set_load_auto_detect(bool load_auto_detect)
{
    m_load_auto_detect = load_auto_detect;
}

bool PluginMngrCore::get_load_auto_detect() const
{
    return m_load_auto_detect;
}

} // namespace esys::base::impl_boost
