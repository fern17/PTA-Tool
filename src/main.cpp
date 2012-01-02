#include "functions.h"
#include "Master.h"
#include "Pkmn.h"
int main(){

    Master *master;

    master = Master::getInstance();

    parsePokemon(Master::getInstance()->dexter);
    //parseAttack(Master::getInstance()->atkdex);
    Pkmn pika("Wormadam",55);

    pika.print();

    return 0;

}
