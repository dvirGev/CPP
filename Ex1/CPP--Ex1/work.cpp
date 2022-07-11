#include "mat.hpp"

#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
    int col, row;
    char c1, c2;
    cout<<"enter the number of col: ";
    cin>>col;
    cout<<"enter the number of row: ";
    cin>>row;
    cout<<"enter the c1: ";
    cin>>c1;
    cout<<"enter the c1: ";
    cin>>c2;
	cout << endl << ariel::mat(col, row, c1, c2) << endl;
}