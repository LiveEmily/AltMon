#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <functions.h>

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

void clearScreen() {
    printf("Press any key to continue...");
    getch();
    system(CLEAR);
}

void intro() {
    system(CLEAR);
    printf("Welcome, to the world of AltMon!");
    for(int i = 0; i < 5; ++i) {
        Beep(i*100, 150);
    }

    for(int i = 0; i < 5; ++i) {
        Beep(i*200, 150);
    }

    for(int i = 0; i < 5; ++i) {
        Beep(i*100, 150);
    }

    for(int i = 0; i < 5; ++i) {
        Beep(i*200, 150);
    }

    for(int i = 0; i < 5; ++i) {
        Beep(i*100, 150);
    }

    for(int i = 0; i < 5; ++i) {
        Beep(i*150, 150);
    }

    for(int i = 0; i < 5; ++i) {
        Beep(i*150, 150);
    }

    for(int i = 0; i < 3; ++i) {
        Beep(i*350, 150);
    }

    for(int i = 0; i < 2; ++i) {
        Beep(i*450, 150);
    }

    Beep(800, 200);
    system(CLEAR);
}