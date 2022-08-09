/*!
 * \file esysbasesexe/esysbaseexe.cpp
 * \brief
 *
 * \cond
 * __legal_b__
 *
 * Copyright (c) 2018-2022 Michel Gillet
 * Distributed under the wxWindows Library Licence, Version 3.1.
 * (See accompanying file LICENSE_3_1.txt or
 * copy at http://www.wxwidgets.org/about/licence)
 *
 * __legal_e__
 * \endcond
 *
 */

#include "esysbaseexe/esysbaseexe_prec.h"
#include "esysbaseexe/esysbaseexe.h"

#include <esys/base/pluginmngr.h>

#include <boost/program_options/cmdline.hpp>
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/locale.hpp>

#include <iostream>
#include <iomanip>
#include <string>

ESysBaseExe::ESysBaseExe()
{
}

ESysBaseExe::~ESysBaseExe()
{
}

void ESysBaseExe::set_os(std::ostream &os)
{
    m_os = &os;
}

std::ostream *ESysBaseExe::get_os()
{
    return m_os;
}

void ESysBaseExe::set_args(int argc, char **argv)
{
    int i;

    m_args.clear();

    m_argc = argc;

    for (i = 1; i < argc; ++i)
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

bool ESysBaseExe::get_debug()
{
    return m_vm["debug"].as<bool>();
}

int ESysBaseExe::run()
{
    if (m_vm.count("help"))
    {
        if (get_os() != nullptr) print_help(*get_os());
        return 0;
    }
    if (m_vm.count("list_plugins"))
    {
        return cmd_list_plugings();
    }
    return -1;
}

int ESysBaseExe::cmd_list_plugings()
{
    if (get_os() == nullptr) return -17;

    if (m_vm.count("list_plugins") == 0) return -18;

    std::string app_name = m_vm["list_plugins"].as<std::string>();

    esys::base::PluginMngr mngr;
    mngr.set_verbose_level(m_vm["verbose"].as<int>());

    if (!app_name.empty()) mngr.set_name(app_name);

    int result = mngr.load();
    if (result < 0)
    {
        *get_os() << "No plugins found" << std::endl;
        return result;
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
    return 0;
}

void ESysBaseExe::set_error_msg(const std::string &error_msg)
{
    m_error_msg = error_msg;
}

const std::string &ESysBaseExe::get_error_msg()
{
    return m_error_msg;
}

void ESysBaseExe::print_help(std::ostream &os)
{
    std::ostringstream oss;

    if (m_desc == nullptr) return;
    oss << *m_desc;

    os << oss.str();
}
