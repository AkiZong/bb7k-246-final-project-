#include "nh.h"
#include "player.h"
#include <ctime>
#include <cstdlib>
#include "gameboard.h"

using namespace std;

NH::NH(string name, int i): Unownable(name, i) {}


void NH::enter(Player *p) {
	PlayerHere[p->getIndex()] = p->getSymbol();
    NumPlayer++;
    srand(time(NULL));
    int tmp = rand()%18+1;
    
    if (tmp == 18) {
        cout << "You got $200 from Needles Hall." << endl;
        p->setCash(200);
    }
    
    else if (tmp >= 16) {
        cout << "You got $100 from Needles Hall." << endl;
        p->setCash(100);
    }
    
    else if (tmp >= 13) {
        cout << "You got $50 from Needles Hall." << endl;
        p->setCash(50);
    }
    
    else if (tmp >= 7) {
        cout<< "You got $25 from Needles Hall." << endl;
        p->setCash(25);
    }
    
    else if (tmp >= 4) {
        cout << "You paid $50 from Needles Hall." << endl;
        p->setCash(-50);
    }
    
    else if (tmp >= 2) {
        cout << "You paid $50 from Needles Hall." << endl;
        p->setCash(-100);
    }
    
    else{
        cout << "You paid $200 from Needles Hall." << endl;
        p->setCash(-200);
    }
    
    // Getting Roll Up Rim Cup
    
    srand(time(NULL));
    int chance = rand()%100;
    
    if (chance == 1 && game->getRoll_up_remains() > 0) {
        cout <<"You got a Tim Roll Up from Needles Hall." << endl;
        p->setRoll(1);
        game->setRoll_up_remains(-1);
    }
}

void NH::leave(Player *p){
    NumPlayer--;
    PlayerHere[p->getIndex()] =' ';
}

