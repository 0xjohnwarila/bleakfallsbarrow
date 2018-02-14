//the header file keeps track of global values to keep track of player information
//TODO:
//make sure all player values are kept in the header so that rooms don't interrupt information

using namespace std;

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
	static string verb, noun, inputString;
	static int english;
	
	//PLAYER VALUES:
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//playerName: The string that keeps track of the name that the player submits when asked
	//playerAge: int that keeps track of the player's age and their senior citizen discount
	//classNum: a number value that decides what class the player is
	//playerLoc: a number that tracks what room the player is in
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	static string playerName;
	static int playerAge, classNum, playerLoc;

	//ROOM CHECK BOOLS:
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//These booleans check to see if the player has entered a room for the first time
	//if it's their first time in a room, then the 
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	static bool startRoomCheck, greenRoomCheck;

	//START ROOM VALUES:
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//These booleans check to see if the player has entered a room for the first time
	//if it's their first time in a room, then the 
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	static bool stone, key, seeInDark;
	static int doorKick;
};

#endif