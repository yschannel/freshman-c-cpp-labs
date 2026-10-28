#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

// Level 3 开放扩展任务
// 提交时请在函数上方写明：容器选择依据、预期输出、实际测试证据。

const std::vector<int> sample_values{4, 2, 4, 1, 3, 2};
const std::map<std::string, double> sample_records{
    {"Alice", 3.2},
    {"Bob", 5.0},
    {"Chen", 4.6},
    {"Diana", 2.8},
};

// 方向 A：容器转换与输出观察
// 使用给定数值，分别组织为 deque、set、vector，并比较顺序与重复值。
void explore_container_conversion(const std::vector<int> &input)
{
    std::cout << "===deque===\n";
    std::deque<int> deque(input.begin(), input.end());
    for (int value : deque)
    {
        std::cout << value << " ";
    }
    std::cout << "\n===set===\n";
    std::set<int> set(input.begin(), input.end());
    for (int value : set)
    {
        std::cout << value << " ";
    }
    std::cout << "\n===vector===\n";
    for (int value : input)
    {
        std::cout << value << " ";
    }
}

// 测试提示：输入 sample_values；记录三种输出的顺序及元素个数。

// 方向 B：运动记录扩展
// 二选一：生成唯一距离集合，或查询并返回最高跑步距离。
std::set<double>
collect_unique_distances(const std::map<std::string, double> &records)
{
    std::set<double> dist;
    for (const auto &element : records)
    {
        dist.insert(element.second);
    }
    return dist;
}
double find_highest_distance(const std::map<std::string, double> &records)
{
    auto it = std::max_element(
        records.begin(), records.end(),
        [](const auto &a, const auto &b)
        { return a.second < b.second; });
    return it->second;
}

// 测试提示：加入重复距离后检查唯一集合；最高距离应为样例中的 5.0。

int main()
{
    // 请选择方向 A 或 B，实现相应函数；这里不提供关键实现。
    std::cout << "A\n";
    explore_container_conversion(sample_values);
    std::cout << "B\n";
    std::set<double> unique_set = collect_unique_distances(sample_records);
    std::cout << "唯一距离集合: ";
    for (double dist : unique_set)
        std::cout << dist << " ";
    std::cout << "\n";

    // 测试最高距离
    double highest = find_highest_distance(sample_records);
    std::cout << "最高跑步距离是: " << highest << "\n";
    return 0;
}
