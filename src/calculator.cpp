#include "calculator.hpp"
#include <vector>
#include <map>

using namespace amrapp;

Calculator::Calculator(std::string file)
    : m_file(file)
{
    m_doc = rapidcsv::Document{m_file, rapidcsv::LabelParams(-1, -1)};
    m_colCount = m_doc.GetColumnCount();
    if (!hasTwoColumn())
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
std::map<std::string, int> Calculator::compareColumns(const std::vector<std::string> &col1, const std::vector<std::string> &col2)
{
    std::map<std::string, int> repeatedList;
    for (auto cellA : col1)
    {
        repeatedList[cellA] = 0;
        for (auto cellB : col2)
            if (cellA == cellB)
                repeatedList[cellA]++;
    }
    return repeatedList;
}

std::vector<std::string> Calculator::complementColumns(const std::vector<std::string> &col1, const std::vector<std::string> &col2)
{
    std::vector<std::string> complementList{};
    for (auto cellA : col1)
    {
        bool found{false};
        for (auto cellB : col2)
        {
            if (cellA == cellB)
            {
                found = true;
                break;
            }
        }
        if (!found && !cellA.empty())
            complementList.push_back(cellA);
    }
    return complementList;
}
void Calculator::printMap(const std::string &title, const std::map<std::string, int> &map)
{
    std::cout << title << std::endl;
    for (auto item : map)
    {
        if (item.second != 0)
            std::cout << "[ " << item.first << " -> " << item.second << " ]" << std::endl;
    }
}
void Calculator::printVector(const std::string &title, const std::vector<std::string> &vector)
{
    std::cout << title << std::endl;
    std::cout << "[ ";
    int size = vector.size();
    for (int i = 0; i < size; i++)
        std::cout << vector[i] << (i + 1 < size ? " , " : "");
    std::cout << " ]" << std::endl;
}
bool Calculator::hasTwoColumn()
{
    auto colCount = m_doc.GetColumnCount();
    return colCount == 2 ? true : false;
}
void Calculator::repeatedAB()
{
    auto compared = compareColumns(m_table["col_a"], m_table["col_b"]);
    printMap("Repated A -> B : ", compared );
}
void Calculator::repeatedBA()
{
    auto compared  = compareColumns(m_table["col_b"], m_table["col_a"]);
    printMap("Repated B -> A : ", compared);
}
void Calculator::complementAB()
{
    auto complement = complementColumns(m_table["col_a"], m_table["col_b"]);
    printVector("Complement A -> B : ", complement);
}
void Calculator::complementBA()
{
    auto complement = complementColumns(m_table["col_b"], m_table["col_a"]);
    printVector("Complement B -> A : ", complement);
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