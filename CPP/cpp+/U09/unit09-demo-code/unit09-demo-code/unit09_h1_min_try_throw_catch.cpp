#include <iostream>

void requirePositive(int value)
{
    if (value < 0)
    {
        throw value;
        // TODO: throw value;  // 预测表：失败位置 requirePositive，抛出类型 int
    }
    std::cout << "requirePositive finished normally.\n";
}

int main()
{
    try
    {
        requirePositive(-1);
        // TODO: requirePositive(-1);  // 预测表：触发异常路径
        // 补全 throw 与调用后，下面这行不会执行。
        std::cout << "This line will not execute after throw.\n";
    }
    catch (int error_code)
    {
        // TODO: 输出 error_code；catch(int) 与 throw 的 int 类型匹配。
        std::cout << "catch(int): " << error_code << '\n';
    }

    // 预测表：异常被处理后，main 从 catch 之后继续执行。
    std::cout << "Execution continues.\n";
    return 0;
}
