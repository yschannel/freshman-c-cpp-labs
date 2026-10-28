#include"MilStatus.h"
#include <iostream>

int MilStatus::clampEquipNum (int num){
    if(num < 0)
        return 0;
    if(num > static_cast<int>(kMaxEquipments))
        return static_cast<int>(kMaxEquipments);
    return num;
}

MilStatus::MilStatus(): MilStatus(0,"Anonym",0,0,{"nothing","nothing","nothing","nothing","nothing"}){}

MilStatus::MilStatus(int _id, const std::string &_name, int _age, int _equipNum, const std::array<std::string, 5>& _equipments) : id(_id), name(_name),age(_age){
    this->equipNum = clampEquipNum(_equipNum);

    if(this->equipNum == 0){
        this->equipments = {"nothing", "nothing", "nothing", "nothing", "nothing"};
    }else{
        this->equipments = _equipments;
        for (std::size_t i = this->equipNum; i < kMaxEquipments; ++i){
            this->equipments[i] = "nothing";
        }
    }
}

bool MilStatus::addEquipment(const std::string& item){
    if(this->equipNum >= static_cast<int>(kMaxEquipments)){
        std::cout << "Equipment full\n";
        return false;
    }

    this->equipments[this->equipNum] = item;
    this->equipNum++;

    return true;
}

void MilStatus::printStatus() const{
    std::cout << "=== Soldier Status ===\n";
    std::cout << "ID:" << this->id << "\n";
    std::cout << "Name: " << this->name << "\n";
    std::cout << "Age:" << this->age << "\n";
    std::cout << "EquipNum:" << this->equipNum << "/" << kMaxEquipments << "\n";
    std::cout << "Equipments List:\n";
    
    for (std::size_t i = 0; i < kMaxEquipments; ++i) {
        std::cout << "  [" << i << "] " << this->equipments[i] << "\n";
    }
    std::cout << "======================" << "\n";
}