// path: project_1 foder/util/load_module/load_2p_game.c
#include "../_masterheader.h"
int loadGame(struct game *game1,struct stats * stat,int total_games, int p1_wins, int p2_wins,int draws) // this function is responsible for executing the whole game
{
    int turn = 0, player = 0, winner = 0, i = 0;
    initBoard(game1); // initializing the struct array
    total_games++;
    do
    {
        turn++;                              // Every time this loop executes, a unique turn is about to be made
        player = (turn + 1) % 2 + 1;         // This mod function alternates the player variable between 1 & 2 each turn
        makeMove(game1, player);             // this function will take user input in the form of array index
        system("cls");            
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
            char replay;
        printf("\nWould you like to play again? Y for yes, M to go back to menu, anything else terminates: ");
        scanf("%c", &replay); // I have to use both a scanf() and a getchar() 
        replay = getchar();
        if(replay == 'y'|| replay == 'Y'){  
            loadGame(game1,stat,total_games,p1_wins,p2_wins,draws);
        }
        else if(replay == 'm' || replay == 'M'){
            menu_printer(game1,stat);
        }
        else 
        exit(0);
    return winner;
}
