//main.cpp is the function that is compiled and ran.

//TODO:
//setup location control for 3 rooms
//look into initializing values in a seperate file to setup file saving

#include <iostream>
#include "./global/header.h"
#include "./roomInfo/startRoom.h"
#include "./roomInfo/greenRoom.h"

//this function initializes all of the values that are in the header file.
//they have to be initialized in the main function. 
//the first paragraph initializes text input values

std::string userInput::verb = "null";
std::string userInput::noun = "null";
std::string userInput::inputString = "null";
std::string userInput::commandFlavor = "null";
int userInput::english = 0;

//initializing player values

std::string userInput::playerName = "null";
int userInput::playerAge = 0;
int userInput::classNum = 0;
int userInput::playerLoc = 2;

bool userInput::greenRoomCheck = false;
bool userInput::startRoomCheck = false;

//initializing startRoom values:

bool userInput::stone = false;
bool userInput::key = false;
bool userInput::seeInDark = false;
int userInput::doorKick = 0;

//the player's location starts as 2, which is the startRoom.
//startRoom is the only function that can change the player's location
//if the player's location is changed to 1, then the game will display win info and dip
//if the player's location is changed to anything else (i.e. 0), then the game will QUIT and exit

int main () {
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
		cout << "Thanks for playing," << endl << endl << "-jwarila and wizard" << endl;
	}
	

	return 0;
	
}