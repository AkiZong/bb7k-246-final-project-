#include "coop.h"
#include "player.h"

using namespace std;

Coop::Coop(string name, int index): Unownable(name, index) {}


void Coop::enter(Player *p) {
	PlayerHere[p->getIndex()] = p->getSymbol();
    NumPlayer++;
    cout << "You paid $150 for COOP Fee." << endl;
}


void Coop::leave(Player *p) {
    NumPlayer--;
    PlayerHere[p->getIndex()] =' ';
}




