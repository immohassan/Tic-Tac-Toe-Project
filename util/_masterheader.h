//Path: Project_1 folder/util/_masterheader.h
#ifndef MASTER_HEADER_FILE
#define MASTER_HEADER_FILE
// this is the master header file



#define ROWS 3                      //total rows 
#define COLS 3                      //total cols
#define N 3                         //total marks needed to win the game
#define NAME_LENGTH 255             //name length
#define INITCHAR ' '                //char present in array at the start of the game
#define PLAYER1CHAR 'X'             //player 1 mark
#define PLAYER2CHAR 'O'             //player 2 mark



struct game          //for game
{
    char gameArray[ROWS][COLS];
    char p1_name[NAME_LENGTH];
    char p2_name[NAME_LENGTH];
};

struct stats{         //for stats
char stat_arr[1000];   
  char file_arr[1000];
};

//header files
#include"./AI_Brain/_AI_master_header.h"
#include"./brain/_Brain_master_header.h"
#include"./interface/_interface_master_header.h"
#include"./save_module/stats_saver.h"
#include"./data/struct.h"
#include"./load_module/_load_master_header.h"
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>


#endif