#ifndef __GOOSE_H__
#define __GOOSE_H__
#include "unownable.h"
#include <iostream>
#include <string>

class Goose:public Unownable{
public:
    // Goose constructor
    Goose(std::string name, int index);
    
    void enter(Player *p);
    void leave(Player *p);
};

#endif
