/*!
 * \file esysbaseexe/esysbaseexe.h
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

#pragma once

#include <esys/base/stdcpp/logger.h>

#include <boost/program_options/variables_map.hpp>
#include <boost/program_options/options_description.hpp>

#include <string>
#include <ostream>

namespace po = boost::program_options;

class ESysBaseExe
{
public:
    ESysBaseExe();
    ~ESysBaseExe();

    void set_args(int argc, char **argv);
    int parse_args();
    int run();

    bool get_debug();

    void set_os(std::ostream &os);
    std::ostream *get_os();

    int cmd_list_plugings();

    void print_help(std::ostream &os);

    void set_error_msg(const std::string &error_msg);
    const std::string &get_error_msg();

private:
    std::shared_ptr<esys::base::stdcpp::Logger> m_logger; 
    std::ostream *m_os = nullptr;
    int m_argc = 0;
    char **m_argv = nullptr;
    std::vector<std::string> m_args;
    po::variables_map m_vm;
    po::options_description *m_desc = nullptr;
    std::vector<std::string> m_to_parse_further;
    bool m_parse_error = false;
    std::string m_error_msg;
};
