#include <iostream>
#include <string>
#include <sstream>
#include <time.h>
#include <stdlib.h>
#include <limits>
#include <chrono>
#include <thread>

using std::string;

class playerInfo {
public:
	string playerName;
	int playerAge;
	int classNum;
	int playerLoc;
	int playerHealth;
	int playerLevel;
} playerOne;

class enemyInfo{
public:
	string enemyName;
	int enemyHealth;
	int enemyLevel;
} enemyOne;

void getPlayerInfo();
void makeEnemy();
void clearScreen();
void introCombatText();
string stringSearch(string *array, int size);
void bubbleSort(string *array, int size);
void combatInitPrompt();
void combatFightModule();
void combatRunModule();
void sleepMilli(int x);
void combatUserAttackBasic();
void combatUserWait();
string combatEnemyChoice();
void combatEnemyAttack();
void combatUserSpellBasic();

int main(){
	clearScreen();
	introCombatText(); // Run the intro
	getPlayerInfo(); // Get the data on player character
	makeEnemy(); // Fill enemy data
	combatInitPrompt(); // Initialize combat
	return 0;
}

void introCombatText(){ // Basic intro text
	using std::cout;
	using std::endl;

	cout << "WELCOME TO THE COMBAT MODULE!!" << endl;
	cout << "IN THIS BREIF DEMO YOU WILL CREATE A CHARACTER AND FIGHT A FOE" << endl;
	cout << "LET'S BEGIN!!!!!!!!!" << endl ;

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

void makeEnemy(){ // Fill the enemy class with data on a default enemy
	enemyOne.enemyName = "Bagrosh the Slimy";
	enemyOne.enemyHealth = 20;
	enemyOne.enemyLevel = 2;

	playerOne.playerHealth = 30; // !!!!!!!!!! TEMP SHIT CHANGE BEFORE PROD !!!!!!!!!!!!!!
	playerOne.playerLevel = 3;
}

void clearScreen(){ // Clear the screen and move curser to the upper left
	using std::cout;

	cout << "\033[2J\033[1;1H";
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

void combatInitPrompt(){ // Initial the combat with choice to fight or run, if 
	                 //fight is chosen you will be sent to the combat proper, if run you will have a chance to escape
	using std::cout;
	using std::endl;

	clearScreen();
	string array[] = {"FIGHT", "RUN", "BUFFER"};
	cout << "A SCORNED LOVER STANDS BEFORE ME WEILDING A SPIKED CUDGEL!" << endl;
	cout << "WHAT SHOULD I DO?" << endl;
	cout << "FIGHT RUN" << endl;

	bubbleSort(array, 3);

	string userCommand = stringSearch(array, 3);
	clearScreen();
	cout << userCommand << endl;
	if(userCommand == "FIGHT"){
		combatFightModule();
	}
	else{
		combatRunModule();
	}
}

void combatFightModule(){ // The user has chosen to fight, run all of the functions for combat
	using std::string;
	using std::cout;
	using std::endl;

	bool userTurn = true;
	string actionArray[] = {"ATTACK", "WAIT", "SPELL", "BUFFER", "BUFFER"};

	cout << "I WILL FIGHT THIS ONE!" << endl;

	sleepMilli(500);

	cout << "THE SCORNED LOVER STEPS CLOSER!" << endl;
	cout << endl << "WHAT DO I DO?" << endl;
	cout << "-- ATTACK -- WAIT -- SPELL --" << endl;
	while(enemyOne.enemyHealth > 0 && playerOne.playerHealth > 0){
		while(userTurn == true){
			bubbleSort(actionArray, 5);
			string userAction = stringSearch(actionArray, 5);

			if(userAction == "ATTACK"){
				combatUserAttackBasic();
				if(enemyOne.enemyHealth <= 0 ){
					cout << "I HAVE DASHED HIS BRAINS AGAINST THE COBBLESTONES! HOORAY!" << endl;
					break;
				}else{
					cout << "ENEMY HEALTH AT " << enemyOne.enemyHealth << endl;
				}
				userTurn = !userTurn;
			}else if(userAction == "SPELL"){
				combatUserSpellBasic();
				if(enemyOne.enemyHealth <= 0 ){
					cout << "I HAVE INCINERATED HIM! HOORAY!" << endl;
					break;
				}else{
					cout << "ENEMY HEALTH AT " << enemyOne.enemyHealth << endl;
				}
				userTurn = !userTurn;
			}else{
				combatUserWait();
				userTurn = !userTurn;
			}
		}

		while(userTurn == false){
			string enemyChoice = combatEnemyChoice();

			if(enemyChoice == "ATTACK"){
				combatEnemyAttack();
			}
			if(playerOne.playerHealth <= 0){
				cout << "I HAVE BEEN STRUCK DOWN! BLEH!" << endl;
			}
			userTurn = !userTurn;
		}
	}
	
	
}

void combatRunModule(){ // The user has chosen to try to run away, roll for chance of run away
	using std::cout;
	using std::endl;

	clearScreen();
	cout << "I AM A COWARD AND RUN AWAY!" << endl;
}

void sleepMilli(int x){ // Sleeps for X milliseconds
	std::this_thread::sleep_for(std::chrono::milliseconds(x));
}

void combatUserAttackBasic(){ // Rolls damage for the user basic attack and applies damage to the enemy
	using std::cout;
	using std::endl;

	srand(time(NULL));

	int damageRoll = (rand() % 10);

	if(playerOne.classNum == 1){
		clearScreen();
		cout << "OPTIONS -- ATTACK (HIT THE ENEMY WITH A LARGE ROCK) -- SPELL (CAST A POWERFULL SPELL AT THE ENEMY... PROBABLY) -- WAIT (STAND WITH A BLANK EXPRESION)" << endl;
		if(damageRoll < 1){
			damageRoll = 0;
		}else{
			damageRoll -= 1;
		}
		cout << endl << "I HAVE SMASHED HIS HEAD FOR " << damageRoll << " DAMAGE!" << endl;
		enemyOne.enemyHealth = enemyOne.enemyHealth - damageRoll;
	}else if(playerOne.classNum == 2){
                clearScreen();
		cout << "OPTIONS -- ATTACK (HIT THE ENEMY WITH A LARGE ROCK) -- SPELL (CAST A POWERFULL SPELL AT THE ENEMY... PROBABLY) -- WAIT (STAND WITH A BLANK EXPRESION)" << endl;
		damageRoll += playerOne.playerLevel;
		cout << endl << "I HAVE SMASHED HIS HEAD FOR " << damageRoll << " DAMAGE!" << endl;
		enemyOne.enemyHealth = enemyOne.enemyHealth - damageRoll;
        }else if(playerOne.classNum == 3){
                clearScreen();
		cout << "OPTIONS -- ATTACK (HIT THE ENEMY WITH A LARGE ROCK) -- SPELL (CAST A POWERFULL SPELL AT THE ENEMY... PROBABLY) -- WAIT (STAND WITH A BLANK EXPRESION)" << endl;
		damageRoll += 1;
		cout << endl << "I HAVE SMASHED HIS HEAD FOR " << damageRoll << " DAMAGE!" << endl;
		enemyOne.enemyHealth = enemyOne.enemyHealth - damageRoll;
        }else if(playerOne.classNum == 4){
                clearScreen();
		cout << "OPTIONS -- ATTACK (HIT THE ENEMY WITH A LARGE ROCK) -- SPELL (CAST A POWERFULL SPELL AT THE ENEMY... PROBABLY) -- WAIT (STAND WITH A BLANK EXPRESION)" << endl;
		if(damageRoll < 4){
			damageRoll = 0;
		}else{
			damageRoll -= 4;
		}
		cout << endl << "I HAVE SMASHED HIS HEAD FOR " << damageRoll << " DAMAGE!" << endl;
		enemyOne.enemyHealth = enemyOne.enemyHealth - damageRoll;
        }
}

void combatUserSpellBasic(){
	using std::cout;
	using std::endl;

	srand(time(NULL));

	int damageRoll;

	if(playerOne.classNum == 1){
		clearScreen();
		cout << "OPTIONS -- ATTACK (HIT THE ENEMY WITH A LARGE ROCK) -- SPELL (CAST A POWERFULL SPELL AT THE ENEMY... PROBABLY) -- WAIT (STAND WITH A BLANK EXPRESION)" << endl << endl;
		damageRoll = (rand() % 10);
		if(damageRoll == 0){
			cout << "I CAST A FIRE BALL AT THE ENEMY! IT GOES PAST THEM AND HITS ME IN THE BACK OF THE HEAD!" << endl;
			cout << "I LOSE 3 HEALTH!" << endl;
			playerOne.playerHealth = playerOne.playerHealth - 3;
		}else if(damageRoll < 10){
			cout << "I SEND A FIRE BALL AT THE ENEMY!" << endl;
			cout << "IT CONNECTS WITH HIS LEFT NOSTRIL!" << endl;
			enemyOne.enemyHealth = enemyOne.enemyHealth - 4;
			cout << "HE TAKES 4 DAMAGE, AND HIS NOSE HAIR IS SINGED!" << endl;
		}else if(damageRoll == 10){
			cout << "I SEND A LIGHTNING BOLT AT THE ENEMY!" << endl;
			cout << "IT STRIKES HIM IN THE RIGHT BIG TOE!" << endl;
			enemyOne.enemyHealth = enemyOne.enemyHealth - 7;
			cout << "THE PAIN OF A HUNDRED STUBBED TOES BRINGS HIM 7 DAMAGES!" << endl;
		}
	}else if(playerOne.classNum == 2){
                clearScreen();
		cout << "OPTIONS -- ATTACK (HIT THE ENEMY WITH A LARGE ROCK) -- SPELL (CAST A POWERFULL SPELL AT THE ENEMY... PROBABLY) -- WAIT (STAND WITH A BLANK EXPRESION)" << endl << endl;
		cout << "I TRY VERY HARD TO CAST A SPELL. INSTEAD I HAVE DROOLED ON MY CHEST!" << endl;
        }else if(playerOne.classNum == 3){
                clearScreen();
		cout << "OPTIONS -- ATTACK (HIT THE ENEMY WITH A LARGE ROCK) -- SPELL (CAST A POWERFULL SPELL AT THE ENEMY... PROBABLY) -- WAIT (STAND WITH A BLANK EXPRESION)" << endl << endl;
		cout << "I TRY VERY HARD TO CAST A SPELL. INSTEAD I HAVE DROOLED ON MY CHEST!" << endl;
        }else if(playerOne.classNum == 4){
                clearScreen();
		cout << "OPTIONS -- ATTACK (HIT THE ENEMY WITH A LARGE ROCK) -- SPELL (CAST A POWERFULL SPELL AT THE ENEMY... PROBABLY) -- WAIT (STAND WITH A BLANK EXPRESION)" << endl << endl;
		damageRoll = (rand() % 10);
		if(damageRoll == 0){
			cout << "I CAST A FIRE BALL AT THE ENEMY! IT GOES PAST THEM AND HITS ME IN THE BACK OF THE HEAD!" << endl;
			cout << "I LOSE 3 HEALTH!" << endl;
			playerOne.playerHealth = playerOne.playerHealth - 3;
		}else if(damageRoll < 10){
			cout << "I SEND A FIRE BALL AT THE ENEMY!" << endl << endl;
			cout << "IT CONNECTS WITH HIS LEFT NOSTRIL!" << endl << endl;
			enemyOne.enemyHealth = enemyOne.enemyHealth - 5;
			cout << "HE TAKES 5 DAMAGE, AND HIS NOSE HAIR IS SINGED!" << endl;
		}else if(damageRoll == 10){
			cout << "I SEND A LIGHTNING BOLT AT THE ENEMY!" << endl;
			cout << "IT STRIKES HIM IN THE RIGHT BIG TOE!" << endl;
			enemyOne.enemyHealth = enemyOne.enemyHealth - 8;
			cout << "THE PAIN OF A HUNDRED STUBBED TOES BRINGS HIM 8 DAMAGE!" << endl;
		}
        }
}
void combatUserWait(){ // User is an idiot and waited
	using std::cout;
	using std::endl;

	clearScreen();
	cout << "OPTIONS -- ATTACK (HIT THE ENEMY WITH A LARGE ROCK) -- WAIT (STAND WITH A BLANK EXPRESION)" << endl;
	cout << endl << "I HAVE ACOMPLISHED MY LIFE LONG GOAL OF WASTING MY TURN!" << endl;
	cout << endl;
}

string combatEnemyChoice(){ // TODO : Make this choice semi random
	return "ATTACK";
}

void combatEnemyAttack(){ // Roll enemy damage and apply damage
	using std::cout;
	using std::endl;
	using std::cin;

	srand(time(NULL));

	int damageRoll;

	if(enemyOne.enemyLevel <= 5){
		damageRoll = (rand() % 10);
		if(damageRoll == 0){
			
			cout << endl << "THE BASTARD HAS MISSED! NOW IS MY CHANCE!" << endl;
			cout << endl;
		}else{
			
			playerOne.playerHealth = playerOne.playerHealth - damageRoll;
			cout << endl << "OOFF, I'VE TAKEN " << damageRoll << " DAMAGE!" << endl;
			if(playerOne.playerHealth <= 0){
				string userDeathCommand;
				bool userDed;

				cout << endl << "I MUST NOW CHOOSE TO HOLD ON OR DIE." << endl;
				getline(cin, userDeathCommand);

				while(!userDed){
					if(userDeathCommand == "DIE"){
						userDed = true;
					}else{
						cout << "I REALLY AM TIRED..." << endl << endl;
						getline(cin, userDeathCommand);
					}

				}
			}else{
				cout << "I ONLY HAVE " << playerOne.playerHealth << " LEFT! I MUST BE CAREFUL" << endl;
				cout << endl;
			}
			
		}
	}
}
