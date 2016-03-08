#include "ownable.h"
#include "player.h"

using namespace std;


Ownable::Ownable(string name, int index, int price): Building(name,index) {
    holder = NULL;
    owner = -1;
    purchCost = price;
    ownership = " ";
    holder = NULL;
    monopoly = false;
    bought = false;
    mortgage = false;
}


Ownable::~Ownable() {}


void Ownable::enter(Player *p) {
	PlayerHere[p->getIndex()] = p->getSymbol();
    NumPlayer++;
}


void Ownable::leave(Player *p) {
    NumPlayer--;
    PlayerHere[p->getIndex()] =' ';
}


void Ownable::enterb(Player *p) {
	PlayerHere[p->getIndex()] = p->getSymbol();
	NumPlayer++;
}


int Ownable::getOwner() {
    return owner;
}


int Ownable::getPurchCost() {
    return purchCost;
}


void Ownable::setOwnship(char sym) {
    ownership[0] = sym;
}

string Ownable::getOwnership() {
    return ownership;
}


bool Ownable::getMono() {
    return monopoly;
}

void Ownable::setBought(bool tmp) {
    bought = tmp;
}


bool Ownable::getBought() {
    return bought;
}


void Ownable::setPlayer(Player *p) {
	bought = true;
    holder = p;
}


string Ownable::getHoldername() {
    if (!holder) {
        return "";
    }
    return holder->getPlayerName();
}


void Ownable::setMono(bool ifmono) {
    monopoly = ifmono;
}



void Ownable::setMort(bool ifmort){
    mortgage = ifmort;
    
}


bool Ownable::getMort() {
    return mortgage;
}

Player* Ownable::getHolder(){
	return holder;
}

bool Ownable::getOwnable(){
    return true;
}

bool Ownable::tradeable(){
	return true;
}
