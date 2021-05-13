/*!
 * \file esys/base/impl_boost/test/getexepath01_boost.cpp
 * \brief
 *
 * \cond
 * __legal_b__
 *
 * __legal_e__
 * \endcond
 *
 */

#include "esys/base/test/esysbase_t_prec.h"
#include "esys/base/test/testcasectrl.h"

#include <esys/base/impl_boost/pluginmngrcore.h>

#include <boost/filesystem.hpp>

#ifndef WIN32
#include <boost/process/search_path.hpp>
#endif

#include <iostream>

namespace esys
{

namespace base
{

namespace impl_boost
{

namespace test
{

/*! \class GetExePath01Boost esys/base/impl_boost/test/getexepath01_boost.cpp
 * "esys/base/impl_boost/test/getexepath01_boost.cpp"
 *
 *  \brief
 *
 */
ESYSTEST_AUTO_TEST_CASE(GetExePath01Boost)
{
    int result = 0;
    std::string exe_path;

    result = PluginMngrCore::s_find_exe_path(exe_path);
    ESYSTEST_REQUIRE_EQUAL(result, 0);

    auto &ctrl = base::test::TestCaseCtrl::get();
    ESYSTEST_REQUIRE_GE(ctrl.GetArgC(), 1);

    std::string argv0 = ctrl.GetArgV()[0];
    boost::filesystem::path exe_path_test = argv0;
#ifdef WIN32
    exe_path_test = exe_path_test.normalize().make_preferred();
#else
    exe_path_test = boost::filesystem::absolute(exe_path_test);
    exe_path_test = exe_path_test.normalize().make_preferred();
#endif

    ESYSTEST_REQUIRE_EQUAL(exe_path, exe_path_test.string());

}

} // namespace test

} // namespace ci

} // namespace repo

} // namespace esys
