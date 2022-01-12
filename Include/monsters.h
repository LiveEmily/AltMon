#ifndef MONSTERS_H
#define MONSTERS_H

#include <moves.h>
//#include <abilities.h>

typedef struct {
    char name[15];
    int hp;
    int dmg;
    int def;
    int spd;
    moves moves[4];
    types type[2];
    //abilities ability;
    int index;
} monster;

#endif