/*!
 * \file esys/base/dynlibrarybase.cpp
 * \brief
 *
 * \cond
 * __legal_b__
 *
 * Copyright (c) 2018-2020 Michel Gillet
 * Distributed under the wxWindows Library Licence, Version 3.1.
 * (See accompanying file LICENSE_3_1.txt or
 * copy at http://www.wxwidgets.org/about/licence)
 *
 * __legal_e__
 * \endcond
 *
 */

#include "esys/base/esysbase_prec.h"
#include "esys/base/dynlibrarybase.h"

namespace esys::base
{

DynLibraryBase::DynLibraryBase() = default;

DynLibraryBase::~DynLibraryBase() = default;

const std::string &DynLibraryBase::get_last_error() const
{
    return m_last_error;
}

void DynLibraryBase::set_last_error(const std::string &last_error)
{
    m_last_error = last_error;
}

} // namespace esys::base
