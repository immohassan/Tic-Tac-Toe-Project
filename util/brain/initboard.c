//Path: Project_1 folder/util/Brain/initboard.c
#include"../_masterheader.h"

void initBoard(struct game* game1)
{
    int row = 0, col = 0;

    for (row = 0; row < ROWS; row++)
    {
        for (col = 0; col < COLS; col++)
        {
            game1->gameArray[row][col] = INITCHAR; // Fill the game1->gameArray with INITCHAR characters
        }
    }

    printBoard(game1); // Having this here prints out the board before
    return;                // the playGame function asks for the first move
}