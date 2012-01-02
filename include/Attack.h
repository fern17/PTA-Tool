#ifndef ATTACK_H
#define ATTACK_H

#include <string>
class Attack{
    public:
    std::string name; //name of the move
    std::string frequency; //will, eot, battle, center
    std::string type; // dark, ghost, etc
    int accuracy; // 0 or greater
    std::string range; // melee, ranged or self
    std::string text; // text
    std::string dmg; // 5d10
    std::string atkType; // spatk or atk
    std::string effect;

    Attack(){};
    void print();
};

#endif
