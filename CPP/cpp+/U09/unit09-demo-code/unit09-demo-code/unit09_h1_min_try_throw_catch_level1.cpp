#include <iostream>

void f(int value)
{
    if (value < 0)
    {
        throw value;
        // TODO: throw value;
        // 预测表列：value=-1 时抛出类型为 int。
    }
    std::cout << "f finished normally.\n";
}

int main()
{
    const int values[] = {1, -1};
    for (int value : values)
    {
        std::cout << "value = " << value << '\n';
        try
        {
            f(value);
            // TODO: f(value);
            // 预测表列：记录本轮是否到达 try 块末尾。
        }
        catch (int e)
        {
            std::cout << "Invalid value: " << e << '\n';
            // TODO: 输出捕获到的异常值 e。
            // 预测表列：仅异常轮命中 catch(int)。
        }
    }
    return 0;
}
