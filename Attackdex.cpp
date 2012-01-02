#include "Attackdex.h"
#include <iostream>

Attackdex::Attackdex(){
	attackdex.clear();
}

void Attackdex::insert(Attack atk){
	std::string name = atk.name;
	if(attackdex.find(name) != attackdex.end()){
		std::cout<<"Duplicate Entry " + name<<std::endl;
        return;
    }

    std::pair<std::string,Attack> pair;
    pair.first = atk.name;
    pair.second = atk;
    attackdex.insert(pair);
}
