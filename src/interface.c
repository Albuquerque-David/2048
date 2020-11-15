#include <ncurses.h>
#include <string.h>
#include "interface.h"
#include "game.h"

short int unicode_status;
extern unsigned int score, high_score;

void defineUnicode(char *flag) {
    unicode_status = !strcmp(flag, "--no-unicode");
}

void startInterface(void) {
    initscr(); /*Start game screen*/
    noecho(); /*Hide user input*/
    curs_set(0); /*Disable terminal cursor*/
}

void terminatesInterface(void) {
    curs_set(1); /*Enable terminal cursor*/
    clear(); /*Clean window*/
    echo(); /*Make user input visible again*/
    endwin(); /*Terinate game screen*/
}

/*Print the gae interface*/
void printInterface(short int matrix[SIZE][SIZE]) {
    short int i, j;
    refresh(); /*Restart window*/
    clear(); /*Clean screen*/
    printw("Score: %5.u\nHigh Score: %5.u\n", score, high_score > score ? high_score : score);

    if (!unicode_status) {
        static char *top =  "╔════╦════╦════╦════╗",
                    *bottom = "╚════╩════╩════╩════╝",
                    *middle = "╠════╬════╬════╬════╣";

        printw("%s\n", top);
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                printw("║%4.i", matrix[i][j]);
            }
            printw("║\n");
            if (i < SIZE - 1) printw("%s\n", middle);
        }
        printw("%s\n", bottom);
    } else {
        static char *div =  "+----+----+----+----+";

        printw("%s\n", div);
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                printw("|%4.i", matrix[i][j]);
            }
            printw("|\n");
            printw("%s\n", div);
        }
    }

    printw("Controls: WASD and arrows. 0 to exit");
}
