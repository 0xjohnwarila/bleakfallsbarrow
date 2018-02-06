#include <iostream>
#include <string>
#include "header.h"
using namespace std;

void nounSearch ();

void verbSearch () {
	string verbAssign [7][15] = {
	{"HELP", "HELPME", "FUCKTHISGAME", "FUCKYOU", "SHITDICK", "IMDONE", "STUCK", "UGH"},
	{"QUIT", "STOP", "TERMINATE", "HALT", "DISCONTINUE", "DIE"},
	{"MOVE", "GO", "WALK", "RUN", "HEAD", "ADVANCE", "CRAWL", "DRIFT", "MIGRATE", "PROCEED", "RELOCATE", "TRAVEL", "HURRY", "MARCH", "SHAMBLE"},
	{"TAKE", "STEAL", "GRAB", "PICKUP", "COLLECT", "SIEZE", "GRASP", "GRIP", "SNATCH", "FIND", "REMOVE"},
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
		for (int c = 0; c < 10; c++) {
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
	if (userInput::noun=="STONE" || userInput::noun=="PANEL" || userInput::noun=="WALL" || userInput::noun=="BRICK" || userInput::noun=="ROCK") {
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