#include <ncurses.h>
#include <stdio.h>

int main() {
  int x;
  int y;
  initscr();
  getmaxyx(stdscr, y, x);
  getch();
  printf("Size: %d %d", x, y);
  return 0;
}
