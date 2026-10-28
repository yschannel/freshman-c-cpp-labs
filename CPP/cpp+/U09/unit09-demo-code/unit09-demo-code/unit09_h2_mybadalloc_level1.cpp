#include <exception>
#include <iostream>
#include <new>

class MyBadAlloc : public std::bad_alloc
{
public:
    const char *what() const noexcept override
    {
        return "MyBadAlloc: simulated allocation failure";
    }
};

void f(int mode)
{
    if (mode == 1)
    {
        throw 100;
    }
    else if (mode == 2)
    {
        throw MyBadAlloc{};
    }
    else if (mode == 3)
    {
        throw std::bad_alloc{};
    }
}

int main()
{
    const int modes[] = {1, 2, 3};
    for (int mode : modes)
    {
        // TODO: 运行前填写 mode、抛出类型和预期 catch。
        try
        {
            f(mode);
        }

        catch (int e)
        {
            std::cout << "catch int: " << e << '\n';
        }
        catch (const MyBadAlloc &e)
        {
            // 派生类在前：保留 MyBadAlloc 的具体处理逻辑。
            std::cout << "catch MyBadAlloc: " << e.what() << '\n';
        }
        catch (const std::bad_alloc &e)
        {
            std::cout << "catch bad_alloc: " << e.what() << '\n';
        }
        catch (const std::exception &e)
        {
            std::cout << "catch exception: " << e.what() << '\n';
        }
    }

    // TODO 实验：将 bad_alloc 的 catch 提前，预测 mode=2 为何改变。
    return 0;
}
