#include <exception>
#include <iostream>
#include <new>

// MyBadAlloc 是 std::bad_alloc 的派生异常；课堂用模拟抛出，不耗尽真实内存。
class MyBadAlloc : public std::bad_alloc
{
public:
    const char *what() const noexcept override
    {
        return "MyBadAlloc: simulated allocation failure";
        // TODO 1: return "MyBadAlloc: simulated allocation failure";
        return "TODO: provide MyBadAlloc message";
    }
};

void f(int mode)
{
    // 预测表：分别记录 mode、抛出类型与第一个匹配的 catch。
    if (mode == 1)
    {
        throw 100;
        // TODO 2: throw 100;             // 类型 int
    }
    else if (mode == 2)
    {
        throw MyBadAlloc{};
        // TODO 3: throw MyBadAlloc{};    // 类型 MyBadAlloc
    }
    else if (mode == 3)
    {
        throw std::bad_alloc{};
        // TODO 4: throw std::bad_alloc{}; // 类型 std::bad_alloc
    }
}

int main()
{
    const int modes[] = {1, 2, 3};
    for (int mode : modes)
    {
        try
        {
            f(mode);
            // TODO 5: f(mode);
        }
        catch (int e)
        {
            std::cout << "catch int: " << e << '\n';
        }
        catch (const MyBadAlloc &e)
        {
            // 正确顺序：派生类 catch 必须在 std::bad_alloc 之前。
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

    // TODO 实验：把 std::bad_alloc 的 catch 移到 MyBadAlloc 之前，
    // 重新预测 mode=2 的处理结果，再比较实际输出。
    return 0;
}
