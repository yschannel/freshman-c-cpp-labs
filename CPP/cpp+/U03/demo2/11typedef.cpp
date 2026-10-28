#include <iostream>
using namespace std;

// 【第1行】定义类型别名
// 语法：using 新名字 = 原有复杂类型;
// 这里的意思是：以后 "FuncType" 就代表 "void (*)(int, int)" 这种类型
using FuncType = void(*)(int, int); 

// 【第2行】定义一个普通函数
// 这个函数的签名是：返回void，接收两个int参数
void example(int a, int b) {
    cout << "Called example with " << a << " and " << b << endl;
}

int main() {
    // 【第3行】使用别名声明变量
    // 等价于：void (*f)(int, int) = example;
    // f 是一个指针，它指向一个函数，该函数接受两个int并返回void
    FuncType f = example; 

    // 【第4行】通过指针调用函数
    f(10, 20); 
    
    return 0;
}