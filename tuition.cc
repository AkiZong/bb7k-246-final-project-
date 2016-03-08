#include "tuition.h"
#include "player.h"

using namespace std;

Tuition::Tuition(string name, int index): Unownable(name, index) {}


void Tuition::enter(Player *p) {
	PlayerHere[p->getIndex()] = p->getSymbol();
    NumPlayer++;
    cout << "You need to pay $300 or 10% of your total cash, enter 300 or 10: ";
    string cmd;
    
    while (cin >> cmd) {
        if (cmd == "300") {
            cout << "You paid $300 to TUITION." << endl;
            p->setCash(-300);
            break;
        }
        
        else if (cmd == "10") {
            cout << "You paid 10% of your total cash to TUITION." << endl;
            p->setCash(-(p->getTotal() * 0.1));
            break;
        }
        
        else{
            cout << "Invalid input: try other commands: ";
            cin.clear();
            cin.ignore();
        }
    }
}



void Tuition::leave(Player *ppl){
    NumPlayer--;
    PlayerHere[ppl->getIndex()] =' ';
}

