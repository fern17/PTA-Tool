#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "Pokedex.h"
#include "Attackdex.h"
#include <string>
#include <map>

void parseAttack(Attackdex &attackdex);
void parsePokemon(Pokedex &pokedex);
void printMap(std::map<int,int>::iterator p, std::map<int,int>::iterator q);
std::string Upper(std::string str);

#endif
