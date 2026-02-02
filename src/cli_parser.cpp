#include "cli_parser.hpp"
#include "constants.hpp"
#include "CLI11.hpp"

using namespace amrapp;


CLIParser::CLIParser(int argc, char **argv)
    : m_argc(argc), m_argv(argv)
{
}
int CLIParser::handle()
{

    CLI::App app{"Calculats Sets from CSV file"};
    m_argv = app.ensure_utf8(m_argv);

    app.usage(APP_NAME + " [OPTION...] <FILE>");
    app.positionals_at_end(true);

    std::string filename;
    app.add_option("FILE", m_optionFlags.fileName , "CSV file to process")->required()->check(CLI::ExistingFile);

    app.add_flag("-a,--repeated-a-b", m_optionFlags.repeatedABFlag, "get repeated from column A in column B");
    app.add_flag("-b,--repeated-b-a", m_optionFlags.repeatedBAFlag, "get repeated from column B in column A");
    app.add_flag("-A,--complement-a-b", m_optionFlags.complementABFlag, "get complement from column A in column B");
    app.add_flag("-B,--complement-b-a", m_optionFlags.complementBAFlag, "get complement from column B in column A");
    app.add_flag("-t,--show-table", m_optionFlags.tableFlag, "show the csv table");
    app.add_flag("--all", m_optionFlags.allFlag, "same as -a -b -A -B -t");

    app.set_version_flag("-v,--version", APP_NAME + " Version " + APP_VERSION);

    CLI11_PARSE(app, m_argc, m_argv);
    return 0; 
}

argsOption CLIParser::getOptions (){
    return m_optionFlags; 
}