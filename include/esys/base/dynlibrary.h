/*!
 * \file esys/base/dynlibrary.h
 * \brief
 *
 * \cond
 * __legal_b__
 *
 * Copyright (c) 2018-2020 Michel Gillet
 * Distributed under the MIT License.
 * (See accompanying file LICENSE.txt or
 * copy at https://opensource.org/licenses/MIT)
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
