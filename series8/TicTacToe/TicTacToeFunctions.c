#include "TicTacToeFunctions.h"

#include <stdio.h>
#include <string.h>

void printField(char* field)
{
	printf("+---+---+---+\n");
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			printf("| %c ", field[row*3+col]);
		}
		printf("|\n+---+---+---+\n");
	}
}

bool checkField(char* field)
{
	bool ok = true;
	int numX = 0, numO = 0;
	// Check characters in field
	for (int idx = 0; idx < 9 && ok; idx++) {
		if (field[idx] == 'X')
			numX++;
		else if (field[idx] == 'O')
			numO++;
		else if (field[idx] != ' ' && field[idx] != '.')
			ok = false;
	}
	// Check number of X-s and O-s
	if (numX != numO + 1) {
		ok = false;
	}
	return ok;
}

bool checkRow(int row, char* field, char player)
{
	bool win = false;
	if (row >= 0 && row < 3) {
		win = true;
		for (int col = 0; col < 3 && win; col++) {
			if (field[row*3+col] != player) {
				win = false;
			}
		}
	}
	return win;
}

bool checkCol(int col, char* field, char player)
{
	bool win = false;
	if (col >= 0 && col < 3) {
		win = true;
		for (int row = 0; row < 3 && win; row++) {
			if (field[row*3+col] != player) {
				win = false;
			}
		}
	}
	return win;
}

bool checkDiag(int diag, char* field, char player)
{
	bool win = false;
	if (diag == 0) {
		win = true;
		for (int row = 0; row < 3 && win; row++) {
			if (field[row*3+row] != player) {
				win = false;
			}
		}
	} else if (diag == 1) {
		win = true;
		for (int row = 0; row < 3 && win; row++) {
			if (field[row*3+2-row] != player) {
				win = false;
			}
		}
	}
	return win;
}

bool checkWin(char* field, char player)
{
	bool win = false;
	for (int row = 0; row < 3 && !win; row++) {
		win = checkRow(row, field, player);
	}
	if (!win) {
		for (int col = 0; col < 3 && !win; col++) {
			win = checkCol(col, field, player);
		}
	}
	if (!win) {
		for (int diag = 0; diag < 2 && !win; diag++) {
			win = checkDiag(diag, field, player);
		}
	}
	return win;
}

bool checkDraw(char* field)
{
	bool full = true;
	for (int idx = 0; idx < 9 && full; idx++) {
		if (field[idx] == ' ' || field[idx] == '.') {
			full = false;
		}
	}
	if (full) {
		return !checkWin(field, 'O') && !checkWin(field, 'X');
	} else {
		return false;
	}
}

int evalMove(char* field, int idx, char player)
{
	char other = (player == 'X') ? 'O' : 'X';
	char tmpField[9];
	memcpy(tmpField, field, 9);
	tmpField[idx] = player;
	if (checkWin(tmpField, player)) {
		return 1;
	} else if (checkDraw(tmpField)) {
		return 0;
	}
	int res, minRes = 2;
	for (int i = 0; i < 9; i++) {
		if (tmpField[i] == ' ' || tmpField[i] == '.') {
			char tmpValue = tmpField[i];
			tmpField[i] = other;
			if (checkWin(tmpField, other)) {
				res = -1;
			} else if (checkDraw(tmpField)) {
				res = 0;
			} else {
				int maxRes = -2;
				for (int j = 0; j < 9; j++) {
					if (tmpField[j] == ' ' || tmpField[j] == '.') {
						res = evalMove(tmpField, j, player);
						if (res > maxRes) {
							maxRes = res;
						}
					}
				}
				res = maxRes < -1 ? 0 : maxRes;
			}
			tmpField[i] = tmpValue;
			if (res < minRes) {
				minRes = res;
			}
		}
	}
	return minRes > 1 ? 0 : minRes;
}

bool nextMove(char* field, char player)
{
	int bestRes = -1;
	int bestIdx = -1;
	for (int idx = 0; idx < 9 && bestRes <= 0; idx++) {
		if (field[idx] == ' ' || field[idx] == '.') {
			int res = evalMove(field, idx, player);
			if (res > bestRes || bestIdx < 0) {
				bestRes = res;
				bestIdx = idx;
			}
		}
	}
	if (bestIdx >= 0) {
		field[bestIdx] = player;
		return true;
	} else {
		return false;
	}
}
