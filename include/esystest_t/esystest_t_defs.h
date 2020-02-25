/*!
 * \file esystest/esystest_t_defs.h
 * \brief Definitions needed for esystest_t
 *
 * \cond
 *__legal_b__
 *
 * Copyright (c) 2015-2020 Michel Gillet
 * Distributed under the wxWindows Library Licence, Version 3.1.
 * (See accompanying file LICENSE_3_1.txt or
 * copy at http://www.wxwidgets.org/about/licence)
 *
 *__legal_e__
 * \endcond
 *
 */

#pragma once

#ifdef ESYSTEST_T_EXPORTS
#define ESYSTEST_T_API __declspec(dllexport)
#elif ESYSTEST_T_USE
#define ESYSTEST_T_API __declspec(dllimport)
#else
#define ESYSTEST_T_API
#endif
