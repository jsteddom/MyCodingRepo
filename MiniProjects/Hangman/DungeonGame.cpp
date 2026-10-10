#include <iostream>
#include <vector>


class Player {
private:
    std::string m_playerName {"You"};
    double healthPoints { 100.0 };
    Items itemOne { Items::Empty };
    Items itemTwo { Items::Empty};
public:
    Player() = default;
    void displayItems();
    void dropItem();
    void pickUpItem();
};

class Mobs {
private:
    std::vector<Enemies> m_mobs {};
public:
    void setMonsters();
};

void Mobs::setMonsters() {

}

enum class Enemies {
    Skeleton,
    Knight,
    Ghoul,
    Goblin,
};


enum class Items {
    Sword,
    Knife,
    HealthPotion,
    Key,
    ManaPotiion,
    Empty,
    Max
};


int main() {

    return 0;
}