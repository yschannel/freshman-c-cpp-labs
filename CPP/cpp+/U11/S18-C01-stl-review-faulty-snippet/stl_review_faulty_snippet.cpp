#include <iostream>
#include <map>
#include <set>
#include <string>

int main() {
    // 需求：查询姓名对应的跑步距离；不存在的姓名不能改变原始记录。
    std::map<std::string, double> records{
        {"Alice", 3.2}, {"Bob", 5.0}, {"Chen", 4.6},
    };

    std::cout << "请输入姓名：";
    std::string name;
    std::cin >> name;
    std::cout << name << " 的距离：" << records[name] << " km\n";
    std::cout << "查询后的记录数：" << records.size() << '\n';

    // 需求：按采集顺序展示编号，同时忽略重复编号。
    const std::set<int> bib_numbers{42, 17, 42, 31};
    std::cout << "编号（采集顺序）：";
    for (int number : bib_numbers) {
        std::cout << ' ' << number;
    }
    std::cout << '\n';

    // 审核方向：输入不存在的姓名，并比较容器内容、输出顺序与需求。
    return 0;
}
