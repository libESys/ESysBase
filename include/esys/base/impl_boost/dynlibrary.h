/*!
 * \file esys/base/impl_boost/dynlibrary.h
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

#pragma once

#include "esys/base/dynlibrarybase.h"

#include <memory>

namespace esys::base::impl_boost
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
    ~DynLibrary() override;

    int load(const std::string &filename) override;
    int unload() override;
    bool is_loaded() override;
    bool has_symbol(const std::string &name) override;
    void *get_symbol(const std::string &name) override;

private:
    //!< \cond DOXY_IMPL
    std::unique_ptr<DynLibraryImpl> m_impl; //!< The PIMPL instance
    //!< \endcond
};

#ifdef ESYSBASE_DYNLIB_USE_BOOST
using namespace impl_boost;
#endif

} // namespace esys::base::impl_boost
