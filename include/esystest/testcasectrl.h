/*!
 * \file esystest/testcasectrl.h
 * \brief
 *
 * \cond
 *__legal_b__
 *
 * Copyright (c) 2016 Michel Gillet
 * Distributed under the wxWindows Library Licence, Version 3.1.
 * (See accompanying file LICENSE_3_1.txt or
 * copy at http://www.wxwidgets.org/about/licence)
 *
 *__legal_e__
 * \endcond
 *
 */

#ifndef __ESYSTEST_TESTCASECTRL_H__
#define __ESYSTEST_TESTCASECTRL_H__

#ifdef ESYSTEST_CMD_LINE
#include "esystest/boost/testcasectrl.h"
#else
// By default use the command line Test Case Controller, which is not meant for embedded SW
#define ESYSTEST_CMD_LINE
#include "esystest/boost/testcasectrl.h"
#endif

#endif

