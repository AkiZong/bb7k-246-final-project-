#ifndef __NH_H__
#define __NH_H__
#include "unownable.h"
#include <iostream>
#include <string>

class NH:public Unownable {
public:
    // NH constructor
    NH(std::string name,int i);
    
    void enter(Player *p);
    void leave(Player *p);
};

#endif
