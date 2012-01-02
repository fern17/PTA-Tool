#include "Pkmn.h"
#include <iostream>
#include <cmath>
#include <ctime>
#include "functions.h"

Pkmn::Pkmn(std::string name,unsigned int level, unsigned int mode){
    poke = Master::getInstance()->dexter.getPoke(Upper(name));
    if(level > 100){
        std::cout<<"Level over 100. Level = 100"<<std::endl;
        level = 100;
    }
    atkList.clear();
    c_lvl = level;
    added.resize(6,0);
    c_stages.resize(6,0);
    c_stats.resize(6,0);
    c_dmg = 0;
    c_exp = Master::getInstance()->levelChart[level];
    c_add = level-1;

    setNature();

    levelingMode = mode;

    distribute(c_add);
    c_add = 0;

   // poke.print();
}

//NOT WORKING, but useless ATM
void Pkmn::distribute(int points){
    while(points > 0){
        switch(levelingMode){
            case MODE_EVEN:{
                int min = getMinStat();
                int max = getMaxStat();
                if(min == max ){//si estan todos igualados
                    added[max]++;
                }else{
                    added[min]++;
                }
                break;
            }
        }
        recalculate();
        points--;
    }
}

int Pkmn::getMaxStat(){
    return *max_element(c_stats.begin(),c_stats.end());
}

int Pkmn::getMinStat(){
    return *min_element(c_stats.begin(),c_stats.end());
}

void Pkmn::recalculate(){
    for(unsigned int i = 0; i < c_stats.size(); i++){
        c_stats[i] = trunc((poke.base[i] + added[i])*stageMultiplier(c_stages[i]));
    }
    c_atkEvasion = (int) c_stats[2]/5;
    c_spatkEvasion = (int) c_stats[4]/5;
    c_speedEvasion = (int) c_stats[5]/10;
    c_hitPoints = c_stats[0]*4 + c_lvl - c_dmg;
}

float Pkmn::stageMultiplier(int i){
    float mult = 1.0;
    int m = 0;
    if(i > 0){
        while(m < i){
            mult *= 1.25;
            m++;
        }
    }
    else if(i < 0){
        while(i < m){
            mult *= 0.875;
            m--;
        }
    }
    return mult;
}

//Modifies the stat idx by adding stage (can be negative)
void Pkmn::raiseStat(unsigned int idx,int stage){
    if(idx > 5){
        std::cout<<"ERROR: idx of stat out of range. 0~5"<<std::endl;
    }
    else if(stage > 6){
        std::cout<<"ERROR: stage out of range. -6~+6"<<std::endl;
    }
    else{
        c_stages[idx] += stage;
        if(c_stages[idx] > 6){
            c_stages[idx] = 6;
        }
        if(c_stages[idx] < -6){
            c_stages[idx] = -6;
        }
        recalculate();
    }
}

void Pkmn::print(){
    std::cout<<poke.name<<" "<<c_lvl<<std::endl;
    nature.print();
    for(unsigned int i = 0; i < poke.base.size();i++){
        std::cout<<poke.base[i]<<" + "<<added[i]<<" = "<<c_stats[i]<<"(Stage="<<c_stages[i]<<")"<<std::endl;
    }
}

void Pkmn::setNature( int i){
    unsigned int maxNat = Master::getInstance()->NATURE_MAX;

    if(i > (int)maxNat){ //force casting because uint
        std::cout<<"Error, Nature out of range 0~"<<maxNat<<std::endl;
    }
    else{
        if(i == -1){
            srand(time(0));
            nature = Master::getInstance()->natures[rand()%maxNat];
        }
        else
            nature = Master::getInstance()->natures[i];
    }

    if(nature.raise == 0){ //HP
        poke.base[0]++;
    }
    else{
        poke.base[nature.raise]+= 2;
    }
    if(nature.lower == 0){ //HP
        poke.base[0]--;
    }
    else{
        poke.base[nature.lower]-= 2;
    }
}

void Pkmn::levelUp(int howMany){
    distribute(howMany);
}
