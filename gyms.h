#ifndef __GYM_H__
#define __GYM_H__
#include <iostream>
#include <string>
#include "ownable.h"
#include "player.h"

class Gyms: public Ownable {
public:
    // Gyms constructor
    Gyms(std::string name, int index, int price);
    // Gyms destructor
    ~Gyms();
    
    void enter(Player *p);
    void leave(Player *p);
};

#endif
