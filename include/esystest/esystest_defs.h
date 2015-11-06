/*!
 * \file esystest/esystest_defs.h
 * \brief Definitions needed for esystest
 *
 * \cond
 *__legal_b__
 *
 *__legal_e__
 * \endcond
 *
 */

#ifndef __ESYSTEST_DEFS_H__
#define __ESYSTEST_DEFS_H__

#ifdef ESYSTEST_EXPORTS
#define ESYSTEST_API __declspec(dllexport)
#define ESYSPROG_TEMPLATE
#elif ESYSTEST_USE
#define ESYSTEST_API __declspec(dllimport)
#define ESYSPROG_TEMPLATE extern
#else
#define ESYSTEST_API
#define ESYSPROG_TEMPLATE
#endif

#ifdef _MSC_VER
#pragma warning (disable : 4251)
#endif

#endif

