#ifndef GAMELOBBY_H
#define GAMELOBBY_H

#include <vector>
#include <string>
#include "Character.h"

class GameLobby
{
private:
    std::vector<Character *> m_character;

public:
    GameLobby();
    ~GameLobby();
    void AddCharacter(Character *c);
    void ExecuteAllAttack();
    void ExecuteMageSkillOnly();
};

#endif