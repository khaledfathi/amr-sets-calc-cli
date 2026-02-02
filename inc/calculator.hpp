#if !defined(CALCULATOR_HPP)
#define CALCULATOR_HPP

#include <string>
#include <format>
#include "rapidcsv.h"


namespace amrapp
{
    using tableType = std::map<std::string, std::vector<std::string>>;
    class Calculator 
    {
    private:
        // table format
        std::string  m_lines = std::format("+{:-<10}+{:-<10}+", "", "") ;
        std::string  m_tableHeader = std::format("|{:^10}|{:^10}|", "Col A", "Col B");
        // 
        std::string m_file{""};
        rapidcsv::Document m_doc{""};
        tableType m_table{{"col_a" ,{}} , {"col_b",{}}};
        int m_colCount=0; 
        bool hasTwoColumn();
        void readTable();
    public:
        Calculator(std::string file);
        void repeatedAB();
        void repeatedBA();
        void complementAB();
        void complementBA();
        void drawTable();
    };
}

#endif // CALCULATOR_HPP
