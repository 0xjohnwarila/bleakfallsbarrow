//TODO:
//finish room commands
//build puzzle <- done.
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
				if (userInput::puzzleDone == false) {
					clearScreen("throne");
					userInput::commandFlavor = "I WALK ONTO A PUZZLE SQUARE";
					cout << userInput::commandFlavor;
					CSLast("throne");


					throneRoomPuzzle();
					if (userInput::puzzleLoc == 1) {
						clear();
						userInput::commandFlavor = "I STEP ONTO THE NORTH-WEST TILE, AND IT FALLS OUT FROM UNTER ME.  I QUICKLY GRAB THE SOLID TILE NEXT TO ME, BUT I CAN'T GET A GRIP ON IT.  DIGGING MY FINGERNAILS INTO THE STONE, I FALL OFF OF THE TILE AND INTO THE DARK DEPTHS BELOW IT.  WITH SURPRISE, I LAND IN A POOL OF COLD WATER.  PIRANHAS BEGIN FEROCIOUSLY TEARING ALL THE FLESH FROM MY BODY.  WITH A GARGLED SCREAM, MY BARE SKELETON FALLS TO THE SILT-COVERED FLOOR OF THE POOL.  THE ONCE CLEAR WATER IS NOW A DARK, MUDDY, AND FULL OF MY BLOOD.";
						cout << userInput::commandFlavor;
						userInput::playerLoc = "0";
					}
					else if (userInput::puzzleLoc == 3) {
						clear();
						userInput::commandFlavor = "I STEP ONTO THE NORTH-EAST TILE, AND MY FEET BEGIN TO SWEAT.  THE TILE IS HEATING QUICKLY.  I STEP BACK TO MY OLD TILE, BUT THAT TILE IS JUST AS HOT.  MY FEET BEGIN TO BURN, SO I RUN TOWARDS THE OPEN WALL.  A LARGE STONE WALL RISES FROM THE EARTH AND BLOCKS MY PATH.  HITTING THE STONE WALL, I FEEL THE TEMPERATURE IN THE ROOM RISING TO UNBEARABLE LEVELS.  I FRANTICALLY TRY TO FIND AN ESCAPE, BUT THE HEAT OF THE ROOM BURNS THE FLESH OFF OF MY BONES.  I LAY STILL ON THE STONE FLOOR AS I AM BURNED ALIVE.";
						cout << userInput::commandFlavor;
						userInput::playerLoc = "0";
					}
					else if (userInput::puzzleLoc == 4) {
						clear();
						userInput::commandFlavor = "I STEP ONTO THE WEST TILE.  WITH RELIEF, IT SEEMS THAT THIS TILE IS SAFE.  I TRY TO STEP ONTO THE SOUTH-WEST TILE, BUT I CAN'T PULL MY FEET OFF OF THE TILE.  THEY'RE STUCK WITH SOME SORT OF DARK GOO.  TRYING TO ESCAPE, I FALL INTO THE GOO SO THAT ONLY MY LEFT ARM IS FREE FROM THE STICKY SUBSTANCE.  AFTER HOURS OF STRUGGLING, IT SEEMS THAT MY ONLY WAY OUT WILL BE TO CUT MY LEGS OFF.  THE ONLY ITEM LIGHT ENOUGH FOR ME TO HOLD WITH ONE ARM IS MY KEY.  WITH A GRIMACE, I BEGIN TO STAB THE KEY INTO MY ANKLE REPEATEDLY.  LOSING BLOOD AND LOSING TIME, I FLY INTO A UNCONTROLLABLE FRENSY AND COMPLETELY DESTROY MY ANKLE UNTIL IT'S FREE.  TATTERED LIGAMENTS, SKIN, AND MUSCLE HANG FROM MY STUMP, BUT I DON'T HAVE ENOUGH ENERGY TO EVEN ATTEMPT CUTTING OFF MY OTHER LEG.  I FALL INTO A POOL OF MY OWN BLOOD AND COUGH THE REMAINING LIFE ENERGY OUT OF MY BODY.";
						cout << userInput::commandFlavor;
						userInput::playerLoc = "0";
					}
					else if (userInput::puzzleLoc == 7) {
						clear();
						userInput::commandFlavor = "SPIKES STAB MY DICK";
						cout << userInput::commandFlavor;
						userInput::playerLoc = "0";
					}
					else if (userInput::puzzleLoc == 8) {
						clear();
						userInput::commandFlavor = "AS I STEP ONTO THE SOUTH TILE, IT SINKS UNDER MY WEIGHT.  I MUST HAVE SET OFF SOME SORT OF TRAP.  WHEN I HEAR THE METALLIC NOISES OF GEARS TURNING, I BEGIN TO SPRINT BACK TOWARDS THE EXIT.  ARROWS FLY FROM ALL DIRECTIONS OUT OF HOLES IN THE WALL AND SINK INTO MY BODY, MORE THAN I CAN COUNT.  I FALL INTO A POOL OF MY OWN BLOOD AND COUGH THE REMAINING LIFE ENERGY OUT OF MY BODY.";
						cout << userInput::commandFlavor;
						userInput::playerLoc = "0";
					}
				}
				else {
					clearScreen("throne");
					userInput::commandFlavor = "(GO SOUTH)";
					cout << userInput::commandFlavor;
					CSLast("throne");
				}
			}
			else fail("throne");
		}
		else if (userInput::verb=="LOOK") {
			if (userInput::noun=="WEST" || userInput::noun=="WALLS" || userInput::noun=="WALL") {
				clearScreen("throne");
				userInput::commandFlavor = "I WALK ACROSS THE ONCE ELEGANT FLOOR TO INSPECT THE MYSTERIOUS WALL.  AS I GET CLOSER, I SEE THAT THERE IS A MESSAGE INSCRIBED ON THE WALL, \"THE ANSWER IS AT YOUR FEET.\"";
				cout << userInput::commandFlavor;
				CSLast("throne");
			}
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
		else if (userInput::verb=="LOOK") {
			if (userInput::noun=="FLOOR") {
				clearScreen("thronePuzzle");
				if (userInput::puzzleLoc == 2 || userInput::puzzleLoc == 6 || userInput::puzzleLoc == 9) {
					userInput::commandFlavor = "I LOOK AT THE TILE BELOW ME.  ETCHED INTO THE STONE TILE IS AN ARROW POINTING SOUTH.";
					cout << userInput::commandFlavor;
				}
				else if (userInput::puzzleLoc == 5) {
					userInput::commandFlavor = "I LOOK AT THE TILE BELOW ME.  ETCHED INTO THE STONE TILE IS AN ARROW POINTING EAST.";
					cout << userInput::commandFlavor;
				}
				cout << userInput::commandFlavor;
				CSLast("thronePuzzle");
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
	userInput::puzzleDone = true;
}