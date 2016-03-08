#include "academic.h"
#include "player.h"

using namespace std;


Academic::Academic(std::string name, int index, int price, int impvcost, int p1, int p2,
                   int p3, int p4, int p5, int p6, int p7): Ownable(name, index, price) {
    mono=new Building* [10];
	NumMono = 0;
    improvement = "     ";
    impvCost = impvcost;
    impvLevel = 0;
    payCost[0] = p1;
    payCost[1] = p2;
    payCost[2] = p3;
    payCost[3] = p4;
    payCost[4] = p5;
    payCost[5] = p6;
    payCost[6] = p7;
}


Academic::~Academic() {
    delete [] mono;
}


void Academic::add_mono(Building *b) {
    mono[NumMono] = b;
    NumMono++;
}


void Academic::enter(Player *p) {
	PlayerHere[p->getIndex()] = p->getSymbol();
    NumPlayer++;
    
    if (bought) {
        if (p->getSymbol() != holder->getSymbol()) {
            if (!monopoly && !mortgage) {
                p->setCash(-payCost[impvLevel]);
                holder->setCash(payCost[impvLevel]);
                cout << p->getPlayerName() << " paid $" << payCost[impvLevel] << " to "
                << holder->getPlayerName() << "." << endl;
            }
            
            else if (monopoly && !mortgage) {
                p->setCash(-payCost[impvLevel+1]);
                holder->setCash(payCost[impvLevel+1]);
                cout << p->getPlayerName() << " paid $" << payCost[impvLevel+1] << " to "
                << holder->getPlayerName() << "." << endl;
            }
            
            else {
                cout << "Mortgaged." << endl;
            }
        }
    }
    
    else {
        cout << "Would you want to pay $" << purchCost << " to own " << BuildingName << "? (y/n): ";
        
        string choice;
        while (cin >> choice) {
            if (choice == "y") {
                p->setCash(-purchCost);
                p->setTotal(purchCost);
                this->setPlayer(p);
                bought = true;
                ownership[0] = p->getSymbol();
                cout << "You paid $" << purchCost << " to buy " << BuildingName << "." << endl;
                break;
            }
            
            else if (choice == "n") {
                cout << "Auction start!" << endl;
                game->auction(this); //Auction
                break;
            }
            
            else {
                cout << "Invalid input, try other commands: ";
                cin.clear();
                cin.ignore();
            }
        }
    }
}


void Academic::leave(Player *p) {
    NumPlayer--;
    PlayerHere[p->getIndex()] =' ';
}


void Academic::setPlayer(Player *p) {
	bought = true;
    bool ifmono = true;
    holder = p;
    for (int i=0; i<NumMono; i++) {
        if (holder->getPlayerName() != mono[i]->getHoldername()) {
            ifmono = false;
        }
    }
    
    for (int i=0; i<NumMono; i++) {
        mono[i]->setMono(ifmono);
    }
    
    monopoly = ifmono;
}


void Academic::improveBuy() {
    if (impvLevel == 5) {
        cout << "Max Improvement, can't improve." << endl;
        return;
    }
    
    holder->setCash(-getImprvPrice());
    improvement[impvLevel] = 'I';
    impvLevel++;
}


void Academic::improveSell() {
    if (impvLevel == 0) {
        cout << "Min Improvement, can't sell." << endl;
    }
    
    holder->setCash(getImprvPrice() * 0.5);
    impvLevel--;
    improvement[impvLevel] = ' ';
}


int Academic::getImprvPrice() {
    return impvCost;
}


string Academic::getImprv() {
    return improvement;
}


int Academic::getImprvLevel() {
    return impvLevel;
}

void Academic::setImprLevel(int i) {
    impvLevel = i;
}

void Academic::improveBuy_load() {
	improvement[impvLevel] = 'I';
	impvLevel++;
}

bool Academic::tradeable(){
	bool cantrade=true;
	if(this->getImprvLevel()!=0){
		cantrade = false;
		return cantrade;
	}
	for(int i=0;i<NumMono;i++){
		if(mono[i]->getImprvLevel()!=0){
			cantrade = false;
		}
	}
	return cantrade;
}










