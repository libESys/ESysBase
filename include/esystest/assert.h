/*!
 * \file esystest/assert.h
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

#ifdef ESYSTEST_USE_ESYS
#include <esys/assert.h>
#else

#ifdef _MSC_VER
#include <assert.h>
#else
#include <cassert>
#endif

#endif

#ifndef assert
//#define assert
#endif
