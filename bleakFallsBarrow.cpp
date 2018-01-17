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

using namespace std;

class  userClass { // Class that stores player data
public:
	string playerName;
	int playerAge;
	int classNum;
	int playerLoc;
} guide, player;

void printCompInfo(userClass player); // Init all functinos
void printPlayerInfo(userClass player);
void getPlayerInfo();
void introText();
void playerIn(userClass player);
void startRoom(userClass player);

int main(){
	introText();
	getPlayerInfo();
	cout << endl << "I'LL LET YOU KNOW A LITTLE ABOUT MYSELF:" << endl;
	printCompInfo(guide);
	cout << endl;
	
	cout << "HERE'S WHAT I CAN TELL YOU ABOUT YOURSELF, TRAVELER:" << endl;
	printPlayerInfo(player);

	return 0;
}

void getPlayerInfo(){ // Ask the player to input the data about their character
  srand(time(NULL));

	string nameIn;
	string ageIn;
	string classIn;

	player.classNum = 0;
	
	cout << "\nWHAT'S YOUR NAME, TRAVELER?: ";
	getline(cin, nameIn);
	player.playerName = nameIn;
	
	cout << "HOW OLD ARE YOU, " << nameIn << "?: ";
	
	while(player.playerAge == 0){
		getline(cin, ageIn);
		stringstream(ageIn) >> player.playerAge;
	  
		if(player.playerAge == 0){
			  cout << "I DIDN'T UDERSTAND YOUR ANSWER. TRY AGAIN: ";
		}
	}
	
	cout << "PICK YOUR CLASS (TYPE MAGE, WARRIOR, ROGUE, WARLOCK, OR RANDOM): ";
	
	while(player.classNum == 0){
		getline(cin, classIn);
		stringstream(classIn) >> player.classNum;
	  
		if(classIn == "MAGE"){
			player.classNum = 1;
		}else if(classIn == "WARRIOR"){
			player.classNum = 2;
		}else if(classIn == "ROGUE"){
			player.classNum = 3;
		}else if(classIn == "WARLOCK"){
			player.classNum = 4;
		}else if(classIn == "RANDOM"){
			player.classNum = (rand() % 4) + 1;
		}else{
			cout << "I DIDN'T UDERSTAND YOUR ANSWER. TRY AGAIN: ";
		}
	}
	
	guide.playerName = "JOSHUA, THE MAGESTIC";
	guide.playerAge = 18;
	guide.classNum = rand() % 4;
}
 
void printCompInfo(userClass player){ // Print info about the comp
	string classPick [4] = {"MAGE", "WARRIOR", "ROGUE", "WARLOCK"};
	  
	cout << "MY NAME IS " << player.playerName << "." << endl;
	cout << "I AM " << player.playerAge << " YEARS OF AGE." << endl;
	cout << "I AM a " << classPick[player.classNum] << "." << endl;
}

void printPlayerInfo(userClass player){ // Print info about the player

	string classPick[5] = {"nullClass", "MAGE", "WARRIOR", "ROGUE", "WARLOCK"};

	cout << endl << "YOUR NAME IS " << player.playerName << "." << endl;
	cout << "YOU ARE " << player.playerAge << " YEARS OF AGE." << endl;
	cout << "YOU ARE A " << classPick[player.classNum] << "." << endl;
}

void introText(){
	cout << "WELCOME TO BLEAKFALLS BARROW ADVENTURE! BEFORE YOU BEGIN PLAYING PLEASE TURN YOUR CASP-LOCK ON, IF YOU DON'T HAVE IT ON I CAN'T UNDERSTAND YOU." << endl;
	cout << "YOU CAN GIVE INSTRUCTIONS WITH TWO WORDS, A VERB AND A NOUN. COMMANDS LOOK LIKE THIS; MOVE NORTH, PICK SWORD, USE SPELL, RUN AWAY." << endl;
  	cout << "THERE ARE FOUR CLASSES THAT YOU CAN CHOOSE FOR YOURSELF, MGAE: A HYBRID CLASS THAT USES A SWORD AND HAS ONE SPELL. WARRIOR: HEAVY FIGHTER THAT USES A TWO HANDED AXE. ROGUE: A SNEAKY CLASS THAT USES A DAGGER AND HAS A HIGHER CHANCE TO ESCAPE. WARLOCK: A PURE MAGIC CLASS WITH TWO SPELLS." << endl;
	cout << endl << "NOW, TELL ME ABOUT YOURSELF..." << endl;
}
