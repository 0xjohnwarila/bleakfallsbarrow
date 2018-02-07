#include <iostream>
#include <string>
#include <sstream>
#include <time.h>
#include <stdlib.h>
#include <limits>
#include <chrono>
#include <thread>
#include "inputSplit.cpp"
#include "mainCombat.cpp"
using namespace std;

bool stone = false;
bool key = false;
int doorKick = 0;

void clearScreenFirst();
void clearScreenDoor();
void clearScreen();
void endCommand(int x);
void fail();
void sleepMilli(int x);
void clear();

void startRoom () {
	userInput::playerLoc = 2;
	clearScreenFirst();
	while (userInput::playerLoc==2) {
		playerInput ();
		if (userInput::verb=="HELP") {
			clearScreen();
			cout << "THE GOAL OF THIS GAME IS TO EXIT THE DUNGEON.  YOU CAN MOVE USING THE CARDINAL DIRECTIONS, AND INTERACT WITH ITEMS BY USING THEM OR TAKING THEM.  LOOK IN A DIRECTION, OR INSPECT VISIBLE ITEMS TO LEARN MORE ABOUT YOUR ENVIRONMENT.  EXCLUDING EXITING THE GAME, ALL COMMANDS MUST BE IN VERB-NOUN FORMAT EX:'WALK NORTH', 'SEARCH BAG', OR 'GRAB AXE'.";
			endCommand(500);
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
				endCommand (500);
			}
			else if (userInput::noun=="SOUTH") {
				if (key==false) {
					if (doorKick==0) {
						clearScreen();
						cout << "I PULL ON THE DOOR BUT IT WON'T BUDGE.  MAYBE I SHOULD TRY KICKING IT.";
						endCommand(500);
					}
					else {
						clearScreen();
						cout << "I PULL ON THE DOOR BUT IT WON'T BUDGE.  I DEFINITELY SHOULD NOT KICK THE DOOR.";
						endCommand(500);
					}
				}
				if (key==true) {
					clearScreen();
					cout << "I STICK THE KEY INTO THE KEYHOLE ON THE DOOR.  THE WALLS SCREAMS LOUDLY AND THE DOOR OPENS IN A FLASH OF GREEN LIGHT.  TWO WORDS APPEAR BEFORE YOU...\n";
					userInput::playerLoc=1;
				}
			}
			else if (userInput::noun=="STONE") {
				if (stone==false) {
					clearScreen();
					cout << "I PULL THE STONE OUT OF THE WALL.  BEHIND IT IS A HOLE WITH A SMALL GOLDEN KEY INSIDE.";
					stone = true;
					endCommand(500);
				}
				else {
					clearScreen();
					cout << "THE STONE IS SITTING ON THE FLOOR BEING USELESS AS ALWAYS.";
					endCommand(500);
				}
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
					endCommand(500);
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
				endCommand(500);
			}
			else if (userInput::noun=="STONE") {
				if (stone==false) {
					clearScreen();
					cout << "I PULL THE STONE OUT OF THE WALL.  BEHIND IT IS A HOLE WITH A SMALL GOLDEN KEY INSIDE.";
					stone = true;
					endCommand(500);
				}
				else {
					clearScreen();
					cout << "THE STONE IS SITTING ON THE FLOOR BEING USELESS AS ALWAYS.";
					endCommand(500);
				}
			}
			/*else if (userInput::noun=="KEY" || userInput::noun=="DOOR") {
				if (stone==true || key==true) {
					clearScreen();
					cout << "I STICK THE KEY INTO THE KEYHOLE ON THE DOOR.  THE WALLS SCREAMS LOUDLY AND THE DOOR OPENS IN A FLASH OF GREEN LIGHT.  TWO WORDS APPEAR BEFORE YOU...\n";
					userInput::playerLoc=1;
				}
			}*/
			else if (userInput::noun=="DOOR") {
				if (key==false) {
					if (doorKick==0) {
						clearScreen();
						cout << "I PULL ON THE DOOR BUT IT WON'T BUDGE.  MAYBE I SHOULD TRY KICKING IT.";
						endCommand(500);
					}
					else {
						clearScreen();
						cout << "I PULL ON THE DOOR BUT IT WON'T BUDGE.  I DEFINITELY SHOULD NOT KICK THE DOOR.";
						endCommand(500);
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
				endCommand(500);
			}
			else if (userInput::noun=="NORTH" || userInput::noun=="HOLE") {
				if (stone==false) {
					clearScreen();
					cout << "THE STONE IN THIS WALL LOOKS LOOSE.";
					endCommand(500);
				}
				else if (stone==true || key==false) {
					clearScreen();
					cout << "THERE IS A KEY LAYING IN THE HOLE WHERE THE STONE USED TO BE.";
					endCommand(500);
				}
				else {
					clearScreen();
					cout << "THE HOLE IS EMPTY, JUST LIKE MY HEART.";
					endCommand(500);
				}
			}
			else if (userInput::noun=="STONE") {
				if (stone==false) {
					clearScreen();
					cout << "THE STONE IN THIS WALL LOOKS LOOSE.";
					endCommand(500);
				}
				else {
					clearScreen();
					cout << "THE STONE IS SITTING ON THE FLOOR BEING USELESS AS ALWAYS.";
					endCommand(500);
				}
			}
			else if (userInput::noun=="SOUTH" || userInput::noun=="DOOR") {
					clearScreen();
					cout << "THE DOOR IS CLOSED, BUT NOT LOCKED.  I SHOULD SEE WHAT'S ON THE OTHER SIDE.";
					endCommand(500);
				
			}
			else if (userInput::noun=="WEST" || userInput::noun=="CHEST") {
				clearScreen();
				cout << "THERE IS A CHEST ON THE WALL.  IT LOOKS STURDY. THERE IS A KEYHOLE ON THE FRONT.";
				endCommand(500);
			}
			else {
				fail();
			}
		}
		else if (userInput::verb=="OPEN") {
			if (userInput::noun=="CHEST") {
				clearScreen();
				cout << "I TRY TO OPEN THE CHEST, BUT IT IS TOO STRONG.  I SHOULD TRY TO OPEN THIS WITH SOMETHING.";
				endCommand(500);
			}
			else if (userInput::noun=="STONE") {
				if (stone==false) {
					clearScreen();
					cout << "I PULL ON THE DOOR AND IT FALLS TO THE GROUND.  THERE'S NO WALL BEHIND IT, JUST MORE STONE.  THERE'S A SMALL KEY ON THE WALL";
					stone = true;
					endCommand(500);
				}
				else {
					clearScreen();
					cout << "THE DOOR IS LYING ON THE FOOR.  I CAN'T DO ANYTHING IMPORTANT WITH IT.";
					endCommand(500);
				}
			}
			else if (userInput::noun=="DOOR") {
				if (key==false) {
					if (doorKick==0) {
						clearScreen();
						cout << "I PULL ON THE DOOR BUT IT WON'T BUDGE.  MAYBE I SHOULD TRY KICKING IT.";
						endCommand(500);
					}
					else {
						clearScreen();
						cout << "I PULL ON THE DOOR BUT IT WON'T BUDGE.  I DEFINITELY SHOULD NOT KICK THE DOOR.";
						endCommand(500);
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
					endCommand(500);
				}
				else if (doorKick==1) {
					clearScreen();
					cout << "I TRY KICKING THE DOOR WITH MY SMASHED TOE, BUT ALAS, THE DOOR IS STILL TOO STRONG.  WITHIN FOUR MORE KICKS, MY TOE HAS BEEN REDUCED TO A BLOODY STUMP.  THERE IS A WET PILE OF SHREDDED TOE AT THE FOOT OF THE DOOR.";
					doorKick++;
					endCommand(500);
				}
				else if (doorKick==2) {
					clearScreen();
					cout << "REALLY?";
					sleepMilli(1500);
					cout << endl << "YOU REALLY WANT ME TO SUFFER LIKE THIS?";
					sleepMilli(1500);
					cout << endl << "MY TOE'S ALREADY GONE.  I HAVE NO ENERGY LEFT.";
					sleepMilli(1500);
					cout << endl << "I'M LOSING BLOOD.  I'M DIZZY.  PLEASE,";
					sleepMilli(3000);
					cout << endl << "I DON'T WANT TO KICK THIS DOOR ANY LONGER.  I JUST WANT TO GO HOME.";
					doorKick++;
					endCommand(1500);
				}
				else if (doorKick==3) {
					clearScreenDoor();
					doorKick++;
					endCommand(500);
				}
				else if (doorKick==4) {
					doorKick++;
					clearScreen();
					clear();
					sleepMilli(1500);
					cout << endl << "WHERE AM I?";
					sleepMilli(1500);
					cout << endl << "\nWHERE'S THE DOOR?";
					sleepMilli(1500);
					cout << endl << "\n\nWHERE'S ANYTHING?";
					sleepMilli(1500);
					cout << endl << "\n\n\n\n\nI CAN'T FEEL MY TOE...";
					sleepMilli(1500);
					cout << endl << "\n\n\n\n\n\n\n\n\n\n\nNO.";
					sleepMilli(1500);
					cout << endl << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nSTOP.";
					sleepMilli(1500);
					cout << endl << "\nPULL YOURSELF TOGETHER";
					sleepMilli(3000);
					clear();
					sleepMilli(1000);
					cout << "WHO AM I? . . .";
					sleepMilli(1000);
					mainCombat();
				}
				else {
					clearScreen();
					cout << "NO.";
					endCommand(500);
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

void clearScreenFirst() { // Clear the screen and move curser to the upper left
	cout << "\033[2J\033[1;1H";
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

void clearScreenDoor() { // Clear the screen and move curser to the upper left
	cout << "\033[2J\033[1;1H";
	cout << "I AM IN A SMALL STONE DOOR.  ";
	cout << "MY BARE DOOR FEEL DOOR ON THE DOOR DOOR.\n\n";
	sleepMilli(1500);
	cout << "VISIBLE DOORS:\n";
	sleepMilli(500);
	cout <<"TO MY DOOR THERE IS A WEST\n";
	sleepMilli(1500);
	cout << "TO MY DOOR THERE IS A NORTH";
	cout << endl;
	sleepMilli(1500);
	cout << "TO MY DOOR THERE IS A SOUTH";
	cout << endl;
	sleepMilli(1500);
	cout << "TO MY DOOR THERE IS AN EAST";
	cout << endl;
	sleepMilli(1500);
	cout << "TO MY DOOR THERE IS A DOOR";
	cout << endl;
	sleepMilli(1500);
	cout <<"\n(TYPE 'DOOR' FOR HELP)\n";
	sleepMilli(500);
	cout <<"(TYPE 'DOOR' TO QUIT)\n";
	sleepMilli(500);
	cout <<"TELL ME WHAT TO DOOR? ";
}

void clear(){
	cout << "\033[2J\033[1;1H";
}

void clearScreen () {
	clear();
	cout << "I AM IN A SMALL STONE ROOM.  MY BARE FEET FEEL COLD ON THE STONE FLOOR.\n\nVISIBLE ITEMS:\nTO MY WEST I CAN SEE A STURDY WOODEN CHEST AGAINST THE WALL\nTO MY NORTH THERE IS A MYSTERIOUS STONE IN THE WALL\nTO MY SOUTH THERE IS AN OLD WOODEN DOOR\n\n(TYPE 'HELP' FOR HELP)\n(TYPE 'QUIT' TO QUIT)\nTELL ME WHAT TO DO? ";
	cout << userInput::inputString;
	cout << endl <<"OK," << endl;
}

void endCommand (int x) {
	sleepMilli(x);
	cout << endl;
	cout << "\nTELL ME WHAT TO DO? ";
}

void fail () {
	clearScreen();
	cout << "I CAN'T DO THAT.\n\nMAKE SURE TO FORMAT YOUR COMMANDS IN TWO WORDS WITH CAPS LOCK.\nTRY LOOKING IN A DIRECTION WITH LOOK.\n\n(TYPE 'HELP' FOR HELP)";
	endCommand (500);
}

void sleepMilli(int x){ // Sleeps for X milliseconds
	this_thread::sleep_for(chrono::milliseconds(x));
	cout << flush;
}
