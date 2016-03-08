#include "residence.h"
#include "player.h"

using namespace std;

Residences::Residences(std::string name, int index, int price, int one, int two, int three, int four): Ownable(name, index, price) {
    payCost[0] = one;
    payCost[1] = two;
    payCost[2] = three;
    payCost[3] = four;
}


Residences::~Residences() {}


void Residences::enter(Player *p) {
	PlayerHere[p->getIndex()] = p->getSymbol();
    NumPlayer++;
    
    if (bought) {
        if (!mortgage) {
            if (p->getSymbol() != holder->getSymbol()) {
                p->setCash(-payCost[holder->getNumRez()-1]);
                holder->setCash(payCost[holder->getNumRez()-1]);
                cout << p->getPlayerName() << " paid $" << payCost[holder->getNumRez()-1] << " to " << holder->getPlayerName() << "." << endl;
            }
        }
        
        else {
            cout << "Mortgaged." << endl;
        }
    }
    
    else {
        cout << "Would you want to pay $" << purchCost << " to own " << BuildingName << " ? (y/n): ";
        
        string choice;
        while (cin >> choice) {
            if (choice == "y") {
                p->setCash(-purchCost);
                p->setTotal(purchCost);
                p->setNumRez(1);
                holder = p;
                bought = true;
                ownership[0] = p->getSymbol();
                cout << "You paid $" << purchCost << " to buy " << BuildingName << "." << endl;
                break;
            }
            
            else if (choice == "n") {
                cout << "Auction start!" << endl;
                game->auction(this); //  Auction
                break;
            }
            
            else {
                cout << "Invalid input, try other commadns: ";
                cin.clear();
                cin.ignore();
            }
        }
    }
}


void Residences::leave(Player *p) {
    NumPlayer--;
    PlayerHere[p->getIndex()] =' ';
}



