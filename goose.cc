#include "goose.h"
#include "player.h"
using namespace std;


Goose::Goose(string name,int index): Unownable(name, index) {};


void Goose::enter(Player *p) {
	PlayerHere[p->getIndex()] = p->getSymbol();
    NumPlayer++;
}

void Goose::leave(Player *p) {
    NumPlayer--;
    PlayerHere[p->getIndex()] =' ';
}

