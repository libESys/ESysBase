/*!
 * \file esystest/logger.h
 * \brief
 *
 * \cond
 *__legal_b__
 *
 *__legal_e__
 * \endcond
 *
 */

#include "esystest/esystest_prec.h"
#include "esystest/logger.h"

namespace esystest
{

Logger *Logger::m_logger = nullptr;

void Logger::Set(Logger *logger)
{
    m_logger = logger;
}

Logger *Logger::Get()
{
    return m_logger;
}

Logger::Logger(): m_report_pass(false)
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

}


