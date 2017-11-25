#ifndef STATENODE_H_
#define STATENODE_H_

#include "board.h"

typedef struct StateNode *StateNode;

extern StateNode create_state_node(Board state, int score);
extern StateNode copy_state_node(const StateNode other);
extern void destroy_state_node(StateNode node);
extern Board get_state(const StateNode node);
extern int get_score(const StateNode node);
extern void set_score(StateNode node, int new_score);


#endif // STATENODE_H_
