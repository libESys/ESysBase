/*!
 * \file esystest/report.h
 * \brief
 *
 * \cond
 *__legal_b__
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
