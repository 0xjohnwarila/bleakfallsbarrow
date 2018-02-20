#include <iostream>
#include <thread>
#include "globalFunk.h"

void sleepMilli(int x) {
	std::this_thread::sleep_for(std::chrono::milliseconds(x));
}

void clear () {
	using std::cout;

	cout << "\033[2J\033[1;1H";
}