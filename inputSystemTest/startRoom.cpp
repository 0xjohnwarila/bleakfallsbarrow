//startRoom is a file that controls everything that can happen in the room the player starts with.

//TODO:
//Finish the room.
//build basic second room to practice movement.
//cry <--- done
//move stone, key, and doorKick to the header file so that they can be global values (maybe?).
//add a 'LOOK AROUND' function that would display helpful general information about the room that's not direction-specific.
//try to fix clearScreen updating timing to include updates with changes to the room.

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

//The stone bool checks to see if the loose stone has been moved out of the wall
//the key bool checks to see if the key in the wall has been taken
//doorKick checks how many times the door has been kicked

bool stone = false;
bool key = false;
int doorKick = 0;

//initializes the different functions:
//clearScreenFirst displays all the room text with the sleep function included
//clearScreen is the same as clearScreenFirst without the sleep
//clear is the actual functions that clears the screen
//endCommand runs after the text for a command.  It sets up the next input line
//fail runs a text if the input is not recognized or if the verb and noun don't sync
//sleepMilli is the sleep function implemented by jWarila

void clearScreenFirst();
void clearScreen();
void clear();
void endCommand();
void fail();
void sleepMilli(int x);

//startRoom is the main function that controls the room
//it is called by the main function and runs until the location of the player is updated
//the first line of if else statements checks for different verbs
//within each verb check are another set of noun checks
//if a verb and noun match (i.e. LOOK NORTH) then it will display text and change any neccesary int/bools
//
//ROOM COMMANDS:
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//HELP:
//HELP is a verb only function that gives some hints to the player about inputs and how to play
//
//QUIT:
//QUIT is another verb only function.  It sets the player location to 0,
//which exits startRoom.cpp.  Main intereperits location 0 as returning 0 and ending the program.
//
//MOVE (NORTH, SOUTH, EAST, WEST):
//MOVE can be used with the cardinal directions.  depending on the direction,
//it would change the players location number to a different room (which hasn't been built yet)
//
//TAKE (KEY):
//TAKE can be used with KEY to remove it from the hole in the wall and "add it to inventory"
//It changes the key bool to true.
//
//USE (CHEST, STONE, DOOR, KEY):
//USE allows the player to interact with items in the room and also use items in their inventory(KEY)
//
//LOOK (CHEST, STONE, DOOR, HOLE, NORTH, WEST, EAST, SOUTH):
//LOOK allows the player to inspect items in a room for usefull/flavorfull information
//
//OPEN (DOOR, CHEST, STONE):
//OPEN has the same functionality as USE but it only works on things that can be opened,
//it's a seperate function because you cant open KEYs and OPEN is too common a term
//to leave it out of the game.  Welcome.
//
//KICK (DOOR):
//the player can KICK the DOOR for some fun flavor text.  possible spinoff game in the back pocket ;)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//ROOM ITEMS:
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//DOOR:
//the DOOR is the mechanic that allows the player to travel to the adjacent room (not functioning yet)
//
//STONE:
//the STONE boolean is a loose rock in the wall of startRoom that the player can remove to find the doorKEY.
//
//KEY:
//The doorKEY(bool key) boolean allows the player to unlock the DOOR and exit the startRoom
//
//CHEST:
//The CHEST holds the item that will allow the player to leave the dungeon and win the test game.
//what is inside the CHEST and how you unlock it hasn't been implemented yet.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void startRoom () {
	userInput::playerLoc = 2;
	clearScreenFirst();
	while (userInput::playerLoc==2) {
		playerInput ();
		if (userInput::verb=="HELP") {
			clearScreen();
			cout << "THE GOAL OF THIS GAME IS TO EXIT THE DUNGEON.  YOU CAN MOVE USING THE CARDINAL DIRECTIONS, AND INTERACT WITH ITEMS BY USING THEM OR TAKING THEM.  LOOK IN A DIRECTION, OR INSPECT VISIBLE ITEMS TO LEARN MORE ABOUT YOUR ENVIRONMENT.  EXCLUDING EXITING THE GAME, ALL COMMANDS MUST BE IN VERB-NOUN FORMAT EX:'WALK NORTH', 'SEARCH BAG', OR 'GRAB AXE'.";
			endCommand();
		}
		else if (userInput::verb=="QUIT") {
			userInput::playerLoc=0;
		}
		else if (userInput::verb=="MOVE") {
			if (userInput::noun=="NORTH" || userInput::noun=="EAST" || userInput::noun=="WEST") {
				clearScreen();
				//cout << endl <<"OK,";
				cout << "I TRY TO MOVE THROUGH THE WALL, BUT I CAN'T GET THROUGH IT.  MAYBE I SHOULD MOVE A DIFFERENT DIRECTION.";
				/*sleepMilli(2000);
				cout << endl;
				sleepMilli(3000);*/
				endCommand ();
			}
			else if (userInput::noun=="SOUTH") {
					clearScreen();
					cout << "I PULL ON THE DOOR BUT IT WON'T BUDGE.  MAYBE I SHOULD TRY KICKING IT.";
					doorKick++;
					endCommand();
			}
			else {
				fail();
			}
		}
		else if (userInput::verb=="TAKE") {
			if (userInput::noun=="KEY") {
				if (stone==true) {
					clearScreen();
					cout << "I TAKE THE KEY OUT OF THE HOLE IN THE WALL.  IT STICKS TO MY HAND.  I FEEL GROSS, BUT ALSO ACCOMPLISHED.";
					key = true;
					endCommand();
				}
				else {
					fail();
				}
			}
			else {
				fail();
			}
		}
		else if (userInput::verb=="USE") {
			if (userInput::noun=="CHEST") {
				clearScreen();
				cout << "I TRY TO OPEN THE CHEST, BUT IT IS TOO STRONG.  I SHOULD TRY TO OPEN THIS WITH SOMETHING.";
				endCommand();
			}
			else if (userInput::noun=="STONE") {
				if (stone==false) {
					clearScreen();
					cout << "I PULL THE STONE OUT OF THE WALL.  BEHIND IT IS A HOLE WITH A SMALL GOLDEN KEY INSIDE.";
					stone = true;
					endCommand();
				}
				else {
					clearScreen();
					cout << "THE STONE IS SITTING ON THE FLOOR BEING USELESS AS ALWAYS.";
					endCommand();
				}
			}
			/*else if (userInput::noun=="KEY" || userInput::noun=="DOOR") {
				if (stone==true || key==true) {
					clearScreen();
					cout << "I STICK THE KEY INTO THE KEYHOLE ON THE DOOR.  THE WALLS SCREAMS LOUDLY AND THE DOOR OPENS IN A FLASH OF GREEN LIGHT.  TWO WORDS APPEAR BEFORE YOU...\n";
					userInput::playerLoc=1;
				}
			}*/
			else if (userInput::noun=="DOOR" || userInput::noun=="KEY") {
				if (key==false) {
					if (doorKick==0) {
						clearScreen();
						cout << "I PULL ON THE DOOR BUT IT WON'T BUDGE.  MAYBE I SHOULD TRY KICKING IT.";
						endCommand();
					}
					else {
						clearScreen();
						cout << "I PULL ON THE DOOR BUT IT WON'T BUDGE.  I DEFINITELY SHOULD NOT KICK THE DOOR.";
						doorKick++;
						endCommand();
					}
				}
				if (key==true) {
					clearScreen();
					cout << "I STICK THE KEY INTO THE KEYHOLE ON THE DOOR.  THE WALLS SCREAMS LOUDLY AND THE DOOR OPENS IN A FLASH OF GREEN LIGHT.  TWO WORDS APPEAR BEFORE YOU...\n";
					userInput::playerLoc=1;
				}
			}
			else {
				fail();
			}
		}
		else if (userInput::verb=="LOOK") {
			if (userInput::noun=="EAST") {
				clearScreen();
				cout << "I INSPECT THE OLD STONE WALLS.  I CAN FEEL THAT THIS PLACE HAS NOT FELT LIFE FOR A LONG TIME.  I UNDERSTAND THE SOLEMNITY OF MY SITUATION.  I FEEL COLD.";
				endCommand();
			}
			else if (userInput::noun=="NORTH" || userInput::noun=="HOLE") {
				if (stone==false) {
					clearScreen();
					cout << "THE STONE IN THIS WALL LOOKS LOOSE.";
					endCommand();
				}
				else if (stone==true || key==false) {
					clearScreen();
					cout << "THERE IS A KEY LAYING IN THE HOLE WHERE THE STONE USED TO BE.";
					endCommand();
				}
				else {
					clearScreen();
					cout << "THE HOLE IS EMPTY, JUST LIKE MY HEART.";
					endCommand();
				}
			}
			else if (userInput::noun=="STONE") {
				if (stone==false) {
					clearScreen();
					cout << "THE STONE IN THIS WALL LOOKS LOOSE.";
					endCommand();
				}
				else {
					clearScreen();
					cout << "THE STONE IS SITTING ON THE FLOOR BEING USELESS AS ALWAYS.";
					endCommand();
				}
			}
			else if (userInput::noun=="SOUTH" || userInput::noun=="DOOR") {
					clearScreen();
					cout << "THE DOOR IS CLOSED, BUT NOT LOCKED.  I SHOULD SEE WHAT'S ON THE OTHER SIDE.";
					endCommand();
				
			}
			else if (userInput::noun=="WEST" || userInput::noun=="CHEST") {
				clearScreen();
				cout << "THERE IS A CHEST ON THE WALL.  IT LOOKS STURDY. THERE IS A KEYHOLE ON THE FRONT.";
				endCommand();
			}
			else {
				fail();
			}
		}
		else if (userInput::verb=="OPEN") {
			if (userInput::noun=="CHEST") {
				clearScreen();
				cout << "I TRY TO OPEN THE CHEST, BUT IT IS TOO STRONG.  I SHOULD TRY TO OPEN THIS WITH SOMETHING.";
				endCommand();
			}
			else if (userInput::noun=="STONE") {
				if (stone==false) {
					clearScreen();
					cout << "I PULL ON THE DOOR AND IT FALLS TO THE GROUND.  THERE'S NO WALL BEHIND IT, JUST MORE STONE.  THERE'S A SMALL KEY ON THE WALL";
					stone = true;
					endCommand();
				}
				else {
					clearScreen();
					cout << "THE DOOR IS LYING ON THE FOOR.  I CAN'T DO ANYTHING IMPORTANT WITH IT.";
					endCommand();
				}
			}
			else if (userInput::noun=="DOOR") {
				if (key==false) {
					if (doorKick==0) {
						clearScreen();
						cout << "I PULL ON THE DOOR BUT IT WON'T BUDGE.  MAYBE I SHOULD TRY KICKING IT.";
						endCommand();
					}
					else {
						clearScreen();
						cout << "I PULL ON THE DOOR BUT IT WON'T BUDGE.  I DEFINITELY SHOULD NOT KICK THE DOOR.";
						endCommand();
					}
				}
				if (key==true) {
					clearScreen();
					cout << "I STICK THE KEY INTO THE KEYHOLE ON THE DOOR.  THE WALLS SCREAMS LOUDLY AND THE DOOR OPENS IN A FLASH OF GREEN LIGHT.  TWO WORDS APPEAR BEFORE YOU...\n";
					userInput::playerLoc=1;
				}
			}
			else {
				fail();
			}
		}
		else if (userInput::verb=="KICK") {
			if (userInput::noun=="DOOR") {
				if (doorKick==0) {
					clearScreen();
					cout << "I TRY KICKING THE DOOR BUT IT'S MUCH STRONGER THAN MY BARE FEET.  MY NOW SMASHED TOE IS IN A LOT OF PAIN.  I SHOULD KICK IT AGAIN.";
					doorKick++;
					endCommand();
				}
				else if (doorKick==1) {
					clearScreen();
					cout << "I TRY KICKING THE DOOR WITH MY SMASHED TOE, BUT ALAS, THE DOOR IS STILL TOO STRONG.  WITHIN FOUR MORE KICKS, MY TOE HAS BEEN REDUCED TO A BLOODY STUMP.  THERE IS A WET PILE OF SHREDDED TOE AT THE FOOT OF THE DOOR.";
					doorKick++;
					endCommand();
				}
				else {
					clearScreen();
					cout << "PLEASE STOP.  I DON'T WANT TO KICK THE DOOR ANYMORE.  JUST FIND A KEY SO WE CAN MOVE ON.";
					endCommand();
				}
			}
			else {
				fail();
			}
		}
		else {
			fail();
		}
	}
}

void clear () {
	cout << "\033[2J\033[1;1H";
}

void clearScreenFirst() {
	clear();
	cout << "I AM IN A SMALL STONE ROOM.  ";
	cout << "MY BARE FEET FEEL COLD ON THE STONE FLOOR.\n\n";
	sleepMilli(1500);
	cout << "VISIBLE ITEMS:\n";
	sleepMilli(500);
	cout <<"TO MY WEST I CAN SEE A STURDY WOODEN CHEST AGAINST THE WALL\n";
	sleepMilli(1500);
	if (stone==false) {
		cout << "TO MY NORTH THERE IS A MYSTERIOUS STONE IN THE WALL";
		cout << endl;
	}
	else if (stone==true) {
		if (key==false) {
			cout << "TO MY NORTH THERE IS A KEY IN A HOLE";
			cout << endl;
		}
		if (key==true) {
			cout << "TO MY NORTH THERE IS AN EMPTY HOLE";
			cout << endl;
		}
	}
	sleepMilli(1500);
	cout << "TO MY SOUTH THERE IS AN OLD WOODEN DOOR";
	cout << endl;
	sleepMilli(1500);
	cout <<"\n(TYPE 'HELP' FOR HELP)\n";
	sleepMilli(500);
	cout <<"(TYPE 'QUIT' TO QUIT)\n";
	sleepMilli(500);
	cout <<"TELL ME WHAT TO DO? ";
}

void clearScreen () {
	clear();
	cout << "I AM IN A SMALL STONE ROOM.  MY BARE FEET FEEL COLD ON THE STONE FLOOR.\n\nVISIBLE ITEMS:\nTO MY WEST I CAN SEE A STURDY WOODEN CHEST AGAINST THE WALL\nTO MY NORTH THERE IS A MYSTERIOUS STONE IN THE WALL\nTO MY SOUTH THERE IS AN OLD WOODEN DOOR\n\n(TYPE 'HELP' FOR HELP)\n(TYPE 'QUIT' TO QUIT)\nTELL ME WHAT TO DO? ";
	cout << userInput::inputString;
	cout << endl <<"OK," << endl;
}

void endCommand () {
	sleepMilli(500);
	cout << endl;
	cout << "\nTELL ME WHAT TO DO? ";
}

void fail () {
	clearScreen();
	cout << "I CAN'T DO THAT.\n\nMAKE SURE TO FORMAT YOUR COMMANDS IN TWO WORDS.\nTRY LOOKING IN A DIRECTION WITH LOOK.\n\n(TYPE 'HELP' FOR HELP)";
	endCommand ();
}

void sleepMilli(int x){
	this_thread::sleep_for(chrono::milliseconds(x));
}
