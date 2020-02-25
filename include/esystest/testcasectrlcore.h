/*!
 * \file esystest/testcasectrlcore.h
 * \brief
 *
 * \cond
 * __legal_b__
 *
 * Copyright (c) 2015-2020 Michel Gillet
 * Distributed under the wxWindows Library Licence, Version 3.1.
 * (See accompanying file LICENSE_3_1.txt or
 * copy at http://www.wxwidgets.org/about/licence)
 *
 * __legal_e__
 * \endcond
 *
 */

#pragma once

#ifdef ESYSTEST_EM
#include "esystest/em/testcasectrlcore.h"
#elif defined(WIN32) || defined(LINUX) || defined(ESYS_VHW) || defined(ESYSTEST_MULTIOS)
#ifndef ESYSTEST_MULTIOS
#define ESYSTEST_MULTIOS
#endif
#include "esystest/multios/testcasectrlcore.h"
#else
#ifndef ESYSTEST_EM
#define ESYSTEST_EM
#endif
#include "esystest/em/testcasectrlcore.h"
#endif
