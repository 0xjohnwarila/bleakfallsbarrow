#include <iostream>
#include "../playerInput/inputSplit.h"
#include "flavor.h"
#include "../global/header.h"
#include "greenRoom.h"
#include "../global/globalFunk.h"

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
				userInput::commandFlavor = "I TRY TO MOVE THROUGH THE STONE WALL, BUT I CAN'T GET THROUGH IT.";
				cout << userInput::commandFlavor;
				CSLast("green");
			}
			else if (userInput::noun=="EAST") {
				clearScreen("green");
				userInput::commandFlavor = "AS I WALK OVER TO THE EAST WALL, THE PILE OF BONES BEGIN TO RATTLE.  AT FIRST, IT'S SLOW AND SPARSE, BUT THE NEARER I GET, THE MORE DISTURBED THE BONES GET.  I BACK AWAY TOWARDS THE CENTER OF THE ROOM.";
				cout << userInput::commandFlavor;
				CSLast("green");
			}
			else if (userInput::noun=="SOUTH") {
				clearScreen("green");
				userInput::commandFlavor = "I TRY TO MOVE THROUGH THE WALL OF VINES, BUT I CAN'T GET THROUGH THEM.";
				cout << userInput::commandFlavor;
				CSLast("green");
			}
			else {
				fail("green");
			}
		}
		else if (userInput::verb=="TAKE") {
			if (userInput::noun=="SKELETON") {
				clearScreen("green");
				userInput::commandFlavor = "AS I REACH FOR THE BONES, THEY BEGIN TO RATTLE.  I PICK ONE UP, BUT IT PULLS OUT OF MY HAND.  THE BONES, RAGS, AND BROADSWORD BEGIN TO ORGANIZE THEMSELVES INTO A RAGGED, VISCIOUS SKELETON. (insert combat module).";
				cout << userInput::commandFlavor;
				CSLast("green");
			}
			if (userInput::noun=="CLOTH") {
				clearScreen("green");
				userInput::commandFlavor = "AS I REACH FOR THE RAGS, THE BONES BEGIN TO SHAKE.  I HOLD THE RAG, BUT IT PULLS OUT OF MY HAND.  THE BONES, RAGS, AND BROADSWORD BEGIN TO ORGANIZE THEMSELVES INTO A RAGGED, VISCIOUS SKELETON. (insert combat module).";
				cout << userInput::commandFlavor;
				CSLast("green");
			}
			if (userInput::noun=="BROADSWORD") {
				clearScreen("green");
				userInput::commandFlavor = "AS I REACH FOR THE BROADSWORD, THE BONES BEGIN TO SHAKE.  I HOLD THE BROADSWORD, BUT IT PULLS OUT OF MY HAND.  THE BONES, RAGS, AND BROADSWORD BEGIN TO ORGANIZE THEMSELVES INTO A RAGGED, VISCIOUS SKELETON. (insert combat module).";
				cout << userInput::commandFlavor;
				CSLast("green");
			}
			if (userInput::noun=="VINE" || userInput::noun=="VINES") {
				clearScreen("green");
				userInput::commandFlavor = "I PULL ON THE VINES, BUT THEY WON'T BUDGE.  THEY'RE STRONGER THAN THEY APPEAR.";
				cout << userInput::commandFlavor;
				CSLast("green");
			}
			if (userInput::noun=="STONE") {
				clearScreen("green");
				userInput::commandFlavor = "THERE'S NOTHING I CAN DO WITH THIS BRICK";
				cout << userInput::commandFlavor;
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