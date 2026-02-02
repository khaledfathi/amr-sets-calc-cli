#include "csv_processor.hpp"
#include "calculator.hpp"

using namespace amrapp;

CSVProcessor::CSVProcessor(argsOption options)
    : m_options(options)
{
}
bool CSVProcessor::isNoOptions (){
    return 
        ! m_options.allFlag &&
        ! m_options.tableFlag &&
        ! m_options.repeatedABFlag &&
        ! m_options.repeatedBAFlag &&
        ! m_options.complementABFlag && 
        ! m_options.complementBAFlag ;
}
int CSVProcessor::run()
{
    Calculator calc{m_options.fileName};
    if(isNoOptions()){
        calc.drawTable();
        return 0 ;
    }
    if (m_options.allFlag)
    {
        m_options.repeatedABFlag = true;
        m_options.repeatedBAFlag = true;
        m_options.complementABFlag = true;
        m_options.complementBAFlag = true;
        m_options.tableFlag = true;
    }
    if (m_options.repeatedABFlag)
    {
        calc.repeatedAB();
    }
    if (m_options.repeatedBAFlag)
    {
        calc.repeatedBA();
    }
    if (m_options.complementABFlag)
    {
        calc.complementAB();
    }
    if (m_options.complementBAFlag)
    {
        calc.complementBA();
    }
    if (m_options.tableFlag)
    {
        calc.drawTable();
    }
    return 0;
}