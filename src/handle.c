#include <ncurses.h>
#include <signal.h>
#include <stdlib.h>
#include "game.h"
#include "handle.h"

#define MIN_X_SIZE 15
#define MIN_Y_SIZE 22

/*Handle the signals SIGKILL e SIGINT*/
void killHandle(void) {
    exitGame();
    exit(0);
}

/*Verify terminal size, if it's to small, end the game*/
void terminalSizeHandle(void) {
    short int x, y;
    getmaxyx(stdscr, x, y);
    if (x < MIN_X_SIZE || y < MIN_Y_SIZE) {
        exitGame();
        system("clear");
        system("echo \"Resize your terminal and try again!\"");
        exit(1);
    }
}
