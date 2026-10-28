#include <iostream>

void f()
{
    throw 100;
    // TODO 1: 写入 throw 100;
    // 预测表列：抛出位置=f，抛出类型=int。
}

int main()
{
    try
    {
        f();
        // TODO 2: 写入 f();
        // 预测表列：throw 后同一 try 块的语句不执行。
        std::cout << "This line will not execute.\n";
    }
    catch (int e)
    {
        std::cout << "catch int: " << e << '\n';
        // TODO 3: 写入 std::cout << "catch int: " << e << '\n';
        // 预测表列：第一个匹配处理程序=catch(int)。
    }

    std::cout << "Execution continues.\n";
    return 0;
}
