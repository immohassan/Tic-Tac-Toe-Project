// Path: Project_1 folder/util/ AI_Brain/minimax.c
#include "../_masterheader.h"
int minimax(struct game *game1, int isMax)
{
	int score = evaluate(game1);
	// If Maximizer has won the game return
	// evaluated score
	if (score == 10) // x wins
		return score;
	// If Minimizer has won the game return
	// evaluated score
	if (score == -10) // o wins
		return score;
	// If there are no more moves and no winner then
	// it is a tie
	if (isMovesLeft(game1) == 0)
		return 0;
	// If this maximizer's move
	if (isMax)
	{
		int best = -1000;
		// Traverse all cells
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				// Check if cell is empty
				if (game1->gameArray[i][j] == INITCHAR)
				{
					// Make the move
					game1->gameArray[i][j] = PLAYER1CHAR;
					// Call minimax recursively and choose
					// the maximum value
					best = max(best,
					minimax(game1, !isMax));
					// Undo the move
					game1->gameArray[i][j] = INITCHAR;
				}
			}
		}
		return best;
	}
	// If this minimizer's move
	else
	{
		int best = 1000;
		// Traverse all cells
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				// Check if cell is empty
				if (game1->gameArray[i][j] == INITCHAR)
				{
					// Make the move
					game1->gameArray[i][j] = PLAYER2CHAR;
					// Call minimax recursively and choose
					// the minimum value
					best = min(best,
					minimax(game1, !isMax));
					// Undo the move
					game1->gameArray[i][j] = INITCHAR;
				}
			}
		}
		return best;
	}
}