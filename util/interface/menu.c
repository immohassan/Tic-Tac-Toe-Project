// Path: Project_1 folder/util/ interface/menu.c
#include "../_masterheader.h"
void onetime_menu(struct game * game1 , struct stats * stat){
    system("color D");
    int choice = 0;
    printf("****************************************\n");
    printf("|              Main menu               |\n");
    printf("|                                      |\n");
    printf("|    Press 1 for Multiplayer game      |\n");
    printf("|    Press 2 to compete with our AI    |\n");
    printf("|    Press 3 to load the saved game    |\n");
    printf("|    Press -1 to exit the game         |\n");
    printf("|                                      |\n");
    printf("****************************************\n");
    scanf("%d", &choice);
    switch(choice){
    case 1: 
        system("cls");
        name(game1);
        maingame(game1, stat);
        break;
    case 2:
        system("cls");
        AIname(game1);
        AImaingame(game1, stat);
        break;
    case 3:
        system("cls");
        file_list(stat, game1);
        break;
    case -1:
        system("cls");
        printf("Thank you for playing!");
        exit(0);
        break;
    default:
    {
        printf("Invalid Input, please enter correct input\n");
        onetime_menu(game1, stat);
    }
    }
}
void menu_printer(struct game *game1, struct stats *stat) // this function simply prints the menu
{
    int n;
    int menu = 0;
    printf("****************************************\n");
    printf("|              Main menu               |\n");
    printf("|                                      |\n");
    printf("|    Press 1 for Multiplayer game      |\n");
    printf("|    Press 2 to compete with our AI    |\n");
    printf("|    Press 3 to Display Stats          |\n");
    printf("|    Press 4 to save the game          |\n");
    printf("|    Press 5 to load the saved game    |\n");
    printf("|    Press 6 to resume the game        |\n");
    printf("|    Press -1 to exit the game         |\n");
    printf("|                                      |\n");
    printf("****************************************\n");
    scanf("%d", &menu);
    switch (menu)
    {
    // cases
    case 1:
        system("cls");
        name(game1);
        maingame(game1, stat);
        break;
    case 2:
        system("cls");
        AIname(game1);
        AImaingame(game1, stat);
        break;
    case 3:
        system("cls");
        stats_printer(stat);
        printf("\n Press 1 for menu, anything else exits");
        scanf("%d", &n);
        if (n == 1)
        {
            menu_printer(game1, stat);
        }
        else
        {
            exit(0);
        }
        break;
    case 4:
        system("cls");
        save_list(stat, game1);
        menu_printer(game1, stat);
        break;
    case 5:
        system("cls");
        file_list(stat, game1);
        break;
    case 6:
        system("cls");
        char a[10] = "AI";
        if (strcmp(a, game1->p2_name) == 0){
            printf("---------------------Game resumed---------------------");
            AImaingame(game1,stat);
        }
        else{
            printf("---------------------Game resumed---------------------");
            maingame(game1, stat);
        }
        break;
    case -1:
        system("cls");
        printf("Thank you for playing!");
        exit(0);
        break;
    // error handling
    default:
    {
        printf("Invalid Input, please enter correct input\n");
        menu_printer(game1, stat);
    }
    }
}