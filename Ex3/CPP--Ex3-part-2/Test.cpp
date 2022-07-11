#include "doctest.h"
#include "Matrix.hpp"
#include <string>
#include <stdexcept>
#include <iostream>
using namespace std;
using namespace zich;
vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};                    // identity matrix 3*3
vector<double> zero16 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // zero matrix 4*4
TEST_CASE("Good input")
{
    vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1}; // identity matrix 3*3
    Matrix I(identity, 3, 3);
    Matrix I3(identity, 3, 3);
    I3 *= 3;
    Matrix I4(identity, 3, 3);
    I4 *= 4;
    Matrix all1({1, 1, 1, 1, 1, 1, 1, 1, 1}, 3, 3);
    SUBCASE("== != Tests")
    {
        CHECK(((I + I3) == I4) == true);
        CHECK(((I4 - I) == I3) == true);
        CHECK(((I4 - I3) == I) == true);
        CHECK((all1 == I3) == false); // the sum is equal, yet the matrix are not

        CHECK(((I + I3) != I4) == false);
        CHECK(((I4 - I) != I3) == false);
        CHECK(((I4 - I3) != I) == false);
        CHECK((all1 != I3) == true); // the sum is equal, yet the matrix are not
    }
    SUBCASE("< <= Tests")
    {
        CHECK((I < I3) == true);
        CHECK((I3 < I4) == true);
        CHECK((I <= I3) == true);
        CHECK((I3 <= I4) == true);
        CHECK((I <= I) == true);
        CHECK((I3 <= all1) == true);
    }
    SUBCASE("> >= Tests")
    {
        CHECK((I4 > I3) == true);
        CHECK((I3 > I) == true);
        CHECK((I4 >= I3) == true);
        CHECK((I3 >= I) == true);
        CHECK((I >= I) == true);
        CHECK((I3 >= all1) == true);
    }
    SUBCASE("++ Tests")
    {
        Matrix tempMat1({2, 1, 1, 1, 2, 1, 1, 1, 2}, 3, 3);
        I++;
        CHECK((tempMat1 == I) == true);
        Matrix tempMat3({4, 1, 1, 1, 4, 1, 1, 1, 4}, 3, 3);
        CHECK((tempMat3 == (++I3)) == true);
    }
    SUBCASE("* Testt")
    {
        CHECK(((I*3)==I3));
        CHECK(((I*4)==I4));
    }
}
TEST_CASE("Bad Input")
{
    SUBCASE("Constructor Test")
    {
        SUBCASE("The size must be positive")
        {
            CHECK_THROWS(Matrix(identity, 0, 3));
            CHECK_THROWS(Matrix(identity, 3, 0));
            CHECK_THROWS(Matrix(identity, -3, 3));
            CHECK_THROWS(Matrix(identity, 3, -3));
        }
        SUBCASE("The size of the vector does not match the size of the matrix")
        {
            SUBCASE("Good Size For Zero16")
            {
                CHECK_NOTHROW(Matrix(zero16, 4, 4));
                CHECK_NOTHROW(Matrix(zero16, 8, 2));
                CHECK_NOTHROW(Matrix(zero16, 2, 8));
                CHECK_NOTHROW(Matrix(zero16, 16, 1));
                CHECK_NOTHROW(Matrix(zero16, 1, 16));
            }
            SUBCASE("Bad Size For Zero16")
            {
                CHECK_THROWS(Matrix(zero16, 4, 8));
                CHECK_THROWS(Matrix(zero16, 8, 1));
                CHECK_THROWS(Matrix(zero16, 1, 8));
                CHECK_THROWS(Matrix(zero16, 8, 8));
            }
        }
    }
    SUBCASE("Operator+ Test")
    {
        Matrix zero44(zero16, 4, 4); // 4*4 matrix
        Matrix zero82(zero16, 8, 2); // 8*2 matrix
        Matrix I33(identity, 3, 3);  // 3*3 matrix
        CHECK_NOTHROW(zero44 + zero44);
        CHECK_THROWS(zero44 + I33);
        CHECK_THROWS(zero82 + zero44);
    }
    SUBCASE("Operator- Test")
    {
        Matrix zero44(zero16, 4, 4); // 4*4 matrix
        Matrix zero82(zero16, 8, 2); // 8*2 matrix
        Matrix I33(identity, 3, 3);  // 3*3 matrix
        CHECK_NOTHROW(zero44 - zero44);
        CHECK_THROWS(zero44 - I33);
        CHECK_THROWS(zero82 - zero44);
    }
    
}