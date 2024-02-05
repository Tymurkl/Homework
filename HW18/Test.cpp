#include <iostream>
#include <string>

class Weapon {
public:
    virtual int getDamageRate(int distance) const = 0;
    virtual ~Weapon() {}
};

class RangedWeapon : public Weapon {
public:
    int getDamageRate(int distance) const override { return static_cast<int>(getPrecision(distance) * 10); }
    virtual ~RangedWeapon() {}

protected:
    virtual float getPrecision(int distance) const { return 1.0f; }
};

class SniperRifle : public RangedWeapon {
protected:
    float getPrecision(int distance) const override;
};

class Pistol : public RangedWeapon {
protected:
    float getPrecision(int distance) const override;
};

class MeleeWeapon : public Weapon {
public:
    int getDamageRate(int distance) const override { return getInReach(distance) * 8; }
    virtual ~MeleeWeapon() {}

protected:
    virtual float getInReach(int distance) const { return 1; }
};

class Sword : public MeleeWeapon {
protected:
    float getInReach(int distance) const override;
};

class Hammer : public MeleeWeapon {
protected:
    float getInReach(int distance) const override;
};

class PlayerClass {
public:
    virtual float getDamageMultiplier() const = 0;
    virtual float getArmorMultiplier() const = 0;
    virtual float getMissChance() const = 0;
    virtual ~PlayerClass() {}
};

class DefaultClass : public PlayerClass {
public:
    float getDamageMultiplier() const override { return 1.0f; }
    float getArmorMultiplier() const override { return 1.0f; }
    float getMissChance() const override { return 0.0f; }
};
class DefenderClass : public DefaultClass
{
public:
    //Leave damage multiplier as is
    virtual float getDamageMultiplier() const override { return 1.0f; }
    virtual float getArmorMultiplier() const override { return 1.2f; }
    virtual float getMissChance() const override { return 0.1f; } //1 out of 10 shots will be missed.
    //See Xcom or other turn-based like game for reference what miss chance is
};

class AttackerClass : public DefaultClass
{
public:
    virtual float getDamageMultiplier() const override { return 5.0f; }
    virtual float getArmorMultiplier() const override { return 0.2f; }
    virtual float getMissChance() const override { return 0.1f; }
};

class LuckyManClass : public DefaultClass {
public:
    float getDamageMultiplier() const override { return 8.0f; }
    float getArmorMultiplier() const override { return 0.1f; }
    float getMissChance() const override { return 0.8f; }
};

class Player {
public:
    Player(const std::string& name = "Auto Generated NameId", Weapon* weapon = new RangedWeapon, PlayerClass* playerClass = new DefaultClass)
            : m_name(name), m_weapon(weapon), m_class(playerClass) {}
    ~Player();

    std::string getName() const { return m_name; }
    int getBaseDamage(int distance) const { return m_weapon->getDamageRate(distance); }
    void setWeapon(Weapon* weapon);
    void setPlayerClass(PlayerClass* playerClass);
    void setHealth(int health) { m_health = health; }
    void setMissChance(int misschance) { m_class->getMissChance(); }
    bool isEliminated() const { return m_health <= 0; }

    void attack(const Player& other, int distance);

private:
    int m_health = 100;
    std::string m_name;

    PlayerClass* m_class = nullptr;
    Weapon* m_weapon = nullptr;
};

float SniperRifle::getPrecision(int distance) const {
    if (distance > 2000) {
        return 0.2f;
    }
    if (distance > 1000) {
        return 1.5f;
    }
    if (distance > 300) {
        return 5.0f;
    }
    return 1.0f;
}

float Pistol::getPrecision(int distance) const {
    if (distance > 200) {
        return 0.2f;
    }
    if (distance > 100) {
        return 1.5f;
    }
    if (distance > 30) {
        return 5.0f;
    }
    return 1.0f;
}

float Sword::getInReach(int distance) const {
    if (distance > 5) {
        return 0;
    }
    if (distance < 5) {
        return 10;
    }
}

float Hammer::getInReach(int distance) const {
    if (distance > 8) {
        return 0;
    }
    if (distance < 8) {
        return 15;
    }
}

Player::~Player() {
    delete m_class;
    delete m_weapon;
}

void Player::setWeapon(Weapon* weapon) {
    delete m_weapon;
    m_weapon = weapon;
}

void Player::setPlayerClass(PlayerClass* playerClass) {
    delete m_class;
    m_class = playerClass;
}

void Player::attack(const Player& other, int distance) {
    if (&other == this) {
        std::cout << "\n-------FRIENDLY FIRE!-------\n";
    }

    if (other.isEliminated()) {
        std::cout << "Player " << other.getName() << " has been already eliminated!\n";
        return;
    }

    const int damage = static_cast<int>(m_weapon->getDamageRate(distance) * m_class->getDamageMultiplier() / other.m_class->getArmorMultiplier());
    m_health -= damage;
    const int misschance = static_cast<int>((m_weapon->getDamageRate(distance) * m_class->getDamageMultiplier() / other.m_class->getArmorMultiplier()) / m_class->getMissChance());

    std::cout << "Player " << getName() << " attacked Player " << other.getName() <<
              " with damage " << damage << std::endl;
    std::cout << "Player " << getName() << " attacked Player " << other.getName() <<
              " Misschance " << misschance << std::endl;
    std::cout << "Health left: " << m_health << std::endl;

    if (m_health <= 0) {
        m_health = 0; // for consistency. For example UI may not support properly negative values

        std::cout << "Player " << other.getName() << " was eliminated!\n";
    }
}

int main() {
    // Example usage
    SniperRifle sniper;
    Pistol pistol;
    Sword sword;
    Hammer hammer;
    LuckyManClass luckyMan;
    AttackerClass attacker;
    DefenderClass defender;

    Player player1("SniperPlayer", &sniper, &luckyMan);
    Player player2("PistolPlayer", &pistol, &attacker);
    Player player3("SwordPlayer", &sword, &defender);
    Player player4("HammerPlayer", &hammer);

    // Example attacks
    player1.attack(player2, 800);
    player3.attack(player4, 5);

    return 0;
}
