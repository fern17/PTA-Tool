#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <vector>
#include <sstream>
typedef struct move{
    std::string name;
    int level;

    move() : name(""),level(0){}
    move(std::string s, int l) : name(s), level(l){};
    std::string get(){
        std::stringstream ss;
        ss<<level;
        return std::string(name +" "+ ss.str());
    }

}move;


class Pokemon{
public:
    static const std::string DEFAULT_NAME;

    unsigned int number;
    std::string name;
    std::vector<std::string> type;
    std::string h;								//full height
    float f_height;								//meters, comparator
    std::string heightClass;					//Small, Medium, Large, Huge or Gigantic
    std::string w;								//full
    float f_weight; 							//kilograms, comparator
    unsigned int weightClass; 					//1 to 6
    std::vector<std::string> diet;
    std::vector<std::string> habitat;
    std::string g; 								// x% M / y% F
    float genderMale; 							//0..1 %
    float genderFemale; 						//0..1 %
    std::vector<std::string> eggGroup;
    unsigned int hatch; 						//days
    std::vector<std::string> stages;

    std::vector<std::string> b; 				//compatibility vector
    std::vector<int> base;
    std::vector<std::string> capabilities;
    std::vector<std::string> basicAbilities;
    std::vector<std::string> highAbilities;
    std::vector<std::string> mL;
    std::vector<move> moveList;
    std::vector<std::string> tmList; 			//need to convert to movelist
    std::vector<std::string> eggMoves;
    std::vector<std::string> tutorMoves;

    int getHP();
    int getATK();
    int getDEF();
    int getSPATK();
    int getSPDEF();
    int getSPEED();

    Pokemon() : name(DEFAULT_NAME), fixed(false){};
    void load(unsigned int n);
    void print();
    bool operator<(Pokemon p);
    bool fixed;
    void fix();
    void fixHeight();
    void fixWeight();
    void fixGender();
    void fixMoves();
    void splitStr(std::string str, char c, std::vector<std::string> &v);

};

#endif
