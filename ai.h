#ifndef AI_H_
#define AI_H_
#include "board.h"

typedef struct AI *AI;

AI create_ai(char id);
void destroy_ai(AI ai);
void make_move(AI ai, Board *b);


#endif // AI_H_
