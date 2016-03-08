#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <iostream>

class Player{
protected:
    std::string PlayerName;
    int PlayerIndex;
    char symbol;
    int cash;
    int totalwealth;
    int position;
    int rollup;
    bool jumpTim;
    int tim;
    bool bankrupt;
    int NumRez;
    int NumGym;
    
public:
    // Player constructor
    Player(std::string name, char sym, int i);
    
    // get a player's symbol
    char getSymbol();
    // set a player's position in the gameboard
    void setPosition(int pos);
    // get a player's position in the gameboard
    int getPosition();
    // set a player's remaining cash
    void setCash(int amount);
    // get a player's remaining cash
    int getCash();
    // set a player's total assets
    void setTotal(int amount);
    // get a player's total assets
    int getTotal();
    // get a player's name
    std::string getPlayerName();
    // set the current player's jump which related to his roll number
    void setJump(bool tmp);
    // get the current player's jump which related to his roll number
    bool getJump();
    // set the current player's number of Tim Roll Cup
    void setTim(int i);
    // get the current player's number of Tim Roll Cup
    int getTim();
    // set how many times the current player has rolled
    void setRoll(int i);
    // get how many times the current player has rolled
    int getRoll();
    // set if the current player is bankrupt
    void setBankrupt();
    // get if the current player is bankrupt
    bool getBankrupt();
    // set how many residences the current player owns
    void setNumRez(int i);
    // get how many residences the current player owns
    int getNumRez();
    // set how many gyms the current player owns
    void setNumGym(int i);
    // get how many gyms the current player owns
    int getNumGym();
    // get the index of a player
    int getIndex();
};

#endif
