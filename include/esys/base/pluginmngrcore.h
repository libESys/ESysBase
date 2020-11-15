/*!
 * \file esys/base/pluginmngrcore.h
 * \brief
 *
 * \cond
 * __legal_b__
 *
 * Copyright (c) 2017-2020 Michel Gillet
 * Distributed under the wxWindows Library Licence, Version 3.1.
 * (See accompanying file LICENSE_3_1.txt or
 * copy at http://www.wxwidgets.org/about/licence)
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
