//Path: Project_1 folder/util/ interface/name.c
#include"../_masterheader.h"

// this function will take the names of the players and store then in the struct variables.
void name(struct game* game1){

    char name1[NAME_LENGTH], name2[NAME_LENGTH];
    printf("Player 1, Enter your name: ");
    scanf("%s",&name1); 
    strcpy(game1->p1_name,name1);

    printf("Player 2, Enter your name: ");
    scanf("%s",&name2);
    strcpy(game1->p2_name,name2);
}

void AIname(struct game* game1){
    char name1[NAME_LENGTH], name2[NAME_LENGTH] = "AI";
    printf("Player 1, Enter your name: ");
    scanf("%s",&name1); 
    strcpy(game1->p1_name,name1);
    strcpy(game1->p2_name,name2);
}