#ifndef STATELIST_H_
#define STATELIST_H_
#include "statenode.h"

typedef struct StateList *StateList;

extern StateList create_state_list(int initial_capacity);
extern void destroy_state_list(StateList list);
extern StateNode get_maximum_state(const StateList list);
extern StateNode get_minimum_state(const StateList list);
extern StateNode get_state_at_index(const StateList list, int index);
extern void add_state(StateList list, const StateNode node);
extern int get_capacity(const StateList list);
extern int get_size(const StateList list);

#endif // STATELIST_H_
