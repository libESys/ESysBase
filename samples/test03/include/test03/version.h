/*!
 * \file esystest/version.h
 * \brief Version info for test03
 *
 * \cond
 *__legal_b__
 *
 *__legal_e__
 * \endcond
 *
 */

#ifndef __TEST03_VERSION_H__
#define __TEST03_VERSION_H__

// Bump-up with each new version
#define TEST03_MAJOR_VERSION    0
#define TEST03_MINOR_VERSION    0
#define TEST03_RELEASE_NUMBER   1
#define TEST03_VERSION_STRING   _T("test03 0.0.1")

// Must be updated manually as well each time the version above changes
#define TEST03_VERSION_NUM_DOT_STRING   "0.0.1"
#define TEST03_VERSION_NUM_STRING       "0001"

// nothing should be updated below this line when updating the version

#define TEST03_VERSION_NUMBER (TEST03_MAJOR_VERSION * 1000) + (TEST03_MINOR_VERSION * 100) + TEST03_RELEASE_NUMBER
#define TEST03_BETA_NUMBER      1
#define TEST03_VERSION_FLOAT TEST03_MAJOR_VERSION + (TEST03_MINOR_VERSION/10.0) + (TEST03_RELEASE_NUMBER/100.0) + (TEST03_BETA_NUMBER/10000.0)

// check if the current version is at least major.minor.release
#define TEST03_CHECK_VERSION(major,minor,release) \
    (TEST03_MAJOR_VERSION > (major) || \
    (TEST03_MAJOR_VERSION == (major) && TEST03_MINOR_VERSION > (minor)) || \
    (TEST03_MAJOR_VERSION == (major) && TEST03_MINOR_VERSION == (minor) && TEST03_RELEASE_NUMBER >= (release)))

#endif

