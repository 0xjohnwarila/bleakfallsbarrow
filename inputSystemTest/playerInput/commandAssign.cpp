//commandAssign is a file that takes inputs from inputSplit and rewrites verb and noun
//to common words

#include <iostream>
#include <string>
#include "../global/header.h"
using namespace std;

//nounSearch: runs only if the player uses a two word input

void nounSearch ();

//verbSearch: takes inputs from the player and makes sure that the room knows what to do with it
//syllables in the verbAssign 2d array are reassigned to the [0] string in the array
//that way if the player uses words that aren't used by startRoom, commandAssign
//makes it so that syllables are still understood.
//
//for each array, verbSearch checks the verb for all syllables (CRAWL, DRIFT, etc.)
//there is an array for each verb that the game uses

void verbSearch () {
	string verbAssign [7][15] = {
	{"HELP", "HELPME", "FUCKTHISGAME", "FUCKYOU", "SHITDICK", "IMDONE", "STUCK", "UGH"},
	{"QUIT", "STOP", "TERMINATE", "HALT", "DISCONTINUE", "DIE"},
	{"MOVE", "GO", "WALK", "RUN", "HEAD", "ADVANCE", "CRAWL", "DRIFT", "MIGRATE", "PROCEED", "RELOCATE", "TRAVEL", "HURRY", "MARCH", "SHAMBLE"},
	{"TAKE", "STEAL", "GRAB", "PICKUP", "COLLECT", "SIEZE", "GRASP", "GRIP", "SNATCH", "FIND", "REMOVE", "PULL"},
	{"USE", "EMPLOY", "EXERCISE", "GOVERN", "APPLY", "EXPLOIT"},
	{"LOOK", "GLANCE", "PEER", "VIEW", "STARE", "ADMIRE", "GAZE", "INSPECT", "OBSERVE", "SCRUTINIZE", "SEARCH"},
	{"OPEN", "UNLOCK"},
	};

	while (userInput::english == 0) {
		for (int c = 0; c < 8; c++) {
			if (verbAssign[0][c] == userInput::verb) {
				userInput::verb="HELP";
				userInput::english=1;
			}
		}
		for (int c = 0; c < 6; c++) {
			if (verbAssign[1][c] == userInput::verb) {
				userInput::verb="QUIT";
				userInput::english=1;
			}
		}
		for (int c = 0; c < 15; c++) {
			if (verbAssign[2][c] == userInput::verb) {
				userInput::verb="MOVE";
				userInput::english=1;
			}
		}
		for (int c = 0; c < 12; c++) {
			if (verbAssign[3][c] == userInput::verb) {
				userInput::verb="TAKE";
				userInput::english=1;
			}
		}
		for (int c = 0; c < 6; c++) {
			if (verbAssign[4][c] == userInput::verb) {
				userInput::verb="USE";
				userInput::english=1;
			}
		}
		for (int c = 0; c < 11; c++) {
			if (verbAssign[5][c] == userInput::verb) {
				userInput::verb="LOOK";
				userInput::english=1;
			}
		}
		for (int c = 0; c < 2; c++) {
			if (verbAssign[6][c] == userInput::verb) {
				userInput::verb="OPEN";
				userInput::english=1;
			}
		}
		if (userInput::english!=1) {
			break;
		}
	}
	if (userInput::verb=="HELP" || userInput::verb=="QUIT") {
		userInput::noun="(null)";
	}
	else nounSearch ();
}

//nounSearch doesn't use the same 2d array system that verbSearch does
//because there aren't as many syllables for the nouns in the game.
//nounSearch makes sure that the inputs from the player are useable by the startRoom function

void nounSearch () {
	if (userInput::noun=="NORTH" || userInput::noun=="N") {
		userInput::noun = "NORTH";
		userInput::english = 1;
	}
	if (userInput::noun=="EAST" || userInput::noun=="E") {
		userInput::noun = "EAST";
		userInput::english = 1;
	}
	if (userInput::noun=="SOUTH" || userInput::noun=="S") {
		userInput::noun = "SOUTH";
		userInput::english = 1;
	}
	if (userInput::noun=="WEST" || userInput::noun=="W") {
		userInput::noun = "WEST";
		userInput::english = 1;
	}
	if (userInput::noun=="STONE" || userInput::noun=="PANEL" || userInput::noun=="BRICK" || userInput::noun=="ROCK") {
		userInput::noun = "STONE";
		userInput::english = 1;
	}
	if (userInput::noun=="HOLE" || userInput::noun=="PANEL" || userInput::noun=="WALL") {
		userInput::noun = "HOLE";
		userInput::english = 1;
	}
	if (userInput::noun=="SKELETON" || userInput::noun=="BONES") {
		userInput::noun = "SKELETON";
		userInput::english = 1;
	}
}