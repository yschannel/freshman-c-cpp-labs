// Language: C++

#include "MilStatus_v0.hpp"

#include <iostream>
#include <utility>

size_t MilStatus::objectCount = 0;

MilStatus::MilStatus(int id, std::string name,
                     std::vector<std::string> equipments, std::string leader)
    : id(id), name(std::move(name)), equipments(std::move(equipments)) {
    objectCount++;
    this->leader = new std::string(leader);
}

MilStatus::MilStatus() : MilStatus(10, "John", {"Jitui", "Hammer"}) {
    // objectCount++;
}

// 深拷贝的 copy ctor
MilStatus::MilStatus(const MilStatus& other) {
    id = other.id;
    name = other.name;
    equipments = other.equipments;
    leader = new std::string(*other.leader);  // 理解含义吗？会写吗？
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

    out << "objectCount=" << objectCount << std::endl;
    out << "-------\n\n" << std::endl;
}