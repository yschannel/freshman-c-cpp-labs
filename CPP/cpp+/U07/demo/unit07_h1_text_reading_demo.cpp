#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int main() {
    {
        std::ofstream sample{"sample.txt"};
        sample << "Alice Zhang 90.5\n";
        sample << "Bob 88\n";
        sample << '\n';
        sample << "last line without extra marker";
    }

    // 读取粒度的选择取决于任务，不取决于个人习惯。
    std::ifstream by_field{"sample.txt"};
    std::string first;
    double score{};
    by_field >> first;
    std::cout << "operator>> first token = " << first << '\n';

    std::ifstream by_line{"sample.txt"};
    std::string line;
    std::getline(by_line, line);
    std::cout << "getline first line     = " << line << '\n';

    std::ifstream by_char{"sample.txt"};
    int newline_count = 0;
    char ch{};
    while (by_char.get(ch)) {
        if (ch == '\n') {
            ++newline_count;
        }
    }
    std::cout << "get newline_count      = " << newline_count << '\n';

    std::istringstream bad{"42"};
    while (!bad.eof()) {
        bad >> score; // 不推荐：eof() 不应作为读取循环入口。
    }
    return 0;
}
