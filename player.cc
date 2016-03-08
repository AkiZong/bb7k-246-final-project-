#include "player.h"

using namespace std;


Player::Player(string name, char sym, int i) {
    PlayerName = name;
    PlayerIndex = i;
    symbol = sym;
    cash = 1500;
    totalwealth = 1500;
    position = 0;
    rollup = 0;
    jumpTim = false;
    tim = 0;
    bankrupt = false;
    NumRez = 0;
    NumGym = 0;
}


char Player::getSymbol() {
    return symbol;
}


void Player::setPosition(int pos) {
    position = pos;
}


int Player::getPosition() {
    return position;
}


void Player::setCash(int amount) {
    cash += amount;
    totalwealth=totalwealth+amount;
}


int Player::getCash() {
    return cash;
}


void Player::setTotal(int amount) {
    totalwealth += amount;
}


int Player::getTotal() {
    return totalwealth;
}


string Player::getPlayerName() {
    return PlayerName;
}


void Player::setJump(bool tmp) {
    jumpTim = tmp;
}


bool Player::getJump() {
    return jumpTim;
}


void Player::setTim(int i) {
    tim = i;
}


int Player::getTim() {
    return tim;
}


void Player::setRoll(int i) {
    rollup += i;
}


int Player::getRoll() {
    return rollup;
}

void Player::setBankrupt() {
    if (cash < 0) {
    	cout<<PlayerName<<" GAME OVER!"<<endl;
        bankrupt = true;
    } else {
        cout << "You can't Bankrupt." << endl;
    }
}


bool Player::getBankrupt() {
    return bankrupt;
}


void Player::setNumRez(int i) {
    NumRez = NumRez + i;
}


void Player::setNumGym(int i) {
    NumGym = NumGym + i;
}


int Player::getNumRez() {
    return NumRez;
}


int Player::getNumGym() {
    return NumGym;
}

int Player::getIndex(){
	return PlayerIndex;
}




