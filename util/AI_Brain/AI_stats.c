//Path: Project_1 folder/util/ AI_Brain/AI_stats.c
#include"../_masterheader.h"

void AI_stats(int tgames, int p1wins, int p2wins, int draws, struct game * game1, struct stats * stat){   
    sprintf(stat->stat_arr,"Total Games = %d\nTotal Wins of Player %s = %d\nTotal Wins of AI = %d\nGame drawns = %d\n",tgames,game1->p1_name,p1wins,p2wins,draws);
    stats_printer(stat); // printing stats
    return;
}  
void Ai_fileStats(int tgames, int p1wins, int p2wins, int draws, struct game * game1, struct stats * stat){
    sprintf(stat->file_arr,"%s\n %s\n %d\n %d\n %d\n %d\n", game1->p1_name, game1->p2_name, tgames,p1wins,p2wins,draws);
    return; //this arr only contains important data except strings to save in file  
}