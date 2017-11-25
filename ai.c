#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "ai.h"
#include "statenode.h"
#include "statelist.h"


struct AI {

    char id;

};

AI create_ai(char id) {
    AI result = malloc(sizeof(struct AI));
    result->id = id;
    return result;
}

void destroy_ai(AI ai) {
    free(ai);
}

static StateList generate_moves(Board b, char player) {
    StateList result = create_state_list(9);
    for (int i = 1; i <= 9; i++) {
        Board after_move = copy_board(b);
        if (set_square(after_move, player, i)) {
            add_state(result, create_state_node(after_move, 0));
        }
        else {
            destroy_board(after_move);
        }
    }
    return result;
}

static int minimax(StateNode node, char subject_player, char current_player) {
    if (check_win(get_state(node))) {
        return subject_player != current_player ? 1 : -1;
    }
    else if (check_draw(get_state(node))) {
        return 0;
    }

    StateList possible_moves = generate_moves(
            get_state(node), 
            current_player
            );

    for (int i = 0; i < get_size(possible_moves); i++) {
        StateNode next = get_state_at_index(possible_moves, i);
        set_score(next, minimax(next, subject_player, current_player == 'X' ? 'O' : 'X'));
    }
    if (subject_player == current_player) {
        StateNode maximum_state = get_maximum_state(possible_moves);
        int result = get_score(maximum_state);
        destroy_state_list(possible_moves);
        return result;
    }
    else {
        StateNode minimum_state = get_minimum_state(possible_moves);
        int result = get_score(minimum_state);
        destroy_state_list(possible_moves);
        return result;
    }
}

void make_move(AI ai, Board *b) {
    printf("Thinking...\n");
    StateList possible_moves = generate_moves((*b), ai->id);
    for (int i = 0; i < get_size(possible_moves); i++) {
        StateNode next = get_state_at_index(possible_moves, i);
        set_score(next, minimax(next, ai->id, ai->id == 'O' ? 'X' : 'O'));
    }
    for (int i = 0; i < get_size(possible_moves); i++) {
        StateNode next = get_state_at_index(possible_moves, i);
        Board state = get_state(next);
        int score = get_score(next);
    }
    Board result = copy_board(get_state(get_maximum_state(possible_moves)));
    destroy_state_list(possible_moves);
    destroy_board(*b);
    (*b) = result;
    printf("Made move\n");
}

/*
void make_move(AI ai, Board b) {
    printf("Thinking....\n");
    srand(time(NULL));

    int made_move = 0;

    for (int i = 1; i <= 9; i++) {
        Board copy = copy_board(b);
        set_square(copy, ai->id, i);
        if (check_win(copy)) {
            destroy_board(copy);
            made_move = set_square(b, ai->id, i);
            break;
        }
        destroy_board(copy);
    }

    while (!made_move) {
        int move = rand() % 9 + 1;
        Board copy = copy_board(b);
        made_move = set_square(copy, ai->id, move);
        if (made_move) {
            for (int i = 1; i <= 9; i++) {
                set_square(copy, 'X', i);
                if (check_win(copy)) {
                    move = i;
                    break;
                }
                else {
                    destroy_board(copy);
                    copy = copy_board(b);
                    set_square(copy, ai->id, move);
                }
            
            }
                    
            made_move = set_square(b, ai->id, move);
            printf("Made move: %d\n", move);
        }
        destroy_board(copy);
    }

}
*/
