#if !defined(CSV_PROCESSOR_HPP)
#define CSV_PROCESSOR_HPP

#include "cli_parser.hpp"

// using namespace amrapp;

namespace amrapp {
    class CSVProcessor {
    private: 
        argsOption m_options;
    public :
        CSVProcessor (argsOption options);
        int run (); 
    };
}

#endif // CSV_PROCESSOR_HPP
