#ifndef BOARD_H_
#define BOARD_H_

typedef struct Board *Board;

extern Board create_board();
extern Board copy_board(const Board b);
extern int check_win(const Board b);
extern int check_draw(const Board b);
extern int set_square(Board b, char new_contents, int index);
extern void destroy_board(Board b);
extern void show_board(const Board b);

#endif
