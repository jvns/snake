#include "snake.h"
#include <ncurses.h>

int main() {
  initscr();
  curs_set(0); // hide cursor

  struct Snake *snake = create_snake();
  int xmax;
  int ymax;
  getmaxyx(stdscr, ymax, xmax);

  while(true) {
    display_snake(snake);
    enum Direction dir = get_next_move();
    snake = move_snake(snake, dir, xmax, ymax);
    if (snake == NULL) break;
  }

  getch();
  //printf("Size: %d %d", x, y);
  return 0;
}
