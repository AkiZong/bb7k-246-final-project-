#include "slc.h"
#include "gameboard.h"
#include "player.h"
#include <ctime>
#include <cstdlib>

using namespace std;

SLC::SLC(string name, int i): Unownable(name, i) {}


void SLC::enter(Player *p){
    srand(time(NULL));
    int tmp = rand()%24+1;
    
    if (tmp == 24){
        cout << "SLC: Collect OSAP" << endl;
        p->setPosition(0);
        game->jump(p);
    }
    
    else if (tmp == 23){
        cout<<"Jump to DC Tims"<<endl;
        p->setPosition(10);
        p->setJump(true);
        game->jump(p);
    }
    
    else if (tmp >= 19){
        cout<<"SLC: Forward 3"<<endl;
        p->setPosition(getIndex()+3);
        game->jump(p);
    }
    
    else if (tmp >= 15){
        cout<<"SLC: Forward 2"<<endl;
        p->setPosition(getIndex()+2);
        game->jump(p);
    }
    
    else if (tmp >= 12){
        cout<<"SLC: Forward 1"<<endl;
        p->setPosition(getIndex()+1);
        game->jump(p);
    }
    
    else if (tmp >= 8){
        cout<<"SLC: backward 1"<<endl;
        p->setPosition(getIndex()-1);
        game->jump(p);
    }
    
    else if (tmp >= 4){
        cout<<"SLC: backward 2"<<endl;
        p->setPosition(getIndex()-2);
        game->jump(p);
    }
    
    else{
        cout<<"SLC: backward 3"<<endl;
        int new_pos=getIndex()-3;
        if(new_pos<0){
            new_pos=new_pos+40;
        }
        p->setPosition(new_pos);
        game->jump(p);
    }
    
    // Getting Roll Up Rim Cup
    
    srand(time(NULL));
    int chance =rand()%100;
    
    if (chance == 1 && game->getRoll_up_remains() > 0) {
        cout <<"SLC: get a Roll Up The Rim Cup" << endl;
        p->setRoll(1);
        game->setRoll_up_remains(-1);
    }
}


void SLC::leave(Player *ppl){
    NumPlayer--;
    PlayerHere[ppl->getIndex()] =' ';
}



