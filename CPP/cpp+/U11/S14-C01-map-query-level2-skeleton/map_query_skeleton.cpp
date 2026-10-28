#include <iostream>
#include <map>
#include <string>

int main()
{
    // Level 2 半完成版：三处 TODO 对应数据、查询和结果处理。
    std::map<std::string, double> records{
        {"Alice", 3.2},
        {"Bob", 5.0},
        {"Chen", 4.6},
        {"Diana", 2.8},
        {"Eric", 6.1},
    };

    // TODO 1：用 insert() 或 emplace() 增加一条记录。
    records.emplace({"Jason", 0.0});
    // TODO 1 END

    std::cout << "请输入姓名：";
    std::string name;
    std::cin >> name;

    // TODO 2：使用 find() 查询；不要用 operator[] 代替存在性查询。
    auto it = records.find(name); // 占位代码，改之

    // TODO 3：判断 it 是否等于 end()，分别输出距离或“未找到记录”。
    if (it == records.end())
    {
        std::cout << "未找到记录（当前仍是待补全框架）。\n";
    }
    else
    {
        std::cout << name << ":" << it->second;
    }

    return 0;
}
