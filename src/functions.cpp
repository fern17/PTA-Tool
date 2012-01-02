#include "functions.h"
#include <iostream>
void printMap(std::map<int,int>::iterator p, std::map<int,int>::iterator q){
    while(p != q){
        std::cout<<p->first<<" "<<p->second<<std::endl;
        p++;
    }

}

std::string Upper(std::string str) {
    for (int i = 0; i < str.length(); i++)
        str[i] = std::toupper(str[i]);
    return str;
}
