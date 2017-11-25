#ifndef ROW_H_
#define ROW_H_
#include "square.h"
typedef struct Row *Row;

extern Row create_row(Square s1, Square s2, Square s3, int owner);
extern Row copy_row(const Row r);
extern void destroy_row(Row r);
extern void show_row(const Row r);
extern int is_win(const Row r);
extern int row_is_filled(const Row r);
extern Square get_square(const Row r, int index);


#endif // ROW_H_
