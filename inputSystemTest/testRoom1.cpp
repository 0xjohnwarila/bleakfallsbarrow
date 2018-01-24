#include <iostream>
#include <string>
#include <sstream>
#include "inputSplit.cpp"
using namespace std;

bool keyWall = false;
bool key = false;

void clearScreenFirst(){ // Clear the screen and move curser to the upper left
	cout << "\033[2J\033[1;1H";
	cout << "I AM IN A SMALL STONE ROOM.  MY BARE FEET FEEL COLD ON THE STONE FLOOR.\n\nVISIBLE ITEMS:\nTO MY WEST I CAN SEE A STURDY WOODEN CHEST AGAINST THE WALL\nTO MY SOUTH THERE IS A WOODEN DOOR\n\n(TYPE 'HELP' FOR HELP)\nTELL ME WHAT TO DO? ";
}

void clearScreen () {
	cout << "\033[2J\033[1;1H";
	cout << "I AM IN A SMALL STONE ROOM.  MY BARE FEET FEEL COLD ON THE STONE FLOOR.\n\nVISIBLE ITEMS:\nTO MY WEST I CAN SEE A STURDY WOODEN CHEST AGAINST THE WALL\nTO MY SOUTH THERE IS A WOODEN DOOR\n\n(TYPE 'HELP' FOR HELP)\nTELL ME WHAT TO DO? ";
	cout << userInput::inputString;
}

void test () {
	cout << "\nTELL ME WHAT TO DO? ";
}

void startRoom () {
	userInput::playerLoc = 2;
	clearScreenFirst();
	while (userInput::playerLoc==2) {
		playerInput ();
		if (userInput::playerVerb==2) {
			if (userInput::playerNoun==1 || userInput::playerNoun==2 || userInput::playerNoun==4) {
				clearScreen();
				cout << "\n\nI TRY TO MOVE THROUGH THE WALL, BUT I CAN'T GET THROUGH IT.  MAYBE I SHOULD MOVE A DIFFERENT DIRECTION.\n";
				test ();
			}
			if (userInput::playerNoun==4) {
				clearScreen();
				cout << "\n\nI PULL ON THE DOOR AND IT FALLS TO THE GROUND.  THERE'S NO WALL BEHIND IT, JUST MORE STONE.  THERE'S A SMALL KEY ON THE WALL\n";
				keyWall = true;
				test();
			}
		}
		else if (userInput::playerVerb==3) {
			if (userInput::playerNoun==9) {
				if (keyWall==true) {
					clearScreen();
					cout << "\n\nI TAKE THE KEY OFF OF THE WALL.  IT STICKS TO MY HAND.  I FEEL GROSS, BUT ALSO ACCOMPLISHED.\n";
					key = true;
					test();
				}
			}
		}
		else if (userInput::playerVerb==4) {
			if (userInput::playerNoun==9) {
				if (key==true) {
					clearScreen();
					cout << "\n\nI STICK THE KEY INTO THE KEYHOLE ON THE CHEST.  THE CHEST SCREAMS LOUDLY AND THEN OPENS IN A FLASH OF GREEN LIGHT.  TWO WORDS APPEAR BEFORE YOU...\n";
					userInput::playerLoc=1;
					test();
				}
			}
		}
		else if (userInput::playerVerb==5) {
			if (userInput::playerNoun==1 || userInput::playerNoun==2) {
				clearScreen();
				cout << "\n\nI INSPECT THE OLD STONE WALLS.  I CAN FEEL THAT THIS PLACE HAS NOT FELT LIFE FOR A LONG TIME.  I UNDERSTAND THE SOLEMNITY OF MY SITUATION.  I FEEL COLD.\n";
				test();
			}
			if (userInput::playerNoun==3) {
				clearScreen();
				cout << "\n\nTHE DOOR IS CLOSED, BUT NOT LOCKED.  I SHOULD SEE WHAT'S ON THE OTHER SIDE\n";
				test();
			}
			if (userInput::playerNoun==4) {
				clearScreen();
				cout << "\n\nI TRY TO OPEN THE CHEST, BUT IT IS TOO STRONG.  I SHOULD TRY TO OPEN THIS WITH SOMETHING\n";
				test();
			}
		}
		else {
			clearScreen();
			cout << "\n\nYOU CAN'T DO THAT.\n";
			test();
		}
	}
}