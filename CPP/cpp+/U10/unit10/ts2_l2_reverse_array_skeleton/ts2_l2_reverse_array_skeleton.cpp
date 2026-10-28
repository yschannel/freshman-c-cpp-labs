#include <array>
#include <cstddef>
#include <iostream>
#include <string>

// T 是元素类型。N 是 std::array<T, N> 在编译期确定的长度。
template <typename T, std::size_t N>
void printArray(const std::array<T, N>& values) {
    for (std::size_t i = 0; i < N; ++i) {
        std::cout << values[i] << (i + 1 == N ? '\n' : ' ');
    }
}

// 安全方向：返回副本，而不是返回局部数组的地址。
template <typename T, std::size_t N>
std::array<T, N> reverseCopy(const std::array<T, N>& input) {
    std::array<T, N> output{};

    // TODO 1：按反向顺序把 input 元素复制到 output。
    // 提示：当 i 为 0 时，源下标应为 N - 1。
    for (std::size_t i = 0; i < N; ++i) {
        output[i] = input[i];
    }

    // TODO 2：说明为什么按值返回 output 在生命周期上是安全的。
    return output;
}

int main() {
    std::array<int, 5> numbers{1, 2, 3, 4, 5};
    std::array<std::string, 3> words{"red", "green", "blue"};

    std::cout << "numbers before: ";
    printArray(numbers);
    std::cout << "numbers after : ";
    printArray(reverseCopy(numbers));

    std::cout << "words before  : ";
    printArray(words);
    std::cout << "words after   : ";
    printArray(reverseCopy(words));

    return 0;
}
