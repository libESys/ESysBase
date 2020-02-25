/*!
 * \file esystest/stdlogger.cpp
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
#include "esystest/stdlogger.h"

namespace esystest
{

StdLogger::StdLogger()
    : Logger_t<std::ostream>()
{
}

StdLogger::~StdLogger()
{
}

Logger &StdLogger::endl()
{
    if (m_logger != nullptr) *m_logger << std::endl;
    return *this;
}

} // namespace esystest
