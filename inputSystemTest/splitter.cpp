#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <boost/algorithm/string.hpp>
#include <vector>
#include "header.h"
#include "searchAlgorithm.cpp"

using namespace std;
using namespace boost;

void playerInput ();
void stringSplitter ();
void stringAssign (vector <string> & v);

int inSplitMain () {
	playerInput ();
	cout << endl << userInput::playerVerb << endl << userInput::playerNoun << endl;
	return 0;
}

void playerInput () {

	userInput::playerNoun = userInput::playerVerb = 0;
	string space = " ";
	string spaceHold;
	cout << "TELL ME WHAT TO DO? ";
	getline(cin, userInput::inputString);
	spaceHold=userInput::inputString;
	size_t found = spaceHold.find(space);
	if (found!=string::npos) {
		stringSplitter ();
	}
	else {
		specialSearch (); //run search algorithm
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
   			playerInput ();
   		}
	}
	verbSearch (); //run search algorithm
}