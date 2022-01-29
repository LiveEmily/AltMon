#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <monsters.h>

void clearScreen();

void intro();

float checkType(monster *, moves);

moves chooseMove(monster);

void battle(monster *, monster *, moves, moves);

#endif