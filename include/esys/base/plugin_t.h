/*!
 * \file esys/base/plugin_t.h
 * \brief
 *
 * \cond
 * __legal_b__
 *
 * Copyright (c) 2017-2022 Michel Gillet
 * Distributed under the MIT License.
 * (See accompanying file LICENSE.txt or
 * copy at https://opensource.org/licenses/MIT)
 *
 * __legal_e__
 * \endcond
 *
 */

#pragma once

namespace esys::base
{

/*! \class Plugin_t esys/base/plugin_t.h "esys/base/plugin_t.h"
 * \brief Plugin class
 *
 */
template<typename DERIVED, typename BASE>
class Plugin_t : public BASE
{
public:
    Plugin_t();
    virtual ~Plugin_t();
};

template<typename DERIVED, typename BASE>
Plugin_t<DERIVED, BASE>::Plugin_t()
    : BASE()
{
    bool debug;

#ifdef _MSC_VER
#ifdef _DEBUG
    debug = true;
#elif NDEBUG
    debug = false;
#else
#error _DEBUG or NDEBUG must be defined
#endif
#else
    debug = false;
#endif
    this->set_debug(debug);
}

template<typename DERIVED, typename BASE>
Plugin_t<DERIVED, BASE>::~Plugin_t()
{
}

} // namespace esys::base
