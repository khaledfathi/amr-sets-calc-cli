#include "calculator.hpp"
#include <vector>
#include <map>

using namespace amrapp;

Calculator::Calculator(std::string file)
    : m_file(file)
{
    m_doc = rapidcsv::Document{m_file, rapidcsv::LabelParams(-1, -1)};
    m_colCount = m_doc.GetColumnCount();
    if ( ! hasTwoColumn())
    {
        std::cout << "ERROR : CSV file doesn't meet requirement | file should have exact 2 columns\n";
        exit(EXIT_FAILURE);
    }
    readTable();
}
void Calculator::readTable()
{
    if (hasTwoColumn())
    {
        m_table["col_a"] = m_doc.GetColumn<std::string>(0);
        m_table["col_b"] = m_doc.GetColumn<std::string>(1);
    }
}
bool Calculator::hasTwoColumn()
{
    auto colCount = m_doc.GetColumnCount();
    return colCount == 2 ? true : false;
}
void Calculator::repeatedAB()
{
    std::cout << "Repeated A B \n";
}
void Calculator::repeatedBA()
{
    std::cout << "Repeated B A \n";
}
void Calculator::complementAB()
{
    std::cout << "Complement A B\n";
}
void Calculator::complementBA()
{
    std::cout << "Complement B A\n";
}
void Calculator::drawTable()
{
    // draw table
    std::cout << m_lines << std::endl;
    std::cout << m_tableHeader << std::endl;
    std::cout << m_lines << std::endl;
    //
    std::vector<std::vector<std::string>> rows;
    for (int i = 0; i < m_doc.GetRowCount(); i++)
    {
        rows.push_back(m_doc.GetRow<std::string>(i));
    }
    //
    for (auto row : rows)
    {
        std::cout << std::format("|{:^10}|{:^10}|", row[0], row[1]) << std::endl;
    }
    std::cout << m_lines << std::endl;
}