/*!
 * \file esys/base/test/testcasectrl.h
 * \brief
 *
 * \cond
 * __legal_b__
 *
 * Copyright (c) 2020-2023 Michel Gillet
 * Distributed under the MIT License.
 * (See accompanying file LICENSE.txt or
 * copy at https://opensource.org/licenses/MIT)
 *
 * __legal_e__
 * \endcond
 *
 */

#pragma once

#include <esystest/testcasectrl.h>
#include <esystest/stdlogger.h>

namespace esys::base::test
{

class TestCaseCtrl : public esystest::TestCaseCtrl
{
public:
    TestCaseCtrl();
    virtual ~TestCaseCtrl();

    static TestCaseCtrl &get();

protected:
    static TestCaseCtrl *g_test_case;

    esystest::StdLogger m_logger;
};

} // namespace esys::base::test
