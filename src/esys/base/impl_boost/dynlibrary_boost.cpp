/*!
 * \file esys/base/impl_boost/dynlibrary_boost.cpp
 * \brief
 *
 * \cond
 * __legal_b__
 *
 * Copyright (c) 2019 Michel Gillet
 * Distributed under the MIT License.
 * (See accompanying file LICENSE.txt or
 * copy at https://opensource.org/licenses/MIT)
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

    std::string last_error;

    auto result = m_impl->load(filename, last_error);

    set_last_error(last_error);
    return result;
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
