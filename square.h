#ifndef SQUARE_H_
#define SQUARE_H_

typedef struct Square *Square;

extern Square create_square(char contents);
extern Square copy_square(const Square s);
extern int set_contents(Square s, char new_contents);
extern int square_is_filled(const Square s);
extern char get_contents(const Square s);
extern void destroy_square(Square s);

#endif // SQUARE_H_
