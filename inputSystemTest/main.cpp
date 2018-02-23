//main.cpp is the function that is compiled and ran.

//TODO:
//setup location control for 3 rooms
//look into initializing values in a seperate file to setup file saving

#include <iostream>
#include <sstream>
#include <thread>
#include "./global/header.h"
#include "./roomInfo/startRoom.h"
#include "./roomInfo/greenRoom.h"
#include "./global/globalFunk.h"

//this function initializes all of the values that are in the header file.
//they have to be initialized in the main function. 
//the first paragraph initializes text input values

std::string userInput::verb = "null";
std::string userInput::noun = "null";
std::string userInput::inputString = "null";
std::string userInput::commandFlavor = "null";
int userInput::english = 0;

//initializing player values

std::string playerInfo::playerName = "null";
int playerInfo::playerAge = 0;
int playerInfo::classNum = 0;
int userInput::playerLoc = 2;
int playerInfo::playerHealth = 0;
int playerInfo::playerLevel = 0;
int playerInfo::battleStatus = 0;
bool playerInfo::playerArthritis = false;
bool playerInfo::playerCrit = false;

bool userInput::greenRoomCheck = false;
bool userInput::startRoomCheck = false;

//initializing startRoom values:

bool userInput::stone = false;
bool userInput::key = false;
bool userInput::startFight = false;
bool userInput::seeInDark = false;
int userInput::doorKick = 0;

bool userInput::skeletonDead = false;
bool userInput::skeleSword = false;
bool userInput::greenRag = false;
bool userInput::vineDead = false;

//the player's location starts as 2, which is the startRoom.
//startRoom is the only function that can change the player's location
//if the player's location is changed to 1, then the game will display win info and dip
//if the player's location is changed to anything else (i.e. 0), then the game will QUIT and exit

void getPlayerInfo();
void startUp();
void givePlayerHealth();
void startGame();

int main(int argc, char *argv[])
{
	using std::cout;
	using std::endl;
	using std::string;
	using std::cin;
	srand(time(NULL));

	cout << "WELCOME TO THE COMBATMODULE INTEGRATION DEMO! YOU WILL CREATE A CHARACTER AND FIGHT AN ENEMY!" << endl;

	//getPlayerInfo();

	if (argc == 2) {
		std::string developerMode = argv[1];
		if (developerMode == "dev") {
			userInput::startRoomCheck = true;
			userInput::greenRoomCheck = true;

			playerInfo::playerName = "JOSH, THE MAGNIFICENT";
			playerInfo::playerAge = 18;
			playerInfo::classNum = 1;
			playerInfo::playerHealth = 50;

			clearFirst();
			cout << "welcome to dev mode\n\nwhat room?: ";
			string devRoom;
			getline(cin, devRoom);
			if (devRoom=="start") {
				userInput::playerLoc = 2;
			}
			else if (devRoom=="green") {
				userInput::playerLoc = 3;
			}
			startGame();
		}
	}
	else {
		getPlayerInfo();
		startGame();
	}

	return 0;
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

	clearFirst();
	cout << "WHAT'S MY NAME?: ";
	getline(cin, nameIn);
	playerInfo::playerName = nameIn;
	
	cout << "HOW OLD AM I, " << playerInfo::playerName << "?: ";
	
	while(playerInfo::playerAge == 0){
		getline(cin, ageIn);
		std::stringstream(ageIn) >> playerInfo::playerAge;

		if(playerInfo::playerAge > 60){
			playerInfo::playerArthritis = true;
		}
	  
		if(playerInfo::playerAge == 0){
			  cout << "I DIDN'T UDERSTAND YOUR ANSWER. TRY AGAIN: ";
		}
	}
	
	cout << "WHAT AM I (TYPE MAGE, WARRIOR, ROGUE, WARLOCK, OR RANDOM): ";
	
	while(playerInfo::classNum == 0){
		getline(cin, classIn);
		std::stringstream(classIn) >> playerInfo::classNum;
	  
		if(classIn == "MAGE"){
			playerInfo::classNum = 1;
		}else if(classIn == "WARRIOR"){
			playerInfo::classNum = 2;
		}else if(classIn == "ROGUE"){
			playerInfo::classNum = 3;
		}else if(classIn == "WARLOCK"){
			playerInfo::classNum = 4;
		}else if(classIn == "RANDOM"){
			playerInfo::classNum = (rand() % 4) + 1;
		}else{
			cout << "I DIDN'T UDERSTAND YOUR ANSWER. TRY AGAIN: ";
		}
	}

	givePlayerHealth();
}

void givePlayerHealth(){ // Assign default health
	playerInfo::playerLevel = 1;

	if(playerInfo::classNum == 1){
		playerInfo::playerHealth = 20;
	}else if(playerInfo::classNum == 2){
		playerInfo::playerHealth = 40;
	}else if(playerInfo::classNum == 3){
		playerInfo::playerHealth = 30;
	}else if(playerInfo::classNum == 4){
		playerInfo::playerHealth = 20;
	}
}

void startGame () {
	using std::cout;
	using std::endl;

	while (userInput::playerLoc != 1 && userInput::playerLoc != 0) {
		while (userInput::playerLoc==2) {
			startRoom ();
		}
		while (userInput::playerLoc==3) {
			greenRoom ();
		}
	}

	if (userInput::playerLoc == 1) {
		cout << "YOU WIN!!!\n\nThanks for playing,\n\n-Jwarila and Wizard\n\n";
	}
	else {
		cout << "\n\nThanks for playing," << endl << endl << "-jwarila and wizard" << endl;
	}
		
}