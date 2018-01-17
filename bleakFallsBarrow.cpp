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
} mine, yours;

void printCompInfo(userClass player); // Init all functinos
void printPlayerInfo(userClass player);
void getPlayerInfo();
void introText();

int main(){
	cout << "CoreEngine";
	introText();
	getPlayerInfo();
	cout << endl << "I'LL LET YOU KNOW A LITTLE ABOUT MYSELF:" << endl;
	printCompInfo(mine);
	cout << endl;
	
	cout << "HERE'S WHAT I CAN TELL YOU ABOUT YOURSELF, TRAVELER:" << endl;
	printPlayerInfo(yours);
	return 0;
}

void getPlayerInfo(){ // Ask the player to input the data about their character
  srand(time(NULL));

	string nameIn;
	string ageIn;
	string classIn;

	yours.classNum = 0;
	
	cout << "\nWHAT'S YOUR NAME, TRAVELER?: ";
	getline(cin, nameIn);
	yours.playerName = nameIn;
	
	cout << "HOW OLD ARE YOU, " << nameIn << "?: ";
	
	while(yours.playerAge == 0){
		getline(cin, ageIn);
		stringstream(ageIn) >> yours.playerAge;
	  
		if(yours.playerAge == 0){
			  cout << "I DIDN'T UDERSTAND YOUR ANSWER. TRY AGAIN: ";
		}
	}
	
	cout << "PICK YOUR CLASS (TYPE MAGE, WARRIOR, ROGUE, WARLOCK, OR RANDOM): ";
	
	while(yours.classNum == 0){
		getline(cin, classIn);
		stringstream(classIn) >> yours.classNum;
	  
		if(classIn == "MAGE"){
			yours.classNum = 1;
		}else if(classIn == "WARRIOR"){
			yours.classNum = 2;
		}else if(classIn == "ROGUE"){
			yours.classNum = 3;
		}else if(classIn == "WARLOCK"){
			yours.classNum = 4;
		}else if(classIn == "RANDOM"){
			yours.classNum = (rand() % 4) + 1;
		}else{
			cout << "I DIDN'T UDERSTAND YOUR ANSWER. TRY AGAIN: ";
		}
	}
	
	mine.playerName = "JOSHUA, THE MAGESTIC";
	mine.playerAge = 18;
	mine.classNum = rand() % 4;
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
	cout << "WELCOME TO BLEAKFALLS BARROW ADVENTURE! BEFORE YOU BEGIN PLAYING PLEASE TURN YOUR CAPS-LOCK ON, IF YOU DON'T HAVE IT ON I CAN'T UNDERSTAND YOU." << endl;
	cout << "YOU CAN GIVE INSTRUCTIONS WITH TWO WORDS, A VERB AND A NOUN. COMMANDS LOOK LIKE THIS; MOVE NORTH, PICK SWORD, USE SPELL, RUN AWAY." << endl;
  	cout << "THERE ARE FOUR CLASSES THAT YOU CAN CHOOSE FOR YOURSELF, MAGE: A HYBRID CLASS THAT USES A SWORD AND HAS ONE SPELL. WARRIOR: HEAVY FIGHTER THAT USES A TWO HANDED AXE. ROUGE: A SNEAKY CLASS THAT USES A DAGGER AND HAS A HIGHER CHANCE TO ESCAPE. WARLOCK: A PURE MAGIC CLASS WITH TWO SPELLS." << endl;
	cout << endl << "NOW, TELL ME ABOUT YOURSELF..." << endl;
}
