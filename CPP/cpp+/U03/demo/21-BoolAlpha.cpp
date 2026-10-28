// Language: C++
 
#include <iostream>
 
int main() {
    bool passed = true;
    bool online = false;
    
    // 默认格式：bool 会按 1/0 输出，容易和普通整数混淆。
    std::cout << "默认输出: passed=" << passed << ", online=" << online << "\n";
    
    // 教学/调试更推荐 boolalpha：直接看到 true/false，语义更清晰。
    std::cout << std::boolalpha;
    std::cout << "boolalpha 输出: passed=" << passed << ", online=" << online << "\n";
    
    // 可选：恢复默认格式，便于比较两种观测口径。
    std::cout << std::noboolalpha;
    std::cout << "恢复默认: passed=" << passed << ", online=" << online << "\n";
    
    // 如何验证：观察三行输出差异，确认 true/false 更利于阅读与审计。
    return 0;
}
