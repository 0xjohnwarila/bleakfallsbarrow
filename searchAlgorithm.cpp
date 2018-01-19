#include <iostream>
#include <string>
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
	string userCommand;
	for(;;){
		cout << "Please enter a command or ENG to terminate: ";
		getline(cin, userCommand);
		if(userCommand == "END") break;

		int first = 0;
		int last = size - 1;
		bool validCommand = false;

		while(!validCommand && first <= last){
			int middle = (first + last) / 2;
			if(array[middle] == userCommand){
				validCommand = true;
				cout << array[middle] << " is a valid command." << endl;
			}
			else if(array[middle] > userCommand)
				last = middle - 1;
			else
				first = middle + 1;
		}
	}
}

int main(){
	string array[] = {"move", "run", "go", "use", "eat", "head", "fight", "attack", "test"};
	bubbleSort(array, 9);
	search(array, 9);
}