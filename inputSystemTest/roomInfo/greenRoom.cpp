#include <iostream>
#include "../playerInput/inputSplit.h"
#include "flavor.h"
#include "../global/header.h"
#include "greenRoom.h"
#include "../global/globalFunk.h"
#include "../combatModule/combatModule.h"

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
				clearScreen("green");
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
				if (userInput::skeletonDead == false) {
					clearScreen("green");
					userInput::commandFlavor = "AS I REACH FOR THE BONES, THEY BEGIN TO RATTLE.  I PICK ONE UP, BUT IT PULLS OUT OF MY HAND.  THE BONES, RAGS, AND BROADSWORD BEGIN TO ORGANIZE THEMSELVES INTO A RAGGED, VISCIOUS SKELETON.";
					cout << userInput::commandFlavor << endl << endl;
					cout << "PRESS ENTER TO CONTINUE..." << endl;
					getchar();
					playerInfo::battleStatus = combatInitPrompt("bad", 10, 1);
					userInput::skeletonDead = true;
					battleOver("skeleton");
				}
				else {
					clearScreen("green");
					userInput::commandFlavor = "I PICK UP A BONE AND IT WITHER'S INTO DUST.  THERE'S NO MORE ENERGY TO HOLD THEM TOGETHER.";
					cout << userInput::commandFlavor;
					CSLast("green");
				}
			}
			else if (userInput::noun=="CLOTH") {
				if (userInput::skeletonDead == false) {
					clearScreen("green");
					userInput::commandFlavor = "AS I REACH FOR THE RAGS, THE BONES BEGIN TO SHAKE.  I HOLD THE RAG, BUT IT PULLS OUT OF MY HAND.  THE BONES, RAGS, AND BROADSWORD BEGIN TO ORGANIZE THEMSELVES INTO A RAGGED, VISCIOUS SKELETON.";
					cout << userInput::commandFlavor << endl << endl;
					cout << "PRESS ENTER TO CONTINUE..." << endl;
					getchar();
					playerInfo::battleStatus = combatInitPrompt("bad", 10, 1);
					userInput::skeletonDead = true;
					battleOver("skeleton");
				}
				else if (userInput::skeletonDead == true) {
					if (userInput::greenRag == false) {
						clearScreen("green");
						userInput::commandFlavor = "I PICK UP THE RAGS.  AS I'M HOLDING THEM, THEY SLOWLY FALL APART INTO DUST AND SLIP THROUGH MY FINGERS.  A SMALL BLUE LIGHT FALLS OUT OF THEM AND FLOATS OUT THROUGH THE CEILING.";
						cout << userInput::commandFlavor;
						CSLast("green");
					}
					else {
						clearScreen("green");
						userInput::commandFlavor = "THERE'S NO RAGS LEFT.  JUST A PILE OF FINE DUST.";
						cout << userInput::commandFlavor;
						CSLast("green");
					}
				}
			}
			else if (userInput::noun=="BROADSWORD") {
				if (userInput::skeletonDead == false) {
					clearScreen("green");
					userInput::commandFlavor = "AS I REACH FOR THE BROADSWORD, THE BONES BEGIN TO SHAKE.  I HOLD THE BROADSWORD, BUT IT PULLS OUT OF MY HAND.  THE BONES, RAGS, AND BROADSWORD BEGIN TO ORGANIZE THEMSELVES INTO A RAGGED, VISCIOUS SKELETON.";
					cout << userInput::commandFlavor << endl << endl;
					cout << "PRESS ENTER TO CONTINUE..." << endl;
					getchar();
					playerInfo::battleStatus = combatInitPrompt("bad", 10, 1);
					userInput::skeletonDead = true;
					battleOver("skeleton");
				}
				else if (userInput::skeletonDead == true) {
					if (userInput::skeleSword == false) {
					clearScreen("green");
					userInput::commandFlavor = "I GRAB THE BROADSWORD.  THE BONES STAY STILL AS I PICK UP THE ANCIENT SWORD.";
					cout << userInput::commandFlavor;
					userInput::skeleSword = true;
					CSLast("green");
					}
					else {
						clearScreen("green");
						userInput::commandFlavor = "I AM ALREADY HOLDING THE BROADSWORD.";
						cout << userInput::commandFlavor;
						CSLast("green");
					}
				}
				
			}
			else if (userInput::noun=="VINE" || userInput::noun=="VINES") {
				clearScreen("green");
				userInput::commandFlavor = "I PULL ON THE VINES, BUT THEY WON'T BUDGE.  THEY'RE STRONGER THAN THEY APPEAR.";
				cout << userInput::commandFlavor;
				CSLast("green");
			}
			else if (userInput::noun=="STONE") {
				clearScreen("green");
				userInput::commandFlavor = "THERE'S NOTHING I CAN DO WITH THIS BRICK";
				cout << userInput::commandFlavor;
				CSLast("green");
			}
			else {
				fail("green");
			}
		}
		else if (userInput::verb=="USE") {
			if (userInput::noun=="SKELETON") {
				if (userInput::skeletonDead == false) {
					clearScreen("green");
					userInput::commandFlavor = "AS I REACH FOR THE BONES, THEY BEGIN TO RATTLE.  I PICK ONE UP, BUT IT PULLS OUT OF MY HAND.  THE BONES, RAGS, AND BROADSWORD BEGIN TO ORGANIZE THEMSELVES INTO A RAGGED, VISCIOUS SKELETON.";
					cout << userInput::commandFlavor << endl << endl;
					cout << "PRESS ENTER TO CONTINUE..." << endl;
					getchar();
					playerInfo::battleStatus = combatInitPrompt("bad", 10, 1);
					userInput::skeletonDead = true;
					battleOver("skeleton");
				}
			}
			else if (userInput::noun=="CLOTH") {
				if (userInput::skeletonDead == false) {
					clearScreen("green");
					userInput::commandFlavor = "AS I REACH FOR THE RAGS, THE BONES BEGIN TO SHAKE.  I HOLD THE RAG, BUT IT PULLS OUT OF MY HAND.  THE BONES, RAGS, AND BROADSWORD BEGIN TO ORGANIZE THEMSELVES INTO A RAGGED, VISCIOUS SKELETON.";
					cout << userInput::commandFlavor << endl << endl;
					cout << "PRESS ENTER TO CONTINUE..." << endl;
					getchar();
					playerInfo::battleStatus = combatInitPrompt("bad", 10, 1);
					userInput::skeletonDead = true;
					battleOver("skeleton");
				}
			}
			else if (userInput::noun=="BROADSWORD") {
				if (userInput::skeletonDead == false) {
					clearScreen("green");
					userInput::commandFlavor = "AS I REACH FOR THE BROADSWORD, THE BONES BEGIN TO SHAKE.  I HOLD THE BROADSWORD, BUT IT PULLS OUT OF MY HAND.  THE BONES, RAGS, AND BROADSWORD BEGIN TO ORGANIZE THEMSELVES INTO A RAGGED, VISCIOUS SKELETON.";
					cout << userInput::commandFlavor << endl << endl;
					cout << "PRESS ENTER TO CONTINUE..." << endl;
					getchar();
					playerInfo::battleStatus = combatInitPrompt("bad", 10, 1);
					userInput::skeletonDead = true;
					battleOver("skeleton");
				}
			}
			else if (userInput::noun=="VINE" || userInput::noun=="VINES") {
				clearScreen("green");
				userInput::commandFlavor = "I PULL ON THE VINES, BUT THEY WON'T BUDGE.  THEY'RE STRONGER THAN THEY APPEAR.";
				cout << userInput::commandFlavor;
				CSLast("green");
			}
			else if (userInput::noun=="STONE") {
				clearScreen("green");
				userInput::commandFlavor = "THERE'S NOTHING I CAN DO WITH THIS BRICK";
				cout << userInput::commandFlavor;
				CSLast("green");
			}
			else {
				fail("green");
			}
		}
		else if (userInput::verb=="CUT") {
			if (userInput::noun=="VINE" || userInput::noun=="VINES") {
				if (userInput::skeleSword==false) {
					clearScreen("green");
					userInput::commandFlavor = "I PULL ON THE VINES, BUT THEY WON'T BREAK.  THEY'RE STRONGER THAN THEY APPEAR.";
					cout << userInput::commandFlavor;
					CSLast("green");
				}
				else {
					if (userInput::vineDead == false) {
						clearScreen("green");
						userInput::commandFlavor = "I SWING THE BROADSWORD AT THE THICK VINES.  AS I CUT THROUGH THEM, A DARK SLUDGE OOZES OUT OF THE LACERATIONS.  THE REMAINING VINES COME TO LIFE AND LASH OUT AT ME.";
						cout << userInput::commandFlavor << endl << endl;
						cout << "PRESS ENTER TO CONTINUE..." << endl;
						getchar();
						playerInfo::battleStatus = combatInitPrompt("vines", 20, 2);
						userInput::vineDead = true;
						battleOver("vines");
					}
					else {
						clearScreen("green");
						userInput::commandFlavor = "THE VINES ARE GONE.";
						cout << userInput::commandFlavor;
						CSLast("green");
					}
				}
			}
		}
		/*} (userInput::verb=="LOOK") {
			
		}
		else if (userInput::verb=="OPEN") {
			
		}*/
		else {
			fail("green");
		}
	}
}