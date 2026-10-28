#include <array>
#include <cstddef>
#include <iostream>
#include <string>

template <typename T, std::size_t N>
void printArray(const std::array<T, N> &values)
{
    for (std::size_t i = 0; i < N; ++i)
    {
        std::cout << values[i] << (i + 1 == N ? '\n' : ' ');
    }
}

// Level 3 从安全签名开始，而不是直接给出完整实现。
// TODO：实现某个方案前，先说明 T 和 N 的含义。
template <typename T, std::size_t N>
std::array<T, N> reverseCopy(const std::array<T, N> &input)
{
    std::array<T, N> output;
    for (std::size_t i = 0; i < N; ++i)
    {
        output[i] = input[N - i - 1];
    }
    return output;
}

// 可选替代方案：
// template <typename T, std::size_t N>
// void reverseInPlace(std::array<T, N>& values);

int main()
{
    std::array<int, 4> numbers{1, 2, 3, 4};
    std::array<std::string, 3> words{"C++", "template", "test"};

    std::cout << "numbers before: ";
    printArray(numbers);
    // TODO：调用你补全后的 reverseCopy 或 reverseInPlace 实现。
    printArray(reverseCopy(numbers));

    std::cout << "words before  : ";
    printArray(words);
    // TODO：用第二种元素类型重复同样的证据。
    printArray(reverseCopy(words));

    std::cout << "Minimum evidence: two element types, before/after output, "
              << "and a short lifetime-safety explanation.\n";

    return 0;
}
