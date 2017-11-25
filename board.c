#include <stdio.h>
#include <stdlib.h>
#include "row.h"
#include "board.h"
#include "square.h"

struct Board {
    Row board[8];
};

Board create_board() {
    Board result = malloc(sizeof(struct Board));
    Square squares[9];
    for (int i = 0; i < 9; i++) {
        squares[i] = create_square(i + '1');
    }

    result->board[0] = create_row(squares[0], squares[1], squares[2], 1);
    result->board[1] = create_row(squares[3], squares[4], squares[5], 1);
    result->board[2] = create_row(squares[6], squares[7], squares[8], 1);
    result->board[3] = create_row(squares[0], squares[3], squares[6], 0);
    result->board[4] = create_row(squares[1], squares[4], squares[7], 0);
    result->board[5] = create_row(squares[2], squares[5], squares[8], 0);
    result->board[6] = create_row(squares[0], squares[4], squares[8], 0);
    result->board[7] = create_row(squares[2], squares[4], squares[6], 0);

    return result;

}

Board copy_board(const Board b) {
    Board copy = malloc(sizeof(struct Board));
    for (int i = 0; i < 3; i++) {
        copy->board[i] = copy_row(b->board[i]);
    }
    for (int j = 3; j < 6; j++) {
        copy->board[j] = create_row(
                get_square(copy->board[0], (j % 3) + 1),
                get_square(copy->board[1], (j % 3) + 1),
                get_square(copy->board[2], (j % 3) + 1), 0
                );
    }
    copy->board[6] = create_row(
            get_square(copy->board[0], 1),
            get_square(copy->board[1], 2),
            get_square(copy->board[2], 3), 0
            );
    copy->board[7] = create_row(
            get_square(copy->board[0], 3),
            get_square(copy->board[1], 2),
            get_square(copy->board[2], 1), 0
            );
    return copy;
}

int check_win(const Board b) {
    for (int i = 0; i < 8; i++) {
        if (is_win(b->board[i])) {
            return 1;
        }
    }
    return 0;
}

int check_draw(const Board b) {
    for (int i = 0; i < 8; i++) {
        if (!row_is_filled(b->board[i])) {
            return 0;
        }
    }
    return 1;
}

int set_square(Board b, char new_contents, int index) {
    Square to_set;
    if (index <= 3) {

        if ((to_set = get_square(b->board[0], index)) != NULL) {
            return set_contents(to_set, new_contents);
        }
        else {
            return 0;
        }
    }
    else if (index <= 6) {

        if ((to_set = get_square(b->board[1], index - 3)) != NULL) {
            return set_contents(to_set, new_contents);
        }
        else {
            return 0;
        }
    }
    else if (index <= 9) {

        if((to_set = get_square(b->board[2], index - 6)) != NULL) {
            return set_contents(to_set, new_contents);
        }
        else {
            return 0;
        }
    }
    else {
        return 0;
    }
}

void destroy_board(Board b) {
    for (int i = 0; i < 8; i++) {
        destroy_row(b->board[i]);
    }
    free(b);
}

void show_board(const Board b) {
    for (int i = 0; i < 3; i++) {
        show_row(b->board[i]);
    }
    printf("\n");
}
