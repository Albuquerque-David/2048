#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "game.h"
#include "interface.h"

#define WIN 1
#define LOSS 0

unsigned int high_score, score = 0;

/*Write a new high_score*/
void newHighScore(void) {
    FILE *score_data = fopen("high_score.bin", "wb");
    high_score = score;
    fwrite(&score, sizeof(int), 1, score_data);
    fclose(score_data);
}

/*Read the high score or create the high_score file*/
void getHighScore(void) {
    FILE *score_data = fopen("high_score.bin", "rb");
    if (!score_data) {
        newHighScore();
    } else {
        fread(&high_score, sizeof(int), 1, score_data);
        fclose(score_data);
    }
}

/*Return true or fale if the game can continue, start the restart process if the player
win or loss*/
short int continues(short int matrix[SIZE][SIZE]) {
    short int i, j;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (matrix[i][j] == 2048) {
                return restart(matrix, WIN);
            }
        }
    }

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (matrix[i][j] == 0) 
                return 1;
            if (i > 0 && i < SIZE - 1) {
                if (matrix[i][j] == matrix[i + 1][j] || matrix[i][j] == matrix[i - 1][j])
                    return 1;
            }

            if (j > 0 && j < SIZE - 1) {
                if (matrix[i][j] == matrix[i][j + 1] || matrix[i][j] == matrix[i][j - 1])
                    return 1;
            }
        }
    }

    return restart(matrix, LOSS);
}

/*Search for empty spaces in the grid and add a new value to one of them*/
void addNewValue(short int matrix[SIZE][SIZE]) {
    short int i, j, counter = 0,
    **empties = (short int **) malloc(sizeof(short int *) * SIZE * SIZE);

    for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			if (matrix[i][j] == 0) {
				*(empties + counter) = &matrix[i][j];
				counter++;
			}
		}
	}

    if (counter > 0) {
        int i = rand() % counter;
        *empties[i] = (rand() % 10) ? 2 : 4;
    }

    free(empties);
}

/*End game process. Disable interface, define high_score and disable keypad tracking*/
void exitGame(void) {
    if (score > high_score) newHighScore();
    terminatesInterface();
    keypad(stdscr, 0);
}

/*Start game proces. Enable interface, read high_score and enable keypad tracking*/
void newGame(short int matrix[SIZE][SIZE]) {
    short int i, j;
    score = 0;
    startInterface();
    printInterface(matrix);
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            matrix[i][j] = 0;
        }
    }

    keypad(stdscr, 1); /*Enable keypad tracking*/
    getHighScore();
    addNewValue(matrix);
    addNewValue(matrix);
    printInterface(matrix);
}

/*Ask to the player if the game has to restart or not*/
short int restart(short int matrix[SIZE][SIZE], int status) {
    printInterface(matrix);
    move(11, 0); /*Move the pinter to the row where are the control instructions*/
    clrtoeol(); /*Erase control line*/

    if (status == WIN) printw("You win!\n");
    else printw("You lose!\n");
    printw("Press r to play again ou q to quit\n");

    while (1) {
        char input = getch();

        switch (input) {
            case 'r':
                exitGame();
                newGame(matrix);
                return 1;

            case 'q':
                return 0;

            default:
                break;
        }
    }
}
