/*!
 * \file esystest/esystest_t_prec.h
 * \brief For precompiled headers
 *
 * \cond
 *__legal_b__
 *
 *__legal_e__
 * \endcond
 *
 */

#ifndef __ESYSTEST_ESYSTEST_T_PREC_H__
#define __ESYSTEST_ESYSTEST_T_PREC_H__

#ifdef _MSC_VER
#pragma warning (disable : 4996)
#pragma warning (disable : 4985)
#endif

#include <boost/test/unit_test.hpp>

#ifdef _MSC_VER
#pragma warning (default : 4996)
#pragma warning (default : 4985)
#endif

#ifdef WIN32
    #define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers
    // Windows Header Files:
    #include <windows.h>
#endif

// TODO: reference additional headers your program requires here

#endif
