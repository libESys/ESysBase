/*!
 * \file esystest/exception.h
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
#include "esystest/inttypes.h"

namespace esystest
{

class ESYSTEST_API Exception
{
public:
    typedef uint16_t ID;

    static const ID UNKNOWN = 0;
    static const ID TEST_FAILED = 1;

    Exception(ID id = UNKNOWN);

    void SetId(ID id);
    ID GetId() const;

protected:
    ID m_id;
};

} // namespace esystest
