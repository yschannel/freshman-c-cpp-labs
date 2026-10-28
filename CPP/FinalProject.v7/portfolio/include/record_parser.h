#ifndef RECORD_PARSER_H
#define RECORD_PARSER_H

#include <string>
#include <vector>
#include <memory>
#include "record.h"
#include "config.h"

class RecordParser
{
private:
    const Config &config;
    RecordFactory factory;
    std::vector<std::string> requiredTypes;
    std::vector<std::string> badLines;

    bool isRequiredType(const std::string &type) const;

public:
    RecordParser(const Config &cfg);

    std::vector<std::unique_ptr<Record>> parse(const std::string &filename);

    const std::vector<std::string> &getBadLines() const;
};

class ParseError : public std::runtime_error
{
public:
    explicit ParseError(const std::string &msg) : std::runtime_error(msg) {}
};

#endif