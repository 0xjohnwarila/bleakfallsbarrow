#include <iostream>
#include <thread>
#include <sstream>
#include "globalFunctions.h"

void bubbleSort(std::string *array, int size){ // Sort the command array so the search can work
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

std::string stringSearch(std::string *array, int size){ // Check if the userCommand is in the string and then return it so the function can be called
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