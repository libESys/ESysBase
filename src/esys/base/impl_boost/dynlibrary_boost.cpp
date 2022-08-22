/*!
 * \file esys/base/impl_boost/dynlibrary_boost.cpp
 * \brief
 *
 * \cond
 * __legal_b__
 *
 * Copyright (c) 2019 Michel Gillet
 * Distributed under the wxWindows Library Licence, Version 3.1.
 * (See accompanying file LICENSE_3_1.txt or
 * copy at http://www.wxwidgets.org/about/licence)
 *
 * __legal_e__
 * \endcond
 *
 */

#include "esys/base/esysbase_prec.h"
#include "esys/base/impl_boost/dynlibrary.h"
#include "esys/base/impl_boost/dynlibraryimpl.h"

#include <cassert>

namespace esys::base::impl_boost
{

DynLibrary::DynLibrary()
    : DynLibraryBase()
{
    m_impl = std::make_unique<DynLibraryImpl>(this);
}

DynLibrary::~DynLibrary() = default;

int DynLibrary::load(const std::string &filename)
{
    assert(m_impl != nullptr);

    return m_impl->load(filename);
}

int DynLibrary::unload()
{
    assert(m_impl != nullptr);

    return m_impl->unload();
}

bool DynLibrary::is_loaded()
{
    assert(m_impl != nullptr);

    return m_impl->is_loaded();
}

bool DynLibrary::has_symbol(const std::string &name)
{
    assert(m_impl != nullptr);

    return m_impl->has_symbol(name);
}

void *DynLibrary::get_symbol(const std::string &name)
{
    assert(m_impl != nullptr);

    return m_impl->get_symbol(name);
}

} // namespace esys::base::impl_boost
