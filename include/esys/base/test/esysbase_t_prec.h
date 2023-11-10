/*!
 * \file esys/base/test/esysbase_t_prec.h
 * \brief For precompiled headers
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

#include <esystest/unit_test.h>

#ifdef WIN32
#define WIN32_LEAN_AND_MEAN // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>
#endif

// TODO: reference additional headers your program requires here

#include "esys/base/test/testcasectrl.h"
