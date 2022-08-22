/*!
 * \file esys/base/impl_boost/pluginmngr.h
 * \brief
 *
 * \cond
 * __legal_b__
 *
 * Copyright (c) 2017-2021 Michel Gillet
 * Distributed under the wxWindows Library Licence, Version 3.1.
 * (See accompanying file LICENSE_3_1.txt or
 * copy at http://www.wxwidgets.org/about/licence)
 *
 * __legal_e__
 * \endcond
 *
 */

#pragma once

#include "esys/base/pluginbase.h"
#include "esys/base/pluginmngrbase.h"
#include "esys/base/impl_boost/dynlibrary.h"

#include <memory>

namespace esys::base
{

namespace impl_boost
{

//!< \cond DOXY_IMPL
/*! \class PluginMngrImplHelper esys/base/impl_boost/pluginmngr.h "esys/base/impl_boost/pluginmngr.h"
 * \brief Helper function used by PluginMngrCore to hold imformation about one shared library/plugin
 */
class PluginMngrImplHelper
{
public:
    //! Default constructor
    PluginMngrImplHelper();

    //! Destructor
    virtual ~PluginMngrImplHelper();

    //! Set the dynamic library instance for this plugin
    /*!
     * \param[in] dyn_lib the dynamic library of this plugin
     */
    void set_dyn_lib(std::shared_ptr<DynLibrary> &dyn_lib);

    //! Get the dynamic library instance for this plugin
    /*!
     * \return the dynamic library of this plugin
     */
    DynLibrary *get_dyn_lib();

    //! Set the plugin entry point in the dynamic libary
    /*!
     * \param[in] entry the plugin entry point in the dynamic libary
     */
    void set_entry_point(void *entry);

    //! Get the plugin entry point in the dynamic libary
    /*!
     * \return the plugin entry point in the dynamic libary
     */
    void *get_entry_point();

    //! Set the plugin instance
    /*!
     * \param[in] entry the plugin instance
     */
    void set_plugin(PluginBase *plugin);

    //! Get the plugin instance
    /*!
     * \return the plugin instance
     */
    PluginBase *get_plugin();

private:
    std::shared_ptr<DynLibrary> m_dyn_lib; //!< Pointer to the object implementing the dynamic loading
    void *m_entry_fct = nullptr;           //!< The entry point giving access to the plugin
    PluginBase *m_plugin = nullptr;        //!< Pointer to the plugin
};
//!< \endcond

/*! \class PluginMngrCore esys/base/impl_boost/pluginmngr.h "esys/base/impl_boost/pluginmngr.h"
 * \brief Boost implementation to discover and load the found plugins
 */
class ESYSBASE_API PluginMngrCore : public PluginMngrBase
{
public:
    //! Default constructor
    PluginMngrCore(const std::string &name = "");

    //! Destructor
    ~PluginMngrCore() override;

    int load() override;
    int load(const std::string &dir) override;
    int release() override;
    std::size_t get_size() override;
    PluginBase *get_base(std::size_t index) override;

    int find_exe_path(std::string &exe_path) override;
    int find_plugin_folder(std::string &plugin_folder) override;
    static int s_find_exe_path(std::string &exe_path);

private:
    //!< \cond DOXY_IMPL
    std::vector<std::shared_ptr<PluginMngrImplHelper>> m_plugins;
    //!< \endcond
};

} // namespace impl_boost

#ifdef ESYSBASE_PLUGIN_USE_BOOST
using namespace impl_boost;
#endif

} // namespace esys::base
