#include <iostream>
#include <vector>
#include <stdexcept>

class Matrix
{
private:
    std::vector<std::vector<double>> mat;
    int row;
    int column;

public:
    Matrix(int row = 0, int column = 0) : row(row), column(column)
    {

        // 隐式处理异常
        if (this->row < 0 || this->column < 0)
        {
            this->row = 0;
            this->column = 0;
        }

        mat = std::vector<std::vector<double>>(this->row, std::vector<double>(this->column));
    }

    friend std::istream &operator>>(std::istream &is, Matrix &m);

    friend std::ostream &operator<<(std::ostream &e, const Matrix &m);

    Matrix &operator=(const Matrix &other)
    {
        std::cout << "Assignment Operator Called" << std::endl;
        if (this != &other)
        {
            this->row = other.row;
            this->column = other.column;
            mat = other.mat;
        }

        return *this;
    }
};

std::istream &operator>>(std::istream &is, Matrix &m)
{
    std::cout << "input row and column(e.g. 2 2): ";

    if (!(is >> m.row >> m.column))
    {
        throw std::invalid_argument("error: row or column format!");
    }

    m.mat.resize(m.row);
    for (int i = 0; i < m.row; ++i)
    {
        m.mat[i].resize(m.column);
    }

    std::cout << "input " << m.row * m.column
              << " element(s) (use "
                 " to devide)"
              << std::endl;
    for (int i = 0; i < m.row; ++i)
    {
        for (int j = 0; j < m.column; ++j)
        {
            if (!(is >> m.mat[i][j]))
            {
                throw std::invalid_argument("invalid input!");
            }
        }
    }

    return is;
}

std::ostream &operator<<(std::ostream &e, const Matrix &m)
{
    if (m.row <= 0 || m.column <= 0)
    {
        e << "{0}";
        return e;
    }

    for (int i = 0; i < m.row; i++)
    {
        e << "{";
        for (int j = 0; j < m.column; j++)
        {
            e << m.mat[i][j];
            if (j != m.column - 1)
            {
                e << ",";
            }
        }
        e << "}";
        e << "\n";
    }

    return e;
}

int main()
{
    Matrix mat;

    try
    {
        std::cin >> mat;
        std::cout << "found successfully! the matrix:\n"
                  << mat << std::endl;
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "\n input error: " << e.what() << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    std::cout << "\nProgram continues running. Enter any character to exit:";
    char end;
    std::cin >> end;

    return 0;
}