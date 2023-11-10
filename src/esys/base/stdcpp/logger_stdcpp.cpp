/*!
 * \file esys/base/stdcpp/logger_stdcpp.cpp
 * \brief
 *
 * \cond
 * __legal_b__
 *
 * Copyright (c) 2020-2023 Michel Gillet
 * Distributed under the MIT License.
 * (See accompanying file LICENSE.txt or
 * copy at https://opensource.org/licenses/MIT)
 *
 * __legal_e__
 * \endcond
 *
 */

#include "esys/base/esysbase_prec.h"
#include "esys/base/stdcpp/logger.h"

namespace esys::base::stdcpp
{

Logger::Logger() = default;

Logger::~Logger() = default;

void Logger::trace(const std::string &msg)
{
    if (m_os == nullptr) return;

    *m_os << "[trace] " << msg << std::endl;
    m_os->flush();
}

void Logger::debug(int level, const std::string &msg)
{
    if (m_os == nullptr) return;

    *m_os << "[debug " << level << "] " << msg << std::endl;
    m_os->flush();
}

void Logger::info(const std::string &msg)
{
    if (m_os == nullptr) return;

    *m_os << "[info] " << msg << std::endl;
    m_os->flush();
}

void Logger::warn(const std::string &msg)
{
    if (m_os == nullptr) return;

    *m_os << "[warn] " << msg << std::endl;
    m_os->flush();
}

void Logger::error(const std::string &msg)
{
    if (m_os == nullptr) return;

    *m_os << "[error] " << msg << std::endl;
    m_os->flush();
}

void Logger::critical(const std::string &msg)
{
    if (m_os == nullptr) return;

    *m_os << "[critical] " << msg << std::endl;
    m_os->flush();
}

void Logger::set_os(std::ostream *os)
{
    m_os = os;
}

void Logger::set_os(std::ostream &os)
{
    m_os = &os;
}

std::ostream *Logger::get_os()
{
    return m_os;
}

} // namespace esys::base::stdcpp
