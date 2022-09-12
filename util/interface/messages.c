// Path: Project_1 folder/util/ interface/messages.c
#include "../_masterheader.h"

// this function simply print messages
void winner_message(struct game *game1, int player)
{
    if (player == 1)
    {
        printf("Congratulations %s, You have won!!\n", game1->p1_name);
    }
    if (player == 2)
    {
        printf("Congratulations %s, You have won!!\n", game1->p2_name);
    }
    return;
}
// this function printf Ai game winner 
void AIwinner_message(struct game *game1)
{
    printf("%s, you have been defeated by our AI!\n", game1->p1_name);
    return;
}
// draw message
void draw_message()
{
    printf("No winner, it's a tie :-((\n");
}
//playagain of multiplayer
int playagain(struct game *game1, struct stats *stat)
{
    char replay;
    printf("\nWould you like to play again? Y for yes, M to go back to menu, anything else terminates: ");

    scanf("%c", &replay); // I have to use both a scanf() and a getchar()
    replay = getchar();
    if (replay == 'y' || replay == 'Y')
    {
        playGame(game1, stat);
    }
    else if (replay == 'm' || replay == 'M')
    {
        menu_printer(game1, stat);
    }
    else
        return 0;
}
//playagain of AI game
int AIplayagain(struct game *game1, struct stats *stat)
{
    char replay;
    printf("\nWould you like to play again? Y for yes, M to go back to menu, anything else terminates: ");

    scanf("%c", &replay); // I have to use both a scanf() and a getchar()
    replay = getchar();
    if (replay == 'y' || replay == 'Y')
    {
        AImaingame(game1, stat);
    }
    else if (replay == 'm' || replay == 'M')
    {
        menu_printer(game1, stat);
    }
    else
        return 0;
}
// introductory message
void intro_message()
{
    printf("\n\n      Welcome to TIC_TAC_TOE Game!\n");
    printf("    A game project by Caffeine_Coders\n\n\n");
    return;
}
//function to print stats
void stats_printer(struct stats *stat)
{
    printf("\n%s", stat->stat_arr);
}
