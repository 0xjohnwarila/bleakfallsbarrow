#include<iostream>
#include<thread>
#include "../global/header.h"
#include "flavor.h"
#include "../global/globalFunk.h"

void startRoomFlavor() {
	using std::cout;
	using std::endl;

	clear();
	cout << "A SMALL DROP OF WATER WAKES ME.  I AM LAYING ON A STONE FLOOR.  I TAKE A DEEP BREATH; STALE AIR FILLS MY LUNGS.  I CAN'T REMEMBER THE LAST TIME I'VE EATEN A WARM MEAL.  I PUSH MYSELF UP OFF OF THE MILDEWED STONE FLOOR AND LOOK AT MY SURROUNDINGS.  I CAN SEE A RUSTIC, WOODEN CHEST.  THE IRON FITTINGS THAT LINE THE CHEST ARE EMBEDDED WITH SCRATCHES AND DENTS.  WHATEVER IS IN THAT CHEST, IT'S IMPORTANT.  THE STONE WALLS LOOK SECURE, BUT THERE IS ONE STONE THAT APPEARS DIFFERENT FROM THE REST.  IT IS UNSETTLED IN THE WALL.  THERE IS A HEAVY WOOD DOOR LADEN WITH DEEP CLAW MARKS.\n\nI NEED TO FIND MY WAY OUT OF HERE BEFORE IT'S TOO LATE.  I'M NOT THE FIRST TO BE TRAPPED IN THIS ROOM.  I WON'T BE THE LAST.";
	cout << endl << endl;
	sleepMilli(10000);
	cout << "PRESS ENTER TO CONTINUE..." << endl;
	getchar();
}

void greenRoomFlavor() {
	using std::cout;
	using std::endl;

	clear();
	cout << "I PUT THE KEY INTO THE KEYHOLE AND TURN.  WITH A SATISFYING METALLIC CLICK, THE DOOR UNLOCKS.  I SET MY BARE FEET INTO THE COLD STONE FLOOR FIRMLY AND PUSH ON THE DOOR.  IT BEGRUDGINGLY SLIDES OPEN AND I'M BLINDED BY A BEAM OF LIGHT COMING FROM THE CEILING.\n\nTHE ONCE STONE ROOF HAS FALLEN APART AND THE SUN IS SHINING THROUGH THE OPEN HOLE.  I CAN FEEL THE SUN AND FRESH AIR ON MY FACE.  ROOTS AND GRASS HAVE OVERGROWN THE STONE FLOOR.  BRICKS ARE SCATTERED AMONG THE FOLIAGE.  LONG VINES HANG FROM THE HOLE IN THE CEILING.  THEY LOOK TOO SLIM TO HOLD MY WEIGHT, SO I DON'T THINK I WILL BE ABLE TO CLIMB OUT OF THIS ROOM.";
	cout << endl << endl;
	sleepMilli(10000);
	cout << "PRESS ENTER TO CONTINUE..." << endl;
	getchar();
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