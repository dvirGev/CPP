#include "Matrix.hpp"
namespace zich
{

    Matrix::Matrix(const vector<double> &dataTemp, const int rowTemp, const int colTemp)
    {
        if (rowTemp <= 0 || colTemp <= 0)
        {
            throw runtime_error("The size must be positive");
        }
        if ((size_t)dataTemp.size() != rowTemp * colTemp)
        {
            throw runtime_error("The size of the vector does not match the size of the matrix");
        }

        this->data = dataTemp;
        row = (size_t)rowTemp;
        col = (size_t)colTemp;
    }
    /**
     * @brief make a new vector and update him in the new value
     *
     * @param b
     * @return Matrix
     */
    Matrix Matrix::operator+(Matrix const &b)
    {
        if (this->row != b.row || this->col != b.col)
        {
            throw runtime_error("The matrices should be the same size");
        }
        size_t length = (row * col);
        vector<double> dataTemp;
        dataTemp.resize(length);
        for (size_t i = 0; i < length; i++)
        {
            dataTemp[i] = this->data[i] + b.data[i];
        }
        return Matrix(dataTemp, row, col); // return a new matrix with the right data
    }
    /**
     * @brief add 1 to all numbers in the data vector
     *
     * @return Matrix&
     */
    Matrix &Matrix::operator++()
    {
        for (size_t i = 0; i < row; i++)
        {
            for (size_t j = 0; j < col; j++)
            {
                data[(i * col + j)] += 1;
            }
        }
        return *this;
    }
    Matrix Matrix::operator++(const int flag)
    {
        Matrix copy = *this;
        this->operator++();
        return copy;
    }
    Matrix &Matrix::operator+=(const Matrix &b)
    {
        isTheMatrixTheSameSize(b);
        *this = (*this) + b;
        return *this;
    }
    /**
     * @brief make a new vector and update him in the new value
     *
     * @param b
     * @return Matrix
     */
    Matrix Matrix::operator-(const Matrix &b)
    {
        if (this->row != b.row || this->col != b.col)
        {
            throw runtime_error("The matrices should be the same size");
        }
        size_t length = (row * col);
        vector<double> dataTemp;
        dataTemp.resize(length);
        for (size_t i = 0; i < length; i++)
        {
            dataTemp[i] = this->data[i] - b.data[i];
        }
        return Matrix(dataTemp, row, col);
    }
    /**
     * @brief Subtract 1 from all the number in the vector data
     *
     * @return Matrix&
     */
    Matrix &Matrix::operator--()
    {
        for (size_t i = 0; i < row; i++)
        {
            for (size_t j = 0; j < col; j++)
            {
                data[(i * col + j)] -= 1;
            }
        }
        return *this;
    }
    Matrix Matrix::operator--(const int flag)
    {
        Matrix copy = *this;
        this->operator--();
        return copy;
    }
    Matrix &Matrix::operator-=(const Matrix &b)
    {
        if (this->row != b.row || this->col != b.col)
        {
            throw runtime_error("The matrices should be the same size");
        }
        *this = (*this) - b;
        return *this;
    }
    /**
     * @brief do row * col multiplication and retrun the sum
     *
     * @param thisRow
     * @param b
     * @param thisCol
     * @return double
     */
    double Matrix::multiplication(const size_t thisRow, const Matrix &b, const size_t thisCol)
    {
        double sum = 0;
        for (size_t i = 0; i < this->col; i++)
        {
            sum += this->data[(this->col * thisRow + i)] * b.data[(b.col * i + thisCol)];
        }
        return sum;
    }
    /**
     * @brief Duplicate Matrix this with matrix b
     *
     * @param b
     * @return Matrix
     */
    Matrix Matrix::operator*(const Matrix &b)
    {
        if (this->col != b.row)
        {
            throw runtime_error("The sizes of the matrices do not match");
        }
        vector<double> n;
        n.resize(row * b.col);
        Matrix newMatrix(n, row, b.col);
        for (size_t i = 0; i < newMatrix.row; i++)
        {
            for (size_t j = 0; j < newMatrix.col; j++)
            {
                newMatrix.data[(i * newMatrix.col + j)] = multiplication(i, b, j); // use the multiplication function to calculate the new matrix
            }
        }
        return newMatrix;
    }
    /**
     * @brief Duplicate Matrix this with scalar a
     *
     * @param a
     * @return Matrix
     */
    Matrix Matrix::operator*(const double a)
    {
        Matrix newMatrix = *this;
        for (size_t i = 0; i < row; i++)
        {
            for (size_t j = 0; j < col; j++)
            {
                // the if is to prevent -0 case ¯\_(ツ)_/¯
                if (newMatrix.data[(col)*i + j] != 0)
                {
                    newMatrix.data[(col)*i + j] *= a;
                }
            }
        }
        return newMatrix;
    }
    Matrix &Matrix::operator*=(const Matrix &b)
    {
        *this = (*this * b);
        return *this;
    }
    Matrix &Matrix::operator*=(const double a)
    {
        *this = (*this * a);
        return *this;
    }
    /**
     * @brief sum the vector data and retrun the sum
     *
     * @return double
     */
    double Matrix::sumMat() const
    {
        double sum = 0;
        for (size_t i = 0; i < this->row; i++)
        {
            for (size_t j = 0; j < this->col; j++)
            {
                sum += data[(i * (this->col) + j)];
            }
        }
        return sum;
    }

    bool Matrix::operator>(const Matrix &b)
    {
        isTheMatrixTheSameSize(b);
        return (*this).sumMat() > b.sumMat();
    }
    bool Matrix::operator<(const Matrix &b)
    {
        isTheMatrixTheSameSize(b);
        return (*this).sumMat() < b.sumMat();
    }
    bool Matrix::operator!=(const Matrix &b)
    {
        isTheMatrixTheSameSize(b);
        size_t size = (row * col);
        for (size_t i = 0; i < size; i++)
        {
            if (this->data[i] != b.data[i])
            {
                return true;
            }
        }
        return false;
    }
    bool Matrix::operator==(const Matrix &b)
    {
        isTheMatrixTheSameSize(b);
        return !((*this) != b);
    }
    bool Matrix::operator>=(const Matrix &b)
    {
        isTheMatrixTheSameSize(b);
        return (*this).sumMat() >= b.sumMat();
    }
    bool Matrix::operator<=(const Matrix &b)
    {
        isTheMatrixTheSameSize(b);
        return (*this).sumMat() <= b.sumMat();
    }
    void Matrix::isTheMatrixTheSameSize(const Matrix &b) const
    {
        if (this->row != b.row || this->col != b.col)
        {
            throw runtime_error("The matrices should be the same size");
        }
    }
    ostream &operator<<(ostream &os, const Matrix &a)
    {
        size_t index = 0;
        for (size_t i = 0; i < a.row - 1; i++)
        {
            os << '[';
            for (size_t j = 0; j < a.col - 1; j++)
            {
                os << a.data[index++] << " ";
            }
            os << a.data[index++] << "]" << endl;
        }
        os << '[';
        for (size_t j = 0; j < a.col - 1; j++)
        {
            os << a.data[index++] << " ";
        }
        os << a.data[index++] << "]";
        return os;
    }
    istream &operator>>(istream &os, Matrix &mat)
    {
        vector<string> newData = splitString(istreamToString(os), ',');

        size_t rowLength = newData.size();
        size_t colLength = splitString(newData[0], ' ').size();

        vector<double> newMat;
        newMat.resize(rowLength * colLength);
        size_t index = 0;
        for (size_t i = 0; i < newData.size(); i++)
        {
            if (i > 0)
            {
                if (newData[i].at(0) != ' ')
            {
                throw runtime_error("student 2 is Stupid");
            }
                newData[i].erase(0, 1);
            }

            vector<string> newRow = splitString(newData[i], ' ');

            if (newRow.size() != colLength)
            {
                throw runtime_error("all rows must be in the same size");
            }
            if (newRow[0].at(0) != '[' || newRow[newRow.size() - 1].at(1) != ']')
            {
                throw runtime_error("all rows must start with [ and ends with ]");
            }

            newRow[0].erase(0, 1);
            newMat[index++] = stod(newRow[0]);
            size_t j = 1;
            for (; j < newRow.size() - 1; j++)
            {
                newMat[index++] = stod(newRow[j]);
            }
            string &lastRow = newRow[j];
            lastRow.pop_back();
            newMat[index++] = stod(lastRow);
        }
        mat = Matrix(newMat, rowLength, colLength);
        return os;
    }
    Matrix operator*(const double a, Matrix &b)
    {
        return b * a;
    }
    Matrix operator-(Matrix &a)
    {
        return a * -1;
    }
    Matrix operator+(Matrix &a)
    {
        return a;
    }
    bool operator==(const Matrix &a, const Matrix &b)
    {
        if (a.row != b.row || a.col != b.col)
        {
            throw invalid_argument("row and cols must be equals");
        }
        for (size_t i = 0; i < a.row; i++)
        {
            for (size_t j = 0; j < a.col; j++)
            {
                if (a.data[(i * a.col + j)] != b.data[(i * a.col + j)])
                {
                    return false;
                }
            }
        }
        return true;
    }
    /**
     * @brief like string.split in java
     *
     * @param str
     * @param c
     * @return vector<string>
     */
    vector<string> splitString(const string &str, const char c)
    {
        vector<string> res;
        res.resize(str.size()); // max size of res;

        size_t realSize = 0; // the real size of res;
        for (size_t i = 0; i < str.size(); i++)
        {
            if (str.at(i) == c)
            {
                ++realSize;
            }
            else
            {
                res[realSize] += str.at(i);
            }
        }

        ++realSize;
        res.resize(realSize);
        return res;
    }
    string istreamToString(istream &os)
    {
        char ch = 0;
        string s;
        while (ch != '\n')
        {
            ch = os.get();
            s += ch;
        }
        s.pop_back();
        return s;
    }
}
//[ 2.5 0 0 ], [ 0 2.5 0 ], [ 0 0 -2.5 ]