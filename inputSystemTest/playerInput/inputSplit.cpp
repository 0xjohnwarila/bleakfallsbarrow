//inputSplit.cpp is a file that takes the string inputString and splits it into the verb and noun strings

#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>
#include "../global/header.h"
#include "commandAssign.cpp"

using namespace std;

//getLineIn: function that resets the verb and noun to (null)
//after that it checks for a space in inputString (1 vs 2 words)
//if the input is 1 word, then it puts the word into verb and searches it with commandAssign.cpp
//if the input is 2 words, then it runs stringSplitter
//
//stringSplitter: splits the two words into verb (first word) and noun (second word)

void getLineIn ();
void stringSplitter ();

//playerInput: the function that startRoom calls to get the input from the player
//it runs through getline and sometimes stringsplitter
//it goes from inputSplit.cpp to commandAssign.cpp, and then finally back to startRoom.

void playerInput () {
	userInput::english = 0;
	if (userInput::english==0) {
		getLineIn ();
	}
}

void getLineIn () {
	userInput::noun = userInput::verb = "(null)";
	string space = " ";
	string spaceHold;
	getline(cin, userInput::inputString);
	spaceHold=userInput::inputString;
	size_t found = spaceHold.find(space);
	if (found!=string::npos) {
		stringSplitter ();
	}
	else {
		userInput::verb=userInput::inputString;
		verbSearch (); //run search algorithm
	}
}

void stringSplitter () {
	size_t n;
	n = userInput::inputString.find(" ");
	if (n!=string::npos)
	{
		userInput::verb = userInput::inputString.substr(0, n);
		userInput::noun = userInput::inputString.substr(n + 1);
	}
	verbSearch ();
}