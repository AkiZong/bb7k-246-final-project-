#ifndef __COOP_H__
#define __COOP_H__
#include "unownable.h"
#include <iostream>
#include <string>

class Coop: public Unownable{
public:
    // Coop constructor
    Coop(std::string name, int index);
    
    void enter(Player *p);
    void leave(Player *p);
};

#endif
