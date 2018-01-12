#include <iostream>
#include <string>
#include <sstream>
#include <time.h>
#include <stdlib.h>
#include <limits>

using namespace std;

struct  userClass {
        string playerName;
        int playerAge;
        int classNum;
} mine, yours;

void printCompInfo(userClass player);
void printPlayerInfo(userClass player);
void getPlayerInfo();

int main(){
        getPlayerInfo();
	cout << endl << "I'LL LET YOU KNOW A LITTLE ABOUT MYSELF:" << endl;
	printCompInfo(mine);
	cout << endl;
	
	cout << "HERE'S WHAT I CAN TELL YOU ABOUT YOURSELF, TRAVELER:" << endl;
	printPlayerInfo(yours);
        return 0;
}

void getPlayerInfo(){
  srand(time(NULL));

	string nameIn;
	string ageIn;
	string classIn;

	yours.classNum = 0;
	
	cout << "\nWHAT'S YOUR NAME, TRAVELER?: ";
	getline(cin, nameIn);
	yours.playerName = nameIn;
	
	cout << "HOW OLD ARE YOU, " << nameIn << "?: ";
	
	while(yours.playerAge == 0){
	        getline(cin, ageIn);
	        stringstream(ageIn) >> yours.playerAge;
	  
	        if(yours.playerAge == 0){
	                  cout << "I DIDN'T UDERSTAND YOUR ANSWER. TRY AGAIN: ";
	        }
	}
	
	cout << "PICK YOUR CLASS (TYPE MAGE, WARRIOR, ROGUE, WARLOCK, OR RANDOM): ";
	
	while(yours.classNum == 0){
	        getline(cin, classIn);
	        stringstream(classIn) >> yours.classNum;
	  
	        if(classIn == "MAGE"){
	                yours.classNum = 1;
	        }else if(classIn == "WARRIOR"){
	                yours.classNum = 2;
	        }else if(classIn == "ROGUE"){
	                yours.classNum = 3;
	        }else if(classIn == "WARLOCK"){
	                yours.classNum = 4;
	        }else if(classIn == "RANDOM"){
	                yours.classNum = (rand() % 4) + 1;
	        }else{
		        cout << "I DIDN'T UDERSTAND YOUR ANSWER. TRY AGAIN: ";
		}
        }
	
	mine.playerName = "JOSHUA, THE MAGESTIC";
	mine.playerAge = 18;
	mine.classNum = rand() % 4;
}
 
void printCompInfo(userClass player){
        string classPick [4] = {"MAGE", "WARRIOR", "ROGUE", "WARLOCK"};
	  
        cout << "MY NAME IS " << player.playerName << "." << endl;
	cout << "I AM " << player.playerAge << " YEARS OF AGE." << endl;
	cout << "I AM a " << classPick[player.classNum] << "." << endl;
}

void printPlayerInfo(userClass player){
        
        string classPick[5] = {"nullClass", "MAGE", "WARRIOR", "ROGUE", "WARLOCK"};

	cout << endl << "YOUR NAME IS " << player.playerName << "." << endl;
	cout << "YOU ARE " << player.playerAge << " YEARS OF AGE." << endl;
	cout << "YOU ARE A " << classPick[player.classNum] << "." << endl;
}
