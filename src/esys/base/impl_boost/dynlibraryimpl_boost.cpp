/*!
 * \file esys/base/boost/dynlibraryimpl_boost.cpp
 * \brief
 *
 * \cond
 * __legal_b__
 *
 * Copyright (c) 2019-2020 Michel Gillet
 * Distributed under the MIT License.
 * (See accompanying file LICENSE.txt or
 * copy at https://opensource.org/licenses/MIT)
 *
 * __legal_e__
 * \endcond
 *
 */

#include "esys/base/esysbase_prec.h"
#include "esys/base/impl_boost/dynlibraryimpl.h"

namespace esys::base::impl_boost
{

DynLibraryImpl::DynLibraryImpl(DynLibrary *self)
    : m_self(self)
{
}

DynLibraryImpl::~DynLibraryImpl()
{
    if (m_lib.is_loaded()) m_lib.unload();
}

int DynLibraryImpl::load(const std::string &filename, std::string &last_error)
{
    last_error = "";

    try
    {
        m_lib.load(filename);
    }
    catch (::boost::system::system_error &e)
    {
        last_error = e.what();
        return -1;
    }

    if (m_lib.is_loaded()) return 0;

    return -1;
}

int DynLibraryImpl::unload()
{
    if (!m_lib.is_loaded()) return -1;
    m_lib.unload();
    return 0;
}

bool DynLibraryImpl::is_loaded()
{
    return m_lib.is_loaded();
}

bool DynLibraryImpl::has_symbol(const std::string &name)
{
    return m_lib.has(name);
}

void *DynLibraryImpl::get_symbol(const std::string &name)
{

    if (!has_symbol(name)) return nullptr;

    return (void *)m_lib.get<void()>(name);
}

} // namespace esys::base::impl_boost
