#include <ncurses.h>
enum Direction get_next_move(enum Direction previous);
void display_points(PointList* snake, const chtype symbol);
