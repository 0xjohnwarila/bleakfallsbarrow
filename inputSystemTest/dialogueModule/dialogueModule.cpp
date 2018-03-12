#include <iostream>
#include "../dialogueModule/dialogueModule.h"
#include "../combatModule/globalFunctions.h"

// Forward Declarations
void fillClassData(int dialogueDifficulty, std::string headingFlavorText, std::string inputName);
void printHeadingFlavor();
void reprintScreen();

class dialogueStatus{
public:
	bool        dialogueComplete;      // Is the dialogue complete
	bool        playerHasLied;         // Has the player lied to the current NPC
	bool        persuasionSuccess;     // Has the player succeeded in persuading the NPC

	int         dialogueDifficulty;    // How difficult is persuasion. Set by the caller of dialogue.
	int         dialogueLocation;

	std::string previousResponse;	   // Store the NPC's previous response for reprinting screen
	std::string headingFlavorText;     // Flavor text to stay at the top of the screen, this should 
									   // be set by the caller. If there is nothing a default text
	                                   // will be displayed.

	construct(){
		dialogueComplete     = false;
		playerHasLied        = false;
		persuasionSuccess    = false;

		dialogueDifficulty   = 1;
		dialogueLocation     = 0;

		previousResponse     = NULL;
		headingFlavorText    = NULL;
	}
}

class nonPlayerCharacter{
public:
	std::string nameOfNPC;

	construct(std::string inputName){
		nameOfNPC = inputName;
	}
}

class enounterData{
public:
	std::string EncounterName;
	std::string npcOpen = NULL;
	std::string npcRe1  = NULL;
	std::string npcRe2  = NULL;
	std::string npcEnd  = NULL;

	std::string playerOption1 = NULL;
	std::string playerOption2 = NULL;
	std::string playerOptionType1 = NULL;
	std::string playerOptionType2 = NULL;

	construct(std::string encounterName){
		currentEncounterName = encounterName;
	}
}

struct demoDialogue{
	static std::string npcOpen            = "DIALOGUE FROM NPC TO OPEN CONVERSATION. ----PLACEHOLDER----";
	static std::string npcCalmDownRe      = "DIALOGUE FROM NPC RESPONSE CALM DOWN    ----PLACEHOLDER----";
	static std::string npcSnarkyRe        = "DIALOGUE FROM NPC RESPONSE SNARKY       ----PLACEHOLDER----";
	static std::string npcEnd             = "DIALOGUE FROM NPC END CONVERSATION      ----PLACEHOLDER----";

	static std::string playerCalmDown     = "DIALOGUE FROM PLAYER CALM DOWN          ----PLACEHOLDER----";
	static std::string playerSnarky       = "DIALOGUE FROM PLAYER SNARKY             ----PLACEHOLDER----";
	static std::string playerOptionType1  = "CALM DONW";
	static std::string playerOptionType2  = "SNARKY";
}

int dialogueDemo(int dialogueDifficulty, std::string headingFlavorText, std::string inputName, std::string encounterName){
	fillClassData(int dialogueDifficulty, std::string headingFlavorText, std::string inputName, std::string encounterName);
	

	return 0;	
}

void fillClassData(int dialogueDifficulty, std::string headingFlavorText, std::string inputName, std::string encounterName){
	nonPlayerCharacter npcCurrent(inputName);
	dialogueStatus     currentDialogue;
	encounterData      currentEncounter(encounterName);	

	if(headingFlavorText == "default"){
		currentDialogue.headingFlavorText = "I AM TALKING TO " << npcCurrent.nameOfNPC;
	}

	if(encounterName == "DEMO"){
		currentEncounter.npcOpen = demoDialogue.npcOpen;
		currentEncounter.npcRe1  = demoDialogue.npcCalmDownRe;
		currentEncounter.npcRe2  = demoDialogue.npcSnarkyRe;
		currentEncounter.npcEnd  = demoDialogue.npcEnd;

		currentEncounter.playerOption1 = demoDialogue.playerCalmDown;
		currentEncounter.playerOption2 = demoDialogue.playerSnarky;
		currentEncounter.playerOption
	}
}

void printHeadingFlavor(){
	using std::cout;
	using std::endl;

	cout << currentDialogue.headingFlavorText << endl;
}

void reprintScreen(){
	using std::cout;
	using std::endl;

	clearScreen();
	printHeadingFlavor();

	cout << endl << currentDialogue.previousResponse << endl;
}

void npcResponse(){
	using std::cout;
	using std::endl;

	if(currentDialogue.dialogueLocation == 0){
		currentDialogue.previousResponse = currentEncounter.npcOpen;

		cout << endl << currentEncounter.npcOpen;

		currentDialogue.dialogueLocation = 1;
	}else if(currentDialogue == 3){
		currentDialogue.previousResponse = currentEncounter.npcRe1;

		cout << endl << currentEncounter.npcRe1;

		currentDialogue.dialogueLocation = 5;
	}else if(currentDialogue == 4){
		currentDialogue.previousResponse = currentEncounter.npcRe2;

		cout << endl << currentEncounter.npcRe2;

		currentDialogue.dialogueLocation = 5;
	}else if(currentDialogue == 5){
		currentDialogue.previousResponse = currentEncounter.npcEnd;

		cout << endl << currentEncounter.npcEnd;

		currentDialogue.dialogueLocation = 6
	}
}

int playerResponse(){
	using std::cout;
	using std::endl;
	using std::cin;

	cout << endl << "WHAT DO I SAY?";
	cout << endl << "1. " << currentEncounter.playerOptionType1 << endl;
	cout << endl << "2. " << currentEncounter.playerOptionType2 << endl;

	std::string options[] = {"1", "2"}

	std::string response = checkPlayerInput(options, 2);

	if(response == "1"){
		reprintScreen();

		cout << endl << currentDialogue.previousResponse;
		cout << endl << currentEncounter.playerOption1;

		return 1;
	}else if(response == "2"){
		reprintScreen();

		cout << endl << currentDialogue.previousResponse;
		cout << endl << currentEncounter.playerOption2

		return 2;
	}
}