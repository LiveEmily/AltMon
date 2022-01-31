#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <functions.h>
#include <engine.h>

#ifdef _WIN32
#define CLEAR "CLS"
#include <conio.h>
#include <Windows.h>
#else
#define CLEAR "clear"
#include <termios.h>

static struct termios old, current;

void initTermios(int echo) {
  tcgetattr(0, &old);
  current = old;
  current.c_lflag &= ~ICANON;
  if(echo) {
      current.c_lflag |= ECHO;
  } else {
      current.c_lflag &= ~ECHO;
  }
  tcsetattr(0, TCSANOW, &current);
}

void resetTermios(void) {
  tcsetattr(0, TCSANOW, &old);
}

char getch_(int echo) {
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}

char getch(void) {
  return getch_(0);
}
#endif

float checkType(monster *mon, moves moveChosen) {
    float multiplier = 1;

    if(mon->type->weak == moveChosen.type.index) {
        multiplier = 2;
    } else if(mon->type->strong == moveChosen.type.index) {
        multiplier = 0.5;
    }

    return multiplier;
}

int checkAbility(monster *mon, moves moveChosen) {
    if(moveChosen.physical == true) {
        switch(mon->ability.effect.index) {
            case 0:
                return 1;
                break;
            case 1:
                return 2;
                break;
            case 2:
                return 3;
                break;
            default:
                return 0;
                break;
        }
    }
    return 0;
}

moves chooseMove(monster mon) {
    char move[10];
    moves moveChosen;

    printf("Please choose a move for %s | HP: %i\n", mon.name, mon.hp);

    for(int i = 0; i < 3; ++i) {
        if(mon.moves[i].exists) {
            printf("Name: %s | Damage: %i | Type: %s\n", mon.moves[i].name, mon.moves[i].dmg, mon.moves[i].type.name);
        }
    }

    scanf("%9s", move);

    for(int i = 0; i < 4; ++i) {
        if(strcmp(mon.moves[i].name, move) == 0) {
            moveChosen = mon.moves[i];
            break;
        }
    }

    system(CLEAR);

    return moveChosen;
}

void battle(monster *mon1, monster *mon2, moves moveChosen, moves moveChosen2) {
    int dmgDealt = 0;
    float multiplier = 1;
    int effect = 0;

    if(mon1->spd >= mon2->spd) {
        printf("%s uses %s!\n", mon1->name, moveChosen.name);

        multiplier = checkType(mon2, moveChosen);

        dmgDealt = (mon1->dmg * moveChosen.dmg / mon2->def) * multiplier;

        printf("%s did %i damage to %s!\n", mon1->name, dmgDealt, mon2->name);

        mon2->hp = mon2->hp - dmgDealt;

        if(mon2->hp <= 0) {
            printf("%s has fainted!\n", mon2->name);
            Beep(300, 200);
            Beep(400, 200);
            Beep(500, 100);
            Beep(600, 200);
            Beep(700, 100);
            Beep(600, 200);
            Beep(550, 300);
            Beep(500, 200);
            Beep(600, 250);
            Beep(200, 200);
            return;
        }

        printf("%s is now %i hp.\n", mon2->name, mon2->hp);

        effect = checkAbility(mon2, moveChosen);

        if(effect == 1) {
            printf("%s's %s inflicted burn to %s!\n", mon2->name, mon2->ability.name, mon1->name);
            mon1->effect = mon2->ability.effect;
        }

        clearScreen();

        printf("%s uses %s!\n", mon2->name, moveChosen2.name);

        multiplier = checkType(mon1, moveChosen2);

        dmgDealt = (mon2->dmg * moveChosen2.dmg / mon1->def) * multiplier;

        printf("%s did %i damge to %s!\n", mon2->name, dmgDealt, mon1->name);

        mon1->hp = mon1->hp - dmgDealt;

        if(mon1->hp <= 0) {
            printf("%s has fainted!\n", mon1->name);
            Beep(300, 200);
            Beep(400, 200);
            Beep(500, 100);
            Beep(600, 200);
            Beep(700, 100);
            Beep(600, 200);
            Beep(550, 300);
            Beep(500, 200);
            Beep(600, 250);
            Beep(200, 200);
            return;
        }

        printf("%s is now at %i hp.\n", mon1->name, mon1->hp);

        effect = checkAbility(mon1, moveChosen2);

        if(effect == 1) {
            printf("%s's %s inflicted burn to %s!\n", mon1->name, mon1->ability.name, mon2->name);
            mon2->effect = mon1->ability.effect;
        }

        clearScreen();

        if(mon1->effect.index == 0) {
            printf("%s got hurt by it's burn!\n", mon1->name);
            mon1->hp = mon1->hp - 5;
            printf("%s is now at %i hp.\n", mon1->name, mon1->hp);
        }

        if(mon1->hp <= 0) {
            printf("%s has fainted!\n", mon1->name);
            Beep(300, 200);
            Beep(400, 200);
            Beep(500, 100);
            Beep(600, 200);
            Beep(700, 100);
            Beep(600, 200);
            Beep(550, 300);
            Beep(500, 200);
            Beep(600, 250);
            Beep(200, 200);
            return;
        }

        if(mon2->effect.index == 0) {
            printf("%s got hurt by it's burn!\n", mon2->name);
            mon2->hp = mon2->hp - 5;
            printf("%s is now at %i hp.\n", mon2->name, mon2->hp);
        }

        if(mon2->hp <= 0) {
            printf("%s has fainted!\n", mon2->name);
            Beep(300, 200);
            Beep(400, 200);
            Beep(500, 100);
            Beep(600, 200);
            Beep(700, 100);
            Beep(600, 200);
            Beep(550, 300);
            Beep(500, 200);
            Beep(600, 250);
            Beep(200, 200);
            return;
        }

        clearScreen();
    } else {
        printf("%s uses %s!\n", mon2->name, moveChosen2.name);

        multiplier = checkType(mon1, moveChosen2);

        dmgDealt = (mon2->dmg * moveChosen2.dmg / mon1->def) * multiplier;

        printf("%s did %i damage to %s!\n", mon2->name, dmgDealt, mon1->name);

        mon1->hp = mon1->hp - dmgDealt;

        if(mon1->hp <= 0) {
            printf("%s has fainted!", mon1->name);
            return;
        }

        printf("%s is now %i hp.\n", mon1->name, mon1->hp);

        clearScreen();

        printf("%s uses %s!\n", mon1->name, moveChosen.name);

        multiplier = checkType(mon2, moveChosen);

        dmgDealt = (mon1->dmg * moveChosen.dmg / mon2->def) * multiplier;

        printf("%s did %i damge to %s!\n", mon1->name, dmgDealt, mon2->name);

        mon2->hp = mon2->hp - dmgDealt;

        if(mon2->hp <= 0) {
            printf("%s has fainted!", mon2->name);
            return;
        }

        printf("%s is now at %i hp.\n", mon2->name, mon2->hp);

        clearScreen();
    }
    return;
}