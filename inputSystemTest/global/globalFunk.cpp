#include <iostream>
#include <thread>
#include "globalFunk.h"
#include "header.h"

void sleepMilli(int x) {
	std::this_thread::sleep_for(std::chrono::milliseconds(x));
}

void clear () {
	using std::cout;

	cout << "\033[2J\033[1;1H";
	displayPlayerInfo();
}

void clearFirst() {
	using std::cout;

	cout << "\033[2J\033[1;1H";
}

void displayPlayerInfo() {
	using std::cout;

	if (playerInfo::playerHealth < 0) {
		playerInfo::playerHealth = 0;
	}
	cout << "|| NAME: " << playerInfo::playerName << " | AGE: " << playerInfo::playerAge << " | CLASS: ";
	if (playerInfo::classNum == 1) {
		cout << "MAGE";
	}
	else if (playerInfo::classNum == 2) {
		cout << "WARRIOR";
	}
	else if (playerInfo::classNum == 3) {
		cout << "ROGUE";
	}
	else if (playerInfo::classNum == 4) {
		cout << "WARLOCK";
	}
	cout << " | HEALTH: " << playerInfo::playerHealth;
	if (playerInfo::playerArthritis == true) {
		cout << " | ARTHRITIS: YES";
	}
	cout << " ||";
	cout << std::endl << std::endl;
}