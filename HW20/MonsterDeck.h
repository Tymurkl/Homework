#pragma once
#include <vector>

class Monster;

class MonsterDeck
{
public:
    MonsterDeck();
    ~MonsterDeck();

    Monster* generateMonster() const;

private:
    mutable std::vector<Monster*> m_monstersDatabase;
    mutable std::vector<Monster*> m_availableMonsters;
};
