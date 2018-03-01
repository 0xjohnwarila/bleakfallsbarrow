//TODO:
//TAKE ASH

#include <iostream>
#include "../playerInput/inputSplit.h"
#include "flavor.h"
#include "../global/header.h"
#include "greenRoom.h"
#include "../global/globalFunk.h"
#include "../combatModule/combatModule.h"
#include "stdio.h"

void greenRoom () {
	using std::cout;
	using std::endl;

	if (userInput::greenRoomCheck == false) {
		greenRoomFlavor();
	}
	
	if (userInput::greenRoomCheck == false) {
		CSFirst("green", 1000);
	}
	else {
		CSFirst("green", 200);
	}
	userInput::greenRoomCheck = true;
	userInput::playerLoc = "green";
	while (userInput::playerLoc=="green") {
		playerInput ();
		if (userInput::verb=="HELP") {
			clearScreen("green");
			cout << "THE GOAL OF THIS GAME IS TO EXIT THE DUNGEON.  YOU CAN MOVE USING THE CARDINAL DIRECTIONS, AND INTERACT WITH ITEMS BY USING THEM OR TAKING THEM.  LOOK IN A DIRECTION, OR INSPECT VISIBLE ITEMS TO LEARN MORE ABOUT YOUR ENVIRONMENT.  EXCLUDING EXITING THE GAME, ALL COMMANDS MUST BE IN VERB-NOUN FORMAT EX:'WALK NORTH', 'SEARCH BAG', OR 'GRAB AXE'.";
			endCommand();
		}
		else if (userInput::verb=="QUIT") {
			clearScreen("green");
			userInput::playerLoc = "0";
		}
		else if (userInput::verb=="WIN") {
			clearScreen("green");
			userInput::playerLoc="WIN";
		}
		else if (userInput::verb=="GO") {
			if (userInput::noun=="NORTH") {
				clearScreen("green");
				userInput::playerLoc="start";
			}
			else if (userInput::noun=="WEST") {
				clearScreen("green");
				userInput::commandFlavor = "SUNSHINE FALLS ONTO THE WET STONE WALL.  AS I GET CLOSER, I SEE THAT THERE IS A MESSAGE INSCRIBED ON THE WALL, \"DON'T TRUST THE VINES.\"";
				cout << userInput::commandFlavor;
				CSLast("green");
			}
			else if (userInput::noun=="EAST") {
				if (userInput::skeletonDead == false) {
					clearScreen("green");
					userInput::commandFlavor = "AS I WALK OVER TO THE EAST WALL, THE PILE OF BONES BEGIN TO RATTLE.  AT FIRST, IT'S SLOW AND SPARSE, BUT THE NEARER I GET, THE MORE DISTURBED THE BONES GET.  I BACK AWAY TOWARDS THE CENTER OF THE ROOM.";
					cout << userInput::commandFlavor;
					CSLast("green");
				}
				else {
					clearScreen("green");
					userInput::commandFlavor = "I INSPECT THE OLD STONE WALLS.  I CAN FEEL THAT THIS PLACE HAS NOT FELT FREE FOR A LONG TIME.  I UNDERSTAND THE DEPTH OF MY SITUATION.  I FEEL TIRED.";
					cout << userInput::commandFlavor;
					CSLast("green");
				}
			}
			else if (userInput::noun=="SOUTH") {
				if (userInput::vineDead == false) {
					clearScreen("green");
					userInput::commandFlavor = "I TRY TO MOVE THROUGH THE WALL OF VINES, BUT I CAN'T GET THROUGH THEM.  ONE LASHES OUT AT ME.  I LOSE 3 HEALTH";
					cout << userInput::commandFlavor;
					playerInfo::playerHealth = playerInfo::playerHealth - 3;
					CSLast("green");
				}
				else {
					clearScreen("green");
					userInput::playerLoc = "throne";
				}
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
					playerInfo::battleStatus = combatInitPrompt("THE VICIOUS SKELETON", "A RUSTY BROADSWORD", 10, 1);
					userInput::skeletonDead = true;
					battleOver("skeleton", "");
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
					playerInfo::battleStatus = combatInitPrompt("THE VICIOUS SKELETON", "A RUSTY BROADSWORD", 10, 1);
					userInput::skeletonDead = true;
					battleOver("skeleton", "");
				}
				else if (userInput::skeletonDead == true) {
					if (userInput::greenRag == false) {
						clearScreen("green");
						userInput::commandFlavor = "I PICK UP THE RAGS.  THEY'RE FRAIL, BUT I CAN STILL USE THEM.";
						cout << userInput::commandFlavor;
						userInput::greenRag = true;
						CSLast("green");
					}
					else {
						clearScreen("green");
						userInput::commandFlavor = "I'M ALREADY HOLDING THE RAGS.";
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
					playerInfo::battleStatus = combatInitPrompt("THE VICIOUS SKELETON", "A RUSTY BROADSWORD", 10, 1);
					userInput::skeletonDead = true;
					battleOver("skeleton", "");
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
				else {
					fail("green");
				}
			}
			else if (userInput::noun=="VINE") {
				if (userInput::vineDead == false) {
					clearScreen("green");
					userInput::commandFlavor = "I PULL ON THE VINES, BUT THEY WON'T BUDGE.  THEY'RE STRONGER THAN THEY APPEAR.";
					cout << userInput::commandFlavor;
					CSLast("green");
				}
				else {
					clearScreen("green");
					userInput::commandFlavor = "THE VINES ARE TO SHRIVELED AND FRAGILE TO DO ANYTHING WITH.";
					cout << userInput::commandFlavor;
					CSLast("green");
				}
			}
			else if (userInput::noun=="STONE") {
				clearScreen("green");
				userInput::commandFlavor = "THERE'S NOTHING I CAN DO WITH THIS BRICK";
				cout << userInput::commandFlavor;
				CSLast("green");
			}
			else if (userInput::noun=="ASH") {
				if (userInput::skeletonDead==true) {
					clearScreen("green");
					userInput::commandFlavor = "THE ASH IS SO FINE THAT IT SLIPS THROUGH MY FINGERS.  THERE'S NO A TRACE OF IT ON MY HANDS.";
					cout << userInput::commandFlavor;
					CSLast("green");
				}
				else {
					fail("green");
				}
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
					playerInfo::battleStatus = combatInitPrompt("THE VICIOUS SKELETON", "A RUSTY BROADSWORD", 10, 1);
					userInput::skeletonDead = true;
					battleOver("skeleton", "");
				}
				else {
					clearScreen("green");
					userInput::commandFlavor = "THE BONES DISINTEGRATE WHEN I TRY TO PICK THEM UP.";
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
					playerInfo::battleStatus = combatInitPrompt("THE VICIOUS SKELETON", "A RUSTY BROADSWORD", 10, 1);
					userInput::skeletonDead = true;
					battleOver("skeleton", "");
				}
				else {
					if (userInput::greenRag == false) {
						clearScreen("green");
						userInput::commandFlavor = "I PICK UP THE RAGS.  THEY'RE FRAIL, BUT I CAN STILL USE THEM.";
						cout << userInput::commandFlavor;
						userInput::greenRag = true;
						CSLast("green");
					}
					else {
						clearScreen("green");
						userInput::commandFlavor = "I CAN'T DO ANYTHING WITH THE RAGS.";
						cout << userInput::commandFlavor;
						CSLast("green");
					}
				}
			}
			else if (userInput::noun=="BROADSWORD") {
				if (userInput::skeleSword==true) {
					if (userInput::skeletonDead == false) {
						clearScreen("green");
						userInput::commandFlavor = "AS I REACH FOR THE BROADSWORD, THE BONES BEGIN TO SHAKE.  I HOLD THE BROADSWORD, BUT IT PULLS OUT OF MY HAND.  THE BONES, RAGS, AND BROADSWORD BEGIN TO ORGANIZE THEMSELVES INTO A RAGGED, VISCIOUS SKELETON.";
						cout << userInput::commandFlavor << endl << endl;
						cout << "PRESS ENTER TO CONTINUE..." << endl;
						getchar();
						playerInfo::battleStatus = combatInitPrompt("THE VICIOUS SKELETON", "A RUSTY BROADSWORD", 10, 1);
						userInput::skeletonDead = true;
						battleOver("skeleton", "");
					}
					else {
						if (userInput::vineDead == false) {
							clearScreen("green");
							userInput::commandFlavor = "I SWING THE BROADSWORD AT THE THICK VINES.  AS I CUT THROUGH THEM, A DARK SLUDGE OOZES OUT OF THE LACERATIONS.  THE REMAINING VINES COME TO LIFE AND LASH OUT AT ME.";
							cout << userInput::commandFlavor << endl << endl;
							cout << "PRESS ENTER TO CONTINUE..." << endl;
							getchar();
							playerInfo::battleStatus = combatInitPrompt("THE EVER-VINED HORROR", "THORNY VINES", 20, 2);
							userInput::vineDead = true;
							battleOver("vines", "");
						}
						else {
							clearScreen("green");
							userInput::commandFlavor = "THE VINES ARE GONE.";
							cout << userInput::commandFlavor;
							CSLast("green");
						}
					}
				}
				else {
					fail("green");
				}
			}
			else if (userInput::noun=="VINE") {
				if (userInput::vineDead == false) {
					clearScreen("green");
					userInput::commandFlavor = "I PULL ON THE VINES, BUT THEY WON'T BUDGE.  THEY'RE STRONGER THAN THEY APPEAR.";
					cout << userInput::commandFlavor;
					CSLast("green");
				}
				else {
					clearScreen("green");
					userInput::commandFlavor = "THE VINES ARE TO SHRIVELED AND FRAGILE TO DO ANYTHING WITH.";
					cout << userInput::commandFlavor;
					CSLast("green");
				}
			}
			else if (userInput::noun=="STONE") {
				clearScreen("green");
				userInput::commandFlavor = "THERE'S NOTHING I CAN DO WITH THESE BRICKS";
				cout << userInput::commandFlavor;
				CSLast("green");
			}
			else if (userInput::noun=="DOOR") {
				clearScreen("green");
				userInput::playerLoc = "start";
			}
			else if (userInput::noun=="ASH") {
				if (userInput::skeletonDead==true) {
					clearScreen("green");
					userInput::commandFlavor = "THE ASH IS SO FINE THAT IT SLIPS THROUGH MY FINGERS.  THERE'S NO A TRACE OF IT ON MY HANDS.";
					cout << userInput::commandFlavor;
					CSLast("green");
				}
				else {
					fail("green");
				}
			}
			else {
				fail("green");
			}
		}
		else if (userInput::verb=="CUT") {
			if (userInput::noun=="VINE") {
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
						playerInfo::battleStatus = combatInitPrompt("THE EVER-VINED HORROR", "THORNY VINES", 20, 2);
						userInput::vineDead = true;
						battleOver("vines", "");
					}
					else {
						clearScreen("green");
						userInput::commandFlavor = "THE VINES ARE GONE.";
						cout << userInput::commandFlavor;
						CSLast("green");
					}
				}
			}
			else {
				fail("green");
			}
		}
		else if (userInput::verb=="LOOK") {
			if (userInput::noun=="NORTH") {
				clearScreen("green");
				userInput::commandFlavor = "THE DOOR IS WIDE OPEN.  THE DOOR LOOKS WORN.  THERE ARE LONG CLAW MARKS RUNNING DOWN ITS CENTER.  WHAT KIND OF BEAST DID THIS?";
				cout << userInput::commandFlavor;
				CSLast("green");
			}
			else if (userInput::noun=="SOUTH") {
				if (userInput::vineDead == false) {
					clearScreen("green");
					userInput::commandFlavor = "THE VINES LOOK ROUGH LIKE LEATHER.  THEY ARE PEELING, WITH DARK, ROTTED PLANT MATTER IN THE LAYERS BELOW.";
					cout << userInput::commandFlavor;
					CSLast("green");
				}
				else {
					clearScreen("green");
					userInput::commandFlavor = "THERE'S A LARGE HOLE IN THE WALL BEHIND WHERE THE VINES USED TO HANG.";
					cout << userInput::commandFlavor;
					CSLast("green");
				}
			}
			else if (userInput::noun=="EAST" || userInput::noun=="PILE") {
				if (userInput::skeletonDead == false) {
					clearScreen("green");
					userInput::commandFlavor = "THE PILE OF BONES BEGIN TO SHAKE AS I DRAW NEAR.  I RETREAD BACK, AND THE BONES REST.";
					cout << userInput::commandFlavor;
					CSLast("green");
				}
				else {
					if (userInput::skeleSword == false) {
						clearScreen("green");
						userInput::commandFlavor = "WHERE THE VISCIOUS SKELETON ONCE STOOD, THE BONES AND RAGS ARE SLOWLY FALLING AWAY INTO DUST.  THE BROADSWORD IS INTACT.";
						cout << userInput::commandFlavor;
						CSLast("green");
					}
					else {
						clearScreen("green");
						userInput::commandFlavor = "THE PILE OF BONES HAS DISINTEGRATED.  THERE'S ONLY ASH LEFT, NOW.  THE ROOM FEELS STEADY.";
						cout << userInput::commandFlavor;
						CSLast("green");
					}
				}
			}
			else if (userInput::noun=="WEST" || userInput::noun=="WALLS" || userInput::noun=="WALL") {
				clearScreen("green");
				userInput::commandFlavor = "SUNSHINE FALLS ONTO THE WET STONE WALL.  AS I GET CLOSER, I SEE THAT THERE IS A MESSAGE INSCRIBED ON THE WALL, \"DON'T TRUST THE VINES.\"";
				cout << userInput::commandFlavor;
				CSLast("green");
			}
			else if (userInput::noun=="CEILING" || userInput::noun=="HOLE") {
				if (userInput::vineDead == false) {
					clearScreen("green");
					userInput::commandFlavor = "THROUGH THE CEILING I CAN SEE PINE TREES AND A CLEAR BLUE SKY.  VINES ARE POURING THROUGH THE HOLE IN THE CEILING AND COVERING THE SOUTH WALL.";
					cout << userInput::commandFlavor;
					CSLast("green");
				}
				else {
					clearScreen("green");
					userInput::commandFlavor = "THROUGH THE CEILING I CAN SEE PINE TREES AND A CLEAR BLUE SKY.  THE VINES HAVE SHRIVELED OUT OF THE HOLE IN THE CEILING.";
					cout << userInput::commandFlavor;
					CSLast("green");
				}
			}
			else if (userInput::noun=="FLOOR" || userInput::noun=="GRASS" || userInput::noun=="STONE") {
				clearScreen("green");
				userInput::commandFlavor = "THE STONE FLOOR HAS BEEN COMPLETELY OVERRUN BY FOLIAGE.  THE REMAINING BRICKS SCATTERED ON THE FLOOR LOOK LIKE THEY FELL FORM THE CEILING.";
				cout << userInput::commandFlavor;
				CSLast("green");
			}
			else if (userInput::noun=="VINE") {
				if (userInput::vineDead == false) {
					clearScreen("green");
					userInput::commandFlavor = "THE VINES FEEL ROUGH LIKE LEATHER.  THEY ARE PEELING, WITH DARK, ROTTED PLANT MATTER IN THE LAYERS BELOW.";
					cout << userInput::commandFlavor;
					CSLast("green");
				}
				else {
					clearScreen("green");
					userInput::commandFlavor = "THERE ARE DARK, DRY STUMPS OF VINE HANGING FROM THE CEILING WHERE THE VINE BEAST USED TO HANG.";
					cout << userInput::commandFlavor;
					CSLast("green");
				}
			}
			else if (userInput::noun=="BROADSWORD") {
				if (userInput::skeleSword == false) {
					clearScreen("green");
					userInput::commandFlavor = "THE SWORD SEEMS WEARY.  IT MUST BE WELL-USED.";
					cout << userInput::commandFlavor;
					CSLast("green");
				}
				else {
					clearScreen("green");
					userInput::commandFlavor = "I TAKE A CLOSER LOOK AT THE SWORD.  IT LOOKS OF NORDIC ORIGIN.  IT IS WELL CRAFTED.";
					cout << userInput::commandFlavor;
					CSLast("green");
				}
			}
			else if (userInput::noun=="CLOTH") {
				clearScreen("green");
				userInput::commandFlavor = "THE CLOTHES ARE OLD AND DUSTY.";
				cout << userInput::commandFlavor;
				CSLast("green");
			}
			else if (userInput::noun=="SKELETON") {
				if (userInput::skeletonDead == false) {
					clearScreen("green");
					userInput::commandFlavor = "THE BONES ARE GLOWING WITH A FAINT BLUE AURA.  THERE IS AN ENERGY TO THEM.";
					cout << userInput::commandFlavor;
					CSLast("green");
				}
				else {
					clearScreen("green");
					userInput::commandFlavor = "THE BONES ARE SLOWLY DISINTEGRATING WHERE THE SKELETON ONCE STOOD.";
					cout << userInput::commandFlavor;
					CSLast("green");
				}
			}
			else if (userInput::noun=="ASH") {
				if (userInput::skeletonDead==true) {
					clearScreen("green");
					userInput::commandFlavor = "THE ASH IS SO FINE THAT IT SLIPS THROUGH MY FINGERS.  THERE'S NO A TRACE OF IT ON MY HANDS.";
					cout << userInput::commandFlavor;
					CSLast("green");
				}
				else {
					fail("green");
				}
			}
			else {
				fail("green");
			}
		}
		else if (userInput::verb=="OPEN") {
			if (userInput::noun=="DOOR") {
				clearScreen("green");
				userInput::playerLoc = "start";
			}
			else {
				fail("green");
			}
		}
		else {
			fail("green");
		}
	}
}