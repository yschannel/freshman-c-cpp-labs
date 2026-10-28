#include <iostream>
#include <new>

// 派生关系：MyBadAlloc 是更具体的 std::bad_alloc。
class MyBadAlloc : public std::bad_alloc
{
public:
    const char *what() const noexcept override
    {
        return "MyBadAlloc";
        // TODO 1: return "MyBadAlloc";
        return "TODO: MyBadAlloc message";
    }
};

void f(int mode)
{
    if (mode == 2)
    {
        throw MyBadAlloc{};
        // TODO 2: throw MyBadAlloc{};
        // 预测表：抛出类型 MyBadAlloc。
    }
}

int main()
{
    try
    {
        f(2);
        // TODO 3: f(2);
    }
    catch (const MyBadAlloc &e)
    {
        std::cout << e.what() << '\n';
        // TODO 4: 输出 e.what()。
        // 预测表：单一路径首先命中派生类 catch。
    }
    return 0;
}
