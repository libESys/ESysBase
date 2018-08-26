/*!
 * \file esystest/testcasectrl.h
 * \brief
 *
 * \cond
 *__legal_b__
 *
 * Copyright (c) 2016-2018 Michel Gillet
 * Distributed under the wxWindows Library Licence, Version 3.1.
 * (See accompanying file LICENSE_3_1.txt or
 * copy at http://www.wxwidgets.org/about/licence)
 *
 *__legal_e__
 * \endcond
 *
 */

#pragma once

#include "esystest/setup.h"

#if defined(ESYSTEST_USE_BOOST) || defined(ESYSTEST_MULTIOS)
#include "esystest/boost/boost/testcasectrl.h"
#else
// By default use the command line Test Case Controller, which is not meant for embedded SW
#include "esystest/esystest/testcasectrl.h"
#endif



