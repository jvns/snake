#include "snake.h"
#include <ncurses.h>

int main() {
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  curs_set(0); // hide cursor
  timeout(100);
  //init_pair(1, COLOR_RED, COLOR_GREEN);
  //attron(COLOR_PAIR(1));

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

  getch();
  //printf("Size: %d %d", x, y);
  return 0;
}
