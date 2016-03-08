#ifndef __RESIDENCE_H__
#define __RESIDENCE_H__
#include <iostream>
#include <string>
#include "ownable.h"
#include "gameboard.h"

class Residences: public Ownable {
    int payCost[4];
    
public:
    // Residences constructor
    Residences(std::string name, int index, int price, int one, int two, int three, int four);
    // Residences destructor
    ~Residences();
    
    void enter(Player *p);
    void leave(Player *p);
};

#endif
