#include <iostream>
#include <set>
#include <string>
#include <map>
#include <vector>
#include <memory>

#include "../include/config.h"
#include "../include/record_parser.h"
#include "../include/report_generator.h"

// 解析命令行参数
std::map<std::string, std::string> parserCommandLine(int argc, char *argv[])
{
    std::map<std::string, std::string> args;
    std::set<std::string> allowed = {"config", "records", "report", "export"};
    for (int i = 1; i < argc; ++i)
    {
        std::string arg = argv[i];
        size_t pos = arg.find('=');
        if (pos == std::string::npos)
        {
            throw std::runtime_error("Invalid argument format: " + arg);
        }
        std::string key = trim(arg.substr(0, pos));
        std::string value = trim(arg.substr(pos + 1));

        if (allowed.find(key) == allowed.end())
        {
            throw std::runtime_error("Unknown argument key: " + key);
        }
        if (args.find(key) != args.end())
        {
            throw std::runtime_error("Duplicate argument: " + key);
        }

        args[key] = value;
    }

    for (const auto &k : allowed)
    {
        if (args.find(k) == args.end())
        {
            throw std::runtime_error("Missing required argument: " + k);
        }
    }
    return args;
}

int main(int argc, char *argv[])
{
    if (argc != 5)
    {
        std::cerr << "Usage: " << argv[0]
                  << " config=...records=... report=... export=..." << std::endl;
        return 1;
    }

    std::map<std::string, std::string> args = parserCommandLine(argc, argv);

    if (args.find("config") == args.end() ||
        args.find("records") == args.end() ||
        args.find("report") == args.end() ||
        args.find("export") == args.end())
    {
        std::cerr << "Error: Missing required arguments." << std::endl;
        return 1;
    }

    std::string configPath = args["config"];
    std::string recordsPath = args["records"];
    std::string reportPath = args["report"];
    std::string exportPath = args["export"];

    try
    {
        Config config(configPath);
        RecordParser parser(config);
        std::vector<std::unique_ptr<Record>> records = parser.parse(recordsPath);
        const std::vector<std::string> &badLines = parser.getBadLines();

        ReportGenerator generator(config, std::move(records), badLines);

        generator.generateReport(reportPath);
        generator.generateExport(exportPath);

        std::cout << "Report and export files generated successfully!" << std::endl;
        return 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Fatal Error: " << e.what() << std::endl;
        return 1;
    }
}