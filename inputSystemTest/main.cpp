#include <iostream>
#include <string>
#include "header.h"
#include "splitter.cpp"

using namespace std;

int userInput::playerVerb = 0;//initializing global userInput values (has to be done in main function)
int userInput::playerNoun = 0;
string userInput::verb = "null";
string userInput::noun = "null";
string userInput::inputString = "null";

string userInput::playerName = "null";
int userInput::playerAge = 0;//initializing global player info values
int userInput::classNum = 0;
int userInput::playerLoc = 0;

int main () {
	playerInput ();
	return 0;
}