#include "Fight.h"
#include "Item.h"
#include "Modifier.h"
#include "Munchkin.h"
#include "Monster.h"
#include "Runaway.h"
#include <cassert>

void Fight::start()
{
    // Setup initial state
    m_result = FightResult::InProgress;

    calculateMunchkinPower();
    calculateMonsterPower();
}

void Fight::applyModifier(int choice)
{
    Modifier* modifier = m_munchkin->popModifier(choice);


    assert(modifier != nullptr && "Received a null modifier.");

    if (modifier != nullptr)
    {
        modifier->apply(m_munchkin, m_monster);

        m_MunchkinPower += modifier->getMunchkinModifier();  // Fixed variable name
        m_monsterPower += modifier->getMonsterModifier();
    }
}

void Fight::runawayFlow()
{
    Runaway* policy = m_monster->getRunawayPolicy();
    policy->apply(m_munchkin);

    m_result = FightResult::MonsterWon;
}

void Fight::victoryFlow()
{


    const int numberOfNewCards = 3;
    m_munchkin->addCardsToHand(numberOfNewCards);


    m_munchkin->updateLevelBy(1);

    m_result = FightResult::MunchkinWon;
}

void Fight::calculateMunchkinPower()
{
    m_MunchkinPower += m_munchkin->getLevel();  // Fixed variable name
    for (Item* item : m_munchkin->getItems())
    {
        m_MunchkinPower += item->getPower(m_monster->getTribe());
    }
}

void Fight::calculateMonsterPower()
{
    m_monsterPower = m_monster->getLevel();
}
