#include <stdlib.h>
#include <stdio.h>
#include "row.h"
#include "square.h"

struct Row {
    Square s1;
    Square s2;
    Square s3;
    int owner;
};

Row create_row(Square s1, Square s2, Square s3, int owner) {
    Row result = malloc(sizeof(struct Row));
    result->s1 = s1;
    result->s2 = s2;
    result->s3 = s3;
    result->owner = owner;
    return result;
}

Row copy_row(const Row r) {
    Row result = malloc(sizeof(struct Row));
    result->s1 = copy_square(r->s1);
    result->s2 = copy_square(r->s2);
    result->s3 = copy_square(r->s3);
    result->owner = 1;
}

void destroy_row(Row r) {
    if (r->owner) {
        destroy_square(r->s1);
        destroy_square(r->s2);
        destroy_square(r->s3);
    }
    free(r);
}

void show_row(const Row r) {

    printf("_______\n");
    printf("|%c|%c|%c|\n", 
            get_contents(r->s1), 
            get_contents(r->s2), 
            get_contents(r->s3));
    printf("_______\n");
}
   
int is_win(const Row r) {
    return  get_contents(r->s1) == get_contents(r->s2) 
            && get_contents(r->s2) == get_contents(r->s3);
}

int row_is_filled(const Row r) {
    return square_is_filled(r->s1) &&
        square_is_filled(r->s2) &&
        square_is_filled(r->s3);
}

Square get_square(const Row r, int index) {
    if (index > 3 || index < 1) {
        return NULL;
    }
    else if (index == 1) {
        return r->s1;
    }
    else if (index == 2) {
        return r->s2;
    }
    else {
        return r->s3;
    }
}
