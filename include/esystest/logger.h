/*!
 * \file esystest/logger.h
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

#ifndef __ESYSTEST_LOGGER_H__
#define __ESYSTEST_LOGGER_H__

#include "esystest/esystest_defs.h"
#include "esystest/inttypes.h"

namespace esystest
{

class ESYSTEST_API Logger
{
public:
    Logger();
    virtual ~Logger();

    virtual Logger& operator<< (uint8_t value) = 0;
    virtual Logger& operator<< (const char *str) = 0;

    void SetReportPass(bool report_pass);
    bool GetReportPass();

    static void Set(Logger *logger);
    static Logger *Get();
protected:
    static Logger *m_logger;
    bool m_report_pass;
};

}

#endif

