/*!
 * \file esys/base/pluginmngrcore_t.h
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

#pragma once

#include "esys/base/pluginmngrcore.h"
#include "esys/base/pluginbase.h"

#include <boost/locale.hpp>

namespace esys
{

namespace base
{

/*! \class PluginMngrCore_t esys/base/pluginmngrcore_t.h "esys/base/pluginmngrcore_t.h"
 * \brief
 */
template<typename T>
class PluginMngrCore_t : public PluginMngrCore
{
public:
    //! Default constructor
    PluginMngrCore_t();

    //! Destructor
    virtual ~PluginMngrCore_t();

    int load() override;

    PluginBase *get_base(const std::string &short_name) override;

    //! Get the vector of loaded plugins
    /*!
     * \return the vector of loaded plugins
     */
    std::vector<T *> get_plugins();

    //! Get the vector of loaded plugins
    /*!
     * \return the vector of loaded plugins
     */
    const std::vector<T *> get_plugins() const;

    //! Get a plugin based on its index
    /*!
     * \param[in] index the index of the plugin to get
     * \return the plugin if available, nullptr otherwise
     */
    T *get(std::size_t index);

    //! Get a plugin based on its short name
    /*!
     * \param[in] short_name the short name of the plugin to get
     * \return the plugin if available, nullptr otherwise
     */
    T *get(const std::string &short_name);

protected:
    //!< \cond DOXY_IMPL

    //! Called for each plugin successfully loaded
    /*!
     * \param[in] plugin the plugin which was just loaded successfully
     * \return 0 if all is fine with the plugin, < 0 the plugin won't be added to the list of loaded plugins
     */
    virtual int plugin_loaded(T *plugin);

    std::vector<T *> m_plugins;                         //!< The vector of loaded plugins
    std::map<std::string, T *> m_map_plugin_short_name; //!< The map of plugins
    //!< \endcond
};

template<typename T>
PluginMngrCore_t<T>::PluginMngrCore_t()
    : PluginMngrCore()
{
}

template<typename T>
PluginMngrCore_t<T>::~PluginMngrCore_t()
{
}

template<typename T>
int PluginMngrCore_t<T>::load()
{
    int result;
    std::size_t idx;
    PluginBase *plugin_base;
    T *plugin;

    result = PluginMngrCore::load();

    if (result < 0) return result;

    for (idx = 0; idx < get_size(); ++idx)
    {
        plugin_base = PluginMngrCore::get_base(idx);

        assert(plugin_base != nullptr);

        plugin = dynamic_cast<T *>(plugin_base);

        m_plugins.push_back(plugin);
        m_map_plugin_short_name[plugin_base->get_short_name()] = plugin;

        plugin_loaded(plugin);
    }
    return result;
}

template<typename T>
PluginBase *PluginMngrCore_t<T>::get_base(const std::string &short_name)
{
    return get(short_name);
}

template<typename T>
std::vector<T *> PluginMngrCore_t<T>::get_plugins()
{
    return m_plugins;
}

template<typename T>
const std::vector<T *> PluginMngrCore_t<T>::get_plugins() const
{
    return m_plugins;
}

template<typename T>
T *PluginMngrCore_t<T>::get(std::size_t index)
{
    if (index >= m_plugins.size()) return nullptr;
    return m_plugins[index];
}

template<typename T>
T *PluginMngrCore_t<T>::get(const std::string &short_name)
{
    typename std::map<std::string, T *>::iterator it;

    it = m_map_plugin_short_name.find(short_name);
    if (it == m_map_plugin_short_name.end()) return nullptr;
    return it->second;
}

template<typename T>
int PluginMngrCore_t<T>::plugin_loaded(T *plugin)
{
    return 0;
}

} // namespace base

} // namespace esys
