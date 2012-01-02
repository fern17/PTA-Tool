#include "Pokedex.h"
#include <iostream>

Pokedex::Pokedex(){
    dexter.clear();
}

template<typename T>
void print(T n){
    std::cout<<n<<std::endl;
}

void Pokedex::insert(Pokemon &p){
    if(dexter.find(p.name) != dexter.end()){
        std::cout<<"Duplicate Entry " + p.name<<std::endl;
        return;
    }
    std::pair<std::string,Pokemon> pair;
    pair.first = p.name;
    pair.second = p;
    dexter.insert(pair);
}

Pokemon Pokedex::getPoke(std::string s){
    std::map<std::string,Pokemon>::iterator p;
    p = dexter.find(s);
    if(p == dexter.end()){
        Pokemon poke; //default poke
        return poke;
    }

    else
        return p->second;
}
