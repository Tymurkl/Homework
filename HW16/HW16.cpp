#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Rectangle {
public:
    float length;
    float height;

    // Constructors
    Rectangle() {
        length = 0.0f;
        height = 0.0f;
    }

    Rectangle(float l, float h) {
        length = l;
        height = h;
    }

    // Methods
    float getArea() const {
        return length * height;
    }

    float getPerimeter() const {
        return 2 * (length + height);
    }
};

enum class PlayerClass {
    Assault,
    Support,
    Sniper,
    Medic
};

class Weapon {
public:
    string name;
    int damage;
    int range;
};

class Player {
public:
    string name;
    int health;
    PlayerClass playerClass;
    Weapon* weapon;
    string team;

    void setWeapon(Weapon* w) {
        weapon = w;
    }

    Weapon* getWeapon() const {
        return weapon;
    }

    void printPlayerInfo() const {
        cout << "Player name: " << name << endl;
        cout << "Player class: ";
        switch (playerClass) {
            case PlayerClass::Assault:
                cout << "Assault" << endl;
                break;
            case PlayerClass::Support:
                cout << "Support" << endl;
                break;
            case PlayerClass::Sniper:
                cout << "Sniper" << endl;
                break;
            case PlayerClass::Medic:
                cout << "Medic" << endl;
                break;
        }
        cout << "Player health: " << health << endl;

        if (weapon != nullptr) {
            cout << "Player's weapon: " << weapon->name << endl;
            cout << "Damage: " << weapon->damage << endl;
            cout << "Range: " << weapon->range << endl;
        } else {
            cout << "Player has no weapon." << endl;
        }

        cout << "Team: " << team << endl;
    }
};

class Team {
public:
    string teamName;
    vector<Player*> players;

    bool addPlayer(Player* player) {
        for (Player* p : players) {
            if (p == player) {
                return false;
            }
        }
        players.push_back(player);
        player->team = teamName;
        return true;
    }

    bool removePlayer(Player* player) {
        for (auto it = players.begin(); it != players.end(); ++it) {
            if (*it == player) {
                players.erase(it);
                player->team = "";
                return true;
            }
        }
        return false;
    }
};

int main() {
    // Test Rectangle
    Rectangle rect1(5.0f, 3.0f);
    cout << "Area of Rectangle: " << rect1.getArea() << endl;
    cout << "Perimeter of Rectangle: " << rect1.getPerimeter() << endl;

    // Test Player, Weapon, Team
    Player p1;
    p1.name = "John";
    p1.health = 100;
    p1.playerClass = PlayerClass::Assault;

    Weapon w1;
    w1.name = "AK-47";
    w1.damage = 50;
    w1.range = 200;

    p1.setWeapon(&w1);

    Player p2;
    p2.name = "Alice";
    p2.health = 90;
    p2.playerClass = PlayerClass::Support;

    Team team1;
    team1.teamName = "Red Team";

    team1.addPlayer(&p1);
    team1.addPlayer(&p2);

    // Display player info
    cout << endl;
    cout << "Player 1 Info:" << endl;
    p1.printPlayerInfo();
    cout << endl;
    cout << "Player 2 Info:" << endl;
    p2.printPlayerInfo();

    return 0;
}
