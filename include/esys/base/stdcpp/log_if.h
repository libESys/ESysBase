/*!
 * \file esys/base/stdcpp/log_if.h
 * \brief
 *
 * \cond
 * __legal_b__
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

namespace stdcpp
{

/*! \class Log_if esys/base/stdcpp/log_if.h "esys/base/stdcpp/log_if.h"
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
    virtual void debug(int level, const std::string &msg) = 0;

    //! Log an information message
    /*!
     * \param[in] msg the information message to log
     */
    virtual void info(const std::string &msg) = 0;

    //! Log a warning message
    /*!
     * \param[in] msg the message to log
     */
    virtual void warn(const std::string &msg) = 0;

    //! Log an error message
    /*!
     * \param[in] msg the message to log
     */
    virtual void error(const std::string &msg) = 0;

    //! Log a critical message
    /*!
     * \param[in] msg the message to log
     */
    virtual void critical(const std::string &msg) = 0;
};

} // namespace stdcpp

#ifndef ESYSBASE_EM
using namespace stdcpp;
#endif

} // namespace esys::base
