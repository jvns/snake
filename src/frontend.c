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
    case 'h':
    case KEY_LEFT:
      if (previous != RIGHT) return LEFT; break;
    case 'l':
    case KEY_RIGHT:
      if (previous != LEFT) return RIGHT; break;
    case 'j':
    case KEY_DOWN:
      if (previous != UP) return DOWN; break;
    case 'k':
    case KEY_UP:
      if (previous != DOWN) return UP; break;
    default:
      return previous;
  }
  return previous;
}


