/*!
 * \file esys/base/dynlibrary.h
 * \brief
 *
 * \cond
 * __legal_b__
 *
 * Copyright (c) 2018-2020 Michel Gillet
 * Distributed under the wxWindows Library Licence, Version 3.1.
 * (See accompanying file LICENSE_3_1.txt or
 * copy at http://www.wxwidgets.org/about/licence)
 *
 * __legal_e__
 * \endcond
 *
 */

#pragma once

#ifndef ESYSBASE_DYNLIB_USE_WX
#ifndef ESYSBASE_DYNLIB_USE_BOOST
#define ESYSBASE_DYNLIB_USE_BOOST
#endif
#include "esys/base/impl_boost/dynlibrary.h"
#else
#ifndef ESYSBASE_DYNLIB_USE_WX
#define ESYSBASE_DYNLIB_USE_WX
#endif
#include "esys/base/impl_wx/dynlibrary.h"
#endif
