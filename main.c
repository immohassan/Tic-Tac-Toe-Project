//Path: Project_1/ folder/main.c 
#include"./util/_masterheader.h"

int main()
{
   struct game * game1 = init();       //initializing game struct
   struct stats * stat = stat_init();  //initializing stats struct
    intro_message();
    onetime_menu(game1,stat);          //printing menu and executing program
}
