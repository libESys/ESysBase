/*!
 * \file esysbase/version.h
 * \brief Version info for esysbaseexe
 *
 * \cond
 * __legal_b__
 *
 * Copyright (c) 2020-2023 Michel Gillet
 * Distributed under the MIT License.
 * (See accompanying file LICENSE.txt or
 * copy at https://opensource.org/licenses/MIT)
 *
 * __legal_e__
 * \endcond
 *
 */

#pragma once

// Bump-up with each new version
#define ESYSBASEEXE_MAJOR_VERSION    0
#define ESYSBASEEXE_MINOR_VERSION    0
#define ESYSBASEEXE_RELEASE_NUMBER   1
#define ESYSBASEEXE_VERSION_STRING   "esysbaseexe 0.0.1"

// Must be updated manually as well each time the version above changes
#define ESYSBASEEXE_VERSION_NUM_DOT_STRING   "0.0.1"
#define ESYSBASEEXE_VERSION_NUM_STRING       "0001"

// nothing should be updated below this line when updating the version

#define ESYSBASEEXE_VERSION_NUMBER (ESYSBASEEXE_MAJOR_VERSION * 1000) + (ESYSBASEEXE_MINOR_VERSION * 100) + ESYSBASEEXE_RELEASE_NUMBER
#define ESYSBASEEXE_BETA_NUMBER      1
#define ESYSBASEEXE_VERSION_FLOAT ESYSBASEEXE_MAJOR_VERSION + (ESYSBASEEXE_MINOR_VERSION/10.0) + (ESYSBASEEXE_RELEASE_NUMBER/100.0) + (ESYSBASEEXE_BETA_NUMBER/10000.0)

// check if the current version is at least major.minor.release
#define ESYSBASEEXE_CHECK_VERSION(major,minor,release) \
    (ESYSBASEEXE_MAJOR_VERSION > (major) || \
    (ESYSBASEEXE_MAJOR_VERSION == (major) && ESYSBASEEXE_MINOR_VERSION > (minor)) || \
    (ESYSBASEEXE_MAJOR_VERSION == (major) && ESYSBASEEXE_MINOR_VERSION == (minor) && ESYSBASEEXE_RELEASE_NUMBER >= (release)))
