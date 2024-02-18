#pragma once
#include <string>
#include "Tribe.h"
#include "Runaway.h"

class Runaway;

class Monster
{
public:
    Monster(const std::string& name, int level = 1, Tribe tribe = Tribe::Human, Runaway* policy = nullptr)
            : m_name(name), m_level(level), m_tribe(tribe), m_RunawayPolicy(policy), m_BonusVictoryPolicy(nullptr) {}

    Tribe getTribe() const { return m_tribe; }
    unsigned int getLevel() const { return m_level; }
    const std::string& getName() const { return m_name; }

    Runaway* getRunawayPolicy() const { return m_RunawayPolicy; }
    Runaway* getBonusVictoryPolicy() const { return m_BonusVictoryPolicy; }

    void setBonusVictoryPolicy(Runaway* bonusPolicy) { m_BonusVictoryPolicy = bonusPolicy; }

    std::string getFullInfo() const { return "Monster " + getName() + ", " + m_RunawayPolicy->getFullInfo(); }

private:
    unsigned int m_level = 1;
    Tribe m_tribe = Tribe::Human;
    std::string m_name;

    Runaway* m_RunawayPolicy = nullptr;
    Runaway* m_BonusVictoryPolicy = nullptr;
};
