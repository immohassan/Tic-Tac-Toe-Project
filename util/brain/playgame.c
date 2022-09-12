//Path: Project_1 folder/util/Brain/playgame.c
#include "../_masterheader.h"
int total_games = 0, p1_wins = 0, p2_wins = 0, draws = 0;
int playGame(struct game *game1,struct stats * stat) // this function is responsible for executing the whole game
{
    int turn = 0, player = 0, winner = 0, i = 0;
    initBoard(game1); // initializing the struct array
    total_games++;
    do
    {
        turn++;                              // Every time this loop executes, a unique turn is about to be made
        player = (turn + 1) % 2 + 1;         // This mod function alternates the player variable between 1 & 2 each turn
        makeMove(game1, player);  
        system("cls");           // this function will take user input in the form of array index
        printBoard(game1);                   // this function will printf the board after insertion of new mark
        winner = checkWinner(game1, player); // after every insertion, winning conditions will be checked
        if (winner == 0 && turn ==9) // if game is draw
        {
            draw_message(); // this means the board is full and the game is over
            draws++; //increase draw counter 
        }
        if (winner != 0) // if it founds a winner
        {
            winner_message(game1, winner); // then print which player won the game
            if (winner == 1)
            {
                p1_wins++; // increase  p1 win counter
            }
            else if (winner == 2)
            {
                p2_wins++; // increase p2 win counter
            }
            break;
        return winner; // this will break the loop
        }


    } while (turn < ROWS * COLS); // Once ROWS*COLS turns have elapsed
            stats(total_games, p1_wins, p2_wins, draws, game1,stat);  // sending counters to stats
            fileStats(total_games, p1_wins, p2_wins, draws,game1,stat);
    return winner;
}