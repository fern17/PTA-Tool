#include <string>
#include <iostream>

typedef struct Nature{
    unsigned int num;
    std::string name;
    unsigned int raise;
    unsigned int lower;
    std::string liked;
    std::string disliked;
    void print(){
        std::cout<<num<<' '<<name<<' '<<raise<<' '<<lower<<' '<<liked<<' '<<disliked<<std::endl;
    }

}Nature;
