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

  	++iit;
  	if (iit!=eos) playerOne.noun=*iit;
  	playerControl (playerOne);
}

void playerControl (userClass player) {

	string verb[] = {"RUN", "WALK", "GO"};
	string south[] = {"SOUTH", "S",};
	for (int i = 0; i < 3; i++ ) {
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
			playerOne.playerNoun=1;
		}
		if (i > 3) {
			break;
		}	
	}
}