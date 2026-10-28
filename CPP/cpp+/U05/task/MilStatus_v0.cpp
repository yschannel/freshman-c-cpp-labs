// Language: C++

#include "MilStatus_v0.hpp"

#include <iostream>
#include <utility>

int MilStatus::objectCount = 0;

MilStatus::MilStatus(int id, std::string name,
                     std::vector<std::string> equipments)
    : id(id), name(std::move(name)), equipments(std::move(equipments)) {
    objectCount++;
}

int MilStatus::getId() const { return id; }

const std::string& MilStatus::getName() const { return name; }

const std::vector<std::string>& MilStatus::getEquipments() const {
    return equipments;
}

void MilStatus::printSummary(std::ostream& out) const {
    out << "MilStatus{id=" << id << ", name=" << name << ", equipments=[";
    for (std::size_t i = 0; i < equipments.size(); ++i) {
        out << equipments[i];
        if (i + 1 != equipments.size()) {
            out << ", ";
        }
    }
    out << "]}\n";
    out << objectCount << "\n";
    out << "=========================\n";
}

int MilStatus::getObjectCount(){
    return objectCount;
}

int MilStatus::getObjectCount2() const{
    return objectCount;
}