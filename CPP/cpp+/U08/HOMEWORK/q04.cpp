#include <iostream>
#include <vector>

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

    void input()
    {
        if (row > 0 && column > 0)
        {
            for (int i = 0; i < row; i++)
            {
                std::cout << "Row" << i << " (e.g. 1.0 2.0 3.0): ";
                for (int j = 0; j < column; j++)
                {
                    std::cin >> mat[i][j];
                }
            }
        }
    }

    bool is_equal(const Matrix &other) const
    {
        if (this->row == other.row && this->column == other.column)
        {
            return true;
        }

        return false;
    }

    Matrix operator+(const Matrix &other) const
    {
        if (!is_equal(other))
        {
            std::cerr << "row or column Not equal!!! output default:{}" << std::endl;
            return Matrix(0, 0);
        }

        Matrix m(this->row, this->column);

        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < this->column; j++)
            {
                m.mat[i][j] = this->mat[i][j] + other.mat[i][j];
            }
        }

        return m;
    }

    friend std::ostream &operator<<(std::ostream &e, const Matrix &m);

    double &operator()(int r, int c) { return mat[r][c]; }      // 读写
    double operator()(int r, int c) const { return mat[r][c]; } // 只读

    Matrix &operator=(const Matrix &other)
    {
        std::cout << "Assignment Operator Called" << std::endl;
        if (this != &other)
        {
            this->row = other.row;
            this->column = other.column;
            mat = other.mat; // vector自动深拷贝
        }

        /*this->row = other.row;
        this->column = other.column;
        mat = std::vector<std::vector<double>>(
            this->row, std::vector<double>(this->column, 0.0));
        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < this->column; j++)
            {
                this->mat[i][j] = other.mat[i][j];
            }
        }
        */

        return *this;
    }
};

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
    Matrix A(2, 2);
    A.input();
    Matrix B(2, 2);
    B = A;
    B(0, 0) = -1;
    std::cout << B << std::endl;
    std::cout << A << std::endl;
    return 0;
}