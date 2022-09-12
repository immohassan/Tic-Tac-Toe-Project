//Path: Project_1 folder/util/ AI_Brain/leftmoves.c
#include"../_masterheader.h"

int isMovesLeft(struct game * game1)
{
	for (int i = 0; i<ROWS; i++)
		for (int j = 0; j<COLS; j++)
			if (game1->gameArray[i][j]==INITCHAR) // checks if any block is left on board
				return 1;
	return 0;
}