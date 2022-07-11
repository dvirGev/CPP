#include "Notebook.hpp"
// #include "Direction.hpp"
// #include <iostream>
// #include <string>
// #include <stdexcept>

using namespace std;
namespace ariel
{
    Notebook::Notebook()
    {
    }
    Notebook::~Notebook()
    {
    }
    void Notebook::write(int page, int row, int col, Direction dir, string txt)
    {
        if (col >= rowLenght)
        {
            throw runtime_error("the col must be less than 100");
        }
        if (col + (int)txt.length() > rowLenght && dir == Direction::Horizontal)
        {
            throw runtime_error("the txt out from the raw lenght");
        }
        if(page < 0 || row < 0 || col < 0)
        {
            throw runtime_error("All parameters should be non-negative");
        }
        stack<char> temp;
        if (dir == Direction::Horizontal)
        {
            int j = col;
            for (int i = 0; i < txt.length(); i++)
            {
                if (book[page][row][j] != 0 && book[page][row][j] != '_')
                {

                    for (; !temp.empty(); j--)
                    {
                        book[page][row][j] = temp.top();
                        temp.pop();
                    }
                    throw runtime_error("You are trying to write where you have already written or deleted");
                }
                if (txt.at((unsigned int)i) == '\n' || txt.at((unsigned int)i) == '~' || txt.at((unsigned int)i) < minChar || txt.at((unsigned int)i) > maxChar)
                {

                    for (; !temp.empty(); j--)
                    {
                        book[page][row][j] = temp.top();
                        temp.pop();
                    }
                    throw runtime_error("You are trying to write a invalid Cher");
                }
                book[page][row][j] = txt.at((unsigned int)i);
                temp.push(txt.at((unsigned int)i));
                j++;
            }
        }
        else
        {
            int j = row;
            for (int i = 0; i < txt.length(); i++)
            {
                if (book[page][j][col] != 0 && book[page][j][col] != '_')
                {

                    for (; !temp.empty(); j--)
                    {
                        book[page][j][col] = temp.top();
                        temp.pop();
                    }
                    throw runtime_error("You are trying to write where you have already written or deleted");
                }
                if (txt.at((unsigned int)i) == '\n' || txt.at((unsigned int)i) == '~' || txt.at((unsigned int)i) < minChar || txt.at((unsigned int)i) > maxChar)
                {

                    for (; !temp.empty(); j--)
                    {
                        book[page][j][col] = temp.top();
                        temp.pop();
                    }
                    throw runtime_error("You are trying to write a invalid Cher");
                }
                book[page][j][col] = txt.at((unsigned int)i);
                temp.push(txt.at((unsigned int)i));
                j++;
            }
        }
    }
    string Notebook::read(int page, int row, int col, Direction dir, int length)
    {
        if (col >= rowLenght)
        {
            throw runtime_error("the col must be less than 100");
        }
        if (col + length > rowLenght && dir == Direction::Horizontal)
        {
            throw runtime_error("the txt out from the raw lenght");
        }
        if(page < 0 || row < 0 || col < 0 || length < 0)
        {
            throw runtime_error("All parameters should be non-negative");
        }

        string res;
        if (dir == Direction::Horizontal)
        {
            int j = col;
            for (int i = 0; i < length; i++)
            {
                char c = book[page][row][j];
                if (c == 0)
                {
                    res += '_';
                }
                else
                {
                    res += c;
                }
                j++;
            }
        }
        else
        {
            int j = row;
            for (int i = 0; i < length; i++)
            {
                char c = book[page][j][col];
                if (c == 0)
                {
                    res += '_';
                }
                else
                {
                    res += c;
                }
                j++;
            }
        }
        return res;
    }
    void Notebook::erase(int page, int row, int col, Direction dir, int length)
    {
        if (col >= rowLenght)
        {
            throw runtime_error("the col must be less than 100");
        }
        if (col + length >= rowLenght && dir == Direction::Horizontal)
        {
            throw runtime_error("the txt out from the raw lenght");
        }
        if(page < 0 || row < 0 || col < 0 || length < 0)
        {
            throw runtime_error("All parameters should be non-negative");
        }

        if (dir == Direction::Horizontal)
        {
            int j = col;
            for (int i = 0; i < length; i++)
            {
                book[page][row][j] = '~';
                j++;
            }
        }
        else
        {
            int j = row;
            for (int i = 0; i < length; i++)
            {
                book[page][j][col] = '~';
                j++;
            }
        }
    }
    void Notebook::show(int page)
    {
        if(page < 0)
        {
            throw runtime_error("page should be non-negative");
        }
        if(book.empty())
        {
            cout<<"the notebook is empty"<<endl;
        }
        // This function in comment because of doing neat
        // map<int, char[rowLenght]> ordered(book[page].begin(), book[page].end());
        // for (auto it = ordered.begin(); it != ordered.end(); ++it)
        // {
        //     int keyLenght = (int)log10(it->first);
        //     std::cout << it->first << ": ";
        //     for (int i = 0; i < 3 - keyLenght; i++)
        //     {
        //         cout << ' ';
        //     }

        //     for (int i = 0; i < rowLenght; i++)
        //     {
        //         char c = it->second[i];
        //         if (c == 0 || c == ' ')
        //         {
        //             cout << '_';
        //         }
        //         else
        //         {
        //             cout << c;
        //         }
        //     }
        //     cout << endl;
        // }
    }
}
