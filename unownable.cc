#include "unownable.h"

using namespace std;


Unownable::Unownable(string name, int index): Building(name,index), roll_up_remain(4){}

void Unownable::setRollup(int i) {
    roll_up_remain += i;
}

int Unownable::getRollup() {
    return roll_up_remain;
}


bool Unownable::tradeable(){
	return false;
}

