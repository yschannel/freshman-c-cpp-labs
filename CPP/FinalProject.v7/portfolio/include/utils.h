#ifndef UTILS_H
#define UTILS_H

#include <map>
#include <string>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <vector>

template <typename T>
class TopKCollector
{
    struct Item
    {
        T key;
        int count;
    };
    std::map<T, int> freq;
    size_t k;

public:
    TopKCollector(size_t k) : k(k) {}

    void add(const T &item) { freq[item]++; }

    std::vector<std::pair<T, int>> getTopK() const
    {
        std::vector<std::pair<T, int>> vec(freq.begin(), freq.end());
        std::sort(vec.begin(), vec.end(), [](const auto &a, const auto &b)
                  {
        if (a.second != b.second)
          return a.second > b.second;
        return a.first < b.first; });
        if (vec.size() > k)
            vec.resize(k);
        return vec;
    }
};

// 辅助函数：去除字符串首尾空格
inline std::string trim(const std::string &str)
{
    if (str.find_first_not_of(" \t\n\r") == std::string::npos)
    {
        return "";
    }
    size_t posf = str.find_first_not_of(" \t\n\r");
    size_t posl = str.find_last_not_of(" \t\n\r");

    // 截取函数
    return str.substr(posf, posl - posf + 1);
}

// 按指定分隔符切割字符串
inline std::vector<std::string> splitString(const std::string &str,
                                            char delimiter)
{
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;

    while (std::getline(ss, token, delimiter))
    {
        token = trim(token);
        tokens.push_back(token);
    }
    return tokens;
}

#endif