#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <iomanip>

int main()
{

    std::vector<std::pair<std::string, double>> validRecords;
    double totalScore = 0.0;

    std::ifstream scores("scores.txt");
    if (!scores.is_open())
    {
        std::cerr << "Error: could not open!" << std::endl;
        return 1;
    }

    std::string buffer;
    while (std::getline(scores, buffer))
    {
        if (buffer.empty())
            continue;

        auto commaPos = buffer.find(',');
        if (commaPos == std::string::npos)
            continue;
        std::string name = buffer.substr(0, commaPos);
        std::string scoreStr = buffer.substr(commaPos + 1);

        try
        {
            size_t pos;
            double score = std::stod(scoreStr, &pos);

            bool isValid = true;
            for (size_t i = pos; i < scoreStr.length(); ++i)
            {
                if (!isspace(scoreStr[i]))
                {
                    isValid = false;
                    break;
                }
            }

            if (isValid)
            {
                validRecords.push_back({name, score});
                totalScore += score;
            }
        }
        catch (const std::invalid_argument &)
        {
            continue;
        }
        catch (const std::out_of_range &)
        {
            continue;
        }
    }
    scores.close();

    double average = 0.0;
    if (!validRecords.empty())
    {
        average = totalScore / validRecords.size();
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "valid aver scores: " << average << std::endl;

    // 6. 文件输出报告
    std::ofstream outFile("report.txt");
    if (!outFile.is_open())
    {
        std::cerr << "error: could not open" << std::endl;
        return 1;
    }

    outFile << "=== 成绩分析报告 ===" << std::endl;
    outFile << "姓名\t成绩" << std::endl;
    for (const auto &record : validRecords)
    {
        outFile << record.first << "\t" << record.second << std::endl;
    }
    outFile << "--------------------" << std::endl;
    outFile << "总平均分: " << average << std::endl;

    outFile.close();

    return 0;
}