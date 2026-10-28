#include "Mage.h"
#include <iostream>

Mage::Mage(int _hp, const std::string &_name) : Character(_hp, _name) {};
void Mage::Attack() { std::cout << this->name << " performed a Normal Attack!\n"; }
void Mage::Skill()
{
    std::cout << this->name << " unleashed a Fireball!\n";
}