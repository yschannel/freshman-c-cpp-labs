#include "Mage.h"
#include "Warrior.h"
#include "Character.h"
#include "GameLobby.h"
#include <iostream>
#include <string>

int main()
{

    GameLobby Lobby;

    Character *W_ptr = new Warrior(100, "W");
    Lobby.AddCharacter(W_ptr);
    Character *M_ptr1 = new Mage(50, "M1");
    Lobby.AddCharacter(M_ptr1);
    Character *M_ptr2 = new Mage(675, "M2");
    Lobby.AddCharacter(M_ptr2);

    Lobby.ExecuteAllAttack();
    Lobby.ExecuteMageSkillOnly();

    return 0;
}