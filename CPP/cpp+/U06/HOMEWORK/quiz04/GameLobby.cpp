#include "GameLobby.h"
#include <iostream>
#include <vector>
#include <string>
#include <typeinfo.h>
#include "Mage.h"

GameLobby::GameLobby() {};
GameLobby::~GameLobby()
{
    for (Character *Cptr : m_character) // 清理容器元素
    {
        delete Cptr;
    }

    m_character.clear(); // 清理容器本身
}

void GameLobby::AddCharacter(Character *c)
{
    if (c != nullptr)
    {
        m_character.push_back(c);
        std::cout << "Added a character to the lobby." << std::endl;
    }
}

void GameLobby::ExecuteAllAttack()
{
    for (Character *Cptr : m_character)
    {
        Cptr->Attack();
    }
}

void GameLobby::ExecuteMageSkillOnly()
{
    for (Character *Cptr : m_character)
    {

        if (typeid(*Cptr) == typeid(Mage))
        {
            Mage *Mptr = dynamic_cast<Mage *>(Cptr);
            if (Mptr != nullptr)
            {
                Mptr->Skill();
            }
        }

        /*没必要用typeid(),可以一步到位，dynamic不会抛出nullptr
        if(Mage* Mptr = dynamic_cast<Mage*>(Cptr)){
            Mptr->Skill()
        }


*/
    }
}