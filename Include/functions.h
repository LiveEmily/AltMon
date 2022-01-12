#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <monsters.h>

void clearScreen();

float checkType(monster *, moves);

moves chooseMove(monster);

void battle(monster *, monster *, moves, moves);

#endif