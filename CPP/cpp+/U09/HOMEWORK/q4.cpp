#include <iostream>
#include <stdexcept>
#include <vector>

class Matrix
{
private:
    std::vector<std::vector<double>> m;
    int row;
    int col;

public:
    Matrix(int row = 0, int col = 0) : row(row), col(col)
    {
        if (this->row < 0 || this->col < 0)
        {
            this->row = 0;
            this->col = 0;
        }
        m.assign(row, std::vector<double>(col, 0.0));
    }

    ~Matrix() = default;

    void input()
    {
        if (row > 0 && col > 0)
        {
            for (int i = 0; i < row; i++)
            {
                std::cout << "Row" << i << " (e.g. 1.0 2.0 3.0): ";
                for (int j = 0; j < col; j++)
                {
                    std::cin >> m[i][j];
                }
            }
        }
    }

    double &operator()(int r, int c)
    {
        if (r < 0 || r > row || c < 0 || c > col)
        {
            throw std::out_of_range{"Matrix index out of range !"};
        }
        return m[r][c];
    }
};

int main()
{
    Matrix mat(2, 2);
    try
    {
        std::cout << mat(0, 0) << '\n';
        std::cout << mat(10, 10) << '\n';
    }
    catch (const std::out_of_range &e)
    {
        std::cout << e.what() << '\n';
    }

    return 0;
}