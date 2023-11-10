/*!
 * \file esys/base/pluginmngrcore.h
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

#ifndef ESYSBASE_PLUGIN_USE_WX
#ifndef ESYSBASE_PLUGIN_USE_BOOST
#define ESYSBASE_PLUGIN_USE_BOOST
#endif
#include "esys/base/impl_boost/pluginmngrcore.h"
#else
#include "esys/base/impl_wx/pluginmngrcore.h"
#endif
