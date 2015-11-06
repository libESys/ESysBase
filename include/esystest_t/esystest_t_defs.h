/*!
 * \file esystest/esystest_t_defs.h
 * \brief Definitions needed for esystest_t
 *
 * \cond
 *__legal_b__
 *
 *__legal_e__
 * \endcond
 *
 */

#ifndef __ESYSTEST_T_DEFS_H__
#define __ESYSTEST_T_DEFS_H__

#ifdef ESYSTEST_T_EXPORTS
#define ESYSTEST_T_API __declspec(dllexport)
#elif ESYSTEST_T_USE
#define ESYSTEST_T_API __declspec(dllimport)
#else
#define ESYSTEST_T_API
#endif

#endif

