/*!
 * \file esys/base/autolink.h
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

#ifdef ESYS_LIB_NAME
#undef ESYS_LIB_NAME
#endif
#define ESYS_LIB_NAME esysbase

#ifdef ESYS_LIB_VERSION
#undef ESYS_LIB_VERSION
#endif
#define ESYS_LIB_VERSION "0.1.0"

#if !defined(ESYSBASE_EXPORTS) && !defined(ESYSBASE_STATIC_LIB)
#define ESYSBASE_AUTO_LINK 1
#endif

#if defined(ESYSBASE_AUTO_LINK) && defined(_MSC_VER)
#include <esysmsvc/autolink.h>
#endif
