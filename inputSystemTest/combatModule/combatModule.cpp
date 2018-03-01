#include <iostream>
#include <sstream>
#include "globalFunctions.h"
#include "combatModule.h"
#include "../global/header.h"
#include "../global/globalFunk.h"
#include "../playerInput/inputSplit.h"
#include "../combatModule/bossFightFlavor/bossFightFlavor.h"

class enemyInfo{
public:
	std::string enemyName, enemyWeapon;
	int enemyHealth;
	int enemyLevel;
} enemyOne, endlessTerror;

int combatInitPrompt(std::string enemyNameInput, std::string enemyWeaponInput, int enemyHealthInput, int enemyLevelInput){ 
	using std::cout;
	using std::endl;
	using std::string;

	if(enemyNameInput == "ENDLESS TERROR"){
		return bossFightEndlessTerror();
	}

	enemyOne.enemyWeapon = checkEnemyWeaponInput(enemyWeaponInput);
	enemyOne.enemyName = checkEnemyNameInput(enemyNameInput);
	enemyOne.enemyHealth = enemyHealthInput;
	enemyOne.enemyLevel = enemyLevelInput;

	clear();
	string userCommandArray[] = {"FIGHT", "RUN", "BUFFER"};
	cout << enemyOne.enemyName << " STANDS BEFORE ME WEILDING " << enemyOne.enemyWeapon << "!" << endl;
	cout << "WHAT SHOULD I DO?" << endl;
	cout << "FIGHT RUN" << endl;

	string userCommand = checkUserInput(userCommandArray, 3);

	clear();
	cout << userCommand << endl;

	if(userCommand == "FIGHT"){
		itemChoice();
		return combatFightModule();
	}
	else{
		combatRunModule();
		return 0;
	}

	return 2;
}

void itemChoice() {
	using std::cout;
	using std::endl;
	bool choice = false;

	clear();
	if (userInput::stone == true) {
		cout << "PICK A WEAPON!: " << endl << endl;
		if (userInput::stone == true) {
			cout << "MYSTERIOUS STONE (+2 DAMAGE)" << endl;
		}
		if (userInput::key == true) {
			cout << "GOLDEN KEY (+1 DAMAGE)" << endl;
		}
		if (userInput::skeleSword == true) {
			cout << "RUSTY BROADSWORD (+5 DAMAGE)" << endl;
		}
		cout << endl << ": ";

		while (choice == false) {
			playerInput();
			if (userInput::noun=="STONE") {
				playerInfo::playerWeapon = "MYSTERIOUS STONE";
				choice = true;
			}
			else if (userInput::noun=="KEY") {
				playerInfo::playerWeapon = "GOLDEN KEY";
				choice = true;
			}
			else if (userInput::noun=="BROADSWORD") {
				playerInfo::playerWeapon = "RUSTY BROADSWORD";
				choice = true;
			}
			else {
				cout << "I CAN'T DO THAT." << endl;
			}
		}
		cout << "YOU PICKED THE " << playerInfo::playerWeapon << endl << endl;
	}

	if (userInput::vineDead == true || userInput::greenRag == true) {
		cout << "PICK A SUPPORT ITEM!: " << endl << endl;
		if (userInput::vineDead == true) {
			cout << "WRIGLING VINE (WRAPS AROUND ENEMY FOR 2 TURNS)" << endl;
		}
		if (userInput::greenRag == true) {
			cout << "SKELETON'S RAGS (+2 DEFENSE)" << endl;
		}
		cout << endl << ": ";

		choice = false;
		while (choice == false) {
			playerInput();
			if (userInput::noun=="VINE") {
				playerInfo::playerSupportItem = "WRIGGLING VINE";
				choice = true;
			}
			else if (userInput::noun=="CLOTH") {
				playerInfo::playerSupportItem = "SKELETON'S RAGS";
				choice = true;
			}
			else {
				cout << "I CAN'T DO THAT." << endl;
			}
		}
		cout << "YOU PICKED THE " << playerInfo::playerSupportItem << endl << endl;
	}

	if (choice == true) {
		enterPause();
	}
}

int combatFightModule(){ // The user has chosen to fight, run all of the functions for combat
	using std::string;
	using std::cout;
	using std::endl;
	using std::string;

	playerInfo::playerTurn = true;
	string actionArray[] = {"ATTACK", "WAIT", "SPELL", "BUFFER", "BUFFER"};

	cout << "I WILL FIGHT THIS ONE!" << endl;

	sleepMilli(500);

	clear();
	printOptions();
	cout << enemyOne.enemyName << " STEPS CLOSER!" << endl;
	cout << endl << "WHAT DO I DO?" << endl;

	while(enemyOne.enemyHealth > 0 && playerInfo::playerHealth > 0){
		if(playerInfo::playerSkipTurn == true){
			skipPlayerTurn();
		}

		while(playerInfo::playerTurn == true){
			string userAction = checkUserInput(actionArray, 5);

			if(userAction == "ATTACK"){
				combatUserAttackBasic();
				if(enemyOne.enemyHealth <= 0 ){
					cout << "I HAVE DASHED " << enemyOne.enemyName << "'S BRAINS AGAINST THE COBBLESTONES! HOORAY!" << endl;
					cout << "\n\nPRESS ENTER TO CONTINUE..." << endl;
					getchar();
					return 1;
				}else{
					cout << enemyOne.enemyName << " HAS " << enemyOne.enemyHealth << " HEALTH LEFT!" << endl;
				}
				playerInfo::playerTurn = !playerInfo::playerTurn;
			}else if(userAction == "SPELL"){
				combatUserSpellBasic();
				if(enemyOne.enemyHealth <= 0 ){
					cout << "I HAVE INCINERATED " << enemyOne.enemyName << "! HOORAY!" << endl;
					cout << "\n\nPRESS ENTER TO CONTINUE..." << endl;
					getchar();
					return 1;
				}else{
					cout << enemyOne.enemyName << " HAS " << enemyOne.enemyHealth << " HEALTH LEFT!" << endl;
				}
				playerInfo::playerTurn = !playerInfo::playerTurn;
			}else{
				combatUserWait();
				playerInfo::playerTurn = !playerInfo::playerTurn;
			}
		}

		while(playerInfo::playerTurn == false){
			string enemyChoice = combatEnemyChoice();

			if(enemyChoice == "ATTACK"){
				combatEnemyAttack();
			}else if(enemyChoice == "WAIT"){
				combatEnemyWait();
			}
			if(playerInfo::playerHealth <= 0){
				cout << "I HAVE BEEN STRUCK DOWN! BLEH!" << endl;
				cout << "\n\nPRESS ENTER TO CONTINUE..." << endl;
				getchar();
				return 0;
			}
			playerInfo::playerTurn = !playerInfo::playerTurn;
		}
	}

	return 2;
}

void combatRunModule(){ // The user has chosen to try to run away, roll for chance of run away
	using std::cout;
	using std::endl;

	clear();
	cout << "I AM A COWARD AND RUN AWAY!" << endl;
	cout << "\n\nPRESS ENTER TO CONTINUE..." << endl;
	getchar();
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

int damageRoller(int damageRoll) {
	if (playerInfo::playerWeapon=="FISTS") {
		return damageRoll;
	}
	else if (playerInfo::playerWeapon=="MYSTERIOUS STONE") {
		return damageRoll += 2;
	}
	else if (playerInfo::playerWeapon=="GOLDEN KEY") {
		return damageRoll += 1;
	}
	else if (playerInfo::playerWeapon=="RUSTY BROADSWORD") {
		return damageRoll += 5;
	}
	else {
		return 0;
	}
}

void combatUserAttackBasic(){ // Rolls damage for the user basic attack and applies damage to the enemy
	using std::cout;
	using std::endl;

	int damageRoll = 0;
	damageRoll = (rand() % 10);



	if(playerInfo::classNum == 1){
		clear();
		printOptions();

		if(damageRoll < 1){
			damageRoll = 0;
		}else{
			damageRoll -= 1;
		}
		damageRoll = damageRoller(damageRoll);

		cout << endl << "I HAVE SMASHED " << enemyOne.enemyName <<"'S HEAD WITH MY " << playerInfo::playerWeapon << " FOR " << damageRoll << " DAMAGE!" << endl;

		enemyOne.enemyHealth = enemyOne.enemyHealth - damageRoll;
	}else if(playerInfo::classNum == 2){
                clear();
                printOptions();
		
		damageRoll += playerInfo::playerLevel;
		damageRoll = damageRoller(damageRoll);

		cout << endl << "I HAVE SMASHED " << enemyOne.enemyName <<"'S HEAD WITH MY " << playerInfo::playerWeapon << " FOR " << damageRoll << " DAMAGE!" << endl;

		enemyOne.enemyHealth = enemyOne.enemyHealth - damageRoll;

        }else if(playerInfo::classNum == 3){
                clear();
                printOptions();

		if(playerInfo::playerCrit == true){
			int critRoll = (rand() % 10) + 5;
			damageRoll = damageRoller(damageRoll);

			cout << endl << "I HAVE STABBED THE ENEMY WITH MY " << playerInfo::playerWeapon << "!" << endl;

			enemyOne.enemyHealth = enemyOne.enemyHealth - critRoll;

			cout << "IT TAKES " <<  critRoll << " DAMAGE" << endl;

			playerInfo::playerCrit = false;

		}else{
			damageRoll += 1;
			damageRoll = damageRoller(damageRoll);

			cout << endl << "I HAVE SMASHED " << enemyOne.enemyName <<"'S HEAD WITH MY " << playerInfo::playerWeapon << " FOR " << damageRoll << " DAMAGE!" << endl;

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
		damageRoll = damageRoller(damageRoll);

		cout << endl << "I HAVE SMASHED " << enemyOne.enemyName <<"'S HEAD WITH MY " << playerInfo::playerWeapon << " FOR " << damageRoll << " DAMAGE!" << endl;

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

	

	int damageRoll;

	if(playerInfo::classNum == 1){
		clear();
		printOptions();

		damageRoll = (rand() % 10);
		if(damageRoll == 0){
			cout << "I CAST A FIRE BALL AT " << enemyOne.enemyName << "! THE FIRE BALL GOES PAST IT AND HITS ME IN THE BACK OF THE HEAD!" << endl;
			cout << "I LOSE 3 HEALTH!" << endl;
			playerInfo::playerHealth = playerInfo::playerHealth - 3;
		}else if(damageRoll < 10){
			cout << "I SEND A FIRE BALL AT " << enemyOne.enemyName << "! " << endl;
			cout << "THE FIRE BALL CONNECTS WITH IT'S " << randomBodyPart() << "!" << endl;
			enemyOne.enemyHealth = enemyOne.enemyHealth - 4;
			cout << "IT TAKES 4 DAMAGE!" << endl;
		}else if(damageRoll == 10){
			cout << "I SEND A LIGHTNING BOLT AT " << enemyOne.enemyName << "! ";
			cout << "IT STRIKES IT IN THE RIGHT BIG TOE!" << endl;
			enemyOne.enemyHealth = enemyOne.enemyHealth - 7;
			cout << "THE PAIN OF A HUNDRED STUBBED TOES BRINGS IT 7 DAMAGE!" << endl;
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
			cout << "I CAST A FIRE BALL AT " << enemyOne.enemyName << "! THE FIRE BALL GOES PAST IT AND HITS ME IN THE BACK OF THE HEAD!" << endl;
			cout << "I LOSE 3 HEALTH!" << endl;
			playerInfo::playerHealth = playerInfo::playerHealth - 3;
		}else if(damageRoll < 10){
			cout << "I SEND A FIRE BALL AT " << enemyOne.enemyName << "!" << endl << endl;
			cout << "THE FIRE BALL CONNECTS WITH IT'S " << randomBodyPart() << "!" << endl;
			enemyOne.enemyHealth = enemyOne.enemyHealth - 5;
			cout << "IT TAKES 5 DAMAGE!" << endl;
		}else if(damageRoll == 10){
			cout << "I SEND A LIGHTNING BOLT AT " << enemyOne.enemyName << "!" << endl;
			cout << "THE LIGHTNING BOLT STRIKES IT IN THE RIGHT BIG TOE!" << endl;
			enemyOne.enemyHealth = enemyOne.enemyHealth - 8;
			cout << "THE PAIN OF A HUNDRED STUBBED TOES BRINGS IT 8 DAMAGE!" << endl;
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
		cout << endl << "I PREPARE MY WEAPON, GIVING " << enemyOne.enemyName << " A MEAN GLARE!" << endl;
		playerInfo::playerCrit = true;
	}else{
		cout << endl << "I HAVE COMPLETED MY LIFE LONG GOAL OF WASTING MY TURN!" << endl;
	}
}

std::string combatEnemyChoice(){ // Determin the choice of the enemy
	
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

	

	int damageRoll;

	cout << endl  << enemyOne.enemyName << " STAGGERS FORWARD AND SWINGS AT ME WITH " << enemyOne.enemyWeapon << "!" << endl;

	if(enemyOne.enemyLevel <= 5){
		damageRoll = (rand() % 10);
		if(damageRoll == 0){
			
			cout << endl << enemyOne.enemyName << " HAS MISSED! NOW IS MY CHANCE!" << endl;
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

	cout << endl << enemyOne.enemyName << " BELCHES AND STARES AT ME MENACINGLY!" << endl << endl;
}

void printOptions(){
	using std::cout;
	using std::endl;

	cout << "OPTIONS -- ATTACK (" << playerInfo::playerWeapon << ") -- SPELL (FIRE BALL) -- ITEM (" << playerInfo::playerSupportItem << ") -- WAIT" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
}

std::string checkEnemyNameInput(std::string enemyNameInput){
	if(enemyNameInput == "RANDOM"){
		return randomEnemyName();
	}else{
		return enemyNameInput;
	}
}

std::string checkEnemyWeaponInput(std::string enemyWeaponInput){
	if(enemyWeaponInput == "RANDOM"){
		return randomEnemyWeapon();
	}else{
		return enemyWeaponInput;
	}
}

std::string randomEnemyName(){
	std::string enemyNameArray[49] = {"THE SLIMY SQUABLER", "THE STUPID BRUTE", "THE IMMENSE BLOB", "STICKY MCGEE", "DAVE", "LENGTHY, THE RECKONER", "AGED PREACHER MARGARET", "WEOLDIN, THE FOURTH LION", "ROMAM, GREAT KNIGHT", "THE DEATH REVEREND", "RADRICK, MASTER OF SMOKE", "THE ANCIENT ONE", "WARILA, THE UNBOUND", "WIZARD, THE UNFORGIVING", "WHISKEY BRICKLE", "THE HIGH PRIEST OF SORROW", "THE ANNOYING AMBASSADOR, LORD OF HATRED", "THE THUNDEROR CONQUEROR", "GARMUND, PRINCE OF SUNLIGHT", "CEOLFRID, ELF OF CHAINS", "BYRNWOLD, EXARCH OF THE BLIND", "GRIEVING CURATOR WOLFRUN", "REYNOLDS, THE GOLDEN GOD", "THE TRASH MAN", "VIC VINEGAR, THE UNWEILDING", "MAJORA, FEARLESS TRIBUNE OF THE ENDLESS MASKS", "THE EXALTED PALADIN OF JUDGEMENT", "WICK, THE CORRUPTED", "THE LOST SOUL", "THE LARGE RAT", "THE SWARM OF ANTS", "THE LEAF MONSTER", "THE ANCIENT DIVINITY AELFMAER", "RIGHTEOUS AILMAR, CONSUL OF MIRRORS", "EDITH, MATRIARCH OF SCALES", "THE FORSAKEN ONE", "AETHELIND, SAGE OF COLOR", "BALDWIN, DIVINITY OF GLASS", "THE WEREMOUSE", "LENGTHY, RIDICULED ONE", "THE ABANDONED WORM", "THE ROBED ROBBER", "THE SCREAMING ANTELOPE", "THE WHITE LION", "GHOSTFACE, UNCAGED BUTCHER", "NOLE K'SUM, THE FALCON TRAINER", "GENGHIS, CONQUEROR OF REALMS", "ARCHIBALD, UNDERWORLD CHEF", "GOR, GREAT MONGREL OF THE DEPTHS"};

	return enemyNameArray[(rand() % 49)];
}

std::string randomEnemyWeapon(){
	std::string enemyWeaponArray[23] = {"A SPIKED CUDGEL", "A RUSTY BROADSWORD", "A GLEAMING SCIMITAR", "A CHIPPED HAND-AND-A-HALF SWORD", "A POISON-TIPPED HALBERD", "A HATTORI HANSO SWORD", "TWIN SAIS", "A DARK SCYTHE", "A ROYAL GREATSWORD", "A ZWEIHÄNDER", "A STIFF QUARTERSTAFF", "TWO SMALL DAGGERS", "TWIN KITANAS", "A LONG KITANA", "A HEAVY ROCK", "A RED BRICK", "THE ART OF SHAOLIN SHADOWBOXING", "CLOSED FISTS", "A MEAN GLARE", "A LENGTHY SPEAR", "A MENACING CHAINWHIP", "TWO NUNCHUCKS", "DUCT TAPE AND ZIP TIES"};

	return enemyWeaponArray[(rand() % 23)];
}

std::string randomBodyPart(){
	using std::cout;
	using std::endl;
	std::string randomBodyPartArray[30] = {"LEFT NOSTRIL", "RIGHT NOSTRIL", "APPENDIX", "LEFT KNEE", "RIGHT KNEE", "LEFT EARLOBE", "RIGHT EARLOBE", "SPLEEN", "BULGING STOMACH", "LEFT TIBULAR", "FAT FACE", "LEFT KNEE PIT", "RIGHT KNEE PIT", "LEFT ARMPIT", "RIGHT ARMPIT", "LEFT EYE SOCKET", "RIGHT EYE SOCKET", "NOGGIN", "SCALP", "THROBBING FOREHEAD", "INNER SOUL", "SPINDLY FINGERS", "LEFT NIPPLE", "RIGHT NIPPLE", "BELLY BUTTON", "SPECIAL AREA", "LEFT JAW", "RIGHT JAW", "TONSILS", "FEELS"};

	return randomBodyPartArray[(rand() % 30)];
}

void skipPlayerTurn(){
	using std::cout;
	using std::endl;

	clear();
	printOptions();

	cout << "A GREAT WEAKNESS OVERCOMES ME! I HAVE LOST MY TURN!" << endl;

	playerInfo::playerTurn = false;
	playerInfo::playerSkipTurn = false;
}

int bossFightEndlessTerror(){
	using std::cout;
	using std::endl;

	clear();

	endlessTerrorIntroText();
	itemChoice();

	enemyOne.enemyWeapon = "A TENDRIL OF EVERLASTING SUFFERING";
	enemyOne.enemyName = "THE ENDLESS TERROR";
	enemyOne.enemyHealth = 80;
	enemyOne.enemyLevel = 5;

	clear();
	printOptions();

	cout << "THE ENDLESS TERROR DRIFTS CLOSER!" << endl;

	while(playerInfo::playerHealth > 0){
		while(playerInfo::playerTurn == true){
			std::string playerChoice = getPlayerChoice();

			if(playerChoice == "ATTACK"){
				combatUserAttackBasic();

				if(enemyOne.enemyHealth <= 0 ){
					endlessTerrorCastIntoVoid();
					return 0;
				}else{
					cout << enemyOne.enemyName << " HAS " << enemyOne.enemyHealth << " HEALTH LEFT!" << endl;
				}
				playerInfo::playerTurn = !playerInfo::playerTurn;
			}else if(playerChoice == "SPELL"){
				combatUserSpellBasic();
				if(enemyOne.enemyHealth <= 20 ){
					endlessTerrorCastIntoVoid();
					return 0;
				}else{
					cout << enemyOne.enemyName << " HAS " << enemyOne.enemyHealth << " HEALTH LEFT!" << endl;
				}
				playerInfo::playerTurn = !playerInfo::playerTurn;
			}else{
				combatUserWait();
				playerInfo::playerTurn = !playerInfo::playerTurn;
			}
		}

		while(playerInfo::playerTurn == false){
			std::string enemyChoice = endlessTerrorCombatChoice();

			if(enemyChoice == "MIND FLAY"){
				endlessTerrorMindFlay();
			}else if(enemyChoice == "HORRENDOUS VISIONS"){
				endlessTerrorHorrendousVisions();
			}else if(enemyChoice == "TENTACLE SLAP"){
				endlessTerrorTentacleSlap();
			}else if(enemyChoice == "CAST INTO VOID"){
				endlessTerrorCastIntoVoid();
			}


			if(playerInfo::playerHealth <= 0 && !playerInfo::playerIsInsane){
				endlessTerrorCastIntoVoid();
				return 0;
			}else if(playerInfo::playerIsInsane){
				return 0;
			}

			playerInfo::playerTurn = !playerInfo::playerTurn;
		}
	}

}

std::string getPlayerChoice(){
	using std::cout;
	using std::endl;

	std::string actionArray[] = {"ATTACK", "WAIT", "SPELL", "BUFFER", "BUFFER"};

	cout << endl << endl << "WHAT DO I DO: ";

	return checkUserInput(actionArray, 5);
}

std::string endlessTerrorCombatChoice(){
	int choice = (rand() % 2);

	if(playerInfo::playerHealth > 30){
		//endlessTerrorMindFlay();
		return "MIND FLAY";
	}else if(playerInfo::playerHealth > 20){
		if(choice == 0){
			//endlessTerrorHorrendousVisions();
			return "HORRENDOUS VISIONS";
		}else{
			//endlessTerrorTentacleSlap();
			return "TENTACLE SLAP";
		}
	}else if(playerInfo::playerHealth > 5){
		if(choice == 0){
			//endlessTerrorTentacleSlap();
			return "TENTACLE SLAP";
		}else{
			//endlessTerrorHorrendousVisions();
			return "HORRENDOUS VISIONS";
		}
	}else{
		//endlessTerrorCastIntoVoid();
		return "CAST INTO VOID";
	}
}

void endlessTerrorMindFlay(){
	using std::cout;
	using std::endl;

	int damageRoll = (rand() % 10);

	if(damageRoll == 10){
		playerInfo::playerHealth -= 10;

		cout << endl << enemyOne.enemyName << " LASHES OUT AT ME! I BEGIN TO LOSE MY MIND!" << endl << endl;
		cout << "I HAVE " << playerInfo::playerHealth << " LIFE LEFT IN ME!" << endl;
	}else if(damageRoll > 1){
		playerInfo::playerHealth -= damageRoll;

		cout << endl << enemyOne.enemyName << " FLAYS MY MIND! IT BEGINS TO UNRAVEL!" << endl << endl;
		cout << "I HAVE " << playerInfo::playerHealth << " LIFE LEFT IN ME!" << endl;
	}else{

		cout << endl << enemyOne.enemyName << " ATTEMPTS TO RIP AT MY MIND! I RESIST ITS PRODING!" << endl;
		cout << "I HAVE " << playerInfo::playerHealth << " LIFE LEFT IN ME!" << endl;
	}
}

void endlessTerrorHorrendousVisions(){
	using std::cout;
	using std::endl;

	int damageRoll = (rand() % 10);

	if(damageRoll == 10){
		playerInfo::playerHealth -= 10;

		if(playerInfo::playerHealth <= 0){
			endlessTerrorCastIntoVoid();
		}

		cout << endl << enemyOne.enemyName << " MAKES THE WALLS TURN TO BLOOD! A WAVE COVERS MY HEAD, CHOKING OUT THE SPARK OF HOPE!" << endl << endl;
		cout << "I HAVE " << playerInfo::playerHealth << " LIFE LEFT IN ME!" << endl;
	}else if(damageRoll > 1){
		playerInfo::playerHealth -= damageRoll;

		if(playerInfo::playerHealth <= 0){
			endlessTerrorCastIntoVoid();
		}

		cout << endl << enemyOne.enemyName << " FILLS MY EYES WITH HORRIBLY DISFIGURED BEINGS! ALL LOOK ALMOST BUT NOT QUITE LIKE MY FAMILY! I AM RUSHED BY THE HOARD, UNABLE TO STRIKE AT THEM!" << endl << endl;
		cout << "I HAVE " << playerInfo::playerHealth << " LIFE LEFT IN ME!" << endl;
	}else{

		cout << endl << enemyOne.enemyName << " SURROUNDS ME WITH MISTY FIGURES! I WAVE MY ARMS THROUGH THEM, THEY DISPERSE!" << endl;
		cout << "I HAVE " << playerInfo::playerHealth << " LIFE LEFT IN ME!" << endl;
	}
}

void endlessTerrorTentacleSlap(){
	using std::cout;
	using std::endl;

	int damageRoll = (rand() % 10);

	if(damageRoll == 10){
		playerInfo::playerHealth -= 10;

		if(playerInfo::playerHealth <= 0){
			endlessTerrorCastIntoVoid();
		}

		cout << endl << enemyOne.enemyName << " STRIKES AT ME WITH A SLIMY TENDRIL! THE ICHOR THAT IS LEFT ON MY SKIN BURNS DOWN TO THE BONE!" << endl << endl;
		cout << "I HAVE " << playerInfo::playerHealth << " LIFE LEFT IN ME!" << endl;
	}else if(damageRoll > 1){
		playerInfo::playerHealth -= damageRoll - 1;

		if(playerInfo::playerHealth <= 0){
			endlessTerrorCastIntoVoid();
		}

		cout << endl << enemyOne.enemyName << " LASHES MY BODY WIHT A BLINDING STRIKE!" << endl << endl;
		cout << "I HAVE " << playerInfo::playerHealth << " LIFE LEFT IN ME!" << endl;
	}else{

		cout << endl << enemyOne.enemyName << " MAKES TO STRIKE ME, BUT I SLICE THE WRIGGLING SINEWS! THEY FALL BEFORE ME!" << endl;
		cout << "I HAVE " << playerInfo::playerHealth << " LIFE LEFT IN ME!" << endl;
	}
}

void endlessTerrorCastIntoVoid(){
	using std::cout;
	using std::endl;

	playerInfo::playerHealth = 0;
	playerInfo::playerIsInsane = true;

	cout << enemyOne.enemyName << " STRIKES AT ME WITH A TENTACLE! I BLOCK IT, BUT AS I DO SO THE CONVOLUTED MASS OPENS BEFORE ME! WHERE THERE WAS WRITHING FORMS NOW THERE IS AN INCOMPREHENSIBLE DARKNESS! MY MIND FINALY SLIPS THE BONDS OF SANITY, I CAN FEEL MY SOUL BEING TORN FROM MY BODY. I FALL FORWARD, LEAVING MY BODY BEHIND, INTO THE DEPTHS OF THE VOID. SWEET RELEASE OF INSANITY COATS ME." << endl;

	cout << endl << "PRESS ENTER TO CONTINUE";
	getchar();
}

void endlessTerrorIntroText(){
	using std::cout;
	using std::endl;

	cout << "OUT OF THE SHADOWS BEFORE ME A CLOUD OF DARKNESS LOOMS! A MASS OF WRITHING TENTACLES COALESCE INTO A FLOATING SPHERE OF INTERLACING PATERNS. AS I PEER INTO THE DEPTHS OF THE BEING THE COLD EMBRACE OF INSANITY TUGGS AT MY MIND. A THICK ICHOR DRIPS IN TENDRILS ONTO THE FLOOR BELOW IT." << endl << endl;
	cout << "SUDDENLY I HEAR AN UNBEARABLE VOICE FILL THE SPACE BETWEEN MY EARS." << endl << endl;
	cout << "Wͨ͛̃͋͂̏H̉̋ͮO͌̈́ͥ ̏̅͂̒͐ͥ͂D͋ͮAR̂ͨẺ̅̌ͪ̃̑̚S̎̿̓͒̋͆ͪ ̎̎̽̑̒E͌̑͒ͭ̽ͩ͐N̒̽̽̆͌Tͭ̓ͪ̚ER̂ ̎̾̿̅T̐̂̍̍̓͗ͦH͂̏̄E ͯ͋͊̄R̋ͥ̉Ȅͤ́A͑̈ͥͣ̊L̄͌̓̂̐ͬM̓͋͆̍̔ ̍̊̓͊ͩO̔͐ͮͯF͊ ";
	cout << "N̂͂҉̢̰̥̝̺̩͇̥̠͈A̶͈̥͕̯̙͖̋ͪͅR̼̲͚̥̹̹͕͕͌̇͒̉ͬ̾̇́Ö̘̠́͛͠͝Kͣ͒̊͋͋͋ͨ͟͏̢̦̭̤̗̻̭͚̙A̸̮͙̗͇̝̒͊ͣ̈̚Sͣ̉̓̽ͮ̎́͡͏̡̪̺̹͈̝͔̹H̢̺ͩ̋̽" << endl << endl;
	cout << "Ẏ̏̈̆̀̈ÔȔ̾̽Rͫ̑̋ͨͤ ̓Mͪ̍̏͒ͯ̓̄I͊̾͗͒ͦN̈́ͦͮ̒̽D̐ͦͧͤ ̊ͦ̽Iͨ͊ͥ͑̇ͭ̏S̔̾ͨ̄ͤͣͦ ̾͋̑W̅̏ͨ̈̔EEK! I ͐͑Wͫ͒̇͒ͤ̈I̓̋ͭ̿ͥ̊͒L̚L̅̏ͦ ͮ̈͋̆͋C͋̄̈́ͥ̄̊̚O͑̄́̎Ṅ͛ͯ̈̎ͬ̆Sͯ̄̑U̾ͥͦ͛̆̏M̃̇̏͊E ͦ̾Y͑̈́̈́ͧ͒O̾̈̔͒̓̅Uͤ̒R͋̓̊ ̌ͥ̿ͤ̋̽T̉ͩͪḦ́̅͐̍́O̾ͤ͌ͥͮUGͭ͑͐͆͗Hͬ̈́ͮ͑̃T̎̊̿̃̐Sͫ̍ ̇ͯ̄A͗̓NͯͥͤͬD̄͑͌͂̋͋̅ ͣ̿ͨ̌DͮE̔̈́̆̎͑ͪVͭ̎̈́͐ͮ̄̚Õ͋ͯ̆̓Uͮ͛ͦ̊̅R͑ͩ̅ͦ͆ ͛̈́̐ͬ̾͊ͮYȮ͑͌ͧU͐ͦ̋̈̓͛ͩRͧ͌͑ ̋͑̌̾̏S͑ͧO͑͑̋̒ͬ̄ͩŪͬ͑̃̓L̅!" << endl << endl;

	cout << "PRESS ENTER TO CONTINUE";
	getchar();
}

