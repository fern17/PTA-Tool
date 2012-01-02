#ifndef PKMN_H
#define PKMN_H

#include "Master.h"
#include "Pokemon.h"
#include "Attack.h"

#include <vector>
#include <algorithm>
#include <string>

//TODO: link to Attack

class Pkmn{
    public:
    //Constants
    static const int MODE_EVEN = 1;

    Pokemon poke;											//base pkmn

    //static throught leveling
    std::vector<Attack> atkList; 							//attack list
    Nature nature; 											//nature
    std::vector<std::string> abilities; 					//1 or more
    int levelingMode;										//how distribute() works
    std::vector<int> added;									//added points to each one

    //variables, c means current
    int c_lvl; 												//current level
    int c_exp; 												//current exp
    int c_hitPoints; 										//4*HP + lvl
    int c_dmg; 												//current damage
    std::vector<int> c_stats;
    int c_add; 												//added points, leveling
    std::vector<int> c_stages;
    int c_atkEvasion; 										//attack evasion
    int c_spatkEvasion; 									//special attack evasion
    int c_speedEvasion; 									//speed evasion

    Pkmn(std::string name, unsigned int level = 1, unsigned int mode = MODE_EVEN);
    void levelUp(int howMany = 1); 							//levelup
    void distribute(int points = 1);					 	// distribute points, not working
    int getMaxStat(); 										//returns max stat value
    int getMinStat(); 										//returns min stat value
    void recalculate(); 									//recalculate every variable because of stat change. MUST BE CALLED OFTEN
    float stageMultiplier(int i); 							//returns the multiplier for a given stage
    void raiseStat(unsigned int idx,int stage); 			//raises a stat by stage
    void setNature(int i = -1); 							//-1 equals random
    void print();
};

#endif
