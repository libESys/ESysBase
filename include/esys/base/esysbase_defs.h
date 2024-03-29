/*!
 * \file esys/base/esysbase_defs.h
 * \brief Definitions needed for esysbase
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

#ifdef ESYSBASE_EXPORTS
#define ESYSBASE_API __declspec(dllexport)
#elif ESYSBASE_USE
#define ESYSBASE_API __declspec(dllimport)
#else
#define ESYSBASE_API
#define ESYS_STATIC_LINK 1
#endif

#include "esys/base/autolink.h"
