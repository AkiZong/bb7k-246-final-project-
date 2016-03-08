#include "dctl.h"
#include <ctime>
#include <cstdlib>
#include "player.h"
#include "gameboard.h"
using namespace std;

Dctl::Dctl(string name, int i): Unownable(name, i) {}


void Dctl::enter(Player *p) {
	PlayerHere[p->getIndex()] = p->getSymbol();
    NumPlayer++;
}


void Dctl::leave(Player *p) {
    NumPlayer--;
    PlayerHere[p->getIndex()] =' ';
}


bool Dctl::line(Player *p, bool iftest) {
    if (p->getJump()) {
        cout << "Tims Line" << endl;
        cout << "You have three choices: 1. roll double, 2. pay $50, 3. use one Tim Cup if you own." << endl;
        cout << "Enter 'roll', 'pay', or 'tim': ";
        
        string cmd;
        
        while (cin >> cmd) {
            if (cmd == "roll") {
                if (p->getTim() == 3) {
                    cout << "You have rolled 3 times, choose other options: ";
                    cin.clear();
                    cin.ignore();
                }
                
                else {
                    int roll1;
                    int roll2;
                    
                    if(!iftest){
                        srand(time(NULL));
                        roll1 = rand()%6 + 1;
                        roll2 = rand()%6 + 1;
                    }
                    else {
                        cin>>roll1;
                        cin>>roll2;
                    }
                    
                    if (roll1 == roll2) {
                        
                        cout << "You rolled double, now you can leave DCTL." << endl;
                        p->setPosition(p->getPosition() + roll1 + roll2);
                        leave(p);
                        p->setJump(false);
                        p->setTim(0);
                        return false;
                    }
                    
                    else {
                        cout << "Sorry, not double." << endl;
                        p->setTim(p->getTim() + 1);
                        return true;
                    }
                }
            }
            
            else if (cmd == "pay") {
                p->setCash(-50);
                p->setTim(0);
                p->setJump(false);
                return false;
            }
            
            else if (cmd == "tim") {
                if (p->getRoll()) {
                    p->setTim(0);
                    p->setJump(false);
                    p->setRoll(-1);
                    // the remain card will increase by 1 because the card is used.
                    game->setRoll_up_remains(1);
                    return false;
                }
                
                else {
                    cout << "You have 0 Tim Cup, choose otheroptions: ";
                    cin.clear();
                    cin.ignore();
                }
            }
        
            else {
                cout << "Invalid input: try other commands: ";
                cin.clear();
                cin.ignore();
            }
        }
    }
    
    else {
        return false;
    }
    return false;
}



