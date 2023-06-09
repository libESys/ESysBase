/*!
 * \file esys/base/autolink.h
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
#define ESYS_LIB_NAME esysbase

#ifdef ESYS_LIB_VERSION
#undef ESYS_LIB_VERSION
#endif
#define ESYS_LIB_VERSION "0.1.0"

#if !defined(ESYSBASE_EXPORTS) && defined(_MSC_VER)
#include <esysmsvc/autolink.h>
#endif
#pragma once
