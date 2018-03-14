#include <iostream>
#include "../dialogueModule/dialogueModule.h"
#include "../combatModule/globalFunctions.h"
#include "../global/globalFunk.h"

// Forward Declarations
void fillClassData(int dialogueDifficulty, std::string headingFlavorText, std::string inputName, std::string encounterName);
void printHeadingFlavor();
void reprintScreen();
void npcResponse();
void playerResponse();
void errorMessageEndOfControl();
void endDialogueText(int result);

int dialogueController();



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

	dialogueStatus();
}currentDialogue;

dialogueStatus::dialogueStatus(void){
	dialogueComplete     = false;
	playerHasLied        = false;
	persuasionSuccess    = false;

	dialogueDifficulty   = 1;
	dialogueLocation     = 0;

	previousResponse     = "NULL";
	headingFlavorText    = "NULL";
}



class encounterData{
public:
	std::string encounterName;
	std::string npcName;
	std::string npcOpen;
	std::string npcRe1;
	std::string npcRe2;
	std::string npcEnd;

	std::string playerOption1;
	std::string playerOption2;
	std::string playerOptionType1;
	std::string playerOptionType2;

	std::string endTextOption1;
	std::string endTextOption2;

	encounterData();
}currentEncounter;

encounterData::encounterData(void){
	encounterName = "NULL";
	npcName = "NULL";

	npcOpen = "NULL";
	npcRe1  = "NULL";
	npcRe2  = "NULL";
	npcEnd  = "NULL";

	playerOption1 = "NULL";
	playerOption2 = "NULL";
	playerOptionType1 = "NULL";
	playerOptionType2 = "NULL";

	endTextOption1 = "NULL";
	endTextOption2 = "NULL";
}

struct demoDialogue{
public:
	std::string npcOpen            = "DIALOGUE FROM NPC TO OPEN CONVERSATION. ----PLACEHOLDER----";
	std::string npcCalmDownRe      = "DIALOGUE FROM NPC RESPONSE CALM DOWN    ----PLACEHOLDER----";
	std::string npcSnarkyRe        = "DIALOGUE FROM NPC RESPONSE SNARKY       ----PLACEHOLDER----";
	std::string npcEnd             = "DIALOGUE FROM NPC END CONVERSATION      ----PLACEHOLDER----";

	std::string playerCalmDown     = "DIALOGUE FROM PLAYER CALM DOWN          ----PLACEHOLDER----";
	std::string playerSnarky       = "DIALOGUE FROM PLAYER SNARKY             ----PLACEHOLDER----";
	std::string playerOptionType1  = "CALM DOWN";
	std::string playerOptionType2  = "SNARKY";

	std::string endTextOption1     = "NPC ATTACKS YOU                         ----PLACEHOLDER----";
	std::string endTextOption2     = "NPC DOES NOT ATTACK YOU                 ----PLACEHOLDER----";
}demoOne;

int dialogueDemo(int dialogueDifficulty, std::string headingFlavorText, std::string inputName, std::string encounterName){
	fillClassData(dialogueDifficulty, headingFlavorText, inputName, encounterName);
	
	int dialogueResult = dialogueController();

	if(dialogueResult == 0){
		errorMessageEndOfControl();
		return 0;
	}else{
		endDialogueText(dialogueResult);
		return dialogueResult;
	}
	return 0;	
}

void fillClassData(int dialogueDifficulty, std::string headingFlavorText, std::string inputName, std::string encounterName){

	if(headingFlavorText == "default"){
		currentDialogue.headingFlavorText = "I AM TALKING TO " + currentEncounter.npcName;
	}

	if(encounterName == "DEMO"){
		currentEncounter.encounterName = encounterName;

		currentEncounter.npcOpen = demoOne.npcOpen;
		currentEncounter.npcRe1  = demoOne.npcCalmDownRe;
		currentEncounter.npcRe2  = demoOne.npcSnarkyRe;
		currentEncounter.npcEnd  = demoOne.npcEnd;

		currentEncounter.playerOption1  = demoOne.playerCalmDown;
		currentEncounter.playerOption2  = demoOne.playerSnarky;
		currentEncounter.endTextOption1 = demoOne.endTextOption1;
		currentEncounter.endTextOption2 = demoOne.endTextOption2;
	}
}

void printHeadingFlavor()
{	using std::cout;
	using std::endl;

	cout << currentDialogue.headingFlavorText << endl;
}

void reprintScreen(){
	using std::cout;
	using std::endl;

	clear();
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
	}else if(currentDialogue.dialogueLocation == 2){
		currentDialogue.previousResponse = currentEncounter.npcRe1;

		cout << endl << currentEncounter.npcRe1;

		currentDialogue.dialogueLocation = 4;
	}else if(currentDialogue.dialogueLocation == 3){
		currentDialogue.previousResponse = currentEncounter.npcRe2;

		cout << endl << currentEncounter.npcRe2;

		currentDialogue.dialogueLocation = 4;
	}else if(currentDialogue.dialogueLocation == 4){
		currentDialogue.previousResponse = currentEncounter.npcEnd;

		cout << endl << currentEncounter.npcEnd;

		currentDialogue.dialogueLocation = 5;
	}
}

void playerResponse(){
	using std::cout;
	using std::endl;
	using std::cin;

	cout << endl << "WHAT DO I SAY?";
	cout << endl << "1. " << currentEncounter.playerOptionType1 << endl;
	cout << endl << "2. " << currentEncounter.playerOptionType2 << endl;

	std::string options[] = {"1", "2"};

	std::string response = checkUserInput(options, 2);

	if(response == "1"){
		reprintScreen();

		cout << endl << currentDialogue.previousResponse;
		cout << endl << currentEncounter.playerOption1;

		currentDialogue.dialogueLocation = 2;

	}else if(response == "2"){
		reprintScreen();

		cout << endl << currentDialogue.previousResponse;
		cout << endl << currentEncounter.playerOption2;

		currentDialogue.dialogueLocation = 3;
	}
}

int dialogueController(){
	while(true){
		if(currentDialogue.dialogueLocation == 0){
			npcResponse();
		}else if(currentDialogue.dialogueLocation == 1){
			playerResponse();
		}else if(currentDialogue.dialogueLocation == 2 
				| currentDialogue.dialogueLocation == 3 
				| currentDialogue.dialogueLocation == 4){
			npcResponse();
		}else if(currentDialogue.dialogueLocation == 5){
			return 1;
		}else{
			return 0;
		}
	}
	return 0;
}

void errorMessageEndOfControl(){
	using std::cout;
	using std::endl;

	cout << "ERROR, REACHED END OF CONTROL WITH NO GOOD OUTCOMES" << endl;
}

void endDialogueText(int result){
	using std::cout;
	using std::endl;
	using std::cin;

	clear();

	if(result == 1){
		cout << currentEncounter.endTextOption1 << endl;
		cout << endl << "PRESS ENTER TO CONTINUE!" << endl;

		enterPause();
	}else if(result == 2){
		cout << currentEncounter.endTextOption2 << endl;
		cout << endl << "PRESS ENTER TO CONTINUE!" << endl;

		enterPause();
	}
}