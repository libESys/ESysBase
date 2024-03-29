/*!
 * \file esys/base/pluginmngrbase.h
 * \brief
 *
 * \cond
 * __legal_b__
 *
 * Copyright (c) 2017-2022 Michel Gillet
 * Distributed under the MIT License.
 * (See accompanying file LICENSE.txt or
 * copy at https://opensource.org/licenses/MIT)
 *
 * __legal_e__
 * \endcond
 *
 */

#pragma once

#include "esys/base/esysbase_defs.h"
#include "esys/base/pluginbase.h"
#include "esys/base/log_if.h"
#include "esys/base/version.h"

#include <map>
#include <memory>
#include <string>
#include <vector>

namespace esys::base
{

/*! \class PluginMngrBase esys/base/pluginmngrbase.h "esys/base/pluginmngrbase.h"
 * \brief Base class for all plugin managers
 */
class ESYSBASE_API PluginMngrBase : public Log_if
{
public:
    //! Default constructor
    /*!
     * \param[in] name the name of the Plugin Manager
     */
    PluginMngrBase(const std::string &name = "");

    //! Destructor
    ~PluginMngrBase() override;

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
    void set_version(const Version &version);

    //! Get the version of the Plugin Manager
    /*!
     * \return the version of the Plugin Manager
     */
    const Version &get_version() const;

    //! Get the version of the Plugin Manager
    /*!
     * \return the version of the Plugin Manager
     */
    Version &get_version();

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
    virtual int load(const std::string &dir, PluginBase **plugin_base = nullptr) = 0;

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

    virtual int find_plugin_path_rel_exe(const std::string &plugin_name, std::string &plugin_path);

    //! Find the full path of the plugin folder
    /*!
     * \param[out] plugin_folder the absolute path of the plugin folder, if successful
     * \return 0 if successful, < 0 otherwise
     */
    virtual int find_plugin_folders(std::vector<std::string> &plugin_folders) = 0;

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
    virtual PluginBase *get_plugin_from_entry_fct(void *entry_fct);

    void set_log_if(std::shared_ptr<Log_if> log_if);
    std::shared_ptr<Log_if> get_log_if() const;

    void trace(const std::string &msg) override;
    void debug(int level, const std::string &msg) override;
    void info(const std::string &msg) override;
    void warn(const std::string &msg) override;
    void error(const std::string &msg) override;
    void critical(const std::string &msg) override;

    void debug_helper(int level, const std::string &msg, const std::vector<std::string> &strings);

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

    PluginBase *find_plugin_abs_path(const std::string &abs_path) const;
    void add_plugin_abs_path(const std::string &abs_path, PluginBase *plugin);

private:
    std::string m_name;                                //!< The name of the plugin manager
    Version m_version;                                 //!< The version of the plugin manager
    uint32_t m_verbose_level = 0;                      //!< The verbosity level
    std::string m_entry_fct_name;                      //!< The plugin entry function name
    std::string m_search_folder;                       //!< The search folder
    bool m_is_loaded = false;                          //!< True if already loaded, false otherwise
    std::vector<std::string> m_env_var_search_folders; //!< Environement variables potentially storing path to plugins
    std::map<std::string, PluginBase *> m_abs_path_plugin_map; //!< Map absolute path to the Plugin
    std::shared_ptr<Log_if> m_log_if;
    //!< \endcond
};

} // namespace esys::base
