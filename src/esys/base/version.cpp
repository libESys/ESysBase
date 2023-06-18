/*!
 * \file esys/base/version.cpp
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

#include "esys/base/esysbase_prec.h"
#include "esys/base/version.h"

#include <boost/algorithm/string.hpp>

#include <sstream>
#include <vector>

namespace esys::base
{

Version::Version() = default;

Version::Version(const std::string &version)
{
    set(version);
}

Version::Version(int major, int minor, int patch)
{
    set(major, minor, patch);
}

void Version::set(const std::string &version)
{
    std::vector<std::string> versions;

    m_version = version;

    boost::split(versions, version, boost::is_any_of("."));

    if (versions.size() < 1) return;
    set_major(atoi(versions[0].c_str()));
    if (versions.size() < 2) return;
    set_minor(atoi(versions[1].c_str()));
    if (versions.size() < 3) return;
    set_patch(atoi(versions[2].c_str()));
}

const std::string &Version::get() const
{
    return m_version;
}

void Version::set(int major, int minor, int patch)
{
    m_major = major;
    m_minor = minor;
    m_patch = patch;

    update_string();
}

void Version::set_major(int major)
{
    m_major = major;
    update_string();
}

int Version::get_major() const
{
    return m_major;
}

void Version::set_minor(int minor)
{
    m_minor = minor;
    update_string();
}

int Version::get_minor() const
{
    return m_minor;
}

void Version::set_patch(int patch)
{
    m_patch = patch;
    update_string();
}

int Version::get_patch() const
{
    return m_patch;
}

void Version::update_string()
{
    std::ostringstream oss;

    oss << m_major;
    if (m_minor < 0)
    {
        m_version = oss.str();
        return;
    }
    oss << "." << m_minor;
    if (m_patch < 0)
    {
        m_version = oss.str();
        return;
    }
    oss << "." << m_patch;
    m_version = oss.str();
}

} // namespace esys::base