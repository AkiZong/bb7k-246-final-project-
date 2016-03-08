#include "gtt.h"
#include "player.h"

using namespace std;

go_to_tims::go_to_tims(string name, int index): Unownable(name, index) {
    tb = NULL;
}

void go_to_tims::add_tim(Building *t) {
    tb = t;
}


void go_to_tims::leave(Player *p) {
    NumPlayer--;
    PlayerHere[p->getIndex()] =' ';
}


void go_to_tims::enter(Player *p) {
    p->setJump(true);
    p->setPosition(10);
    tb->enter(p);
}

