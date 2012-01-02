#define DEBUG 1

#include "Pokemon.h"
#include<iostream>
#include<cstdlib>

const std::string Pokemon::DEFAULT_NAME = "DEFAULT_NAME";

void Pokemon::print(){
    if(!fixed) fix(); //force fix

    std::cout<<number<<" "<<name<<std::endl;
    for(unsigned int i = 0; i < type.size();i++){
        std::cout<<type[i]<<" ";
    }
    std::cout<<std::endl;
    std::cout<<h<<std::endl;
    std::cout<<w<<std::endl;
    for(unsigned int i = 0; i < diet.size();i++){
        std::cout<<diet[i]<<";";
    }
    std::cout<<std::endl;

    for(unsigned int i = 0; i < habitat.size();i++){
        std::cout<<habitat[i]<<";";
    }
    std::cout<<std::endl;

    std::cout<<g<<std::endl;

    for(unsigned int i = 0; i < eggGroup.size();i++){
        std::cout<<eggGroup[i]<<";";
    }
    std::cout<<std::endl;

    std::cout<<hatch<<std::endl;

    for(unsigned int i = 0; i < stages.size();i++){
        std::cout<<stages[i]<<";";
    }
    std::cout<<std::endl;

    std::cout<<base[0]<<std::endl;
    std::cout<<base[1]<<std::endl;
    std::cout<<base[2]<<std::endl;
    std::cout<<base[3]<<std::endl;
    std::cout<<base[4]<<std::endl;
    std::cout<<base[5]<<std::endl;


    for(unsigned int i = 0; i < capabilities.size();i++){
        std::cout<<capabilities[i]<<";";
    }
    std::cout<<std::endl;

    for(unsigned int i = 0; i < basicAbilities.size();i++){
        std::cout<<basicAbilities[i]<<";";
    }
    std::cout<<std::endl;

    for(unsigned int i = 0; i < highAbilities.size();i++){
        std::cout<<highAbilities[i]<<";";
    }
    std::cout<<std::endl;

    for(unsigned int i = 0; i < mL.size();i++){
        //std::cout<<moveList[i].get()<<"\n ";
        std::cout<<mL[i]<<"\n ";
    }
    std::cout<<std::endl;

    for(unsigned int i = 0; i < tmList.size();i++){
        std::cout<<tmList[i]<<";";
    }
    std::cout<<std::endl;

    for(unsigned int i = 0; i < eggMoves.size();i++){
        std::cout<<eggMoves[i]<<";";
    }
    std::cout<<std::endl;

    for(unsigned int i = 0; i < tutorMoves.size();i++){
        std::cout<<tutorMoves[i]<<";";
    }
    std::cout<<std::endl;
    std::cout<<"-------------------------------------------------"<<std::endl;
}


bool Pokemon::operator<(Pokemon p){
    return number < p.number;
}


void Pokemon::fix(){
    //std::cout<<name<<std::endl;

    fixHeight();
    fixWeight();
    fixGender();
    fixMoves();

    splitStr(b[0],',',b);
    base.resize(6);
    base[0] = atoi(b[0].c_str());
    base[1] = atoi(b[1].c_str());
    base[2] = atoi(b[2].c_str());
    base[3] = atoi(b[3].c_str());
    base[4] = atoi(b[4].c_str());
    base[5] = atoi(b[5].c_str());


    splitStr(diet[0],',',diet);
    splitStr(eggGroup[0],'/',eggGroup);
    splitStr(capabilities[0],',',capabilities);
    splitStr(basicAbilities[0],'/',basicAbilities);
    splitStr(highAbilities[0],'/',highAbilities);

    for(unsigned int i = 0; i < stages.size(); i++){ //erases "Minimun" Text
        int pos = stages[i].find("Minimum");
        if(pos != std::string::npos) stages[i].erase(pos,8);
    }

    if(tmList.size() != 0) splitStr(tmList[0],',',tmList);
    if(eggMoves.size() != 0) splitStr(eggMoves[0],',',eggMoves);
    if(tutorMoves.size() != 0) splitStr(tutorMoves[0],',',tutorMoves);
    //print();
    fixed = true;
}

void Pokemon::fixMoves(){
    if(mL.size() == 0)
        return;
    std::vector<std::string> vec;
    vec.push_back(mL[0]);

    splitStr(vec[0],',',vec);
    mL.erase(mL.begin()); //deletes because it is in vec
    mL.insert(mL.begin(),vec.begin(),vec.end());

    moveList.resize(mL.size());

    for(unsigned int i = 0; i < mL.size(); i++){
        if(mL[i][0] == ' ') mL[i] = mL[i].substr(1); //erases space at beginning
        int pos = mL[i].find(':');
        if(pos == std::string::npos){ //pos is learned before
            moveList[i].name = mL[i];
            moveList[i].level = 1;
        }
        else{
            moveList[i].name = mL[i].substr(pos+2);
            moveList[i].level = atoi(mL[i].substr(0,pos).c_str());
        }
       // std::cout<<moveList[i].get()<<std::endl;
    }

}


void Pokemon::fixGender(){
    if(g.size() == 0 or g == "No Gender"){
        genderMale = 0.0;
        genderFemale = 0.0;
    }
    else{
        int pos = g.find('%');
        genderMale = atof(g.substr(0,pos).c_str())/100.0;
        pos = g.find('/');
        int posn = g.find('%',pos);
        genderFemale = atof(g.substr(pos+2,posn-pos-2).c_str())/100.0;

    }
}

void Pokemon::fixHeight(){
    if(h.size() == 0){
        f_height = 1;
        heightClass = "Medium";
        return;
    }

    int pos = h.find('/');
    int posn = h.find('m');

    f_height = atof(h.substr(pos+2,posn-pos-2).c_str());
    pos = h.find('(');
    posn = h.find(')');

    heightClass = h.substr(pos+1,h.size()-1);
}

void Pokemon::fixWeight(){

    if(w.size() == 0){
        f_weight = 1;
        weightClass = 1;
        return;
    }

    int pos = w.find('/');
    int posn = w.find("kg");

    f_weight = atof(w.substr(pos+2,posn-pos-2).c_str());

    pos = w.find('(');
    posn = w.find(')');

    weightClass = atoi(w.substr(pos+1,h.size()-1).c_str());
}

void Pokemon::splitStr(std::string str, char c, std::vector<std::string> &v){

    std::string s = str;
   // if(DEBUG) std::cout<<"Input:"<<str<<std::endl;
    std::string toAdd = "";
    v.clear();
    int pos = 0;
    int posn = 0;

    posn = s.find(c);

    if(posn == -1) posn = s.size();

    toAdd = s.substr(0,posn);
    while(toAdd[0] == ' ') toAdd = toAdd.substr(1);
    while(toAdd[toAdd.size()-1] == ' ') toAdd = toAdd.substr(0,toAdd.size()-1);
    v.push_back(toAdd);

    if(posn != s.size()) posn++;

    while(posn != s.size() and pos != s.size()){
        pos = posn;
        posn = s.find(c,pos+1);
        if(posn == std::string::npos){
            posn = s.size();
        }

        toAdd = s.substr(pos+1,posn-pos-1);
        while(toAdd[0] == ' ') toAdd = toAdd.substr(1);
        while(toAdd[toAdd.size()-1] == ' ') toAdd = toAdd.substr(0,toAdd.size()-1);

        v.push_back(toAdd);
    }
}


int Pokemon::getHP(){
    return base[0];
}

int Pokemon::getATK(){
    return base[1];
}

int Pokemon::getDEF(){
    return base[2];
}

int Pokemon::getSPATK(){
    return base[3];
}

int Pokemon::getSPDEF(){
    return base[4];
}

int Pokemon::getSPEED(){
    return base[5];
}
