#include <ncurses.h>
#include "backend.h"
#include "frontend.h"

void display_snake(PointList* snake) {
  while(snake) {
    mvaddch(snake->y, snake->x, ACS_BLOCK);
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


