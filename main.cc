#include <iostream>
#include <string>
#include "gameboard.h"
#include "building.h"
#include "ownable.h"
#include "unownable.h"
#include "academic.h"
#include "residence.h"
#include "gyms.h"

using namespace std;

int main(int argc, char* argv[]) {
    int num_ply;
    string filename;
    bool ifload = false;
    bool iftest = false;
    if (argc == 2){
    	string cmd1 = argv[1];
    	if(cmd1 == "-test"){
    		iftest=true;
    	}else if(cmd1 == "-load"){
    		cout<<"There must be a filename following -load."<<endl;
    	}else{
    		cout<<"Invalid input: try other commadns: "<<endl;
    	}
    }else if(argc == 1){
        cout<<"Normal game started!"<<endl;
    }
    else if(argc == 3){
    	string cmd1 = argv[1];
    	string cmd2 = argv[2];
    	if(cmd1 == "-test"){
    		iftest = true;
    	}
    	if(cmd2 == "-load"){
    		cout<<"There must be a filename following -load."<<endl;
    	}
    	if(cmd1 == "-load"){
    		ifload=true;
    		filename = cmd2;
    	}
    }else if(argc == 4){
    	string cmd1 = argv[1];
    	string cmd2 = argv[2];
    	string cmd3 = argv[3];
    	if(cmd1 == "-test"){
    		iftest = true;
    	}
    	if(cmd3 == "-test"){
    		iftest = true;
    	}
    	if(cmd2 == "-load"){
    		ifload = true;
    		filename = cmd3;
    	}else if(cmd1 == "-load"){
    		ifload = true;
    		filename = cmd2;
    	}
    }else{
    	cout<<"Invalid command line arguments, normal game start!"<<endl;
    }
    
    cout << "Welcome to Monopoly" << endl;
    cout << "---------------------------------------" << endl;
    cout << "|    ####   ####   #######  #   #     |" << endl;
    cout << "|    #   #  #   #       #   #  #      |" << endl;
    cout << "|    #   #  #   #      #    # #       |" << endl;
    cout << "|    ####   ####      #     ###       |" << endl;
    cout << "|    #   #  #   #    #      #  #      |" << endl;
    cout << "|    #   #  #   #   #       #   #     |" << endl;
    cout << "|    ####   ####   #        #    #    |" << endl;
    cout << "---------------------------------------" << endl;
    GameBoard game(1);
    if(!ifload){
    	cout << "Please enter the number of players: ";
    	cin >> num_ply;
    	while (cin.fail()) {
    		cout << "The number must be an integer." << endl;
    		cin.clear();
    		cin.ignore();
    		cin >> num_ply;
    	}
    	game.change_num_play(num_ply);
    	game.init_board();
    	game.setPlayers();
        game.prboard();
    }else{
    	game.init_board();
    	game.loadfile(filename);
    }
    game.play(iftest);
    
    cout << "Happy!!" << endl;
}

