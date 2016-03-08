#ifndef __OWNABLE_H__
#define __OWNABLE_H__
#include <iostream>
#include <string>
#include "building.h"

class Ownable: public Building {
protected:
    int owner;
    int purchCost;
    std::string ownership;
    Player *holder;
    bool monopoly;
    bool bought;
    bool mortgage;
    
public:
    // Ownable constructor
    Ownable(std::string name, int index, int price);
    // Ownable destructor
    virtual ~Ownable();
    
    // detaied descriptions in building.h
    virtual void enter(Player *p);
    virtual void leave(Player *p);
    virtual void enterb(Player *p);
    std::string getOwnership();
    void setPlayer(Player *p);
    std::string getHoldername();
    void setBought(bool tmp);
    bool getBought();
    Player* getHolder();
    bool tradeable();
    bool getOwnable();
    void setOwnship(char sym);
    int getPurchCost();
    void setMort(bool ifmort);
    bool getMort();
    
    // set if an ownable building is in a monopoly or not
    void setMono(bool ifmono);
    // get if an ownable building is in a monopoly or not
    bool getMono();
    // return the owner of an ownable building
    int getOwner();
};

#endif
