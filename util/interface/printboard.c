//Path: Project_1 folder/util/ interface/printboard.c
#include"../_masterheader.h"

// fuction to printf board
void printBoard(struct game*game1)
{
    printf("\n   1   2   3\n");
    printf("\n1  %c | %c | %c \n", game1->gameArray[0][0], game1->gameArray[0][1], game1->gameArray[0][2]);
    printf("  ---+---+---\n");
    printf("2  %c | %c | %c \n", game1->gameArray[1][0], game1->gameArray[1][1], game1->gameArray[1][2]);
    printf("  ---+---+---\n");
    printf("3  %c | %c | %c \n\n", game1->gameArray[2][0], game1->gameArray[2][1], game1->gameArray[2][2]);
}
