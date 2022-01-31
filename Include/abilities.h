#ifndef ABILITIES_H
#define ABILITIES_H

#include <effects.h>
#include <stdbool.h>

typedef struct {
    char name[10];
    bool hidden;
    effects effect;
    bool powerUp;
} abilities;

#endif