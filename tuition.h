#ifndef __TUITION_H__
#define __TUITION_H__
#include "unownable.h"

class Tuition: public Unownable {
public:
    // Tuition constructor
    Tuition(std::string name,int index);
    
    void enter(Player *p);
    void leave(Player *p);
};

#endif
