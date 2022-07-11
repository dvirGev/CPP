#include "mat.hpp"
#include <iostream>
#include <stdexcept>
#include <bits/stdc++.h>
using namespace std;

constexpr int maxCol = 100;
constexpr char minChar = 33;
constexpr char maxChar = 126;

/** make a zigzag string from c1 and c2 
 * for exmpale 5, @, - -> "@-@-@" */
string zigzag(int len, char c1, char c2)
{
    if (len < 0)
    {
        throw runtime_error("length must be positive");
    }
    string res;
    for (int i = 0; i < len; i++)
    {
        if (i % 2 == 0)
        {
            res += c1;
        }
        else
        {
            res += c2;
        }
    }
    return res;
}
/** make one line of Mat
 * start with a zigzag test
 * add middle
 * end with reverse zigzag */  
string oneLineOfMat(int i, int len, char c1, char c2)
{
    string res;
    int zigLen = min(i-1, len / 2);
    string zig = zigzag(zigLen, c1, c2);
    res += zig;
    if (zigLen % 2 == 0)
    {
        for (int j = 0; j < len - 2 * zigLen; j++)
        {
            res += c1;
        }
    }
    else
    {
        for (int j = 0; j < len - 2 * zigLen; j++)
        {
            res += c2;
        }
    }
    reverse(zig.begin(), zig.end());
    res += zig + '\n';
    return res;
}
namespace ariel
{
    /** Assistant to the factory manager to design his rugs
     * The function takes on size and symbols and creates a matrix by layers with the function oneLineOfMat
     * For example: 9, 7, '@', '-' ->
       @@@@@@@@@
       @-------@
       @-@@@@@-@
       @-@---@-@
       @-@@@@@-@
       @-------@
       @@@@@@@@@ */
    string mat(int col, int row, char c1, char c2)
    {
        if (col <= 0 || row <= 0)
        {
            throw runtime_error("Mat size is always positive");
        }
        if (col % 2 == 0 || row % 2 == 0)
        {
            throw runtime_error("Mat size is always odd");
        }
        if (col > maxCol)
        {
            throw runtime_error("The col is too much");
        }
        if (!(c1 >= minChar && c1 <= maxChar))
        {
            throw runtime_error("Invalid icon");
        }
        if (!(c2 >= minChar && c2 <= maxChar))
        {
            throw runtime_error("Invalid icon");
        }
        // Implementation of the function

        string res;
        // First half
        for (int i = 1; i <= (row) / 2 + 1; i++)
        {
            res += oneLineOfMat(i, col, c1, c2);
        }
        //Second half
        for (int i = (row) / 2; i >= 1; i--)
        {
            res += oneLineOfMat(i, col, c1, c2);
        }
        return res;
    }
}