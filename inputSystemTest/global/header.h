//the header file keeps track of global values to keep track of player information
//TODO:
//make sure all player values are kept in the header so that rooms don't interrupt information

#ifndef HEADER_H
#define HEADER_H

class userInput {
public:
	//TEXT INPUT VALUES:
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//verb: The most recent string for the first word the player inputs
	//noun: The word after noun that the player inputs
	//inputString: The complete string that the player inputs before it's split into verb and noun
	//english: keeps track of if the player inputs were recognized or not (maybe not neccesary)
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	static std::string verb, noun, inputString, commandFlavor;
	static int english;

	//PLAYER VALUES:
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//playerName: The string that keeps track of the name that the player submits when asked
	//playerAge: int that keeps track of the player's age and their senior citizen discount
	//classNum: a number value that decides what class the player is
	//playerLoc: a number that tracks what room the player is in
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	static std::string playerLoc;

	//ROOM CHECK BOOLS:
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//These booleans check to see if the player has entered a room for the first time
	//if it's their first time in a room, then the 
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	static bool startRoomCheck, greenRoomCheck, throneRoomCheck, seeInDark;

	//START ROOM VALUES:
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//These booleans check to see if the player has entered a room for the first time
	//if it's their first time in a room, then the 
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	static bool stone, key, startFight;
	static int doorKick;

	//GREEN ROOM VALUES
	static bool skeletonDead, skeleSword, greenRag, vineDead;

	//THRONE ROOM VALUES
	static int puzzleLoc;
	static bool puzzleDone;
};

class playerInfo{
public:
	static std::string playerName;
	static std::string playerWeapon;
	static std::string playerSupportItem;
	static int playerAge;
	static int classNum;
	static int playerHealth;
	static int playerLevel;
	static int battleStatus;
	static bool playerArthritis;
	static bool playerCrit;
	static bool playerSkipTurn;
	static bool playerTurn;
};

#endif