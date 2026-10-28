#include "../include/config.h"
#include <algorithm>
#include <cctype>
#include <stdexcept>

void Config::checkRequiredKey(const std::string &key)
{
    if (data.find(key) == data.end())
    {
        throw ConfigException("Missing required config key: " + key);
    }
}

void Config::load(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        throw ConfigException("Cannot open config file: " + filename);
    }

    std::string line;
    int lineNum = 0;
    while (std::getline(file, line))
    {
        lineNum++;
        line = trim(line);

        if (line.empty() || line[0] == '#')
        {
            continue;
        }

        size_t pos = line.find('=');
        if (pos == std::string::npos)
        {
            throw ConfigException("Invalid format: missing '=' in line " + std::to_string(lineNum));
        }

        std::string key = trim(line.substr(0, pos));
        std::string value = trim(line.substr(pos + 1));

        if (data.find(key) != data.end())
        {
            throw ConfigException("Duplicate config key: " + key);
        }
        data[key] = value;
    }

    checkRequiredKey("student_id");
    checkRequiredKey("seed");
    checkRequiredKey("delimiter");
    checkRequiredKey("required_types");
    checkRequiredKey("sort_by");
    checkRequiredKey("sort_order");
    checkRequiredKey("report_format");
    checkRequiredKey("strict");
}

std::string Config::getString(const std::string &key) const
{
    auto it = data.find(key);
    if (it == data.end())
    {
        throw ConfigException("Config key not found: " + key);
    }
    else
    {
        return it->second;
    }
}

int Config::getInt(const std::string &key) const
{
    auto it = data.find(key);
    if (it == data.end())
    {
        throw ConfigException("Config key not found: " + key);
    }
    else
    {
        int value;
        try
        {
            value = std::stoi(it->second);
        }
        catch (const std::invalid_argument &e)
        {
            throw ConfigException("Invalid format:" + key + "=" + it->second);
        }
        catch (const std::exception &e)
        {
            throw e;
        }
        return value;
    }
}

bool Config::getBool(const std::string &key) const
{
    auto it = data.find(key);
    if (it == data.end())
    {
        throw ConfigException("Config key not found: " + key);
    }
    else
    {
        std::string str = it->second;
        std::transform(str.begin(), str.end(), str.begin(),
                       [](unsigned char c)
                       { return std::tolower(c); });
        if (str == "true" || str == "1")
        {
            return true;
        }
        else if (str == "false" || str == "0")
        {
            return false;
        }
        else
        {
            throw ConfigException("Invalid format: " + key + '=' + it->second);
        }
    }
}

Config::Config(const std::string &filename)
{
    load(filename);
}