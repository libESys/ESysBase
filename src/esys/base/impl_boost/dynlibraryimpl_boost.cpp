/*!
 * \file esys/base/boost/dynlibraryimpl_boost.cpp
 * \brief
 *
 * \cond
 * __legal_b__
 *
 * Copyright (c) 2019-2020 Michel Gillet
 * Distributed under the wxWindows Library Licence, Version 3.1.
 * (See accompanying file LICENSE_3_1.txt or
 * copy at http://www.wxwidgets.org/about/licence)
 *
 * __legal_e__
 * \endcond
 *
 */

#include "esys/base/esysbase_prec.h"
#include "esys/base/impl_boost/dynlibraryimpl.h"

namespace esys
{

namespace base
{

namespace impl_boost
{

DynLibraryImpl::DynLibraryImpl(DynLibrary *self)
    : m_self(self)
{
}

DynLibraryImpl::~DynLibraryImpl()
{
    if (m_lib.is_loaded()) m_lib.unload();
}

int DynLibraryImpl::load(const std::string &filename)
{
    try
    {
        m_lib.load(filename);
    }
    catch (::boost::system::system_error &)
    {
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

} // namespace impl_boost

} // namespace base

} // namespace esys
