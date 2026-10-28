#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>

int main()
{

    std::cout << std::filesystem::current_path() << std::endl;

    std::ifstream input("scores.txt");

    if (!input.is_open())
    {
        std::cerr << "Error: Could not open the file 'scores.txt'!" << std::endl;
        return 1;
    }

    std::string name;
    double score; // 改成int 停止

    std::cout << "---Reading Data---" << std::endl;

    // 高级条件判断
    while (input >> name >> score)
    {
        std::cout << "Name: " << name << ", Score: " << score << std::endl;
    }

    if (!input.eof())
    {
        std::cerr << "Warning: Stopped reading due to a format error in the file." << std::endl;
    }

    input.close();

    return 0;
}