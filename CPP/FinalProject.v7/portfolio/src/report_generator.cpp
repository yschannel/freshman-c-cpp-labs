#include "../include/report_generator.h"
#include <fstream>
#include <algorithm>
#include <map>

ReportGenerator::ReportGenerator(
    const Config &cfg, std::vector<std::unique_ptr<Record>> &&recs,
    const std::vector<std::string> &bads)
    : config(cfg), records(std::move(recs)), badLines(bads) {}

void ReportGenerator::generateExport(const std::string &filename)
{
    std::sort(
        records.begin(), records.end(),
        [](const std::unique_ptr<Record> &a, const std::unique_ptr<Record> &b)
        {
            return a->getTime() > b->getTime();
        });

    char delimiter = config.getString("delimiter")[0];

    std::ofstream file(filename);
    if (!file.is_open())
    {
        throw std::runtime_error("Cannot open export file: " + filename);
    }

    for (const auto &record : records)
    {
        file << record->toExportString(delimiter) << "\n";
    }
}

void ReportGenerator::generateReport(const std::string &filename)
{

    // 重载的运用
    if (!records.empty())
    {
        std::cout << "Preview of first record: " << *records[0] << std::endl;
    }

    std::ofstream file(filename);
    if (!file.is_open())
    {
        throw std::runtime_error("Cannot open report file: " + filename);
    }

    int total_records = records.size();
    int bad_lines = badLines.size();
    std::string student_id = config.getString("student_id");
    int seed = config.getInt("seed");

    std::map<std::string, int> count_by_type;
    std::map<int, int> difficulty_hist;
    TopKCollector<std::string> tag_collector(5);
    // std::map<std::string, int> tag_counts;

    for (const auto &record : records)
    {
        count_by_type[record->getType()]++;
        difficulty_hist[std::stoi(record->getDifficulty())]++;

        std::string tags = record->getTags();
        std::vector<std::string> tag_list = splitString(tags, ',');
        for (const auto &tag : tag_list)
        {
            if (!tag.empty())
            {
                tag_collector.add(tag);
            }
        }
    }

    /*
    std::vector<std::pair<std::string, int>> sorted_tags(tag_counts.begin(),
                                                         tag_counts.end());
    std::sort(sorted_tags.begin(), sorted_tags.end(),
              [](const auto &a, const auto &b)
              {
                  if (a.second != b.second)
                      return a.second > b.second;
                  return a.first < b.first;
              });
    */
    std::vector<std::string> required_types =
        splitString(config.getString("required_types"), ',');
    std::vector<std::string> missing_types;
    for (const auto &req_type : required_types)
    {
        if (count_by_type.find(req_type) == count_by_type.end())
        {
            missing_types.push_back(req_type);
        }
    }

    std::string checksum = "S" + std::to_string(seed) + "-R" +
                           std::to_string(total_records) + "-B" +
                           std::to_string(bad_lines);

    auto top_tags = tag_collector.getTopK();

    std::string report_format = config.getString("report_format");
    if (report_format == "text")
    {
        file << "student_id: " << student_id << "\n";
        file << "total_records: " << total_records << "\n";
        file << "bad_lines: " << bad_lines << "\n";

        file << "count_by_type:\n";
        for (const auto &type : required_types)
        {
            file << "  " << type << ": " << count_by_type[type] << "\n";
        }

        file << "difficulty_hist:\n";
        for (int i = 1; i <= 5; ++i)
        {
            file << "  " << i << ": " << difficulty_hist[i] << "\n";
        }

        file << "top_tags:\n";
        int top_n = 0;
        for (const auto &[tag, count] : top_tags)
        {
            file << "  " << tag << ": " << count << "\n";
        }

        if (!missing_types.empty())
        {
            file << "missing_required_types: ";
            for (size_t i = 0; i < missing_types.size(); ++i)
            {
                if (i > 0)
                    file << ",";
                file << missing_types[i];
            }
            file << "\n";
        }

        if (!badLines.empty())
        {
            file << "bad_line_details:\n";
            for (const auto &bad : badLines)
            {
                file << "  " << bad << "\n";
            }
        }

        file << "checksum: " << checksum << "\n";
    }
    else
    { // kvblock
        file << "student_id=" << student_id << "\n";
        file << "total_records=" << total_records << "\n";
        file << "bad_lines=" << bad_lines << "\n";

        for (const auto &type : required_types)
        {
            file << "count_by_type." << type << "=" << count_by_type[type] << "\n";
        }

        for (int i = 1; i <= 5; ++i)
        {
            file << "difficulty_hist." << i << "=" << difficulty_hist[i] << "\n";
        }

        int top_n = 0;
        for (const auto &[tag, count] : top_tags)
        {
            file << "top_tags." << tag << "=" << count << "\n";
        }

        if (!missing_types.empty())
        {
            file << "missing_required_types=";
            for (size_t i = 0; i < missing_types.size(); ++i)
            {
                if (i > 0)
                    file << ",";
                file << missing_types[i];
            }
            file << "\n";
        }

        for (size_t i = 0; i < badLines.size(); ++i)
        {
            file << "bad_line_details.line" << (i + 1) << "=\"" << badLines[i] << "\"\n";
        }

        file << "checksum=" << checksum << "\n";
    }
}