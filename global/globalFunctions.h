#ifndef GLOBALFUNCTIONS_H
#define GLOBALFUNCTIONS_H

void sleepMilli(int x);
void clear();
void clearFirst();
void enterPause();
void displayPlayerInfo();
void playerInventory();
void bubbleSort(std::string *array, int size);
std::string stringSearch(std::string *array, int size);
std::string checkUserInput(std::string *array, int size);
char getch();

#endif