//Path: Project_1 folder/util/Brain/arrayinput.c
#include"../_masterheader.h"

//this function will store the user mark in struct array

void arrayinput(struct game* game1,int x,int y,int player){   
      if (player == 1)
    {
    game1->gameArray[x][y] =  PLAYER1CHAR;
    }
    else
    {
    game1->gameArray[x][y] =  PLAYER2CHAR;
    }
}