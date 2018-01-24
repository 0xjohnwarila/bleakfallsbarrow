#include <iostream>
#include <string>
#include "header.h"
using namespace std;

void nounSearch ();

void verbSearch () {
	string verbAssign [7][15] = {
	{"HELP", "HELPME", "FUCKTHISGAME", "FUCKYOU", "SHITDICK", "IMDONE", "STUCK", "UGH"},
	{"QUIT", "STOP", "TERMINATE", "HALT", "DISCONTINUE"},
	{"MOVE", "GO", "WALK", "RUN", "HEAD", "ADVANCE", "CRAWL", "DRIFT", "MIGRATE", "PROCEED", "RELOCATE", "TRAVEL", "HURRY", "MARCH", "SHAMBLE"},
	{"TAKE", "STEAL", "GRAB", "PICKUP", "COLLECT", "SIEZE", "GRASP", "GRIP", "SNATCH", "FIND"},
	{"USE", "EMPLOY", "EXERCISE", "GOVERN", "APPLY", "EXPLOIT"},
	{"LOOK", "GLANCE", "PEER", "VIEW", "STARE", "ADMIRE", "GAZE", "INSPECT", "OBSERVE", "SCRUTINIZE", "SEARCH"},
	{"OPEN"}
	};

	while (userInput::english == 0) {
		for (int c = 0; c < 8; c++) {
			if (verbAssign[0][c] == userInput::verb) {
				userInput::playerVerb=0;
				userInput::english=1;
			}
		}
		for (int c = 0; c < 5; c++) {
			if (verbAssign[1][c] == userInput::verb) {
				userInput::playerVerb=1;
				userInput::english=1;
			}
		}
		for (int c = 0; c < 15; c++) {
			if (verbAssign[2][c] == userInput::verb) {
				userInput::playerVerb=2;
				userInput::english=1;
			}
		}
		for (int c = 0; c < 10; c++) {
			if (verbAssign[3][c] == userInput::verb) {
				userInput::playerVerb=3;
				userInput::english=1;
			}
		}
		for (int c = 0; c < 6; c++) {
			if (verbAssign[4][c] == userInput::verb) {
				userInput::playerVerb=4;
				userInput::english=1;
			}
		}
		for (int c = 0; c < 11; c++) {
			if (verbAssign[5][c] == userInput::verb) {
				userInput::playerVerb=5;
				userInput::english=1;
			}
		}
		for (int c = 0; c < 1; c++) {
			if (verbAssign[6][c] == userInput::verb) {
				userInput::playerVerb=6;
				userInput::english=1;
			}
		}
		if (userInput::english!=1) {
			break;
		}
	}
	if (userInput::playerVerb==0 || userInput::playerVerb==1) {
		userInput::playerNoun=0;
	}
	else nounSearch ();
}

void nounSearch () {
	if (userInput::noun=="NORTH" || userInput::noun=="N") {
		userInput::playerNoun = 1;
		userInput::english = 1;
	}
	if (userInput::noun=="EAST" || userInput::noun=="E") {
		userInput::playerNoun = 2;
		userInput::english = 1;
	}
	if (userInput::noun=="SOUTH" || userInput::noun=="S") {
		userInput::playerNoun = 3;
		userInput::english = 1;
	}
	if (userInput::noun=="WEST" || userInput::noun=="W") {
		userInput::playerNoun = 4;
		userInput::english = 1;
	}
	if (userInput::noun=="CHEST") {
		userInput::playerNoun = 5;
		userInput::english = 1;
	}
	if (userInput::noun=="DOOR") {
		userInput::playerNoun = 6;
		userInput::english = 1;
	}
	if (userInput::noun=="SKELETON" || userInput::noun=="BONES") {
		userInput::playerNoun = 7;
		userInput::english = 1;
	}
	if (userInput::noun=="GATE") {
		userInput::playerNoun = 8;
		userInput::english = 1;
	}
	if (userInput::noun=="KEY") {
		userInput::playerNoun = 9;
		userInput::english = 1;
	}
	if (userInput::noun=="ROD") {
		userInput::playerNoun = 10;
		userInput::english = 1;
	}
}