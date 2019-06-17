#ifndef __TIC_TAC_TOE_FUNCTIONS_H__
#define __TIC_TAC_TOE_FUNCTIONS_H__

#include <stdbool.h>  // use booleans in C

/** Print field represented by given character array.
	The array must contains 9 chars ('O', 'X' or ' ')
	ordered row-wise from top left to bottom right. */
void printField(char* field);

/** Check if the field is valid for the server. */
bool checkField(char* field);

/** Check if the given player has won for the
    given field. Player must be 'X' or 'O'. */
bool checkWin(char* field, char player);

/** Check if the given field is a draw match. */
bool checkDraw(char* field);

/** Compute the next move for the given field and
    player and updates the field. Returns true if
    a move was made, and false in case of error. */
bool nextMove(char* field, char player);

#endif
