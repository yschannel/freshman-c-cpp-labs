#include "Mage.h"
#include "Warrior.h"
#include "Character.h"
#include <iostream>
#include <string>

int main()
{
    Warrior warrior(100, "W");
    Character *W_ptr = &warrior;

    Character *M_ptr = new Mage(50, "M");

    W_ptr->Attack();
    W_ptr->Skill();

    M_ptr->Attack();
    M_ptr->Skill();

    return 0;
}