#pragma once
#include "Munchkin.h"
#include <string>

class Runaway
{
public:
    virtual void apply(Munchkin* munchkin) = 0;
    virtual std::string getFullInfo() = 0;
};

class Runaway_LevelDowngrade : public Runaway
{
public:
    Runaway_LevelDowngrade(int levelToDowngrade) : m_levelToDowngrade(levelToDowngrade) {}

    void apply(Munchkin* munchkin) override;
    std::string getFullInfo() override;

private:
    int m_levelToDowngrade;
};

class Runaway_LevelDowngradeIf : public Runaway_LevelDowngrade
{
public:
    Runaway_LevelDowngradeIf(int levelToDowngrade, int minimalMunchkinLevelToApply)
            : Runaway_LevelDowngrade(levelToDowngrade), m_minimalMunchkinLevelToApply(minimalMunchkinLevelToApply) {}

    void apply(Munchkin* munchkin) override;
    std::string getFullInfo() override;

private:
    int m_minimalMunchkinLevelToApply;
};

class Runaway_ModifierFromHandRemoval : public Runaway
{
public:
    void apply(Munchkin* munchkin) override;
    std::string getFullInfo() override;
};

class Runaway_ItemEquippedRemoval : public Runaway
{
public:
    void apply(Munchkin* munchkin) override;
    std::string getFullInfo() override;
};
