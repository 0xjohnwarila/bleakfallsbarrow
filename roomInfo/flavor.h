#ifndef FLAVOR_H
#define FLAVOR_H

void startRoomFlavor();
void greenRoomFlavor();
void throneRoomFlavor();
void CSFirst(std::string room, int time);
void clearScreen(std::string room);
void CSLast(std::string room);
void endCommand();
void fail(std::string room);
void battleOver(std::string enemy, std::string room);
void restoreHealth();

#endif