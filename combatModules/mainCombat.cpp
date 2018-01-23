#include <iostream>
#include <string>
#include <sstream>
#include <time.h>
#include <stdlib.h>
#include <limits>
#include <chrono>
#include <thread>

using namespace std;


class playerInfo {
public:
	string playerName;
	int playerAge;
	int classNum;
	int playerLoc;
	int playerHealth;
	int playerLevel;
} playerOne;

class enemyInfo{
public:
	string enemyName;
	int enemyHealth;
	int enemyLevel;
} goblinOne;

void getPlayerInfo();
void makeEnemy();
void clearScreen();
void introCombatText();
string stringSearch(string *array, int size);
void bubbleSort(string *array, int size);
void combatInitPrompt();
void combatFightModule();
void combatRunModule();

int main(){
	clearScreen();
	introCombatText(); // Run the intro
	getPlayerInfo(); // Get the data on player character
	makeEnemy(); // Fill enemy data
	combatInitPrompt(); // Initialize combat
	return 0;
}

void introCombatText(){ // Basic intro text
	cout << "WELCOME TO THE COMBAT MODULE!!" << endl;
	cout << "IN THIS BREIF DEMO YOU WILL CREATE A CHARACTER AND FIGHT A FOE" << endl;
	cout << "LET'S BEGIN!!!!!!!!!" << endl ;

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

void makeEnemy(){ // Fill the enemy class with data on a default enemy
	goblinOne.enemyName = "Bagrosh the Slimy";
	goblinOne.enemyHealth = 30;
	goblinOne.enemyLevel = 2;
}

void clearScreen(){ // Clear the screen and move curser to the upper left
	cout << "\033[2J\033[1;1H";
}

void bubbleSort(string *array, int size){ // Sort the command array so the search can work
	bool swap;
	string temp;

	do{
		swap = false;
		for(int count = 1; count < (size - 1); count++){
			if(array[count-1] > array[count]){
				temp = array[count-1];
				array[count-1] = array[count];
				array[count] = temp;
				swap = true;
			}
		}
	}
	while(swap);
}

string stringSearch(string *array, int size){ // Check if the userCommand is in the string and then return it so the function can be called
	string userCommand;
	for(;;){
		cout << ": ";
		getline(cin, userCommand);
		if(userCommand == "END") break;

		int first = 0;
		int last = size - 1;
		bool validCommand = false;

		while(!validCommand && first <= last){
			int middle = (first + last) / 2;
			if(array[middle] == userCommand){
				validCommand = true;
				return userCommand;			}
			else if(array[middle] > userCommand)
				last = middle - 1;
			else
				first = middle + 1;
		}
	}
	return "error";
}

void combatInitPrompt(){ // Initial the combat with choice to fight or run, if 
	                 //fight is chosen you will be sent to the combat proper, if run you will have a chance to escape
	clearScreen();
	string array[] = {"FIGHT", "RUN", "BUFFER"};
	cout << "YOU HAVE BEEN CONFRONTED BY THE SCORNED LOVER!!!" << endl;
	cout << "WHAT DO YOU WANT TO DO?" << endl;
	cout << "FIGHT RUN" << endl;

	bubbleSort(array, 3);

	string userCommand = stringSearch(array, 3);
	clearScreen();
	cout << userCommand << endl;
	if(userCommand == "FIGHT"){
		combatFightModule();
	}
	else{
		combatRunModule();
	}
}

void combatFightModule(){ // The user has chosen to fight, run all of the functions for combat
	cout << "YOU HAVE CHOSEN TO FIGHT!" << endl;
}

void combatRunModule(){ // The user has chosen to try to run away, roll for chance of run away
	clearScreen();
	cout << "YOU HAVE CHOSEN TO RUN AWAY!" << endl;
}