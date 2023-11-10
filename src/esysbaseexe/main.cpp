/*!
 * \file esysbase/main.cpp
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

#include "esysbaseexe/esysbaseexe_prec.h"
#include "esysbaseexe/esysbaseexe.h"
#include "esysbaseexe/version.h"

#include <iostream>

int main(int argc, char *argv[])
{
    ESysBaseExe esys_exe;

    std::cout << ESYSBASEEXE_VERSION_STRING << std::endl << std::endl;

    esys_exe.set_os(std::cout);
    esys_exe.set_args(argc, argv);
    int result = esys_exe.parse_args();
    if (result < 0)
    {
        esys_exe.print_help(std::cout);
        return -result;
    }

    esys_exe.create_log();

    // esys::PluginMngrBase::SetAppExe(argv[0]);

    return esys_exe.run();
}
