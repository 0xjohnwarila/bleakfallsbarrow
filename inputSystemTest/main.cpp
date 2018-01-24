#include <iostream>
#include <string>
#include "header.h"
#include "testRoom1.cpp"

using namespace std;

int userInput::playerVerb = 0;//initializing global userInput values (has to be done in main function)
int userInput::playerNoun = 0;
string userInput::verb = "null";
string userInput::noun = "null";
string userInput::inputString = "null";
int userInput::english = 0;

string userInput::playerName = "null";//initializing global player info values
int userInput::playerAge = 0;
int userInput::classNum = 0;
int userInput::playerLoc = 2;

int main () {
	while (userInput::playerLoc==2) {
		startRoom ();
	}
	if (userInput::playerLoc==1) {
		cout << "YOU WIN!!!\n\nThanks for playing,\n\n-Jwarila and Wizard\n\n";
	}
	return 0;
}