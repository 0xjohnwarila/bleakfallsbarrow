//startRoom is a file that controls everything that can happen in the room the player starts with.

//TODO:
//cry <-- done.
//integrate combat module <-- done.
//debug integrated combat module
//look hole
//kick chest
//look up
//look down

#include <iostream>
#include "../playerInput/inputSplit.h"
#include "flavor.h"
#include "../global/header.h"
#include "startRoom.h"
#include "../global/globalFunk.h"
#include "../combatModule/combatModule.h"

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

void startRoom () {
	using std::cout;	
	using std::endl;

	if (userInput::startRoomCheck == false) {
		startRoomFlavor();
	}

	if (userInput::startRoomCheck == false) {
		CSFirst("start", 1000);
	}
	else {
		CSFirst("start", 200);
	}
	userInput::startRoomCheck = true;
	userInput::playerLoc = 2;
	while (userInput::playerLoc==2) {
		playerInput ();
		if (userInput::verb=="HELP") {
			clearScreen("start");
			userInput::commandFlavor = "THE GOAL OF THIS GAME IS TO EXIT THE DUNGEON.  YOU CAN MOVE USING THE CARDINAL DIRECTIONS, AND INTERACT WITH ITEMS BY USING THEM OR TAKING THEM.  LOOK IN A DIRECTION, OR INSPECT VISIBLE ITEMS TO LEARN MORE ABOUT YOUR ENVIRONMENT.  EXCLUDING EXITING THE GAME, ALL COMMANDS MUST BE IN VERB-NOUN FORMAT EX:'WALK NORTH', 'SEARCH BAG', OR 'GRAB AXE'.";
			cout << userInput::commandFlavor;
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
		else if (userInput::verb=="GO") {
			if (userInput::noun=="NORTH" || userInput::noun=="EAST" || userInput::noun=="WEST") {
				clearScreen("start");
				userInput::commandFlavor = "I TRY TO MOVE THROUGH THE STONE WALL, BUT I CAN'T GET THROUGH IT.";
				cout << userInput::commandFlavor;
				CSLast("start");
			}
			else if (userInput::noun=="SOUTH") {
				if (userInput::key==false) {
					if (userInput::doorKick==0) {
						clearScreen("start");
						userInput::commandFlavor = "I PULL ON THE DOOR BUT IT WON'T BUDGE.  MAYBE I SHOULD TRY KICKING IT.";
						cout << userInput::commandFlavor;
						CSLast("start");
					}
					else {
						clearScreen("start");
						userInput::commandFlavor = "I PULL ON THE DOOR BUT IT WON'T BUDGE.  I DEFINITELY SHOULD NOT KICK THE DOOR.";
						cout << userInput::commandFlavor;
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
					if (userInput::key == false) {
						clearScreen("start");
						userInput::commandFlavor = "I TAKE THE KEY OUT OF THE HOLE IN THE WALL.  IT STICKS TO MY HAND.  I FEEL GROSS, BUT ALSO ACCOMPLISHED.";
						cout << userInput::commandFlavor;
						userInput::key = true;
						CSLast("start");
					}
					else {
						clearScreen("start");
						userInput::commandFlavor = "I AM ALREADY HOLDING THE KEY.";
						cout << userInput::commandFlavor;
						CSLast("start");
					}
				}
				else {
					fail("green");
				}
			}
			else if (userInput::noun=="STONE") {
				if (userInput::stone==false) {
					clearScreen("start");
					userInput::commandFlavor = "I PULL THE STONE OUT OF THE WALL.  BEHIND IT IS A HOLE WITH A SMALL GOLDEN KEY INSIDE.";
					cout << userInput::commandFlavor;
					userInput::stone = true;
					CSLast("start");
				}
				else {
					clearScreen("start");
					userInput::commandFlavor = "I AM ALREADY HOLDING THE STONE.";
					cout << userInput::commandFlavor;
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
					userInput::commandFlavor = "I TRY TO OPEN THE CHEST, BUT IT IS TOO STRONG.  I SHOULD TRY TO OPEN THIS WITH SOMETHING.";
					cout << userInput::commandFlavor;
					CSLast("start");
				}
				if (userInput::key == true) {
					clearScreen("start");
					userInput::commandFlavor = "THE GOLDEN KEY IS TOO SMALL FOR THE KEYHOLE ON THIS CHEST.";
					cout << userInput::commandFlavor;
					CSLast("start");
				}
			}
			else if (userInput::noun=="STONE") {
				if (userInput::stone==false) {
					clearScreen("start");
					userInput::commandFlavor = "I PULL THE STONE OUT OF THE WALL.  BEHIND IT IS A HOLE WITH A SMALL GOLDEN KEY INSIDE.";
					cout << userInput::commandFlavor;
					userInput::stone = true;
					CSLast("start");
				}
				else {
					clearScreen("start");
					userInput::commandFlavor = "THE STONE IS SITTING ON THE FLOOR BEING USELESS AS ALWAYS.";
					cout << userInput::commandFlavor;
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
					userInput::commandFlavor = "I'M NOT SURE WHAT TO USE THIS ON.  THE CHEST AND THE DOOR BOTH SEEM TO HAVE KEYHOLES.";
					cout << userInput::commandFlavor;
					CSLast("start");
				}
			}
			else if (userInput::noun=="DOOR") {
				if (userInput::key==false) {
					if (userInput::doorKick==0) {
						clearScreen("start");
						userInput::commandFlavor = "I PULL ON THE DOOR BUT IT WON'T BUDGE.  MAYBE I SHOULD TRY KICKING IT.";
						cout << userInput::commandFlavor;
						CSLast("start");
					}
					else {
						clearScreen("start");
						userInput::commandFlavor = "I PULL ON THE DOOR BUT IT WON'T BUDGE.  I DEFINITELY SHOULD NOT KICK THE DOOR.";
						cout << userInput::commandFlavor;
						userInput::doorKick++;
						CSLast("start");
					}
				}
				if (userInput::key==true) {
					if (userInput::startFight==false) {
						clearScreen("start");
						userInput::commandFlavor = "AS I OPEN THE DOOR, A SHADOWED FIGURE CHARGES ME.";
						cout << userInput::commandFlavor << endl << endl;
						enterPause();
						playerInfo::battleStatus = combatInitPrompt("RANDOM", "RANDOM", 10, 1);
						userInput::startFight = true;
						battleOver("random", "start");

						if (userInput::playerLoc != 0) {
							enterPause();
							userInput::playerLoc = 3;
						}
					}
					else {
						clearScreen("start");
						userInput::playerLoc = 3;
					}
				}
			}
			else {
				fail("start");
			}
		}
		else if (userInput::verb=="LOOK") {
			if (userInput::noun=="EAST" || userInput::noun=="WALL" || userInput::noun=="WALLS") {
				clearScreen("start");
				userInput::commandFlavor = "I INSPECT THE OLD STONE WALLS.  I CAN FEEL THAT THIS PLACE HAS NOT FELT LIFE FOR A LONG TIME.  I UNDERSTAND THE SOLEMNITY OF MY SITUATION.  I FEEL COLD.";
				cout << userInput::commandFlavor;
				CSLast("start");
			}
			else if (userInput::noun=="NORTH") {
				if (userInput::stone==false) {
					clearScreen("start");
					userInput::commandFlavor = "THE STONE IN THIS WALL LOOKS LOOSE.";
					cout << userInput::commandFlavor;
					CSLast("start");
				}
				else if (userInput::stone==true && userInput::key==false) {
					clearScreen("start");
					userInput::commandFlavor = "THERE IS A KEY LYING IN THE HOLE WHERE THE STONE USED TO BE.";
					cout << userInput::commandFlavor;
					CSLast("start");
				}
				else {
					clearScreen("start");
					userInput::commandFlavor = "THE HOLE IS DARK AND EMPTY, JUST LIKE MY SOUL.";
					cout << userInput::commandFlavor;
					CSLast("start");
				}
			}
			else if (userInput::noun=="HOLE") {
				if (userInput::stone==false) {
					fail("green");
				}
				else if (userInput::stone==true && userInput::key==false) {
					clearScreen("start");
					userInput::commandFlavor = "THERE IS A KEY LYING IN THE HOLE WHERE THE STONE USED TO BE.";
					cout << userInput::commandFlavor;
					CSLast("start");
				}
				else {
					clearScreen("start");
					userInput::commandFlavor = "THE HOLE IS DARK AND EMPTY, JUST LIKE MY SOUL.";
					cout << userInput::commandFlavor;
					CSLast("start");
				}
			}
			else if (userInput::noun=="STONE") {
				if (userInput::stone==false) {
					clearScreen("start");
					userInput::commandFlavor = "THE STONE IN THIS WALL FEELS LOOSE.  IT SOUNDS HOLLOW.";
					cout << userInput::commandFlavor;
					CSLast("start");
				}
				else {
					clearScreen("start");
					userInput::commandFlavor = "THE STONE IS SITTING ON THE FLOOR BEING USELESS AS ALWAYS.";
					cout << userInput::commandFlavor;
					CSLast("start");
				}
			}
			else if (userInput::noun=="SOUTH") {
				clearScreen("start");
				userInput::commandFlavor = "THE DOOR LOOKS WORN.  THERE ARE LONG CLAW MARKS RUNNING DOWN ITS CENTER.  WHAT KIND OF BEAST DID THIS?";
				cout << userInput::commandFlavor;
				CSLast("start");
			}
			else if (userInput::noun=="DOOR") {
				clearScreen("start");
				userInput::commandFlavor = "THIS DOOR FEELS HEAVY.  THIS WOOD IT'S MADE FROM LOOKS OLD, YET VERY STRONG.  THE GOLDEN KEYHOLE ON THE DOOR HAS DULLED ENGRAVINGS ON IT.";
				cout << userInput::commandFlavor;
				CSLast("start");
			}
			else if (userInput::noun=="WEST") {
				clearScreen("start");
				userInput::commandFlavor = "THERE IS A CHEST ON THE WALL.  IT LOOKS STURDY. THERE IS A KEYHOLE ON THE FRONT.";
				cout << userInput::commandFlavor;
				CSLast("start");
			}
			else if (userInput::noun=="CHEST") {
				clearScreen("start");
				userInput::commandFlavor = "ALTHOUGH ITS CRAFTED FROM WOOD, THE CHEST IS TOO HEAVY TO MOVE, AND TOO STRONG TO BREAK.";
				cout << userInput::commandFlavor;
				CSLast("start");
			}
			else if (userInput::noun=="KEY") {
				if (userInput::stone == true && userInput::key == false) {
					clearScreen("start");
					userInput::commandFlavor = "THIS KEY LOOKS UNTOUCHED, AS IF IT WERE MADE YESTERDAY.  I BETTER TAKE IT BEFORE SOMEBODY ELSE DOES.";
					cout << userInput::commandFlavor;
					CSLast("start");
				}
				if (userInput::key == true) {
					clearScreen("start");
					userInput::commandFlavor = "THE KEY IS MADE OF GOLD.  THE CRAFTMANSHIP IS OF THE HIGHEST LEVEL.  IT'S ENGRAVED WITH DEPICTIONS OF A STOUT DWARF.";
					cout << userInput::commandFlavor;
					CSLast("start");
				}
			}
			else if (userInput::noun=="AROUND") {
				clearScreen("start");
				userInput::commandFlavor = "THE SMALL STONE ROOM IS DIMLY LIT FROM LIGHT CREEPING FROM CRACKS IN THE CEILING.  THE WALLS LOOK TOO STRONG TO BREAK.  THE AIR IS COLD AND DAMP.  I FEEL THAT THERE'S A DARKNESS HERE.";
				cout << userInput::commandFlavor;
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
					userInput::commandFlavor = "I TRY TO OPEN THE CHEST, BUT IT IS TOO STRONG.  I SHOULD TRY TO OPEN THIS WITH SOMETHING.";
					cout << userInput::commandFlavor;
					CSLast("start");
				}
				if (userInput::key == true) {
					clearScreen("start");
					userInput::commandFlavor = "THE GOLDEN KEY IS TOO SMALL FOR THE KEYHOLE ON THIS CHEST.";
					cout << userInput::commandFlavor;
					CSLast("start");
				}
			}
			else if (userInput::noun=="DOOR") {
				if (userInput::key==false) {
					if (userInput::doorKick==0) {
						clearScreen("start");
						userInput::commandFlavor = "I PULL ON THE DOOR BUT IT WON'T BUDGE.  MAYBE I SHOULD TRY KICKING IT.";
						cout << userInput::commandFlavor;
						CSLast("start");
					}
					else {
						clearScreen("start");
						userInput::commandFlavor = "I PULL ON THE DOOR BUT IT WON'T BUDGE.  I DEFINITELY SHOULD NOT KICK THE DOOR.";
						cout << userInput::commandFlavor;
						userInput::doorKick++;
						CSLast("start");
					}
				}
				if (userInput::key==true) {
					if (userInput::startFight==false) {
						if (userInput::startFight==false) {
						clearScreen("start");
						userInput::commandFlavor = "AS I OPEN THE DOOR, A SHADOWED FIGURE CHARGES ME.";
						cout << userInput::commandFlavor << endl << endl;
						enterPause();
						playerInfo::battleStatus = combatInitPrompt("RANDOM", "RANDOM", 10, 1);
						userInput::startFight = true;
						battleOver("random", "start");

						if (userInput::playerLoc != 0) {
							enterPause();
							userInput::playerLoc = 3;
						}
					}
					else {
						clearScreen("start");
						userInput::playerLoc = 3;
					}
					}
					else {
						clearScreen("start");
						userInput::playerLoc = 3;
					}
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
					userInput::commandFlavor = "I TRY KICKING THE DOOR BUT IT'S MUCH STRONGER THAN MY BARE FEET.  MY NOW SMASHED TOE IS IN A LOT OF PAIN.  I SHOULD KICK IT AGAIN.";
					cout << userInput::commandFlavor;
					userInput::doorKick++;
					CSLast("start");
				}
				else if (userInput::doorKick==1) {
					clearScreen("start");
					userInput::commandFlavor = "I TRY KICKING THE DOOR WITH MY SMASHED TOE, BUT ALAS, THE DOOR IS STILL TOO STRONG.  WITHIN FOUR MORE KICKS, MY TOE HAS BEEN REDUCED TO A BLOODY STUMP.  THERE IS A WET PILE OF SHREDDED TOE AT THE FOOT OF THE DOOR.";
					cout << userInput::commandFlavor;
					userInput::doorKick++;
					CSLast("start");
				}
				else {
					clearScreen("start");
					userInput::commandFlavor = "PLEASE STOP.  I DON'T WANT TO KICK THE DOOR ANYMORE.  JUST FIND A KEY SO WE CAN MOVE ON.";
					cout << userInput::commandFlavor;
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
				userInput::commandFlavor = "SEE IN DARK.";
				cout << userInput::commandFlavor;
				userInput::seeInDark = true;
				CSLast("start");
			}
			else {
				fail("start");
			}
		}
		else if (userInput::verb=="START") {
			if (userInput::noun=="COMBAT") {
				clearScreen("start");
				combatInitPrompt("RANDOM", "RANDOM", 10, 1);
				userInput::commandFlavor = "THE FIGHT IS OVER.";
				cout << userInput::commandFlavor;
				CSLast("start");
			}
		}
		/*else if (userInput::verb=="WIGGLE") {
				if (userInput::noun=="STONE") {
				clearScreen("start");
				userInput::commandFlavor = "LISTEN ROBERT, WE DON'T WIGGLE ROCKS IN THESE PARTS.";
				cout << userInput::commandFlavor;
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