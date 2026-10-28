// Language: C++
 
#include <iostream>
 
int main() {
    double pi = 3.14159;
    int whole = static_cast<int>(pi);  // 显式说明：这里接受小数部分丢失。
    std::cout << "double -> int: " << pi << " -> " << whole << "\n";
    
    int code = 65;
    char letter = static_cast<char>(code);  // 显式说明：按字符编码解释整数。
    std::cout << "int -> char: " << code << " -> '" << letter << "'\n";
 
    // 对照（不推荐）：
    // int whole2 = (int)pi;
    // char letter2 = (char)code;
    // static_cast 在审查时更醒目，更容易让人追问“是否会丢信息”。
    
    // 如何验证：
    // 1) 比较转换前后输出；
    // 2) 口头回答每一步是否丢信息（double->int 会，int->char 取决于范围/编码）。
    return 0;
}
