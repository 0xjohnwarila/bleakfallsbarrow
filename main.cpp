//main.cpp is the function that is compiled and ran.
#include <iostream>
#include <sstream>
#include <thread>
#include "./global/header.h"
#include "./roomInfo/startRoom.h"
#include "./roomInfo/greenRoom.h"
#include "./roomInfo/throneRoom.h"
#include "./global/globalFunctions.h"
#include "./saveGame/save.h"
#include "./menuInterface/mainMenu.h"

// Init text values

std::string userInput::verb = "null";
std::string userInput::noun = "null";
std::string userInput::inputString = "null";
std::string userInput::commandFlavor = "null";
int userInput::english = 0;

// Init player info values

std::string playerInfo::playerName = "null";
std::string playerInfo::playerWeapon = "FISTS";
std::string playerInfo::playerSupportItem = "NOTHING";
std::string userInput::playerLoc = "start";
int playerInfo::playerAge = 0;
int playerInfo::classNum = 0;
int playerInfo::playerHealth = 0;
int playerInfo::playerLevel = 0;
int playerInfo::battleStatus = 0;
bool playerInfo::playerArthritis = false;
bool playerInfo::playerCrit = false;
bool playerInfo::playerTurn = true;
bool playerInfo::playerSkipTurn = false;
bool playerInfo::playerIsInsane = false;

bool userInput::greenRoomCheck = false;
bool userInput::startRoomCheck = false;
bool userInput::throneRoomCheck = false;

// Init startRoom values

bool userInput::stone = false;
bool userInput::key = false;
bool userInput::startFight = false;
bool userInput::seeInDark = false;
int userInput::doorKick = 0;

// Init greenRoom values

bool userInput::skeletonDead = false;
bool userInput::skeleSword = false;
bool userInput::greenRag = false;
bool userInput::vineDead = false;

// Init throneRome values

int userInput::puzzleLoc = 0;
bool userInput::puzzleDone = false;


int main(int argc, char *argv[])
{
	using std::cout;
	using std::endl;
	using std::string;
	using std::cin;
	srand(time(NULL));

	//getPlayerInfo();

	if(argc == 2) {
		std::string developerMode = argv[1];
		if(developerMode == "dev") {
			userInput::startRoomCheck = true;
			userInput::greenRoomCheck = true;
			userInput::throneRoomCheck = true;

			playerInfo::playerName = "JOSH, THE MAGNIFICENT";
			playerInfo::playerWeapon = "BOOK FOR CLEAN CODE";
			playerInfo::playerAge = 18;
			playerInfo::classNum = 1;
			playerInfo::playerHealth = 50;

			clearFirst();
			cout << "welcome to dev mode\n\nwhat room?: ";
			string devRoom;
			getline(cin, devRoom);
			if(devRoom=="start") {
				userInput::playerLoc = "start";
			}
			else if(devRoom=="start done") {
				userInput::stone = true;
				userInput::key = true;
				userInput::startFight = true;
				userInput::playerLoc = "start";
			}
			else if(devRoom=="green") {
				userInput::stone = true;
				userInput::key = true;
				userInput::startFight = true;
				userInput::playerLoc = "green";
			}
			else if(devRoom=="green done") {
				userInput::stone = true;
				userInput::key = true;
				userInput::startFight = true;

				userInput::skeletonDead = true;
				userInput::skeleSword = true;
				userInput::greenRag = true;
				userInput::vineDead = true;
				userInput::playerLoc = "green";
			}
			else if(devRoom=="throne") {
				userInput::stone = true;
				userInput::key = true;
				userInput::startFight = true;

				userInput::skeletonDead = true;
				userInput::skeleSword = true;
				userInput::greenRag = true;
				userInput::vineDead = true;
				userInput::playerLoc = "throne";
			}
			startGame();
		}
		else {
			printTitleScreen();
		}
	}
	else if(argc == 3) {
		std::string developerMode = argv[2];
		if(developerMode == "dev") {
			userInput::startRoomCheck = true;
			userInput::greenRoomCheck = true;

			playerInfo::playerName = "JOSH, THE MAGNIFICENT";
			playerInfo::playerWeapon = "BOOK FOR CLEAN CODE";
			playerInfo::playerAge = 18;
			playerInfo::classNum = 1;
			playerInfo::playerHealth = 50;

			clearFirst();
			cout << "welcome to dev mode\n\nwhat room?: ";
			string devRoom;
			getline(cin, devRoom);
			if(devRoom=="start") {
				userInput::playerLoc = 2;
			}
			else if(devRoom=="green") {
				userInput::playerLoc = 3;
			}
			startGame();
		}
		else {
			printTitleScreen();
		}
	}
	else {
		printTitleScreen();

	}

	return 0;
}
