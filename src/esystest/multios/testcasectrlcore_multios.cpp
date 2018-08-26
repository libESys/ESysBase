/*!
 * \file esystest/multios/testcasectrlcore_multios.cpp
 * \brief
 *
 * \cond
 * __legal_b__
 *
 * Copyright (c) 2015-2018 Michel Gillet
 * Distributed under the wxWindows Library Licence, Version 3.1.
 * (See accompanying file LICENSE_3_1.txt or
 * copy at http://www.wxwidgets.org/about/licence)
 *
 * __legal_e__
 * \endcond
 *
 */

#include "esystest/esystest_prec.h"
#include "esystest/multios/testcasectrlcore.h"
#include "esystest/testcaseinfo.h"
#include "esystest/mastertestsuite.h"
#include "esystest/exception.h"
#include "esystest/assert.h"

#include <esys/vld.h>

#include <boost/locale.hpp>
#include <boost/filesystem.hpp>
#include <boost/program_options/cmdline.hpp>
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/version.hpp>

#include <cstdlib>
#include <string.h>
#include <iostream>

namespace esystest
{

namespace multios
{

TestCaseCtrlCore::TestCaseCtrlCore()
    : TestCaseCtrlBase(), m_desc("ESysTest options"), m_is_parsed(false)
    , m_verbose(-1), m_log_trace(false)
{
}

TestCaseCtrlCore::~TestCaseCtrlCore()
{
}

int32_t TestCaseCtrlCore::Init()
{
    int32_t result;

    AddDefaultOptions();

    AddOptions(m_desc);

    result = Parse();
    if (result < 0)
        return result;

    result = 0;
    if (DoFindFolders() == true)
        result = FindFolders();
    return result;
}

void TestCaseCtrlCore::BeforeTest()
{

}

void TestCaseCtrlCore::AfterTest()
{
}

void TestCaseCtrlCore::Invoke(TestCaseInfo *cur_test)
{
    bool succeeded = true;
    bool run_test = true;
    Exception::ID excep_id = Exception::UNKNOWN;

    assert(cur_test != nullptr);

    if (GetRunAll() == false)
    {
        if (strcmp(GetTestToRun(), cur_test->GetName()) != 0)
            run_test = false;
    }

    if (run_test == true)
    {
        try
        {
            cur_test->Invoke();
        }

        catch (const Exception &e)
        {
            succeeded = false;
            excep_id = e.GetId();
        }
        if (succeeded == false)
            cur_test->SetResult(-excep_id);
        else
            cur_test->SetResult(0);
    }
    else
        cur_test->SetResult(0);
}

void TestCaseCtrlCore::Assert()
{
    throw Exception(Exception::TEST_FAILED);
}

void TestCaseCtrlCore::AddOptions(po::options_description &desc)
{
}

int TestCaseCtrlCore::HandleActions()
{
    return 1;
}

int TestCaseCtrlCore::HandleSwitches()
{
    return 0;
}

int TestCaseCtrlCore::Parse()
{
    int result = 0;

    po::store(po::parse_command_line(MasterTestSuite::Get().GetArgC(), MasterTestSuite::Get().GetArgV(), m_desc), m_vm);
    po::notify(m_vm);

    m_is_parsed = true;

    result = HandleSwitches();
    if (result < 0)
        return -1;
    result = HandleActions();
    if (result <= 0)
        return result;

    if (m_vm.count("help"))
    {
        std::cout << m_desc << "\n";
        return -1;
    }
    else
    {
        if (m_vm.count("run_test"))
        {
            RunOneTest((char *)m_run_test.c_str());
        }
        else if (m_vm.count("list"))
        {
            PrintList();
            result = -1;
        }
    }
    return result;
}

bool TestCaseCtrlCore::IsParsed()
{
    return m_is_parsed;
}

bool TestCaseCtrlCore::DoFindFolders()
{
    if (m_search_paths.size() != 0)
        return true;
    if (m_search_path_env_vars.size() != 0)
        return true;
    return false;
}

int32_t TestCaseCtrlCore::FindFolders()
{
    int32_t result;

    // First check all given environment variables as path root
    result = FindFoldersEnvVarAsRoot();
    if (result == 0)
        return 0;
    result = FindFoldersCWDAsRoot();
    if (result == 0)
        return 0;
    return -1;
}

int32_t TestCaseCtrlCore::SearchRelativePathFromRoot(const boost::filesystem::path &root_path)
{
    std::vector<std::wstring>::iterator search_path_it;
    std::wstring wenv_var;
    std::string env_var;
    std::wstring wenv_var_value;
    //char *value;
    boost::filesystem::path full_path;

    LoadEnvVar();

    // Try all relative search paths using the environment variable value as root path
    for (search_path_it = m_search_paths.begin(); search_path_it != m_search_paths.end(); ++search_path_it)
    {
        full_path = *search_path_it;
        // If the search path is absolute, it can't be used as a relative path
        if (full_path.is_absolute())
            continue;
        // Build the full path using the enviroment variable value as root path
        full_path = root_path;
        // Append the relative search path
        full_path /= *search_path_it;

        // If the folder exists, we found the test files folder
        if (boost::filesystem::exists(full_path) == true)
        {
            // Since the path exists, it is assumed to be the correct one
            SetTestFilesFolder(full_path.wstring());
            return 0;
        }
    }
    return -1;
}

int32_t TestCaseCtrlCore::FindFoldersCWDAsRoot()
{
    std::vector<std::wstring>::iterator it;
    boost::filesystem::path test_path;
    //int result;

    for (it = m_search_paths.begin(); it != m_search_paths.end(); ++it)
    {
        test_path = *it;
        if (test_path.is_absolute() == true)
            continue;
        if (boost::filesystem::exists(test_path))
        {
            SetTestFilesFolder(test_path.wstring());
            return 0;
        }
    }
    return -1;
}

int32_t TestCaseCtrlCore::FindFoldersEnvVarAsRoot()
{
    std::vector<std::wstring>::iterator env_var_it;
    std::vector<std::wstring>::iterator search_path_it;
    boost::filesystem::path test_path;
    boost::filesystem::path full_path;
    std::wstring wenv_var_value;
    std::wstring search_path;
    int result;

    // Make sure all enviroment variables were loaded
    LoadEnvVar();

    for (env_var_it = m_vec_env_vars.begin(); env_var_it != m_vec_env_vars.end(); ++env_var_it)
    {
        wenv_var_value = *env_var_it;
        test_path = wenv_var_value;

        result = SearchRelativePathFromRoot(test_path);
        if (result == 0)
            return result;
    }
    return -1;
}

void TestCaseCtrlCore::AddSearchPath(const std::wstring &search_path)
{
    m_search_paths.push_back(search_path);
}

void TestCaseCtrlCore::AddSearchPathEnvVar(const std::wstring &env_var)
{
    m_search_path_env_vars.push_back(env_var);
}

void TestCaseCtrlCore::LoadEnvVar()
{
    if (m_vec_env_vars.size() == m_search_path_env_vars.size())
        return;

    std::vector<std::wstring>::iterator it;
    std::wstring wenv_var;
    std::string env_var;
    char *value;
    std::wstring wenv_value;

    for (it = m_search_path_env_vars.begin(); it != m_search_path_env_vars.end(); ++it)
    {
        wenv_var = *it;
        env_var = boost::locale::conv::utf_to_utf<char>(wenv_var);
        value = std::getenv(env_var.c_str());
        if (value == nullptr)
            continue;
        wenv_value = boost::locale::conv::utf_to_utf<wchar_t>(value);
        m_map_env_vars[wenv_var] = wenv_value;
        m_vec_env_vars.push_back(wenv_value);
    }
}

void TestCaseCtrlCore::AddDefaultOptions()
{
    m_desc.add_options()
    ("help", "produce help message")
    ("help-all", "produce help message")
    ("run_test", po::value<std::string>(&m_run_test), "give the name of the test to run")
    ("list", "list all unit tests")

#ifdef ESYS_USE_VLD
    ("vld-off", "turn off vld")
#endif

    ("log_trace", po::value<std::string>(&m_log_trace_path)->implicit_value(""), "log calling traces")
    ("verbose,v", po::value<int>()->default_value(0), "set verbosity level: 0 is off")
    ("test_file_path", po::value<std::string>(&m_test_file_path_s)->default_value(m_dft_test_file_path), "set the path for test files");
}

void TestCaseCtrlCore::SetArgs(int argc, char **argv)
{
    m_argc = argc;
    m_argv = argv;
}

void TestCaseCtrlCore::SetArgs(int argc, wchar_t **argv)
{
    m_argc = argc;
    m_wargv = argv;
}

void TestCaseCtrlCore::SetTestFilesFolder(const std::string &test_files_folder)
{
    m_test_files_folder = boost::locale::conv::utf_to_utf<wchar_t>(test_files_folder);
}

void TestCaseCtrlCore::SetTestFilesFolder(const std::wstring &test_files_folder)
{
    m_test_files_folder = test_files_folder;
}

const std::wstring &TestCaseCtrlCore::GetTestFilesFolder()
{
    return m_test_files_folder;
}

}

}

