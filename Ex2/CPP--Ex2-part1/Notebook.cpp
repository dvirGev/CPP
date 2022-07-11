#include "Notebook.hpp"
#include "Direction.hpp"
// #include <iostream>
// #include <string>
// #include <stdexcept>
constexpr unsigned int rowLenght = 100;

using namespace std;
namespace ariel
{
    void Notebook::write(unsigned int page, unsigned int row, unsigned int col, Direction dir, string txt)
    {
        if (col >= rowLenght)
        {
            throw runtime_error("the col must be less than 100");
        }
        else if (col + txt.length() >= rowLenght && dir == Direction::Horizontal)
        {
            throw runtime_error("the txt out from the raw lenght");
        }
        cout << "I am write" << endl;
    }
    string Notebook::read(unsigned int page, unsigned int row, unsigned int col, Direction dir, unsigned int length)
    {
        if(col >= rowLenght)
        {
            throw runtime_error("the col must be less than 100");
        }
        else if(col + length >= rowLenght && dir == Direction::Horizontal)
        {
            throw runtime_error("the txt out from the raw lenght");
        }
        return "I am read";
    }
    void Notebook::erase(unsigned int page, unsigned int row, unsigned int col, Direction dir, unsigned int length)
    {
        if(col >= rowLenght)
        {
            throw runtime_error("the col must be less than 100");
        }
        else if(col + length >= rowLenght && dir == Direction::Horizontal)
        {
            throw runtime_error("the txt out from the raw lenght");
        }
        cout << "I am erase" << endl;
    }
    void Notebook::show(unsigned int page)
    {
        cout << "I am show" << endl;
    }
}
