#include "snake.h"
#include <ncurses.h>

int main() {
  initscr();
  curs_set(0); // hide cursor

  struct Snake *snake = create_snake();

  while(true) {
    display_snake(snake);
    enum Direction dir = get_next_move();
    enum Status status = move_snake(snake, dir);
    if (status == FAIL) break;
  }

  //getmaxyx(stdscr, y, x);
  getch();
  //printf("Size: %d %d", x, y);
  return 0;
}
