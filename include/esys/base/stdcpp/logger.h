/*!
 * \file esys/base/stdcpp/logger.h
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
#include "esys/base/stdcpp/log_if.h"

#include <ostream>

namespace esys::base
{

namespace stdcpp
{

/*! \class Logger esys/base/stdcpp/loggger.h "esys/base/stdcpp/logger.h"
 * \brief Logger
 */
class ESYSBASE_API Logger : public Log_if
{
public:
    //! Constructor
    Logger();

    //! Destructor
    ~Logger() override;

    void debug(int level, const std::string &msg) override;
    void info(const std::string &msg) override;
    void warn(const std::string &msg) override;
    void error(const std::string &msg) override;
    void critical(const std::string &msg) override;

    void set_os(std::ostream *os);
    void set_os(std::ostream &os);
    std::ostream *get_os();

private:
    std::ostream *m_os = nullptr;
};

} // namespace stdcpp

#ifndef ESYSBASE_EM
using namespace stdcpp;
#endif

} // namespace esys::base
