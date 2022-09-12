// Path: Project_1 folder/util/ AI_Brain/AI_maingame.c
#include "../_masterheader.h"

int AImaingame(struct game *game1, struct stats *stat) // this function will play the whole game
{
    int winner = 0;
    int num;
    do // This loop plays through the game until the user selects not to
    {
        winner = AIplayGame(game1, stat);
        num = AIplayagain(game1, stat);
        if (num == 0)
        {
            exit(0);
        }
    } while (winner != 0);
}