#include <iostream>
#include <sstream>
#include <time.h>
#include <stdlib.h>
#include <limits>
#include <chrono>
#include <thread>
#include "header.h"
#include "combatModule.cpp"

using std::string;

void getPlayerInfo();
void bubbleSort(string *array, int size);
string stringSearch(string *array, int size);
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

void getPlayerInfo(){ // Ask the player to input the data about their character
	using namespace std;

	srand(time(NULL));

	string nameIn;
	string ageIn;
	string classIn;

	playerOne.classNum = 0;
	
	cout << "\nWHAT'S MY NAME?: ";
	getline(cin, nameIn);
	playerOne.playerName = nameIn;
	
	cout << "HOW OLD AM I?: ";
	
	while(playerOne.playerAge == 0){
		getline(cin, ageIn);
		stringstream(ageIn) >> playerOne.playerAge;

		if(playerOne.playerAge > 60){
			playerOne.playerArthritis = true;
		}
	  
		if(playerOne.playerAge == 0){
			  cout << "I DIDN'T UDERSTAND YOUR ANSWER. TRY AGAIN: ";
		}
	}
	
	cout << "WHAT AM I (TYPE MAGE, WARRIOR, ROGUE, WARLOCK, OR RANDOM): ";
	
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

	givePlayerHealth();
}

void givePlayerHealth(){ // Assign default health
	if(playerOne.classNum == 1){
		playerOne.playerHealth = 20;
	}else if(playerOne.classNum == 2){
		playerOne.playerHealth = 40;
	}else if(playerOne.classNum == 3){
		playerOne.playerHealth = 30;
	}else if(playerOne.classNum == 4){
		playerOne.playerHealth = 20;
	}
}