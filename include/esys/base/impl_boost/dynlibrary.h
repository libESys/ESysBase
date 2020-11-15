/*!
 * \file esys/base/impl_boost/dynlibrary.h
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

#pragma once

#include "esys/base/dynlibrarybase.h"

#include <memory>

namespace esys
{

namespace base
{

namespace impl_boost
{

class ESYSBASE_API DynLibraryImpl;

/*! \class DynLibrary esys/base/impl_boost/dynlibrary.h "esys/base/impl_boost/dynlibrary.h"
 * \brief Boost implementation to handle a dynamic library
 */
class ESYSBASE_API DynLibrary : public DynLibraryBase
{
public:
    //! Default constructor
    DynLibrary();

    //! Destructor
    virtual ~DynLibrary();

    int load(const std::string &filename) override;
    int unload() override;
    bool is_loaded() override;
    bool has_symbol(const std::string &name) override;
    void *get_symbol(const std::string &name) override;

protected:
    //!< \cond DOXY_IMPL
    std::unique_ptr<DynLibraryImpl> m_impl; //!< The PIMPL instance
    //!< \endcond
};

} // namespace impl_boost

#ifdef ESYSBASE_DYNLIB_USE_BOOST
using namespace impl_boost;
#endif

} // namespace base

} // namespace esys
