#include <iostream>
#include <thread>
#include <termios.h>
#include <unistd.h>
#include "globalFunctions.h"
#include "header.h"

void sleepMilli(int x) {
	// Sleep Milli
	// Sleep for x amount of milliseconds
	// John Warila
	std::this_thread::sleep_for(std::chrono::milliseconds(x));
}

void clear () {
	// Clear
	// Clear the screen and print the player info
	// Josh
	using std::cout;

	clearFirst();
	displayPlayerInfo();
}

void clearFirst() {
	// Clear First
	// Clear the screen
	// John Warila
	using std::cout;

	cout << "\033[2J\033[1;1H";
}

void enterPause() {
	// Enter Pause
	// Holds the screen until the player presses enter
	// Josh
	using std::cout;
	using std::endl;

	cout << "PRESS ENTER TO CONTINUE..." << endl;
	getchar();
}

void displayPlayerInfo() {
	// Display Player Info
	// Print the info about the player, Name, Age, Class, Health
	// Josh
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
	cout << std::endl;
	playerInventory();
	cout << std::endl << std::endl;
}

void playerInventory() {
	// Player Inventory
	// Prints the player's current inventory
	// Josh
	using std::cout;

	cout << "|| INVENTORY: ";
	if (userInput::stone == true) {
		cout << " | MYSTERIOUS STONE";
	}
	if (userInput::key == true) {
		cout << " | GOLDEN KEY";
	}
	if (userInput::skeleSword == true) {
		cout << " | RUSTY BROADWSORD";
	}
	if (userInput::greenRag == true) {
		cout << " | SKELETON'S RAGS";
	}
	if (userInput::vineDead == true) {
		cout << " | WRIGGLING VINE";
	}
	cout << " ||";
}

void bubbleSort(std::string *array, int size) {
	// Bubble sort
	// Sort the array of inputs for searching, using bubblesort algorithm
	// John Warila
	using std::string;
	bool swap;
	string temp;

	do{
		swap = false;
		for(int count = 1; count < (size - 1); count++){
			if(array[count-1] > array[count]){
				temp = array[count-1];
				array[count-1] = array[count];
				array[count] = temp;
				swap = true;
			}
		}
	}
	while(swap);
}

std::string stringSearch(std::string *array, int size) { 
	// String Search
	// Search a sorted array of strings and return an input if it is in the array
	// John Warila
	using std::string;
	using std::cin;
	using std::cout;

	string userCommand;
	for(;;) {
		cout << ": ";
		getline(cin, userCommand);

		int first = 0;
		int last = size - 1;
		bool validCommand = false;

		while(!validCommand && first <= last) {
			int middle = (first + last) / 2;
			if(array[middle] == userCommand) {
				validCommand = true;
				return userCommand;
			}
			else if(array[middle] > userCommand)
				last = middle - 1;
			else
				first = middle + 1;
		}
	}
	return "error";
}

std::string checkUserInput(std::string *array, int size) {
	// Check User Input
	// Check an input from a user and return the input if it is valid
	// John Warila
	bubbleSort(array, size);
	return stringSearch(array, size);
}


char getch() {
	// Getch
	// Get a character from the user without requiring a endline
	// John Warila
        char buf = 0;
        struct termios old = {0};
        if (tcgetattr(0, &old) < 0)
                perror("tcsetattr()");
        old.c_lflag &= ~ICANON;
        old.c_lflag &= ~ECHO;
        old.c_cc[VMIN] = 1;
        old.c_cc[VTIME] = 0;
        if (tcsetattr(0, TCSANOW, &old) < 0)
                perror("tcsetattr ICANON");
        if (read(0, &buf, 1) < 0)
                perror ("read()");
        old.c_lflag |= ICANON;
        old.c_lflag |= ECHO;
        if (tcsetattr(0, TCSADRAIN, &old) < 0)
                perror ("tcsetattr ~ICANON");
        return (buf);
}