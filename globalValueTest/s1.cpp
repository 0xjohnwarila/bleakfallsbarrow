#include <iostream>
#include "header.h"
#include "s2.cpp"

using namespace std;

int playerInfoGlobal::numberX = 0;

int main () {
	cout << playerInfoGlobal::numberX << endl;
	changeX ();
	cout << playerInfoGlobal::numberX << endl;
}
