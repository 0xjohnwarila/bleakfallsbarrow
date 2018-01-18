#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <boost/algorithm/string.hpp>
#include <vector>

using namespace std;
using namespace boost;

class userClass {
public:
	int playerVerb;
	int playerNoun;
	string verb;
	string noun;
	string inputString;
} playerOne;

void playerInput (userClass player);
void stringSplitter (userClass player);
void wordSearch (userClass player);
void specialCase (userClass player);
void stringAssign (vector <string> & v);

int main () {
	playerInput (playerOne);
	cout << endl << playerOne.playerVerb << endl << playerOne.playerNoun << endl;
	return 0;
}

void playerInput (userClass player) {

	playerOne.playerNoun = playerOne.playerVerb = 0;
	string space = " ";
	string spaceHold;
	cout << "TELL ME WHAT TO DO? ";
	getline(cin, playerOne.inputString);
	spaceHold=playerOne.inputString;
	size_t found = spaceHold.find(space);
	if (found!=string::npos) {
		stringSplitter (playerOne);
	}
	else {
		specialCase (playerOne);
	}
}

void specialCase (userClass player) {
	string help[] = {"HELP"};
	string quit[] = {"QUIT", "END", "DIE"};
	for (int i = 0; i < 3; i++) {
		size_t foundHelp = help[0].find(playerOne.inputString);
		if (foundHelp!=string::npos) {
			cout << "\nHELP\n";
			playerInput (playerOne);
		}
		size_t foundQuit = quit[i].find(playerOne.inputString);
		if (foundQuit!=string::npos) {
			cout << "KILL ME";
			break;
		}

	}

}

void stringSplitter (userClass player) {
  	vector <string> fields;
  	split( fields, playerOne.inputString, is_any_of( " " ), token_compress_on);
  	stringAssign (fields);
}

void stringAssign (vector <string> & v) {
	for (size_t n = 0; n < v.size(); n++) {
   		playerOne.verb = v[n];
   		n=n+1;
   		playerOne.noun = v[n];
   		if (n==3) {
   			cout << "YOU MAY ONLY TELL ME WHAT TO DO WITH ONE OR TWO WORD COMMANDS\n";
   			playerInput (playerOne);
   		}
	}
	wordSearch (playerOne);
}

void wordSearch (userClass player) {

	string verb[] = {"RUN", "WALK", "GO", "HEAD"};
	string south[] = {"SOUTH", "S",};
	string north[] = {"NORTH", "N"};
	string west[] = {"WEST", "W"};
	string east[] = {"EAST", "E"};
	for (int i = 0; i < 4; i++ ) {
		size_t found = verb[i].find(player.verb);
		if (found!=string::npos) {
			playerOne.playerVerb=1;
		}
		if (i > 3) {
			break;
		}
	}
	for (int i = 0; i < 2; i++ ) {
		size_t found = south[i].find(player.noun);
		if (found!=string::npos) {
			playerOne.playerNoun=3;
		}
		if (i > 3) {
			break;
		}	
	}
	for (int i = 0; i < 2; i++ ) {
		size_t found = north[i].find(player.noun);
		if (found!=string::npos) {
			playerOne.playerNoun=1;
		}
		if (i > 3) {
			break;
		}	
	}
	for (int i = 0; i < 2; i++ ) {
		size_t found = east[i].find(player.noun);
		if (found!=string::npos) {
			playerOne.playerNoun=2;
		}
		if (i > 3) {
			break;
		}	
	}
	for (int i = 0; i < 2; i++ ) {
		size_t found = west[i].find(player.noun);
		if (found!=string::npos) {
			playerOne.playerNoun=4;
		}
		if (i > 3) {
			break;
		}	
	}
}