#include "Master.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include "functions.h"
bool Master::instanceFlag = false;
Master * Master::master = NULL;

std::string Master::EXP_FILE = "expchart.txt";
std::string Master::NATURE_FILE = "natures.txt";

const unsigned int Master::NATURE_MAX;

std::map<int,int> Master::levelChart;
std::vector<Nature> Master::natures;

//void printMap(std::map<int,int>::iterator p, std::map<int,int>::iterator q){

void Master::openExpChart(){
    std::fstream f(EXP_FILE.c_str());
    if(!f.is_open()){
        std::cout<<"Error opening file! " + EXP_FILE<<std::endl;
    }

    int level = 1;
    while(!f.eof()){
        int exp;
        f>>exp;
        levelChart[level] = exp;
        level++;
    }
    f.close();
}

void Master::openNaturesChart(){
    std::fstream f(NATURE_FILE.c_str());
    if(!f.is_open()){
        std::cout<<"Error opening file! " + NATURE_FILE<<std::endl;
    }

    while(!f.eof()){
        Nature nat;
        std::string t;

        getline(f,t,'#');
        nat.num = atoi(t.c_str());

        getline(f,t,'#');
        nat.name = t;

        getline(f,t,'#');
        nat.raise = atoi(t.c_str());

        getline(f,t,'#');
        nat.lower = atoi(t.c_str());

        getline(f,t,'#');
        nat.liked = t;

        getline(f,t,'\n');
        nat.disliked = t;

        natures.push_back(nat);
    }
    f.close();
}


Master::Master(){
    openExpChart();
    openNaturesChart();
}


Master::~Master(){
    instanceFlag = false;
}

Master * Master::getInstance(){
    if(!instanceFlag){
        master = new Master();
        instanceFlag = true;
        return master;
    }
    else{
        return master;
    }
}
