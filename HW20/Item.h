#pragma once
#include "Tribe.h"
#include <string>

class Item
{
public:
    virtual int getPower(Tribe monsterTribeModifier) const { return getBasePower(); }
    virtual int getBasePower() const { return 0; }

    void setName(const std::string& name) { m_name = name; }
    const std::string getName() const { return m_name; }
    virtual std::string getFullInfo() const = 0;

protected:
    std::string m_name;
    //other fields like description, image, category

private:
};

class Weapon : public Item
{
public:
    Weapon(const std::string& name, int power);

    int getBasePower() const override;

    std::string getFullInfo() const override;

protected:
    int m_power;
};

class UndeadWeapon : public Weapon
{
public:
    UndeadWeapon(const std::string& name, int power);

    int getPower(Tribe monsterTribeModifier) const override;

    std::string getFullInfo() const override;
};

class HolySword : public Weapon
{
public:
    HolySword(const std::string& name, int power);

    int getPower(Tribe monsterTribeModifier) const override;

    std::string getFullInfo() const override;
};
