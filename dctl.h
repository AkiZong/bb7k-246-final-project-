#ifndef __DCTL_H__
#define __DCTL_H__
#include "unownable.h"
#include <iostream>
#include <string>

class Dctl: public Unownable{
public:
    // Dctl constructor
    Dctl(std::string name, int i);
    
    void enter(Player *p);
    void leave(Player *p);
    
    // if a player was sended to "DC TIMS LINE", check if he needs to get related punish
    bool line(Player *p, bool iftest);
};

#endif
