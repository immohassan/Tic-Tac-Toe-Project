//Path: Project_1 folder/util/Brain/checkwinner.c
#include"../_masterheader.h"

int checkWinner(struct game*game1, int player){
    int row = 0, col = 0, i = 0;
    char currentChar;

    if (player == 1)
        currentChar = PLAYER1CHAR;
    else
        currentChar = PLAYER2CHAR;

    for (row = 0; row < ROWS; row++) // This first for loop checks every row
    {
        for (col = 0; col < (COLS - 2); col++) // and only first column
        {
            while (game1->gameArray[row][col] == currentChar) // For consecutive rows of the current player's mark
            {
                col++;
                i++;
                if (i == N) // we need 3 consecutive marks to win
                {
                    return player;
                }
            }
            i = 0;
        }
    }

    for (col = 0; col < COLS; col++) // This one checks for columns of consecutive marks
    {
        for (row = 0; row < (ROWS - 2); row++)
        {
            while (game1->gameArray[row][col] == currentChar)
            {
                row++;
                i++;
                if (i == N)
                {
                    return player;
                }
            }
            i = 0;
        }
    }

    for (col = 0; col < (COLS - 2); col++) // This one checks for "forwards" diagonal runs
    {
        for (row = 0; row < (ROWS - 2); row++)
        {
            while (game1->gameArray[row][col] == currentChar)
            {
                row++;
                col++;
                i++;
                if (i == N)
                {
                    return player;
                }
            }
            i = 0;
        }
    }
    // Finally, the backwards diagonals:
    for (col = COLS - 1; col > 1; col--)       
    {                                          // The math seems strange here but the numbers work out when you trace them
        for (row = 0; row < (ROWS - 2); row++) // Start from the first row and the last column
        {
            while (game1->gameArray[row][col] == currentChar) // If the current player's character is there
            {
                row++;      // Go down a row
                col--;      // And back a column
                i++;        // The i variable tracks how many consecutive marks have been found
                if (i == N) // Once i == N
                {
                    return player; // Return the current player number to the
                }                  // winnner variable in the playGame function
            }                      // If it breaks out of the while loop, there weren't 3 consecutive marks
            i = 0;                 // So make i = 0 again
        }                          // And go back into the for loop, incrementing the row to check from
    }

    return 0; // If we got to here, no winner has been detected,
} // so we pop back up into the playGame function

