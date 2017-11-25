#include <stdlib.h>
#include "board.h"
#include "statenode.h"

struct StateNode {
    Board state;
    int score;
};


StateNode create_state_node(Board state, int score) {
    StateNode result = malloc(sizeof(struct StateNode));
    result->state = state;
    result->score = score;
    return result;
}

StateNode copy_state_node(const StateNode other) {
    StateNode copy = malloc(sizeof(struct StateNode));
    copy->state = copy_board(other->state);
    copy->score = other->score;
    return copy;
}

void destroy_state_node(StateNode node) {
    destroy_board(node->state);
    free(node);
}

Board get_state(const StateNode node) {
    return node->state;
}

int get_score(const StateNode node) {
    return node->score;
}

void set_score(StateNode node, int new_score) {
    node->score = new_score;
}
