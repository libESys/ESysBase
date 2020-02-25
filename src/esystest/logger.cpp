/*!
 * \file esystest/logger.h
 * \brief
 *
 * \cond
 * __legal_b__
 *
 * Copyright (c) 2015-2020 Michel Gillet
 * Distributed under the wxWindows Library Licence, Version 3.1.
 * (See accompanying file LICENSE_3_1.txt or
 * copy at http://www.wxwidgets.org/about/licence)
 *
 * __legal_e__
 * \endcond
 *
 */

#include "esystest/esystest_prec.h"
#include "esystest/logger.h"

namespace esystest
{

Logger *Logger::s_logger = nullptr;

void Logger::Set(Logger *logger)
{
    s_logger = logger;
}

Logger *Logger::Get()
{
    return s_logger;
}

Logger::Logger()
    : m_report_pass(false)
{
}

Logger::~Logger()
{
}

void Logger::SetReportPass(bool report_pass)
{
    m_report_pass = report_pass;
}

bool Logger::GetReportPass()
{
    return m_report_pass;
}

Logger &Logger::operator<<(Logger &(*op)(Logger &))
{
    return (*op)(*this);
}

ESYSTEST_API Logger &endl(Logger &log)
{
    return log.endl();
}

} // namespace esystest
