/*!
 * \file esys/base/version.h
 * \brief
 *
 * \cond
 * __legal_b__
 *
 * Copyright (c) 2023 Michel Gillet
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

/*! \class Version esys/base/version.h "esys/base/version.h"
 * \brief Base class for all plugin managers
 */
class ESYSBASE_API Version
{
public:
    Version();
    Version(const std::string &version);
    Version(int major, int minor, int patch = 0);

    //! Set the version as text following semantic versioning format
    /*!
     * \param[in] version the version
     */
    void set(const std::string &version);

    //! Get the version of the Plugin Manager
    /*!
     * \return the version of the Plugin Manager
     */
    const std::string &get() const;

    //! Set the version
    /*!
     * \param[in] major the major part of the version
     * \param[in] minor the minor part of the version
     * \param[in] patch the pacth part of the version
     */
    void set(int major, int minor = -1, int patch = -1);

    //! Set the major part of the version
    /*!
     * \param[in] major the major part of the version
     */
    void set_major(int major);

    //! Get the major part of the version
    /*!
     * \return the major part of the version
     */
    int get_major() const;

    //! Set the minor part of version
    /*!
     * \param[in] minor the minor part of the version
     */
    void set_minor(int minor);

    //! Get the minor part of version
    /*!
     * \return the minor part of the version
     */
    int get_minor() const;

    //! Set the patch part of version
    /*!
     * \param[in] patch the patch part of the version
     */
    void set_patch(int patch_part);

    //! Get the patch part of the version
    /*!
     * \return the patch part of the version
     */
    int get_patch() const;

private:
    //!< \cond DOXY_IMPL
    void update_string();

    std::string m_version; //!< The textual representation
    int m_major = 0;       //!< The major part of the semantic versioning
    int m_minor = -1;      //!< The minor part of the semantic versioning
    int m_patch = -1;      //!< The patch part of the semantic versioning
};

} // namespace esys::base