/*
This module is for dialogue between the player and an NPC. You start the module by inlcuding
dialogueModule.h and calling the function dialogue with the data for the dialgogue you want.
EXAMPLE:

dialogue(1, "YOU ARE TALKING TO CLUCKY", "CLUCKY", "TALKING WITH CHICKEN");

This sets the difficulty of the dialogue to 1, the heading text to "YOU ARE TALKING TO CLUCKY", the
name of the NPC to "CLUCKY", and the encounter name (This is used to load the correct dialogue data)
to "TALKING WITH CHICKEN". The function will return an int that corresponds to the outcome of the dialogue.
*/
#include <iostream>
#include "../dialogueModule/dialogueModule.h"
#include "../combatModule/globalFunctions.h"
#include "../global/globalFunk.h"
#include "../global/header.h"

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
	std::string encounterName;         // Name of the encounter, this provides the controller with what tree should be loaded
	std::string npcName;               // Name of the NPC
	std::string npcOpen;               // Text that the NPC says at the begining, these options are loaded from the struct of the current encounter by the loader
	std::string npcRe1;                // NPC response to player choice 1
	std::string npcRe2;                // NPC response to player choice 2
	std::string npcEnd;                // NPC ends conversation text

	std::string playerOption1;         // Player option 1, this is the full text that player says
	std::string playerOption2;         // Player option 2
	std::string playerOptionType1;     // Player option type 2, this is what the player chooses. Example: Snarky.
	std::string playerOptionType2;     // Player option type 1

	std::string endTextOption1;        // End text for the first outcome
	std::string endTextOption2;        // End text for the second outcome

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
	std::string npcOpen            = "I AM LOREN! A RACIST STORMCLOAK! I HATE EVERYONE BUT NORDS!";
	std::string npcCalmDownRe      = "I AM THE CALMEST MAN ALIVE, LOOK AS I HEADBUTT THIS POST!";
	std::string npcSnarkyRe        = "YOU ARE STUPID ELF! MY MOTHER IS NORD!";
	std::string npcEnd             = "I WILL SNAP YOUR NECK!";

	std::string playerCalmDown     = "CALM DOWN! YOU ARE GETTING STUPID!";
	std::string playerSnarky       = "FROM YOUR FACE IT LOOKS LIKE YOU ARE HALF ORC!";
	std::string playerOptionType1  = "CALM DOWN";
	std::string playerOptionType2  = "SNARKY";

	std::string endTextOption1     = "LOREN CHARGES ME WEILDING A SPIKE CUDGEL!";
	std::string endTextOption2     = "NPC DOES NOT ATTACK YOU                 ----PLACEHOLDER----";
}demoOne;

int dialogue(int dialogueDifficulty, std::string headingFlavorText, std::string inputName, std::string encounterName){
	clear();

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
	}else{
		currentDialogue.headingFlavorText = headingFlavorText;
	}

	if(encounterName == "DEMO"){
		currentEncounter.encounterName = encounterName;

		currentEncounter.npcOpen = demoOne.npcOpen;
		currentEncounter.npcRe1  = demoOne.npcCalmDownRe;
		currentEncounter.npcRe2  = demoOne.npcSnarkyRe;
		currentEncounter.npcEnd  = demoOne.npcEnd;
		currentEncounter.npcName = inputName;

		currentEncounter.playerOption1  = demoOne.playerCalmDown;
		currentEncounter.playerOption2  = demoOne.playerSnarky;
		currentEncounter.playerOptionType1 = demoOne.playerOptionType1;
		currentEncounter.playerOptionType2 = demoOne.playerOptionType2;
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
		cout << endl << currentDialogue.headingFlavorText << endl;
		currentDialogue.previousResponse = currentEncounter.npcOpen;

		cout << endl << currentEncounter.npcName << ": " << currentEncounter.npcOpen << endl;

		currentDialogue.dialogueLocation = 1;
	}else if(currentDialogue.dialogueLocation == 2){
		currentDialogue.previousResponse = currentEncounter.npcRe1;

		cout << endl << currentEncounter.npcName << ": "<< currentEncounter.npcRe1 << endl;

		currentDialogue.dialogueLocation = 4;

		enterPause();
	}else if(currentDialogue.dialogueLocation == 3){
		currentDialogue.previousResponse = currentEncounter.npcRe2;

		cout << endl << currentEncounter.npcName << ": " << currentEncounter.npcRe2 << endl;

		currentDialogue.dialogueLocation = 4;

		enterPause();
	}else if(currentDialogue.dialogueLocation == 4){
		currentDialogue.previousResponse = currentEncounter.npcEnd;

		cout << endl << currentEncounter.npcName << ": " << currentEncounter.npcEnd << endl;

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
		cout << endl << playerInfo::playerName << ": " << currentEncounter.playerOption1;

		currentDialogue.dialogueLocation = 2;

	}else if(response == "2"){
		reprintScreen();
		cout << endl << playerInfo::playerName << ": " << currentEncounter.playerOption2;

		currentDialogue.dialogueLocation = 3;
	}
}

int dialogueController(){
	while(true){
		if(currentDialogue.dialogueLocation == 0){
			npcResponse();
		}else if(currentDialogue.dialogueLocation == 1){
			playerResponse();
		}else if((currentDialogue.dialogueLocation == 2) 
				| (currentDialogue.dialogueLocation == 3) 
				| (currentDialogue.dialogueLocation == 4)){
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

		enterPause();
	}else if(result == 2){
		cout << currentEncounter.endTextOption2 << endl;
		enterPause();
	}
}