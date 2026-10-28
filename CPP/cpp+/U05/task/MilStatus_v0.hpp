// Language: C++

#ifndef GENERATED_CPP_UNIT05_CODE_S02_MIL_STATUS_V0_HPP
#define GENERATED_CPP_UNIT05_CODE_S02_MIL_STATUS_V0_HPP

#include <iosfwd>
#include <string>
#include <vector>

class MilStatus {
   public:
    MilStatus(int id, std::string name, std::vector<std::string> equipments);

    int getId() const;
    const std::string& getName() const;
    const std::vector<std::string>& getEquipments() const;

    void printSummary(std::ostream& out) const;

    static int getObjectCount ();
    int getObjectCount2 ()const;

private:
    int id;
    std::string name;
    std::vector<std::string> equipments;

    static int objectCount;
};

#endif
