#include <functional>
#include "cli_parser.hpp"
#include "csv_processor.hpp"

using namespace amrapp ; 

int main(int argc, char **argv)
{
    // Parsers
    CLIParser parser{argc , argv};
    int exitCode = parser.handle();
    if (exitCode != 0 ) return exitCode;
    // retrieve options
    auto options = parser.getOptions();

    // application 
    CSVProcessor csv{options};
    return csv.run();

}