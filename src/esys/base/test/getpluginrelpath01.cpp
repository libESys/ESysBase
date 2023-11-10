/*!
 * \file esys/base/test/getpluginrelpath01.cpp
 * \brief
 *
 * \cond
 * __legal_b__
 *
 * Copyright (c) 2021 Michel Gillet
 * Distributed under the MIT License.
 * (See accompanying file LICENSE.txt or
 * copy at https://opensource.org/licenses/MIT)
 *
 * __legal_e__
 * \endcond
 *
 */

#include "esys/base/test/esysbase_t_prec.h"
#include "esys/base/test/testcasectrl.h"

#include <esys/base/pluginmngrcore.h>

#include <boost/filesystem.hpp>

#include <iostream>

namespace esys
{

namespace base
{

namespace test
{

namespace getpluginrelpath01
{

class PluginMngr : public PluginMngrCore
{
public:
    PluginMngr();
    virtual ~PluginMngr();

    PluginBase *get_base(const std::string &short_name) override;
    PluginBase *get_plugin_from_entry_fct(void *entry_fct) override;
};

PluginMngr::PluginMngr()
    : PluginMngrCore("test_esysbase")
{
}

PluginMngr::~PluginMngr()
{
}

PluginBase *PluginMngr::get_base(const std::string &short_name)
{
    return nullptr;
}

PluginBase *PluginMngr::get_plugin_from_entry_fct(void *entry_fct)
{
    return nullptr;
}

/*! \class GetPluginRelPath01 esys/base/test/getpluginrelpath01.cpp
 * "esys/base/test/getpluginrelpath01.cpp"
 *
 *  \brief
 *
 */
ESYSTEST_AUTO_TEST_CASE(GetPluginRelPath01)
{
    PluginMngr mngr;

    std::string path;
    int result = 0;

    result = mngr.get_rel_plugin_path(path);
    ESYSTEST_REQUIRE_EQUAL(result, 0);

#ifdef WIN32
    ESYSTEST_REQUIRE_EQUAL(path, "plugins\\test_esysbase");
#else
    ESYSTEST_REQUIRE_EQUAL(path, "test_esysbase/0/plugins");
#endif
}

} // namespace getpluginrelpath01

} // namespace test

} // namespace base

} // namespace esys
