#include <iostream>
#include <string>
using namespace std;

// 版本 1: 处理 int
void print(int i) {
    cout << "打印整数: " << i << endl;
}

// 版本 2: 处理 double
void print(double d) {
    cout << "打印小数: " << d << endl;
}

// 版本 3: 处理 string
void print(const string& s) {
    cout << "打印字符串: " << s << endl;
}

// 版本 4: 处理两个 int (参数个数不同)
void print(int a, int b) {
    cout << "打印两个整数: " << a << ", " << b << endl;
}

int main() {
    print(10);          // 调用版本 1 (匹配 int)
    print(3.14);        // 调用版本 2 (匹配 double)
    print("Hello");     // 调用版本 3 ("Hello" 可转换为 string)
    print(1, 2);        // 调用版本 4 (匹配两个 int)

    return 0;
}