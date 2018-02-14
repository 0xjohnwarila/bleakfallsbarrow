//startRoom is a file that controls everything that can happen in the room the player starts with.

//TODO:
//Finish the rooms verb/noun stuff. <--done sorta
//build basic second room to practice movement. <-- done.
//cry <--- done
//move stone, key, and doorKick to the header file so that they can be global values (maybe?).
//add a 'LOOK AROUND' function that would display helpful general information about the room that's not direction-specific.
//try to fix startCS updating timing to include updates with changes to the room. <-- done
//redo LOOK:
// - cardinal directions
// - chest, door, hole, stone, key, floor, ceiling, walls
// - LOOK AROUND

#include <iostream>
#include <string>
#include <sstream>
#include <time.h>
#include <stdlib.h>
#include <limits>
#include <chrono>
#include <thread>
#include "../playerInput/inputSplit.cpp"
#include "flavor.cpp"
using namespace std;

//The stone bool checks to see if the loose stone has been moved out of the wall
//the key bool checks to see if the key in the wall has been taken
//doorKick checks how many times the door has been kicked

//initializes the different functions:
//startCSFirst displays all the room text with the sleep function included
//startCS is the same as startCSFirst without the sleep
//clear is the actual functions that clears the screen
//endCommand runs after the text for a command.  It sets up the next input line
//fail runs a text if the input is not recognized or if the verb and noun don't sync
//sleepMilli is the sleep function implemented by jWarila

void startCSFirst();
void startCS();
void startCSLast();
void greenCSFirst();
void greenCS();
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
//TAKE (KEY, STONE):
//TAKE can be used with KEY to remove it from the hole in the wall and "add it to inventory"
//It changes the key bool to true.
//Same principle for the stone.
//
//USE (CHEST, STONE, DOOR, KEY):
//USE allows the player to interact with items in the room and also use items in their inventory(KEY)
//
//LOOK (CHEST, STONE, DOOR, HOLE, NORTH, WEST, EAST, SOUTH):
//LOOK allows the player to inspect items in a room for usefull/flavorfull information
//
//OPEN (DOOR, CHEST):
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

string commandFlavor;

void startRoom () {
	if (userInput::startRoomCheck == false) {
		startRoomFlavor();
	}
	userInput::startRoomCheck = true;
	userInput::playerLoc = 2;
	startCSFirst();
	while (userInput::playerLoc==2) {
		playerInput ();
		if (userInput::verb=="HELP") {
			startCS();
			commandFlavor = "THE GOAL OF THIS GAME IS TO EXIT THE DUNGEON.  YOU CAN MOVE USING THE CARDINAL DIRECTIONS, AND INTERACT WITH ITEMS BY USING THEM OR TAKING THEM.  LOOK IN A DIRECTION, OR INSPECT VISIBLE ITEMS TO LEARN MORE ABOUT YOUR ENVIRONMENT.  EXCLUDING EXITING THE GAME, ALL COMMANDS MUST BE IN VERB-NOUN FORMAT EX:'WALK NORTH', 'SEARCH BAG', OR 'GRAB AXE'.";
			cout << commandFlavor;
			startCSLast();
		}
		else if (userInput::verb=="QUIT") {
			userInput::playerLoc=0;
		}
		else if (userInput::verb=="MOVE") {
			if (userInput::noun=="NORTH" || userInput::noun=="EAST" || userInput::noun=="WEST") {
				startCS();
				commandFlavor = "I TRY TO MOVE THROUGH THE WALL, BUT I CAN'T GET THROUGH IT.  MAYBE I SHOULD MOVE A DIFFERENT DIRECTION.";
				cout << commandFlavor;
				startCSLast ();
			}
			else if (userInput::noun=="SOUTH") {
				if (userInput::key==false) {
					if (userInput::doorKick==0) {
						startCS();
						commandFlavor = "I PULL ON THE DOOR BUT IT WON'T BUDGE.  MAYBE I SHOULD TRY KICKING IT.";
						cout << commandFlavor;
						startCSLast();
					}
					else {
						startCS();
						commandFlavor = "I PULL ON THE DOOR BUT IT WON'T BUDGE.  I DEFINITELY SHOULD NOT KICK THE DOOR.";
						cout << commandFlavor;
						userInput::doorKick++;
						startCSLast();
					}
				}
				if (userInput::key==true) {
					userInput::playerLoc = 3;
				}
			}
			else {
				fail();
			}
		}
		else if (userInput::verb=="TAKE") {
			if (userInput::noun=="KEY") {
				if (userInput::stone==true) {
					startCS();
					commandFlavor = "I TAKE THE KEY OUT OF THE HOLE IN THE WALL.  IT STICKS TO MY HAND.  I FEEL GROSS, BUT ALSO ACCOMPLISHED.";
					cout << commandFlavor;
					userInput::key = true;
					startCSLast();
				}
				else {
					fail();
				}
			}
			else if (userInput::noun=="STONE") {
				if (userInput::stone==false) {
					startCS();
					commandFlavor = "I PULL THE STONE OUT OF THE WALL.  BEHIND IT IS A HOLE WITH A SMALL GOLDEN KEY INSIDE.";
					cout << commandFlavor;
					userInput::stone = true;
					startCSLast();
				}
				else {
					startCS();
					commandFlavor = "THE STONE IS SITTING ON THE FLOOR BEING USELESS AS ALWAYS.";
					cout << commandFlavor;
					startCSLast();
				}
			}
			else {
				fail();
			}
		}
		else if (userInput::verb=="USE") {
			if (userInput::noun=="CHEST") {
				startCS();
				commandFlavor = "I TRY TO OPEN THE CHEST, BUT IT IS TOO STRONG.  I SHOULD TRY TO OPEN THIS WITH SOMETHING.";
				cout << commandFlavor;
				startCSLast();
			}
			else if (userInput::noun=="STONE") {
				if (userInput::stone==false) {
					startCS();
					commandFlavor = "I PULL THE STONE OUT OF THE WALL.  BEHIND IT IS A HOLE WITH A SMALL GOLDEN KEY INSIDE.";
					cout << commandFlavor;
					userInput::stone = true;
					startCSLast();
				}
				else {
					startCS();
					commandFlavor = "THE STONE IS SITTING ON THE FLOOR BEING USELESS AS ALWAYS.";
					cout << commandFlavor;
					startCSLast();
				}
			}
			/*else if (userInput::noun=="KEY" || userInput::noun=="DOOR") {
				if (userInput::stone==true || userInput::key==true) {
					startCS();
					cout << "I STICK THE KEY INTO THE KEYHOLE ON THE DOOR.  THE WALLS SCREAMS LOUDLY AND THE DOOR OPENS IN A FLASH OF GREEN LIGHT.  TWO WORDS APPEAR BEFORE YOU...\n";
					userInput::playerLoc=1;
				}
			}*/
			else if (userInput::noun=="KEY") {
				if (userInput::key==false) {
					fail();
				}
				else if (userInput::key == true) {
					startCS();
					commandFlavor = "I'M NOT SURE WHAT TO USE THIS ON.  THERE'S A CHEST AND A DOOR AND THEY BOTH HAVE KEYHOLES.";
					cout << commandFlavor;
					startCSLast();
				}
			}
			else if (userInput::noun=="DOOR") {
				if (userInput::key==false) {
					if (userInput::doorKick==0) {
						startCS();
						commandFlavor = "I PULL ON THE DOOR BUT IT WON'T BUDGE.  MAYBE I SHOULD TRY KICKING IT.";
						cout << commandFlavor;
						startCSLast();
					}
					else {
						startCS();
						commandFlavor = "I PULL ON THE DOOR BUT IT WON'T BUDGE.  I DEFINITELY SHOULD NOT KICK THE DOOR.";
						cout << commandFlavor;
						userInput::doorKick++;
						startCSLast();
					}
				}
				if (userInput::key==true) {
					userInput::playerLoc = 3;
				}
			}
			else {
				fail();
			}
		}
		else if (userInput::verb=="LOOK") {
			if (userInput::noun=="EAST") {
				startCS();
				commandFlavor = "I INSPECT THE OLD STONE WALLS.  I CAN FEEL THAT THIS PLACE HAS NOT FELT LIFE FOR A LONG TIME.  I UNDERSTAND THE SOLEMNITY OF MY SITUATION.  I FEEL COLD.";
				cout << commandFlavor;
				startCSLast();
			}
			else if (userInput::noun=="NORTH") {
				if (userInput::stone==false) {
					startCS();
					commandFlavor = "THE STONE IN THIS WALL LOOKS LOOSE.";
					cout << commandFlavor;
					startCSLast();
				}
				else if (userInput::stone==true || userInput::key==false) {
					startCS();
					commandFlavor = "THERE IS A KEY LYING IN THE HOLE WHERE THE STONE USED TO BE.";
					cout << commandFlavor;
					startCSLast();
				}
				else {
					startCS();
					commandFlavor = "THE HOLE IS DARK AND EMPTY, JUST LIKE MY SOUL.";
					cout << commandFlavor;
					startCSLast();
				}
			}
			else if (userInput::noun=="STONE") {
				if (userInput::stone==false) {
					startCS();
					commandFlavor = "THE STONE IN THIS WALL FEELS LOOSE.  IT SOUNDS HOLLOW.";
					cout << commandFlavor;
					startCSLast();
				}
				else {
					startCS();
					commandFlavor = "THE STONE IS SITTING ON THE FLOOR BEING USELESS AS ALWAYS.";
					cout << commandFlavor;
					startCSLast();
				}
			}
			else if (userInput::noun=="SOUTH") {
				startCS();
				commandFlavor = "THE DOOR LOOKS WORN.  THERE ARE LONG CLAW MARKS RUNNING DOWN ITS CENTER.  WHAT KIND OF BEAST DID THIS?";
				cout << commandFlavor;
				startCSLast();
				
			}
			else if (userInput::noun=="DOOR") {
				startCS();
				commandFlavor = "THIS DOOR FEELS HEAVY.  THIS WOOD IT'S MADE FROM LOOKS OLD, YET VERY STRONG.  THE GOLDEN KEYHOLE ON THE DOOR HAS DULLED ENGRAVINGS ON IT.";
				cout << commandFlavor;
				startCSLast();
			}
			else if (userInput::noun=="WEST") {
				startCS();
				commandFlavor = "THERE IS A CHEST ON THE WALL.  IT LOOKS STURDY. THERE IS A KEYHOLE ON THE FRONT.";
				cout << commandFlavor;
				startCSLast();
			}
			else if (userInput::noun=="CHEST") {
				startCS();
				commandFlavor = "ALTHOUGH ITS CRAFTED FROM WOOD, THE CHEST IS TOO HEAVY TO MOVE, AND TOO STRONG TO BREAK.";
				cout << commandFlavor;
				startCSLast();
			}
			else if (userInput::noun=="KEY") {
				if (userInput::stone == true && userInput::key == false) {
					startCS();
					commandFlavor = "THIS KEY LOOKS UNTOUCHED, AS IF IT WERE MADE YESTERDAY.  I BETTER TAKE IT BEFORE SOMEBODY ELSE DOES.";
					cout << commandFlavor;
					startCSLast();
				}
				if (userInput::key == true) {
					startCS();
					commandFlavor = "THE KEY LOOKS TOO SMALL FOR THE KEYHOLE ON THE CHEST.  IT'S ENGRAVED WITH DEPICTIONS OF A STOUT DWARF SITTING ON JEWELERY ENCRUSTED FURNITURE.";
					cout << commandFlavor;
					startCSLast();
				}
			}
			else {
				fail();
			}
		}
		else if (userInput::verb=="OPEN") {
			if (userInput::noun=="CHEST") {
				if (userInput::key == false) {
					startCS();
					commandFlavor = "I TRY TO OPEN THE CHEST, BUT IT IS TOO STRONG.  I SHOULD TRY TO OPEN THIS WITH SOMETHING.";
					cout << commandFlavor;
					startCSLast();
				}
				if (userInput::key == true) {
					startCS();
					commandFlavor = "THE GOLDEN KEY IS TOO SMALL FOR THE KEYHOLE ON THIS CHEST.  MAYBE IT FITS SOMEWHERE ELSE.";
					cout << commandFlavor;
					startCSLast();
				}
			}
			else if (userInput::noun=="DOOR") {
				if (userInput::key==false) {
					if (userInput::doorKick==0) {
						startCS();
						commandFlavor = "I PULL ON THE DOOR BUT IT WON'T BUDGE.  MAYBE I SHOULD TRY KICKING IT.";
						cout << commandFlavor;
						startCSLast();
					}
					else {
						startCS();
						commandFlavor = "I PULL ON THE DOOR BUT IT WON'T BUDGE.  I DEFINITELY SHOULD NOT KICK THE DOOR.";
						cout << commandFlavor;
						userInput::doorKick++;
						startCSLast();
					}
				}
				if (userInput::key==true) {
					userInput::playerLoc = 3;
				}
			}
			else {
				fail();
			}
		}
		else if (userInput::verb=="KICK") {
			if (userInput::noun=="DOOR") {
				if (userInput::doorKick==0) {
					startCS();
					commandFlavor = "I TRY KICKING THE DOOR BUT IT'S MUCH STRONGER THAN MY BARE FEET.  MY NOW SMASHED TOE IS IN A LOT OF PAIN.  I SHOULD KICK IT AGAIN.";
					cout << commandFlavor;
					userInput::doorKick++;
					startCSLast();
				}
				else if (userInput::doorKick==1) {
					startCS();
					commandFlavor = "I TRY KICKING THE DOOR WITH MY SMASHED TOE, BUT ALAS, THE DOOR IS STILL TOO STRONG.  WITHIN FOUR MORE KICKS, MY TOE HAS BEEN REDUCED TO A BLOODY STUMP.  THERE IS A WET PILE OF SHREDDED TOE AT THE FOOT OF THE DOOR.";
					cout << commandFlavor;
					userInput::doorKick++;
					startCSLast();
				}
				else {
					startCS();
					commandFlavor = "PLEASE STOP.  I DON'T WANT TO KICK THE DOOR ANYMORE.  JUST FIND A KEY SO WE CAN MOVE ON.";
					cout << commandFlavor;
					startCSLast();
				}
			}
			else {
				fail();
			}
		}
		else if (userInput::verb=="HOW") {
			if (userInput::noun=="SEE") {
				startCS();
				commandFlavor = "SEE IN DARK.";
				cout << commandFlavor;
				userInput::seeInDark = true;
				startCSLast();
			}
			else {
				fail();
			}
		}
		/*else if (userInput::verb=="WIGGLE") {
				if (userInput::noun=="STONE") {
				startCS();
				commandFlavor = "LISTEN ROBERT, WE DON'T WIGGLE ROCKS IN THESE PARTS.";
				cout << commandFlavor;
				startCSLast();
			}
			else {
				fail();
			}
		}*/
		else {
			fail();
		}
	}
}

void startCSFirst() {
	clear();
	cout << "I AM IN A SMALL STONE ROOM.  ";
	cout << "MY BARE FEET FEEL COLD ON THE STONE FLOOR.\n\n";
	sleepMilli(1000);
	if (userInput::seeInDark==false) {
		cout << "VISIBLE ITEMS:\n";
	}
	else if (userInput::seeInDark==true) {
		cout << "SEE IN DARK ITEMS:\n";
	}
	sleepMilli(1000);
	cout <<"TO MY WEST I CAN SEE A STURDY WOODEN CHEST AGAINST THE WALL\n";
	sleepMilli(1000);
	if (userInput::stone==false) {
		cout << "TO MY NORTH THERE IS A MYSTERIOUS STONE IN THE WALL";
	}
	else if (userInput::stone==true) {
		if (userInput::key==false) {
			cout << "TO MY NORTH THERE IS A KEY IN A HOLE";
		}
		if (userInput::key==true) {
			cout << "TO MY NORTH THERE IS AN EMPTY HOLE";
		}
	}
	cout << endl;
	sleepMilli(1000);
	if (userInput::greenRoomCheck==false) {
		cout << "TO MY SOUTH THERE IS A CLOSED WOODEN DOOR";
	}
	else if (userInput::greenRoomCheck==true) {
		cout << "TO MY SOUTH THERE IS AN OPEN WOODEN DOOR";
	}
	cout << endl;
	sleepMilli(1000);
	cout <<"\n(TYPE 'HELP' FOR HELP)\n";
	sleepMilli(1000);
	cout <<"(TYPE 'QUIT' TO QUIT)\n";
	sleepMilli(1000);
	cout <<"TELL ME WHAT TO DO? ";
}

void startCS () {
	clear();

	cout << "I AM IN A SMALL STONE ROOM.  ";
	cout << "MY BARE FEET FEEL COLD ON THE STONE FLOOR.\n\n";
	if (userInput::seeInDark==false) {
		cout << "VISIBLE ITEMS:\n";
	}
	else if (userInput::seeInDark==true) {
		cout << "SEE IN DARK ITEMS:\n";
	}
	cout <<"TO MY WEST I CAN SEE A STURDY WOODEN CHEST AGAINST THE WALL\n";
	if (userInput::stone==false) {
		cout << "TO MY NORTH THERE IS A MYSTERIOUS STONE IN THE WALL";
	}
	else if (userInput::stone==true) {
		if (userInput::key==false) {
			cout << "TO MY NORTH THERE IS A KEY IN A HOLE";
		}
		if (userInput::key==true) {
			cout << "TO MY NORTH THERE IS AN EMPTY HOLE";
		}
	}
	cout << endl;
	if (userInput::greenRoomCheck==false) {
		cout << "TO MY SOUTH THERE IS A CLOSED WOODEN DOOR";
	}
	else if (userInput::greenRoomCheck==true) {
		cout << "TO MY SOUTH THERE IS AN OPEN WOODEN DOOR";
	}
	cout << endl;
	cout <<"\n(TYPE 'HELP' FOR HELP)\n";
	cout <<"(TYPE 'QUIT' TO QUIT)\n";
	cout <<"TELL ME WHAT TO DO? ";

	cout << userInput::inputString;
	cout << endl <<"OK," << endl;
}

void startCSLast () {
	sleepMilli(500);

	clear();
	cout << "I AM IN A SMALL STONE ROOM.  ";
	cout << "MY BARE FEET FEEL COLD ON THE STONE FLOOR.\n\n";
	if (userInput::seeInDark==false) {
		cout << "VISIBLE ITEMS:\n";
	}
	else if (userInput::seeInDark==true) {
		cout << "SEE IN DARK ITEMS:\n";
	}
	cout <<"TO MY WEST I CAN SEE A STURDY WOODEN CHEST AGAINST THE WALL\n";
	if (userInput::stone==false) {
		cout << "TO MY NORTH THERE IS A MYSTERIOUS STONE IN THE WALL";
	}
	else if (userInput::stone==true) {
		if (userInput::key==false) {
			cout << "TO MY NORTH THERE IS A KEY IN A HOLE";
		}
		if (userInput::key==true) {
			cout << "TO MY NORTH THERE IS AN EMPTY HOLE";
		}
	}
	cout << endl;
	if (userInput::greenRoomCheck==false) {
		cout << "TO MY SOUTH THERE IS A CLOSED WOODEN DOOR";
	}
	else if (userInput::greenRoomCheck==true) {
		cout << "TO MY SOUTH THERE IS AN OPEN WOODEN DOOR";
	}
	cout << endl;
	cout <<"\n(TYPE 'HELP' FOR HELP)\n";
	cout <<"(TYPE 'QUIT' TO QUIT)\n";
	cout <<"TELL ME WHAT TO DO? ";

	cout << userInput::inputString;
	cout << endl <<"OK," << endl;
	cout << commandFlavor;
	endCommand();
}

void greenRoom () {
	if (userInput::greenRoomCheck == false) {
		greenRoomFlavor();
	}
	userInput::greenRoomCheck = true;
	userInput::playerLoc = 3;
	greenCSFirst();
	while (userInput::playerLoc==3) {
		playerInput ();
		if (userInput::verb=="HELP") {
			greenCS();
			cout << "THE GOAL OF THIS GAME IS TO EXIT THE DUNGEON.  YOU CAN MOVE USING THE CARDINAL DIRECTIONS, AND INTERACT WITH ITEMS BY USING THEM OR TAKING THEM.  LOOK IN A DIRECTION, OR INSPECT VISIBLE ITEMS TO LEARN MORE ABOUT YOUR ENVIRONMENT.  EXCLUDING EXITING THE GAME, ALL COMMANDS MUST BE IN VERB-NOUN FORMAT EX:'WALK NORTH', 'SEARCH BAG', OR 'GRAB AXE'.";
			endCommand();
		}
		else if (userInput::verb=="QUIT") {
			userInput::playerLoc=0;
		}
		else if (userInput::verb=="MOVE") {
			if (userInput::noun=="NORTH" || userInput::noun=="BACK") {
				userInput::playerLoc=2;
			}
			else {
				fail();
			}
		}
		/*else if (userInput::verb=="TAKE") {
			if () {
				
			}
			else {
				fail();
			}
		}
		else if (userInput::verb=="USE") {
			if () {
				
			}
			else {
				fail();
			}
		} (userInput::verb=="LOOK") {
			if () {
				
			}
			else {
				fail();
			}
		}
		else if (userInput::verb=="OPEN") {
			if () {
				
			}
			else {
				fail();
			}
		}*/
		else {
			fail();
		}
	}
}

void greenCSFirst() {
	clear();
	cout << "I AM IN A WALLED FOREST.  I HEAR BIRDS.  ";
	cout << "THE MOSSY BRICKS FEEL REFRESHING ON MY BARE FEET.\n\n";
	sleepMilli(1500);
	cout << "VISIBLE ITEMS:\n";
	sleepMilli(500);
	cout <<"TO MY EAST I CAN SEE A PILE OF BONES AND SCRAPS OF CLOTH\n";
	sleepMilli(1500);
	cout <<"TO MY NORTH I CAN SEE AN OPEN DOOR LEADING BACK TO THE STONE ROOM";
	cout << endl;
	sleepMilli(1500);
	cout << "TO MY SOUTH THERE IS A THICK WALL OF VINES";
	cout << endl;
	sleepMilli(1500);
	cout <<"\n(TYPE 'HELP' FOR HELP)\n";
	sleepMilli(500);
	cout <<"(TYPE 'QUIT' TO QUIT)\n";
	sleepMilli(500);
	cout <<"TELL ME WHAT TO DO? ";
}

void greenCS () {
	clear();
	cout << "I AM IN A WALLED FOREST.  I HEAR BIRDS.  THE MOSSY BRICKS FEEL REFRESHING ON MY BARE FEET.\n\nVISIBLE ITEMS:\nTO MY EAST I CAN SEE A PILE OF BONES AND SCRAPS OF CLOTH\nTO MY NORTH I CAN SEE AN OPEN DOOR LEADING BACK TO THE STONE ROOM\nTO MY SOUTH THERE IS A THICK WALL OF VINES\n\n(TYPE 'HELP' FOR HELP)\n(TYPE 'QUIT' TO QUIT)\nTELL ME WHAT TO DO?";
	cout << userInput::inputString;
	cout << endl <<"OK," << endl;
}

void endCommand () {
	cout << endl;
	cout << "\nTELL ME WHAT TO DO? ";
}

void fail () {
	startCS();
	cout << "I CAN'T DO THAT.\n\nMAKE SURE TO FORMAT YOUR COMMANDS IN TWO WORDS.\nTRY LOOKING IN A DIRECTION WITH LOOK.\n\n(TYPE 'HELP' FOR HELP)";
	endCommand ();
}

void sleepMilli(int x){
	this_thread::sleep_for(chrono::milliseconds(x));
}

void clear () {
	cout << "\033[2J\033[1;1H";
}
