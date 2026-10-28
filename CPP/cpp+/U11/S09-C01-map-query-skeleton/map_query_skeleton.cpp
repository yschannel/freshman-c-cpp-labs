#include <iostream>
#include <map>
#include <string>

int main()
{
    // Level 2 半完成版：请补全 TODO，并解释 find() 与 end() 的关系。
    std::map<std::string, double> records{
        {"Alice", 3.2},
        {"Bob", 5.0},
        {"Chen", 4.6},
        {"Diana", 2.8},
        {"Eric", 6.1},
    };

    // TODO 1（数据插入）：再加入一条姓名与跑步距离记录。
    records.insert({"Shit", 6.7});
    // TODO 1 END

    std::cout << "请输入姓名：";
    std::string name;
    std::cin >> name;

    // TODO 2（find 查询）：将占位值替换为 records.find(name)。
    // find() 找不到键时会返回 records.end()，end() 是尾后位置。
    // 找到则输出姓名和成绩信息，未找到则输出提示
    auto it = records.find(name); // 占位代码

    // TODO 3（缺失键处理）：补全分支，使找到时输出距离，否则输出未找到。
    if (it != records.end())
    {
        std::cout << name << ":" << it->second;
    }
    else
    {
        std::cout << "未找到记录。\n";
    }

    return 0;
}
