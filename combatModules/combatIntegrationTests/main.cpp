#include <iostream>
#include <sstream>
#include <thread>
#include "globalFunctions.h"
#include "combatModule.h"
#include "header.h"

void getPlayerInfo();
void startUp();
void givePlayerHealth();

int main(){
	
	startUp();

	return 0;
}

void startUp(){
	using std::cout;
	using std::endl;

	cout << "WELCOME TO THE COMBATMODULE INTEGRATION DEMO! YOU WILL CREATE A CHARACTER AND FIGHT AN ENEMY!" << endl;

	getPlayerInfo();

	cout << endl << combatInitPrompt("bad", 10, 3) << endl;
}

// Classes and player creation
//
// The classes in the game are as follows:
//
// Warrior: High physical damage
//          High health
//          No spells
//
// Mage:    Medium physical damage
//          Medium magic damage
//          Low health
// 
// Rogue:   Average physical damage
//          No spells
//          Average health
//
// Warlock: Very low physical damage
//          High magic damage
//          Low health
//
// The only incentive to play rogue at the moment is a challenge, in the future
// rogues will be able to wait and get a critical hit on their next turn.
// 
// Warriors may be over powered in the long term, their damage being connected
// to their player level.
//

void getPlayerInfo(){ // Ask the player to input the data about their character
	using std::string;
	using std::endl;
	using std::cin;
	using std::cout;

	srand(time(NULL));

	string nameIn;
	string ageIn;
	string classIn;

	int playerInfo.classNum = 0;
	
	cout << "\nWHAT'S MY NAME?: ";
	getline(cin, nameIn);
	std::string playerInfo.playerName = nameIn;
	
	cout << "HOW OLD AM I?: ";
	
	int playerInfo.playerAge;

	while(playerInfo.playerAge == 0){
		getline(cin, ageIn);
		std::stringstream(ageIn) >> playerInfo.playerAge;

		if(playerInfo.playerAge > 60){
			bool playerInfo.playerArthritis = true;
		}
	  
		if(playerInfo.playerAge == 0){
			  cout << "I DIDN'T UDERSTAND YOUR ANSWER. TRY AGAIN: ";
		}
	}
	
	cout << "WHAT AM I (TYPE MAGE, WARRIOR, ROGUE, WARLOCK, OR RANDOM): ";
	
	while(playerInfo.classNum == 0){
		getline(cin, classIn);
		std::stringstream(classIn) >> playerInfo.classNum;
	  
		if(classIn == "MAGE"){
			playerInfo.classNum = 1;
		}else if(classIn == "WARRIOR"){
			playerInfo.classNum = 2;
		}else if(classIn == "ROGUE"){
			playerInfo.classNum = 3;
		}else if(classIn == "WARLOCK"){
			playerInfo.classNum = 4;
		}else if(classIn == "RANDOM"){
			playerInfo.classNum = (rand() % 4) + 1;
		}else{
			cout << "I DIDN'T UDERSTAND YOUR ANSWER. TRY AGAIN: ";
		}
	}

	givePlayerHealth();
}

void givePlayerHealth(){ // Assign default health
	int playerInfo.playerLevel = 1;
	int playerInfo.playerHealth;

	if(playerInfo.classNum == 1){
		playerInfo.playerHealth = 20;
	}else if(playerInfo.classNum == 2){
		playerInfo.playerHealth = 40;
	}else if(playerInfo.classNum == 3){
		playerInfo.playerHealth = 30;
	}else if(playerInfo.classNum == 4){
		playerInfo.playerHealth = 20;
	}
}