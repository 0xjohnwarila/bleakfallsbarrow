// TODO
// Add class for inventory and health
// Work out combat system
// Figure out how to deal with map

#include <iostream>
#include <string>
#include <sstream>
#include <time.h>
#include <stdlib.h>
#include <limits>
#include <chrono>
#include <thread>

using namespace std;

class  playerInfo { // Class that stores player data
public:
	string playerName;
	int playerAge;
	int classNum;
	int playerLoc;
} playerOne;

void printPlayerInfo(playerInfo player);
void getPlayerInfo();
void introText();
void clearScreen();
void startRoom (playerInfo player);
void sleepMilli(int x);

int main(){
	introText();
	getPlayerInfo();

	
	printPlayerInfo(playerOne);
	return 0;
}

void getPlayerInfo(){ // Ask the player to input the data about their character
  srand(time(NULL));

	string nameIn;
	string ageIn;
	string classIn;

	playerOne.classNum = 0;
	
	cout << "\nWHAT'S YOUR NAME, TRAVELER?: ";
	getline(cin, nameIn);
	playerOne.playerName = nameIn;
	
	cout << "HOW OLD ARE YOU, " << nameIn << "?: ";
	
	while(playerOne.playerAge == 0){
		getline(cin, ageIn);
		stringstream(ageIn) >> playerOne.playerAge;
	  
		if(playerOne.playerAge == 0){
			  cout << "I DIDN'T UDERSTAND YOUR ANSWER. TRY AGAIN: ";
		}
	}
	
	cout << "PICK YOUR CLASS (TYPE MAGE, WARRIOR, ROGUE, WARLOCK, OR RANDOM): ";
	
	while(playerOne.classNum == 0){
		getline(cin, classIn);
		stringstream(classIn) >> playerOne.classNum;
	  
		if(classIn == "MAGE"){
			playerOne.classNum = 1;
		}else if(classIn == "WARRIOR"){
			playerOne.classNum = 2;
		}else if(classIn == "ROGUE"){
			playerOne.classNum = 3;
		}else if(classIn == "WARLOCK"){
			playerOne.classNum = 4;
		}else if(classIn == "RANDOM"){
			playerOne.classNum = (rand() % 4) + 1;
		}else{
			cout << "I DIDN'T UDERSTAND YOUR ANSWER. TRY AGAIN: ";
		}
	}
}

void printPlayerInfo(playerInfo player){ // Print info about the player
	sleepMilli(1000);
	clearScreen();

	cout << endl << "HERE'S WHAT I CAN TELL YOU ABOUT YOURSELF, TRAVELER:" << endl;

	string classPick[5] = {"nullClass", "MAGE", "WARRIOR", "ROGUE", "WARLOCK"};

	cout << endl << "YOUR NAME IS " << player.playerName << "." << endl;
	cout << "YOU ARE " << player.playerAge << " YEARS OF AGE." << endl;
	cout << "YOU ARE A " << classPick[player.classNum] << "." << endl;
}

void introText(){
	clearScreen();
	cout << "WELCOME TO BLEAKFALLS BARROW ADVENTURE! BEFORE YOU BEGIN PLAYING PLEASE TURN YOUR CAPS-LOCK ON, IF YOU DON'T HAVE IT ON I CAN'T UNDERSTAND YOU." << endl;
	cout << "YOU CAN GIVE INSTRUCTIONS WITH TWO WORDS, A VERB AND A NOUN. COMMANDS LOOK LIKE THIS; MOVE NORTH, PICK SWORD, USE SPELL, RUN AWAY." << endl;
  	cout << "THERE ARE FOUR CLASSES THAT YOU CAN CHOOSE FOR YOURSELF, MAGE: A HYBRID CLASS THAT USES A SWORD AND HAS ONE SPELL. WARRIOR: HEAVY FIGHTER THAT USES A TWO HANDED AXE. ROUGE: A SNEAKY CLASS THAT USES A DAGGER AND HAS A HIGHER CHANCE TO ESCAPE. WARLOCK: A PURE MAGIC CLASS WITH TWO SPELLS." << endl;
	cout << endl << "NOW, TELL ME ABOUT YOURSELF..." << endl;
}

void startRoom (playerInfo player) {
	playerOne.playerLoc=3;
}


void clearScreen(){ // Clear the screen and move curser to the upper left
	cout << "\033[2J\033[1;1H";

}

void sleepMilli(int x){ // Sleeps for X milliseconds
	std::this_thread::sleep_for(std::chrono::milliseconds(x));
}