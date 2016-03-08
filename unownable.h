#ifndef __UNOWNABLE_H__
#define __UNOWNABLE_H__
#include "building.h"
#include <iostream>
#include <string>


class Unownable: public Building{
    int roll_up_remain;  // total roll_up card is 4.
public:
    // Unownable constructor
    Unownable(std::string name, int index);
    
    // set how many Roll Up cards remain
    void setRollup(int i);
    // get how many Roll Up cards remain
    int getRollup();
    
    // detailed descriptions in building.h
    bool tradeable();
};



#endif
