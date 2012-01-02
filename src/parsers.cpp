#ifndef PARSERS_CPP
#define PARSERS_CPP

#include<vector>
#include<fstream>
#include<iostream>
#include<string>
#include<cstdlib>

#include "Pokedex.h"
#include "Pokemon.h"
#include "Attack.h"
#include "Attackdex.h"
#include "functions.h"

#define MIN_POKE 0
#define MAX_POKE 649

void parsePokemon(Pokedex &pokedex){
    std::string filename = "res/newdex2.txt";
    int n;

    std::fstream f(filename.c_str());
    if(!f.is_open()){
        std::cout<<"Error opening file!"<<std::endl;
    }
    std::string line;

    while(!f.eof()){

        Pokemon poke;

        getline(f,line);

        while(!f.eof() and (line.length() == 0 or line[0] == '#' or line[0] == '&')){
            getline(f,line);
        }

        if(line.substr(0,4) == "Name"){
            poke.name = line.substr(6,line.size());
            getline(f,line);
        }

		if(line.substr(0,7) == "Jp_Name"){
			poke.jpname = line.substr(9,line.size());
            getline(f,line);
		}

		if(line.substr(0,7) == "PTA_Num"){
			poke.ptanum = line.substr(9,line.size());
			poke.number = std::atoi(poke.ptanum.c_str());
            getline(f,line);
		}

		if(line.substr(0,7) == "Nat_Num"){
			poke.natnum = line.substr(9,line.size());
            getline(f,line);
		}

        while(line.substr(0,4) == "Type"){
            poke.type.push_back(line.substr(8,line.size()));
            getline(f,line);
        }


        if(line.substr(0,8) == "HeightUS"){
            poke.hUS = line.substr(10,line.size());
            getline(f,line);
        }

        if(line.substr(0,8) == "HeightSI"){
            poke.hSI = line.substr(10,line.size());
            getline(f,line);
        }

        if(line.substr(0,11) == "HeightClass"){
            poke.heightClass = line.substr(13,line.size());
            getline(f,line);
        }


		if(line.substr(0,8) == "WeightUS"){
            poke.wUS = line.substr(10,line.size());
            getline(f,line);
        }

        if(line.substr(0,8) == "WeightSI"){
            poke.wSI = line.substr(10,line.size());
            getline(f,line);
        }

        if(line.substr(0,11) == "WeightClass"){
            poke.weightClass = line.substr(13,line.size());
            getline(f,line);
        }


        if(line.substr(0,14) == "Classification"){
            poke.classification = line.substr(16,line.size());
            getline(f,line);
        }

        if(line.substr(0,8) == "Dex_Text"){
            poke.dexText = line.substr(10,line.size());
            getline(f,line);
        }

        if(line.substr(0,4) == "Diet"){
            poke.diet.push_back(line.substr(6,line.size()));
            getline(f,line);
        }


        if(line.substr(0,7) == "Habitat"){
            poke.habitat.push_back(line.substr(9,line.size()));
            getline(f,line);
        }


        if(line.substr(0,6) == "Gender"){
            poke.g = line.substr(8,line.size());
            getline(f,line);

        }


        if(line.substr(0,9) == "Egg_Group"){
            poke.eggGroup.push_back(line.substr(11,line.size()));
            getline(f,line);
        }


        if(line.substr(0,10) == "Hatch_Rate"){
            poke.hatch = atoi(line.substr(12,line.find(' ',12)-12).c_str());
            getline(f,line);

        }

        while(line.substr(0,5) == "Stage"){
            poke.stages.push_back(line.substr(9,line.size()));
            getline(f,line);
        }


        if(line.substr(0,4) == "Base"){
            poke.b.push_back(line.substr(12,line.size()));
            getline(f,line);
        }


        if(line.substr(0,12) == "Capabilities"){
            poke.capabilities.push_back(line.substr(14,line.size()));
            getline(f,line);
        }


        if(line.substr(0,15) == "Basic_Abilities"){
            poke.basicAbilities.push_back(line.substr(17,line.size()));
        }

        getline(f,line);
        if(line.substr(0,14) == "High_Abilities"){
            poke.highAbilities.push_back(line.substr(16,line.size()));
            getline(f,line);
        }


        if(line.substr(0,5) == "Moves"){
            poke.mL.push_back(line.substr(7,line.size()));
            getline(f,line);
        }

        while(isdigit(line[0])){
            poke.mL.push_back(line.substr(0,line.size()));
            getline(f,line);
        }

        if(line.substr(0,2) == "TM"){
            poke.tmList.push_back(line.substr(9,line.size()));
            getline(f,line);
        }


        if(line.substr(0,3) == "Egg"){
            poke.eggMoves.push_back(line.substr(11,line.size()));
            getline(f,line);
        }


        if(line.substr(0,5) == "Tutor"){
            poke.tutorMoves.push_back(line.substr(13,line.size()));
            getline(f,line);
        }


        if(poke.name != Pokemon::DEFAULT_NAME){
            poke.fix();
            //poke.print();
            pokedex.insert(poke);
        }
    }//end while

    f.close();
}


void parseAttack(Attackdex &attackdex){

    std::string filename = "res/movelist.txt";

    std::fstream f(filename.c_str());
    if(!f.is_open()){
        std::cout<<"Error opening file !" + filename<<std::endl;
    }
    std::string line;

    while(!f.eof()){
        Attack atk;

        getline(f,line);
        while(line.length() == 0 or line[0] == '&'){
            getline(f,line);
        }

        int pos = line.find('-');
        atk.name = line.substr(0,pos-1);
        atk.type = line.substr(pos+2,line.size()-pos-1);

        getline(f,line);
        pos = line.find('-');
        atk.frequency = line.substr(0,pos-1);
        atk.accuracy = atoi(line.substr(pos+2,line.size()-pos-1).c_str());

        getline(f,line);
        pos = line.find('-');
        atk.range = line.substr(0,pos-1);
        atk.atkType = line.substr(pos+2,line.size()-pos-1);

        if(atk.atkType != "No Damage"){
            getline(f,line);
            atk.dmg = line;
        }else{
            atk.dmg = "No Damage";
        }

        getline(f,line);
        atk.effect = line;

        atk.text = "";
        getline(f,line);
        while(line.size() != 0 and line[0] != '&'){
            atk.text += line + " ";
            getline(f,line);
        }

        //atk.print();
        attackdex.insert(atk);
    }
    f.close();
}
#endif
