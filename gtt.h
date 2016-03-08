#ifndef __GTT_H__
#define __GTT_H__
#include "unownable.h"
#include <iostream>
#include <string>

class go_to_tims: public Unownable {
    Building *tb;
    
public:
    // detailed descriptions in building.h
    void enter(Player *p);
    void leave(Player *p);
    
    // if the current player landed on "Go To Tims", he shoudl be sent to
    // "DC Tims Line"
    go_to_tims(std::string name, int index);
    // add Tim if a player landed in "Go To Tims"
    void add_tim(Building *t);

};

#endif
