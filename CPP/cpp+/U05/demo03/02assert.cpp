#include<iostream>
#include<array>
#include<cassert>
#include<type_traits> // used for std::is_integral

// ==========================================
// 1. static_assert: 编译期检查
// ==========================================

// 场景 A: 检查平台位数 (假设我们只支持 64 位系统)
// 如果你在 32 位编译器下编译这行代码，编译会直接失败，并显示后面的消息
static_assert(sizeof(void *) >= 8, "Error: This code reuqires a 64-bit system!");

// 场景 B: 模板编程中的类型检查
// 定义一个函数，只允许整数类型传入
template <typename T>
void processInteger(T value){
    static_assert(std::is_integral<T>::value,"Error: processInteger only accepts integer types!");

    std::cout << "Processing integer: " << value << std::endl;
}
// ==========================================
// 2. main 函数: 运行时逻辑
// ==========================================
int main() {
    // --- 演示 static_assert 的成功案例 ---
    // int 是整数，编译通过
    processInteger(10); 
    // processInteger(3.14); // 如果取消注释，编译器会直接报错，提示 "only accepts integer types"

    // --- 演示 用户输入处理 (预期内的错误) ---
    int divisor = 0;
    std::cout << "\n--- Input Validation Demo ---\n";
    std::cout << "Please enter a non-zero divisor: ";
    
    // 使用循环处理用户可能的错误输入 (这是预期会发生的情况)
    while(true){
        if(!(std::cin >> divisor)){
            std::cin.clear();//清楚错误标志
            std::cin.ignore(10000, '\n');//丢弃无效输入
            std::cout<<"Invalid input type. Please enter an integer: ";
            continue;
        }

        if(divisor == 0){
            std::cout << "Zero is not allowed! Please try again: ";

        }else {
            break;
        }
    }

    // --- 演示 assert: 内部逻辑假设 (绝不该发生的错误) ---
    // 经过上面的 while 循环，逻辑上 divisor 绝对不可能为 0。
    // 如果这里它为 0，说明上面的循环逻辑写崩了，或者内存被非法修改了。
    // 这是一个 BUG，我们需要在开发阶段立刻发现它。
    assert((divisor != 0) && "CRITICAL BUG: Divisor became zero after validation loop!");
    
    // 安全地进行除法运算
    int result = 100 / divisor;
    std::cout << "Result: 100 / " << divisor << " = " << result << std::endl;

    // --- 演示数组越界检查 ---
    std::array<int , 3> arr = {1,2,3};
    int index = 2;

    // 假设这里有一段复杂的逻辑计算 index
    // 我们假设逻辑保证 index 永远小于 3
    // 如果 index >= 3，说明逻辑错了
    assert(index < arr.size() && "CRITICAL BUG: Index out of bounds!");

    std::cout << "Array element: " << arr[index] << std::endl;

    return 0;
}