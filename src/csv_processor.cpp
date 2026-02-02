#include "csv_processor.hpp"
#include "calculator.hpp" 

using namespace amrapp;

CSVProcessor::CSVProcessor (argsOption options)
    :m_options(options)
{
}

int CSVProcessor::run (){
    Calculator calc{m_options.fileName}; 
    if (m_options.allFlag){
        m_options.repeatedABFlag = true;
        m_options.repeatedBAFlag = true;
        m_options.complementABFlag =true; 
        m_options.complementBAFlag =true; 
        m_options.tableFlag =true; 
    }
    if (m_options.repeatedABFlag){
       calc.repeatedAB(); 
    }
    if (m_options.repeatedBAFlag){
       calc.repeatedBA(); 
    }
    if (m_options.complementABFlag){
       calc.complementAB(); 
    }
    if (m_options.complementBAFlag){
       calc.complementBA(); 
    }
    if (m_options.tableFlag){
        calc.drawTable();
    }
    return 0; 
}