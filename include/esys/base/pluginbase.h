/*!
 * \file esys/base/pluginbase.h
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

#include <boost/program_options/options_description.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/filesystem/path.hpp>

#include <cstddef>
#include <string>
#include <vector>

namespace po = boost::program_options;

#define DECLARE_ESYSBASE_PLUGIN(exp, shortname, base_class_) \
    extern "C" exp base_class_ *get_##short_name##_plugin(); \
    extern "C" exp esys::base::PluginBase *get_esysbase_plugin();

#define DEFINE_ESYSBASE_PLUGIN(exp, shortname, base_class_, class_) \
    static class_ g_plugin;                                         \
    extern "C" exp base_class_ *get_##shortname##_plugin()          \
    {                                                               \
        return &g_plugin;                                           \
    }                                                               \
    extern "C" exp esys::base::PluginBase *get_esysbase_plugin()    \
    {                                                               \
        return &g_plugin;                                           \
    }

namespace esys::base
{

/*! \class PluginBase esys/base/pluginbase.h "esys/base/pluginbase.h"
 * \brief Base class for all plugin
 */
class ESYSBASE_API PluginBase
{
public:
    friend class ESYSBASE_API PluginMngrBase;

    static const std::string s_entry_fct_name;

    //! Defalut constructor
    PluginBase();

    //! Destructor
    virtual ~PluginBase();

    //! Get the name of the plugin
    /*!
     * \return the name of the plugin
     */
    std::string &get_name();

    //! Get the short name of the plugin
    /*!
     * \return the short name of the plugin
     */
    std::string &get_short_name();

    //! Get the version of the plugin
    /*!
     * \return the version of the plugin
     */
    std::string &get_version();

    //! Get the file name of the plugin
    /*!
     * \return the file name of the plugin
     */
    std::string &get_filename();

    //! Tells if the plugin was created by a debug build or not
    /*!
     * \return if the plugin was created by a debug build or not
     */
    bool is_debug() const;

    //! Initialize the plugin
    /*!
     * \return 0 if successful, < 0 otherwise
     */
    virtual int init();

    //! Release the plugin
    /*!
     * \return 0 if successful, < 0 otherwise
     */
    virtual int release();

    virtual int run(const std::vector<std::string> &cmd_line, const po::variables_map &vm);

    virtual std::size_t get_options_desc_count();
    virtual po::options_description *get_options_desc(std::size_t idx = 0);
    virtual void add_options_desc(po::options_description *options_desc);

    //! Get the path
    /*!
     * \return the path
     */
    const boost::filesystem::path &get_path() const;

protected:
    //!< \cond DOXY_IMPL

    //! Set if the plugin was created by a debug build or not
    /*!
     * \param[in] debug true the plugin was created by a debug build, false otherwise
     */
    void set_debug(bool debug);

    //! Set the name of the plugin
    /*!
     * \param[in] name the name of the plugin
     */
    void set_name(const std::string &name);

    //! Set the short name of the plugin
    /*!
     * \param[in] short_name the short name of the plugin
     */
    void set_short_name(const std::string &short_name);

    //! Set the version of the plugin
    /*!
     * \param[in] version the version of the plugin
     */
    void set_version(const std::string &version);

    //! Set the path
    /*!
     * \param[in] path the path
     */
    void set_path(const ::boost::filesystem::path &path);

    //! Set the file name of the plugin
    /*!
     * \param[in] fileame the file name of the plugin
     */
    void set_filename(const std::string &filename);

private:
    bool m_is_debug = false;        //!< True if debug build, false otherwise
    bool m_init = false;            //!< True if already initialized, false otherwise
    std::string m_name;             //!< The name of the plugin
    std::string m_short_name;       //!< The short name of the plugin
    std::string m_version;          //!< The version of the plugin
    boost::filesystem::path m_path; //!< The path
    std::string m_filename;         //!< The filename
    std::vector<po::options_description *> m_options_desc;
    //!< \endcond
};

using PluginBaseEntryFunction = PluginBase * (*)();

} // namespace esys::base
