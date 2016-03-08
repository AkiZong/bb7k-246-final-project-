#include "building.h"
#include "gameboard.h"
#include "player.h"

using namespace std;

Building::Building(std::string name, int index) {
    BuildingName = name;
    BuildingIndex = index;
    NumPlayer = 0;
    PlayerHere = "      ";
    game = NULL;
    centreMoney = 0;
    impvLevel = 0;
}


Building::~Building() {}


string Building::getBuildingName() {
    return BuildingName;
}


int Building::getIndex() {
    return BuildingIndex;
}


string Building::getPlayerHere() {
    return PlayerHere;
}


void Building::add_mono(Building *b) {}


void Building::enter(Player *p) {
    PlayerHere[p->getIndex()] = p->getSymbol();
    NumPlayer++;
}


void Building::leave(Player *p) {
    NumPlayer--;
    PlayerHere[p->getIndex()] =' ';
}


void Building::enterb(Player *p) {
	PlayerHere[p->getIndex()] = p->getSymbol();
    NumPlayer++;
}


void Building::setOwnship(char sym) {}


string Building::getOwnership() {
    return "";
}


void Building::addgame(GameBoard *g) {
    game = g;
}


string Building::getHoldername() {
    return "";
}


void Building::setPlayer(Player *p) {}


void Building::setMono(bool ifmono) {}


bool Building::getMono() {
    return false;
}


string Building::getImprv() {
    return "";
}


int Building::getImprvPrice() {
    return 0;
}


int Building::getPurchCost() {
    return 0;
}


void Building::improveBuy() {}


void Building::improveSell() {}

void Building::setMort(bool ifmort) {}


bool Building::getMort(){
    return false;
}


bool Building::getBought(){
	return false;
}


Player* Building::getHolder(){
	return NULL;
}


void Building::setBought(bool i){};


int Building::getImprvLevel() {
    return impvLevel;
}

void Building::add_tim(Building *t){}


void Building:: setImprLevel(int i) {
	impvLevel = i;
}


void Building::improveBuy_load(){}

bool Building::getOwnable() {
    return false;
}

bool Building::tradeable(){
	return false;
}

bool Building::line(Player *p, bool iftest){
	return false;
}





