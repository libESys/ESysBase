/*!
 * \file esys/base/impl_boost/dynlibraryimpl.h
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

#pragma once

#include "esys/base/impl_boost/dynlibrary.h"

#include <boost/dll.hpp>

namespace esys::base::impl_boost
{

class ESYSBASE_API DynLibraryImpl
{
public:
    explicit DynLibraryImpl(DynLibrary *self);
    virtual ~DynLibraryImpl();

    int load(const std::string &filename, std::string &last_error);
    int unload();
    bool is_loaded();
    bool has_symbol(const std::string &name);
    void *get_symbol(const std::string &name);

private:
    DynLibrary *m_self = nullptr;
    boost::dll::shared_library m_lib;
};

} // namespace esys::base::impl_boost
