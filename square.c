#include <stdlib.h>
#include <stdio.h>
#include "square.h"

struct Square {

    char contents;

};

Square create_square(char contents) {
    Square result = malloc(sizeof(struct Square));
    result->contents = contents;

}

Square copy_square(const Square s) {
    Square result = malloc(sizeof(struct Square));
    result->contents = s->contents;
    return result;
}

int set_contents(Square s, char new_contents) {
    if (s->contents == 'X' || s->contents == 'O') {
        return 0;
    }
    s->contents = new_contents;
    return 1;
}

int square_is_filled(const Square s) {
    return s->contents == 'X' || s->contents == 'O';
}

char get_contents(const Square s) {
    return s->contents;
}

void destroy_square(Square s) {
    free(s);

}
