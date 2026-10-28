#ifndef REPORT_GENERATOR_H
#define REPORT_GENERATOR_H

#include <string>
#include <vector>
#include <memory>
#include "config.h"
#include "record.h"

class ReportGenerator
{
private:
    const Config &config;
    std::vector<std::unique_ptr<Record>> records;
    const std::vector<std::string> &badLines;

public:
    ReportGenerator(const Config &cfg,
                    std::vector<std::unique_ptr<Record>> &&recs,
                    const std::vector<std::string> &bads);

    void generateReport(const std::string &filename);
    void generateExport(const std::string &filename);
};

#endif