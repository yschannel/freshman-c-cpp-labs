#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::cout << "Please enter your name: ";

    std::string name;
    std::getline(std::cin, name); // 读取用户输入

    // 默认覆盖原内容 如果要追加写成
    // std::ofstream outFile("output.txt", std::ios::app);
    std::ofstream outFile("output.txt");

    // 打开检查
    if (!outFile.is_open())
    {
        std::cerr << "Error: Could not open the file!" << std::endl;
        return 1;
    }

    outFile << "User Name: " << name << std::endl;
    outFile << "Statue: Succes" << std::endl;

    // 长时间大项目建议写close()
    outFile.close();

    std::cout << "Data has been written to output.txt successfully." << std::endl;

    return 0;
}