#include "Runaway.h"
#include "Munchkin.h"
#include <algorithm>
#include <cstdlib>

void Runaway_LevelDowngrade::apply(Munchkin* munchkin)
{
    munchkin->updateLevelBy(-m_levelToDowngrade);
}

std::string Runaway_LevelDowngrade::getFullInfo()
{
    return "Level Downgrade by " + std::to_string(m_levelToDowngrade) + " upon loss";
}

void Runaway_LevelDowngradeIf::apply(Munchkin* munchkin)
{
    if (munchkin->getLevel() >= m_minimalMunchkinLevelToApply)
    {
        Runaway_LevelDowngrade::apply(munchkin);
    }
}

std::string Runaway_LevelDowngradeIf::getFullInfo()
{
    return "Level Downgrade by " + std::to_string(m_levelToDowngrade) + " if level >= " + std::to_string(m_minimalMunchkinLevelToApply) + " upon loss";
}

void Runaway_ModifierFromHandRemoval::apply(Munchkin* munchkin)
{
    auto& modifiers = munchkin->getModifiers();
    if (!modifiers.empty())
    {
        std::size_t randomIndex = std::rand() % modifiers.size();
        modifiers.erase(modifiers.begin() + static_cast<std::ptrdiff_t>(randomIndex));
    }
}

std::string Runaway_ModifierFromHandRemoval::getFullInfo()
{
    return "Removes one random modifier from hand upon loss";
}

void Runaway_ItemEquippedRemoval::apply(Munchkin* munchkin)
{
    auto& items = munchkin->getItems();

    if (!items.empty())
    {
        auto maxPowerItem = std::max_element(items.begin(), items.end(),
                                             [](const Item* item1, const Item* item2) {
                                                 return item1->getBasePower() < item2->getBasePower();
                                             });

        if (maxPowerItem != items.end()) {
            auto iteratorToMaxPowerItem = std::find(items.begin(), items.end(), *maxPowerItem);

            if (iteratorToMaxPowerItem != items.end()) {
                items.erase(iteratorToMaxPowerItem);
            }
        }
    }
}

std::string Runaway_ItemEquippedRemoval::getFullInfo()
{
    return "Removes the most powerful equipped item upon loss";
}
