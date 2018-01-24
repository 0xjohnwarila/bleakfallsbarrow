#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <boost/algorithm/string.hpp>
#include <vector>
#include "header.h"
#include "commandAssign.cpp"

using namespace std;
using namespace boost;

void getLineIn ();
void stringSplitter ();
void stringAssign (vector <string> & v);

int playerInput () {
	userInput::english = 0;
	if (userInput::english==0) {
		getLineIn ();
	}
	return 0;
}

void getLineIn () {
	userInput::playerNoun = userInput::playerVerb = 0;
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
  	vector <string> fields;
  	split( fields, userInput::inputString, is_any_of( " " ), token_compress_on);
  	stringAssign (fields);
}

void stringAssign (vector <string> & v) {
	for (size_t n = 0; n < v.size(); n++) {
   		userInput::verb = v[n];
   		n=n+1;
   		userInput::noun = v[n];
   		if (n==3) {
   			cout << "YOU MAY ONLY TELL ME WHAT TO DO WITH ONE OR TWO WORD COMMANDS\n";
   			getLineIn ();
   		}
	}
	verbSearch ();
}