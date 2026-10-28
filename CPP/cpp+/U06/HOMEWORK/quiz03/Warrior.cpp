#include "Warrior.h"
#include <iostream>

Warrior::Warrior(int _hp, const std::string &_name) : Character(_hp, _name) {};
void Warrior::Attack() { std::cout << this->name << " used a Heavy Slash!\n"; }
void Warrior::Skill()
{
    std::cout << this->name << " used a Whirlwind Slash!\n";
}