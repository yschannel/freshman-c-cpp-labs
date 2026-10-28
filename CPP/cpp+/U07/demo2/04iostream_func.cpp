#include <iostream>
#include <fstream>
#include <string>
#include <array>

int main()
{

    std::ifstream input("data.txt");
    if (!input.is_open())
    {
        std::cerr << "counld not open file." << std::endl;
        return 1;
    }

    std::cout << "---" << std::endl;
    // 使用std::getline 按 '#' 分割读取
    std::string name;

    while (std::getline(input, name, '#'))
    {
        std::cout << "Read name: " << name << std::endl;
    }

    // 清除 eof 标志，把文件指针重置到开头，准备进行下一次演示
    input.clear();
    input.seekg(0, std::ios::beg);

    //-- -演示 2：成员函数 input.getline 读取 char 数组-- -
    std::cout << "---" << std::endl;
    constexpr int SIZE = 40;
    std::array<char, SIZE> charName{};

    while (input.getline(charName.data(), SIZE, '#'))
    {
        std::cout << "Read name: " << charName.data() << std::endl;
    }
    input.close();

    // --- 演示 3：put() 和 flush() ---
    std::cout << "---" << std::endl;
    std::ofstream output("output.txt");
    if (output)
    {
        output.put('H');
        output.put('i');
        output.put('\n');
        // 轻质刷新缓冲区，确保信息立即写入
        output.flush();

        output << "World";
        output.close(); // close() 时会自动再次 flush 并写入 "World!"
    }

    return 0;
}