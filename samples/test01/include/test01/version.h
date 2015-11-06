/*!
 * \file esystest/version.h
 * \brief Version info for test01
 *
 * \cond
 *__legal_b__
 *
 *__legal_e__
 * \endcond
 *
 */

#ifndef __TEST01_VERSION_H__
#define __TEST01_VERSION_H__

// Bump-up with each new version
#define TEST01_MAJOR_VERSION    0
#define TEST01_MINOR_VERSION    0
#define TEST01_RELEASE_NUMBER   1
#define TEST01_VERSION_STRING   _T("test01 0.0.1")

// Must be updated manually as well each time the version above changes
#define TEST01_VERSION_NUM_DOT_STRING   "0.0.1"
#define TEST01_VERSION_NUM_STRING       "0001"

// nothing should be updated below this line when updating the version

#define TEST01_VERSION_NUMBER (TEST01_MAJOR_VERSION * 1000) + (TEST01_MINOR_VERSION * 100) + TEST01_RELEASE_NUMBER
#define TEST01_BETA_NUMBER      1
#define TEST01_VERSION_FLOAT TEST01_MAJOR_VERSION + (TEST01_MINOR_VERSION/10.0) + (TEST01_RELEASE_NUMBER/100.0) + (TEST01_BETA_NUMBER/10000.0)

// check if the current version is at least major.minor.release
#define TEST01_CHECK_VERSION(major,minor,release) \
    (TEST01_MAJOR_VERSION > (major) || \
    (TEST01_MAJOR_VERSION == (major) && TEST01_MINOR_VERSION > (minor)) || \
    (TEST01_MAJOR_VERSION == (major) && TEST01_MINOR_VERSION == (minor) && TEST01_RELEASE_NUMBER >= (release)))

#endif

