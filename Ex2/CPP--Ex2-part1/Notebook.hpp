#include <iostream>
#include <string>
#include <stdexcept>
#include "Direction.hpp"

using namespace std;
using namespace ariel;
namespace ariel{
    class Notebook
    {
    // private:
    public:
        // Notebook(/* args */){return}
        // ~Notebook();
        void write(unsigned int page, unsigned int row, unsigned int col, Direction dir, string txt);
        string read(unsigned int page, unsigned int row, unsigned int col, Direction dir, unsigned int length);
        void erase(unsigned int page, unsigned int row, unsigned int col, Direction dir, unsigned int length);
        void show(unsigned int page);
    };
    
    // Notebook::Notebook(/* args */)
    // {
    // }
    
    // Notebook::~Notebook()
    // {
    // }
};