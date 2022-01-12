#ifndef MOVES_H
#define MOVES_H

#include <stdbool.h>
#include <types.h>

typedef struct {
    char name[10];
    int dmg;
    bool exists;
    int index;
    types type;
} moves;

#endif