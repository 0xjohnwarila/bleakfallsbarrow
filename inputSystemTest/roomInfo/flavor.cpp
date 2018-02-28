#include<iostream>
#include<thread>
#include "../global/header.h"
#include "flavor.h"
#include "../global/globalFunk.h"

void restoreHealth() {
	if (playerInfo::classNum == 1) {
		playerInfo::playerHealth += 10;
	}
	else if (playerInfo::classNum == 2) {
		playerInfo::playerHealth += 10;
	}
	else if (playerInfo::classNum == 3) {
		playerInfo::playerHealth += 10;
	}
	else if (playerInfo::classNum == 4) {
		playerInfo::playerHealth += 10;
	}
}

void startRoomFlavor() {
	using std::cout;
	using std::endl;

	clear();
	cout << "A SMALL DROP OF WATER WAKES ME.  I AM LAYING ON A STONE FLOOR.  I TAKE A DEEP BREATH; STALE AIR FILLS MY LUNGS.  I CAN'T REMEMBER THE LAST TIME I'VE EATEN A WARM MEAL.  I PUSH MYSELF UP OFF OF THE MILDEWED STONE FLOOR AND LOOK AT MY SURROUNDINGS.  I CAN SEE A RUSTIC, WOODEN CHEST.  THE IRON FITTINGS THAT LINE THE CHEST ARE EMBEDDED WITH SCRATCHES AND DENTS.  WHATEVER IS IN THAT CHEST, IT'S IMPORTANT.  THE STONE WALLS LOOK SECURE, BUT THERE IS ONE STONE THAT APPEARS DIFFERENT FROM THE REST.  IT IS UNSETTLED IN THE WALL.  I CAN SEE A HEAVY WOOD DOOR LADEN WITH DEEP CLAW MARKS.\n\nI NEED TO FIND MY WAY OUT OF HERE BEFORE IT'S TOO LATE.  I'M NOT THE FIRST TO BE TRAPPED IN THIS ROOM.  I WON'T BE THE LAST.";
	cout << endl << endl;
	sleepMilli(3000);
	enterPause();
}

void greenRoomFlavor() {
	using std::cout;
	using std::endl;

	clear();
	cout << "I PUT THE KEY INTO THE KEYHOLE AND TURN.  WITH A SATISFYING METALLIC CLICK, THE DOOR UNLOCKS.  I SET MY BARE FEET INTO THE COLD STONE FLOOR FIRMLY AND PUSH ON THE DOOR.  IT BEGRUDGINGLY SLIDES OPEN AND I'M BLINDED BY A BEAM OF LIGHT COMING FROM THE CEILING.\n\nTHE ONCE STONE ROOF HAS FALLEN APART AND THE SUN IS SHINING THROUGH THE OPEN HOLE.  I CAN FEEL THE SUN AND FRESH AIR ON MY FACE.  ROOTS AND GRASS HAVE OVERGROWN THE STONE FLOOR.  BRICKS ARE SCATTERED AMONG THE FOLIAGE.  LONG VINES HANG FROM THE HOLE IN THE CEILING.  THEY LOOK TOO SLIM TO HOLD MY WEIGHT, SO I DON'T THINK I WILL BE ABLE TO CLIMB OUT OF THIS ROOM.";
	cout << endl << endl;
	sleepMilli(3000);
	enterPause();
}

void throneRoomFlavor() {
	using std::cout;
	using std::endl;

	clear();
	cout << "(THRONE ROOM FLAVOR TEXT)";
	cout << endl << endl;
	sleepMilli(3000);
	enterPause();
}

void CSFirst(std::string room, int time) {
	using std::cout;
	using std::endl;

	clear();
	sleepMilli(time);

	if (room=="start") {
		cout << "I AM IN A SMALL STONE ROOM.  ";
		cout << "MY BARE FEET FEEL COLD ON THE STONE FLOOR.\n\n";
		sleepMilli(time);
		if (userInput::seeInDark==false) {
			cout << "VISIBLE ITEMS:\n";
		}
		else if (userInput::seeInDark==true) {
			cout << "SEE IN DARK ITEMS:\n";
		}
		sleepMilli(time);
		cout <<"TO MY WEST I CAN SEE A STURDY WOODEN CHEST AGAINST THE WALL\n";
		sleepMilli(time);
		if (userInput::stone==false) {
			cout << "TO MY NORTH I CAN SEE A MYSTERIOUS STONE IN THE WALL";
		}
		else if (userInput::stone==true) {
			if (userInput::key==false) {
				cout << "TO MY NORTH I CAN SEE A KEY IN A HOLE";
			}
			if (userInput::key==true) {
				cout << "TO MY NORTH I CAN SEE AN EMPTY HOLE";
			}
		}
		cout << endl;
		sleepMilli(time);
		if (userInput::greenRoomCheck==false) {
			cout << "TO MY SOUTH I CAN SEE A CLOSED WOODEN DOOR";
		}
		else if (userInput::greenRoomCheck==true) {
			cout << "TO MY SOUTH I CAN SEE AN OPEN WOODEN DOOR";
		}
	}	

	if (room=="green") {
		cout << "I AM IN A WALLED FOREST.  I HEAR BIRDS.  ";
		cout << "MY BARE FEET FEEL REFRESHED ON THE MOSSY BRICKS.\n\n";
		sleepMilli(time);
		if (userInput::seeInDark==false) {
			cout << "VISIBLE ITEMS:\n";
		}
		else if (userInput::seeInDark==true) {
			cout << "SEE IN DARK ITEMS:\n";
		}
		sleepMilli(time);
		if (userInput::skeletonDead == false) {
			cout <<"TO MY EAST I CAN SEE A PILE OF BONES, TATTERED RAGS, AND A RUSTY BROADSWORD\n";
		}
		else {
			if (userInput::skeleSword == false) {
				if (userInput::greenRag == false) {
					cout <<"TO MY EAST I CAN SEE A PILE OF ASH, TATTERED RAGS, AND A RUSTY BROADSWORD\n";
				}
				else {
					cout <<"TO MY EAST I CAN SEE A PILE OF ASH AND A RUSTY BROADSWORD\n";
				}
			}
			else {
				if (userInput::greenRag == false) {
					cout <<"TO MY EAST I CAN SEE A PILE OF ASH AND TATTERED RAGS\n";
				}
				else {
					cout <<"TO MY EAST I CAN SEE A PILE OF ASH\n";
				}
			}
		}
		sleepMilli(time);
		cout <<"TO MY NORTH I CAN SEE AN OPEN DOOR";
		cout << endl;
		sleepMilli(time);
		if (userInput::vineDead == false) {
			cout << "TO MY SOUTH I CAN SEE A THICK WALL OF VINES\n";
		}
		else {
			cout << "TO MY SOUTH I CAN SEE A LARGE HOLE IN THE WALL\n";
		}
		sleepMilli(time);
		cout << "TO MY WEST I CAN SEE A MYSTERIOUS WALL";
	}

	if (room=="throne") {
		cout << "I AM IN A THRONE ROOM.  ";
		cout << "MY FEET FEEL DIGNIFIED ON THE MARBLE FLOOR.\n\n";
		sleepMilli(time);
		if (userInput::seeInDark==false) {
			cout << "VISIBLE ITEMS:\n";
		}
		else if (userInput::seeInDark==true) {
			cout << "SEE IN DARK ITEMS:\n";
		}
		sleepMilli(time);
		cout << "TO MY EAST I CAN SEE AN ELEGANT MARBLE COLUMN\n";
		sleepMilli(time);
		cout << "TO MY NORTH I CAN SEE A LARGE HOLE IN THE WALL\n";
		sleepMilli(time);
		cout << "TO MY SOUTH I CAN SEE A SPIKY FLOOR\n";
		sleepMilli(time);
		cout << "TO MY WEST I CAN SEE A MYSTERIOUS WALL";
	}

	cout << endl;
	sleepMilli(time);
	cout <<"\n(TYPE 'HELP' FOR HELP)\n";
	sleepMilli(time);
	cout <<"(TYPE 'QUIT' TO QUIT)\n";
	sleepMilli(time);
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
			cout << "TO MY NORTH I CAN SEE A MYSTERIOUS STONE IN THE WALL";
		}
		else if (userInput::stone==true) {
			if (userInput::key==false) {
				cout << "TO MY NORTH I CAN SEE A KEY IN A HOLE";
			}
			if (userInput::key==true) {
				cout << "TO MY NORTH I CAN SEE AN EMPTY HOLE";
			}
		}
		cout << endl;
		if (userInput::greenRoomCheck==false) {
			cout << "TO MY SOUTH I CAN SEE A CLOSED WOODEN DOOR";
		}
		else if (userInput::greenRoomCheck==true) {
			cout << "TO MY SOUTH I CAN SEE AN OPEN WOODEN DOOR";
		}
	}

	if (room=="green") {
		cout << "I AM IN A WALLED FOREST.  I HEAR BIRDS.  ";
		cout << "MY BARE FEET FEEL REFRESHED ON THE MOSSY BRICKS.\n\n";
		if (userInput::seeInDark==false) {
			cout << "VISIBLE ITEMS:\n";
		}
		else if (userInput::seeInDark==true) {
			cout << "SEE IN DARK ITEMS:\n";
		}
		if (userInput::skeletonDead == false) {
			cout <<"TO MY EAST I CAN SEE A PILE OF BONES, TATTERED RAGS, AND A RUSTY BROADSWORD\n";
		}
		else {
			if (userInput::skeleSword == false) {
				if (userInput::greenRag == false) {
					cout <<"TO MY EAST I CAN SEE A PILE OF ASH, TATTERED RAGS, AND A RUSTY BROADSWORD\n";
				}
				else {
					cout <<"TO MY EAST I CAN SEE A PILE OF ASH AND A RUSTY BROADSWORD\n";
				}
			}
			else {
				if (userInput::greenRag == false) {
					cout <<"TO MY EAST I CAN SEE A PILE OF ASH AND TATTERED RAGS\n";
				}
				else {
					cout <<"TO MY EAST I CAN SEE A PILE OF ASH\n";
				}
			}
		}
		cout <<"TO MY NORTH I CAN SEE AN OPEN DOOR";
		cout << endl;
		if (userInput::vineDead == false) {
			cout << "TO MY SOUTH I CAN SEE A THICK WALL OF VINES\n";
		}
		else {
			cout << "TO MY SOUTH I CAN SEE A LARGE HOLE IN THE WALL\n";
		}
		cout << "TO MY WEST I CAN SEE A MYSTERIOUS WALL";
	}

	if (room=="throne") {
		cout << "I AM IN A THRONE ROOM.  ";
		cout << "MY FEET FEEL DIGNIFIED ON THE MARBLE FLOOR.\n\n";
		if (userInput::seeInDark==false) {
			cout << "VISIBLE ITEMS:\n";
		}
		else if (userInput::seeInDark==true) {
			cout << "SEE IN DARK ITEMS:\n";
		}
		cout << "TO MY EAST I CAN SEE AN ELEGANT MARBLE COLUMN\n";
		cout << "TO MY NORTH I CAN SEE A LARGE HOLE IN THE WALL\n";
		cout << "TO MY SOUTH I CAN SEE A SPIKY FLOOR\n";
		cout << "TO MY WEST I CAN SEE A MYSTERIOUS WALL";
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
			cout << "TO MY NORTH I CAN SEE A MYSTERIOUS STONE IN THE WALL";
		}
		else if (userInput::stone==true) {
			if (userInput::key==false) {
				cout << "TO MY NORTH I CAN SEE A KEY IN A HOLE";
			}
			if (userInput::key==true) {
				cout << "TO MY NORTH I CAN SEE AN EMPTY HOLE";
			}
		}
		cout << endl;
		if (userInput::greenRoomCheck==false) {
			cout << "TO MY SOUTH I CAN SEE A CLOSED WOODEN DOOR";
		}
		else if (userInput::greenRoomCheck==true) {
			cout << "TO MY SOUTH I CAN SEE AN OPEN WOODEN DOOR";
		}
	}

	if (room=="green") {
		cout << "I AM IN A WALLED FOREST.  I HEAR BIRDS.  ";
		cout << "MY BARE FEET FEEL REFRESHED ON THE MOSSY BRICKS.\n\n";
		if (userInput::seeInDark==false) {
			cout << "VISIBLE ITEMS:\n";
		}
		else if (userInput::seeInDark==true) {
			cout << "SEE IN DARK ITEMS:\n";
		}
		if (userInput::skeletonDead == false) {
			cout <<"TO MY EAST I CAN SEE A PILE OF BONES, TATTERED RAGS, AND A RUSTY BROADSWORD\n";
		}
		else {
			if (userInput::skeleSword == false) {
				if (userInput::greenRag == false) {
					cout <<"TO MY EAST I CAN SEE A PILE OF ASH, TATTERED RAGS, AND A RUSTY BROADSWORD\n";
				}
				else {
					cout <<"TO MY EAST I CAN SEE A PILE OF ASH AND A RUSTY BROADSWORD\n";
				}
			}
			else {
				if (userInput::greenRag == false) {
					cout <<"TO MY EAST I CAN SEE A PILE OF ASH AND TATTERED RAGS\n";
				}
				else {
					cout <<"TO MY EAST I CAN SEE A PILE OF ASH\n";
				}
			}
		}
		cout <<"TO MY NORTH I CAN SEE AN OPEN DOOR";
		cout << endl;
		if (userInput::vineDead == false) {
			cout << "TO MY SOUTH I CAN SEE A THICK WALL OF VINES\n";
		}
		else {
			cout << "TO MY SOUTH I CAN SEE A LARGE HOLE IN THE WALL\n";
		}
		cout << "TO MY WEST I CAN SEE A MYSTERIOUS WALL";
	}

	if (room=="throne") {
		cout << "I AM IN A THRONE ROOM.  ";
		cout << "MY FEET FEEL DIGNIFIED ON THE MARBLE FLOOR.\n\n";
		if (userInput::seeInDark==false) {
			cout << "VISIBLE ITEMS:\n";
		}
		else if (userInput::seeInDark==true) {
			cout << "SEE IN DARK ITEMS:\n";
		}
		cout << "TO MY EAST I CAN SEE AN ELEGANT MARBLE COLUMN\n";
		cout << "TO MY NORTH I CAN SEE A LARGE HOLE IN THE WALL\n";
		cout << "TO MY SOUTH I CAN SEE A SPIKY FLOOR\n";
		cout << "TO MY WEST I CAN SEE A MYSTERIOUS WALL";
	}

	cout << endl;
	cout <<"\n(TYPE 'HELP' FOR HELP)\n";
	cout <<"(TYPE 'QUIT' TO QUIT)\n";
	cout <<"TELL ME WHAT TO DO? ";

	cout << userInput::inputString;
	cout << endl <<"OK," << endl;
	cout << userInput::commandFlavor;
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

void battleOver (std::string enemy, std::string room) {
	using std::cout;
	using std::endl;
	using std::string;

	if (enemy == "random") {
		if (playerInfo::battleStatus == 1) {
			restoreHealth();
			clearScreen(room);
			userInput::commandFlavor = "THE BATTLE IS OVER.  THE ENEMY SCREECHES AND DISENTEGRATES.\n";
			cout << userInput::commandFlavor << endl;
		}
		if (playerInfo::battleStatus == 0) {
			clearScreen(room);
			userInput::commandFlavor = "THE BATTLE IS OVER.  I FALL INTO A POOL OF MY OWN BLOOD AND COUGH THE REMAINING LIFE ENERGY OUT OF MY BODY.";
			cout << userInput::commandFlavor;
			userInput::playerLoc = 0;
		}
	}

	if (enemy == "skeleton") {
		if (playerInfo::battleStatus == 1) {
			restoreHealth();
			clearScreen("green");
			userInput::commandFlavor = "THE BATTLE IS OVER.  AS THE SKELETON HOBBLES TOWARDS ME, IT'S LIMBS FALL OFF ONE BY ONE.  THE SKULL FALLS OFF OF THE SPINE AND SHATTERS ON THE GROUND.  THE REST OF THE BODY FALLS APART UNTIL IT'S JUST A PILE OF BONES AGAIN, SLOWLY DISENTEGRATING INTO DUST.";
			cout << userInput::commandFlavor;
			CSLast("green");
		}
		if (playerInfo::battleStatus == 0) {
			clearScreen("green");
			userInput::commandFlavor = "THE BATTLE IS OVER.  THE SKELETON APPROACHES ME WITH ALARMING SPEED AND SINKS IT'S BROADSWORD DEEP INTO MY HEART.  MY VISION FADES.  WITH MY LAST BREATH, I TRY TO PULL THE SWORD OUT OF MY CHEST.  IT'S NO USE, THE SKELETON HAS STRUCK ME DOWN.  I FALL INTO A POOL OF MY OWN BLOOD AND COUGH THE REMAINING LIFE ENERGY OUT OF MY BODY.";
			cout << userInput::commandFlavor;
			userInput::playerLoc = 0;
		}
	}

	if (enemy == "vines") {
		if (playerInfo::battleStatus == 1) {
			restoreHealth();
			clearScreen("green");
			userInput::commandFlavor = "THE BATTLE IS OVER.  I SLICE THE LAST LIVING VINE IN HALF WITH MY BROADSWORD.  THE REMAINING STUMPS LEAK A BLACK OOZE AND SHRIVEL UP TOWARDS THE CEILING.  A WRIGGLING VINE FALLS TO THE FLOOR AND I PICK IT UP.";
			cout << userInput::commandFlavor;
			CSLast("green");
		}
		if (playerInfo::battleStatus == 0) {
			clearScreen("green");
			userInput::commandFlavor = "THE BATTLE IS OVER.  THE VINES WRAP AROUND MY LEGS AND START PULLING ME TOWARDS THEIR CENTER.  I SWING AT THEM WITH MY BROADSWORD, BUT THE VINES KNOCK IT OUT OF MY HAND.  THE VINES SLOWLY GOUGE OUT MY EYES AND CONSUME MY BRAIN.  I FALL INTO A POOL OF MY OWN BLOOD AND COUGH THE REMAINING LIFE ENERGY OUT OF MY BODY.";
			cout << userInput::commandFlavor;
			userInput::playerLoc = 0;
		}
	}
}