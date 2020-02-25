/*!
 * \file esystest/stdlogger.h
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

#pragma once

#include "esystest/esystest_defs.h"
#include "esystest/logger.h"

#include <ostream>

namespace esystest
{

class ESYSTEST_API StdLogger : public Logger_t<std::ostream>
{
public:
    StdLogger();
    virtual ~StdLogger();

    virtual Logger &endl();
};

} // namespace esystest
