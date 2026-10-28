#include <iostream>
#include <vector>
#include <string>

// TODO 1: 定义自定义异常类 IndexOutOfBoundsException
// 要求：公有继承 std::exception
// 要求：重写 what() 方法，返回 "Index out of range"
class IndexOutOfBoundsException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Index out of range";
    }
};

// ==========================================
// VectorN 类定义
// ==========================================
class VectorN
{
private:
    std::vector<double> data_;
    size_t size_;

public:
    VectorN(size_t n) : size_(n), data_(n, 0.0) {}

    // TODO 2: 实现 operator[] (非const版本)
    // 逻辑：检查 index >= size_，如果是，抛出 TODO 1 定义的异常
    // 否则，返回 data_[index]
    double &operator[](size_t index)
    {
        if (index >= size_)
        {
            throw IndexOutOfBoundsException{};
        }
        return data_[index];
    }
};

// ==========================================
// 主函数
// ==========================================
int main()
{
    VectorN vec(3); // 创建3维向量

    try
    {
        // 这行应该正常
        vec[0] = 1.0;
        std::cout << "vec[0] assigned." << std::endl;

        // 这行应该抛出异常
        vec[5] = 5.0;
        std::cout << "vec[5] assigned." << std::endl;
    }
    // TODO 3: 捕获 TODO 1 定义的异常类型
    // 逻辑：打印 "Caught exception: " << e.what()
    catch (const IndexOutOfBoundsException &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught std::exception: " << e.what() << std::endl;
    }

    return 0;
}