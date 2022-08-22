/*!
 * \file esys/base/pluginmngrbase.h
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

#pragma once

#include "esys/base/esysbase_defs.h"
#include "esys/base/pluginbase.h"

#include <vector>
#include <string>
#include <map>
#include <memory>

namespace esys::base
{

/*! \class PluginMngrBase esys/base/pluginmngrbase.h "esys/base/pluginmngrbase.h"
 * \brief Base class for all plugin managers
 */
class ESYSBASE_API PluginMngrBase
{
public:
    //! Default constructor
    /*!
     * \param[in] name the name of the Plugin Manager
     */
    PluginMngrBase(const std::string &name = "");

    //! Destructor
    virtual ~PluginMngrBase();

    //! Set the name of the Plugin Manager
    /*!
     * \param[in] name the name of the Plugin Manager
     */
    void set_name(const std::string &name);

    //! Get the name of the Plugin Manager
    /*!
     * \return the name of the Plugin Manager
     */
    const std::string &get_name() const;

    //! Set the version of the Plugin Manager
    /*!
     * \param[in] version the version of the Plugin Manager
     */
    void set_version(const std::string &version);

    //! Set the version of the Plugin Manager
    /*!
     * \param[in] major the major version of the Plugin Manager
     * \param[in] minor the minor version of the Plugin Manager
     * \param[in] patch the pacth version of the Plugin Manager
     */
    void set_version(int major, int minor, int patch = 0);

    //! Get the version of the Plugin Manager
    /*!
     * \return the version of the Plugin Manager
     */
    const std::string &get_version();

    //! Get the version of the Plugin Manager
    /*!
     * \param[out] major the major version of the Plugin Manager
     * \param[out] minor the minor version of the Plugin Manager
     * \param[out] patch the pacth version of the Plugin Manager
     */
    void get_version(int &major, int &minor, int &patch) const;

    //! Set the major version of the Plugin Manager
    /*!
     * \param[in] major the major version of the Plugin Manager
     */
    void set_major_version(int major_version);

    //! Get the major version of the Plugin Manager
    /*!
     * \return the major version of the Plugin Manager
     */
    int get_major_version() const;

    //! Set the minor version of the Plugin Manager
    /*!
     * \param[in] minor the minor version of the Plugin Manager
     */
    void set_minor_version(int minor_version);

    //! Get the minor version of the Plugin Manager
    /*!
     * \return the minor version of the Plugin Manager
     */
    int get_minor_version() const;

    //! Set the patch version of the Plugin Manager
    /*!
     * \param[in] patch the pacth version of the Plugin Manager
     */
    void set_patch_version(int patch_version);

    //! Get the patch version of the Plugin Manager
    /*!
     * \return the pacth version of the Plugin Manager
     */
    int get_patch_version() const;

    //! Set the folder where to find plugins
    /*!
     * \param[in] search_folder the folder where to find plugins
     */
    virtual void set_search_folder(const std::string &search_folder);

    //! Get the folder where to find plugins
    /*!
     * \return the folder where to find plugins
     */
    const std::string &get_search_folder() const;

    void add_env_var_search_folder(const std::string &env_var_search_folder);

    std::vector<std::string> &get_env_var_search_folders();
    const std::vector<std::string> &get_env_var_search_folders() const;

    //! Load the plugins
    /*!
     * \return 0 if successful, < 0 otherwise
     */
    virtual int load() = 0;

    /*! Set if plugins were already loaded
    /*!
     * \param[in] is_loaded true if already loaded, false otherwise
     */
    void set_is_loaded(bool is_loaded);

    //! Tells if plugins were already loaded
    /*!
     * \return true if already loaded, false otherwise
     */
    bool get_is_loaded() const;

    //! Attempt to load a plugin
    /*!
     * \return 0 if successful, < 0 otherwise
     */
    virtual int load(const std::string &dir) = 0;

    //! Load all plugins if not already done
    /*!
     * \return 0 if successful, < 0 otherwise
     */
    int load_if_not_loaded();

    //! Release the plugins
    /*!
     * \return 0 if successful, < 0 otherwise
     */
    virtual int release() = 0;

    //! Return the number of loaded plugins
    /*!
     * \return the number of loaded plugins
     */
    virtual std::size_t get_size() = 0;

    //! Return the plugin with a given index
    /*!
     * \param[in] index the index of the plugin
     * \return the plugin if any, nullptr otherwise
     */
    virtual PluginBase *get_base(std::size_t index) = 0;

    //! Return the plugin with a given short name
    /*!
     * \param[in] short_name the short name of the plugin
     * \return the plugin if any, nullptr otherwise
     */
    virtual PluginBase *get_base(const std::string &short_name) = 0;

    //! Find the full path of the current executable
    /*!
     * \param[out] exe_path the absolute path of the current executable, if successful
     * \return 0 if successful, < 0 otherwise
     */
    virtual int find_exe_path(std::string &exe_path) = 0;

    //! Find the full path of the plugin folder
    /*!
     * \param[out] plugin_folder the absolute path of the plugin folder, if successful
     * \return 0 if successful, < 0 otherwise
     */
    virtual int find_plugin_folder(std::string &plugin_folder) = 0;

    //! Get the relative path of the folder with the plugins
    /*!
     * \param[out] rel_plugin_path the relative path of the folder with the plugins
     * \return 0 if successful, < 0 otherwise
     */
    virtual int get_rel_plugin_path(std::string &rel_plugin_path);

    //! Set the verbosity level
    /*!
     * \param[in] verbose_level the verbosity level
     */
    void set_verbose_level(uint32_t verbose_level);

    //! Get the verbosity level
    /*!
     * \return the verbosity level
     */
    uint32_t get_verbose_level() const;

    //! Get the plugin entry function name
    /*!
     * \return the plugin entry function name
     */
    const std::string &get_entry_fct_name() const;

    //! Get the plugin instance from the entry function
    /*!
     * \return the plugin instance
     */
    virtual PluginBase *get_plugin_from_entry_fct(void *entry_fct) = 0;

    //! Set the base folder
    /*!
     * \param[in] base_folder the base folder
     */
    static void set_base_folder(const std::string &base_folder);

    //! Get the base folder
    /*!
     * \return the base folder
     */
    static const std::string &get_base_folder();

    //! Set the application exe name
    /*!
     * \param[in] app_exe the application exe name
     */
    static void set_app_exe(const std::string &app_exe);

    //! Get the application exe name
    /*!
     * \return the application exe name
     */
    static const std::string &get_app_exe();

protected:
    //!< \cond DOXY_IMPL

    //! Set the filename of a plugin
    /*!
     * \param[in] plugin the plugin
     * \param[in] filename the file name
     */
    static void set_plugin_filename(PluginBase *plugin, const std::string &filename);

    //! Set the name of the entry function of the plugin
    /*!
     * \param[in] entry_fct_name the name of the entry function of the plugin
     */
    void set_entry_fct_name(const std::string &entry_fct_name);

    static std::string m_base_folder; //!< The base folder
    static std::string m_app_exe;     //!< The application exe name

private:
    std::string m_name;
    std::string m_version;
    int m_major_version = 0;
    int m_minor_version = -1;
    int m_patch_version = -1;
    uint32_t m_verbose_level = 0;                      //!< The verbosity level
    std::string m_entry_fct_name;                      //!< The plugin entry function name
    std::string m_search_folder;                       //!< The search folder
    bool m_is_loaded = false;                          //!< True if already loaded, false otherwise
    std::vector<std::string> m_env_var_search_folders; //!< Environement variables potentially storing path to plugins
    //!< \endcond
};

} // namespace esys::base
