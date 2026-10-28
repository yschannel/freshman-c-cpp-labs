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
            else
            {
                e << "}";
                e << "\n";
            }
        }
    }

    return e;
}

int main()
{
    std::cout << "---Test 1---" << std::endl;
    Matrix m1(2, 2);
    m1.input();
    Matrix m2(2, 2);
    m2.input();
    Matrix m3 = m1 + m2;
    std::cout << "result:\n"
              << m3 << std::endl;

    std::cout << "---Test 2---" << std::endl;
    Matrix m4(3, 3);
    Matrix m5 = m3 + m4;
}