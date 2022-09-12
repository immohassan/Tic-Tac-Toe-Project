//Path: Project_1 folder/util/ AI_Brain/checkwinner.c
#include"../_masterheader.h"

int evaluate(struct game * game1)
{
	// Checking for Rows for X or O victory.
	for (int row = 0; row<ROWS; row++)
	{
		if (game1->gameArray[row][0]==game1->gameArray[row][1] &&
			game1->gameArray[row][0]==game1->gameArray[row][2])
		{
			if (game1->gameArray[row][0]==PLAYER1CHAR)
				return +10; 
			else if (game1->gameArray[row][0]==PLAYER2CHAR)
				return -10;
		}
	}

	// Checking for Columns for X or O victory.
	for (int col = 0; col<COLS; col++)
	{
		if (game1->gameArray[0][col]==game1->gameArray[1][col] &&
			game1->gameArray[0][col]==game1->gameArray[2][col])
		{
			if (game1->gameArray[0][col]==PLAYER1CHAR)
				return +10;

			else if (game1->gameArray[0][col]==PLAYER2CHAR)
				return -10;
		}
	}

	// Checking for Diagonals for X or O victory.
	if (game1->gameArray[0][0]==game1->gameArray[1][1] && game1->gameArray[1][1]==game1->gameArray[2][2])
	{
		if (game1->gameArray[0][0]==PLAYER1CHAR)
			return +10;
		else if (game1->gameArray[0][0]==PLAYER2CHAR)
			return -10;
	}

	if (game1->gameArray[0][2]==game1->gameArray[1][1] && game1->gameArray[1][1]==game1->gameArray[2][0])
	{
		if (game1->gameArray[0][2]==PLAYER1CHAR)
			return +10;
		else if (game1->gameArray[0][2]==PLAYER2CHAR)
			return -10;
	}

	// Else if none of them have won then return 0
	return 0;
}