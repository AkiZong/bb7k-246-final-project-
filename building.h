#ifndef __BUILDING_H__
#define __BUILDING_H__
#include <iostream>
#include <string>

class Player;
class GameBoard;

class Building {
protected:
    std::string BuildingName;
    int BuildingIndex;
    std::string PlayerHere;
    int NumPlayer;
    GameBoard *game;
    int impvLevel;
    int centreMoney;
    
public:
    // Building constructor
    Building(std::string name, int index);
    // Building destructor
    virtual ~Building();
    // get the current building's name
    std::string getBuildingName();
    // get the current building's index
    int getIndex();
    // get the symbol(s) of player(s) who are in the current board
    std::string getPlayerHere();
    // when a player enters a building, change players' symbols in the current building
    virtual void enter(Player *p);
    // when a player leaves a building, change players' symbols in the current building
    virtual void leave(Player *p);
    // enterb function is to avoid players get $200 OSAP at the beginning of the game
    // since they landed on OSAP when the game starts
    virtual void enterb(Player *p);
    // when the current player buys a building B, set the ownersip of B to the player
    virtual void setOwnship(char sym);
    // get a building's owner name
    virtual std::string getOwnership();
    // add a game to these buildings
    void addgame(GameBoard *game);
    // get the player's name who owns the target building
    virtual std::string getHoldername();
    // set players in the current building
    virtual void setPlayer(Player *p);
    // get a building's purchase cost
    virtual int getPurchCost();
    // if a building is bought by a player, set bought to true, otherwise false
    virtual void setBought(bool i);
    // get if a buidling is bought by some player
    virtual bool getBought();
    // get all information of a player who owns a target building
    virtual Player* getHolder();
    // check if a building is tradable
    virtual bool tradeable();
    // get if a building is owned by some player
    virtual bool getOwnable();
    // set if a building is mortgaged or not
    virtual void setMort(bool ifmort);
    // get if a building is mortgaged or not
    virtual bool getMort();
    
    // detailed destriptions in academic.h
    virtual void add_mono(Building *b);
    virtual void improveBuy();
    virtual void improveSell();
    virtual void improveBuy_load();
    virtual int getImprvPrice();
    virtual std::string getImprv();
    virtual void setImprLevel(int i);
    virtual int getImprvLevel();
    
    // detailed destriptions in dctl.h
    virtual bool line(Player *p, bool iftest);
    
    // detailed descriptions in ownable.h
    virtual bool getMono();
    virtual void setMono(bool ifmono);
    
    // detailed descriptions in gtt.h
    virtual void add_tim(Building *t);
};

#endif





