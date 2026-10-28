#include "../include/record.h"
#include <stdexcept>
#include <sstream>

Record::Record(const std::vector<std::string> &fields)
    : type(fields[0]), time(fields[1]), title(fields[2]), difficulty(fields[3]), tags(fields[4]),
      note(fields[5])
{
    int diff_value = std::stoi(difficulty);
    if (diff_value < 1 || diff_value > 5)
    {
        throw std::invalid_argument("Invalid difficulty: " + difficulty);
    }
}

std::ostream &operator<<(std::ostream &os, const Record &rec)
{
    os << rec.toReportString();
    return os;
}

// ExerciseRecord
std::string ExerciseRecord::toReportString() const
{
    std::ostringstream oss;
    oss << "[" << type << "] " << time << ": " << title << " (Difficulty: " << difficulty << ")";
    return oss.str();
}

std::string ExerciseRecord::toExportString(char delimiter) const
{
    std::ostringstream oss;
    oss << type << delimiter
        << time << delimiter
        << title << delimiter
        << difficulty << delimiter
        << tags << delimiter
        << note;
    return oss.str();
}

// ConceptRecord
std::string ConceptRecord::toReportString() const
{
    std::ostringstream oss;
    oss << "[" << type << "] " << time << ": " << title << " (Difficulty: " << difficulty << ")";
    return oss.str();
}

std::string ConceptRecord::toExportString(char delimiter) const
{
    std::ostringstream oss;
    oss << type << delimiter
        << time << delimiter
        << title << delimiter
        << difficulty << delimiter
        << tags << delimiter
        << note;
    return oss.str();
}

// BugRecord
std::string BugRecord::toReportString() const
{
    std::ostringstream oss;
    oss << "[" << type << "] " << time << ": " << title << " (Difficulty: " << difficulty << ")";
    return oss.str();
}

std::string BugRecord::toExportString(char delimiter) const
{
    std::ostringstream oss;
    oss << type << delimiter << time << delimiter << title << delimiter
        << difficulty << delimiter << tags << delimiter << note;
    return oss.str();
}

// RecordFactory
RecordFactory::RecordFactory()
{
    registry["EXERCISE"] =
        [](const std::vector<std::string> &fields)
    { return std::make_unique<ExerciseRecord>(fields); };

    registry["CONCEPT"] = [](const std::vector<std::string> &fields)
    {
        return std::make_unique<ConceptRecord>(fields);
    };

    registry["BUG"] = [](const std::vector<std::string> &fields)
    {
        return std::make_unique<BugRecord>(fields);
    };
}

std::unique_ptr<Record>
RecordFactory::create(const std::string &type,
                      const std::vector<std::string> &fields) const
{
    auto it = registry.find(type);
    if (it == registry.end())
    {
        throw std::runtime_error("Unknown record type: " + type);
    }
    return it->second(fields);
}