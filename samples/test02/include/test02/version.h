/*!
 * \file esystest/version.h
 * \brief Version info for test02
 *
 * \cond
 *__legal_b__
 *
 *__legal_e__
 * \endcond
 *
 */

#ifndef __TEST02_VERSION_H__
#define __TEST02_VERSION_H__

// Bump-up with each new version
#define TEST02_MAJOR_VERSION    0
#define TEST02_MINOR_VERSION    0
#define TEST02_RELEASE_NUMBER   1
#define TEST02_VERSION_STRING   _T("test02 0.0.1")

// Must be updated manually as well each time the version above changes
#define TEST02_VERSION_NUM_DOT_STRING   "0.0.1"
#define TEST02_VERSION_NUM_STRING       "0001"

// nothing should be updated below this line when updating the version

#define TEST02_VERSION_NUMBER (TEST02_MAJOR_VERSION * 1000) + (TEST02_MINOR_VERSION * 100) + TEST02_RELEASE_NUMBER
#define TEST02_BETA_NUMBER      1
#define TEST02_VERSION_FLOAT TEST02_MAJOR_VERSION + (TEST02_MINOR_VERSION/10.0) + (TEST02_RELEASE_NUMBER/100.0) + (TEST02_BETA_NUMBER/10000.0)

// check if the current version is at least major.minor.release
#define TEST02_CHECK_VERSION(major,minor,release) \
    (TEST02_MAJOR_VERSION > (major) || \
    (TEST02_MAJOR_VERSION == (major) && TEST02_MINOR_VERSION > (minor)) || \
    (TEST02_MAJOR_VERSION == (major) && TEST02_MINOR_VERSION == (minor) && TEST02_RELEASE_NUMBER >= (release)))

#endif

