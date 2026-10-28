#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
class Character
{
protected:
    int hp;
    std::string name;

public:
    virtual void Attack() = 0;
    virtual void Skill() = 0;
    Character(int _hp, const std::string &_name);
    virtual ~Character() = default;
};
#endif