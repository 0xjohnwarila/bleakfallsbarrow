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
int userInput::playerLoc = 0;

int main () {
	while (userInput::playerLoc==0 || 2) {
		startRoom ();
	}
	if (userInput::playerLoc==1) {
		cout << "YOU WIN!!!";
	}
	return 0;
}