#ifndef __SLC_H__
#define __SLC_H__
#include "unownable.h"

class SLC: public Unownable {
public:
    // SLC constructor
    SLC(std::string name, int i);
    
    void enter(Player *p);
    void leave(Player *p);
};

#endif
