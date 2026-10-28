#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <stdexcept>
#include "utils.h"

// 自定义异常类
class ConfigException : public std::exception
{
private:
    std::string message;

public:
    ConfigException(const std::string &msg) : message(msg) {}

    const char *what() const noexcept override
    {
        return message.c_str();
    }
};

// 配置类
class Config
{
private:
    std::map<std::string, std::string> data;

    // tool
    void checkRequiredKey(const std::string &key);

public:
    Config(const std::string &filename);

    void load(const std::string &filename);

    std::string getString(const std::string &key) const;

    int getInt(const std::string &key) const;

    bool getBool(const std::string &key) const;
};

#endif