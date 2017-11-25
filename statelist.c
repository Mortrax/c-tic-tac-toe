#include <stdlib.h>
#include <assert.h>
#include "statelist.h"
#include "statenode.h"
#include "board.h"

struct StateList {
    StateNode *data;
    int capacity;
    int size;
};

StateList create_state_list(int initial_capacity) {
    assert(initial_capacity > 0);
    StateList result = malloc(sizeof(struct StateList));
    result->data = malloc(sizeof(StateNode) * initial_capacity);
    for (int i = 0; i < initial_capacity; i++) {
        result->data[i] = NULL;
    }
    result->capacity = initial_capacity;
    result->size = 0;
}

void destroy_state_list(StateList list) {
    for (int i = 0; i < list->capacity; i++) {
        if (list->data[i] != NULL) {
            destroy_state_node(list->data[i]);
        }
    }
    free(list->data);
    free(list);
}

StateNode get_maximum_state(const StateList list) {
    if (list->data == NULL) {
        return NULL;
    }
    StateNode result = list->data[0];
    for (int i = 1; i < list->size; i++) {
        if (get_score(list->data[i]) > get_score(result)) {
            result = list->data[i];
        }  
    }
    return result;
}

StateNode get_minimum_state(const StateList list) {
    if (list->data == NULL) {
        return NULL;
    }
    StateNode result = list->data[0];
    for (int i = 1; i < list->size; i++) {
        if (get_score(list->data[i]) < get_score(result)) {
            result = list->data[i];
        }
    }
    return result;
}

StateNode get_state_at_index(const StateList list, int index) {
    if (index < 0 || index >= list->size) {
        return NULL;
    }
    return list->data[index];
}

void add_state(StateList list, const StateNode node) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        StateNode *new_data = malloc(sizeof(StateNode) * list->capacity);
        for (int i = 0; i < list->size; i++) {
            new_data[i] = list->data[i];
        }
        for (int i = list->size; i < list->capacity; i++) {
            new_data[i] = NULL;
        }
        free(list->data);
        list->data = new_data;
    }
    list->data[list->size++] = node;
}

int get_capacity(const StateList list) {
    return list->capacity;
}

int get_size(const StateList list) {
    return list->size;
}

