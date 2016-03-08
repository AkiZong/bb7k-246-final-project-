#ifndef __CLTOSAP_H__
#define __CLTOSAP_H__
#include "unownable.h"

class Cltosap: public Unownable{
public:
    // Cltosap constructor
    Cltosap(std::string name,int i);
    
    void enter(Player *p);
    void enterb(Player *p);
    void leave(Player *p);
};

#endif
