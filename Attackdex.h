#ifndef ATTACKDEX_H
#define ATTACKDEX_H

#include "Attack.h"
#include <string>
#include <map>

class Attackdex{
	public:
	std::map<std::string,Attack>  attackdex;

	Attackdex();
	Attack getAttack(std::string name);
	void insert(Attack atk);
};

#endif
