/*!
 * \file esysslora/config.h
 * \brief
 *
 * \cond
 * __legal_b__
 *
 * __legal_e__
 * \endcond
 *
 */

#pragma once

#ifdef ESYS_LIB_NAME
#undef ESYS_LIB_NAME
#endif
#define ESYS_LIB_NAME esystest

#ifdef ESYS_LIB_VERSION
#undef ESYS_LIB_VERSION
#endif
#define ESYS_LIB_VERSION "0.0.0"

#include "esystest/autolink_msvc.h"
