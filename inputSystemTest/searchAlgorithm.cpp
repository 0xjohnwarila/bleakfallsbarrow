#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void bubbleSort(string *array, int size){
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

void search(string *array, int size){
	for(;;){
		if(userInput::inputString == "END") break;

		int first = 0;
		int last = size - 1;
		bool validCommand = false;

		while(!validCommand && first <= last){
			int middle = (first + last) / 2;
			if(array[middle] == userInput::inputString){
				validCommand = true;
				cout << userInput::inputString << " is a valid command" << endl;
			}
			else if(array[middle] > userInput::inputString)
				last = middle - 1;
			else
				first = middle + 1;
		}
		break;
	}
}

void specialSearch () {
	string array[] = {"HELP", "QUIT", "STOP", "TERMINATE", "HALT", "DISCONTINUE"};
	bubbleSort(array, 7);
	search(array, 7);
}

void verbSearch () {
	string array[] = {"MOVE", "GO", "WALK", "RUN", "HEAD", "TAKE", "STEAL", "GRAB", "PICKUP", "SNATCH", "USE"};
	bubbleSort(array, 12);
	search(array, 12);
}