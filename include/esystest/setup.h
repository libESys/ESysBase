/*!
 * \file esystest/setup.h
 * \brief
 *
 * \cond
 * __legal_b__
 *
 * Copyright (c) 2016-2018 Michel Gillet
 * Distributed under the wxWindows Library Licence, Version 3.1.
 * (See accompanying file LICENSE_3_1.txt or
 * copy at http://www.wxwidgets.org/about/licence)
 *
 * __legal_e__
 * \endcond
 *
 */

#pragma once

#ifdef ESYSTEST_USE_BOOST

#else

#ifndef ESYSTEST_USE_ESYSTEST
#define ESYSTEST_USE_ESYSTEST
#endif

#endif

#if defined(WIN32)

#ifndef ESYSTEST_USE_ESYS
//#define ESYSTEST_USE_ESYS
#endif

#endif

#ifdef ESYSTEST_USE_ESYS
#include <esys/setup.h>
#endif


