/*!
 * \file esys/base/em/log_if.h
 * \brief
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

#include "esys/base/esysbase_defs.h"

namespace esys::base
{

namespace em
{

/*! \class Log_if esys/base/em/log_if.h "esys/base/em/log_if.h"
 * \brief Logging interface
 */
class ESYSBASE_API Log_if
{
public:
    //! Constructor
    Log_if();

    //! Destructor
    virtual ~Log_if();

    //! Log a debug message
    /*!
     * \param[in] level the level of the debug message
     * \param[in] msg the message to log
     *
     * Message will appear in the logs only if the level <= to the debug level.
     */
    virtual void debug(int level, const char *msg) = 0;

    //! Log an information message
    /*!
     * \param[in] msg the information message to log
     */
    virtual void info(const char *msg) = 0;

    //! Log a warning message
    /*!
     * \param[in] msg the message to log
     */
    virtual void warn(const char *msg) = 0;

    //! Log an error message
    /*!
     * \param[in] msg the message to log
     */
    virtual void error(const char *msg) = 0;

    //! Log a critical message
    /*!
     * \param[in] msg the message to log
     */
    virtual void critical(const char *msg) = 0;
};

} // namespace em

#ifdef ESYSBASE_EM
using namespace em;
#endif

} // namespace esys::base
