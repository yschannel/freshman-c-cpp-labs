#ifndef MAGE_H
#define MAGE_H
#include "Character.h"

class Mage : public Character
{
public:
    Mage(int _hp, const std::string &_name);
    void Attack() override;
    void Skill() override;
};

#endif