#include <ncurses.h>
#include "backend.h"
#include "frontend.h"

void display_points(PointList* snake, const chtype symbol) {
  while(snake) {
    mvaddch(snake->y, snake->x, symbol);
    snake = snake->next;
  }
}

enum Direction get_next_move(enum Direction previous) {
  int ch = getch();
  switch (ch) {
    case KEY_LEFT:
      return LEFT;
    case KEY_RIGHT:
      return RIGHT;
    case KEY_DOWN:
      return DOWN;
    case KEY_UP:
      return UP;
    default:
      return previous;
  }
}


