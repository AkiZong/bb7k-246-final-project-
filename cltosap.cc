#include "cltosap.h"
#include "player.h"

using namespace std;

Cltosap::Cltosap(string name, int i): Unownable(name, i) {}


void Cltosap::enter(Player *p) {
	PlayerHere[p->getIndex()] = p->getSymbol();
    NumPlayer++;
    cout << "You get OSAP $200." << endl;
    p->setCash(200);
}


void Cltosap::enterb(Player *p) {
	PlayerHere[p->getIndex()] = p->getSymbol();
    NumPlayer++;
}


void Cltosap::leave(Player *p) {
    NumPlayer--;
    PlayerHere[p->getIndex()] =' ';
}


