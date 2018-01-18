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

int main(){
	clearScreen();
	introCombatText();
	getPlayerInfo();
	makeEnemy();

	return 0;
}

void introCombatText(){
	cout << "WELCOME TO THE COMBAT MODULE!!" << endl;
	cout << "IN THIS BREIF DEMO YOU WILL CREAT A CHARACTER AND FIGHT A FOE" << endl;
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

void makeEnemy(){
	goblinOne.enemyName = "Bagrosh the Slimy";
	goblinOne.enemyHealth = 30;
	goblinOne.enemyLevel = 2;
}

void clearScreen(){ // Clear the screen and move curser to the upper left
	cout << "\033[2J\033[1;1H";
}