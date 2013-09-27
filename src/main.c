#include "snake.h"
#include <ncurses.h>

int main() {
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE); // make keys work
  curs_set(0); // hide cursor
  timeout(100);

  struct Snake *snake = create_snake();
  int xmax;
  int ymax;
  getmaxyx(stdscr, ymax, xmax);
  enum Direction dir = RIGHT;
  while(true) {
    erase();
    display_snake(snake);
    dir = get_next_move(dir);
    snake = move_snake(snake, dir, xmax, ymax);
    if (snake == NULL) break;
  }
  endwin();

  return 0;
}
