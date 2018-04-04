#include <iostream>
#include "../global/header.h"
#include "../global/globalFunk.h"
#include "../roomInfo/startRoom.h"
#include "../roomInfo/greenRoom.h"
#include "../roomInfo/throneRoom.h"
#include "../saveGame/save.h"
#include "../roomInfo/flavor.h"


void universalRoomCommands (std::string room) {
	using std::cout;

	if (userInput::verb=="HELP") {
			clearScreen(room);
			userInput::commandFlavor = "THE GOAL OF THIS GAME IS TO EXIT THE DUNGEON.  YOU CAN MOVE USING THE CARDINAL DIRECTIONS, AND INTERACT WITH ITEMS BY USING THEM OR TAKING THEM.  LOOK IN A DIRECTION, OR INSPECT VISIBLE ITEMS TO LEARN MORE ABOUT YOUR ENVIRONMENT.  EXCLUDING EXITING THE GAME, ALL COMMANDS MUST BE IN VERB-NOUN FORMAT EX:'WALK NORTH', 'SEARCH BAG', OR 'GRAB AXE'.";
			cout << userInput::commandFlavor;
			CSLast(room);
	}
	else if (userInput::verb=="QUIT") {
		clearScreen(room);
		userInput::playerLoc="0";
	}
	else if (userInput::verb=="HOW") {
		if (userInput::noun=="SEE") {
			clearScreen(room);
			userInput::commandFlavor = "SEE IN DARK.";
			cout << userInput::commandFlavor;
			userInput::seeInDark = true;
			CSLast(room);
		}
		else {
			fail(room);
		}
	}
	else if (userInput::verb=="SAVE") {
		if (userInput::noun=="GAME" || userInput::noun=="SAVE") {
			clearScreen(room);
			saveGame();
			userInput::commandFlavor = "THE GAME IS SAVED.";
			cout << userInput::commandFlavor;
			CSLast(room);
		}
		else {
			fail(room);
		}
	}
	else {
		fail(room);
	}
}