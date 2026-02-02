#if !defined(CLI_PARSER_HPP)
#define CLI_PARSER_HPP
#include <string>

namespace amrapp {
    struct argsOption {
        bool repeatedABFlag{false};
        bool repeatedBAFlag{false};
        bool complementABFlag{false};
        bool complementBAFlag{false};
        bool tableFlag{false};
        bool allFlag{false};
        std::string fileName{""};
    };

    class CLIParser {
    private:
        int m_argc;
        char** m_argv;
        argsOption m_optionFlags{};
    public : 
        CLIParser(int argc , char** argv);
        int handle ();
        argsOption getOptions ();
    };
}

#endif // CLI_PARSER_HPP
