// path: project_1 foder/util/load_module/file_loader.c
#include "../_masterheader.h"

void file_list(struct stats *stat, struct game *game1)
{
    char file[NAME_LENGTH];
    DIR *list;                  //creating DIR pointer to access the list of files in the folder
    struct dirent *dir;         // file names wll be stored in this struct

    list = opendir("./saved_games/");  // opening the folder
    printf("\nList of saved game files: \n");
    if (list != NULL)
    {
        while ((dir = readdir(list)) != NULL)  //condition
        {
            printf("%s\n", dir->d_name);       //printing all the files in the folder
        }
        closedir(list);
    }
    printf("\n\nEnter the name of the file ( Without Extension ) you want to load: ");
    scanf("%s",file);
    char ext[NAME_LENGTH] = ".txt";      //again concatinating as in stats_saver.c
    char str[NAME_LENGTH] = "./saved_games/";
    strcat(str, file); // including path to the file name
    strcat(str, ext);
    loader(stat, str, game1);    // calling the loader function to execute the game
}
void loader(struct stats *stat, char str[NAME_LENGTH], struct game *game1)
{
    char p1[NAME_LENGTH], p2[NAME_LENGTH];
    int tgames, p1win, p2win, draw;
    FILE *file = fopen(str, "r");     //opening the file
    if (file == NULL)
    {
        fprintf(stderr, "\nError opened file\n");
        file_list(stat,game1);
    }
    else
    {
        fscanf(file, "%s %s %d %d %d %d",p1,p2, &tgames, &p1win, &p2win, &draw);   //getting data from file
        strcpy(game1->p1_name, p1); //giving names to struct
        strcpy(game1->p2_name, p2);
        fclose(file);
        char a[10] = "AI";
        if(strcmp(a,game1->p2_name) == 0)  // if file is AI, AIgame will be loaded
        {
            printf("\n-----------------Welcome back %s----------------\n", game1->p1_name);
            printf("Total Games = %d\nTotal Wins of Player %s = %d\nTotal Wins of Player %s = %d\nGame drawns = %d\n\n",tgames,p1,p1win,p2,p2win,draw);
            printf("-----------------Game loaded-----------------\n\n");
            AIloadGame(game1, stat, tgames, p1win, p2win, draw);
        }
        else   // else if the file is of 2player, 2player game will be loaded
        {
            printf("\n-----------------Welcome back %s & %s----------------\n\n", game1->p1_name, game1->p2_name);
            printf("Total Games = %d\nTotal Wins of Player %s = %d\nTotal Wins of Player %s = %d\nGame drawns = %d\n\n",tgames,p1,p1win,p2,p2win,draw);
            printf("-----------------Game loaded-----------------\n\n");
            loadGame(game1, stat, tgames, p1win, p2win, draw);
        }
    }
}
