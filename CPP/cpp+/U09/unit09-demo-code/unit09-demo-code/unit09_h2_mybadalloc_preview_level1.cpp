#include <iostream>
#include <new>

// H1 仅预备这个派生类；完整的 catch 顺序实验留到 H2。
class MyBadAlloc : public std::bad_alloc
{
public:
    const char *what() const noexcept override
    {
        // TODO (H1): 返回自定义错误信息。
        return "TODO: MyBadAlloc message";
    }
};

void f(int mode)
{
    if (mode == 1)
    {
        throw 100;
        // TODO (H1): throw 100;  // 预测类型 int
    }
    else if (mode == 2)
    {
        throw MyBadAlloc{};
        // TODO (H1): throw MyBadAlloc{};  // 预测类型 MyBadAlloc
    }
}

int main()
{
    const int modes[] = {1, 2};
    for (int mode : modes)
    {
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
            std::cout << "catch MyBadAlloc: " << e.what() << '\n';
        }
        catch (const std::exception &e)
        {
            std::cout << "catch exception: " << e.what() << '\n';
        }
    }
    // TODO (H2): 添加 try-catch，并验证派生类 catch 位于基类 catch 之前。
    return 0;
}
