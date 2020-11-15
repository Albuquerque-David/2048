/*
* 2048
* Authors: Eduardo, Jorge e João Matheus;
* Tested at GNU/Linux 5.9.1-arch1-1 e 4.19.101-2-lts;
* This software is licensed under MIT license.
*/

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <locale.h>
#include <time.h>
#include "controls.h"
#include "interface.h"
#include "game.h"
#include "handle.h"

int main(int argc, char *argv[]) {
    static short int matrix[SIZE][SIZE];
    short int control, moves;

    srand(time(NULL)); /*Create a rand() seed*/
    setlocale(LC_ALL, ""); /*Add full UTF-8 support*/

    /*Disable control + Z and Control + C behaviour and handle it to the killHandle() function*/
    signal(SIGINT, killHandle);
    signal(SIGTSTP, killHandle);

    if (argc > 1) defineUnicode(argv[1]); /*Verify if --no-unicode flag is enabled*/

    newGame(matrix);
    terminalSizeHandle();

    /*While the game continues, get player inputs*/
    while (continues(matrix)) {
        control = getch();
        moves = 0;

        switch (control) {
            case 'w': case KEY_UP:
                moves = moveUp(matrix);
            break;

            case 'a': case KEY_LEFT:
                moves = moveLeft(matrix);
            break;

            case 's': case KEY_DOWN:
                moves = moveDown(matrix);
            break;

            case 'd': case KEY_RIGHT:
                moves = moveRight(matrix);
            break;

            case '0':
                exitGame();
                return 0;

            default:
                break;
        }

        if (moves) {
            addNewValue(matrix);
            printInterface(matrix);
        }
    }

    /*End the game. Generally, the game just came here if the player lose r win and press q to exit*/
    exitGame();
    return 0;
}
