#include "controls.h"

extern unsigned int score;

/*Move the pieces upwards if the controls w or KEY_UP be presed
and returns > 0 to if moves has happened or 0 if not*/
short int moveUp(short int matrix[SIZE][SIZE]) {
    short int i, j, k, moves = 0;
	/*First move upwards*/
    for (k = 0; k < SIZE - 1; k++) {
        for (i = 1; i < SIZE; i++) {
			for (j = 0; j < SIZE; j++) {
				if (matrix[i][j] != 0 && matrix[i - 1][j] == 0) {
					matrix[i - 1][j] = matrix[i][j];
					matrix[i][j] = 0;
					moves++;
				}
			}
        }
    }

    /*Join near and equal values*/
    for (i = 0; i < SIZE - 1; i++) {
		for (j = 0; j < SIZE; j++) {
			if (matrix[i][j] != 0 && matrix[i][j] == matrix[i + 1][j]) {
				matrix[i][j] += matrix[i + 1][j];
				matrix[i + 1][j] = 0;
				score += matrix[i][j];
				moves++;
			}
		}
    }

    /*move upwards again after joining*/
    if (moves > 0) {
		for (i = 1; i < SIZE; i++) {
			for (j = 0; j < SIZE; j++) {
				if (matrix[i][j] != 0 && matrix[i - 1][j] == 0) {
					matrix[i - 1][j] = matrix[i][j];
					matrix[i][j] = 0;
				}
			}
		}
	}
	return moves;
}

/*Move the pieces downwards if the controls s or KEY_DOWN be presed
and returns > 0 to if moves has happened or 0 if not*/
short int moveDown(short int matrix[SIZE][SIZE]) {
	short int i, j, k, moves = 0;
	/*First move downwards*/
    for (k = 0; k < SIZE - 1; k++) {
        for (i = SIZE - 2; i >= 0; i--) {
			for (j = 0; j < SIZE; j++) {
				if (matrix[i][j] != 0 && matrix[i + 1][j] == 0) {
					matrix[i + 1][j] = matrix[i][j];
					matrix[i][j] = 0;
					moves++;
				}
			}
        }
    }

    /*Join near and equal values*/
	for (i = SIZE - 1; i > 0; i--) {
		for (j = 0; j < SIZE; j++) {
			if (matrix[i][j] != 0 && matrix[i][j] == matrix[i - 1][j]) {
				matrix[i][j] += matrix[i - 1][j];
				matrix[i - 1][j] = 0;
				score += matrix[i][j];
				moves++;
			}
		}
	}

    /*move downwards again after joining*/
	if (moves > 0) {
		for (i = SIZE - 2; i >= 0; i--) {
			for (j = 0; j < SIZE; j++) { 
				if (matrix[i][j] != 0 && matrix[i + 1][j] == 0) {
					matrix[i + 1][j] = matrix[i][j];
					matrix[i][j] = 0;
				}
			}
		}
	}
	return moves;
}

/*Move the pieces upwards if the controls a or KEY_LEFT be presed
and returns > 0 to if moves has happened or 0 if not*/
short int moveLeft(short int matrix[SIZE][SIZE]) {
	/*First move leftwards*/
	short int i, j, k, moves = 0;
    for (k = 0; k < SIZE - 1; k++) {
        for (j = 1; j < SIZE; j++) {
			for (i = 0; i < SIZE; i++) {
				if (matrix[i][j] != 0 && matrix[i][j - 1] == 0) {
					matrix[i][j - 1] = matrix[i][j];
					matrix[i][j] = 0;
					moves++;
				}
			}
        }
    }

    /*Join near and equal values*/
    for (j = 0; j < SIZE - 1; j++) {
		for (i = 0; i < SIZE; i++) {
			if (matrix[i][j] != 0 && matrix[i][j] == matrix[i][j + 1]) {
				matrix[i][j] += matrix[i][j + 1];
				matrix[i][j + 1] = 0;
				score += matrix[i][j];
				moves++;
			}
		}
    }

    /*move leftwards again after joining*/
	if (moves > 0) {
		for (j = 1; j < SIZE; j++) {
			for (i = 0;i < SIZE; i++) {
				if (matrix[i][j] != 0 && matrix[i][j - 1] == 0) {
					matrix[i][j - 1] = matrix[i][j];
					matrix[i][j] = 0;
				}
			}
		}
	}
	return moves;
}

/*Move the pieces upwards if the controls d or KEY_RIGHT be presed
and returns > 0 to if moves has happened or 0 if not*/
short int moveRight(short int matrix[SIZE][SIZE]) {
	/*First move rightwards*/
	short int i, j, k, moves = 0;
    for (k = 0; k < SIZE - 1; k++) {
        for (j = SIZE - 2; j >= 0; j--) {
			for (i = 0; i < SIZE; i++) {
				if (matrix[i][j] != 0 && matrix[i][j + 1] == 0) {
					matrix[i][j + 1] = matrix[i][j];
					matrix[i][j] = 0;
					moves++;
				}
			}
        }
    }

    /*Join near and equal values*/
    for (j = SIZE - 1; j > 0; j--) {
		for (i = 0; i < SIZE; i++) {
			if (matrix[i][j] != 0 && matrix[i][j] == matrix[i][j - 1]) {
				matrix[i][j] += matrix[i][j - 1];
				matrix[i][j - 1] = 0;
				score += matrix[i][j];
				moves++;
			}
		}
    }

    /*move rightwards again after joining*/
	if (moves > 0) {
		for (j = SIZE - 2; j >= 0; j--) {
			for (i = 0; i < SIZE; i++) {
				if (matrix[i][j] != 0 && matrix[i][j + 1] == 0) {
					matrix[i][j + 1] = matrix[i][j];
					matrix[i][j] = 0;
				}
			}
		}
	}
	return moves;
}
