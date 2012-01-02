#include "Attack.h"
#include<iostream>


void Attack::print(){
    std::cout<<name<<" "<<type<<std::endl;
    std::cout<<frequency<<" "<<accuracy<<std::endl;
    std::cout<<range<<" "<<atkType<<std::endl;
    std::cout<<dmg<<std::endl;
    std::cout<<effect<<std::endl;
    std::cout<<text<<std::endl;
    std::cout<<"-------------------------"<<std::endl;
}
