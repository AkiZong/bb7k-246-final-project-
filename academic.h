#ifndef __ACADEMIC_H__
#define __ACADEMIC_H__
#include <iostream>
#include <string>
#include "ownable.h"
#include "gameboard.h"

class Academic: public Ownable {
    Building **mono;
    int NumMono;
    std::string improvement;
    int impvCost;
    int impvLevel;
    int payCost[7];
    
public:
    // Academic constructor
    Academic(std::string name, int index, int price, int impvcost, int c1, int c2,
             int c3, int c4, int c5, int c6, int c7);
    // Academic destructor
    ~Academic();
    
    // detailed descriptions in building.h
    void enter(Player *p);
    void leave(Player *p);
    void setPlayer(Player *p);
    bool tradeable();
    
    // if buildings are in the same monopoly, add them together
    void add_mono(Building *b);
    // to check if one buulding can be improved or not, if it can be improved, change
    // the building's improvement status and player's assets, otherwise, display
    // "Max Improvement, can't improve."
    void improveBuy();
    // load the status of Academic buildings' improvement level(s)
    void improveBuy_load();
    // to check if one building can be sold or not, if it can be sold, change the
    // building's status and player's assets, otherwise, display "Min Improvement,
    // can't sell."
    void improveSell();
    // get a building's improve cost
    int getImprvPrice();
    // if a building has been improved, add a "I" at the top of that building
    std::string getImprv();
    // set the improvlevel to some integer.
    void setImprLevel(int i);
    // get a building's improve level(s)
    int getImprvLevel();
};










#endif
