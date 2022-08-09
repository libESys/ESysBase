/*!
 * \file esys/base/pluginmngr.cpp
 * \brief
 *
 * \cond
 * __legal_b__
 *
 * Copyright (c) 2022 Michel Gillet
 * Distributed under the wxWindows Library Licence, Version 3.1.
 * (See accompanying file LICENSE_3_1.txt or
 * copy at http://www.wxwidgets.org/about/licence)
 *
 * __legal_e__
 * \endcond
 *
 */

#include "esys/base/esysbase_prec.h"
#include "esys/base/pluginmngr.h"

#include <cassert>

namespace esys::base
{

PluginMngr::PluginMngr()
    : BaseType("esysbase")
{
    set_entry_fct_name("get_esysbase_plugin");

    // Needed if used from Python code, as the location
    // of the Python executable is not useful
    add_env_var_search_folder("PYESYSBASe_INST_DIR");
    add_env_var_search_folder("ESYSBASE_INST_DIR");
    add_env_var_search_folder("PYESYSSDK_INST_DIR");
    add_env_var_search_folder("ESYSSDK_INST_DIR");
}

PluginMngr::~PluginMngr()
{
}

base::PluginBase *PluginMngr::get_plugin_from_entry_fct(void *entry_fct)
{
    PluginBaseEntryFunction the_entry_fct = (PluginBaseEntryFunction)entry_fct;
    PluginBase *plugin;

    assert(entry_fct != nullptr);

    plugin = (*the_entry_fct)();

    return plugin;
}

int PluginMngr::plugin_loaded(PluginBase *plugin)
{
    return 0;
}

} // namespace esys::base
