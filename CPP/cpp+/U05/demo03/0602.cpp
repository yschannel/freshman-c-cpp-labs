#include<iostream>
#include<string>

int main(){
    //s 后缀定义在 std::literals::string_literals 命名空间中
    using namespace std::string_literals; 

    std::string s1 = "abc\0\0def";
    std::string s2 = "abc\0\0def"s;
    std::cout << "s1: " << s1.size() << " \"" << s1 << "\"\n";
    std::cout << "s2: " << s2.size() << " \"" << s2 << "\"\n";

    std::cout << "s2 true content: ";
    for (char c : s2) {
        if (c == '\0') {
            std::cout << "[NULL]";
        } else {
            std::cout << c;
        }
    }
    std::cout << std::endl;

    return 0;
}