/*!
 * \file esystest/esystest_defs.h
 * \brief Definitions needed for esystest
 *
 * \cond
 *__legal_b__
 *
 * Copyright (c) 2015-2016 Michel Gillet
 * Distributed under the wxWindows Library Licence, Version 3.1.
 * (See accompanying file LICENSE_3_1.txt or
 * copy at http://www.wxwidgets.org/about/licence)
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

#ifndef ESYSTEST_USE_OWN_DATA_SECTION
#define ESYSTEST_DATA_SECTION
#else

#if defined(__GNUC__) || defined(__GNUG__)
#define ESYSTEST_DATA_SECTION __attribute__((section (".data_esystest")))
#else
#error Compiler doesn''t support the usage of ESYSTEST_USE_OWN_SECTION
#endif

#endif


#ifdef __cplusplus

namespace esystest
{

enum ToolLevel
{
    WARN, CHECK, REQUIRE, PASS,
    TOOLLEVEL_COUNT

};

enum CheckType
{
    CHECK_PRED,
    CHECK_MSG,
    CHECK_EQUAL,
    CHECK_NE,
    CHECK_LT,
    CHECK_LE,
    CHECK_GT,
    CHECK_GE,
    CHECK_CLOSE,
    CHECK_CLOSE_FRACTION,
    CHECK_SMALL,
    CHECK_BITWISE_EQUAL,
    CHECK_PRED_WITH_ARGS,
    CHECK_EQUAL_COLL,
    CHECK_BUILT_ASSERTION,
    CHECKTYPE_COUNT
};

}
#endif

#endif

