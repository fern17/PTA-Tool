#ifndef POKEDEX_H
#define POKEDEX_H

#include "Pokemon.h"
#include <string>
#include <map>

class Pokedex{
    public:
    std::map<std::string,Pokemon> dexter;
    void insert(Pokemon &p);
    Pokemon getPoke(std::string s);

    Pokedex();
};
#endif
