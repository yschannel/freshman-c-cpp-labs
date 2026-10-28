// Language: C++

#ifndef GENERATED_CPP_UNIT05_CODE_S02_MIL_STATUS_V0_HPP
#define GENERATED_CPP_UNIT05_CODE_S02_MIL_STATUS_V0_HPP

#include <iosfwd>
#include <string>
#include <vector>

class MilStatus {
   public:
    MilStatus(int id, std::string name, std::vector<std::string> equipments);
    MilStatus(const MilStatus &other);
    ~MilStatus();

    int getId() const;
    const std::string& getName() const;
    const std::vector<std::string>& getEquipments() const;

    void printSummary(std::ostream& out) const;

   private:
    int id;
    std::string name;
    std::vector<std::string> equipments;

    //统计对象个数
    static size_t objectCount;// = 0

    std::string *leader{nullptr};
};

#endif
