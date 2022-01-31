#ifndef ENGINE_H
#define ENGINE_H

#include <monsters.h>

float checkType(monster *, moves);

moves chooseMove(monster);

void battle(monster *, monster *, moves, moves);

#endif