#include <iostream>
#include <string>
#include <sstream>
#include <time.h>
#include <stdlib.h>
#include <limits>
#include <chrono>
#include <thread>
#include "inputSplit.cpp"
using namespace std;

bool door = false;
bool key = false;

void clearScreenFirst();
void clearScreen();
void endCommand();
void failThat();
void failThere();
void fail();
void sleepMilli(int x);

void startRoom () {
	userInput::playerLoc = 2;
	clearScreenFirst();
	while (userInput::playerLoc==2) {
		playerInput ();
		if (userInput::playerVerb==0) {
			clearScreen();
			cout << "THE GOAL OF THIS GAME IS TO EXIT THE DUNGEON.  YOU CAN MOVE USING THE CARDINAL DIRECTIONS, AND INTERACT WITH ITEMS BY USING THEM OR TAKING THEM.  LOOK IN A DIRECTION, OR INSPECT VISIBLE ITEMS TO LEARN MORE ABOUT YOUR ENVIRONMENT.  EXCLUDING EXITING THE GAME, ALL COMMANDS MUST BE IN VERB-NOUN FORMAT EX:'WALK NORTH', 'SEARCH BAG', OR 'GRAB AXE'";
			endCommand();
		}
		else if (userInput::playerVerb==1) {
			userInput::playerLoc=0;
		}
		else if (userInput::playerVerb==2) {
			if (userInput::playerNoun==1 || userInput::playerNoun==2 || userInput::playerNoun==4) {
				clearScreen();
				//cout << endl <<"OK,";
				cout << "I TRY TO MOVE THROUGH THE WALL, BUT I CAN'T GET THROUGH IT.  MAYBE I SHOULD MOVE A DIFFERENT DIRECTION.";
				/*sleepMilli(2000);
				cout << endl;
				sleepMilli(3000);*/
				endCommand ();
			}
			else if (userInput::playerNoun==3) {
				if (door==false) {
					clearScreen();
					cout << "I PULL ON THE DOOR AND IT FALLS TO THE GROUND.  THERE'S NO WALL BEHIND IT, JUST MORE STONE.  THERE'S A SMALL KEY ON THE WALL";
					door = true;
					endCommand();
				}
				else {
					clearScreen();
					cout << "THE DOOR IS LYING ON THE FOOR.  I CAN'T DO ANYTHING IMPORTANT WITH IT.";
					endCommand();
				}
			}
			else {
				failThere();
			}
		}
		else if (userInput::playerVerb==3) {
			if (userInput::playerNoun==9) {
				if (door==true) {
					clearScreen();
					cout << "I TAKE THE KEY OFF OF THE WALL.  IT STICKS TO MY HAND.  I FEEL GROSS, BUT ALSO ACCOMPLISHED.";
					key = true;
					endCommand();
				}
				else {
					failThat();
				}
			}
			else {
				failThat();
			}
		}
		else if (userInput::playerVerb==4) {
			if (userInput::playerNoun==5) {
				clearScreen();
				cout << "I TRY TO OPEN THE CHEST, BUT IT IS TOO STRONG.  I SHOULD TRY TO OPEN THIS WITH SOMETHING";
				endCommand();
			}
			else if (userInput::playerNoun==6) {
				if (door==false) {
					clearScreen();
					cout << "I PULL ON THE DOOR AND IT FALLS TO THE GROUND.  THERE'S NO WALL BEHIND IT, JUST MORE STONE.  THERE'S A SMALL KEY ON THE WALL";
					door = true;
					endCommand();
				}
				else {
					clearScreen();
					cout << "THE DOOR IS LYING ON THE FOOR.  I CAN'T DO ANYTHING IMPORTANT WITH IT.";
					endCommand();
				}
			}
			else if (userInput::playerNoun==9 || userInput::playerNoun==5) {
				if (door==true || key==true) {
					clearScreen();
					cout << "I STICK THE KEY INTO THE KEYHOLE ON THE CHEST.  THE CHEST SCREAMS LOUDLY AND THEN OPENS IN A FLASH OF GREEN LIGHT.  TWO WORDS APPEAR BEFORE YOU...\n";
					userInput::playerLoc=1;
				}
				else {
					failThat();
				}
			}
			else {
				failThat();
			}
		}
		else if (userInput::playerVerb==5) {
			if (userInput::playerNoun==1 || userInput::playerNoun==2) {
				clearScreen();
				cout << "I INSPECT THE OLD STONE WALLS.  I CAN FEEL THAT THIS PLACE HAS NOT FELT LIFE FOR A LONG TIME.  I UNDERSTAND THE SOLEMNITY OF MY SITUATION.  I FEEL COLD.";
				endCommand();
			}
			else if (userInput::playerNoun==3 || userInput::playerNoun==6) {
				if (door==false) {
					clearScreen();
					cout << "THE DOOR IS CLOSED, BUT NOT LOCKED.  I SHOULD SEE WHAT'S ON THE OTHER SIDE";
					endCommand();
				}
				else if (key==false) {
					clearScreen();
					cout << "THERE IS A KEY STUCK TO THE STONE WALL WHERE THE DOOR USED TO BE.";
					endCommand();
				}
				else {
					clearScreen();
					cout << "THERE IS A STICKY SUBSTANCE ON THE WALL WHERE THE KEY USED TO BE.";
					endCommand();
				}
			}
			else if (userInput::playerNoun==4 || userInput::playerNoun==5) {
				clearScreen();
				cout << "THERE IS A CHEST ON THE WALL.  IT LOOKS STURDY. THERE IS A KEYHOLE ON THE FRONT";
				endCommand();
			}
			else {
				failThat();
			}
		}
		else if (userInput::playerVerb==6) {
			if (userInput::playerNoun==5) {
				clearScreen();
				cout << "I TRY TO OPEN THE CHEST, BUT IT IS TOO STRONG.  I SHOULD TRY TO OPEN THIS WITH SOMETHING";
				endCommand();
			}
			else if (userInput::playerNoun==6) {
				if (door==false) {
					clearScreen();
					cout << "I PULL ON THE DOOR AND IT FALLS TO THE GROUND.  THERE'S NO WALL BEHIND IT, JUST MORE STONE.  THERE'S A SMALL KEY ON THE WALL";
					door = true;
					endCommand();
				}
				else {
					clearScreen();
					cout << "THE DOOR IS LYING ON THE FOOR.  I CAN'T DO ANYTHING IMPORTANT WITH IT.";
					endCommand();
				}
			}
			else {
				failThat();
			}
		}
		else {
			failThat();
		}
	}
}

void clearScreenFirst(){ // Clear the screen and move curser to the upper left
	cout << "\033[2J\033[1;1H";
	cout << "I AM IN A SMALL STONE ROOM.  ";
	cout << "MY BARE FEET FEEL COLD ON THE STONE FLOOR.\n\n";
	sleepMilli(1000);
	cout << "VISIBLE ITEMS:\n";
	sleepMilli(500);
	cout <<"TO MY WEST I CAN SEE A STURDY WOODEN CHEST AGAINST THE WALL\n";
	sleepMilli(500);
	cout <<"TO MY SOUTH THERE IS A WOODEN DOOR\n\n";
	sleepMilli(500);
	cout <<"(TYPE 'HELP' FOR HELP)\n";
	sleepMilli(500);
	cout <<"(TYPE 'QUIT' TO QUIT)\n";
	sleepMilli(500);
	cout <<"TELL ME WHAT TO DO? ";
}

void clearScreen () {
	cout << "\033[2J\033[1;1H";
	cout << "I AM IN A SMALL STONE ROOM.  MY BARE FEET FEEL COLD ON THE STONE FLOOR.\n\nVISIBLE ITEMS:\nTO MY WEST I CAN SEE A STURDY WOODEN CHEST AGAINST THE WALL\nTO MY SOUTH THERE IS A WOODEN DOOR\n\n(TYPE 'HELP' FOR HELP)\n(TYPE 'QUIT' TO QUIT)\nTELL ME WHAT TO DO? ";
	cout << userInput::inputString;
	cout << endl <<"OK," << endl;
}

void endCommand () {
	sleepMilli(500);
	cout << endl;
	cout << "\nTELL ME WHAT TO DO? ";
}

void failThat () {
	clearScreen();
	cout << "\n\nI CAN'T " << userInput::verb << " THAT. (TYPE 'HELP' FOR HELP)\n";
	endCommand ();
}

void failThere () {
	clearScreen();
	cout << "\n\nI CAN'T " << userInput::verb << " THERE. (TYPE 'HELP' FOR HELP)\n";
	endCommand ();
}

void fail () {
	clearScreen();
	cout << "\n\nI CAN'T DO THAT. (TYPE 'HELP' FOR HELP)\n";
	endCommand ();
}

void sleepMilli(int x){ // Sleeps for X milliseconds
	this_thread::sleep_for(chrono::milliseconds(x));
}
