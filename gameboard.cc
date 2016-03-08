#include "gameboard.h"
#include "player.h"
#include "academic.h"
#include "residence.h"
#include "gyms.h"
#include "building.h"
#include "cltosap.h"
#include "coop.h"
#include "dctl.h"
#include "goose.h"
#include "gtt.h"
#include "nh.h"
#include "slc.h"
#include "tuition.h"
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;


GameBoard::GameBoard(int num_ply) {
    num_player = num_ply;
    cen_money = 0;
    num_double = 0;
    board = new Building*[40];
    players = new Player*[num_ply];
    roll_up_remains = 4;
}


GameBoard::~GameBoard() {
    for(int i=0;i<num_player;i++){
        delete players[i];
    }
    delete [] players;
    
    for(int i=0;i<40;i++){
        delete board[i];
    }
    delete [] board;
}


void GameBoard::setPlayers() {
    string ply_nm;
    char symb;
    bool symb_se[8];
    
    for (int i=0; i<8; i++)
    {
        symb_se[i]=false;
    }
    
    for (int i=0; i<num_player; i++)
    {
        cout << "Please enter the name of Player["<<i+1<<"]: ";
        cin >> ply_nm;
        cout << "Please select the symbol for Player["<<i+1<<"] from follwoing table: " << endl;
        cout << "-----------------------------------------------------------------------------------------------------" << endl;
        cout << "|Name   |Goose  |GRT Bus |Tim Hortons Doughnut   |Professor   |Student   |Money   |Laptop  |Pink tie|" << endl;
        cout << "-----------------------------------------------------------------------------------------------------" << endl;
        cout << "|Char   |   G   |   B    |         D             |      P     |    S     |   $    |    L   |   T    |" << endl;
        cout << "-----------------------------------------------------------------------------------------------------" << endl;
        
        while (cin >> symb)
        {
            if (symb == 'G' && !symb_se[0])
            {
                symb_se[0] = true;
                break;
            }
            else if (symb == 'B' && !symb_se[1])
            {
                symb_se[1] = true;
                break;
            }
            else if (symb == 'D' && !symb_se[2])
            {
                symb_se[2] = true;
                break;
            }
            else if (symb == 'P' && !symb_se[3])
            {
                symb_se[3] = true;
                break;
            }
            else if (symb == 'S' && !symb_se[4])
            {
                symb_se[4] = true;
                break;
            }
            else if (symb == '$' && !symb_se[5])
            {
                symb_se[5] = true;
                break;
            }
            else if (symb == 'L' && !symb_se[6])
            {
                symb_se[6] = true;
                break;
            }
            else if (symb == 'T' && !symb_se[7])
            {
                symb_se[7] = true;
                break;
            }
            else
            {
                cout<<"The symbol you selected is either invaild or used."<<endl;
                cout<<"Please reselect a symbol for Player["<<i+1<<"]: "<<endl;
            }
        }
        players[i] = new Player(ply_nm, symb, i);
        board[0]->enterb(players[i]);
    }
    cout << endl;
    cout << "-----------------------------------------------------------------------------------------------------" << endl;
    cout << "                                    *_* GAME START! READY GO! *_*                                    " << endl;
    cout << "-----------------------------------------------------------------------------------------------------" << endl;
    cout << players[0]->getPlayerName() << "'s turn:" << endl;
}


void GameBoard::init_board()
{
    board[0] = new Cltosap("COLLECT OSAP",0);
    board[1] = new Academic("AL",1,40,50,2,4,10,30,90,160,250);
    board[2] = new SLC("SLC",2);
    board[3] = new Academic("ML",3,60,50,4,8,20,60,180,320,450);
    board[4] = new Tuition("TUITUION",4);
    board[5] = new Residences("MKV",5,200,25,50,100,200);
    board[6] = new Academic("ECH",6,100,50,6,12,30,90,270,400,550);
    board[7] = new NH("NEEDLES HALL",7);
    board[8] = new Academic("PAS",8,100,50,6,12,30,90,270,400,550);
    board[9] = new Academic("HH",9,120,50,8,16,40,100,300,450,600);
    board[10] = new Dctl("DC Tims Line",10);
    board[11] = new Academic("RCH",11,140,100,10,20,50,150,450,625,750);
    board[12] = new Gyms("PAC",12,150);
    board[13] = new Academic("DWE",13,140,100,10,20,50,150,450,625,750);
    board[14] = new Academic("CPH",14,160,100,12,24,60,180,500,700,900);
    board[15] = new Residences("UWP",15,200,25,50,100,200);
    board[16] = new Academic("LHI",16,180,100,14,28,70,200,550,750,950);
    board[17] = new SLC("SLC",17);
    board[18] = new Academic("BMH",18,180,100,14,28,70,200,550,750,950);
    board[19] = new Academic("OPT",19,200,100,16,32,80,220,600,800,1000);
    board[20] = new Goose("Goose Nesting",20);
    board[21] = new Academic("EV1",21,220,150,18,36,90,250,700,875,1050);
    board[22] = new NH("NEEDLES HALL",22);
    board[23] = new Academic("EV2",23,220,150,18,36,90,250,700,875,1050);
    board[24] = new Academic("EV3",24,240,150,20,40,100,300,750,925,1100);
    board[25] = new Residences("V1",25,200,25,50,100,200);
    board[26] = new Academic("PHYS",26,260,150,22,44,110,330,800,975,1150);
    board[27] = new Academic("B1",27,260,150,22,44,110,330,800,975,1150);
    board[28] = new Gyms("CIF",28,150);
    board[29] = new Academic("B2",29,280,150,24,48,120,360,850,1025,1200);
    board[30] = new go_to_tims("GO TO TIMS",30);
    board[31] = new Academic("EIT",31,300,200,26,52,130,390,900,1100,1275);
    board[32] = new Academic("ESC",32,300,200,26,52,130,390,900,1100,1275);
    board[33] = new SLC("SLC",33);
    board[34] = new Academic("C2",34,320,200,28,56,150,450,1000,1200,1400);
    board[35] = new Residences("REV",35,200,25,50,100,200);
    board[36] = new NH("NEEDLES HALL",36);
    board[37] = new Academic("MC",37,350,200,35,70,175,500,1100,1300,1500);
    board[38] = new Coop("COOP FEE",38);
    board[39] = new Academic("DC",39,400,200,50,100,200,600,1400,1700,2000);
    board[39] = new Academic("DC",39,400,200,50,100,200,600,1400,1700,2000);
    
    board[30]->add_tim(board[10]);
    
    //add mono to each academic board:
    
    board[1]->add_mono(board[3]);//Arts1
    board[3]->add_mono(board[1]);
    
    board[6]->add_mono(board[8]);  //Arts2
    board[8]->add_mono(board[6]);
    board[6]->add_mono(board[9]);
    board[9]->add_mono(board[6]);
    board[9]->add_mono(board[8]);
    board[8]->add_mono(board[9]);
    
    board[11]->add_mono(board[13]);  //Eng
    board[13]->add_mono(board[11]);
    board[11]->add_mono(board[14]);
    board[14]->add_mono(board[11]);
    board[13]->add_mono(board[14]);
    board[14]->add_mono(board[13]);
    
    board[16]->add_mono(board[18]);  //Health
    board[18]->add_mono(board[16]);
    board[16]->add_mono(board[19]);
    board[19]->add_mono(board[16]);
    board[18]->add_mono(board[19]);
    board[19]->add_mono(board[18]);
    
    board[21]->add_mono(board[23]);  //Env
    board[23]->add_mono(board[21]);
    board[21]->add_mono(board[24]);
    board[24]->add_mono(board[21]);
    board[23]->add_mono(board[24]);
    board[24]->add_mono(board[23]);
    
    board[26]->add_mono(board[27]);  //Sci1
    board[27]->add_mono(board[26]);
    board[26]->add_mono(board[29]);
    board[29]->add_mono(board[26]);
    board[27]->add_mono(board[29]);
    board[29]->add_mono(board[27]);
    
    board[31]->add_mono(board[32]);  //Sci2
    board[32]->add_mono(board[31]);
    board[31]->add_mono(board[34]);
    board[34]->add_mono(board[31]);
    board[32]->add_mono(board[34]);
    board[34]->add_mono(board[32]);
    
    board[37]->add_mono(board[39]);  //Math
    board[39]->add_mono(board[37]);
    
    for (int i=0; i < 40; i++)
    {
        board[i]->addgame(this);
    }
}


void GameBoard::play(bool iftest)
{
    string cmd;
    int i = 0;
    bool rolled = false;
    int num_survier=0;
    int winner;
    while(1)
    {
    	num_survier=0;
    	for(int z=0;z<num_player;z++){
    		if(!players[z]->getBankrupt()){
    			num_survier++;
    		}
    	}
    	if(num_survier==1){
    		for(int z=0;z<num_player;z++){
    			if(!players[z]->getBankrupt()){
    				winner=z;
    			}
    		}
    		cout<<"Winner is "<<players[winner]->getPlayerName() << "! Congratulation!" << endl;
    		return;
    	}
    	if(players[i]->getPosition()==10&&!rolled){
    		rolled=board[players[i]->getPosition()]->line(players[i], iftest);
    	}
    	cin >> cmd;
        
    	if (cmd == "next")
    	{
    		if (rolled)
    		{
    			setDouble_num(0);
    			cout << players[i]->getPlayerName() << " ended this round." << endl;
    			cout << endl;
    			if (i == num_player-1) {i = 0;}
    			else {i++;}
                while(players[i]->getBankrupt()){
                    i++;
                    if (i == num_player) {i = 0;}
                }
    			cout << players[i]->getPlayerName() << "'s turn: ";
    			rolled = false;
    		} else {
    			cout << "You cannot enter 'next' immediately! Try other commands: ";
    			continue;
    		}
    	}
    	else if (cmd == "roll") {
    		if (!rolled)
    		{
    			rolled=true;
    			srand(time(NULL));
    			int roll1; int roll2;
// not test: uncomment ###########################################################################
                if(!iftest){
                	roll1 = rand()%6 + 1;
                	roll2 = rand()%6 + 1;
                }
                

//test start #####################################################################################
                else{
                	cin>>roll1;
                	cin>>roll2;
                }
//test end #######################################################################################
                cout << players[i]->getPlayerName() << " rolled a " << roll1 << " and a " << roll2 << "." << endl;
                
                int new_pos=players[i]->getPosition() + roll1+roll2;
                if(new_pos < 0){
                    new_pos=new_pos+40;
                }
                if(new_pos>40){
                	cout << players[i]->getPlayerName() << "passed OSAP, get $200!"<<endl;
                	players[i]->setCash(200);
                }
                
                if(roll1==roll2)  addDouble_num();

                if(!(getDouble_num() >= 3)){
                	cout << players[i]->getPlayerName() << " landed on " << board[new_pos % 40]->getBuildingName() << "." << endl;
                	board[players[i]->getPosition()]->leave(players[i]);
                	players[i]->setPosition(new_pos % 40);
                	board[players[i]->getPosition()]->enter(players[i]);
                	prboard();
                }

                if ((roll1 == roll2)&&!(getDouble_num() >= 3))
                {
                    cout << players[i]->getPlayerName() << "rolls double. Please roll again: ";
                    rolled = false;
                }
                if (getDouble_num() >= 3) {
                    
                    board[players[i]->getPosition()]->leave(players[i]);
                    players[i]->setPosition(30);
                    board[players[i]->getPosition()]->enter(players[i]);
                    prboard();
                    
                    rolled=true;
                    setDouble_num(0);
                    cout << players[i]->getPlayerName() << " has been sent to DC Tims Line since you rolled double for 3 times." << endl;
                    cout << "End of the Roll." << endl;
                }
            }
            else
            {
                cout << "You have rolled. Try other commands: ";
                cin.clear();
                cin.ignore();
                setDouble_num(0);
            }
        }
        else if (cmd == "quit")
        {
            return;
        }
        
        else if (cmd == "trade") {
            string name;
            int give;
            int receive;
            cin >> name;
            cin >> give;
            
            if (cin.fail())
            {
                string give2;
                cin.clear();
                cin >> give2;
                cin >> receive;
                if (cin.fail())
                {
                    string receive2;
                    cin.clear();
                    cin >> receive2;
                    trade(i, name, give2, receive2);
                }
                else
                {
                    trade(i, name, give2, receive);
                }
            }
            else
            {
                cin >> receive;
                if (cin.fail()) {
                    string receive2;
                    cin.clear();
                    cin >> receive2;
                    trade(i, name, give, receive2);
                }
                else
                {
                    trade(i, name, give, receive);
                }
            }
        }
        else if (cmd == "improve")
        {
            string property;
            string action;
            cin >> property;
            cin >> action;
            improve(i, property, action);
        }
        
        else if (cmd == "mortgage")
        {
            string property;
            cin >> property;
            mortgage(property, i);
        }
        else if (cmd == "ummortgage") {
            string property;
            cin >> property;
            unmortgage(property, i);
        }
        else if (cmd == "bankrupt")
        {
            players[i]->setBankrupt();
        }
        
        else if (cmd == "assets")
        {
            cout << players[i]->getPlayerName() << "'s assets: $" << players[i]->getTotal() << endl;
            cout << "Cash: $" << players[i]->getCash() << endl;
            
            for (int k=0; k<40; k++)
            {
                if (board[k]->getHoldername() == players[i]->getPlayerName())
                {
                    cout << board[k]->getBuildingName() << ": ";
                    cout << board[k]->getImprvLevel() << "level(s)" << endl;
                }
            }
        }
        else if (cmd == "save") {
            string filename;
            cin >> filename;
            save(filename);
            continue;
        }
        else
        {
        	cout<<"Invalid input, try other commands: ";
        	cin.clear();
        	cin.ignore();
        }
        
        while(players[i]->getCash()<0&&!players[i]->getBankrupt())
        {
        	cout << "Your balance is negative, choose 'trade' or 'mortgage' or 'banktrupt': ";
        	string tmp;
        	cin>>tmp;
        	if(tmp=="trade")
        	{
        		string name;
        		int give;
        		int receive;
        		cin >> name;
        		cin >> give;

        		if (cin.fail())
        		{
        			string give2;
        			cin.clear();
        			cin >> give2;
        			cin >> receive;
        			if (cin.fail())
        			{
        				string receive2;
        				cin.clear();
        				cin >> receive2;
        				trade(i, name, give2, receive2);
        			}
        			else
        			{
        				trade(i, name, give2, receive);
        			}
        		}
        		else
        		{
        			cin >> receive;
        			if (cin.fail()) {
        				string receive2;
        				cin.clear();
        				cin >> receive2;
        				trade(i, name, give, receive2);
        			}
        			else
        			{
        				trade(i, name, give, receive);
        			}
        		}
        	}else if(tmp=="mortgage"){
        		string property;
        		cin >> property;
        		mortgage(property, i);
        	}else if(tmp=="banktrupt"){
        		players[i]->setBankrupt();
        		bankrupt(players[i]);
                cout<<players[i]->getPlayerName()<<"'s turn is ended."<<endl;
                while(players[i]->getBankrupt()){
                    i++;
                    if (i == num_player) {i = 0;}
                }
                cout<<players[i]->getPlayerName()<<"'s turn: "<<endl;
                rolled = false;
        		break;
        	}else{
        		cout<<"Invalid input, try other commands: ";
        		cin.clear();
        		cin.ignore();
        	}
        }
    }
}


void GameBoard::jump(Player *ppl){
    board[ppl->getPosition()]->enter(ppl);
}


void GameBoard::prboard(){
    cout << "_________________________________________________________________________________________" << endl;
    
    cout << "|Goose  |"<<board[21]->getOwnership();
    cout << " " << board[21]->getImprv();
    cout << "|NEEDLES|" << board[23]->getOwnership();
    cout << " " << board[23]->getImprv();
    cout << "|" << board[24]->getOwnership();
    cout << " " << board[24]->getImprv();
    cout << "|V1     |" << board[26]->getOwnership();
    cout << " " << board[26]->getImprv();
    cout << "|" << board[27]->getOwnership();
    cout << " " << board[27]->getImprv();
    cout << "|CIF    |" << board[29]->getOwnership();
    cout << " " << board[29]->getImprv();
    cout << "|GO TO  |" << endl;
    
    cout << "|Nesting|-------|HALL   |-------|-------|" << board[25]->getOwnership();
    cout << "      |-------|-------|" << board[28]->getOwnership();
    cout << "      |-------|TIMS   |" << endl;
    
    cout << "|       |EV1    |       |EV2    |EV3    |       |PHYS   |B1     |       |B2     |       |" << endl;
    
    cout << "|" << board[20]->getPlayerHere();
    cout << " |" << board[21]->getPlayerHere();
    cout << " |" << board[22]->getPlayerHere();
    cout << " |" << board[23]->getPlayerHere();
    cout << " |" << board[24]->getPlayerHere();
    cout << " |" << board[25]->getPlayerHere();
    cout << " |" << board[26]->getPlayerHere();
    cout << " |" << board[27]->getPlayerHere();
    cout << " |" << board[28]->getPlayerHere();
    cout << " |" << board[29]->getPlayerHere();
    cout << " |" << board[30]->getPlayerHere();
    cout << " |" << endl;
    
    cout << "|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|" << endl;
    
    cout << "|" << board[19]->getOwnership();
    cout << " " << board[19]->getImprv();
    cout << "|                                                                       |" << board[31]->getOwnership();
    cout << " " << board[31]->getImprv();
    cout << "|" << endl;
    
    cout << "|-------|                                                                       |-------|" << endl;
    cout << "|OPT    |                                                                       |EIT    |" << endl;
    
    cout << "|"<<board[19]->getPlayerHere();
    cout << " |                                                                       |" << board[31]->getPlayerHere();
    cout << " |" << endl;
    
    cout << "|_______|                                                                       |_______|" << endl;
    
    cout << "|" << board[18]->getOwnership();
    cout << " " << board[18]->getImprv();
    cout << "|                                                                       |" << board[32]->getOwnership();
    cout << " " << board[32]->getImprv();
    cout << "|" << endl;
    
    cout << "|-------|                                                                       |-------|" << endl;
    cout << "|BMH    |                                                                       |ESC    |" << endl;
    
    cout << "|" << board[18]->getPlayerHere();
    cout << " |                                                                       |" << board[32]->getPlayerHere();
    cout << " |" << endl;
    
    cout << "|_______|                                                                       |_______|" << endl;
    cout << "|SLC    |                                                                       |SLC    |" << endl;
    cout << "|       |                                                                       |       |" << endl;
    cout << "|       |                                                                       |       |" << endl;
    
    cout << "|" << board[17]->getPlayerHere();
    cout << " |                                                                       |";
    cout << board[33]->getPlayerHere();
    cout << " |" << endl;
    
    cout << "|_______|                                                                       |_______|" << endl;
    cout << "|"<<board[16]->getOwnership();
    cout << " " << board[16]->getImprv();
    cout << "|                                                                       |" << board[34]->getOwnership();
    cout << " " << board[34]->getImprv();
    cout << "|" << endl;
    
    cout << "|-------|                                                                       |-------|" << endl;
    cout << "|LHI    |                                                                       |C2     |" << endl;
    cout << "|" << board[16]->getPlayerHere();
    cout << " |               _________________________________________               |" << board[34]->getPlayerHere();
    cout << " |" << endl;
    
    cout << "|_______|               |                                       |               |_______|" << endl;
    cout << "|UWP    |               | ###   ###   #####  ###   ###   ###    |               |REV    |" << endl;
    cout << "|" << board[15]->getOwnership();
    cout << "      |               | #  #  #  #     #  #   # #   # #   #   |               |" << board[35]->getOwnership();
    cout << "      |" << endl;
    
    cout << "|       |               | ####  ####    #   #   # #   # #   #   |               |       |" << endl;
    cout << "|" << board[15]->getPlayerHere();
    cout << " |               | #   # #   #  #    #   # #   # #   #   |               |" <<board[35]->getPlayerHere();
    cout << " |" << endl;
    
    cout << "|_______|               | ####  ####  #      ###   ###   ###    |               |_______|" << endl;
    cout << "|" << board[14]->getOwnership();
    cout << "      |               |_______________________________________|               |NEEDLES|" << endl;
    cout << "|-------|                                                                       |HALL   |" << endl;
    cout << "|CPH    |                                                                       |       |" << endl;
    
    cout << "|" << board[14]->getPlayerHere();
    cout << " |                                                                       |" << board[36]->getPlayerHere();
    cout << " |" << endl;
    
    cout << "|_______|                                                                       |_______|" << endl;
    cout << "|" << board[13]->getOwnership();
    cout << " " << board[13]->getImprv();
    cout << "|                                                                       |" << board[37]->getOwnership();
    cout << " " << board[37]->getImprv();
    cout << "|" << endl;
    
    cout << "|-------|                                                                       |-------|" << endl;
    cout << "|DWE    |                                                                       |MC     |" << endl;
    cout << "|" << board[13]->getPlayerHere();
    cout << " |                                                                       |" << board[37]->getPlayerHere();
    cout << " |" << endl;
    
    cout << "|_______|                                                                       |_______|" << endl;
    cout << "|PAC    |                                                                       |COOP   |" << endl;
    cout << "|" << board[12]->getOwnership();
    cout << "      |                                                                       |FEE    |" << endl;
    cout << "|       |                                                                       |       |" << endl;
    cout << "|" << board[12]->getPlayerHere();
    cout << " |                                                                       |" << board[38]->getPlayerHere();
    cout << " |" <<endl;
    
    cout << "|_______|                                                                       |_______|" << endl;
    cout << "|" << board[11]->getOwnership();
    cout << " " << board[11]->getImprv();
    cout << "|                                                                       |" << board[39]->getOwnership();
    cout << " " << board[39]->getImprv();
    cout << "|" << endl;
    
    cout << "|-------|                                                                       |-------|" << endl;
    cout << "|RCH    |                                                                       |DC     |" << endl;
    cout << "|" << board[11]->getPlayerHere();
    cout << " |                                                                       |" << board[39]->getPlayerHere();
    cout << " |" << endl;
    
    cout << "|_______|_______________________________________________________________________|_______|" << endl;
    
    cout << "|DC Tims|" << board[9]->getOwnership();
    cout << " " << board[9]->getImprv();
    cout << "|" << board[8]->getOwnership();
    cout << " " << board[8]->getImprv();
    cout << "|NEEDLES|" << board[6]->getOwnership();
    cout << " " << board[6]->getImprv();
    cout << "|MKV    |TUITION|" << board[3]->getOwnership();
    cout << " " << board[3]->getImprv();
    cout << "|SLC    |" << board[1]->getOwnership();
    cout << " " << board[1]->getImprv();
    cout << "|COLLECT|" << endl;
    
    cout << "|Line   |-------|-------|HALL   |-------|" << board[5]->getOwnership();
    cout << "      |       |-------|       |-------|OSAP   |" << endl;
    
    cout << "|       |HH     |PAS    |       |ECH    |       |       |ML     |       |AL     |       |" << endl;
    cout << "|" << board[10]->getPlayerHere();
    cout << " |" << board[9]->getPlayerHere();
    cout << " |" << board[8]->getPlayerHere();
    cout << " |" << board[7]->getPlayerHere();
    cout << " |" << board[6]->getPlayerHere();
    cout << " |" << board[5]->getPlayerHere();
    cout << " |" << board[4]->getPlayerHere();
    cout << " |" << board[3]->getPlayerHere();
    cout << " |" << board[2]->getPlayerHere();
    cout << " |" << board[1]->getPlayerHere();
    cout << " |" << board[0]->getPlayerHere();
    cout << " |" << endl;
    
    cout << "|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|" << endl;
}



void GameBoard::auction(Building *bd)
{
    int i = 0;
    int num_pl = num_player;
    int price = 0;
    bool plstat[num_player];
    
    for (int t=0; t<num_player; t++)
    {
        plstat[t] = true;
    }
    while (num_pl != 1)
    {
        if (plstat[i])
        {
            cout << players[i]->getPlayerName() << ", how much you want to pay for "<<bd->getBuildingName()<<" or enter '0' to quit: ";
            int tmp_pri;
            
            while (cin >> tmp_pri)
            {
                if (tmp_pri == 0)
                {
                    cout << players[i]->getPlayerName() << ", you quit!" << endl;
                    plstat[i] = false;
                    num_pl--;
                    break;
                }
                else if (players[i]->getCash() < tmp_pri) {
                    cout << players[i]->getPlayerName() << ", your cash is not enough, you can bid again: ";
                    continue;
                }
                else if (tmp_pri <= price)
                {
                    cout << "Price must be higher than previous one, you can bid again: ";
                    cin.clear();
                    cin.ignore();
                }
                else if (players[i]->getCash() >= tmp_pri)
                {


                    price = tmp_pri;
                    cout << players[i]->getPlayerName() << ", you bid success!" << endl;
                    break;
                }
            }
        }
        
        i++;
        
        if (i == num_player)
        {
            i=0;
        }
    }
    
    int winner = 0;
    
    for (int t=0; t<num_player; t++)
    {
        if (plstat[t])
        {
            winner = t;
        }
    }


    if (bd->getBuildingName() == "MKV" ||
        bd->getBuildingName() == "UWP" ||
        bd->getBuildingName() == "V1" ||
        bd->getBuildingName() == "REV") {
        players[winner]->setNumRez(1);
    }

    if (bd->getBuildingName() == "PAC" ||
        bd->getBuildingName() == "CIF") {
        players[winner]->setNumGym(1);
    }


    cout << players[winner]->getPlayerName() << ", you paid $" << price << " and you win the bid!" << endl;
    players[winner]->setCash(-price);
    players[winner]->setTotal(bd->getPurchCost());
    bd->setPlayer(players[winner]);
    bd->setBought(true);
    bd->setOwnship(players[winner]->getSymbol());
}



void GameBoard::trade(int tryer, string decider, int gvemoney, string bdname){
    
    int rever = 0;
    int bud = 0;
    bool ifrecbd = false;
    bool ifhavepl = false;
    for (int i=0; i<num_player; i++)
    {
        if (decider == players[i]->getPlayerName())
        {
            rever = i;
            ifhavepl = true;
            break;
        }
    }
    
    for (int i=0; i<40; i++)
    {
        if (bdname == board[i]->getBuildingName())
        {
            bud = i;
            ifrecbd = true;
            break;
        }
    }
    if (board[bud]->getImprvLevel() != 0) {
        cout << board[bud]->getBuildingName() << " can't be improved. The building is not in monopoly." << endl;
        return;
    }
    
    if (!ifhavepl)
    {
        cout << "No such player." << endl;
        return;
    }
    if (!ifrecbd)
    {
        cout << "No such building." << endl;
        return;
    }
    if (board[bud]->getHoldername() != decider)
    {
        cout << "(S)he doesn't have this building." << endl;
        return;
    }
    
    if(!board[bud]->tradeable()){
    	cout<<board[bud]->getBuildingName()<<" can't be traded."<<endl;
    	return;
    }




    cout << "Would you want to trade with him? (y/n): ";
    string cmd;
    
    while (cin >> cmd) {
        if (cmd == "y")
        {
            cout << "Treaded" << endl;
            players[tryer]->setCash(-gvemoney);
            players[tryer]->setTotal(board[bud]->getPurchCost());
            players[rever]->setCash(gvemoney);
            players[rever]->setTotal(-board[bud]->getPurchCost());
            board[bud]->setOwnship(players[tryer]->getSymbol());
            board[bud]->setPlayer(players[tryer]);
            
            if (board[bud]->getBuildingName() == "MKV" ||
                board[bud]->getBuildingName() == "UWP" ||
                board[bud]->getBuildingName() == "V1" ||
                board[bud]->getBuildingName() == "REV") {
                players[tryer]->setNumRez(-1);
                players[rever]->setNumRez(1);
            }
            
            if (board[bud]->getBuildingName() == "PAC" ||
                board[bud]->getBuildingName() == "CIF") {
                players[tryer]->setNumGym(-1);
                players[rever]->setNumGym(1);
            }
            
            break;
        }
        else if (cmd == "n")
        {
            cout << "Refused" << endl;
            break;
        }
        else
        {
            cout << "Invalid input, try other commands: ";
            cin.clear();
            cin.ignore();
        }
    }
}


void GameBoard::trade(int tryer, string decider, string gvebuild, string getbuild){
    int rever = 0;
    int gvbd = 0;
    int getbd = 0;
    bool ifrecbd = false;
    bool ifgvebd = false;
    bool ifhavepl = false;
    for (int i=0; i<num_player; i++)
    {
        if (decider == players[i]->getPlayerName())
        {
            rever = i;
            ifhavepl = true;
            break;
        }
    }
    for (int i=0; i<40; i++)
    {
        if (gvebuild == board[i]->getBuildingName())
        {
            gvbd = i;
            ifgvebd = true;
        }
        if (getbuild == board[i]->getBuildingName())
        {
            getbd = i;
            ifrecbd = true;
        }
    }
    
    if (board[getbd]->getImprvLevel() != 0
        || board[gvbd]->getImprvLevel() != 0) {
        cout << board[getbd]->getBuildingName()<<" or "<<board[gvbd]->getBuildingName() << " can't be traded. The building has been improved or mortgaged." << endl;
        return;
    }
    
    if (!ifhavepl)
    {
        cout << "No such player." << endl;
        return;
    }
    if (!ifrecbd)
    {
        cout << "No such recevie building." << endl;
        return;
    }
    if (!ifgvebd)
    {
        cout << "No such give building." << endl;
        return;
    }
    if (board[getbd]->getHoldername() != decider)
    {
        cout << "S(h)e doesn't have this building." << endl;
        return;
    }
    if (board[gvbd]->getHoldername() != players[tryer]->getPlayerName())
    {
        cout << "You don't have this building." << endl;
        return;
    }
    
    if(!board[getbd]->tradeable()){
    	cout<<board[getbd]->getBuildingName()<<" can't be traded."<<endl;
    	return;
    }

    if(!board[gvbd]->tradeable()){
    	cout<<board[gvbd]->getBuildingName()<<" can't be traded."<<endl;
    	return;
    }

    cout << "Do you want to trade with him? (y/n): ";
    string cmd;
    
    while (cin >> cmd)
    {
        if (cmd == "y")
        {
            cout << "Treaded" << endl;
            board[getbd]->setOwnship(players[tryer]->getSymbol());
            board[getbd]->setPlayer(players[tryer]);
            board[gvbd]->setOwnship(players[rever]->getSymbol());
            board[gvbd]->setPlayer(players[rever]);
            
            if (board[gvbd]->getBuildingName() == "MKV" ||
                board[gvbd]->getBuildingName() == "UWP" ||
                board[gvbd]->getBuildingName() == "V1" ||
                board[gvbd]->getBuildingName() == "REV") {
                players[tryer]->setNumRez(-1);
                players[rever]->setNumRez(1);
            }
            
            if (board[gvbd]->getBuildingName() == "PAC" ||
                board[gvbd]->getBuildingName() == "CIF") {
                players[tryer]->setNumGym(-1);
                players[rever]->setNumGym(1);
            }
            
            
            if (board[getbd]->getBuildingName() == "MKV" ||
                board[getbd]->getBuildingName() == "UWP" ||
                board[getbd]->getBuildingName() == "V1" ||
                board[getbd]->getBuildingName() == "REV") {
                players[rever]->setNumRez(-1);
                players[tryer]->setNumRez(1);
            }
            
            if (board[getbd]->getBuildingName() == "PAC" ||
                board[getbd]->getBuildingName() == "CIF") {
                players[rever]->setNumGym(-1);
                players[tryer]->setNumGym(1);
            }
            
            break;
        }
        else if (cmd == "n")
        {
            cout << "Refused" << endl;
            break;
        }
        else{
            cout<<"Invalid input, try other commands: ";
            cin.clear();
            cin.ignore();
        }
    }
}


void GameBoard::trade(int tryer,string decider,string gvebuild, int recmoney){
    int rever = 0;
    int bud = 0;
    bool ifgvebd = false;
    bool ifhavepl = false;
    for (int i=0; i<num_player; i++)
    {
        if (decider == players[i]->getPlayerName())
        {
            rever = i;
            ifhavepl = true;
            break;
        }
    }
    
    for(int i=0; i<40; i++)
    {
        if (gvebuild == board[i]->getBuildingName())
        {
            bud = i;
            ifgvebd = true;
            break;
        }
    }
    
    if (board[bud]->getImprvLevel() != 0) {
        cout << board[bud]->getBuildingName() << " can't be traded. The building has been improved or mortgaged." << endl;
        return;
    }
    
    if (!ifhavepl)
    {
        cout << "No such player." << endl;
        return;
    }
    if (!ifgvebd)
    {
        cout << "No such building." << endl;
        return;
    }
    if (board[bud]->getHoldername() != players[tryer]->getPlayerName())
    {
        cout << "You don't have such building." << endl;
        return;
    }

    if(!board[bud]->tradeable()){
    	cout<<board[bud]->getBuildingName()<<" can't be traded."<<endl;
    	return;
    }


    cout << "Do you want to trade with him? (y/n): ";
    string cmd;
    
    while (cin >> cmd)
    {
        if (cmd == "y")
        {
            cout << "Treaded" << endl;
            players[rever]->setCash(-recmoney);
            players[rever]->setTotal(board[bud]->getPurchCost());
            players[tryer]->setCash(recmoney);
            players[tryer]->setTotal(-board[bud]->getPurchCost());
            board[bud]->setOwnship(players[rever]->getSymbol());
            board[bud]->setPlayer(players[rever]);
            
            if (board[bud]->getBuildingName() == "MKV" ||
                board[bud]->getBuildingName() == "UWP" ||
                board[bud]->getBuildingName() == "V1" ||
                board[bud]->getBuildingName() == "REV") {
                players[tryer]->setNumRez(-1);
                players[rever]->setNumRez(1);
            }
            
            if (board[bud]->getBuildingName() == "PAC" ||
                board[bud]->getBuildingName() == "CIF") {
                players[tryer]->setNumGym(-1);
                players[rever]->setNumGym(1);
            }
            
            break;
        }
        else if (cmd == "n")
        {
            cout << "Refused" << endl;
            break;
        }
        else
        {
            cout << "Invalid input, try other commands: ";
            cin.clear();
            cin.ignore();
        }
    }
}

void GameBoard::trade(int tryer,string decider,int gvemoney, int recmoney){
    int rever = 0;
    bool ifhavepl = false;
    
    for (int i=0; i<num_player; i++)
    {
        if (decider == players[i]->getPlayerName())
        {
            rever = i;
            ifhavepl = true;
            break;
        }
    }
    
    if (!ifhavepl) {
        cout << "No such player." << endl;
        return;
    }
    
    cout << "Would you want to trade with him? (y/n): ";
    string cmd;
    
    while (cin >> cmd)
    {
        if (cmd == "y")
        {
            cout<<"Treaded"<<endl;
            players[tryer]->setCash(-gvemoney);
            players[tryer]->setCash(recmoney);
            players[rever]->setCash(-recmoney);
            players[rever]->setCash(gvemoney);
            break;
        }else if(cmd=="n"){
            cout<<"Refused"<<endl;
            break;
        }else{
            cout<<"Invalid input, try other commands: "<<endl;
            cin.clear();
            cin.ignore();
        }
    }
}

void GameBoard::improve(int plindex, string bdname, string action){
    int bdin = 0;
    bool ifbd = false;
    for (int i=0; i<40; i++)
    {
        if (board[i]->getBuildingName() == bdname)
        {
            ifbd = true;
            bdin = i;
        }
    }
    if (!ifbd)
    {
        cout << "No such building." << endl;
        return;
    }
    
    if (!board[bdin]->getMono())
    {
       cout << board[bdin]->getBuildingName() << " can't be traded. The building has been improved or mortgaged." << endl;
        return;
    }
    if (board[bdin]->getHoldername() != players[plindex]->getPlayerName())
    {
        cout << "Building doesn't belong to you." << endl;
        return;
    }
    
    int imprv_level_now = board[bdin]->getImprvLevel();
    
    if (action == "buy" && imprv_level_now < 5)
    {
        board[bdin]->improveBuy();
        imprv_level_now++;
        board[bdin]->setImprLevel(imprv_level_now);
        
        cout << board[bdin]->getBuildingName() << " has been improved to ";
        cout << board[bdin]->getImprvLevel() << " level(s)." <<endl;
    }
    else if (action == "sell" && imprv_level_now > 0)
    {
        board[bdin]->improveSell();
        
        imprv_level_now--;
        board[bdin]->setImprLevel(imprv_level_now);
        
        cout<<"Degraded"<<endl;
    }
    else
    {
        cout << "Invalid action buy/sell" << endl;
    }
}


void GameBoard::mortgage(string bdname, int player_index) {
    int bdin = 0;
    
    for (int i=0; i<40; i++)
    {
        if (board[i]->getBuildingName() == bdname)
        {
            bdin = i;
        }
    }
    
    if (players[player_index]->getPlayerName() != board[bdin]->getHoldername())
    {
        cout << "The property is not owned to you." << endl;
        return;
    }
    else if (board[bdin]->getImprvLevel() == -1) {
        cout << "The building had mortgaged as before." << endl;
    }
    else if (board[bdin]->getImprvLevel() != 0) {
        cout << "You must sold the improvements before mortgage the building." << endl;
        return;
    }
    
    board[bdin]->setMort(true);
    
    int mortgage_fee = board[bdin]->getPurchCost() / 2;
    
    players[player_index]->setCash(mortgage_fee);
    cout << "Mortgage is successful." << endl;
    
    board[bdin]->setImprLevel(-1);
    
}


void GameBoard::unmortgage(std::string bdname, int player_index){
    int bdin = 0;
    
    for (int i=0; i<40; i++)
    {
        if (board[i]->getBuildingName() == bdname){
            bdin = i;
        }
    }
    
    if (board[bdin]->getImprvLevel() != -1) {
        cout << "The buiding has not been mortgaged as before." << endl;
        return;
    }
    
    int unmortgage_fee = (board[bdin]->getPurchCost() * 1.1) / 2;

    
    if (players[player_index]->getCash() >= unmortgage_fee &&
        players[player_index]->getPlayerName() == board[bdin]->getHoldername())
    {
        board[bdin]->setMort(false);
        
        players[player_index]->setCash(-unmortgage_fee);
        
        board[bdin]->setImprLevel(0);
        cout << "Unmortgage successful." << endl;
        
    }
    else {
        cout << "The property is not owned to you OR The Cash is not enough." << endl;
        cout << "Unmortgage is unsuccessful." << endl;
    }
}

void GameBoard::bankrupt(Player *p) {
	if(board[p->getPosition()]->getBought()){
		board[p->getPosition()]->getHolder()->setCash(p->getCash());

		for(int i =0; i < 40; i++){
			if(board[i]->getHoldername()==p->getPlayerName()){
				board[p->getPosition()]->getHolder()->setTotal(board[i]->getPurchCost());
				board[i]->setPlayer(board[p->getPosition()]->getHolder());
				board[i]->setOwnship(board[p->getPosition()]->getHolder()->getSymbol());
                if (board[i]->getImprvLevel() == -1) {
                    cout << "You should pay 10% when you reveiving the mortgage properties." << endl;

                    board[p->getPosition()]->getHolder()->setCash((board[i]->getPurchCost() / 2) * (-0.1));

                    cout << "Do you want to unmortgage immediately? (y/n): ";
                    char ans;
                    cin >> ans;
                    
                    if (cin.fail()) {
                        cout << "Invaild input, try other commands: ";
                        cin.clear();
                        cin.ignore();
                    }
                    else if(ans == 'y'){
                        board[p->getPosition()]->getHolder()->setCash((board[i]->getPurchCost() / 2) * (-1.1));
                        board[i]->setMort(false);
                        board[i]->setImprLevel(0);

                    }
                    else {
                        board[p->getPosition()]->getHolder()->setCash((board[i]->getPurchCost() / 2) * (-0.1));
                    }
                }
			}
		}
	}else{
		for(int i =0; i < 40; i++){
			if(board[i]->getHoldername()==p->getPlayerName()){
				this->auction(board[i]);
			}
		}
	}
	p->setBankrupt();
}




int GameBoard::getDouble_num() {
    return num_double;
}


void GameBoard::addDouble_num(){
    num_double++;
}
void GameBoard::setDouble_num(int i){
    num_double = i;
}



int GameBoard::getnum_player(){
    return num_player;
}


void GameBoard::save(string filename) {
    ofstream write;
    write.open(filename.c_str());
    write << getnum_player() << endl;
    
    for (int i = 0; i < getnum_player(); i++) {
        if (!players[i]->getBankrupt()) {
            write << players[i]->getPlayerName();
            write << " " << players[i]->getSymbol();
            write << " " << players[i]->getRoll();
            write << " " << players[i]->getCash();
            write << " " << players[i]->getPosition();
            if (players[i]->getPosition() == 10) {
                if (players[i]->getJump()) {
                    write << " 1 " << players[i]->getTim();
                }
            }
            write<<endl;
        }
    }
    
    for(int j = 0; j < 40; j++) {
        if (board[j]->getBought()) {
            write << board[j]->getBuildingName();
            write << " " <<  board[j]->getHoldername();
            write << " " << board[j]->getImprvLevel() << endl;
        }
        else if(board[j]->getOwnable()) {
            write << board[j]->getBuildingName();
            write << " BANK";
            write << " " << board[j]->getImprvLevel() << endl;
        }
    }
    
    write.close();
    
    cout << "Save successful." << endl;
    
}


void GameBoard::change_num_play(int n){
    num_player=n;
    delete [] players;
    players=new Player*[num_player];
}


void GameBoard::loadfile(string filename){
    string line;
    ifstream myfile(filename.c_str());
    getline(myfile,line);
    int numpl;
    istringstream ss(line);
    ss>>numpl;
    change_num_play(numpl);
    string name; char symbol; int TimsCups; int money; int position; int iftim; int round;
    for(int t=0;t<numpl;t++){
        getline(myfile,line);
        istringstream ss(line);
        ss>>name>>symbol>>TimsCups>>money>>position;
        players[t]=new Player(name,symbol,t);
        players[t]->setPosition(position);
        board[position]->enterb(players[t]);
        players[t]->setCash(money-1500);
        players[t]->setRoll(TimsCups);
        if(position==10){
            ss>>iftim;
            if(iftim==1){
                players[t]->setJump(true);
                ss>>round;
                players[t]->setTim(round);
            }
        }
    }
    int bdindex=0;
    while(getline(myfile,line)){
        istringstream ss(line);
        string buildingname; string holdername; int implvl;
        ss>>buildingname>>holdername>>implvl;
        int i;
        if(holdername!="BANK"){
            for(int t=0;t<numpl;t++){
                if(players[t]->getPlayerName()==holdername){
                    i=t;
                }
            }
            for(int t=0;t<40;t++){
            	if(board[t]->getBuildingName()==buildingname){
            		bdindex=t;
            		break;
            	}
            }
            board[bdindex]->setPlayer(players[i]);
            board[bdindex]->setOwnship(players[i]->getSymbol());
            players[i]->setTotal(board[bdindex]->getPurchCost());
            if(implvl==-1){
                board[bdindex]->setMort(true);
                board[bdindex]->setImprLevel(-1);
            }else if(implvl>0){
                for(int z=0;z<implvl;z++){
                    board[bdindex]->improveBuy_load();
                }
            }
            if(buildingname=="MKV" || buildingname=="UWP" || buildingname=="V1" || buildingname=="REV"){
            	players[i]->setNumRez(1);
            }
            if(buildingname=="PAC" || buildingname=="CIF"){
            	players[i]->setNumGym(1);
            }
        }
    }
    cout << "-----------------------------------------------------------------------------------------------------" << endl;
    cout << "                                    *_* GAME LOADED! READY GO! *_*                                   " << endl;
    cout << "-----------------------------------------------------------------------------------------------------" << endl;
    prboard();    
    cout << players[0]->getPlayerName() << "'s turn: ";
    //prboard();
}

void GameBoard::setRoll_up_remains(int i){
	roll_up_remains = roll_up_remains + i;
}


int GameBoard::getRoll_up_remains(){
	return roll_up_remains;
}


