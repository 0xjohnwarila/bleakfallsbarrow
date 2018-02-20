//startRoom is a file that controls everything that can happen in the room the player starts with.

//TODO:
//Finish the rooms verb/noun stuff. <--done sorta
//build basic second room to practice movement. <-- done.
//cry <--- done
//move stone, key, and doorKick to the header file so that they can be global values (maybe?) <-- done.
//add a 'LOOK AROUND' function that would display helpful general information about the room that's not direction-specific.
//try to fix startCS updating timing to include updates with changes to the room. <-- done
//redo LOOK:
// - cardinal directions <-- done.
// - chest, door, hole, stone, key, floor, ceiling, walls <-- done.
// - LOOK AROUND
//rewrite functions to use verb identification

#include <iostream>
#include "../playerInput/inputSplit.h"
#include "flavor.h"
#include "../global/header.h"
#include "startRoom.h"
#include "../global/globalFunk.h"

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

std::string commandFlavor;

void startRoom () {
	using std::cout;	

	if (userInput::startRoomCheck == false) {
		startRoomFlavor();
	}
	userInput::startRoomCheck = true;
	userInput::playerLoc = 2;
	CSFirst("start");
	while (userInput::playerLoc==2) {
		playerInput ();
		if (userInput::verb=="HELP") {
			clearScreen("start");
			commandFlavor = "THE GOAL OF THIS GAME IS TO EXIT THE DUNGEON.  YOU CAN MOVE USING THE CARDINAL DIRECTIONS, AND INTERACT WITH ITEMS BY USING THEM OR TAKING THEM.  LOOK IN A DIRECTION, OR INSPECT VISIBLE ITEMS TO LEARN MORE ABOUT YOUR ENVIRONMENT.  EXCLUDING EXITING THE GAME, ALL COMMANDS MUST BE IN VERB-NOUN FORMAT EX:'WALK NORTH', 'SEARCH BAG', OR 'GRAB AXE'.";
			cout << commandFlavor;
			CSLast("start");
		}
		else if (userInput::verb=="QUIT") {
			clearScreen("start");
			userInput::playerLoc=0;
		}
		else if (userInput::verb=="WIN") {
			clearScreen("start");
			userInput::playerLoc=1;
		}
		else if (userInput::verb=="MOVE") {
			if (userInput::noun=="NORTH" || userInput::noun=="EAST" || userInput::noun=="WEST") {
				clearScreen("start");
				commandFlavor = "I TRY TO MOVE THROUGH THE STONE WALL, BUT I CAN'T GET THROUGH IT.";
				cout << commandFlavor;
				CSLast("start");
			}
			else if (userInput::noun=="SOUTH") {
				if (userInput::key==false) {
					if (userInput::doorKick==0) {
						clearScreen("start");
						commandFlavor = "I PULL ON THE DOOR BUT IT WON'T BUDGE.  MAYBE I SHOULD TRY KICKING IT.";
						cout << commandFlavor;
						CSLast("start");
					}
					else {
						clearScreen("start");
						commandFlavor = "I PULL ON THE DOOR BUT IT WON'T BUDGE.  I DEFINITELY SHOULD NOT KICK THE DOOR.";
						cout << commandFlavor;
						userInput::doorKick++;
						CSLast("start");
					}
				}
				if (userInput::key==true) {
					clearScreen("start");
					userInput::playerLoc = 3;
				}
			}
			else {
				fail("start");
			}
		}
		else if (userInput::verb=="TAKE") {
			if (userInput::noun=="KEY") {
				if (userInput::stone==true) {
					clearScreen("start");
					commandFlavor = "I TAKE THE KEY OUT OF THE HOLE IN THE WALL.  IT STICKS TO MY HAND.  I FEEL GROSS, BUT ALSO ACCOMPLISHED.";
					cout << commandFlavor;
					userInput::key = true;
					CSLast("start");
				}
				else {
					fail("start");
				}
			}
			else if (userInput::noun=="STONE") {
				if (userInput::stone==false) {
					clearScreen("start");
					commandFlavor = "I PULL THE STONE OUT OF THE WALL.  BEHIND IT IS A HOLE WITH A SMALL GOLDEN KEY INSIDE.";
					cout << commandFlavor;
					userInput::stone = true;
					CSLast("start");
				}
				else {
					clearScreen("start");
					commandFlavor = "THE STONE IS SITTING ON THE FLOOR BEING USELESS AS ALWAYS.";
					cout << commandFlavor;
					CSLast("start");
				}
			}
			else {
				fail("start");
			}
		}
		else if (userInput::verb=="USE") {
			if (userInput::noun=="CHEST") {
				if (userInput::key == false) {
					clearScreen("start");
					commandFlavor = "I TRY TO OPEN THE CHEST, BUT IT IS TOO STRONG.  I SHOULD TRY TO OPEN THIS WITH SOMETHING.";
					cout << commandFlavor;
					CSLast("start");
				}
				if (userInput::key == true) {
					clearScreen("start");
					commandFlavor = "THE GOLDEN KEY IS TOO SMALL FOR THE KEYHOLE ON THIS CHEST.";
					cout << commandFlavor;
					CSLast("start");
				}
			}
			else if (userInput::noun=="STONE") {
				if (userInput::stone==false) {
					clearScreen("start");
					commandFlavor = "I PULL THE STONE OUT OF THE WALL.  BEHIND IT IS A HOLE WITH A SMALL GOLDEN KEY INSIDE.";
					cout << commandFlavor;
					userInput::stone = true;
					CSLast("start");
				}
				else {
					clearScreen("start");
					commandFlavor = "THE STONE IS SITTING ON THE FLOOR BEING USELESS AS ALWAYS.";
					cout << commandFlavor;
					CSLast("start");
				}
			}
			/*else if (userInput::noun=="KEY" || userInput::noun=="DOOR") {
				if (userInput::stone==true || userInput::key==true) {
					clearScreen("start");
					cout << "I STICK THE KEY INTO THE KEYHOLE ON THE DOOR.  THE WALLS SCREAMS LOUDLY AND THE DOOR OPENS IN A FLASH OF GREEN LIGHT.  TWO WORDS APPEAR BEFORE YOU...\n";
					userInput::playerLoc=1;
				}
			}*/
			else if (userInput::noun=="KEY") {
				if (userInput::key==false) {
					fail("start");
				}
				else if (userInput::key == true) {
					clearScreen("start");
					commandFlavor = "I'M NOT SURE WHAT TO USE THIS ON.  THE CHEST AND THE DOOR BOTH SEEM TO HAVE KEYHOLES.";
					cout << commandFlavor;
					CSLast("start");
				}
			}
			else if (userInput::noun=="DOOR") {
				if (userInput::key==false) {
					if (userInput::doorKick==0) {
						clearScreen("start");
						commandFlavor = "I PULL ON THE DOOR BUT IT WON'T BUDGE.  MAYBE I SHOULD TRY KICKING IT.";
						cout << commandFlavor;
						CSLast("start");
					}
					else {
						clearScreen("start");
						commandFlavor = "I PULL ON THE DOOR BUT IT WON'T BUDGE.  I DEFINITELY SHOULD NOT KICK THE DOOR.";
						cout << commandFlavor;
						userInput::doorKick++;
						CSLast("start");
					}
				}
				if (userInput::key==true) {
					clearScreen("start");
					userInput::playerLoc = 3;
				}
			}
			else {
				fail("start");
			}
		}
		else if (userInput::verb=="LOOK") {
			if (userInput::noun=="EAST") {
				clearScreen("start");
				commandFlavor = "I INSPECT THE OLD STONE WALLS.  I CAN FEEL THAT THIS PLACE HAS NOT FELT LIFE FOR A LONG TIME.  I UNDERSTAND THE SOLEMNITY OF MY SITUATION.  I FEEL COLD.";
				cout << commandFlavor;
				CSLast("start");
			}
			else if (userInput::noun=="NORTH") {
				if (userInput::stone==false) {
					clearScreen("start");
					commandFlavor = "THE STONE IN THIS WALL LOOKS LOOSE.";
					cout << commandFlavor;
					CSLast("start");
				}
				else if (userInput::stone==true || userInput::key==false) {
					clearScreen("start");
					commandFlavor = "THERE IS A KEY LYING IN THE HOLE WHERE THE STONE USED TO BE.";
					cout << commandFlavor;
					CSLast("start");
				}
				else {
					clearScreen("start");
					commandFlavor = "THE HOLE IS DARK AND EMPTY, JUST LIKE MY SOUL.";
					cout << commandFlavor;
					CSLast("start");
				}
			}
			else if (userInput::noun=="STONE") {
				if (userInput::stone==false) {
					clearScreen("start");
					commandFlavor = "THE STONE IN THIS WALL FEELS LOOSE.  IT SOUNDS HOLLOW.";
					cout << commandFlavor;
					CSLast("start");
				}
				else {
					clearScreen("start");
					commandFlavor = "THE STONE IS SITTING ON THE FLOOR BEING USELESS AS ALWAYS.";
					cout << commandFlavor;
					CSLast("start");
				}
			}
			else if (userInput::noun=="SOUTH") {
				clearScreen("start");
				commandFlavor = "THE DOOR LOOKS WORN.  THERE ARE LONG CLAW MARKS RUNNING DOWN ITS CENTER.  WHAT KIND OF BEAST DID THIS?";
				cout << commandFlavor;
				CSLast("start");
				
			}
			else if (userInput::noun=="DOOR") {
				clearScreen("start");
				commandFlavor = "THIS DOOR FEELS HEAVY.  THIS WOOD IT'S MADE FROM LOOKS OLD, YET VERY STRONG.  THE GOLDEN KEYHOLE ON THE DOOR HAS DULLED ENGRAVINGS ON IT.";
				cout << commandFlavor;
				CSLast("start");
			}
			else if (userInput::noun=="WEST") {
				clearScreen("start");
				commandFlavor = "THERE IS A CHEST ON THE WALL.  IT LOOKS STURDY. THERE IS A KEYHOLE ON THE FRONT.";
				cout << commandFlavor;
				CSLast("start");
			}
			else if (userInput::noun=="CHEST") {
				clearScreen("start");
				commandFlavor = "ALTHOUGH ITS CRAFTED FROM WOOD, THE CHEST IS TOO HEAVY TO MOVE, AND TOO STRONG TO BREAK.";
				cout << commandFlavor;
				CSLast("start");
			}
			else if (userInput::noun=="KEY") {
				if (userInput::stone == true && userInput::key == false) {
					clearScreen("start");
					commandFlavor = "THIS KEY LOOKS UNTOUCHED, AS IF IT WERE MADE YESTERDAY.  I BETTER TAKE IT BEFORE SOMEBODY ELSE DOES.";
					cout << commandFlavor;
					CSLast("start");
				}
				if (userInput::key == true) {
					clearScreen("start");
					commandFlavor = "THE KEY IS MADE OF GOLD.  THE CRAFTMANSHIP IS OF THE HIGHEST LEVEL.  IT'S ENGRAVED WITH DEPICTIONS OF A STOUT DWARF.";
					cout << commandFlavor;
					CSLast("start");
				}
			}
			else if (userInput::noun=="AROUND") {
				clearScreen("start");
				commandFlavor = "THE SMALL STONE ROOM IS DIMLY LIT FROM LIGHT CREEPING FROM CRACKS IN THE CEILING.  THE WALLS LOOK TOO STRONG TO BREAK.  THE AIR IS COLD AND DAMP.  I FEEL THAT THERE'S A DARKNESS HERE.";
				cout << commandFlavor;
				CSLast("start");
			}
			else {
				fail("start");
			}
		}
		else if (userInput::verb=="OPEN") {
			if (userInput::noun=="CHEST") {
				if (userInput::key == false) {
					clearScreen("start");
					commandFlavor = "I TRY TO OPEN THE CHEST, BUT IT IS TOO STRONG.  I SHOULD TRY TO OPEN THIS WITH SOMETHING.";
					cout << commandFlavor;
					CSLast("start");
				}
				if (userInput::key == true) {
					clearScreen("start");
					commandFlavor = "THE GOLDEN KEY IS TOO SMALL FOR THE KEYHOLE ON THIS CHEST.";
					cout << commandFlavor;
					CSLast("start");
				}
			}
			else if (userInput::noun=="DOOR") {
				if (userInput::key==false) {
					if (userInput::doorKick==0) {
						clearScreen("start");
						commandFlavor = "I PULL ON THE DOOR BUT IT WON'T BUDGE.  MAYBE I SHOULD TRY KICKING IT.";
						cout << commandFlavor;
						CSLast("start");
					}
					else {
						clearScreen("start");
						commandFlavor = "I PULL ON THE DOOR BUT IT WON'T BUDGE.  I DEFINITELY SHOULD NOT KICK THE DOOR.";
						cout << commandFlavor;
						userInput::doorKick++;
						CSLast("start");
					}
				}
				if (userInput::key==true) {
					clearScreen("start");
					userInput::playerLoc = 3;
				}
			}
			else {
				fail("start");
			}
		}
		else if (userInput::verb=="KICK") {
			if (userInput::noun=="DOOR") {
				if (userInput::doorKick==0) {
					clearScreen("start");
					commandFlavor = "I TRY KICKING THE DOOR BUT IT'S MUCH STRONGER THAN MY BARE FEET.  MY NOW SMASHED TOE IS IN A LOT OF PAIN.  I SHOULD KICK IT AGAIN.";
					cout << commandFlavor;
					userInput::doorKick++;
					CSLast("start");
				}
				else if (userInput::doorKick==1) {
					clearScreen("start");
					commandFlavor = "I TRY KICKING THE DOOR WITH MY SMASHED TOE, BUT ALAS, THE DOOR IS STILL TOO STRONG.  WITHIN FOUR MORE KICKS, MY TOE HAS BEEN REDUCED TO A BLOODY STUMP.  THERE IS A WET PILE OF SHREDDED TOE AT THE FOOT OF THE DOOR.";
					cout << commandFlavor;
					userInput::doorKick++;
					CSLast("start");
				}
				else {
					clearScreen("start");
					commandFlavor = "PLEASE STOP.  I DON'T WANT TO KICK THE DOOR ANYMORE.  JUST FIND A KEY SO WE CAN MOVE ON.";
					cout << commandFlavor;
					CSLast("start");
				}
			}
			else {
				fail("start");
			}
		}
		else if (userInput::verb=="HOW") {
			if (userInput::noun=="SEE") {
				clearScreen("start");
				commandFlavor = "SEE IN DARK.";
				cout << commandFlavor;
				userInput::seeInDark = true;
				CSLast("start");
			}
			else {
				fail("start");
			}
		}
		/*else if (userInput::verb=="WIGGLE") {
				if (userInput::noun=="STONE") {
				clearScreen("start");
				commandFlavor = "LISTEN ROBERT, WE DON'T WIGGLE ROCKS IN THESE PARTS.";
				cout << commandFlavor;
				CSLast("start");
			}
			else {
				fail("start");
			}
		}*/
		else {
			fail("start");
		}
	}
}

void greenRoom () {
	using std::cout;
	using std::endl;

	if (userInput::greenRoomCheck == false) {
		greenRoomFlavor();
	}
	userInput::greenRoomCheck = true;
	userInput::playerLoc = 3;
	CSFirst("green");
	while (userInput::playerLoc==3) {
		playerInput ();
		if (userInput::verb=="HELP") {
			clearScreen("green");
			cout << "THE GOAL OF THIS GAME IS TO EXIT THE DUNGEON.  YOU CAN MOVE USING THE CARDINAL DIRECTIONS, AND INTERACT WITH ITEMS BY USING THEM OR TAKING THEM.  LOOK IN A DIRECTION, OR INSPECT VISIBLE ITEMS TO LEARN MORE ABOUT YOUR ENVIRONMENT.  EXCLUDING EXITING THE GAME, ALL COMMANDS MUST BE IN VERB-NOUN FORMAT EX:'WALK NORTH', 'SEARCH BAG', OR 'GRAB AXE'.";
			endCommand();
		}
		else if (userInput::verb=="QUIT") {
			clearScreen("green");
			userInput::playerLoc=0;
		}
		else if (userInput::verb=="WIN") {
			clearScreen("green");
			userInput::playerLoc=1;
		}
		else if (userInput::verb=="MOVE") {
			if (userInput::noun=="NORTH") {
				clearScreen("start");
				userInput::playerLoc=2;
			}
			else if (userInput::noun=="WEST") {
				clearScreen("green");
				commandFlavor = "I TRY TO MOVE THROUGH THE STONE WALL, BUT I CAN'T GET THROUGH IT.";
				cout << commandFlavor;
				CSLast("green");
			}
			else if (userInput::noun=="EAST") {
				clearScreen("green");
				commandFlavor = "AS I WALK OVER TO THE EAST WALL, THE PILE OF BONES BEGIN TO RATTLE.  AT FIRST, IT'S SLOW AND SPARSE, BUT THE NEARER I GET, THE MORE DISTURBED THE BONES GET.  I BACK AWAY TOWARDS THE CENTER OF THE ROOM.";
				cout << commandFlavor;
				CSLast("green");
			}
			else if (userInput::noun=="SOUTH") {
				clearScreen("green");
				commandFlavor = "I TRY TO MOVE THROUGH THE WALL OF VINES, BUT I CAN'T GET THROUGH THEM.";
				cout << commandFlavor;
				CSLast("green");
			}
			else {
				fail("green");
			}
		}
		else if (userInput::verb=="TAKE") {
			if (userInput::noun=="SKELETON") {
				clearScreen("green");
				commandFlavor = "AS I REACH FOR THE BONES, THEY BEGIN TO RATTLE.  I PICK ONE UP, BUT IT PULLS OUT OF MY HAND.  THE BONES, RAGS, AND BROADSWORD BEGIN TO ORGANIZE THEMSELVES INTO A RAGGED, VISCIOUS SKELETON. (insert combat module).";
				cout << commandFlavor;
				CSLast("green");
			}
			if (userInput::noun=="CLOTH") {
				clearScreen("green");
				commandFlavor = "AS I REACH FOR THE RAGS, THE BONES BEGIN TO SHAKE.  I HOLD THE RAG, BUT IT PULLS OUT OF MY HAND.  THE BONES, RAGS, AND BROADSWORD BEGIN TO ORGANIZE THEMSELVES INTO A RAGGED, VISCIOUS SKELETON. (insert combat module).";
				cout << commandFlavor;
				CSLast("green");
			}
			if (userInput::noun=="BROADSWORD") {
				clearScreen("green");
				commandFlavor = "AS I REACH FOR THE BROADSWORD, THE BONES BEGIN TO SHAKE.  I HOLD THE BROADSWORD, BUT IT PULLS OUT OF MY HAND.  THE BONES, RAGS, AND BROADSWORD BEGIN TO ORGANIZE THEMSELVES INTO A RAGGED, VISCIOUS SKELETON. (insert combat module).";
				cout << commandFlavor;
				CSLast("green");
			}
			if (userInput::noun=="VINE" || userInput::noun=="VINES") {
				clearScreen("green");
				commandFlavor = "I PULL ON THE VINES, BUT THEY WON'T BUDGE.  THEY'RE STRONGER THAN THEY APPEAR.";
				cout << commandFlavor;
				CSLast("green");
			}
			if (userInput::noun=="STONE") {
				clearScreen("green");
				commandFlavor = "THERE'S NOTHING I CAN DO WITH THIS BRICK";
				cout << commandFlavor;
				CSLast("green");
			}
			else {
				fail("green");
			}
		}
		/*else if (userInput::verb=="USE") {
			if () {
				
			}
			else {
				fail("start");
			}
		} (userInput::verb=="LOOK") {
			if () {
				
			}
			else {
				fail("start");
			}
		}
		else if (userInput::verb=="OPEN") {
			if () {
				
			}
			else {
				fail("start");
			}
		}*/
		else {
			fail("green");
		}
	}
}

void CSFirst(std::string room) {
	using std::cout;
	using std::endl;

	clear();

	if (room=="start") {
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
	}	

	if (room=="green") {
		cout << "I AM IN A WALLED FOREST.  I HEAR BIRDS.  ";
		cout << "THE MOSSY BRICKS FEEL REFRESHING ON MY BARE FEET.\n\n";
		sleepMilli(1000);
		cout << "VISIBLE ITEMS:\n";
		sleepMilli(1000);
		cout <<"TO MY EAST I CAN SEE A PILE OF BONES, CLOTH, AND A RUSTY BROADSWORD\n";
		sleepMilli(1000);
		cout <<"TO MY NORTH I CAN SEE AN OPEN DOOR";
		cout << endl;
		sleepMilli(1000);
		cout << "TO MY SOUTH THERE IS A THICK WALL OF VINES";
	}

	cout << endl;
	sleepMilli(1000);
	cout <<"\n(TYPE 'HELP' FOR HELP)\n";
	sleepMilli(1000);
	cout <<"(TYPE 'QUIT' TO QUIT)\n";
	sleepMilli(1000);
	cout <<"TELL ME WHAT TO DO? ";
}

void clearScreen (std::string room) {
	using std::cout;
	using std::endl;

	clear();

	if (room=="start") {
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
	}

	if (room=="green") {
		cout << "I AM IN A WALLED FOREST.  I HEAR BIRDS.  ";
		cout << "THE MOSSY BRICKS FEEL REFRESHING ON MY BARE FEET.\n\n";
		cout << "VISIBLE ITEMS:\n";
		cout <<"TO MY EAST I CAN SEE A PILE OF BONES, CLOTH, AND A RUSTY BROADSWORD\n";
		cout <<"TO MY NORTH I CAN SEE AN OPEN DOOR";
		cout << endl;
		cout << "TO MY SOUTH THERE IS A THICK WALL OF VINES";
	}
	cout << endl;
	cout <<"\n(TYPE 'HELP' FOR HELP)\n";
	cout <<"(TYPE 'QUIT' TO QUIT)\n";
	cout <<"TELL ME WHAT TO DO? ";

	cout << userInput::inputString;
	cout << endl <<"OK," << endl;
	sleepMilli(500);
}

void CSLast (std::string room) {
	using std::cout;
	using std::endl;

	clear();

	if (room=="start") {
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
	}

	if (room=="green") {
		cout << "I AM IN A WALLED FOREST.  I HEAR BIRDS.  ";
		cout << "THE MOSSY BRICKS FEEL REFRESHING ON MY BARE FEET.\n\n";
		cout << "VISIBLE ITEMS:\n";
		cout <<"TO MY EAST I CAN SEE A PILE OF BONES, CLOTH, AND A RUSTY BROADSWORD\n";
		cout <<"TO MY NORTH I CAN SEE AN OPEN DOOR";
		cout << endl;
		cout << "TO MY SOUTH THERE IS A THICK WALL OF VINES";
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

void fail (std::string room) {
	using std::cout;
	using std::endl;

	clearScreen(room);
	sleepMilli(500);
	cout << "I CAN'T DO THAT.\n\nMAKE SURE TO FORMAT YOUR COMMANDS IN TWO WORDS.\nTRY LOOKING IN A DIRECTION WITH LOOK.\n\n(TYPE 'HELP' FOR HELP)";
	endCommand ();
}

void endCommand () {
	using std::cout;
	using std::endl;

	cout << endl;
	cout << "\nTELL ME WHAT TO DO? ";
}
