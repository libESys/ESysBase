/*!
 * \file esys/base/dynlibrarybase.h
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

#include "esys/base/esysbase_defs.h"

#include <string>

namespace esys::base
{

/*! \class DynLibraryBase esys/base/dynlibrarybase.h "esys/base/dynlibrarybase.h"
 * \brief Base class for all implementation handling a dynamic library
 */
class ESYSBASE_API DynLibraryBase
{
public:
    //! Default constructor
    DynLibraryBase();

    //! Destructor
    virtual ~DynLibraryBase();

    //! Load a dynamic library
    /*!
     * \param[in] filename full path name of the dynamic library to load
     * \return 0 if successful, < 0 otherwise
     */
    virtual int load(const std::string &filename) = 0;

    //! Unload a dynamic library
    /*!
     * \return 0 if successful, < 0 otherwise
     */
    virtual int unload() = 0;

    //! Tells if the library was loaded or not
    /*!
     * \return true if the library is loaded, false othewise
     */
    virtual bool is_loaded() = 0;

    //! Tells if the library has a given symbol
    /*!
     * \param[in] name the name of the symbol
     * \return true if the library has this symbol loaded, false othewise
     */
    virtual bool has_symbol(const std::string &name) = 0;

    //! Get a given symbol
    /*!
     * \param[in] name the name of the symbol
     * \return the symbol is existing, nullptr otherwise
     */
    virtual void *get_symbol(const std::string &name) = 0;

    const std::string &get_last_error() const;

protected:
    void set_last_error(const std::string &last_error);

private:
    std::string m_last_error;
};

} // namespace esys::base
