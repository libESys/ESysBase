/*!
 * \file esystest/multios/testcasectrlcore.h
 * \brief
 *
 * \cond
 *__legal_b__
 *
 * Copyright (c) 2015-2018 Michel Gillet
 * Distributed under the wxWindows Library Licence, Version 3.1.
 * (See accompanying file LICENSE_3_1.txt or
 * copy at http://www.wxwidgets.org/about/licence)
 *
 *__legal_e__
 * \endcond
 *
 */

#pragma once

#include "esystest/esystest_defs.h"
#include "esystest/testcasectrlbase.h"

#include <boost/filesystem/path.hpp>
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/variables_map.hpp>

#include <string>
#include <map>
#include <vector>

namespace po = boost::program_options;

namespace esystest
{

namespace multios
{

class ESYSTEST_API TestCaseCtrlCore: public TestCaseCtrlBase
{
public:
    TestCaseCtrlCore();
    virtual ~TestCaseCtrlCore();

    virtual int Init() override;

    virtual void BeforeTest() override;
    virtual void AfterTest() override;
    virtual void Invoke(TestCaseInfo *cur_test) override;
    virtual void Assert() override;

    virtual void AddOptions(po::options_description &desc);
    virtual int Parse();
    virtual int HandleActions();
    virtual int HandleSwitches();
    bool IsParsed();

    //! Search for the folder containing the test files
    /*
    * The following steps are taken by searching path:
    * - composed of 1 environment variable and a relative search path
    * - composed of current working directory and a relative search path
    * - absolute search path
    * - environment variable as absolute path
    */
    virtual int32_t FindFolders();
    virtual bool DoFindFolders();

    //! Search for test files folder by using environment variable as root folder
    virtual int32_t FindFoldersEnvVarAsRoot();

    //! Search for test files folder by using current working directory as root folder
    virtual int32_t FindFoldersCWDAsRoot();

    void AddSearchPath(const std::wstring &search_path);
    void AddSearchPathEnvVar(const std::wstring &env_var);
    int32_t SearchRelativePathFromRoot(const boost::filesystem::path &root_path);

    void LoadEnvVar();

    void SetArgs(int argc, char **argv);
    void SetArgs(int argc, wchar_t **argv);

    const std::wstring &GetTestFilesFolder();
protected:
    void AddDefaultOptions();
    //! Set the folder where the test files are located
    void SetTestFilesFolder(const std::wstring &test_files_folder);

    //! Set the folder where the test files are located
    void SetTestFilesFolder(const std::string &test_files_folder);

    int m_argc = 0;
    char **m_argv = nullptr;
    wchar_t **m_wargv = nullptr;
    std::map<std::wstring, std::wstring> m_map_env_vars;
    std::vector<std::wstring> m_vec_env_vars;
    std::vector<std::wstring> m_search_paths;
    std::vector<std::wstring> m_search_path_env_vars;
    std::wstring m_test_file_path;
    std::string m_test_file_path_s;
    std::string m_log_trace_path;
    std::wstring m_test_files_folder;
    std::string m_dft_test_file_path;
    boost::filesystem::path m_abs_test_file_path;
    boost::filesystem::path m_abs_temp_path;
    std::string m_run_test;
    po::variables_map m_vm;
    po::options_description m_desc;
    bool m_is_parsed;
    int m_verbose;
    bool m_log_trace;
};

}

#ifdef ESYSTEST_MULTIOS
using namespace multios;
#endif

}




