/*!
 * \file esys/base/pluginmngr_t.h
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

#include "esys/base/pluginmngrcore_t.h"

#include <memory>

namespace esys::base
{

/*! \class PluginMngr_t esys/base/pluginmngr_t.h "esys/base/pluginmngr_t.h"
 * \brief
 */
template<typename MNGR, typename PLUGIN, typename TYPE, typename ENTRY_FCT>
class PluginMngr_t : public PluginMngrCore_t<PLUGIN>
{
public:
    //! Default constructor
    PluginMngr_t(const std::string &name = "");

    //! Destructor
    ~PluginMngr_t() override;

    base::PluginBase *get_plugin_from_entry_fct(void *entry_fct) override;

    std::map<TYPE, PLUGIN *> get_map_type_plugin();
    const std::map<TYPE, PLUGIN *> get_map_type_plugin() const;

    PLUGIN *get_plugin(TYPE plugin_type);

    static MNGR &get();

protected:
    //! \cond DOXY_IMPL
    static std::unique_ptr<MNGR> s_mngr;

    int plugin_loaded(PLUGIN *plugin) override;

private:
    std::map<TYPE, PLUGIN *> m_map_type_plugin;
    //! \endcond
};

template<typename MNGR, typename PLUGIN, typename TYPE, typename ENTRY_FCT>
PluginMngr_t<MNGR, PLUGIN, TYPE, ENTRY_FCT>::PluginMngr_t(const std::string &name)
    : PluginMngrCore_t<PLUGIN>(name)
{
}

template<typename MNGR, typename PLUGIN, typename TYPE, typename ENTRY_FCT>
PluginMngr_t<MNGR, PLUGIN, TYPE, ENTRY_FCT>::~PluginMngr_t()
{
}

template<typename MNGR, typename PLUGIN, typename TYPE, typename ENTRY_FCT>
base::PluginBase *PluginMngr_t<MNGR, PLUGIN, TYPE, ENTRY_FCT>::get_plugin_from_entry_fct(void *entry_fct)
{
    ENTRY_FCT the_entry_fct = (ENTRY_FCT)entry_fct;
    PLUGIN *plugin;

    assert(entry_fct != nullptr);

    plugin = (*the_entry_fct)();

    return plugin;
}

template<typename MNGR, typename PLUGIN, typename TYPE, typename ENTRY_FCT>
std::map<TYPE, PLUGIN *> PluginMngr_t<MNGR, PLUGIN, TYPE, ENTRY_FCT>::get_map_type_plugin()
{
    return m_map_type_plugin;
}

template<typename MNGR, typename PLUGIN, typename TYPE, typename ENTRY_FCT>
const std::map<TYPE, PLUGIN *> PluginMngr_t<MNGR, PLUGIN, TYPE, ENTRY_FCT>::get_map_type_plugin() const
{
    return m_map_type_plugin;
}

template<typename MNGR, typename PLUGIN, typename TYPE, typename ENTRY_FCT>
PLUGIN *PluginMngr_t<MNGR, PLUGIN, TYPE, ENTRY_FCT>::get_plugin(TYPE plugin_type)
{
    auto it = m_map_type_plugin.find(plugin_type);

    if (it != m_map_type_plugin.end()) return it->second;

    return nullptr;
}

template<typename MNGR, typename PLUGIN, typename TYPE, typename ENTRY_FCT>
int PluginMngr_t<MNGR, PLUGIN, TYPE, ENTRY_FCT>::plugin_loaded(PLUGIN *plugin)
{
    if (plugin->get_type() != TYPE::NOT_SET) m_map_type_plugin[plugin->get_type()] = plugin;

    return 0;
}

template<typename MNGR, typename PLUGIN, typename TYPE, typename ENTRY_FCT>
MNGR &PluginMngr_t<MNGR, PLUGIN, TYPE, ENTRY_FCT>::get()
{
    if (s_mngr == nullptr)
    {
        s_mngr = std::make_unique<MNGR>();
    }
    return *s_mngr.get();
}

template<typename MNGR, typename PLUGIN, typename TYPE, typename ENTRY_FCT>
std::unique_ptr<MNGR> PluginMngr_t<MNGR, PLUGIN, TYPE, ENTRY_FCT>::s_mngr;

} // namespace esys::base
