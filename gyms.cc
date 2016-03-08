#include "gyms.h"
#include "gameboard.h"
#include <ctime>
#include <cstdlib>
using namespace std;

Gyms::Gyms(string name, int index, int price): Ownable(name, index, price) {}

Gyms::~Gyms() {}


void Gyms::enter(Player *p) {
	PlayerHere[p->getIndex()] = p->getSymbol();
    NumPlayer++;
    int totalpay = 0;
    
    if (bought) {
        if (p->getSymbol() != holder->getSymbol()) {
            srand(time(NULL));
            int roll1 = rand()%6+1;
            int roll2 = rand()%6+1;
            
            if (holder->getNumGym() == 1) {
                totalpay = (roll1 + roll2) * 4;
            } else if (holder->getNumGym() == 2) {
                totalpay = (roll1 + roll2) * 10;
            }
            
            p->setCash(-totalpay);
            holder->setCash(totalpay);
            cout << p->getPlayerName() << " paid $" << totalpay << " to " << holder->getPlayerName() << "." << endl;
        }
    }
    
    else {
        cout << "Would you want to pay $" << purchCost << " to own " << BuildingName << " ? (y/n): ";
        
        string choice;
        while (cin >> choice) {
            if (choice == "y") {
                p->setCash(-purchCost);
                p->setTotal(purchCost);
                // add gym num
                p->setNumGym(1);
                holder = p;
                bought = true;
                ownership[0] = p->getSymbol();
                cout << "You paid $" << purchCost << " to buy " << BuildingName << "." << endl;
                break;
            }
            
            else if (choice == "n") {
                cout << "Auction start!" << endl;
                game->auction(this);  //Auction
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


void Gyms::leave(Player *p) {
    NumPlayer--;
    PlayerHere[p->getIndex()] =' ';
}



