//Path: Project_1 folder/util/ interface/messages.h
void winner_message(struct game * game1, int player);
void draw_message();
int playagain(struct game * game1, struct stats * stat);
void AIwinner_message(struct game* game1);
int AIplayagain(struct game * game1,struct stats * stat);
void intro_message();
void stats_printer(struct stats * stat);