#ifndef WARRIOR_H
#define WARRIOR_H
#include "Character.h"

class Warrior : public Character
{
public:
    Warrior(int _hp, const std::string &_name);
    void Attack() override;
    void Skill() override;
};

#endif