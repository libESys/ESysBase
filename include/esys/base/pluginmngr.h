/*!
 * \file esys/base/pluginmngr.h
 * \brief
 *
 * \cond
 * __legal_b__
 *
 * Copyright (c) 2022 Michel Gillet
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
#include "esys/base/pluginmngrcore_t.h"

#include <vector>
#include <map>

//<swig_inc/>

namespace esys::base
{

/*! \class PluginMngr esys/base/pluginmngr.h "esys/base/pluginmngr.h"
 * \brief Plugin manager class for esysbase itself
 *
 */
class ESYSBASE_API PluginMngr : public PluginMngrCore_t<PluginBase>
{
public:
    typedef base::PluginMngrCore_t<PluginBase> BaseType;

    using BaseType::get;

    //! Constructor
    PluginMngr();

    //! Destructor
    ~PluginMngr() override;

    base::PluginBase *get_plugin_from_entry_fct(void *entry_fct) override;

protected:
    int plugin_loaded(PluginBase *plugin) override;
};

} // namespace esys::base
