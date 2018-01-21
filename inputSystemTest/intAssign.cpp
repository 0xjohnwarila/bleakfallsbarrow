#include <iostream>
#include <string>
#include "header.h"
using namespace std;

void specialAssign () {
	if (userInput::inputString=="HELP") {
		userInput::playerVerb = 0;
	}
	if (userInput::inputString=="QUIT" || userInput::inputString=="STOP" || userInput::inputString=="TERMINATE" || userInput::inputString=="HALT" || userInput::inputString=="DISCONTINUE") {
		userInput::playerVerb = 1;
	}
}

void verbAssign () {
	if (userInput::verb=="MOVE" || userInput::verb=="GO" || userInput::verb=="WALK" || userInput::verb=="RUN" || userInput::verb=="HEAD") {
		userInput::playerVerb = 2;
	}
	if (userInput::verb=="TAKE" || userInput::verb=="STEAL" || userInput::verb=="GRAB" || userInput::verb=="PICKUP" || userInput::verb=="SNATCH") {
		userInput::playerVerb = 3;
	}
	if (userInput::verb=="USE") {
		userInput::playerVerb = 4;
	}
}

void nounAssign () {
	if (userInput::noun=="NORTH" || userInput::noun=="N") {
		userInput::playerNoun = 1;
	}
	if (userInput::noun=="EAST" || userInput::noun=="E") {
		userInput::playerNoun = 2;
	}
	if (userInput::noun=="SOUTH" || userInput::noun=="S") {
		userInput::playerNoun = 3;
	}
	if (userInput::noun=="WEST" || userInput::noun=="W") {
		userInput::playerNoun = 4;
	}
	if (userInput::noun=="CHEST") {
		userInput::playerNoun = 5;
	}
	if (userInput::noun=="DOOR") {
		userInput::playerNoun = 6;
	}
	if (userInput::noun=="SKELETON" || userInput::noun=="BONES") {
		userInput::playerNoun = 7;
	}
	if (userInput::noun=="GATE") {
		userInput::playerNoun = 8;
	}
}