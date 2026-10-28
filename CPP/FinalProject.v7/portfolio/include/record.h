#ifndef RECORD_H
#define RECORD_H

#include <string>
#include <vector>
#include <map>
#include <functional>
#include <memory>

class Record
{
protected:
    std::string type;
    std::string time;
    std::string title;
    std::string difficulty;
    std::string tags;
    std::string note;

public:
    Record(const std::vector<std::string> &fields);

    virtual ~Record() = default;

    std::string getType() const { return type; }
    std::string getTime() const { return time; }
    std::string getTitle() const { return title; }
    std::string getDifficulty() const { return difficulty; }
    std::string getTags() const { return tags; }
    std::string getNote() const { return note; }

    virtual std::string toReportString() const = 0;

    virtual std::string toExportString(char delimiter) const = 0;
};

std::ostream &operator<<(std::ostream &os, const Record &rec);

class ExerciseRecord : public Record
{
public:
    using Record::Record;

    std::string toReportString() const override;
    std::string toExportString(char delimiter) const override;
};

class ConceptRecord : public Record
{
public:
    using Record::Record;

    std::string toReportString() const override;
    std::string toExportString(char delimiter) const override;
};

class BugRecord : public Record
{
public:
    using Record::Record;

    std::string toReportString() const override;
    std::string toExportString(char delimiter) const override;
};

class RecordFactory
{
private:
    // 存储创建外壳
    using RecordCreator =
        std::function<std::unique_ptr<Record>(const std::vector<std::string> &)>;

    // 注册表
    std::map<std::string, RecordCreator> registry;

public:
    RecordFactory();

    std::unique_ptr<Record> create(const std::string &type, const std::vector<std::string> &fields) const;
};

#endif