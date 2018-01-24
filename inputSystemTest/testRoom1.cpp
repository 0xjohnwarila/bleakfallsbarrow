#include <iostream>
#include <string>
#include <sstream>
#include "inputSplit.cpp"
using namespace std;

bool door = false;
bool key = false;

void clearScreenFirst(){ // Clear the screen and move curser to the upper left
	cout << "\033[2J\033[1;1H";
	cout << "I AM IN A SMALL STONE ROOM.  MY BARE FEET FEEL COLD ON THE STONE FLOOR.\n\nVISIBLE ITEMS:\nTO MY WEST I CAN SEE A STURDY WOODEN CHEST AGAINST THE WALL\nTO MY SOUTH THERE IS A WOODEN DOOR\n\n(TYPE 'HELP' FOR HELP)\n(TYPE 'QUIT' TO QUIT)\nTELL ME WHAT TO DO? ";
}

void clearScreen () {
	cout << "\033[2J\033[1;1H";
	cout << "I AM IN A SMALL STONE ROOM.  MY BARE FEET FEEL COLD ON THE STONE FLOOR.\n\nVISIBLE ITEMS:\nTO MY WEST I CAN SEE A STURDY WOODEN CHEST AGAINST THE WALL\nTO MY SOUTH THERE IS A WOODEN DOOR\n\n(TYPE 'HELP' FOR HELP)\n(TYPE 'QUIT' TO QUIT)\nTELL ME WHAT TO DO? ";
	cout << userInput::inputString;
}

void endCommand () {
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

void startRoom () {
	userInput::playerLoc = 2;
	clearScreenFirst();
	while (userInput::playerLoc==2) {
		playerInput ();
		if (userInput::playerVerb==0) {
			clearScreen();
			cout << "\n\nTHE GOAL OF THIS GAME IS TO EXIT THE DUNGEON.  YOU CAN MOVE USING THE CARDINAL DIRECTIONS, AND INTERACT WITH ITEMS BY USING THEM OR TAKING THEM.  LOOK IN A DIRECTION, OR INSPECT VISIBLE ITEMS TO LEARN MORE ABOUT YOUR ENVIRONMENT.  EXCLUDING EXITING THE GAME, ALL COMMANDS MUST BE IN VERB-NOUN FORMAT EX:'WALK NORTH' OR 'GRAB AXE'\n";
			endCommand();
		}
		else if (userInput::playerVerb==1) {
			userInput::playerLoc=0;
		}
		else if (userInput::playerVerb==2) {
			if (userInput::playerNoun==1 || userInput::playerNoun==2 || userInput::playerNoun==4) {
				clearScreen();
				cout << "\n\nI TRY TO MOVE THROUGH THE WALL, BUT I CAN'T GET THROUGH IT.  MAYBE I SHOULD MOVE A DIFFERENT DIRECTION.\n";
				endCommand ();
			}
			else if (userInput::playerNoun==3) {
				if (door==false) {
					clearScreen();
					cout << "\n\nI PULL ON THE DOOR AND IT FALLS TO THE GROUND.  THERE'S NO WALL BEHIND IT, JUST MORE STONE.  THERE'S A SMALL KEY ON THE WALL\n";
					door = true;
					endCommand();
				}
				else {
					clearScreen();
					cout << "\n\nTHE DOOR IS LYING ON THE FOOR.  I CAN'T DO ANYTHING IMPORTANT WITH IT.\n";
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
					cout << "\n\nI TAKE THE KEY OFF OF THE WALL.  IT STICKS TO MY HAND.  I FEEL GROSS, BUT ALSO ACCOMPLISHED.\n";
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
				cout << "\n\nI TRY TO OPEN THE CHEST, BUT IT IS TOO STRONG.  I SHOULD TRY TO OPEN THIS WITH SOMETHING\n";
				endCommand();
			}
			else if (userInput::playerNoun==6) {
				clearScreen();
				cout << "\n\nI PULL ON THE DOOR AND IT FALLS TO THE GROUND.  THERE'S NO WALL BEHIND IT, JUST MORE STONE.  THERE'S A SMALL KEY ON THE WALL\n";
				door = true;
				endCommand();
			}
			else if (userInput::playerNoun==9 || userInput::playerNoun==5) {
				if (door==true) {
					clearScreen();
					cout << "\n\nI STICK THE KEY INTO THE KEYHOLE ON THE CHEST.  THE CHEST SCREAMS LOUDLY AND THEN OPENS IN A FLASH OF GREEN LIGHT.  TWO WORDS APPEAR BEFORE YOU...\n";
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
				cout << "\n\nI INSPECT THE OLD STONE WALLS.  I CAN FEEL THAT THIS PLACE HAS NOT FELT LIFE FOR A LONG TIME.  I UNDERSTAND THE SOLEMNITY OF MY SITUATION.  I FEEL COLD.\n";
				endCommand();
			}
			else if (userInput::playerNoun==3 || userInput::playerNoun==6) {
				if (door==false) {
					clearScreen();
					cout << "\n\nTHE DOOR IS CLOSED, BUT NOT LOCKED.  I SHOULD SEE WHAT'S ON THE OTHER SIDE\n";
					endCommand();
				}
				else if (key==false) {
					clearScreen();
					cout << "\n\nTHERE IS A KEY STUCK TO THE STONE WALL WHERE THE DOOR USED TO BE.\n";
					endCommand();
				}
				else {
					clearScreen();
					cout << "\n\nTHERE IS A STICKY SUBSTANCE ON THE WALL WHERE THE KEY USED TO BE.\n";
					endCommand();
				}
			}
			else if (userInput::playerNoun==4 || userInput::playerNoun==5) {
				clearScreen();
				cout << "\n\nTHERE IS A CHEST ON THE WALL.  IT LOOKS STURDY. THERE IS A KEYHOLE ON THE FRONT\n";
				endCommand();
			}
			else {
				failThat();
			}
		}
		else if (userInput::playerVerb==6) {
			if (userInput::playerNoun==5) {
				clearScreen();
				cout << "\n\nI TRY TO OPEN THE CHEST, BUT IT IS TOO STRONG.  I SHOULD TRY TO OPEN THIS WITH SOMETHING\n";
				endCommand();
			}
			else if (userInput::playerNoun==6) {
				clearScreen();
				cout << "\n\nI PULL ON THE DOOR AND IT FALLS TO THE GROUND.  THERE'S JUST MORE STONE BEHIND IT.  THERE'S A SMALL GOLDEN KEY ON THE WALL\n";
				door = true;
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
}