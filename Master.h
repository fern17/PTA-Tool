#ifndef MASTER_H
#define MASTER_H

#include "Pokedex.h"
#include "Attackdex.h"
#include "Pokemon.h"
#include "Nature.h"
#include <iostream>

class Master{
    static bool instanceFlag;
    static Master* master;
    Master();
public:
    static std::string EXP_FILE;
    static std::string NATURE_FILE;
    static const unsigned int NATURE_MAX = 35;

    static Master * getInstance();
    static std::map<int,int> levelChart;
    static std::vector<Nature> natures;

    ~Master();
    Pokedex dexter;
	Attackdex attackdex;
    void openExpChart();
    void openNaturesChart();
};


#endif
