#include<iostream>
#include<array>
#include "MilStatus.h"

int main(){
    MilStatus cadet1;

    std::array<std::string, 5> initialEquips = {"Rifle", "Helmet", "nothing", "nothing", "nothing"};
    MilStatus veteran(7, "Zhang San", 21, 2, initialEquips);
    std::cout << "--- Initial Status ---\n";
    cadet1.printStatus();
    std::cout << "\n";
    veteran.printStatus();
    std::cout << "\n";

    std::cout << "--- Adding Equipment ---\n";
    std::cout << "Adding Radio: " << (veteran.addEquipment("Radio") ? "Success" : "Failed") << "\n";
    std::cout << "Adding Knife: " << (veteran.addEquipment("Knife") ? "Success" : "Failed") << "\n";
    std::cout << "Adding Backpack: " << (veteran.addEquipment("Backpack") ? "Success" : "Failed") << "\n";
    
    std::cout << "Adding Extra Item: " << (veteran.addEquipment("Extra") ? "Success" : "Failed") << "\n";

    std::cout << "--- Final Status ---\n";
    cadet1.printStatus(); 
    std::cout << "\n";
    veteran.printStatus(); 

    return 0;
}