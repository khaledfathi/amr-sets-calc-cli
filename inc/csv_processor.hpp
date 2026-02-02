#if !defined(CSV_PROCESSOR_HPP)
#define CSV_PROCESSOR_HPP

#include "cli_parser.hpp"

namespace amrapp {
    class CSVProcessor {
    private: 
        argsOption m_options;
        bool isNoOptions ();
    public :
        CSVProcessor (argsOption options);
        int run (); 
    };
}

#endif // CSV_PROCESSOR_HPP
