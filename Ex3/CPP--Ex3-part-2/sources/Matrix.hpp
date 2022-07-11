#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;
namespace zich
{
    class Matrix
    {
    private:
        vector<double> data;
        size_t row;
        size_t col;
        double multiplication(const size_t thisRow, const Matrix &b, const size_t thisCol);
        double sumMat() const;

    public:
        Matrix(const vector<double> &dataTemp, const int rowTemp, const int colTemp);
        Matrix operator+(const Matrix &b);
        Matrix &operator++();
        Matrix operator++(const int flag);
        Matrix &operator+=(const Matrix &b);

        Matrix operator-(const Matrix &b);
        Matrix &operator--();
        Matrix operator--(const int flag);
        Matrix &operator-=(const Matrix &b);

        Matrix operator*(const Matrix &b);
        Matrix operator*(const double a);
        Matrix &operator*=(const Matrix &b);
        Matrix &operator*=(const double a);

        bool operator>(const Matrix &b);
        bool operator<(const Matrix &b);
        bool operator!=(const Matrix &b);
        bool operator==(const Matrix &b);
        bool operator>=(const Matrix &b);
        bool operator<=(const Matrix &b);

        void isTheMatrixTheSameSize(const Matrix &b) const;

        friend ostream &operator<<(ostream &os, const Matrix &a);
        friend istream &operator>>(istream &os, Matrix &mat);
        friend Matrix operator*(const double a, Matrix &b);
        friend Matrix operator-(Matrix &a);
        friend Matrix operator+(Matrix &a);
        friend bool operator==(const Matrix &a, const Matrix &b);
    };
    vector<string> splitString(const string &str, const char c);
    string istreamToString(istream &os);
};
