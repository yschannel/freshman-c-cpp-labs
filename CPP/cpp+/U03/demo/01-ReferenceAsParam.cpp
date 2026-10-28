// Language: C++
 
#include <iostream>
 
// 值传递：函数拿到的是副本，修改不会影响外部变量。
void inc_by_value(int x) {
    x++;
    std::cout << "[inc_by_value] 函数内副本 x = " << x << "\n";
}
 
// 指针传递：函数可修改外部变量，但要处理空指针语义。
void inc_by_pointer(int* p) {
    if (p == nullptr) {
        std::cout << "[inc_by_pointer] 收到 nullptr，跳过修改\n";
        return;
    }
    (*p)++;
}
 
// 引用传递：函数拿到的是“同一对象的别名”，可直接修改外部变量。
void inc_by_ref(int& r) { r++; }
 
int main() {
    int n = 10;
    std::cout << "初始 n = " << n << "\n";
 
    inc_by_value(n);
    std::cout << "inc_by_value 后 n = " << n << "  (未变化，因修改的是副本)\n";
 
    inc_by_pointer(&n);
    std::cout << "inc_by_pointer(&n) 后 n = " << n << "  (已变化，修改了原对象)\n";
 
    inc_by_ref(n);
    std::cout << "inc_by_ref(n) 后 n = " << n << "  (已变化，引用是别名)\n";
 
    // 易错点：指针版本天然可表达“空值语义”，引用版本不能这样调用。
    inc_by_pointer(nullptr);
 
    // 如何验证：
    // 1) 观察每次调用后 n 是否变化；
    // 2) 比较调用端写法：&n / n；
    // 3) 思考“这个参数是否允许为空”该用哪个接口。
    return 0;
}
