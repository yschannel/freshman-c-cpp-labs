#include <iostream>
#include <set>
#include <vector>

int main() {
    // Level 1 最小可行演示：使用固定数据，确保每次运行都可复现。
    const std::vector<int> input{4, 2, 4, 1, 3, 2};

    // vector 用来观察插入顺序；它会保留重复元素。
    const std::vector<int> values(input.begin(), input.end());

    // set 用来观察排序与去重；相同元素只保留一个。
    const std::set<int> unique_values(input.begin(), input.end());

    std::cout << "vector（插入顺序，保留重复）：";
    for (int value : values) {
        std::cout << ' ' << value;
    }

    std::cout << "\nset（升序输出，自动去重）：";
    for (int value : unique_values) {
        std::cout << ' ' << value;
    }
    std::cout << '\n';

    return 0;
}
