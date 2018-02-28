//TODO:
//finish room commands
//build puzzle
//flavortext

#include <iostream>
#include "../playerInput/inputSplit.h"
#include "flavor.h"
#include "../global/header.h"
#include "throneRoom.h"
#include "../global/globalFunk.h"
#include "../combatModule/combatModule.h"

void throneRoom () {
	using std::cout;
	using std::endl;

	if (userInput::throneRoomCheck == false) {
		throneRoomFlavor();
	}
	
	if (userInput::throneRoomCheck == false) {
		CSFirst("throne", 1000);
	}
	else {
		CSFirst("throne", 200);
	}
	userInput::throneRoomCheck = true;
	userInput::playerLoc = 4;
	while (userInput::playerLoc==4) {
		playerInput ();
		if (userInput::verb=="HELP") {
			clearScreen("throne");
			cout << "THE GOAL OF THIS GAME IS TO EXIT THE DUNGEON.  YOU CAN MOVE USING THE CARDINAL DIRECTIONS, AND INTERACT WITH ITEMS BY USING THEM OR TAKING THEM.  LOOK IN A DIRECTION, OR INSPECT VISIBLE ITEMS TO LEARN MORE ABOUT YOUR ENVIRONMENT.  EXCLUDING EXITING THE GAME, ALL COMMANDS MUST BE IN VERB-NOUN FORMAT EX:'WALK NORTH', 'SEARCH BAG', OR 'GRAB AXE'.";
			endCommand();
		}
		else if (userInput::verb=="QUIT") {
			clearScreen("throne");
			userInput::playerLoc=0;
		}
		else if (userInput::verb=="WIN") {
			clearScreen("throne");
			userInput::playerLoc=1;
		}
		else if (userInput::verb=="GO") {
			if (userInput::noun=="NORTH") {
				clearScreen("throne");
				userInput::playerLoc=3;
			}
			else {
				fail("throne");
			}
		}
		else {
			fail("throne");
		}
	}
}