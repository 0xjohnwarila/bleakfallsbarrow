//skeleRoom is a room that will have a skeleton fight that leads to getting the chest key

//TODO:
//integrate combat module
//write verb/nouns
//connect rooms with playerLoc

#include <iostream>
#include <string>
#include <sstream>
#include <time.h>
#include <stdlib.h>
#include <limits>
#include <chrono>
#include <thread>
#include "inputSplit.cpp"
using namespace std;

void clearScreenFirst();
void clearScreen();
void clear();
void endCommand();
void fail();
void sleepMilli(int x);

//startRoom is the main function that controls the room
//it is called by the main function and runs until the location of the player is updated
//the first line of if else statements checks for different verbs
//within each verb check are another set of noun checks
//if a verb and noun match (i.e. LOOK NORTH) then it will display text and change any neccesary int/bools
//
//ROOM COMMANDS:
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//HELP:
//HELP is a verb only function that gives some hints to the player about inputs and how to play
//
//QUIT:
//QUIT is another verb only function.  It sets the player location to 0,
//which exits startRoom.cpp.  Main intereperits location 0 as returning 0 and ending the program.
//
//MOVE (NORTH, SOUTH, EAST, WEST):
//
//TAKE:
//
//USE:
//
//LOOK (NORTH, WEST, EAST, SOUTH):
//LOOK allows the player to inspect items in a room for usefull/flavorfull information
//
//OPEN:
//OPEN has the same functionality as USE but it only works on things that can be opened,
//it's a seperate function because you cant open KEYs and OPEN is too common a term
//to leave it out of the game.  Welcome.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//ROOM ITEMS:
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void greenRoom () {
        userInput::playerLoc = 2;
        clearScreenFirst();
        while (userInput::playerLoc==2) {
                playerInput ();
                if (userInput::verb=="HELP") {
                        clearScreen();
                        cout << "THE GOAL OF THIS GAME IS TO EXIT THE DUNGEON.  YOU CAN MOVE USING THE CARDINAL DIRECTIONS, AND INTERACT WITH ITEMS BY USING THEM OR TAKING THEM.  LOOK IN A DIRECTION, OR INSPECT VISIBLE ITEMS TO LEARN MORE ABOUT YOUR ENVIRONMENT.  EXCLUDING EXITING THE GAME, ALL COMMANDS MUST BE IN VERB-NOUN FORMAT EX:'WALK NORTH', 'SEARCH BAG', OR 'GRAB AXE'.";
                        endCommand();
                }
                else if (userInput::verb=="QUIT") {
                        userInput::playerLoc=0;
                }
                else if (userInput::verb=="MOVE") {
                        if () {

                        }
                        else {
                                fail();
                        }
                }
                else if (userInput::verb=="TAKE") {
                        if () {
                                
                        }
                        else {
                                fail();
                        }
                }
                else if (userInput::verb=="USE") {
                        if () {
                                
                        }
                        else {
                                fail();
                        }
                } (userInput::verb=="LOOK") {
                        if () {
                                
                        }
                        else {
                                fail();
                        }
                }
                else if (userInput::verb=="OPEN") {
                        if () {
                                
                        }
                        else {
                                fail();
                        }
                }
                else {
                        fail();
                }
        }
}

void clear () {
        cout << "\033[2J\033[1;1H";
}

void clearScreenFirst() {
        clear();
        cout << "I AM IN A WALLED FOREST.  I HEAR BIRDS.";
        cout << "THE MOSSY BRICKS FEEL REFRESHING ON MY BARE FEET.";
        sleepMilli(1500);
        cout << "VISIBLE ITEMS:\n";
        sleepMilli(500);
        cout <<"TO MY EAST I CAN SEE A PILE OF BONES AND SCRAPS OF CLOTH\n";
        cout << endl;
        sleepMilli(1500);
        cout <<"TO MY NORTH I CAN SEE AN OPEN DOOR LEADING BACK TO THE STONE ROOM\n";
        cout << endl;
        sleepMilli(1500);
        cout <<"TO MY SOUTH THERE IS A WALL OF THICK VINES\n";
        cout << endl;
        sleepMilli(1500);
        cout <<"\n(TYPE 'HELP' FOR HELP)\n";
        sleepMilli(500);
        cout <<"(TYPE 'QUIT' TO QUIT)\n";
        sleepMilli(500);
        cout <<"TELL ME WHAT TO DO? ";
}

void clearScreen () {
        clear();
        cout << "(same as clearScreenFirst)"
        cout << userInput::inputString;
        cout << endl <<"OK," << endl;
}

void endCommand () {
        sleepMilli(500);
        cout << endl;
        cout << "\nTELL ME WHAT TO DO? ";
}

void fail () {
        clearScreen();
        cout << "I CAN'T DO THAT.\n\nMAKE SURE TO FORMAT YOUR COMMANDS IN TWO WORDS.\nTRY LOOKING IN A DIRECTION WITH LOOK.\n\n(TYPE 'HELP' FOR HELP)";
        endCommand ();
}

void sleepMilli(int x){
        this_thread::sleep_for(chrono::milliseconds(x));
}
