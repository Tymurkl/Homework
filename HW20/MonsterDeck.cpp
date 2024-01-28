#include "MonsterDeck.h"
#include "Monster.h"
#include "Runaway.h"
#include <vector>
#include <algorithm>

MonsterDeck::MonsterDeck()
{
    m_monstersDatabase =
            {
                    new Monster{"Crazy Joe", 4},
                    new Monster{"Shiva destructor", 20, Tribe::God, new Runaway_LevelDowngradeIf{2, 5}},
                    new Monster{"Vampire", 3, Tribe::Undead, new Runaway_LevelDowngrade{1}},
                    new Monster{"Gool", 20, Tribe::Zombie, new Runaway_LevelDowngradeIf{2, 4}}
            };
    m_availableMonsters = m_monstersDatabase;
}

MonsterDeck::~MonsterDeck()
{
    for (Monster* monster : m_monstersDatabase)
    {
        delete monster;
    }
    m_monstersDatabase.clear();
}

Monster* MonsterDeck::generateMonster() const
{
    if (m_availableMonsters.empty())
    {
        m_availableMonsters = m_monstersDatabase;
    }

    const int randomIndex = std::rand() % m_availableMonsters.size();
    const Monster* chosenMonster = m_availableMonsters[randomIndex];

    m_availableMonsters.erase(std::remove(m_availableMonsters.begin(), m_availableMonsters.end(), chosenMonster), m_availableMonsters.end());

    return new Monster(*chosenMonster);
}
