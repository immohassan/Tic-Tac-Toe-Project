//Path: Project_1 folder/util/ interface/AI_makemove.c
#include"../_masterheader.h"

void AImakeMove(struct game*game1) 
{
    int row = 0, col = 0, i = 0;
    char currentChar;

 // This gets the correct player's mark
        currentChar = PLAYER2CHAR;
    

    printf("\n%s, please enter the column of your move: ",game1->p1_name);
    scanf("%i", &col);
    printf("Please enter the row of your move: ");
    scanf("%i", &row);

    row--; // These lines translate the user's rows and columns numbering
    col--; // (starting with 1) to the computer's (starting with 0)

    while (game1->gameArray[row][col] != INITCHAR || row > ROWS - 1 || col > COLS - 1) // We are not using a do... while because
    {                                                                           // I wanted the prompt to change
        printBoard(game1);
        printf("\n%s, please enter a valid move! Column first, then row.\n",game1->p1_name);
        scanf("%i %i", &col, &row);

        row--; 
        col--;
    }
    game1->gameArray[row][col]=PLAYER2CHAR;  // user  input will be stored in board
    
}