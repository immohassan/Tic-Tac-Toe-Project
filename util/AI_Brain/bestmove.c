//Path: Project_1 folder/util/ AI_Brain/bestmove.c
#include"../_masterheader.h"

int findBestMove(struct game * game1)
{
	int bestVal = -1000;
	int bestMove_row = -1;
	int bestMove_col = -1;

	// Traverse all cells, evaluate minimax function for
	// all empty cells. And return the cell with optimal
	// value.
	for (int i = 0; i<ROWS; i++)
	{
		for (int j = 0; j<COLS; j++)
		{
			// Check if cell is empty
			if (game1->gameArray[i][j]==INITCHAR)
			{
				// Make the move
				game1->gameArray[i][j] = PLAYER1CHAR;

				// compute evaluation function for this
				// move.
				int moveVal = minimax(game1, 0);

				// Undo the move
				game1->gameArray[i][j] = INITCHAR;

				// If the value of the current move is
				// more than the best value, then update
				// best
				if (moveVal > bestVal)
				{
					bestMove_row = i;
					bestMove_col = j;
					bestVal = moveVal;
                    
				}
			}
		}
	}
	game1->gameArray[bestMove_row][bestMove_col]=PLAYER1CHAR; // make move at the best place
	return bestVal;
}