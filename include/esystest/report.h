/*!
 * \file esystest/report.h
 * \brief
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

#ifndef __ESYSTEST_REPORT_H__
#define __ESYSTEST_REPORT_H__

#include "esystest/esystest_defs.h"

namespace esystest
{

ESYSTEST_API bool report_assertion(bool result, const char *file_name, int line_num, ToolLevel tl, CheckType ct);

}

#endif
