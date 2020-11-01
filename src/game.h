#ifndef GAME_H
#define GAME_H

#define SIZE 4

short int restart(short int matrix[SIZE][SIZE], int win);
void newGame(short int matrix[SIZE][SIZE]);
void exitGame(void);
void newHighScore(void);
void getHighScore(void);
void addNewValue(short int matrix[SIZE][SIZE]);
short int continues(short int matrix[SIZE][SIZE]);

#endif
