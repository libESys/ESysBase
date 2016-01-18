/*!
* \file esystest/inttypes.h
* \brief
*
* \cond
*__legal_b__
*
*__legal_e__
* \endcond
*
*/

#ifndef __ESYSTEST_INTTYPES_H__
#define __ESYSTEST_INTTYPES_H__

#if defined __GNUC__ || defined __GNUG__
#ifdef HAVE_STDINT_H
#include <stdint.h>
#endif
#ifdef HAVE_INTTYPES_H
#include <inttypes.h>
#endif
#include <limits.h>
#define UINT32_T_MAX ULONG_MAX
#endif

namespace esystest 
{

#ifdef _MSC_VER
#include <limits.h>

typedef __int8 int8_t;
typedef __int16 int16_t;
typedef __int32 int32_t;
typedef __int64 int64_t;

typedef unsigned __int8 uint8_t;
typedef unsigned __int16 uint16_t;
typedef unsigned __int32 uint32_t;
typedef unsigned __int64 uint64_t;

#define UINT32_T_MAX ULONG_MAX

#elif defined __GNUC__ || defined __GNUG__

typedef ::int8_t int8_t;
typedef ::int16_t int16_t;
typedef ::int32_t int32_t;
typedef ::int64_t int64_t;

typedef ::uint8_t uint8_t;
typedef ::uint16_t uint16_t;
typedef ::uint32_t uint32_t;
typedef ::uint64_t uint64_t;

#endif //_MSC_VER

}


#endif


