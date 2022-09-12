//Path: Project_1 folder/util/ data/struct.c
#include"../_masterheader.h"

// this function is responsible to create an instance of the struct
struct game * init(){
    struct game * game1 = (struct game*)malloc(sizeof(struct game)); // allocating dynamic memory
    return game1;
}
struct stats * stat_init(){  // allocating dynamic memory
    struct stats * stat = (struct stats*)malloc(sizeof(struct stats));
    return stat;
}