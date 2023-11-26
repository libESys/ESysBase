/*!
 * \file esysbasesexe/esysbaseexe.cpp
 * \brief
 *
 * \cond
 * __legal_b__
 *
 * Copyright (c) 2018-2023 Michel Gillet
 * Distributed under the MIT License.
 * (See accompanying file LICENSE.txt or
 * copy at https://opensource.org/licenses/MIT)
 *
 * __legal_e__
 * \endcond
 *
 */

#include "esysbaseexe/esysbaseexe_prec.h"
#include "esysbaseexe/esysbaseexe.h"

#include <esys/base/pluginmngr.h>

#include <esys/trace/call.h>
#include <esys/trace/macros.h>

#include <boost/program_options/cmdline.hpp>
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/locale.hpp>

#include <iostream>
#include <iomanip>
#include <string>

ESysBaseExe::ESysBaseExe()
    : esys::log::User()
{
    // m_logger = std::make_shared<esys::base::stdcpp::Logger>();
    // m_logger->set_os(std::cout);
}

ESysBaseExe::~ESysBaseExe() = default;

void ESysBaseExe::set_os(std::ostream &os)
{
    m_os = &os;
    // m_logger->set_os(os);
}

std::ostream *ESysBaseExe::get_os()
{
    return m_os;
}

void ESysBaseExe::set_args(int argc, char **argv)
{
    m_args.clear();

    m_argc = argc;

    for (int i = 1; i < argc; ++i)
    {
#ifdef WIN32
        std::vector<std::string> temp_args = po::split_winmain(argv[i]);
        m_args.insert(m_args.end(), temp_args.begin(), temp_args.end());
#else
        std::string temp = argv[i];
        m_args.push_back(temp);
#endif
    }
    // m_argv = m_args.data();
}

int ESysBaseExe::parse_args()
{
    bool parse_error = false;
    bool strict = false;
    po::positional_options_description p;
    // p.add("input", -1);

    m_desc = new po::options_description("Allowed options");
    // clang-format off
    m_desc->add_options()
        ("help,h", "produce help message")
        ("list_plugins", po::value<std::string>()->implicit_value(""), "list plugins of the given application")
        ("verbose", po::value<int>()->default_value(0)->implicit_value(1), "set verbose level")
        ("debug", po::value<bool>()->default_value(false)->implicit_value(true), "set debug mode, default random variable")
        ("trace", po::value<bool>()->default_value(false)->implicit_value(true), "set trace mode")
        ("no_esyslog", po::value<bool>()->default_value(false)->implicit_value(true), "don't use esyslog for traces")
        ;
    // clang-format on

    try
    {
        // po::store(po::wcommand_line_parser(m_argc, m_argv).options(desc).positional(p).run(), vm);
        if (strict == false)
        {
            po::parsed_options parsed =
                po::command_line_parser(m_args).options(*m_desc)./*positional(p).*/ allow_unregistered().run();
            m_to_parse_further = po::collect_unrecognized(parsed.options, po::include_positional);
            po::store(parsed, m_vm);
        }
        else
        {
            po::parsed_options parsed = po::command_line_parser(m_args).options(*m_desc).positional(p).run();
            m_to_parse_further = po::collect_unrecognized(parsed.options, po::include_positional);
            po::store(parsed, m_vm);
        }
        po::notify(m_vm);
    }
    catch (po::error &e)
    {
        m_parse_error = true;
        set_error_msg(e.what());
        // std::cout << e.what() << std::endl << std::flush;
    }

    if (m_parse_error) return -1;
    return 0;
}

bool ESysBaseExe::get_debug() const
{
    return m_vm["debug"].as<bool>();
}

bool ESysBaseExe::get_trace() const
{
    return m_vm["trace"].as<bool>();
}

bool ESysBaseExe::get_no_esyslog() const
{
    return m_vm["no_esyslog"].as<bool>();
}

int ESysBaseExe::run()
{
    ETRC_CALL_RET_DEF_NP(int, result);

    if (m_vm.count("help"))
    {
        if (get_os() != nullptr) print_help(*get_os());
        return ETRC_RET(0);
    }
    if (m_vm.count("list_plugins"))
    {
        return ETRC_RET(cmd_list_plugings());
    }
    return ETRC_RET(-1);
}

int ESysBaseExe::cmd_list_plugings()
{
    ETRC_CALL_RET_DEF_NP(int, result);

    if (get_os() == nullptr) return ETRC_RET(-17);

    if (m_vm.count("list_plugins") == 0) return ETRC_RET(-18);

    std::string app_name = m_vm["list_plugins"].as<std::string>();

    esys::base::PluginMngr mngr;
    mngr.set_log_if(m_logger);
    mngr.set_verbose_level(m_vm["verbose"].as<int>());

    if (!app_name.empty()) mngr.set_name(app_name);

    int l_result = mngr.load();
    if (l_result < 0)
    {
        *get_os() << "No plugins found" << std::endl;
        return ETRC_RET(l_result);
    }

    *get_os() << "Number of '" << app_name << "' Plugins : " << mngr.get_plugins().size() << std::endl;

    esys::base::PluginBase *plugin;
    std::size_t idx;

    for (idx = 0; idx < mngr.get_plugins().size(); ++idx)
    {
        plugin = mngr.get(idx);

        assert(plugin != nullptr);

        *get_os() << "[" << idx << "] " << plugin->get_name() << " " << plugin->get_version() << std::endl;
        *get_os() << "    Filename : " << plugin->get_filename() << std::endl;
    }
    *get_os() << std::endl;
    return ETRC_RET(0);
}

void ESysBaseExe::set_error_msg(const std::string &error_msg)
{
    m_error_msg = error_msg;
}

const std::string &ESysBaseExe::get_error_msg()
{
    return m_error_msg;
}

void ESysBaseExe::create_esystrace_log()
{
    if (m_trace_logger != nullptr) return;

    m_trace_logger = std::make_shared<esys::trace::Logger>();
    m_trace_logger->use_std_streams("etrc_call01.txt");
    esys::trace::Call::set_default_logger(m_trace_logger.get());
    esys::trace::Call::enable();
}

void ESysBaseExe::create_esyslog_log()
{
    if (m_logger != nullptr) return;

    if (m_logger_mngr == nullptr) m_logger_mngr = esys::log::Mngr::get();
    m_logger = m_logger_mngr->new_logger(esys::log::LoggerType::SPDLOG, "metacppcli");
    if (m_logger != nullptr)
    {
        set_logger_if(m_logger);

        auto level = esys::log::Level::DEBUG;
        if (get_trace()) level = esys::log::Level::TRACE;

        if (get_debug() || get_trace())
        {
            m_logger->add_console("[%^%l%$] %v", level);
            if (!get_log_file_path().empty()) m_logger->add_basic_file(get_log_file_path());
            m_logger->set_log_level(level);
            m_logger->set_debug_level(10);
            m_logger->set_flush_log_level(level);

            if (get_trace())
            {
                m_trace = std::make_shared<esys::log::Trace>();
                m_trace->set_logger(m_logger);

                m_trace_logger = std::make_shared<esys::trace::Logger>();
                m_trace_logger->set_log_if(m_trace);
                esys::trace::Call::set_default_logger(m_trace_logger.get());
                esys::trace::Call::enable();
            }
        }
        else
        {
            m_logger->add_console("[%^%l%$] %v", esys::log::Level::INFO);
            if (!get_log_file_path().empty())
                m_logger->add_basic_file(get_log_file_path(), false, esys::log::Level::INFO);
            m_logger->set_log_level(esys::log::Level::INFO);
            m_logger->set_flush_log_level(esys::log::Level::INFO);
        }
    }
    else
    {
        if (get_trace()) create_esystrace_log();
    }
}

void ESysBaseExe::create_log()
{
    if (get_no_esyslog())
    {
        if (get_trace()) create_esystrace_log();
        return;
    }
    create_esyslog_log();
}

void ESysBaseExe::set_log_file_path(const std::string &log_file_path)
{
    m_log_file_path = log_file_path;
}

const std::string &ESysBaseExe::get_log_file_path()
{
    if (m_log_file_path.empty()) m_log_file_path = "log.txt";
    return m_log_file_path;
}

void ESysBaseExe::print_help(std::ostream &os)
{
    std::ostringstream oss;

    if (m_desc == nullptr) return;
    oss << *m_desc;

    os << oss.str();
}
