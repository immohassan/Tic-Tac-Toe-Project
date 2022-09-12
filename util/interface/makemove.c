//Path: Project_1 folder/util/ interface/makemove.c
#include"../_masterheader.h"

// this functin will take user input to store the player's mark
void makeMove(struct game*game1, int player) 
{
    int row = 0, col = 0, i = 0;
    char currentChar;

    if (player == 1) // This gets the correct player's mark
        currentChar = PLAYER1CHAR;
    else
        currentChar = PLAYER2CHAR;

    printf("\nPlayer %i, please enter the column of your move: ", player);
    scanf("%d", &col);
    printf("Please enter the row of your move: ");
    scanf("%d", &row);

    row--; // These lines translate the user's rows and columns numbering
    col--; // (starting with 1) to the computer's (starting with 0)

    while (game1->gameArray[row][col] != INITCHAR || row > ROWS - 1 || col > COLS - 1) // We are not using a do... while because
    {                                                                           // I wanted the prompt to change
        printBoard(game1);
        printf("\nPlayer %i, please enter a valid move! Column first, then row.\n", player);
        scanf("%d %d", &col, &row);

        row--; 
        col--;
    }
    arrayinput(game1,row,col,player);   // the user input will be sent to the brain function 
    
}
