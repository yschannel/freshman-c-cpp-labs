#include "../include/record_parser.h"
#include "../include/utils.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <set>
#include <cctype>

static std::string validataAndNormalize(std::vector<std::string> &fields,
                                        char delimiter)
{
    if (fields.size() != 6)
        return "field count mismatch";
    const std::string &type = fields[0];
    const std::string &time = fields[1];
    const std::string &title = fields[2];
    const std::string &difficulty = fields[3];
    const std::string &tagsStr = fields[4];
    const std::string &note = fields[5];

    // 1.type
    if (type != "CONCEPT" && type != "EXERCISE" && type != "BUG")
        return "unknown type: " + type;

    // 2.time(YYYY-MM-DD)
    if (time.size() != 10 || time[4] != '-' || time[7] != '-')
        return "invalid date format: " + time;

    // 3. title/note cannot contain delimiter
    if (title.find(delimiter) != std::string::npos)
        return "title contains delimiter";
    if (note.find(delimiter) != std::string::npos)
        return "note contains delimiter";

    // 4. difficulty must be integer 1-5
    int diff;
    try
    {
        diff = std::stoi(difficulty);
    }
    catch (...)
    {
        return "invalid difficulty: " + difficulty;
    }
    if (diff < 1 || diff > 5)
        return "invalid difficulty: " + difficulty;

    // 5. tags: split，deduplicate，check
    if (tagsStr.empty())
    {
        return "empty tags";
    }
    std::vector<std::string> tags = splitString(tagsStr, ',');
    std::set<std::string> uniqueTags;
    for (const auto &tag : tags)
    {
        if (tag.empty())
            return "empty tag";
        for (char c : tag)
        {
            if (!std::isalnum(static_cast<unsigned char>(c)) && c != '_' && c != '-')
                return "invalid tag character: " + tag;
        }
        uniqueTags.insert(tag);
    }

    std::string normalizedTags;
    for (auto it = uniqueTags.begin(); it != uniqueTags.end(); ++it)
    {
        if (it != uniqueTags.begin())
            normalizedTags += ",";
        normalizedTags += *it;
    }
    fields[4] = normalizedTags;
    // 注意：这里需要修改原始字段，但无法修改const fields，所以需要在外部更新

    return ""; // AC
}

RecordParser::RecordParser(const Config &cfg) : config(cfg)
{
    requiredTypes = splitString(config.getString("required_types"), ',');
}

bool RecordParser::isRequiredType(const std::string &type) const
{
    return std::find(requiredTypes.begin(), requiredTypes.end(), type) != requiredTypes.end();
}

std::vector<std::unique_ptr<Record>>
RecordParser::parse(const std::string &filename)
{
    std::vector<std::unique_ptr<Record>> records;
    std::ifstream file(filename);

    if (!file.is_open())
    {
        throw std::runtime_error("Cannot open records file: " + filename);
    }

    std::string line;
    int lineNum = 0;
    char delimiter = config.getString("delimiter")[0];
    bool strict = config.getBool("strict");

    while (std::getline(file, line))
    {
        lineNum++;
        line = trim(line);
        if (line.empty())
            continue;

        std::vector<std::string> fields = splitString(line, delimiter);

        if (fields.size() != 6)
        {
            if (!strict)
            {
                badLines.push_back("line " + std::to_string(lineNum) + ": field count mismatch");
                continue;
            }
            else
            {
                throw std::runtime_error("Invalid record format at line " + std::to_string(lineNum));
            }
        }

        // copy to normalize
        std::vector<std::string> validFields = fields;
        std::string error = validataAndNormalize(validFields, delimiter);

        if (!error.empty())
        {
            if (strict)
            {
                throw ParseError("line " + std::to_string(lineNum) + ": " + error);
            }
            else
            {
                badLines.push_back("line " + std::to_string(lineNum) + ": " + error);
                continue;
            }
        }

        try
        {
            auto record = factory.create(validFields[0], validFields);
            records.push_back(std::move(record));
        }
        catch (const std::exception &e)
        {
            if (strict)
            {
                throw;
            }
            else
            {
                badLines.push_back("line " + std::to_string(lineNum) + ": " + e.what());
            }
        }
    }
    return records;
}

const std::vector<std::string> &RecordParser::getBadLines() const
{
    return badLines;
}
