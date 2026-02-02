/*
 * amr-sets-calculator-cli 
 *
 * URL:      https://github.com/khaledfathi/amr-sets-calc-cli 
 * Version:  1.0.0
 *
 * Copyright (C) 2026 Khaled Fathi (dev@khaledfathi.com) 
 * all rights reserved.
 *
 * amr-sets-calculator-cli is distributed under the GPL v3, see LICENSE for details.
 *
 */
#include <functional>
#include "cli_parser.hpp"
#include "csv_processor.hpp"

using namespace amrapp ; 

int main(int argc, char **argv)
{
    // Parsers
    CLIParser parser{argc , argv};
    int exitCode = parser.handle();
    if (exitCode >= 0 ) return exitCode;
    // retrieve options
    argsOption options = parser.getOptions();

    // application 
    CSVProcessor csv{options};
    return csv.run();

}