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
	userInput::playerLoc = "throne";
	while (userInput::playerLoc=="throne") {
		playerInput ();
		if (userInput::verb=="HELP") {
			clearScreen("throne");
			cout << "THE GOAL OF THIS GAME IS TO EXIT THE DUNGEON.  YOU CAN MOVE USING THE CARDINAL DIRECTIONS, AND INTERACT WITH ITEMS BY USING THEM OR TAKING THEM.  LOOK IN A DIRECTION, OR INSPECT VISIBLE ITEMS TO LEARN MORE ABOUT YOUR ENVIRONMENT.  EXCLUDING EXITING THE GAME, ALL COMMANDS MUST BE IN VERB-NOUN FORMAT EX:'WALK NORTH', 'SEARCH BAG', OR 'GRAB AXE'.";
			endCommand();
		}
		else if (userInput::verb=="QUIT") {
			clearScreen("throne");
			userInput::playerLoc = "0";
		}
		else if (userInput::verb=="WIN") {
			clearScreen("throne");
			userInput::playerLoc="WIN";
		}
		else if (userInput::verb=="GO") {
			if (userInput::noun=="NORTH") {
				clearScreen("throne");
				userInput::playerLoc="green";
			}
			else if (userInput::noun=="SOUTH") {
				clearScreen("throne");
				userInput::commandFlavor = "I WALK ONTO A PUZZLE SQUARE";
				cout << userInput::commandFlavor;
				CSLast("throne");

				throneRoomPuzzle();
				if (userInput::puzzleLoc == 1 || userInput::puzzleLoc == 3 || userInput::puzzleLoc == 4 || userInput::puzzleLoc == 7 || userInput::puzzleLoc == 8) {
					clearScreen("thronePuzzle");
					userInput::commandFlavor = "SPIKES STAB MY DICK";
					cout << userInput::commandFlavor;
					userInput::playerLoc = "0";
				}
			}
			else fail("throne");
		}
		else {
			fail("throne");
		}
	}
}

void throneRoomPuzzle() {
	using std::cout;
	using std::endl;

	userInput::puzzleLoc = 2;
	CSFirst("thronePuzzle", 0);
	while (userInput::puzzleLoc >= 1 && userInput::puzzleLoc <= 9) {
		if (userInput::puzzleLoc == 1 || userInput::puzzleLoc == 3 || userInput::puzzleLoc == 4 || userInput::puzzleLoc == 7 || userInput::puzzleLoc == 8) {
			break;
		}
		playerInput();
		if (userInput::verb=="GO") {
			if (userInput::noun=="NORTH") {
				clearScreen("thronePuzzle");
				userInput::puzzleLoc -= 3;
				userInput::commandFlavor = "I MOVE NORTH ONE TILE.";
				cout << userInput::commandFlavor;
				CSLast("thronePuzzle");
			}
			else if (userInput::noun=="SOUTH") {
				clearScreen("thronePuzzle");
				userInput::puzzleLoc += 3;
				userInput::commandFlavor = "I MOVE SOUTH ONE TILE.";
				cout << userInput::commandFlavor;
				CSLast("thronePuzzle");
			}
			else if (userInput::noun=="WEST") {
				if (userInput::puzzleLoc != 1 && userInput::puzzleLoc != 4 && userInput::puzzleLoc != 7) {
					clearScreen("thronePuzzle");
					userInput::puzzleLoc --;
					userInput::commandFlavor = "I MOVE WEST ONE TILE.";
					cout << userInput::commandFlavor;
					CSLast("thronePuzzle");
				}
				else {
					clearScreen("thronePuzzle");
					userInput::commandFlavor = "I CAN'T MOVE THAT WAY.";
					cout << userInput::commandFlavor;
					CSLast("thronePuzzle");
				}
			}
			else if (userInput::noun=="EAST") {
				if (userInput::puzzleLoc != 3 && userInput::puzzleLoc != 6 && userInput::puzzleLoc != 9) {
					clearScreen("thronePuzzle");
					userInput::puzzleLoc ++;
					userInput::commandFlavor = "I MOVE EAST ONE TILE.";
					cout << userInput::commandFlavor;
					CSLast("thronePuzzle");
				}
				else {
					clearScreen("thronePuzzle");
					userInput::commandFlavor = "I CAN'T MOVE THAT WAY.";
					cout << userInput::commandFlavor;
					CSLast("thronePuzzle");
				}
			}
			else {
				fail("thronePuzzle");
			}
		}
		else {
			fail("thronePuzzle");
		}
	}
	if (userInput::puzzleLoc < 1) {
		clearScreen("throne");
		userInput::commandFlavor = "I'M BACK WHERE I STARTED.";
		cout << userInput::commandFlavor;
		CSLast("throne");
	}
	else if (userInput::puzzleLoc > 9) {
		clearScreen("throne");
		userInput::commandFlavor = "I HAVE FINISHED THE PUZZLE.";
		cout << userInput::commandFlavor;
		CSLast("throne");
	}
}