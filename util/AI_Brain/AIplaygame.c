// Path: Project_1 folder/util/ AI_Brain/AIplaygame.c
#include "../_masterheader.h"
int AItotal_games = 0, AIp1_wins = 0, AI_wins = 0, AIdraws = 0;
int AIplayGame(struct game *game1, struct stats *stat) // this function is responsible for executing the whole game
{
    AItotal_games++; // for stats
    int turn = 0, player = 0, winner = 0, i = 0;
    initBoard(game1); // initializing the struct array

    do
    {
        AImakeMove(game1);     // this function will take user input in the form of array index
        system("cls");   
        printBoard(game1);        // this function will printf the board after insertion of new mark
        winner = evaluate(game1); // after every insertion, winning conditions will be checked
        findBestMove(game1);      // this function will play te AI move
        system("cls");      
        printBoard(game1);        // this function will printf the board after insertion of new mark
        winner = evaluate(game1); // after every insertion, winning conditions will be checked

        if (evaluate(game1) == 10 || evaluate(game1) == -10) // if it founds a winner
        {
            AI_wins++;               // for stats       
            AIwinner_message(game1); // printf winner
            break;
        }
        if (isMovesLeft(game1) == 0)
        {
            AIdraws++;      // for stats
            draw_message(); // if no one wins, then it is a draw
            break;
        }

    } while (turn < ROWS * COLS || winner != 0); // Once ROWS*COLS turns have elapsed
    AI_stats(AItotal_games, AIp1_wins, AI_wins, AIdraws, game1, stat);
    Ai_fileStats(AItotal_games, AIp1_wins, AI_wins, AIdraws,game1,stat);
    return winner;
}