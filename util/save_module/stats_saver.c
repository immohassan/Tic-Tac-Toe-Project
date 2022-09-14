// path: project_1 foder/util/save_module/stats_saver.c
#include "../_masterheader.h"

void save_list(struct stats *stat, struct game *game1)
{
        printf("Please enter the name of the file to save. \n");
        char file_name[10000];
        scanf("%s", file_name);
        FILE *outfile;                       //file pointer for file handling
        char ext[100] = ".txt";              //we cannot give absolute path of file in scanf 
        char str[100] = "./saved_games/";   // so we used string concatination
        strcat(str, file_name);              // including path to the file name 
        strcat(str, ext);
        if (access(str, F_OK) == 0)          // checking  if there exists a file with the given name
        {
            printf("File with this name already exits, please use a different name\n");
            save_list(stat,game1);
        }
        else
        {
            outfile = fopen(str, "a+");       // open file for writing
            if (outfile == NULL)              //if file didn't open
            {
                fprintf(stderr, "\nError opened file\n");
                save_list(stat,game1);
            }
            // write struct array to file
            fwrite(&stat->file_arr, sizeof(struct stats), 1, outfile);
            if (fwrite != 0)
                printf("contents to file written successfully !\n");
            else if (fwrite == 0)     //if there was an error writing the file
            {
                printf("error writing file !\n");
                save_list(stat,game1);
            }
            // close file
            fclose(outfile);
            return;
    }
        }
