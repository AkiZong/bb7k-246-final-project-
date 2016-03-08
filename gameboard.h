#ifndef __GAMEBOARD_H__
#define __GAMEBOARD_H__
#include <iostream>
#include <string>
#include "building.h"
#include "ownable.h"
#include "player.h"

class GameBoard{
    int num_player;
    Building **board;
    Player **players;
    int cen_money;
    int num_double;
    int roll_up_remains;
    
public:
    // GameBoard constructor
    GameBoard(int n);
    // GameBoard destructor
    ~GameBoard();
    // set players' information in the gameboard
    void setPlayers();
    // initialize every board in the gameboard
    void init_board();
    // recognize every command and make related changes in players and boards
    void play(bool iftest);
    // the current player jumps to the board which is related rolled number
    void jump(Player *ppl);
    // display the initial board
    void prboard();
    // when the current player doesn't want to buy the budilging which (s)he is landedon,
    // the game will start auction, and make related changed in players and boards
    void auction(Building *bd);
    // the current player A is willing to give another player B money in exchange for a
    // building that belong to B. Example: trade Nomair 500 DC
    void trade(int tryer,std::string decider,int gvemoney, std::string getbuild);
    // the current player A is willing to give another player B a building which belongs
    // to A in excahnge for a building which belongs to B. Example: trade Kirsten DC MC.
    void trade(int tryer,std::string decider,std::string gvebuild, std::string getbuild);
    // the current player A is willing to give another player B a building which belongs
    // to A in excahnge for money Example: trade Sean MC 500
    void trade(int tryer,std::string decider,std::string gvebuild, int recmoney);
    // the current player A is willing to give another player B money in exchange for money.
    // Example: trade Sean 300 300
    void trade(int tryer,std::string decider,int gvemoney, int recmoney);
    // when a player owns a monopoly, (s)he can improve his buildings in this monopoly no more
    // than 5 times, and his buildings in this monopoly will cost others more tuition
    void improve(int i, std::string bdname, std::string action);
    // the current player can mortgage his properties to get related money
    void mortgage(std::string bdname, int player_index);
    // the current player can pay related fee to unmortgage his properties
    void unmortgage(std::string bdname, int player_index);
    // the current player has to bankrupt when his money is negative
    void bankrupt(Player *p);
    // when players want to save their current game and continue later, they can save
    void save(std::string filename);
    // get how many times the current player has rolled double continusly
    int getDouble_num();
    // if the current player rolls double, increase the number of double by 1;
    void addDouble_num();
    // set the current player's roll double times
    void setDouble_num(int i);
    // if players want to continue their previous game, they can load their saved game
    void loadfile(std::string filename);
    // if a player have banktrupted, change the current number of players
    void change_num_play(int n);
    // get the current number of players
    int getnum_player();
    // set the current number of remaining Tim Roll Ups
    void setRoll_up_remains(int i);
    // get the current number of remaining Tim Roll Ups
    int getRoll_up_remains();
};

#endif
