/*!
 * \file esystest/unit_test.h
 * \brief Version info for esystest
 *
 * \cond
 * __legal_b__
 *
 * Copyright (c) 2016-2020 Michel Gillet
 * Distributed under the wxWindows Library Licence, Version 3.1.
 * (See accompanying file LICENSE_3_1.txt or
 * copy at http://www.wxwidgets.org/about/licence)
 *
 * __legal_e__
 * \endcond
 *
 */

#pragma once

#include "esystest/setup.h"

#ifdef ESYSTEST_USE_BOOST
// ESysTest is a wrapper around Boost Unit Test Framework
#include "esystest/boost/unit_test.h"
#elif defined(ESYSTEST_USE_ESYSTEST)
// ESysTest unit test framework is used
#include "esystest/esystest/unit_test.h"
//#include "esystest/boost/boost/test/unit_test.hpp"
#endif
