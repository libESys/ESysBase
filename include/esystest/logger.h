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

    virtual Logger& operator<< (const char *value) = 0;
    virtual Logger& operator<< (const uint8_t &value) = 0;
    virtual Logger& operator<< (const uint16_t &value) = 0;
    virtual Logger& operator<< (const uint32_t &value) = 0;
    virtual Logger& operator<< (const int8_t &value) = 0;
    virtual Logger& operator<< (const int16_t &value) = 0;
    virtual Logger& operator<< (const int32_t &value) = 0;

    virtual Logger& operator<< (uint8_t value) = 0;

    virtual Logger& endl() = 0;

    Logger& operator<< (Logger& (*op)(Logger&));

    void SetReportPass(bool report_pass);
    bool GetReportPass();

    static void Set(Logger *logger);
    static Logger *Get();
protected:
    static Logger *s_logger;
    bool m_report_pass;
};

template<typename T>
class Logger_t : public Logger
{
public:
    Logger_t();
    virtual ~Logger_t();

    virtual Logger& operator<< (const char *value);
    virtual Logger& operator<< (const uint8_t &value);
    virtual Logger& operator<< (const uint16_t &value);
    virtual Logger& operator<< (const uint32_t &value);
    virtual Logger& operator<< (const int8_t &value);
    virtual Logger& operator<< (const int16_t &value);
    virtual Logger& operator<< (const int32_t &value);

    virtual Logger& operator<< (uint8_t value);

    void Set(T *logger);
    T *Get();
protected:
    T *m_logger;
};

ESYSTEST_API Logger& endl(Logger &log);

template<typename T>
Logger_t<T>::Logger_t(): m_logger(nullptr)
{
}

template<typename T>
Logger_t<T>::~Logger_t()
{
}

template<typename T>
Logger& Logger_t<T>::operator<< (const char *value)
{
    if (m_logger != nullptr)
        *m_logger << value;
    return *this;
}

template<typename T>
Logger& Logger_t<T>::operator<< (const uint8_t &value)
{
    if (m_logger != nullptr)
        *m_logger << value;
    return *this;
}

template<typename T>
Logger& Logger_t<T>::operator<< (const uint16_t &value)
{
    if (m_logger != nullptr)
        *m_logger << value;
    return *this;
}

template<typename T>
Logger& Logger_t<T>::operator<< (const uint32_t &value)
{
    if (m_logger != nullptr)
        *m_logger << value;
    return *this;
}

template<typename T>
Logger& Logger_t<T>::operator<< (const int8_t &value)
{
    if (m_logger != nullptr)
        *m_logger << value;
    return *this;
}

template<typename T>
Logger& Logger_t<T>::operator<< (const int16_t &value)
{
    if (m_logger != nullptr)
        *m_logger << value;
    return *this;
}

template<typename T>
Logger& Logger_t<T>::operator<< (const int32_t &value)
{
    if (m_logger != nullptr)
        *m_logger << value;
    return *this;
}

template<typename T>
Logger& Logger_t<T>::operator<< (uint8_t value)
{
    if (m_logger != nullptr)
        *m_logger << value;
    return *this;
}

template<typename T>
void Logger_t<T>::Set(T *logger)
{
    m_logger = logger;
}

template<typename T>
T *Logger_t<T>::Get()
{
    return m_logger;
}

}

#endif

