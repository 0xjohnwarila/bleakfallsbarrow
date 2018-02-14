#include <iostream>
#include "header.h"
#include "combatModule.cpp"

using std::string;

void getPlayerInfo();
void bubbleSort();
string stringSearch();

int main(){
	
	return 0;
}

void getPlayerInfo(){ // Ask the player to input the data about their character
	using namespace std;

	srand(time(NULL));

	string nameIn;
	string ageIn;
	string classIn;

	playerOne.classNum = 0;
	
	cout << "\nWHAT'S MY NAME?: ";
	getline(cin, nameIn);
	playerOne.playerName = nameIn;
	
	cout << "HOW OLD AM I?: ";
	
	while(playerOne.playerAge == 0){
		getline(cin, ageIn);
		stringstream(ageIn) >> playerOne.playerAge;

		if(playerOne.playerAge > 60){
			playerOne.playerArthritis = true;
		}
	  
		if(playerOne.playerAge == 0){
			  cout << "I DIDN'T UDERSTAND YOUR ANSWER. TRY AGAIN: ";
		}
	}
	
	cout << "WHAT AM I (TYPE MAGE, WARRIOR, ROGUE, WARLOCK, OR RANDOM): ";
	
	while(playerOne.classNum == 0){
		getline(cin, classIn);
		stringstream(classIn) >> playerOne.classNum;
	  
		if(classIn == "MAGE"){
			playerOne.classNum = 1;
		}else if(classIn == "WARRIOR"){
			playerOne.classNum = 2;
		}else if(classIn == "ROGUE"){
			playerOne.classNum = 3;
		}else if(classIn == "WARLOCK"){
			playerOne.classNum = 4;
		}else if(classIn == "RANDOM"){
			playerOne.classNum = (rand() % 4) + 1;
		}else{
			cout << "I DIDN'T UDERSTAND YOUR ANSWER. TRY AGAIN: ";
		}
	}
}

void bubbleSort(string *array, int size){ // Sort the command array so the search can work
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

string stringSearch(string *array, int size){ // Check if the userCommand is in the string and then return it so the function can be called
	using std::string;
	using std::cin;
	using std::cout;

	string userCommand;
	for(;;){
		cout << ": ";
		getline(cin, userCommand);

		int first = 0;
		int last = size - 1;
		bool validCommand = false;

		while(!validCommand && first <= last){
			int middle = (first + last) / 2;
			if(array[middle] == userCommand){
				validCommand = true;
				return userCommand;			}
			else if(array[middle] > userCommand)
				last = middle - 1;
			else
				first = middle + 1;
		}
	}
	return "error";
}