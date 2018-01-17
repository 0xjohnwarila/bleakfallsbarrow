#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
using namespace std;

struct userClass {
	int playerVerb;
	int playerNoun;
	string verb;
	string noun;
} playerOne;

void playerInput (userClass player);
void playerControl (userClass player);

int main () {
	playerInput (playerOne);
	cout << endl << playerOne.playerVerb << endl << playerOne.playerNoun << endl;
	return 0;
}

void playerInput (userClass player) {
	istream_iterator<string> eos;              // end-of-stream iterator
  	istream_iterator<string> iit (cin);   // stdin iterator

  	if (iit!=eos) playerOne.verb=*iit;
  	if (iit==eos) {
  		playerOne.playerNoun=0;
  		playerControl (playerOne);
  	}
  	++iit;
  	if (iit!=eos) playerOne.noun=*iit;
  	playerControl (playerOne);

}

void playerControl (userClass player) {

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