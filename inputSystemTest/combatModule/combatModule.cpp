#include <iostream>
#include <sstream>
#include "globalFunctions.h"
#include "combatModule.h"
#include "../global/header.h"
#include "../global/globalFunk.h"

class enemyInfo{
public:
	std::string enemyName;
	int enemyHealth;
	int enemyLevel;
} enemyOne;

int combatInitPrompt(std::string enemyNameInput, int enemyHealthInput, int enemyLevelInput){ 
	using std::cout;
	using std::endl;
	using std::string;

	enemyOne.enemyName = enemyNameInput;
	enemyOne.enemyHealth = enemyHealthInput;
	enemyOne.enemyLevel = enemyLevelInput;

	clear();
	string array[] = {"FIGHT", "RUN", "BUFFER"};
	cout << "A SCORNED LOVER STANDS BEFORE ME WEILDING A SPIKED CUDGEL!" << endl;
	cout << "WHAT SHOULD I DO?" << endl;
	cout << "FIGHT RUN" << endl;

	bubbleSort(array, 3);

	string userCommand = stringSearch(array, 3);
	clear();
	cout << userCommand << endl;
	if(userCommand == "FIGHT"){
		return combatFightModule();
	}
	else{
		combatRunModule();
		return 0;
	}

	return 2;
}

int combatFightModule(){ // The user has chosen to fight, run all of the functions for combat
	using std::string;
	using std::cout;
	using std::endl;
	using std::string;

	bool userTurn = true;
	string actionArray[] = {"ATTACK", "WAIT", "SPELL", "BUFFER", "BUFFER"};

	cout << "I WILL FIGHT THIS ONE!" << endl;

	sleepMilli(500);

	clear();
	printOptions();
	cout << "THE SCORNED LOVER STEPS CLOSER!" << endl;
	cout << endl << "WHAT DO I DO?" << endl;

	while(enemyOne.enemyHealth > 0 && playerInfo::playerHealth > 0){
		while(userTurn == true){
			bubbleSort(actionArray, 5);
			string userAction = stringSearch(actionArray, 5);

			if(userAction == "ATTACK"){
				combatUserAttackBasic();
				if(enemyOne.enemyHealth <= 0 ){
					cout << "I HAVE DASHED HIS BRAINS AGAINST THE COBBLESTONES! HOORAY!" << endl;
					sleepMilli(3000);
					return 1;
				}else{
					cout << "ENEMY HEALTH AT " << enemyOne.enemyHealth << endl;
				}
				userTurn = !userTurn;
			}else if(userAction == "SPELL"){
				combatUserSpellBasic();
				if(enemyOne.enemyHealth <= 0 ){
					cout << "I HAVE INCINERATED HIM! HOORAY!" << endl;
					sleepMilli(3000);
					return 1;
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
			}else if(enemyChoice == "WAIT"){
				combatEnemyWait();
			}
			if(playerInfo::playerHealth <= 0){
				cout << "I HAVE BEEN STRUCK DOWN! BLEH!" << endl;
				sleepMilli(3000);
				return 0;
			}
			userTurn = !userTurn;
		}
	}

	return 2;
}

void combatRunModule(){ // The user has chosen to try to run away, roll for chance of run away
	using std::cout;
	using std::endl;

	clear();
	cout << "I AM A COWARD AND RUN AWAY!" << endl;
	sleepMilli(3000);
}

// Attacks
//
// The only physical attack is a basic one with damage that varies on what class
// the player is.
//
// Warriors get the most significant bonus to their damage roll, adding to the
// damage roll their playerLevel. This means they are incapable of missing.
//
// Mages and warlocks get a slight nerf to their damage, mages being - 1, and
// warlocks being -4. Note cannot be negative damage, so a lot of hits are counted
// as misses.
//
// Rogues get a small buff to basic attack, +1, but it is static meaning that at
// higher levels rogues are going to have to rely on their other abilities.
//

void combatUserAttackBasic(){ // Rolls damage for the user basic attack and applies damage to the enemy
	using std::cout;
	using std::endl;

	srand(time(NULL));

	int damageRoll = (rand() % 10);

	if(playerInfo::classNum == 1){
		clear();
		printOptions();

		if(damageRoll < 1){
			damageRoll = 0;
		}else{
			damageRoll -= 1;
		}
		cout << endl << "I HAVE SMASHED HIS HEAD FOR " << damageRoll << " DAMAGE!" << endl;

		enemyOne.enemyHealth = enemyOne.enemyHealth - damageRoll;
	}else if(playerInfo::classNum == 2){
                clear();
                printOptions();
		
		damageRoll += playerInfo::playerLevel;

		cout << endl << "I HAVE SMASHED HIS HEAD FOR " << damageRoll << " DAMAGE!" << endl;

		enemyOne.enemyHealth = enemyOne.enemyHealth - damageRoll;

        }else if(playerInfo::classNum == 3){
                clear();
                printOptions();

		if(playerInfo::playerCrit == true){
			int critRoll = (rand() % 10) + 5;

			cout << endl << "I HAVE STAB THE ENEMY WITH MY ... ROCK!" << endl;

			enemyOne.enemyHealth = enemyOne.enemyHealth - critRoll;

			cout << "THEY TAKE " <<  critRoll << " DAMAGE" << endl;

			playerInfo::playerCrit = false;

		}else{
			damageRoll += 1;

			cout << endl << "I HAVE SMASHED HIS HEAD FOR " << damageRoll << " DAMAGE!" << endl;

			enemyOne.enemyHealth = enemyOne.enemyHealth - damageRoll;
		}
		
        }else if(playerInfo::classNum == 4){
                clear();
		printOptions();

		if(damageRoll < 4){
			damageRoll = 0;
		}else{
			damageRoll -= 4;
		}
		cout << endl << "I HAVE SMASHED HIS HEAD FOR " << damageRoll << " DAMAGE!" << endl;
		enemyOne.enemyHealth = enemyOne.enemyHealth - damageRoll;
        }
}

// Spells
// 
// At the moment the only spell is a basic damage spell that can only be used by
// mage and warlock. If a warrior or a rogue try and use the spell they waste 
// their turn.
//
// The mage has medium damage with the spell, 4 if it hits and 7 if it crits.
//
// Warlocks have higher spell damage, with 5 if it hits and 8 if it crits.
// 
// TODO:
//       Update damage to make warlock more apealing
//       Make some super rare effects of spells
//

void combatUserSpellBasic(){ // Spell damage rolls
	using std::cout;
	using std::endl;

	srand(time(NULL));

	int damageRoll;

	if(playerInfo::classNum == 1){
		clear();
		printOptions();

		damageRoll = (rand() % 10);
		if(damageRoll == 0){
			cout << "I CAST A FIRE BALL AT THE ENEMY! IT GOES PAST THEM AND HITS ME IN THE BACK OF THE HEAD!" << endl;
			cout << "I LOSE 3 HEALTH!" << endl;
			playerInfo::playerHealth = playerInfo::playerHealth - 3;
		}else if(damageRoll < 10){
			cout << "I SEND A FIRE BALL AT THE ENEMY! ";
			cout << "IT CONNECTS WITH HIS LEFT NOSTRIL!" << endl;
			enemyOne.enemyHealth = enemyOne.enemyHealth - 4;
			cout << "HE TAKES 4 DAMAGE, AND HIS NOSE HAIR IS SINGED!" << endl;
		}else if(damageRoll == 10){
			cout << "I SEND A LIGHTNING BOLT AT THE ENEMY! ";
			cout << "IT STRIKES HIM IN THE RIGHT BIG TOE!" << endl;
			enemyOne.enemyHealth = enemyOne.enemyHealth - 7;
			cout << "THE PAIN OF A HUNDRED STUBBED TOES BRINGS HIM 7 DAMAGES!" << endl;
		}
	}else if(playerInfo::classNum == 2){
                clear();
		printOptions();

		cout << "I TRY VERY HARD TO CAST A SPELL. INSTEAD I HAVE DROOLED ON MY CHEST!" << endl;
        }else if(playerInfo::classNum == 3){
                clear();
		printOptions();

		cout << "I TRY VERY HARD TO CAST A SPELL. INSTEAD I HAVE DROOLED ON MY CHEST!" << endl;
        }else if(playerInfo::classNum == 4){
                clear();
		printOptions();

		damageRoll = (rand() % 10);
		if(damageRoll == 0){
			cout << "I CAST A FIRE BALL AT THE ENEMY! IT GOES PAST THEM AND HITS ME IN THE BACK OF THE HEAD!" << endl;
			cout << "I LOSE 3 HEALTH!" << endl;
			playerInfo::playerHealth = playerInfo::playerHealth - 3;
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

// Wait turn
//
// If the player is a rogue then they prepare their weapon and gain a crit for 
// the next round
//
// If the player is any other class they waste their turn
//

void combatUserWait(){ 
	using std::cout;
	using std::endl;

	clear();
	printOptions();

	if(playerInfo::classNum == 3){
		cout << endl << "I PREPARE MY WEAPON, GIVING THE ENEMY A MEAN GLARE!" << endl;
		playerInfo::playerCrit = true;
	}else{
		cout << endl << "I HAVE COMPLETED MY LIFE LONG GOAL OF WASTING MY TURN!" << endl;
	}
}

std::string combatEnemyChoice(){ // Determin the choice of the enemy
	srand(time(NULL));
	int enemyChoice = (rand() % 5);

	if(enemyChoice > 3){
		return "WAIT";
	}else{
		return "ATTACK";
	}
}

void combatEnemyAttack(){ // Roll enemy damage and apply damage
	using std::cout;
	using std::endl;
	using std::cin;
	using std::string;

	srand(time(NULL));

	int damageRoll;

	cout << endl << "THE BRUTE STAGGERS FORWARD AND SWINGS AT ME WITH HIS SPIKED CUDGEL!" << endl;

	if(enemyOne.enemyLevel <= 5){
		damageRoll = (rand() % 10);
		if(damageRoll == 0){
			
			cout << endl << "THE BASTARD HAS MISSED! NOW IS MY CHANCE!" << endl;
			cout << endl;
		}else{
			
			playerInfo::playerHealth = playerInfo::playerHealth - damageRoll;
			cout << endl << "OOFF, I'VE TAKEN " << damageRoll << " DAMAGE!" << endl;
			if(playerInfo::playerHealth <= 0){
				string userDeathCommand;
				bool userDed = false;

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
				cout << "I ONLY HAVE " << playerInfo::playerHealth 
				<< " LEFT! I MUST BE CAREFUL" << endl;

				cout << endl;
			}
			
		}
	}
}

void combatEnemyWait(){ // The enemy waits a turn
	using std::cout;
	using std::endl;

	cout << endl << "THE DRUNKEN LOVER BELCHES AND STARES AT ME MENACINGLY!" << endl << endl;
}

void printOptions(){
	using std::cout;
	using std::endl;

	cout << "OPTIONS -- ATTACK (HIT THE ENEMY WITH A LARGE ROCK) -- SPELL (CAST A POWERFULL SPELL AT THE ENEMY... PROBABLY) -- WAIT (STAND WITH A BLANK EXPRESION)" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
}
