#include<iostream>
#include<fstream>
#include<sstream>
#include "../global/globalFunk.h"
#include "../global/header.h"
#include "save.h"
#include "../roomInfo/startRoom.h"
#include "../roomInfo/greenRoom.h"
#include "../roomInfo/throneRoom.h"


void createSave(std::string saveName);
void loadSave(std::string saveName);
void getPlayerInfo();
void startUp();
void givePlayerHealth();
void startGame();
void saveGame();

std::string saveStateName;

void saveState () {
	using std::cout;
	using std::cin;
	using std::string;
	using std::endl;

	string select;

	choice:
	getline(cin, select);
	if (select == "YES") {
		cout << "What would you like to call your save file?: ";
		getline(cin, saveStateName);
		createSave(saveStateName);
		getPlayerInfo();
		startGame();
	}
	else if (select == "NO") {
		cout << "What is the name of your save file?: ";
		getline(cin, saveStateName);
		loadSave(saveStateName);
		startGame();
	}
	else {
		goto choice;
	}
}

void createSave(std::string saveName) {
	using std::cout;
	using std::cin;
	using std::string;
	using std::ofstream;
	using std::ifstream;

	string test;

	ifstream file ("initializeData.fleek");

	if(file.is_open()){
		ofstream save;
		save.open("./saveGame/saves/" + saveName + ".bleak");

		while(getline(file, test)){
			save << test << "\n";
		}
		file.close();
		save.close();
	}
	else {
		cout << "can't find default save file\n";
	}
}

void loadSave(std::string saveName) {
	std::cout << "3" << std::endl;
	using std::cout;
	using std::ifstream;
	using std::endl;

	std::string test;
	int lineCount = 1;

	ifstream file ("./saveGame/saves/" + saveName + ".bleak");
	if( file.is_open() ) {
		while(getline(file, test)) {
			switch(lineCount) {
				case 2: playerInfo::playerName = test;
				break;
				case 4: playerInfo::playerWeapon = test;
				break;
				case 6: playerInfo::playerSupportItem = test;
				break;
				case 8: userInput::playerLoc = test;
				break;
				case 10: std::stringstream(test) >> playerInfo::playerAge; 
				break; 
				case 12: std::stringstream(test) >> playerInfo::classNum;
				break;
				case 14: std::stringstream(test) >> playerInfo::playerHealth; 
				break; 
				case 16: std::stringstream(test) >> playerInfo::playerLevel; 
				break; 
				case 18: std::stringstream(test) >> playerInfo::battleStatus; 
				break; 
				case 20: 
					if (test == "1") {
						playerInfo::playerArthritis = true;
					}
					else {
						playerInfo::playerArthritis = false;
					}
					break;
				case 22:
					if (test == "1") {
						userInput::greenRoomCheck = true;
					}
					else {
						userInput::greenRoomCheck = false;
					}
					break;
				case 24:
					if (test == "1") {
						userInput::startRoomCheck = true;
					}
					else {
						userInput::startRoomCheck = false;
					}
					break;
				case 26:
					if (test == "1") {
						userInput::throneRoomCheck = true;
					}
					else {
						userInput::throneRoomCheck = false;
					}
					break;
				case 28:
					if (test == "1") {
						userInput::stone = true;
					}
					else {
						userInput::stone = false;
					}
					break;
				case 30:
					if (test == "1") {
						userInput::key = true;
					}
					else {
						userInput::key = false;
					}
					break;
				case 32:
					if (test == "1") {
						userInput::startFight = true;
					}
					else {
						userInput::startFight = false;
					}
					break;
				case 34:
					if (test == "1") {
						userInput::seeInDark = true;
					}
					else {
						userInput::seeInDark = false;
					}
					break;
				case 36:
					if (test == "1") {
						userInput::doorKick = true;
					}
					else {
						userInput::doorKick = false;
					}
					break;
				case 38:
					if (test == "1") {
						userInput::skeletonDead = true;
					}
					else {
						userInput::skeletonDead = false;
					}
					break;
				case 40:
					if (test == "1") {
						userInput::skeleSword = true;
					}
					else {
						userInput::skeleSword = false;
					}
					break;
				case 42:
					if (test == "1") {
						userInput::greenRag = true;
					}
					else {
						userInput::greenRag = false;
					}
					break;
				case 44:
					if (test == "1") {
						userInput::vineDead = true;
					}
					else {
						userInput::vineDead = false;
					}
					break;
				case 46:
					if (test == "1") {
						userInput::puzzleLoc = true;
					}
					else {
						userInput::puzzleLoc = false;
					}
					break;
				case 48:
					if (test == "1") {
						userInput::puzzleDone = true;
					}
					else {
						userInput::puzzleDone = false;
					}
					break;
			}
			lineCount += 1;
			if (lineCount > 48) {
				break;
			}
		}
		file.close();
	}
	else {
		cout << "Cannot find save. starting a new game.\n";
		enterPause();
	}
}


void saveGame () {
	std::string test;
	int lineCount = 1;
	bool copyLine = true;

	std::ifstream file ("initializeData.fleek");
	if( file.is_open() ) {
		std::ofstream save;
		save.open ("./saveGame/saves/" + saveStateName + ".bleak");

		while(getline(file, test)) {
			if (copyLine == true) {
				save << test << "\n";
			}
			else {
				switch(lineCount) {
				case 2: save << playerInfo::playerName << "\n";
				break;
				case 4: save << playerInfo::playerWeapon << "\n";
				break;
				case 6: save << playerInfo::playerSupportItem << "\n";
				break;
				case 8: save << userInput::playerLoc << "\n";
				break;
				case 10: save << playerInfo::playerAge << "\n"; 
				break; 
				case 12: save << playerInfo::classNum << "\n";
				break;
				case 14: save << playerInfo::playerHealth << "\n"; 
				break; 
				case 16: save << playerInfo::playerLevel << "\n"; 
				break; 
				case 18: save << playerInfo::battleStatus << "\n"; 
				break; 
				case 20: save << playerInfo::playerArthritis << "\n";
				break;
				case 22: save << userInput::greenRoomCheck << "\n";
				break;
				case 24: save << userInput::startRoomCheck << "\n";
				break;
				case 26: save << userInput::throneRoomCheck << "\n";
				break;
				case 28: save << userInput::stone << "\n";
				break;
				case 30: save << userInput::key << "\n";
				break;
				case 32: save << userInput::startFight << "\n";
				break;
				case 34: save << userInput::seeInDark << "\n";
				break;
				case 36: save << userInput::doorKick << "\n";
				break;
				case 38: save << userInput::skeletonDead << "\n";
				break;
				case 40: save << userInput::skeleSword << "\n";
				break;
				case 42: save << userInput::greenRag << "\n";
				break;
				case 44: save << userInput::vineDead << "\n";
				break;
				case 46: save << userInput::puzzleLoc << "\n";
				break;
				case 48: save << userInput::puzzleDone << "\n";
				break;
				}
			}
			copyLine = !copyLine;
			lineCount++;
			if (lineCount > 48) {
				break;
			}
		}
		file.close();
	}
	else {
		std::cout << "Cannot complete save properly\n";
		enterPause();
	}
}

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
	cout << endl;

	while (userInput::playerLoc != "WIN" && userInput::playerLoc != "0") {
		while (userInput::playerLoc=="start") {
			startRoom ();
		}
		while (userInput::playerLoc=="green") {
			cout << "aaa" << endl;
			greenRoom ();
		}
		while (userInput::playerLoc=="throne") {
			throneRoom();
		}
	}

	if (userInput::playerLoc == "WIN") {
		cout << "YOU WIN!!!\n\nThanks for playing,\n\n-Jwarila and Wizard\n\n";
	}
	else {
		cout << "\n\nThanks for playing," << endl << endl << "-jwarila and wizard" << endl;
	}
		
}