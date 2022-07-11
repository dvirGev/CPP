#include <iostream>
#include <string>
#include <stdexcept>
#include <unordered_map>
#include <math.h>
#include <map>
#include <stack>
#include "Direction.hpp"
using namespace std;
using namespace ariel;
constexpr int rowLenght = 100;
constexpr char minChar = 32;
constexpr char maxChar = 126;
namespace ariel{
    class Notebook
    {
    private:
        unordered_map<int, unordered_map<int, char[rowLenght]>> book;
    public:
        Notebook(/* args */);
        ~Notebook();
        void write(int page, int row, int col, Direction dir, string txt);
        string read(int page, int row, int col, Direction dir, int length);
        void erase(int page, int row, int col, Direction dir, int length);
        void show(int page);
    };
    
    // Notebook::Notebook(/* args */)
    // {
    // }
    
    // Notebook::~Notebook()
    // {
    // }
};