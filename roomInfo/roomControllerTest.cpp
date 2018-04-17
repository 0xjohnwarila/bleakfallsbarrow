// This file is the test of a new room controller to replace current model.
// The basic structure is as follows:
//
// Has the player been here before?
// Print the correct text.
//
// While the player is here find out what they want to do.
// See if they can do that, and what happens?
// Store it, then tell them what happened.
// When they leave move them to the next room or the exit.
//
// The purpose of the rewrite is to make rooms more readable from the outside,
// and make the writing of a new room easier.
//
// To write a new room:
/*
// 1. Copy the template
// 2. Write the specific actions for the room
// 3. Write the flavor text for the room
// 4. Connect the template to the new actions
// 5. If needed update the input system for new verbs/nouns
// 6. Link the new room to all nearby rooms
// 7. Document and test
// 8. Push to beta branch
// 9. Merge with master

#include <iostream>
#include "../playerInput/inputSplit.h"
#include "flavor.h"
#include "../global/header.h"
#include "roomControllerTest.h"
#include "../global/globalFunctions.h"
#include "../combatModule/combatModule.h"
#include "../saveGame/save.h"
#include "../playerInput/universalRoomCommands.h"

struct localRoomData {
	
};

void roomController() {
	using std::cout;
	using std::endl;

	introText();
	updatePlayerLoc();

	while(userInput::playerLoc=="start") {
		playerInput();

	}
}

// introText()
// Check to see if the user has been here
// If they have not, play the intro for 1000ms
// If the have, play the intro for 200ms
void introText() {
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
}

// updatePlayerLoc()
// Update the location of the player to the current room
void updatePlayerLoc() {
	userInput::startRoomCheck = true;
	userInput::playerLoc = "start";
}

// checkVerb()
// Find what verb the user inputed
void checkVerb() {
	if(userInput::verb == "GO") {

	}
}

// movementController()
// If the user wants to move check to see if they can, then do it.
void movementController() {
	using std::cout;
	using std::endl;

	if(userInput::noun=="NORTH" 
	   || userInput::noun=="EAST" 
	   || userInput::noun=="WEST") {

	}
}
*/